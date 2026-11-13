/**
 * Author: Unknown
 * Date: 2002-09-13
 * License: CC0
 * Source: predates tinyKACTL
 * Description: Size $< n$ $\Rightarrow$ there is a cycle.
 * Time: $O(|V|+|E|)$
 * Status: stress-tested
 */
#pragma once

vector<int> topoSort(const vector<vector<int>>& g) {
	vector<int> indeg((int)g.size()), q;
	for (auto& li : g) for (int x : li) indeg[x]++;
	for (int i = 0; i < (int)g.size(); ++i)
		if (indeg[i] == 0) q.push_back(i);
	for (int j = 0; j < (int)q.size(); ++j)
		for (int x : g[q[j]])
			if (--indeg[x] == 0) q.push_back(x);
	return q;
}
