#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_min_in_row(int **arr, int n, int r); // n - кол-во столбцов, r - номер ряда

int main() {
    enum {M=6, N=6};
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
            arr[i][j] = rand() % 100;
        }
    }

    // вывод массива
    for (i=0; i<M; i++) {
        for (j=0; j<N; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // нахождение минимального элемента в каждой четной строке
    for (int r=0; r<M; r++) {
        if (r % 2 == 0) {
            int min = get_min_in_row(arr, N, r);
            printf("\nminimal element in %d row = %d", r, min);
        }   
    }

    // освобождение динамической памяти
    for (i=0; i<M; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}

int get_min_in_row(int **arr, int n, int r) {
    int min = arr[r][0];
    for (int i=0; i<n; i++) {
        if (arr[r][i] < min)
            min = arr[r][i];
    }
    return min;
}