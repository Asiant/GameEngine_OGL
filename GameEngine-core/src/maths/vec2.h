#pragma once
#include <iostream>

namespace GameEngine {
	namespace maths{
	
		struct vec2{
			float x, y;
			
			//constructors
			vec2();
			vec2(const float &x, const float &y);
			//operators
			vec2& add(const vec2& other);
			vec2& subtract(const vec2& other);
			vec2& multiply(const vec2& other);
			vec2& divide(const vec2& other);

			friend vec2 operator+(vec2, const vec2&);
			friend vec2 operator-(vec2, const vec2&);
			friend vec2 operator/(vec2, const vec2&);
			friend vec2 operator*(vec2, const vec2&);


			vec2& operator+=(const vec2& right);
			vec2& operator-=(const vec2& right);
			vec2& operator/=(const vec2& right);
			vec2& operator*=(const vec2& right);

			bool operator==(const vec2 & other);
			bool operator!=(const vec2 & other);
			friend std::ostream& operator<<(std:: ostream& stream, const vec2& vector);
		};


	}
}