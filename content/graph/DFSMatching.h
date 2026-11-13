/**
 * Author: Lukas Polacek
 * Date: 2009-10-28
 * License: CC0
 * Source:
 * Description: g[l] = right neighbours of left l, btoa = vector(m, -1). btoa[i] = left match of right i or -1.
 * Time: O(VE)
 * Status: works
 */
#pragma once

bool find(int j, vector<vector<int>>& g, vector<int>& btoa, vector<int>& vis) {
	if (btoa[j] == -1) return 1;
	vis[j] = 1; int di = btoa[j];
	for (int e : g[di])
		if (!vis[e] && find(e, g, btoa, vis)) {
			btoa[e] = di;
			return 1;
		}
	return 0;
}
int dfsMatching(vector<vector<int>>& g, vector<int>& btoa) {
	vector<int> vis;
	for (int i = 0; i < (int)g.size(); ++i) {
		vis.assign((int)btoa.size(), 0);
		for (int j : g[i])
			if (find(j, g, btoa, vis)) {
				btoa[j] = i;
				break;
			}
	}
	return (int)btoa.size() - (int)count(btoa.begin(), btoa.end(), -1);
}
