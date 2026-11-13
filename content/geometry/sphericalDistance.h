/**
 * Author: Ulf Lundstrom
 * Date: 2009-04-07
 * License: CC0
 * Source: My geometric reasoning
 * Description: Sphere of radius r: f = longitude $\phi$ from the x axis, t = $\theta$ from the z axis (0 = north pole),
 * radians. With cartesian coordinates keep only the last two lines.
 * Status: tested on kattis:airlinehub
 */
#pragma once

double sphericalDistance(double f1, double t1,
		double f2, double t2, double radius) {
	double dx = sin(t2) * cos(f2) - sin(t1) * cos(f1);
	double dy = sin(t2) * sin(f2) - sin(t1) * sin(f1);
	double dz = cos(t2) - cos(t1);
	double d = sqrt(dx * dx + dy * dy + dz * dz);
	return radius * 2 * asin(d / 2);
}
