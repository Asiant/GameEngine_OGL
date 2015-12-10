#include"window.h"

namespace GameEngine {
	namespace graphics{
		void winResize(GLFWwindow* w, int width, int height);
		Window::Window(const char* title, int width, int height) {
			m_title = title;
			m_width = width;
			m_height = height;
			if (!init()){
				glfwTerminate();
			}
		}
		Window::~Window(){
			glfwTerminate();
		}
		bool Window::init(){
			if (!glfwInit()){
				std::cout << "Failed to initialize GLFW";
				return false;
			}
			m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
			if (!m_window)
			{
				glfwTerminate();
				std::cout << "Failed to create window" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(m_window);
			glfwSetWindowSizeCallback(m_window,winResize);
			//start of glew part
			//this must be below glfw context created... IMPORTAINT
			//Remember to set GLEW_STATIC in preprocessor in props
			std::cout << "OpenGL: "<<glGetString(GL_VERSION) << std::endl;
			if (glewInit() != GLEW_OK){
				std::cout << "Could not Initlize glew! :(" << std::endl;
				return false;
			}
			//End of GLEW part

			return true;

		}
		void Window::clear() const{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
		bool Window::closed() const{
			return !(glfwWindowShouldClose(m_window)==0);
		}
		void Window::update(){
			glfwSwapBuffers(m_window);
			glfwGetFramebufferSize(m_window,&m_width,&m_height);
			//glViewport(0, 0, m_width, m_height);
			glfwPollEvents();

		}
		void winResize(GLFWwindow* w, int width, int height){
			glViewport(0, 0, width, height);
		}
	}
}