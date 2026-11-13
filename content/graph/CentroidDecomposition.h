/**
 * Author: 
 * Description: g = tree. build(v) returns the centroid of the component of v;
 * cpar[c] = parent in the centroid tree (the root points to itself). Depth $O(\log N)$.
 * Time: O(N \log N)
 */
#pragma once

vector<int> g[N];
int siz[N], cpar[N];
bool dead[N];

int calcSiz(int v, int p) {
	siz[v] = 1;
	for (int u : g[v])
		if (u != p && !dead[u]) siz[v] += calcSiz(u, v);
	return siz[v];
}

int centroid(int v, int p, int tot) {
	for (int u : g[v])
		if (u != p && !dead[u] && siz[u] * 2 > tot)
			return centroid(u, v, tot);
	return v;
}

int build(int v) {
	int c = centroid(v, -1, calcSiz(v, -1));
	cpar[c] = c; dead[c] = 1;
	for (int u : g[c])
		if (!dead[u]) cpar[build(u)] = c;
	return c;
}
