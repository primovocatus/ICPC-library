/**
 * Author: Benjamin Qi, Oleksandr Kulkov, chilli
 * Date: 2020-01-12
 * License: CC0
 * Source: https://codeforces.com/blog/entry/53170, https://github.com/bqi343/USACO/blob/master/Implementations/content/graphs%20(12)/Trees%20(10)/HLD%20(10.3).h
 * Description: Root 0, full adjacency list. Value of v is at pos[v] (VALS\_EDGES: value of the edge to the parent).
 * process(u, v, op) calls op(l, r) for $O(\log N)$ segments [l, r) of the path; subtree(v) = [l, r).
 * Use any segment tree on positions (commutative operations).
 * Time: O((\log N)^2)
 * Status: stress-tested against old HLD
 */
#pragma once

template <bool VALS_EDGES> struct HLD {
	int N, tim = 0;
	vector<vector<int>> adj;
	vector<int> par, siz, rt, pos;
	HLD(vector<vector<int>> adj_)
		: N((int)adj_.size()), adj(adj_), par(N, -1), siz(N, 1),
		  rt(N), pos(N) { dfsSz(0); dfsHld(0); }
	void dfsSz(int v) {
		for (int& u : adj[v]) {
			adj[u].erase(find(adj[u].begin(), adj[u].end(), v));
			par[u] = v;
			dfsSz(u);
			siz[v] += siz[u];
			if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
		}
	}
	void dfsHld(int v) {
		pos[v] = tim++;
		for (int u : adj[v]) {
			rt[u] = (u == adj[v][0] ? rt[v] : u);
			dfsHld(u);
		}
	}
	template <class B> void process(int u, int v, B op) {
		for (; ; v = par[rt[v]]) {
			if (pos[u] > pos[v]) swap(u, v);
			if (rt[u] == rt[v]) break;
			op(pos[rt[v]], pos[v] + 1);
		}
		op(pos[u] + VALS_EDGES, pos[v] + 1);
	}
	pair<int, int> subtree(int v) { return {pos[v] + VALS_EDGES, pos[v] + siz[v]}; }
};
