#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_sum_elements(int **arr, int m, int n);

int main() {
    enum {M=3, N=3};
    int i, j;
    srand(time(NULL));

    // выделение динамической памяти под массив
    int **arr = (int **) malloc(M * sizeof(int *));
    for (i=0; i<M; i++) {
        arr[i] = (int *) malloc(N * sizeof(int));
    }

    // заполнение массива псевдорандомными числами
    for (i=0; i<M; i++) {
        for (j=0; j<N; j++) {
            arr[i][j] = rand() % 10;
        }
    }

    // вывод массива
    for (i=0; i<M; i++) {
        for (j=0; j<N; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    int sum = get_sum_elements(arr, M, N);
    printf("\nsum of the elements above the main diagonal = %d\n", sum);

    // освобождение динамической памяти
    for (i=0; i<M; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}

int get_sum_elements(int **arr, int m, int n) {
    int sum = 0;
    int i, j;

    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            if (i < j)
                sum += abs(arr[i][j]);
        }
    }
    return sum;
}