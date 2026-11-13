/**
 * Author: Simon Lindholm
 * Date: 2017-04-17
 * License: CC0
 * Source: folklore
 * Description: ed[a] = \{(b, eid)\}, same eid in both directions. bicomps(f): f(edge ids) for each
 * biconnected component. A vertex can be in several components; an edge in none is a bridge.
 * Time: O(E + V)
 * Status: tested during MIPT ICPC Workshop 2017
 */
#pragma once

vector<int> num, st;
vector<vector<pair<int, int>>> ed;
int Time;
template<class F>
int dfs(int at, int par, F& f) {
	int me = num[at] = ++Time, top = me;
	for (auto [y, e] : ed[at]) if (e != par) {
		if (num[y]) {
			top = min(top, num[y]);
			if (num[y] < me)
				st.push_back(e);
		} else {
			int si = (int)st.size();
			int up = dfs(y, e, f);
			top = min(top, up);
			if (up == me) {
				st.push_back(e);
				f(vector<int>(st.begin() + si, st.end()));
				st.resize(si);
			}
			else if (up < me) st.push_back(e);
			else { /* e is a bridge */ }
		}
	}
	return top;
}

template<class F>
void bicomps(F f) {
	num.assign((int)ed.size(), 0);
	for (int i = 0; i < (int)ed.size(); ++i) if (!num[i]) dfs(i, -1, f);
}
