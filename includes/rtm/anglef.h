#pragma once

////////////////////////////////////////////////////////////////////////////////
// The MIT License (MIT)
//
// Copyright (c) 2018 Nicholas Frechette & Realtime Math contributors
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
////////////////////////////////////////////////////////////////////////////////

#include "rtm/math.h"
#include "rtm/impl/angle_common.h"

namespace rtm
{
	//////////////////////////////////////////////////////////////////////////
	// Converts degrees into radians.
	//////////////////////////////////////////////////////////////////////////
	constexpr float scalar_deg_to_rad(float deg) RTM_NO_EXCEPT
	{
		return deg * ((float)k_pi / 180.0f);
	}

	//////////////////////////////////////////////////////////////////////////
	// Converts radians into degrees.
	//////////////////////////////////////////////////////////////////////////
	constexpr float scalar_rad_to_deg(float rad) RTM_NO_EXCEPT
	{
		return rad * (180.0f / (float)k_pi);
	}

	//////////////////////////////////////////////////////////////////////////
	// An angle class for added type safety.
	//////////////////////////////////////////////////////////////////////////
	class anglef
	{
	public:
		constexpr anglef() RTM_NO_EXCEPT : m_radians(0.0f) {}

		constexpr float as_radians() const { return m_radians; }
		constexpr float as_degrees() const { return scalar_rad_to_deg(m_radians); }

	protected:
		constexpr anglef(float rad) RTM_NO_EXCEPT : m_radians(rad) {}

		float m_radians;

		friend constexpr anglef radians(float rad);
		friend constexpr anglef degrees(float rad);
	};

	//////////////////////////////////////////////////////////////////////////
	// Returns the proper angle type for a floating point type.
	//////////////////////////////////////////////////////////////////////////
	template<> struct angle_type<float> { using type = anglef; };

	//////////////////////////////////////////////////////////////////////////
	// Constructs an angle from a radians value.
	//////////////////////////////////////////////////////////////////////////
	constexpr anglef radians(float rad)
	{
		return anglef(rad);
	}

	//////////////////////////////////////////////////////////////////////////
	// Constructs an angle from a degrees value.
	//////////////////////////////////////////////////////////////////////////
	constexpr anglef degrees(float deg)
	{
		return anglef(scalar_deg_to_rad(deg));
	}
}
