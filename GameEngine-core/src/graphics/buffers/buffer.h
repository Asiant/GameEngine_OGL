#pragma once
#include<GL/glew.h>
namespace GameEngine {
	namespace graphics{
		class Buffer{
		private:
			GLuint m_bufferID;
			GLuint m_componentCount;
		public:
			Buffer(GLfloat* data, GLsizei count, GLuint componentCounr);

			void bind() const;
			void unbind() const;

			GLuint getComponentCount() const  { return m_componentCount; }
		};
	}
}