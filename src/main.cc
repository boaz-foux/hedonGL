

#ifndef _WIN32
#define GLEW_STATIC
#endif
#include <GL/glew.h>

#define GLFW_NO_GLU
#define GLFW_DLL
#include <GLFW/glfw3.h>
#include <node.h>
#include "hedon.h"

/* small patch */
std::vector<std::string> titles;
GLFWwindow* CreateWindow (int x , int y , std::string str){
	int i= titles.size(); 
	titles.push_back(str);
	return glfwCreateWindow( x ,  y ,  titles[i].data() ,NULL, NULL);
};
/* small patch */

#define INVOKE(I)   NODE_SET_METHOD(exports, #I,HEDON::BIND(I))

void Init( v8::Handle<v8::Object> exports) {
	// small patch
	glewExperimental=true; 
	INVOKE(CreateWindow);

	//gl 
	INVOKE(GL_AMBIENT);
	INVOKE(GL_AMBIENT_AND_DIFFUSE);
	INVOKE(GL_COLOR_BUFFER_BIT);
	INVOKE(GL_COLOR_MATERIAL);
	INVOKE(GL_CONSTANT_ATTENUATION);
	INVOKE(GL_DEPTH_BUFFER_BIT);
	INVOKE(GL_DEPTH_TEST);
	INVOKE(GL_DEPTH_TEST);
	INVOKE(GL_DEPTH);
	INVOKE(GL_DIFFUSE);
	INVOKE(GL_DOUBLE);
	INVOKE(GL_FRONT_AND_BACK);
	INVOKE(GL_LIGHT_MODEL_TWO_SIDE);
	INVOKE(GL_LIGHT0);
	INVOKE(GL_LIGHT1);
	INVOKE(GL_LIGHT2);
	INVOKE(GL_LIGHT3);
	INVOKE(GL_LIGHT4);
	INVOKE(GL_LIGHT5);
	INVOKE(GL_LIGHT6);
	INVOKE(GL_LIGHT7);
	INVOKE(GL_LIGHTING);
	INVOKE(GL_LINE);
	INVOKE(GL_LINEAR_ATTENUATION);
	INVOKE(GL_LINES);
	INVOKE(GL_LEQUAL);
	INVOKE(GL_MODELVIEW);
	INVOKE(GL_POLYGON);
	INVOKE(GL_POSITION);
	INVOKE(GL_PROJECTION);
	INVOKE(GL_RGB);
	INVOKE(GL_RGBA);
	INVOKE(GL_TEXTURE_2D);
	INVOKE(GL_TRUE);
	INVOKE(GL_SMOOTH);
	INVOKE(GL_SPECULAR);
	INVOKE(GL_SPOT_CUTOFF);
	INVOKE(GL_SPOT_DIRECTION);
	INVOKE(GL_SPOT_EXPONENT);
	INVOKE(GL_SHININESS);
	INVOKE(GL_QUADRATIC_ATTENUATION);

	INVOKE(glAccum);
	INVOKE(glAlphaFunc);
	INVOKE(glBegin);
	INVOKE(glBindTexture);
	INVOKE(glBitmap);
	INVOKE(glBlendFunc);
	INVOKE(glCallList);
	INVOKE(glCallLists);
	INVOKE(glClear);
	INVOKE(glClearAccum);
	INVOKE(glClearColor);
	INVOKE(glClearDepth);
	INVOKE(glClearIndex);
	INVOKE(glClearStencil);
	INVOKE(glClipPlane);
	INVOKE(glColor3f);
	INVOKE(glColorMaterial);
	INVOKE(glColorPointer);
	INVOKE(glCopyPixels);
	INVOKE(glCopyTexImage1D);
	INVOKE(glCopyTexImage2D);
	INVOKE(glCullFace);
	INVOKE(glDeleteLists);
	INVOKE(glDeleteTextures);
	INVOKE(glDepthFunc);
	INVOKE(glDepthMask);
	INVOKE(glDepthRange);
	INVOKE(glDisable);
	INVOKE(glDisableClientState);
	INVOKE(glDrawArrays);
	INVOKE(glDrawBuffer);
	INVOKE(glDrawElements);
	INVOKE(glDrawPixels);
	INVOKE(glEdgeFlagPointer);
	INVOKE(glEnable);
	INVOKE(glEnableClientState);
	INVOKE(glEnd);
	INVOKE(glEndList);
	INVOKE(GLEW_OK);
	INVOKE(glewInit);
	INVOKE(glFeedbackBuffer);
	INVOKE(glFinish);
	INVOKE(glFlush);
	INVOKE(glFrontFace);
	INVOKE(glFrustum);
	INVOKE(glGenLists);
	INVOKE(glGetClipPlane);
	INVOKE(glGetError);
	INVOKE(glGetPixelMapfv);
	INVOKE(glGetPointerv);
	INVOKE(glGetPolygonStipple);
	INVOKE(glGetString);
	INVOKE(glGetTexImage);
	INVOKE(glLightfv);
	INVOKE(glLoadIdentity);
	INVOKE(glMatrixMode);
	INVOKE(glMaterialfv);
	INVOKE(glOrtho);
	INVOKE(glPopMatrix);
	INVOKE(glPushMatrix);
	INVOKE(glRotatef);
	INVOKE(glScalef);
	INVOKE(glShadeModel);
	INVOKE(glTranslatef);
	INVOKE(glVertex3f);
	INVOKE(glViewport);
	// glfw
	INVOKE(GLFW_CONTEXT_VERSION_MAJOR);
	INVOKE(GLFW_CONTEXT_VERSION_MINOR);
	INVOKE(GLFW_KEY_ESCAPE);
	INVOKE(GLFW_OPENGL_CORE_PROFILE); 
	INVOKE(GLFW_OPENGL_FORWARD_COMPAT); 
	INVOKE(GLFW_OPENGL_PROFILE);
	INVOKE(GLFW_PRESS);
	INVOKE(GLFW_SAMPLES);
	INVOKE(GLFW_STICKY_KEYS);
	INVOKE(glfwCreateCursor);
	INVOKE(glfwCreateWindow);
	INVOKE(glfwCreateWindow);
	INVOKE(glfwDestroyCursor);
	INVOKE(glfwDestroyWindow);
	INVOKE(glfwGetKey);
	INVOKE(glfwGetMonitors);
	INVOKE(glfwInit);
	INVOKE(glfwMakeContextCurrent);
	INVOKE(glfwPollEvents);
	INVOKE(glfwSetCursorEnterCallback);
	INVOKE(glfwSetCursorPosCallback);
	INVOKE(glfwSetFramebufferSizeCallback);
	INVOKE(glfwSetInputMode);
	INVOKE(glfwSetKeyCallback);
	INVOKE(glfwSetMouseButtonCallback);
	INVOKE(glfwSetScrollCallback);
	INVOKE(glfwSetWindowCloseCallback);
	INVOKE(glfwSetWindowFocusCallback);
	INVOKE(glfwSetWindowIconifyCallback);
	INVOKE(glfwSetWindowPosCallback);
	INVOKE(glfwSetWindowRefreshCallback);
	INVOKE(glfwSetWindowSizeCallback);
	INVOKE(glfwSwapBuffers);
	INVOKE(glfwTerminate);
	INVOKE(glfwWindowHint);
	INVOKE(glfwWindowShouldClose);
	// glu
	INVOKE(GLU_SMOOTH);
	INVOKE(gluLookAt);
	INVOKE(gluNewNurbsRenderer);
	INVOKE(gluNewQuadric);
	INVOKE(gluNewTess);
	INVOKE(gluNextContour);
	INVOKE(gluNurbsCallback);
	INVOKE(gluNurbsCallbackData);
	INVOKE(gluNurbsCallbackDataEXT);
	INVOKE(gluNurbsCurve);
	INVOKE(gluNurbsProperty);
	INVOKE(gluNurbsSurface);
	INVOKE(gluOrtho2D);
	INVOKE(gluPartialDisk);
	INVOKE(gluPerspective);
	INVOKE(gluPickMatrix);
	INVOKE(gluProject);
	INVOKE(gluPwlCurve);
	INVOKE(gluQuadricCallback);
	INVOKE(gluQuadricDrawStyle);
	INVOKE(gluQuadricNormals);
	INVOKE(gluQuadricOrientation);
	INVOKE(gluScaleImage);
	INVOKE(gluSphere);
	INVOKE(gluTessBeginContour);
	INVOKE(gluTessBeginPolygon);
	INVOKE(gluTessCallback);
	INVOKE(gluTessEndContour);
	INVOKE(gluTessEndPolygon);
	INVOKE(gluTessNormal);
	INVOKE(gluTessProperty);
	INVOKE(gluTessVertex);
	INVOKE(gluUnProject);
	INVOKE(gluUnProject4);
}


NODE_MODULE(hello, Init);