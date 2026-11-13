/**
 * Author: Ulf Lundstrom
 * Date: 2009-03-21
 * License: CC0
 * Source: Basic math
 * Description:\\
\begin{minipage}{75mm}
Signed distance from p to the line ab: positive on the left of $a \to b$. a == b gives nan.
For Point3D call .dist on the cross product.
\end{minipage}
\begin{minipage}{15mm}
\includegraphics[width=\textwidth]{content/geometry/lineDistance}
\end{minipage}
 * Status: tested
 */
#pragma once

#include "Point.h"

template<class P>
double lineDist(P a, P b, P p) {
	return (double)(b - a).cross(p - a) / (b - a).dist();
}
