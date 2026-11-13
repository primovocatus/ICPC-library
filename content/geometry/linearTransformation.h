/**
 * Author: Per Austrin, Ulf Lundstrom
 * Date: 2009-04-09
 * License: CC0
 * Source:
 * Description:\\
\begin{minipage}{75mm}
Applies to r the transformation (translation, rotation, scaling) that takes line $p_0 p_1$ to line $q_0 q_1$.
\end{minipage}
\begin{minipage}{15mm}
\vspace{-8mm}
\includegraphics[width=\textwidth]{content/geometry/linearTransformation}
\vspace{-2mm}
\end{minipage}
 * Status: not tested
 */
#pragma once

#include "Point.h"

typedef Point<double> P;
P linearTransformation(P p0, P p1, P q0, P q1, P r) {
	P dp = p1 - p0, dq = q1 - q0, num(dp.cross(dq), dp.dot(dq));
	return q0 + P((r - p0).cross(num), (r - p0).dot(num)) / dp.dist2();
}
