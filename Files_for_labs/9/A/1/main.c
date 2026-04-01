#include <stdio.h>

int main() {
    enum {N = 7};
    char *c; short *h; int *d; long *l; float *f; double *lf; long double *Lf;
    char data_types[N][12] = {"char", "short", "int", "long", "float", "double", "long double"};
    int sizes_types[N] = {sizeof(char), sizeof(short), sizeof(int), sizeof(long), sizeof(float),
    sizeof(double), sizeof(long double)};
    void *pointers[N] = {c, h, d, l, f, lf, Lf};

    for (int i=0; i<N; i++) {
        printf("%s = %d\t*%s = %d\n", data_types[i], sizes_types[i], data_types[i], sizeof(pointers[i]));
    }

    return 0;
}