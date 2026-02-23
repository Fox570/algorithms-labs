#include <stdio.h>

int F(int k) {
	float s = (float)k;
	return s;
}

int main() {
	int res = F(5);
	printf("%d\n", res);
	return 0;
}
