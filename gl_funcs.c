#include "gl_funcs.h"
#include <stdio.h>

// Global function pointer definitions
PFNGLENABLEPROC _glEnable;
PFNGLCULLFACEPROC _glCullFace;
PFNGLFRONTFACEPROC _glFrontFace;
PFNGLCLEARPROC _glClear;
PFNGLCLEARCOLORPROC _glClearColor;
PFNGLVIEWPORTPROC _glViewport;
PFNGLDEBUGMESSAGECALLBACKPROC _glDebugMessageCallback;
PFNGLCREATESHADERPROC _glCreateShader;
PFNGLSHADERSOURCEPROC _glShaderSource;
PFNGLCOMPILESHADERPROC _glCompileShader;
PFNGLGETSHADERIVPROC _glGetShaderiv;
PFNGLGETSHADERINFOLOGPROC _glGetShaderInfoLog;
PFNGLCREATEPROGRAMPROC _glCreateProgram;
PFNGLATTACHSHADERPROC _glAttachShader;
PFNGLLINKPROGRAMPROC _glLinkProgram;
PFNGLGETPROGRAMIVPROC _glGetProgramiv;
PFNGLGETPROGRAMINFOLOGPROC _glGetProgramInfoLog;
PFNGLDELETESHADERPROC _glDeleteShader;
PFNGLUSEPROGRAMPROC _glUseProgram;
PFNGLGETUNIFORMLOCATIONPROC _glGetUniformLocation;
PFNGLUNIFORMMATRIX4FVPROC _glUniformMatrix4fv;
PFNGLUNIFORM3FPROC _glUniform3f;
PFNGLGENVERTEXARRAYSPROC _glGenVertexArrays;
PFNGLBINDVERTEXARRAYPROC _glBindVertexArray;
PFNGLGENBUFFERSPROC _glGenBuffers;
PFNGLBINDBUFFERPROC _glBindBuffer;
PFNGLBUFFERDATAPROC _glBufferData;
PFNGLVERTEXATTRIBPOINTERPROC _glVertexAttribPointer;
PFNGLENABLEVERTEXATTRIBARRAYPROC _glEnableVertexAttribArray;
PFNGLDRAWELEMENTSPROC _glDrawElements;
PFNGLDELETEBUFFERSPROC _glDeleteBuffers;
PFNGLDELETEVERTEXARRAYSPROC _glDeleteVertexArrays;

void load_gl_functions() {
    _glEnable = (PFNGLENABLEPROC)glfwGetProcAddress("glEnable");
    _glCullFace = (PFNGLCULLFACEPROC)glfwGetProcAddress("glCullFace");
    _glFrontFace = (PFNGLFRONTFACEPROC)glfwGetProcAddress("glFrontFace");
    _glClear = (PFNGLCLEARPROC)glfwGetProcAddress("glClear");
    _glClearColor = (PFNGLCLEARCOLORPROC)glfwGetProcAddress("glClearColor");
    _glViewport = (PFNGLVIEWPORTPROC)glfwGetProcAddress("glViewport");
    _glDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC)glfwGetProcAddress("glDebugMessageCallback");
    _glCreateShader = (PFNGLCREATESHADERPROC)glfwGetProcAddress("glCreateShader");
    _glShaderSource = (PFNGLSHADERSOURCEPROC)glfwGetProcAddress("glShaderSource");
    _glCompileShader = (PFNGLCOMPILESHADERPROC)glfwGetProcAddress("glCompileShader");
    _glGetShaderiv = (PFNGLGETSHADERIVPROC)glfwGetProcAddress("glGetShaderiv");
    _glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)glfwGetProcAddress("glGetShaderInfoLog");
    _glCreateProgram = (PFNGLCREATEPROGRAMPROC)glfwGetProcAddress("glCreateProgram");
    _glAttachShader = (PFNGLATTACHSHADERPROC)glfwGetProcAddress("glAttachShader");
    _glLinkProgram = (PFNGLLINKPROGRAMPROC)glfwGetProcAddress("glLinkProgram");
    _glGetProgramiv = (PFNGLGETPROGRAMIVPROC)glfwGetProcAddress("glGetProgramiv");
    _glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)glfwGetProcAddress("glGetProgramInfoLog");
    _glDeleteShader = (PFNGLDELETESHADERPROC)glfwGetProcAddress("glDeleteShader");
    _glUseProgram = (PFNGLUSEPROGRAMPROC)glfwGetProcAddress("glUseProgram");
    _glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)glfwGetProcAddress("glGetUniformLocation");
    _glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)glfwGetProcAddress("glUniformMatrix4fv");
    _glUniform3f = (PFNGLUNIFORM3FPROC)glfwGetProcAddress("glUniform3f");
    _glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)glfwGetProcAddress("glGenVertexArrays");
    _glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)glfwGetProcAddress("glBindVertexArray");
    _glGenBuffers = (PFNGLGENBUFFERSPROC)glfwGetProcAddress("glGenBuffers");
    _glBindBuffer = (PFNGLBINDBUFFERPROC)glfwGetProcAddress("glBindBuffer");
    _glBufferData = (PFNGLBUFFERDATAPROC)glfwGetProcAddress("glBufferData");
    _glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)glfwGetProcAddress("glVertexAttribPointer");
    _glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)glfwGetProcAddress("glEnableVertexAttribArray");
    _glDrawElements = (PFNGLDRAWELEMENTSPROC)glfwGetProcAddress("glDrawElements");
    _glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)glfwGetProcAddress("glDeleteBuffers");
    _glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)glfwGetProcAddress("glDeleteVertexArrays");
}
