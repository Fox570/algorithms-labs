#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int contains(int **arr, int n, int r, int c); // проверяет наличие элемента c в ряду массива
int multiply_row(int **arr, int n, int r, int d); // умножает все элементы ряда r на число d

int main() {
    enum {M=10, N=10};
    int i, j;
    int c = 5, d = 5;
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

    // выполнение условия задачи
    for (int row=0; row<M; row++) {
        if (contains(arr, N, row, c)) { // проверка на наличие c
            multiply_row(arr, N, row, d); // умножение элементов строки
        }   
    }

    // вывод массива
    printf("\n");
    for (i=0; i<M; i++) {
        for (j=0; j<N; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // освобождение динамической памяти
    for (i=0; i<M; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}

int contains(int **arr, int n, int row, int c) {
    for (int i=0; i<n; i++) {
        if (arr[row][i] == c) {
            return 1;
        }
    }
    return 0;
}

int multiply_row(int **arr, int n, int row, int d) {
    for (int i=0; i<n; i++) {
        arr[row][i] *= d;
    }
}