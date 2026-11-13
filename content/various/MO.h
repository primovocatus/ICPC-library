/**
 * Author: 
 * Description: Offline [l, r] queries: sort, then ans[q.it] = mo.get(q.l, q.r). C $\approx n / \sqrt q$.
 * hilbert(l, r) as the sort key is often faster (coordinates $< 2^{20}$).
 * Time: O((n + q) \sqrt n)
 */
#pragma once

const int C = 700;
struct query {
	int l, r, it;
	bool operator<(const query& a) const {
		if (l / C != a.l / C) return l < a.l;
		return (l / C & 1) ? r < a.r : r > a.r;
	}
};
struct {
	int l = 0, r = -1;

	void add(int pos) {} // a[pos] enters
	void del(int pos) {} // a[pos] leaves

	int get() { return 0; } // current answer
	int get(int pl, int pr) {
		while (r < pr)
			add(++r);
		while (l < pl)
			del(l++);
		while (l > pl)
			add(--l);
		while (r > pr)
			del(r--);
		return get();
	}
} mo;

ll hilbert(int x, int y) { // OPTIONAL
	const int H = 1 << 20;
	ll d = 0;
	for (int s = H / 2; s > 0; s /= 2) {
		int rx = (x & s) > 0, ry = (y & s) > 0;
		d += (ll)s * s * ((3 * rx) ^ ry);
		if (ry == 0) {
			if (rx == 1) x = H - 1 - x, y = H - 1 - y;
			swap(x, y);
		}
	}
	return d;
}
