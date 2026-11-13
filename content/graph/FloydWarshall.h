/**
 * Author: Simon Lindholm
 * Date: 2016-12-15
 * License: CC0
 * Source: http://en.wikipedia.org/wiki/Floyd–Warshall_algorithm
 * Description: m[i][j] = inf if no edge. Result: inf if no path, -inf if through a negative cycle.
 * Time: O(N^3)
 * Status: slightly tested
 */
#pragma once

const ll inf = 1ll << 62;
void floydWarshall(vector<vector<ll>>& m) {
	int n = (int)m.size();
	for (int i = 0; i < n; ++i) m[i][i] = min(m[i][i], 0ll);
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (m[i][k] != inf && m[k][j] != inf) {
					auto newDist = max(m[i][k] + m[k][j], -inf);
					m[i][j] = min(m[i][j], newDist);
				}
	for (int k = 0; k < n; ++k) if (m[k][k] < 0)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (m[i][k] != inf && m[k][j] != inf) m[i][j] = -inf;
}
