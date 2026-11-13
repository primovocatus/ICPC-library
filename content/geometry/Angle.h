/**
 * Author: Simon Lindholm
 * Date: 2015-01-31
 * License: CC0
 * Source: me
 * Description: Angles as int points + number of full turns t, for rotational sweeps.
 * Status: Used, works well
 */
#pragma once

// sweep: v = {w[0], ..., w[0].t360(), ...} sorted; while (v[j] < v[i].t180()) ++j;
struct Angle {
	int x, y;
	int t;
	Angle(int x, int y, int t = 0) : x(x), y(y), t(t) {}
	Angle operator-(Angle b) const { return {x - b.x, y - b.y, t}; }
	int half() const {
		assert(x || y);
		return y < 0 || (y == 0 && x < 0);
	}
	Angle t90() const { return {-y, x, t + (half() && x >= 0)}; }
	Angle t180() const { return {-x, -y, t + half()}; }
	Angle t360() const { return {x, y, t + 1}; }
};
bool operator<(Angle a, Angle b) {
	// add a.dist2() and b.dist2() to also compare distances
	return make_tuple(a.t, a.half(), a.y * (ll)b.x) <
	       make_tuple(b.t, b.half(), a.x * (ll)b.y);
}

// smallest angle between two points (covers the segment)
pair<Angle, Angle> segmentAngles(Angle a, Angle b) {
	if (b < a) swap(a, b);
	return (b < a.t180() ?
	        make_pair(a, b) : make_pair(b, a.t360()));
}
Angle operator+(Angle a, Angle b) { // point a + vector b
	Angle r(a.x + b.x, a.y + b.y, a.t);
	if (a.t180() < r) r.t--;
	return r.t180() < a ? r.t360() : r;
}
Angle angleDiff(Angle a, Angle b) { // angle b - angle a
	int tu = b.t - a.t; a.t = b.t;
	return {a.x * b.x + a.y * b.y, a.x * b.y - a.y * b.x, tu - (b < a)};
}
