#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int local_min(int **arr, int n);

int main() {
    enum {N=10};
    int i, j;
    srand(time(NULL)); // задаем зерно для функции rand

    // выделение динамической памяти под массив
    int **arr = (int **) malloc(N * sizeof(int *));
    for (i=0; i<N; i++) {
        arr[i] = (int *) malloc(N * sizeof(int));
    }

    // заполнение массива псевдорандомными числами
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            arr[i][j] = rand() % 10; // записываем последнюю цифру рандомного числа
        }
    }

    // вывод массива
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // находим количество локальных минимумов
    int n = local_min(arr, N);
    printf("\nnumber of local minimum = %d\n", n);

    // освобождение динамической памяти
    for (i=0; i<N; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}

int local_min(int **arr, int n) {
    int cnt = 0;
    int i, j, k, t;
    short flag;

    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            flag = 1;
            for (k=-1; k<2; k++) {
                for (t=-1; t<2; t++) {
                    if (k != 0 || t != 0) { // чтобы не сравнивать с самим собой
                        if (i+k >= 0 && j+t >= 0 && i+k < n && j+t < n) { // проверяем выход за границу
                            if (arr[i+k][j+t] <= arr[i][j]) // проверка на наличие соседа который меньше выбранного числа (arr[i][j])
                                flag = 0;
                        }
                    }
                }
            }
            if (flag == 1)
                cnt++;
        }
    }

    return cnt;
}