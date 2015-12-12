#pragma once
#include"vec2.h"
#include"vec3.h"
#include"vec4.h"
#include"mat4.h"
/***************************************
Tests Vectors

vec2 a2(0.2f,0.32f), b2(1.32f,43.1f);
vec3 a3(0.2f, 2.43f, 0.32f), b3(-1.2f, 0.43f, 2.32f);
vec4 a4(0.2f, 2.43f, 0.32f, 0.22f), b4(0.2f, 2.43f, 0.32f,1.0f);
std::cout << a2 << std::endl;
std::cout << a3 << std::endl;
std::cout << a4 << std::endl;

std::cout << a2 + b2 << std::endl;
std::cout << a3 + b3 << std::endl;
std::cout << a4 + b4 << std::endl;

std::cout << a2 << std::endl;
std::cout << a3 << std::endl;
std::cout << a4 << std::endl;=
**************************************
Matrix Test

mat4 M1 = mat4::translation(vec3(2.0f, 6.9f, 1.9f));
mat4 M2 = mat4::identity();
mat4 M3 = M2*M1;
std::cout << M1.columns[3];


****************************************/

