#include <stdio.h>

int min(int, int);
// float pow(float, int);
void Print_hello(void);
void print(float);
long fact(int);
float seq(int);
void repeat(char, int);
float mult(float, float);

int main() {
	printf("%d\n", 1e-10);
	printf("%f", seq(6));
	return 0;
}

int min(int x, int y) {
	if (x < y)
		return x;
	else
		return y;
}

// float pow(float x, int n) {
// 	int i;
// 	float p = 1.0;
// 	for (i=0;i<abs(n);i++)
// 		p *= x;
// 	return p;
// }

void Print_hello(void) {
	printf("Hello!\n");
}

void print(float x){
	printf("\nx=%f\n", x);
}

long fact(int n){
	int p=1,i;
	for (i=2;i<=n;i++)
		p *= i;
	return p;
}

float seq(int n){
	int i=n;
	float s=0.0,t;
	do {
		t=1.0/i;
		s+=t;
		i*=n;
	} while (t>1e-10);
	printf("%d\n", i);
	return s;
}

void repeat(char v, int n) {
	int i;
	for (i=0;i<n;i++)
		printf("\n%c\n", v);
}

float mult(float x, float y) {
	return x*y;
}
