/**
 * Author: Ulf Lundstrom
 * Date: 2009-03-21
 * License: CC0
 * Source:
 * Description:\\
\begin{minipage}{75mm}
Distance from p to the segment [s, e]. On segment: segDist(s, e, p) < eps.
\end{minipage}
\begin{minipage}{15mm}
\vspace{-10mm}
\includegraphics[width=\textwidth]{content/geometry/SegmentDistance}
\end{minipage}
 * Status: tested
 */
#pragma once

#include "Point.h"

typedef Point<double> P;
double segDist(P s, P e, P p) {
	if (s == e) return (p - s).dist();
	auto d = (e - s).dist2(), t = min(d, max(.0, (p - s).dot(e - s)));
	return ((p - s) * d - (e - s) * t).dist() / d;
}
