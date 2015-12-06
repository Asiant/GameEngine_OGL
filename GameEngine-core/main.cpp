#include <GLFW/glfw3.h>
#include <iostream>
#include"src/graphics/window.h"
int main(){
	using namespace GameEngine;
	using namespace graphics;

	Window window("GE1", 800, 600);
	glClearColor(0.2f,0.1f,0.5f,0.6f);
	//std::cout << glGetString (GL_VERSION)<< std::endl;
	while (!window.closed()){
		//std::cout << "Width: " << window.getWidth() << "Height: " << window.getHeight()<<std::endl;
		window.clear();
		glBegin(GL_TRIANGLES);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(-0.5f, 0.6f);
		glEnd();

		window.update();
	}
	//system("PAUSE");
	return 0;
}