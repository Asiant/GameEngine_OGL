#pragma once
#include<iostream>
#include"../utils/fileutils.h"
#include"../maths/maths.h"
#include<vector>
#include<GL/glew.h>
namespace GameEngine {
	namespace graphics{
		class Shader{// way to program Graphics Card!!
		private:
			GLuint m_shaderID;
			const char* m_vartPath; 
			const char* m_fragPath;
		public:
			Shader(const char* vartPath, const char * fragPath);
			~Shader();
			


			void setUniform1f(const char* name, float value);
			void setUniform2f(const char* name, const maths::vec2& value);
			void setUniform3f(const char* name, const maths::vec3& value); 
			void setUniform4f(const char* name, const maths::vec4& value);
			void setUniform1i(const char* name, int value);
			void setUniformMat4(const char* name, const maths::mat4 &matrix);

			void enable() const;
			void disable() const;
		private:
			GLuint load();
			GLint getUniformLocation(const GLchar* name);
		};
	}
}