#include <stdio.h>

int main() {
    int i, j;
    const int N = 10;

    printf("i\tj\n\n");
    for (i=1, j=1; i<=N; i++, j+=4)
    {
        printf("%d\t%d\n", i, j);
    }

    return 0;
}