#pragma once
#include<GL/glew.h>
namespace GameEngine {
	namespace graphics{
		class IndexBuffer{
		private:
			GLuint m_bufferID;
			GLuint m_Count;
		public:
			IndexBuffer(GLushort* data, GLsizei count);

			void bind() const;
			void unbind() const;

			GLuint getCount() const  { return m_Count; }
		};
	}
}