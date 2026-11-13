/**
 * Author: 
 * Description: Subset sums when the total W is small: 3+ copies of w become 1-2 copies of w and the rest
 * as copies of 2w, so only $O(\sqrt W)$ items remain. b[s] = 1 iff some subset has sum s. $w_i \ge 1$, W < MAXW.
 * Time: O(W \sqrt W / 64)
 */
#pragma once

const int MAXW = 250001;
bitset<MAXW> subsetSum(vector<int>& w) {
	int W = 0;
	for (int x : w) W += x;
	vector<int> cnt(W + 1);
	for (int x : w) cnt[x]++;
	bitset<MAXW> b; b[0] = 1;
	for (int i = 1; i <= W; ++i) {
		if (cnt[i] > 2) {
			int k = (cnt[i] - 1) / 2;
			cnt[i] -= 2 * k;
			cnt[2 * i] += k;
		}
		for (int j = 0; j < cnt[i]; ++j) b |= b << i;
	}
	return b;
}
