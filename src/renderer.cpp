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

void Renderer::setWindowIcon(const char* filepath) {
	GLFWimage images[1]; 
	int channels;
	
	images[0].pixels = stbi_load(filepath, &images[0].width, &images[0].height, &channels, 4);

	if (images[0].pixels) {
	
		glfwSetWindowIcon(window, 1, images);

		stbi_image_free(images[0].pixels);
	}
	else {
		std::cout << "Failed to load window icon from: " << filepath << std::endl;
	}
}