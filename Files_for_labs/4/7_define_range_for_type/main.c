#include <stdio.h>
#include <math.h>


int main() {
	long number_of_values = pow(2, sizeof(char)*8);
	long min_value = -number_of_values *.5;
	long max_value = number_of_values *.5 - 1;
	
	return 0;
}
