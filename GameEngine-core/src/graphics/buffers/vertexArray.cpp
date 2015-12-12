#include"vertexArray.h"
namespace GameEngine {
	namespace graphics{
		VertexArray::VertexArray(){
			glGenVertexArrays(1, &m_ArrayID);
		}
		VertexArray::~VertexArray(){
			int n = m_Buffers.size();
			for (int i = 0; i < n ; i++){
				delete m_Buffers[i];
			}
		}

		void VertexArray::addBuffer(Buffer *buffer, GLuint index){
			bind();
			buffer->bind();

			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

			buffer->unbind();
			unbind();
		}
		void VertexArray::bind() const{ glBindVertexArray(m_ArrayID); }
		void VertexArray::unbind() const{ glBindVertexArray(0); }
	}
}