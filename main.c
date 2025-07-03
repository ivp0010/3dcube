#include <GLFW/glfw3.h>
#include <stdio.h>
#include "matrix.h"
#include "camera.h"
#include "geoLoader.h"
#include "timer.h"
#include "vector.h"
#include "shader.h"
#include "gl_funcs.h"
#include "debug.h"
#define PI 3.14159265358979323846f

void run_shader(GLuint* shader_program, float angle, Mat* view, mesh* cube, Mat* proj, vec3 eye);

int main(void) {
	
	if (!glfwInit()) {
        	fprintf(stderr, "Failed to initialize GLFW\n");
        	return -1;
   	 }

	GLFWwindow* window = glfwCreateWindow(640, 480, "Spining CUBE", NULL, NULL);
    	if (!window) {
        	fprintf(stderr, "Failed to create GLFW window\n");
        	glfwTerminate();
        	return -1;
    	}

	
	glfwMakeContextCurrent(window);

	glViewport(0, 0, 640, 480);
	glClearColor(.1f, .1f, .1f, 1.f);


	

	float angle = 0.f;
	float current_time = 0.f;
	float prev_time = getTime();
	float delta_time = 0.f;
	GLuint shader_program;	
	vec3 eye = {.x = 0.f, .y = 0.f, .z = 5.f};
	vec3 center = {.x = 0.f, .y = 0.f, .z = 0.f};
	vec3 up = {.x = 0.f, .y = 1.f, .z = 0.f};
	Mat view;
	mat_look(&view, &eye, &center, &up);
	mesh cube = {0};
	load_geometry(&cube);
	create_buffer(&cube);
	GLuint shader = shader_create("/home/zaiah/c/3dcube/shaders/cube.vert", "/home/zaiah/c/3dcube/shaders/cube.frag");
	Mat proj;
	float fov = 45.f * (PI / 180.f);
	float aspect = 640.f / 480.f;
	makePerspectiveMatrix(&proj, fov, aspect, 0.1f, 100.f);
	float rotation_speed = 3.f;
	

    	while (!glfwWindowShouldClose(window)) {
	
		current_time = getTime();
	    	delta_time = getDeltaTime(&prev_time);

		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glFrontFace(GL_CCW);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(shader);

		glUniform3f(glGetUniformLocation(shader, "lightPos"), 0.0f, 5.0f, 0.0f);
		glUniform3f(glGetUniformLocation(shader, "viewPos"), eye.x, eye.y, eye.z);
		glUniform3f(glGetUniformLocation(shader, "lightColor"), 1.0f, 1.0f, 1.0f);
		glUniform3f(glGetUniformLocation(shader, "objectColor"), 1.0f, 0.5f, 0.31f);	



		angle += rotation_speed * delta_time;
	
		run_shader(&shader, angle, &view, &cube, &proj, eye);

		glUniform3f(glGetUniformLocation(shader, "lightPos"), 0.0f, 5.0f, 0.0f);
   		glUniform3f(glGetUniformLocation(shader, "viewPos"), eye.x, eye.y, eye.z);
        	
		glfwSwapBuffers(window);
		glfwPollEvents();
    	}

    	glfwDestroyWindow(window);
    	glfwTerminate();
    
return 0;
}


void run_shader(GLuint* shader_program, float angle, Mat* view, mesh* cube, Mat* proj, vec3 eye)
{
    
    Mat model;
    make_cube_model(&model, angle);
/*
    printf("Model Matrix:\n");
for (int i = 0; i < 16; ++i) {
    printf("%.2f ", model.arr[i]);
    if ((i + 1) % 4 == 0) printf("\n");
}
*/
    glUseProgram(*shader_program);

    shader_set_mat(*shader_program, "u_model", &model);
    shader_set_mat(*shader_program, "u_view", view);
    shader_set_mat(*shader_program, "u_projection", proj);

    glUniform3f(glGetUniformLocation(*shader_program, "lightPos"), 0.0f, 5.0f, 0.0f);
    glUniform3f(glGetUniformLocation(*shader_program, "viewPos"), eye.x, eye.y, eye.z);
    glUniform3f(glGetUniformLocation(*shader_program, "lightColor"), 1.0f, 1.0f, 1.0f);
    glUniform3f(glGetUniformLocation(*shader_program, "objectColor"), 1.0f, 0.5f, 0.31f);
  
    render_mesh(cube, *shader_program);
}

