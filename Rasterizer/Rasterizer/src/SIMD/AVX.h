#pragma once

#include "AVXBool.h"
#include "AVXInt.h"
#include "AVXFloat.h"

#include "../Math/Vec2.h"
#include "../Math/Vec3.h"

typedef Math::Vec<2, AVXFloat> AVXVec2f;
typedef Math::Vec<2, AVXInt> AVXVec2i;
typedef Math::Vec<2, AVXBool> AVXVec2b;

typedef Math::Vec<3, AVXFloat> AVXVec3f;
typedef Math::Vec<3, AVXInt> AVXVec3i;
typedef Math::Vec<3, AVXBool> AVXVec3b;

namespace AVX
{
	__forceinline bool All(const AVXBool& rhs) { return _mm256_movemask_ps(rhs) == 0xf; }
	__forceinline bool Any(const AVXBool& rhs) { return _mm256_movemask_ps(rhs) != 0x0; }
	__forceinline bool None(const AVXBool& rhs) { return _mm256_movemask_ps(rhs) == 0x0; }

	__forceinline AVXFloat Select(const AVXBool& m, const AVXFloat& t, const AVXFloat& f)
	{
		return _mm256_blendv_ps(f, t, m);
	}

	__forceinline AVXFloat Rcp(const AVXFloat& rhs)
	{
		const AVXFloat r = _mm256_rcp_ps(rhs.m256);
		return _mm256_sub_ps(_mm256_add_ps(r, r), _mm256_mul_ps(_mm256_mul_ps(r, r), rhs));
	}

	__forceinline AVXFloat operator +(const float& lhs, const AVXFloat& rhs) { return AVXFloat(lhs) + rhs; }
	__forceinline AVXFloat operator -(const float& lhs, const AVXFloat& rhs) { return AVXFloat(lhs) - rhs; }
	__forceinline AVXFloat operator *(const float& lhs, const AVXFloat& rhs) { return AVXFloat(lhs) * rhs; }
	__forceinline AVXFloat operator /(const float& lhs, const AVXFloat& rhs) { return lhs * Rcp(rhs); }
}
