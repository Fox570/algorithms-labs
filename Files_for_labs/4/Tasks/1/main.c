#include <stdio.h>
#include <math.h>

int main () {
	double e, t;

	t = M_PI/3 + 0.01;
	e = (2*(cos(t)*sin(t)*sin(t) + tan(t))/3) / (t - M_PI/3);

	printf("%lf\n", e);
}
