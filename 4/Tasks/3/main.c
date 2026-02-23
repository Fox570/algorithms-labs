#include <stdio.h>
#include <math.h>

int main () {
	int n = 2;
	n/=((n--)-(--n));
	printf("%d\n", n);
}
