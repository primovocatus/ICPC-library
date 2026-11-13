/**
 * Author: Simon Lindholm
 * Date: 2015-02-11
 * License: CC0
 * Source: Wikipedia
 * Description: Adaptive Simpson. Nested integrals: quad(-1, 1, [](d x) \{ return quad(-1, 1, ...); \}).
 * Status: mostly untested
 */
#pragma once

typedef double d;
#define SMP(a, b) (f(a) + 4 * f((a + b) / 2) + f(b)) * (b - a) / 6

template <class F>
d rec(F& f, d a, d b, d eps, d S) {
	d c = (a + b) / 2;
	d S1 = SMP(a, c), S2 = SMP(c, b), T = S1 + S2;
	if (abs(T - S) <= 15 * eps || b - a < 1e-10)
		return T + (T - S) / 15;
	return rec(f, a, c, eps / 2, S1) + rec(f, c, b, eps / 2, S2);
}
template<class F>
d quad(d a, d b, F f, d eps = 1e-8) {
	return rec(f, a, b, eps, SMP(a, b));
}
