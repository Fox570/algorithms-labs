#include <stdio.h>

int F(int k) {
	float s = (float)k;
	return s;
}

int main() {
	printf("%d\n", F(5));
	return 0;
}
