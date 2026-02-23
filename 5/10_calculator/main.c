#include <stdio.h>

int main(void) {
	int a,b;
	char operator;
	
    printf("\n#-# This is mini program for simple arithmetic operations between two numbers.");
	printf("\n#-# Input integer numbers a & b.\n");
	printf("#-# Use following syntax a operator.\n");
	printf("#-# You can use following operators: + - / *: \n\t");
	scanf("%d%c%d", &a, &operator, &b);
	// printf("a = %d\tb = %d", a, b);
	
	if (operator == '+') {
        printf("\n%d + %d = %d", a, b, a+b);
    } else if (operator == '-') {
        printf("\n%d - %d = %d", a, b, a-b);
    } else if (operator == '*') {
        printf("\n%d * %d = %d", a, b, a*b);
    } else if (operator == '/') {
        if (b == 0) {
			printf("\n#!# Divizion by zero is not allowed!");
			printf("\n#-# Please enter correct operators.");
		} else 
			printf("\n%d / %d = %.2f", a, b, (float)a/b);
    } else if (operator == '%')
	{
        if (b == 0) {
			printf("\n#!# Divizion by zero is not allowed!");
			printf("\n#-# Please enter correct operators.");
		}else
			printf("\n%d %% %d = %d", a, b, a%b);
	};
	
	return 0;
};