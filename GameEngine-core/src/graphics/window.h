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
				static bool m_keys[MAX_KEYS];
				static bool m_MouseButtons[MAX_BUTTONS];
				static double m_x, m_y;
				  
			public:
				Window(const char* name, int width, int height);
				~Window();
				bool closed() const;
				void update();
				void clear() const;

				inline int getWidth() const { return m_width; }
				inline int getHeight() const { return m_height; }

			private:
				bool init();
				
		};
	
	}
}