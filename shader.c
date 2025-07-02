#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "camera.h"
#include "matrix.h"
#include "vector.h"
#include "shader.h"
#include <stdlib.h>

char* load_file(const char* filename)
{
	FILE* f = fopen(filename, "r");
	if(f == NULL)
	{
		perror("Error opening file");
		return NULL;
	}

	fseek(f, 0, SEEK_END);
	long length = ftell(f);
	rewind(f);
	char* buffer = (char*)malloc(length + 1);
	fread(buffer, 1, length, f);
	buffer[length] = '\0';
	fclose(f);
	return buffer;
}

GLuint compile_shader(const char* source, GLenum type)
{
	GLuint id = glCreateShader(type);
	glShaderSource(id, 1, source, NULL);
	glCompileShader(id);
	char infoLog[512];
	int success;
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);
	if(!success)
	{
	   glGetShaderInfoLog(id, 512, NULL, infoLog);
      	   fprintf(stderr, "Shader compile error (%d): %s\n", type, infoLog);	
	}
	
	return id;
}


GLuint link_program(GLuint vertexShader, GLuint fragmentShader)
{
	GLuint program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);

 	GLint success;
    	char infoLog[512];
    	glGetProgramiv(program, GL_LINK_STATUS, &success);
    	if (!success) {
        	glGetProgramInfoLog(program, 512, NULL, infoLog);
       		fprintf(stderr, "Program link error: %s\n", infoLog);
    	}	

	return program;
}

shader shader_create(const char* vertexPath, const char* fragmentPath)
{
	char* vertex_source = load_file(vertexPath);
	char* fragment_source = load_file(fragmentPath);

	if(vertex_source == NULL || fragment_source == NULL)
	{
		exit(-1);
	}

	GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, (const char**)&vertex_source, NULL);
	glCompileShader(vertex_shader);

	int success;
	char infoLog[512];
	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
		fprintf(stderr, "Vertex shader compilation error:\n%s\n", infoLog);
	}

	GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, (const char**)&fragment_source, NULL);
	glCompileShader(fragment_shader);

	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(fragment_shader, 512, NULL, infoLog);
		fprintf(stderr, "Fragment shader compilation error:\n%s\n", infoLog);
	}
	
	GLuint shader_program =	link_program(vertex_shader, fragment_shader);

	glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
  	if(!success) 
	{
        	glGetProgramInfoLog(shader_program, 512, NULL, infoLog);
       	 	fprintf(stderr, "Shader program linking error:\n%s\n", infoLog);
    	}

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
	free(vertex_source);
	free(fragment_source);
	
	shader s;
	s.id = shader_program;
	return s;
}

void shader_set_mat(GLuint shader_program, const char* name, const Mat* matrix)
{
	glUseProgram(shader_program);

	GLint location = glGetUniformLocation(shader_program, name);
	if(location == -1)
	{
		fprintf(stderr, "Warning: Uniform '%s' not found or in unused in shader.\n", name);
		return;
	}

	glUniformMatrix4fv(location, 1, GL_FALSE, matrix->arr);
}
