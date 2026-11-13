/**
 * Author: Mattias de Zalenski
 * Date: 2002-11-04
 * License: CC0
 * Description: Faces (fields a, b, c) must point outwards.
 * Status: tested
 */
#pragma once

template<class V, class L>
double signedPolyVolume(const V& p, const L& trilist) {
	double v = 0;
	for (auto i : trilist) v += p[i.a].cross(p[i.b]).dot(p[i.c]);
	return v / 6;
}
