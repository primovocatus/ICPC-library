/**
 * Author: 
 * Description: n x m matrix over T (ll, Mod, double, ...). bpow(a, k): square a, $k \ge 0$.
 * Time: O(n^3 \log k)
 */
#pragma once

template<class T> struct Matrix {
	int n, m;
	vector<vector<T>> a;
	Matrix(int n, int m) : n(n), m(m), a(n, vector<T>(m)) {}
	Matrix operator*(const Matrix& b) const {
		assert(m == b.n);
		Matrix res(n, b.m);
		for (int i = 0; i < n; ++i)
			for (int k = 0; k < m; ++k)
				for (int j = 0; j < b.m; ++j)
					res.a[i][j] = res.a[i][j] + a[i][k] * b.a[k][j];
		return res;
	}
};

template<class T> Matrix<T> bpow(Matrix<T> a, ll k) {
	Matrix<T> res(a.n, a.n);
	for (int i = 0; i < a.n; ++i) res.a[i][i] = 1;
	for (; k; k >>= 1, a = a * a)
		if (k & 1) res = res * a;
	return res;
}
