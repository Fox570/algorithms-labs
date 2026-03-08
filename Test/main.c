#include <stdio.h>
#include <stdlib.h>

void sort(int *arr, int n) {
    int i, j, t;
    for (i=0; i<n-1; i++) {
        for (j=0; j<n-i-1; j++) {
            if (arr[j+1] < arr[j]) {
                t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
}

int main() {
    int arr[] = {3, -2, 1, 5, 0};
    int i, n;
    for (i=0; i<5; i++) {printf("%d ", arr[i]);}
    sort(arr, 5);
    puts("\n");
    for (i=0; i<5; i++) {printf("%d ", arr[i]);}

    return 0;
}