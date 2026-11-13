/**
 * Author: Chen Xing
 * Date: 2009-10-13
 * License: CC0
 * Source: N/A
 * Description: Edge flow: compare capacities before and after, take the positive values.
 * Time: O(VE^2)
 * Status: stress-tested
 */
#pragma once

template<class T> T edmondsKarp(vector<unordered_map<int, T>>& g, int source, int sink) {
	assert(source != sink);
	T flow = 0;
	vector<int> par((int)g.size()), q = par;

	for (; ;) {
		fill(par.begin(), par.end(), -1);
		par[source] = 0;
		int ptr = 1;
		q[0] = source;

		for (int i = 0; i < ptr; ++i) {
			int x = q[i];
			for (auto e : g[x]) {
				if (par[e.first] == -1 && e.second > 0) {
					par[e.first] = x;
					q[ptr++] = e.first;
					if (e.first == sink) goto out;
				}
			}
		}
		return flow;
out:
		T inc = numeric_limits<T>::max();
		for (int y = sink; y != source; y = par[y])
			inc = min(inc, g[par[y]][y]);

		flow += inc;
		for (int y = sink; y != source; y = par[y]) {
			int p = par[y];
			if ((g[p][y] -= inc) <= 0) g[p].erase(y);
			g[y][p] += inc;
		}
	}
}
