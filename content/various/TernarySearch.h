/**
 * Author: Simon Lindholm
 * Date: 2015-05-12
 * License: CC0
 * Source: own work
 * Description: Smallest i in [a, b] maximizing f, $f(a) < \dots < f(i) \ge \dots \ge f(b)$.
 * Other side non-strict: (A) to <=, reverse loop (B). Minimize: > also at (B).
 * Time: O(\log(b-a))
 * Status: tested
 */
#pragma once

template<class F>
int ternSearch(int a, int b, F f) {
	assert(a <= b);
	while (b - a >= 5) {
		int mid = (a + b) / 2;
		if (f(mid) < f(mid + 1)) a = mid; // (A)
		else b = mid + 1;
	}
	for (int i = a + 1; i < b + 1; ++i) if (f(a) < f(i)) a = i; // (B)
	return a;
}
