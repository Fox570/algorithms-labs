#include <stdio.h>
#include <stdlib.h>

int main() {
    char d = 10;
    char *gpt = &d; // gpt = &d;

    printf("gpt = %p, *gpt = %d, d = %d\n", gpt, *gpt, d);

    *gpt = 100;

    printf("gpt = %p, *gpt = %d, d = %d\n", gpt, *gpt, d);

    return 0;
}