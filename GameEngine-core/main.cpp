#include <iostream>
#include"src/graphics/shader.h"
#include"src/graphics/window.h"
#include"src/maths/maths.h"
#include"src\graphics\buffers\buffer.h"
#include"src\graphics\buffers\IndexBuffer.h"
#include"src\graphics\buffers\vertexArray.h"

int main(){
	using namespace GameEngine;
	using namespace graphics;
	using namespace maths;

	Window window("GE1", 800, 400);
	//glClearColor(0.2f,0.1f,0.5f,0.6f);
	GLfloat vertices[] = {
		5.0f, 5.0f, 0.0f,
		10.5f, 5.0f, 0.0f,
		10.5f, 10.5f, 0.0f,
		5.0f, 10.5f, 0.0f,
	};
	GLushort indices[] = {
		0,1,2,
		2,3,0
	};
	VertexArray vao;
	Buffer *vbo = new Buffer(vertices, 4 * 3, 3);
	IndexBuffer ibo(indices, 6);
	vao.addBuffer(vbo, 0);

	mat4 ortho = mat4::orthographic(0.0f,12.0f, 0.0f, 15.0f, -1.0f, 1.0f);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_martix", ortho);
	//shader.setUniformMat4("m1_martix", mat4::rotation(45.0f, vec3(0.0f,0.0f,1.0f)));
	//shader.setUniformMat4("m1_martix", mat4::translation(vec3(-3.0f, 2.0f, 1.0f)));

	shader.setUniform2f("light_pos", vec2(6.0f, 7.5f));
	shader.setUniform4f("colour", vec4(0.2f, 0.3f, 0.8f, 0.9f));


	while (!window.closed()){
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 12.0f / 800.0f), 15.0f -(float)(y * 15.0f / 400.0f)));
		vao.bind();
		ibo.bind();
		shader.setUniformMat4("m1_martix", mat4::translation(vec3(-3.0f, 2.0f, 0.0f)));
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
		shader.setUniformMat4("m1_martix", mat4::translation(vec3(0.0f, 0.0f, 0.0f)));
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);

		ibo.unbind();
		vao.unbind();
		
		window.update();
	}
	return 0;
}
/*
std::cout << glGetString (GL_VERSION)<< std::endl;
std::cout << "Width: " << window.getWidth() << "Height: " << window.getHeight()<<std::endl;
glBegin(GL_TRIANGLES);
glVertex2f(0.5f, 0.5f);
glVertex2f(0.5f, -0.5f);
glVertex2f(-0.5f, 0.6f);
glEnd();
if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)){
std::cout << "Pressed <"<< std::endl;
}
double x, y;
window.getMousePosition(x, y);
std::cout << x << ", " << y << std::endl;
*/
/*
OLD WAY LEL :D
GLfloat vertices[] = {
5.0f,  5.0f, 0.0f,
10.5f,  5.0f, 0.0f,
10.5f,  10.5f, 0.0f,
10.5f,  10.5f, 0.0f,
5.0f,  10.5f, 0.0f,
5.0f,  5.0f, 0.0f
};
GLuint vbo;
glGenBuffers(1, &vbo);
glBindBuffer(GL_ARRAY_BUFFER, vbo);
glBufferData(GL_ARRAY_BUFFER,sizeof(vertices), vertices, GL_STATIC_DRAW);
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
glEnableVertexAttribArray(0);


while (!window.closed()){
window.clear();
double x, y;
window.getMousePosition(x, y);
shader.setUniform2f("light_pos", vec2((float)(x * 12.0f / 800.0f), 15.0f -(float)(y * 15.0f / 400.0f)));
glDrawArrays(GL_TRIANGLES,0,6);
std::cout << x << ", " << y << std::endl;
window.update();
}
*/