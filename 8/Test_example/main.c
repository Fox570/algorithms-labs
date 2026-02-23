#include <stdio.h>
#include <math.h>

int main() {
    const int N = 10;
    // int a[10] = {1, 3, -5, 1, -2, 1, -1, 3, 8, 4};
    int arr[10];
    int i, imax, imin, ibeg, iend, counter;

    for (i=0; i<N; i++) {
        scanf("%d", &arr[i]);
    }
    
    for(i = imax = imin = 0; i < N; i++) {
        if (arr[i] > arr[imax]) imax = i;
        if (arr[i] < arr[imin]) imin = i;
    }
    printf("\nmax = %d\t min = %d\t \n", arr[imax], arr[imin]);
    
    ibeg = imax < imin ? imax : imin;
    iend = imax < imin ? imin : imax;
    printf("ibeg=%d\t iend=%d\n", ibeg, iend);
    
    for (counter = 0, i = ibeg + 1; i < iend; i++)
        if(arr[i] > 0) counter++;
    printf("The number of positive elements = %d\n",counter);
    
    return 0;
}