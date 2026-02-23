#include "_stdio.h"

void _printf(const char* str, ...);
void _scanf(const char* str, ...);

int main() {
    _printf("Integer: %d\nString: %s\nFloat: %0.2f\n", 10, "Balls", 12.2548);

    int a;
    float b;
    _scanf("%i %f", &a, &b);
    _printf("%d %f\n", a, b);
    return 0;
}
