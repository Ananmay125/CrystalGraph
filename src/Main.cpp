#include "renderer.h"
#include "interface.h"

int main() {

	Renderer renderer;
	Interface interface;

	renderer.init();

	GLFWwindow* rawWindow = renderer.getWindow();
	
	interface.initInterface(rawWindow);

	while (!renderer.shouldClose()) {

		glClearColor(0.02f, 0.03f, 0.02f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		interface.drawFrame();
		interface.renderFrame();

		renderer.swapBuffers();
		renderer.pollEvents();
	}

	interface.cleanInterface();
	renderer.clean();
	return 0;
}
