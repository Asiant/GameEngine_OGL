#pragma once
#include<iostream>
#include<GLFW/glfw3.h>

namespace GameEngine {
	namespace graphics{

		class Window{
			private:
				int m_width, m_height;
				const char* m_title;
				GLFWwindow* m_window;
				bool m_closed;
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