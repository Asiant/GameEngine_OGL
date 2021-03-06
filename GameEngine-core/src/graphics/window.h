#pragma once
#include<iostream>
#include<GL/glew.h>
#include<GLFW/glfw3.h>

#define MAX_KEYS	1024
#define MAX_BUTTONS 32

//callback methods need to be static or function.. not inside class
namespace GameEngine {
	namespace graphics{

		class Window{
			private:
				int m_width, m_height;
				const char* m_title;
				GLFWwindow* m_window;
				bool m_closed;
				bool m_keys[MAX_KEYS];
				bool m_MouseButtons[MAX_BUTTONS];
				double mx, my;
				  
			public:
				Window(const char* name, int width, int height);
				~Window();
				bool closed() const;
				void update();
				void clear() const;

				inline int getWidth() const { return m_width; }
				inline int getHeight() const { return m_height; }


				bool isKeyPressed(unsigned int keycode) const;
				bool isMouseButtonPressed(unsigned int button_code) const;
				void getMousePosition(double &x, double &y) const;
			private:
				bool init();
				friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
				friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
				friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		};
	
	}
}
/*******************************************************
Tests

if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)){
std::cout << "Pressed <"<< std::endl;
}
double x, y;
window.getMousePosition(x, y);
std::cout << x << ", " << y << std::endl;
*********************************************************/