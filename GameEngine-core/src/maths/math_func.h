#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

namespace GameEngine {
	namespace maths{
		float toRadians(float degrees){//degree arg should be standard
			return degrees * (M_PI / 180.0f);
		}
	}
}