#pragma once

#define IMGUI_DEFINE_MATH_OPERATORS 
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <iostream>

class Interface {
public:

	void initInterface(GLFWwindow* window);
	void drawFrame();
	void renderFrame();
	void cleanInterface();

private:


};