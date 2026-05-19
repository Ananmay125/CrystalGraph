#include "renderer.h"

void Renderer::init() {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, "CrystalGraph", nullptr, nullptr);
	if (!window) {
		std::cout << "GLFW window couldn't be created" << std::endl;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
	}
}

void Renderer::clean() {
	glfwDestroyWindow(window);
	glfwTerminate();
}

GLFWwindow* Renderer::getWindow() {
	return window;
}

bool Renderer::shouldClose() {
	return glfwWindowShouldClose(window);
}

void Renderer::swapBuffers() {
	glfwSwapBuffers(window);
}

void Renderer::pollEvents() {
	glfwPollEvents();
}