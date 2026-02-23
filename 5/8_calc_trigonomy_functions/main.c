#include <stdio.h>
#include <math.h>

double fix_zero(double x, double eps) {
	return (fabs(x) < eps) ? 0.0 : x;
}

int main() {
	int angle;
	double x, sin_y, cos_y, tan_y, ctg_y;
	const double EPS = 1e-9;

	printf("\n#-# This is mini programm for determine trigonomy functions by angle value.");

	printf("\n#-# Enter the angle value: ");
	scanf("%d", &angle);

	x = angle * M_PI / 180;

	sin_y = sin(x);
	cos_y = cos(x);

	printf("\tsin(%d) = %.3f\n\tcos(%d) = %.3f", angle, sin_y, angle, cos_y);

	if (fabs(sin_y) < EPS) {
		tan_y = tan(x);
		tan_y = fix_zero(tan_y, EPS);

		printf("\n\ttan(%d) = %.3f", angle, tan_y);
		printf("\n\t#-# Cotangent does not exist with this argument.\n");

	} else if(fabs(cos_y) < EPS) {
		ctg_y = cos_y / sin_y;
		ctg_y = fix_zero(ctg_y, EPS);

		printf("\n\tctg(%d) = %.3f", angle, ctg_y);
		printf("\n\t#-# Tangent does not exists with this arguent.\n");

	} else {
		tan_y = tan(x);
		ctg_y = cos_y / sin_y;

		tan_y = fix_zero(tan_y, EPS);
		ctg_y = fix_zero(ctg_y, EPS);

		printf("\n\ttan(%d) = %.3f\n\tctg(%d) = %.3f", angle, tan_y, angle, ctg_y);
	}
	
	return 0;
}
