#include <stdio.h>

int main() {
    int a, b, c, x, x_final, step;
    float f;

    printf("Enter integer values separated by spaces a, b, c, x, x_final, step: ");
    scanf("%d %d %d %d %d %d", &a, &b, &c, &x, &x_final, &step);

    if (step > 0) {
        if (x > x_final) {
            printf("Start must be less than Final!");
            return -1;}
    } else if (step < 0) {
        if (x < x_final) {
            printf("Final must be less than start with neagtive step!");
            return -1;}
    } else {
        printf("Step cannot be zero!");
        return -1;
    }
              
    printf("\n-----------------------------\n");
    printf("|f(x)         |y            \n");
    printf("-----------------------------\n");

    for (x; (step > 0) ? (x < x_final) : (x > x_final); x += step) {
        if (x < 5 & c != 0) {
           f = -(x * x) - b;
        } else if (x > 5 & c == 0) {
            f = (a - x) / (float) x;
        } else {
            if (c == 0) {f = 0.0;} else {
                f = -x / (float) c;
            }
        }
        printf("|f(%d)         |%.2f\n", x, f);
        printf("-----------------------------\n");
    }

    return 0;
}