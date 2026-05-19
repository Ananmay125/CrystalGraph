#include "renderer.h"

int main() {

	Renderer renderer;

	renderer.init();
	
	GLFWwindow* rawWindow = renderer.getWindow();

	while (!renderer.shouldClose()) {

		glClearColor(0.02f, 0.03f, 0.02f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		renderer.swapBuffers();
		renderer.pollEvents();
	}

	renderer.clean();
	return 0;
}
