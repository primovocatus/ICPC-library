/**
 * Author: Lucian Bicsi
 * Date: 2015-06-25
 * License: CC0
 * Source: csacademy
 * Description: $c[z] = \sum_{z = x \oplus y} a[x] \cdot b[y]$, $\oplus$ = AND / OR / XOR. Size of a: power of two.
 * Time: O(N \log N)
 * Status: stress-tested
 */
#pragma once

void FST(vector<int>& a, bool inv) {
	for (int n = (int)a.size(), step = 1; step < n; step *= 2) {
		for (int i = 0; i < n; i += 2 * step)
			for (int j = i; j < i + step; ++j) {
				int &u = a[j], &v = a[j + step]; tie(u, v) =
					inv ? pair<int, int>(v - u, u) : pair<int, int>(v, u + v); // AND
					// inv ? pair<int, int>(v, u - v) : pair<int, int>(u + v, u); // OR /// include-line
					// pair<int, int>(u + v, u - v);                   // XOR /// include-line
			}
	}
	// if (inv) for (int& x : a) x /= (int)a.size(); // XOR only /// include-line
}
vector<int> conv(vector<int> a, vector<int> b) {
	FST(a, 0); FST(b, 0);
	for (int i = 0; i < (int)a.size(); ++i) a[i] *= b[i];
	FST(a, 1); return a;
}
