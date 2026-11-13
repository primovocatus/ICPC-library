/**
 * Author: Johan Sannemo
 * License: CC0
 * Description: Min number of intervals [l, r) covering G, returns their indices, \{\} if impossible.
 * For [l, r] change (A) to add \texttt{|| R.empty()}.
 * Time: O(N \log N)
 * Status: Tested on kattis:intervalcover
 */
#pragma once

template<class T>
vector<int> cover(pair<T, T> G, vector<pair<T, T>> I) {
	vector<int> S((int)I.size()), R;
	iota(S.begin(), S.end(), 0);
	sort(S.begin(), S.end(), [&](int a, int b) { return I[a] < I[b]; });
	T cur = G.first;
	int at = 0;
	while (cur < G.second) { // (A)
		pair<T, int> mx = make_pair(cur, -1);
		while (at < (int)I.size() && I[S[at]].first <= cur) {
			mx = max(mx, make_pair(I[S[at]].second, S[at]));
			at++;
		}
		if (mx.second == -1) return {};
		cur = mx.first;
		R.push_back(mx.second);
	}
	return R;
}
