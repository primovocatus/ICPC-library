/**
 * Author: chilli, pajenegod
 * Date: 2020-02-20
 * License: CC0
 * Source: Folklore
 * Description: Root 0, C = adjacency list (directed or undirected). Euler tour + sparse table.
 * dist(a, b) = depth[a] + depth[b] - 2 * depth[lca(a, b)].
 * Time: $O(N \log N + Q)$
 * Status: stress-tested
 */
#pragma once

struct LCA {
	int T = 0;
	vector<int> time, path, ret;
	vector<vector<int>> st;

	LCA(vector<vector<int>>& C) : time((int)C.size()) {
		dfs(C, 0, -1);
		st.assign(1, ret);
		for (int pw = 1, k = 1; pw * 2 <= (int)ret.size(); pw *= 2, ++k) {
			st.emplace_back((int)ret.size() - pw * 2 + 1);
			for (int j = 0; j < (int)st[k].size(); ++j)
				st[k][j] = min(st[k - 1][j], st[k - 1][j + pw]);
		}
	}
	void dfs(vector<vector<int>>& C, int v, int par) {
		time[v] = T++;
		for (int y : C[v]) if (y != par) {
			path.push_back(v), ret.push_back(time[v]);
			dfs(C, y, v);
		}
	}

	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		int d = __lg(b - a);
		return path[min(st[d][a], st[d][b - (1 << d)])];
	}
};
