/**
 * Author: Ulf Lundstrom, Simon Lindholm
 * Date: 2009-08-15
 * License: CC0
 * Source: https://en.wikipedia.org/wiki/Tridiagonal_matrix_algorithm
 * Description: Solves $Ax = b$, A tridiagonal: diag $d_i$, super $p_i$ (row i, col i+1), sub $q_i$ (row i+1, col i).
 * For $a_i = b_i a_{i-1} + c_i a_{i+1} + d_i$, $1 \le i \le n$ ($a_0, a_{n+1}$ known):
 * $\{a_i\}$ = tridiagonal($\{1, -1, \dots, -1, 1\}$, $\{0, c_1, \dots, c_n\}$, $\{b_1, \dots, b_n, 0\}$, $\{a_0, d_1, \dots, d_n, a_{n+1}\}$).
 * Fails if the solution is not unique. Diagonally dominant / positive definite: tr and the zero check are not needed.
 * Time: O(N)
 * Status: Brute-force tested mod 5 and 7 and stress-tested for real matrices obeying the criteria above.
 */
#pragma once

typedef double T;
vector<T> tridiagonal(vector<T> diag, const vector<T>& super,
		const vector<T>& sub, vector<T> b) {
	int n = (int)b.size(); vector<int> tr(n);
	for (int i = 0; i < n - 1; ++i) {
		if (abs(diag[i]) < 1e-9 * abs(super[i])) { // diag[i] == 0
			b[i + 1] -= b[i] * diag[i + 1] / super[i];
			if (i + 2 < n) b[i + 2] -= b[i] * sub[i + 1] / super[i];
			diag[i + 1] = sub[i]; tr[++i] = 1;
		} else {
			diag[i + 1] -= super[i] * sub[i] / diag[i];
			b[i + 1] -= b[i] * sub[i] / diag[i];
		}
	}
	for (int i = n; i--;) {
		if (tr[i]) {
			swap(b[i], b[i - 1]);
			diag[i - 1] = diag[i];
			b[i] /= super[i - 1];
		} else {
			b[i] /= diag[i];
			if (i) b[i - 1] -= b[i] * super[i - 1];
		}
	}
	return b;
}
