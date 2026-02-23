#include <stdio.h>
#include <math.h>

int max(int array[], int length) {
    int max_num = array[0];
    for (int i = 1; i < length; i++) {
        if (array[i] > max_num) {
            max_num = array[i];
        }
    }
    return max_num;
}

int main() {
    int a, b, c;

	printf("Enter 3 numbers separated by spaces: "); 
	scanf("%d %d %d", &a, &b, &c);
	
    int arr[] = {a, b, c};
	int max_side = max(arr, 3);

    if (a <= 0 || b <= 0 || c <= 0) {
        printf("The data entered is incorrect!\nThe sides must be greater than zero.\n");
        return -1;
    }
    if ((a+b+c-max_side) < max_side) {
        printf("The data entered is incorrect!\nPlease check the side lengths.\n");
        return -1;
    }

    double alpha = acos((pow(b,2) + pow(c,2) - pow(a,2)) / (2.0*b*c)) * 180 / M_PI;
    double beta  = acos((pow(a,2) + pow(c,2) - pow(b,2)) / (2.0*a*c)) * 180 / M_PI;
    double gamma = acos((pow(a,2) + pow(b,2) - pow(c,2)) / (2.0*a*b)) * 180 / M_PI;

    printf("alpha = %.2f°\n", alpha);
    printf("beta  = %.2f°\n", beta);
    printf("gamma = %.2f°\n", gamma);

    return 0;
}