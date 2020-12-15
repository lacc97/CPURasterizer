#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

#include "../SIMD/SSE.h"
#include "../SIMD/AVX.h"

namespace Math
{
	__forceinline const SSEFloat Rsqrt(const SSEFloat& rhs)
	{
		const SSEFloat r = _mm_rsqrt_ps(rhs.m128);
		return _mm_add_ps(
			_mm_mul_ps(_mm_set_ps(1.5f, 1.5f, 1.5f, 1.5f), r),
			_mm_mul_ps(_mm_mul_ps(_mm_mul_ps(rhs, _mm_set_ps(-0.5f, -0.5f, -0.5f, -0.5f)), r),
			           _mm_mul_ps(r, r)));
	}

	__forceinline const AVXFloat Rsqrt(const AVXFloat& rhs)
	{
		const AVXFloat r = _mm256_rsqrt_ps(rhs.m256);

		return _mm256_add_ps(
			_mm256_mul_ps(_mm256_set_ps(1.5f, 1.5f, 1.5f, 1.5f, 1.5f, 1.5f, 1.5f, 1.5f), r),
			_mm256_mul_ps(
				_mm256_mul_ps(_mm256_mul_ps(rhs, _mm256_set_ps(-0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f)),
				              r),
				_mm256_mul_ps(r, r)));
	}

	template <class T>
	__forceinline T Dot(const Vec<3, T>& vec1, const Vec<3, T>& vec2)
	{
		return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
	}

	const __m256 absmask = _mm256_castsi256_ps(_mm256_set1_epi32(~(1 << 31)));

	__forceinline __m256 vecabs_and(__m256 v)
	{
		return _mm256_and_ps(absmask, v);
	}

	__forceinline AVXVec3f absVec(AVXVec3f& vec)
	{
		AVXVec3f out;

		out.x = vecabs_and(vec.x);
		out.y = vecabs_and(vec.y);
		out.z = vecabs_and(vec.z);

		return out;
	}
}
