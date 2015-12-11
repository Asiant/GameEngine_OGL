#include"window.h"

namespace GameEngine {
	namespace graphics{
		void win_resize(GLFWwindow* w, int width, int height); 

		Window::Window(const char* title, int width, int height) {
			m_title = title;
			m_width = width;
			m_height = height;
			if (!init()){
				glfwTerminate();
			}
			for (int i = 0; i < MAX_KEYS; i++){
				m_keys[i] = false;
			}
			for (int i = 0; i < MAX_BUTTONS; i++){
				m_MouseButtons[i] = false;
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
			
			//callback functions and icc init 
			glfwSetWindowUserPointer(m_window, this);
			glfwSetKeyCallback(m_window, key_callback);
			glfwSetMouseButtonCallback(m_window, mouse_button_callback);
			glfwSetCursorPosCallback(m_window, cursor_position_callback);
			glfwSetWindowSizeCallback(m_window,win_resize);
			
			
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
		bool Window::isKeyPressed(unsigned int keycode) const{
			if (keycode >= MAX_KEYS)
				return false;
			return m_keys[keycode];
		}
		bool Window::isMouseButtonPressed(unsigned int button_code) const{
			if (button_code >= MAX_KEYS)
				return false;
			return m_MouseButtons[button_code];
		}
		void Window::getMousePosition(double &x, double &y) const{
			x = mx;
			y = my;

		}
		void win_resize(GLFWwindow* w, int width, int height){
			glViewport(0, 0, width, height);
		}
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
			Window* win =(Window*)glfwGetWindowUserPointer(window);
			win->m_keys[key] = action != GLFW_RELEASE;

		}
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods){
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_MouseButtons[button] = action != GLFW_RELEASE;
		}
		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos){
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->mx = xpos;
			win->my = ypos;
		}
	}
}