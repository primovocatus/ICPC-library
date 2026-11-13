/**
 * Author: Simon Lindholm
 * Date: 2017-05-10
 * License: CC0
 * Source: Wikipedia
 * Description: Polynomial of degree n-1 through (x[i], y[i]), res[i] = coefficient of $x^i$.
 * For precision pick $x[k] = c \cos(k / (n-1) \pi)$.
 * Time: O(n^2)
 */
#pragma once

typedef vector<double> vd;
vd interpolate(vd x, vd y, int n) {
	vd res(n), temp(n);
	for (int k = 0; k < n - 1; ++k)
		for (int i = k + 1; i < n; ++i)
			y[i] = (y[i] - y[k]) / (x[i] - x[k]);
	double last = 0; temp[0] = 1;
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i) {
			res[i] += y[k] * temp[i];
			swap(last, temp[i]);
			temp[i] -= last * x[k];
		}
	return res;
}
