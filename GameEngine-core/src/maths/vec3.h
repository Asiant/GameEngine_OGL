#pragma once
#include <iostream>

namespace GameEngine {
	namespace maths{
	
		struct vec3{
			float x, y, z;
			
			//constructors
			vec3();
			vec3(const float &x, const float &y, const float &z);
			//operators
			vec3& add(const vec3& other);
			vec3& subtract(const vec3& other);
			vec3& multiply(const vec3& other);
			vec3& divide(const vec3& other);

			friend vec3 operator+(vec3, vec3&);
			friend vec3 operator-(vec3, vec3&);
			friend vec3 operator/(vec3, vec3&);
			friend vec3 operator*(vec3, vec3&);


			vec3& operator+=(const vec3& right);
			vec3& operator-=(const vec3& right);
			vec3& operator/=(const vec3& right);
			vec3& operator*=(const vec3& right);

			bool operator==(const vec3 & other);
			bool operator!=(const vec3 & other);
			friend std::ostream& operator<<(std:: ostream& stream, const vec3& vector);
		};


	}
}