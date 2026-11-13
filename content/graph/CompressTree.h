/**
 * Author: Simon Lindholm
 * Date: 2016-01-14
 * License: CC0
 * Description: Virtual tree of the subset S (adds pairwise LCAs). Returns (par, orig\_index), root 0 points to itself.
 * Time: $O(|S| \log |S|)$
 * Status: Tested at CodeForces
 */
#pragma once

#include "LCA.h"

vector<pair<int, int>> compressTree(LCA& lca, const vector<int>& subset) {
	static vector<int> rev; rev.resize((int)lca.time.size());
	vector<int> li = subset, &T = lca.time;
	auto cmp = [&](int a, int b) { return T[a] < T[b]; };
	sort(li.begin(), li.end(), cmp);
	int m = (int)li.size() - 1;
	for (int i = 0; i < m; ++i) {
		int a = li[i], b = li[i + 1];
		li.push_back(lca.lca(a, b));
	}
	sort(li.begin(), li.end(), cmp);
	li.erase(unique(li.begin(), li.end()), li.end());
	for (int i = 0; i < (int)li.size(); ++i) rev[li[i]] = i;
	vector<pair<int, int>> ret = {pair<int, int>(0, li[0])};
	for (int i = 0; i < (int)li.size() - 1; ++i) {
		int a = li[i], b = li[i + 1];
		ret.emplace_back(rev[lca.lca(a, b)], b);
	}
	return ret;
}
