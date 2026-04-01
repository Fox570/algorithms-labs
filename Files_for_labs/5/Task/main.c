#include <stdio.h>

int main() {
	int a, b, c;
	float x, f;

	printf("Enter any float X value: ");
	scanf("%f", &x);	

	a = 9, b = 3, c = 0;
	
	if (x<5 & c!=0) {
		f = (x*x) - b;
	} else if (x>5 & c==0) {
		f = (a-x)/x;
	} else {
		if (c == 0) {
			printf("Can not divide by zero: enter a C value other than zero.");
			return -1;
		} else {
			f = -(x/c);
		}
		
	}

	printf("f = %f", f);

	return 0;
}
