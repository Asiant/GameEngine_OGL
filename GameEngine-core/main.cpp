#include <iostream>
#include"src/graphics/window.h"
#include "src/maths/maths.h"

int main(){
	using namespace GameEngine;
	using namespace graphics;
	using namespace maths;
	Window window("GE1", 800, 600);
	glClearColor(0.2f,0.1f,0.5f,0.6f);
	//std::cout << glGetString (GL_VERSION)<< std::endl;
	mat4 M1 = mat4::translation(vec3(2.0f, 6.9f, 1.9f));
	mat4 M2 = mat4::identity();
	mat4 M3 = M2*M1;
	std::cout << M1.columns[3];
	while (!window.closed()){
		//std::cout << "Width: " << window.getWidth() << "Height: " << window.getHeight()<<std::endl;
		window.clear();
		//glBegin(GL_TRIANGLES);
		//glVertex2f(0.5f, 0.5f);
		//glVertex2f(0.5f, -0.5f);
		//glVertex2f(-0.5f, 0.6f);
		//glEnd();
		/*if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)){
			std::cout << "Pressed <"<< std::endl;
		}
		double x, y;
		window.getMousePosition(x, y);
		std::cout << x << ", " << y << std::endl;*/
		window.update();
	}
	//system("PAUSE");
	return 0;
}