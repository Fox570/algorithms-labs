#include <stdio.h>
#include <math.h>

#define N 10  // Размер массива

int main() {
    double arr[N] = {-9.2, 0.32, 0, 1.45, -6.75, -8.1, 0, 6.0, -3.1415, 0.0};  // Массив для вещественных чисел
    int i;
    
    // ============ Ввод массива с клавиатуры ============
    // printf("Введите %d вещественных чисел (через пробел или Enter):\n", N);
    // for (i = 0; i < N; i++) {
    //     printf("arr[%d] = ", i);
    //     scanf("%lf", &arr[i]);  // %lf для чтения double
    // }
    
    // Вывод введённого массива
    printf("\nВы ввели массив:\n");
    for (i = 0; i < N; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n\n");
    
    // ============ 1. Максимальный по модулю элемент ============
    double max_abs = fabs(arr[0]);
    int max_index = 0;
    
    for (i = 1; i < N; i++) {
        if (fabs(arr[i]) > max_abs) {
            max_abs = fabs(arr[i]);
            max_index = i;
        }
    }
    printf("1) Максимальный по модулю элемент:\n");
    printf("   arr[%d] = %.2f, модуль = %.2f\n\n", max_index, arr[max_index], max_abs);
    
    // ============ 2. Сумма между положительными элементами ============
    int first_pos = -1, second_pos = -1;
    double sum = 0.0;
    
    // Поиск первого положительного
    for (i = 0; i < N; i++) {
        if (arr[i] > 0) {
            first_pos = i;
            break;
        }
    }
    
    // Поиск второго положительного (после первого)
    if (first_pos != -1) {
        for (i = first_pos + 1; i < N; i++) {
            if (arr[i] > 0) {
                second_pos = i;
                break;
            }
        }
    }
    
    // Вычисление суммы
    printf("2) Сумма между положительными элементами:\n");
    if (first_pos == -1) {
        printf("   В массиве нет положительных элементов\n");
    } else if (second_pos == -1) {
        printf("   В массиве только один положительный элемент (индекс %d)\n", first_pos);
    } else if (second_pos - first_pos <= 1) {
        printf("   Положительные элементы стоят рядом (индексы %d и %d)\n", 
               first_pos, second_pos);
        printf("   Между ними нет элементов для суммирования\n");
    } else {
        for (i = first_pos + 1; i < second_pos; i++) {
            sum += arr[i];
        }
        printf("   Между элементами arr[%d] и arr[%d]:\n", first_pos, second_pos);
        for (i = first_pos + 1; i < second_pos; i++) {
            printf("   arr[%d] = %.2f %c ", i, arr[i], 
                   (i < second_pos - 1) ? '+' : '=');
        }
        printf("%.2f\n\n", sum);
    }
    
    // ============ 3. Перемещение нулей в конец ============
    printf("3) Перемещение нулей в конец массива:\n");
    
    int non_zero_count = 0;
    
    // Сначала переписываем все ненулевые элементы в начало
    for (i = 0; i < N; i++) {
        // Проверка на ноль с небольшой погрешностью для вещественных чисел
        if (fabs(arr[i]) > 0.000001) {
            arr[non_zero_count] = arr[i];
            non_zero_count++;
        }
    }
    
    // Затем заполняем оставшиеся позиции нулями
    for (i = non_zero_count; i < N; i++) {
        arr[i] = 0.0;
    }
    
    printf("   Массив после преобразования:\n   ");
    for (i = 0; i < N; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n\n");
    
    // ============ 4. Подсчёт абитуриентов с двойками ============
    printf("4) Подсчёт абитуриентов, не допущенных ко второму экзамену:\n");
    
    int grades[N];  // Массив для оценок
    int count = 0;  // Счётчик двоек
    
    printf("   Введите %d оценок (2, 3, 4, 5):\n", N);
    for (i = 0; i < N; i++) {
        printf("   grade[%d] = ", i);
        scanf("%d", &grades[i]);
        
        // Проверка на корректность оценки
        while (grades[i] < 2 || grades[i] > 5) {
            printf("   Ошибка! Введите оценку от 2 до 5: ");
            scanf("%d", &grades[i]);
        }
        
        if (grades[i] == 2) {
            count++;
        }
    }
    
    printf("\n   Введённые оценки: ");
    for (i = 0; i < N; i++) {
        printf("%d ", grades[i]);
    }
    printf("\n   Не допущено ко второму экзамену: %d человек(а)\n", count);
    
    return 0;
}