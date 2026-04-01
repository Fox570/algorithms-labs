#include <stdio.h>

int main() {
    char symbol;
    int a,b;

    printf ("\nInput integer numbers a & b\n");
    printf ("Use following syntax a operator b\n");
    printf ("You can use followng operators: + - / *\n");
    scanf ("%d%c%d",&a, &symbol, &b);

    switch (symbol) {
        case '+':
            printf("\n%d + %d = %d\n", a, b, a+b);
            break;
        case '-':
            printf("\n%d - %d = %d\n", a, b, a-b);
            break;
        case '/':
            printf("\n%d / %d = %d\n", a, b, a/b); // incorrect division (%f, (float)a/b)
            break;
        case '*':
            printf("\n%d * %d = %d\n", a, b, a*b);
            break;
        default:
            printf("\nCannot resolve operator\n");
    }
    return 0;
}