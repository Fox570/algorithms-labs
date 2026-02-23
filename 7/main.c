#include <stdio.h>

int add(int a, int b) {
	return a + b;
}

void hello(void) {
	printf("hello world!\n");
}

int main() {
	int res;
	int value = 2;
	res = add(7, value);
	printf("result = %d\n", res);

	hello();
	return 0;
}