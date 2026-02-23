#include <stdio.h>
#include "functions.h"

int sum(int, int);
int fibonacci(int);

int main() {
    int s, f;
    // s = sum(5, 7);
    f = fibonacci(6);
    printf("f(%d) = %d\n", 6, f);
    printf("%f", PI);
    // printf("sum = %d\n", s);
    return 0;
}

int sum(int a, int b) {
    return a + b;
}
