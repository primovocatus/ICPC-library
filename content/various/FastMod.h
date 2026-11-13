/**
 * Author: Simon Lindholm
 * Date: 2020-05-30
 * License: CC0
 * Source: https://en.wikipedia.org/wiki/Barrett_reduction
 * Description: $a \bmod b$ about 5x faster, b constant but unknown at compile time. Result in $[0, 2b)$.
 * Status: proven correct, stress-tested
 */
#pragma once

struct FastMod {
	ull b, m;
	FastMod(ull b) : b(b), m(-1ull / b) {}
	ull reduce(ull a) { // a % b + (0 or b)
		return a - (ull)((__uint128_t(m) * a) >> 64) * b;
	}
};
