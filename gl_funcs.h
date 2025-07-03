#ifndef GL_FUNCS_H
#define GL_FUNCS_H

#include <GLFW/glfw3.h>

// Common OpenGL function pointer types
typedef void (*PFNGLENABLEPROC)(GLenum cap);
typedef void (*PFNGLCULLFACEPROC)(GLenum mode);
typedef void (*PFNGLFRONTFACEPROC)(GLenum mode);
typedef void (*PFNGLCLEARPROC)(GLbitfield mask);
typedef void (*PFNGLCLEARCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (*PFNGLVIEWPORTPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (*PFNGLDEBUGMESSAGECALLBACKPROC)(GLDEBUGPROC callback, const void *userParam);
typedef GLuint (*PFNGLCREATESHADERPROC)(GLenum type);
typedef void (*PFNGLSHADERSOURCEPROC)(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
typedef void (*PFNGLCOMPILESHADERPROC)(GLuint shader);
typedef void (*PFNGLGETSHADERIVPROC)(GLuint shader, GLenum pname, GLint *params);
typedef void (*PFNGLGETSHADERINFOLOGPROC)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef GLuint (*PFNGLCREATEPROGRAMPROC)(void);
typedef void (*PFNGLATTACHSHADERPROC)(GLuint program, GLuint shader);
typedef void (*PFNGLLINKPROGRAMPROC)(GLuint program);
typedef void (*PFNGLGETPROGRAMIVPROC)(GLuint program, GLenum pname, GLint *params);
typedef void (*PFNGLGETPROGRAMINFOLOGPROC)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (*PFNGLDELETESHADERPROC)(GLuint shader);
typedef void (*PFNGLUSEPROGRAMPROC)(GLuint program);
typedef GLint (*PFNGLGETUNIFORMLOCATIONPROC)(GLuint program, const GLchar *name);
typedef void (*PFNGLUNIFORMMATRIX4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*PFNGLUNIFORM3FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (*PFNGLGENVERTEXARRAYSPROC)(GLsizei n, GLuint *arrays);
typedef void (*PFNGLBINDVERTEXARRAYPROC)(GLuint array);
typedef void (*PFNGLGENBUFFERSPROC)(GLsizei n, GLuint *buffers);
typedef void (*PFNGLBINDBUFFERPROC)(GLenum target, GLuint buffer);
typedef void (*PFNGLBUFFERDATAPROC)(GLenum target, GLsizeiptr size, const void *data, GLenum usage);
typedef void (*PFNGLVERTEXATTRIBPOINTERPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
typedef void (*PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint index);
typedef void (*PFNGLDRAWELEMENTSPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices);
typedef void (*PFNGLDELETEBUFFERSPROC)(GLsizei n, const GLuint *buffers);
typedef void (*PFNGLDELETEVERTEXARRAYSPROC)(GLsizei n, const GLuint *arrays);

// Global function pointers
extern PFNGLENABLEPROC _glEnable;
extern PFNGLCULLFACEPROC _glCullFace;
extern PFNGLFRONTFACEPROC _glFrontFace;
extern PFNGLCLEARPROC _glClear;
extern PFNGLCLEARCOLORPROC _glClearColor;
extern PFNGLVIEWPORTPROC _glViewport;
extern PFNGLDEBUGMESSAGECALLBACKPROC _glDebugMessageCallback;
extern PFNGLCREATESHADERPROC _glCreateShader;
extern PFNGLSHADERSOURCEPROC _glShaderSource;
extern PFNGLCOMPILESHADERPROC _glCompileShader;
extern PFNGLGETSHADERIVPROC _glGetShaderiv;
extern PFNGLGETSHADERINFOLOGPROC _glGetShaderInfoLog;
extern PFNGLCREATEPROGRAMPROC _glCreateProgram;
extern PFNGLATTACHSHADERPROC _glAttachShader;
extern PFNGLLINKPROGRAMPROC _glLinkProgram;
extern PFNGLGETPROGRAMIVPROC _glGetProgramiv;
extern PFNGLGETPROGRAMINFOLOGPROC _glGetProgramInfoLog;
extern PFNGLDELETESHADERPROC _glDeleteShader;
extern PFNGLUSEPROGRAMPROC _glUseProgram;
extern PFNGLGETUNIFORMLOCATIONPROC _glGetUniformLocation;
extern PFNGLUNIFORMMATRIX4FVPROC _glUniformMatrix4fv;
extern PFNGLUNIFORM3FPROC _glUniform3f;
extern PFNGLGENVERTEXARRAYSPROC _glGenVertexArrays;
extern PFNGLBINDVERTEXARRAYPROC _glBindVertexArray;
extern PFNGLGENBUFFERSPROC _glGenBuffers;
extern PFNGLBINDBUFFERPROC _glBindBuffer;
extern PFNGLBUFFERDATAPROC _glBufferData;
extern PFNGLVERTEXATTRIBPOINTERPROC _glVertexAttribPointer;
extern PFNGLENABLEVERTEXATTRIBARRAYPROC _glEnableVertexAttribArray;
extern PFNGLDRAWELEMENTSPROC _glDrawElements;
extern PFNGLDELETEBUFFERSPROC _glDeleteBuffers;
extern PFNGLDELETEVERTEXARRAYSPROC _glDeleteVertexArrays;

void load_gl_functions();

#endif
