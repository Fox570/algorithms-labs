#include "functions.h"

int fibonacci(int n) {
    int a, b, r;
    a = b = 1;
    for (int i=2; i<n; i++) {
        r = a;
        a = b;
        b = r + b;
    }
    return b;
}