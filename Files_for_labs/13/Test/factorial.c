#include "factorial.h"

long long factorial(int n) {
    int i, p;

    for (i=2; i<=n; i++) {
        p *= i;
    }
    return p;
}