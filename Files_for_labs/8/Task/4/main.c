#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool contains(int *arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) return true;
    }
    return false;
}

int main() {
    int src[] = {1, 2, 3, 2, 4, 1, 5, 3, 6};
    int n = sizeof(src) / sizeof(src[0]);

    int *unique = NULL;      // динамический массив уникальных элементов
    int uniq_count = 0;

    for (int i = 0; i < n; i++) {
        if (!contains(unique, uniq_count, src[i])) {
            // увеличиваем массив на 1 элемент
            int *tmp = realloc(unique, (uniq_count + 1) * sizeof(int));
            if (tmp == NULL) {
                free(unique);
                fprintf(stderr, "Memory allocation error\n");
                return 1;
            }
            unique = tmp;
            unique[uniq_count++] = src[i];
        }
    }

    // вывод результата
    for (int i = 0; i < uniq_count; i++) {
        printf("%d ", unique[i]);
    }

    free(unique);
    printf("\n%d", sizeof(unique));
    return 0;
}
