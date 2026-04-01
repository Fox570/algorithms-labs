#include <stdio.h>
#include <math.h>

int main() {
    double a,b,c,x,D,x1,x2;
    a=0.5;
    b=1.0;
    c=1.1;
    D=b*b-4.0*a*c; // Discriminant calculation
    if (D == 0.0)
    {
        printf("\nThere are no real roots of equation!\n");
        return 0;
    }
    else // if (D != 0.0)
    {
        x1=(-b+sqrt(D))/(2*a);
        x2=(-b-sqrt(D))/(2*a);
        printf("\nThe roots are x1=%.4f\tx2=%.4f\n",x1,x2);
    }
    return 0;
}