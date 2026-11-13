/**
 * Author: Mårten Wiman
 * License: CC0
 * Source: Pisinger 1999, "Linear Time Algorithms for Knapsack Problems with Bounded Weights"
 * Description: Max subset sum $\le t$, weights $\ge 0$.
 * Time: O(N \max(w_i))
 * Status: Tested on kattis:eavesdropperevasion, stress-tested
 */
#pragma once

int knapsack(vector<int> w, int t) {
	int a = 0, b = 0, x;
	while (b < (int)w.size() && a + w[b] <= t) a += w[b++];
	if (b == (int)w.size()) return a;
	int m = *max_element(w.begin(), w.end());
	vector<int> u, v(2 * m, -1);
	v[a + m - t] = b;
	for (int i = b; i < (int)w.size(); ++i) {
		u = v;
		for (int x = 0; x < m; ++x) v[x + w[i]] = max(v[x + w[i]], u[x]);
		for (x = 2 * m; --x > m;)
			for (int j = max<int>(0, u[x]); j < v[x]; ++j)
				v[x - w[j]] = max(v[x - w[j]], j);
	}
	for (a = t; v[a + m - t] < 0; a--) ;
	return a;
}
