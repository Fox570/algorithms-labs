#include <stdio.h>
#include "factorial.h"

int main() {
    int x;
    printf("Enter x: ");
    scanf("%d", &x);

    printf("x! = %ld\n", factorial(x));
    
    return 0;
}