/**
 * Author: Victor Lecomte, chilli
 * Date: 2019-04-26
 * License: CC0
 * Source: https://vlecomte.github.io/cp-geo.pdf
 * Description: p inside the polygon; strict: false on the boundary. Watch for overflow.
 * Time: O(n)
 * Status: stress-tested and tested on kattis:pointinpolygon
 */
#pragma once

#include "Point.h"
#include "OnSegment.h"
#include "SegmentDistance.h"

template<class P>
bool inPolygon(vector<P> &p, P a, bool strict = true) {
	int cnt = 0, n = (int)p.size();
	for (int i = 0; i < n; ++i) {
		P q = p[(i + 1) % n];
		if (onSegment(p[i], q, a)) return !strict;
		// or: if (segDist(p[i], q, a) <= eps) return !strict;
		cnt ^= ((a.y < p[i].y) - (a.y < q.y)) * a.cross(p[i], q) > 0;
	}
	return cnt;
}
