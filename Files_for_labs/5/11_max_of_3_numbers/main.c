#include <stdio.h>

int get_max_of_3_numbers(int a, int b, int c) {
    int max;
    if (a > b) {
        if (a > c) {
            max = a;
        } else if (c > b) {
            max = c;
        } else {
            max = b;
        }
    }
    else {
        if (b > c) {
            max = b;
        } else if (a > c) {
            max = a;
        } else {
            max = c;
        }
    }

    return max;
}

int main(void) {
    int a, b, c;
    int max_number; 
    
    printf("\n#-# This is programm will determine the largest of 3 numbers\n");
    printf("#-# Enter 3 any numbers separated by spaces: ");
    scanf("%d %d %d", &a, &b, &c);
    
    max_number = get_max_of_3_numbers(a, b, c);
    printf("\n#-# The largest number is %d", max_number);

    return 0;
}