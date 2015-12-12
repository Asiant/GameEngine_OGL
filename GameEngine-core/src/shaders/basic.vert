#version 330 core

layout (location = 0) in vec4 position;

uniform mat4 pr_martix;
uniform mat4 vw_martix = mat4(1.0);
uniform mat4 m1_martix = mat4(1.0);

out vec4 pos;
void main()
{
	gl_Position = pr_martix * vw_martix * m1_martix * position;
	pos = position;
}