#include <stdio.h>

int main() {
    int i, s = 0;
    for (i=1; i<=100; i++) //i = 2; ++i 
    {
        s += i*i;
    }
    printf("Sum of the sequence = %d\n", s);

    return 0;
}