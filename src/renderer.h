#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "stb_image.h"

class Renderer {
public:

	void init();
	bool shouldClose();
	void swapBuffers();
	void pollEvents();
	void clean();

	GLFWwindow* getWindow();
	void setWindowIcon(const char* filepath);

private:

	GLFWwindow* window;
	int width = 1000;
	int height = 600;

};