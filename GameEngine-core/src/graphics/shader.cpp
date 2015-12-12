#include"shader.h"

namespace GameEngine {
	namespace graphics{
		Shader::Shader(const char* vartPath, const char * fragPath):m_vartPath(vartPath), m_fragPath(fragPath){
			m_shaderID = load();
		}
		GLuint Shader::load(){
			GLuint program = glCreateProgram();
			//both vert and frag needed reqired !!
			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

			std::string vertSource = utils::read_file(m_vartPath);
			std::string fragSource = utils::read_file(m_fragPath);
			const char* v = vertSource.c_str();
			const char* f = fragSource.c_str();
			glShaderSource(vertex, 1, &v, NULL);
			glCompileShader(vertex);

			GLint result;
			glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE){
				GLint length;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertex, length, &length, &error[0]);
				std::cout << &error[0] << std::endl;
				glDeleteShader(vertex);
				return 0;
			}

			glShaderSource(fragment, 1, &f, NULL);
			glCompileShader(fragment);

			//GLint result;
			glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE){
				GLint length;
				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(fragment, length, &length, &error[0]);
				std::cout << &error[0] << std::endl;
				glDeleteShader(fragment);
				return 0;
			}

			glAttachShader(program, vertex);
			glAttachShader(program, fragment);

			glLinkProgram(program);
			glValidateProgram(program);

			glDeleteShader(vertex);
			glDeleteShader(fragment);

			return program;
		}
		GLint Shader::getUniformLocation(const GLchar* name){
			return glGetUniformLocation(m_shaderID, name);
		}

		void Shader::setUniform1f(const char* name, float value){
			glUniform1f(getUniformLocation(name), value);
		}

		void Shader::setUniform2f(const char* name, const maths::vec2& value){
			glUniform2f(getUniformLocation(name), value.x, value.y);
		}

		void Shader::setUniform3f(const char* name, const maths::vec3& value){
			glUniform3f(getUniformLocation(name), value.x, value.y, value.z);
		}

		void Shader::setUniform4f(const char* name, const maths::vec4& value){
			glUniform4f(getUniformLocation(name), value.x, value.y, value.z, value.w);
		}

		void Shader::setUniform1i(const char* name, int value){
			glUniform1i(getUniformLocation(name), value);
		}

		void Shader::setUniformMat4(const char* name, const maths::mat4 &matrix){
			glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.elements);
		}



		void Shader::enable() const{
			glUseProgram(m_shaderID);
		}
		void Shader::disable() const{
			glUseProgram(0);
		}
		Shader::~Shader(){
			glDeleteProgram(m_shaderID);
		}
	}
}