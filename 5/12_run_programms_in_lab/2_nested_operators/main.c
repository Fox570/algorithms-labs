#include <stdio.h>

int main() {
    int a,b,c;

    printf("\nInsert three integer numbers a, b and c: ");
    scanf("%d%d%d", &a, &b, &c);

    if (a<b) // Первый уровень
    {
        if(a<c) // Второй уровень
            printf ("\nMinimum is a=%d\n", a);
        else
            printf ("\nMinimum is c=%d\n", c);
    } else 
    {
        if (b<c) // Второй уровень
            printf ("\nMinimum is b=%d\n", b);
        else
            printf ("\nMinimum is c=%d\n", c);
    }
    return 0;
}