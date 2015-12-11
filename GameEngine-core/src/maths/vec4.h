#pragma once
#include <iostream>

namespace GameEngine {
	namespace maths{

		struct vec4{
			float x, y, z, w;

			//constructors
			vec4();
			vec4(const float &x, const float &y, const float &z, const float &w);
			//operators
			vec4& add(const vec4& other);
			vec4& subtract(const vec4& other);
			vec4& multiply(const vec4& other);
			vec4& divide(const vec4& other);

			friend vec4 operator+(vec4, vec4&);
			friend vec4 operator-(vec4, vec4&);
			friend vec4 operator/(vec4, vec4&);
			friend vec4 operator*(vec4, vec4&);


			vec4& operator+=(const vec4& right);
			vec4& operator-=(const vec4& right);
			vec4& operator/=(const vec4& right);
			vec4& operator*=(const vec4& right);

			bool operator==(const vec4 & other);
			bool operator!=(const vec4 & other);
			friend std::ostream& operator<<(std::ostream& stream, const vec4& vector);
		};


	}
}