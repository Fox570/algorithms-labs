#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <mylib/mylib.h>


enum {name_length=50, max_routes=20};

struct MARSH {
    char BEGST[name_length];
    char TERM[name_length];
    unsigned short NUMBER;
};


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


int get_index_route(struct MARSH *routes, short cnt, short route_number) {
    for (int i=0; i<cnt; i++) {
        if (routes[i].NUMBER == route_number)
            return i;
    }
    return -1;
}


int add_route(char FNAME[], struct MARSH *routes, short *cnt) {
    if (*cnt >= max_routes) {
        printf("Ошибка. Список маршрутов переполнен.\n");
        return 0;
    }

    struct MARSH new_route;
    printf("Введите номер маршрута: ");
    scanf("%hd", &new_route.NUMBER);
    while (getchar() != '\n');

    printf("Начальный пункт: ");
    fgets(new_route.BEGST, sizeof(new_route.BEGST), stdin);
    new_route.BEGST[strcspn(new_route.BEGST, "\n")] = '\0'; // заменяем лишний отступ на конец строки, для нормального вывода

    printf("Конечный пункт: ");
    fgets(new_route.TERM, sizeof(new_route.TERM), stdin);
    new_route.TERM[strcspn(new_route.TERM, "\n")] = '\0'; // также для TERM

    routes[*cnt] = new_route;

    FILE *fp;
    if ((fp = fopen(FNAME, "ab")) == NULL) {perror(FNAME); return 1;}
    fwrite(&routes[(*cnt)++], sizeof(struct MARSH), 1, fp);
    fclose(fp);

    printf("Маршрут успешно добавлен.\n");
    return 0;
}


int *get_available_routes(struct MARSH *routes, short cnt) {
    int *route_nums = (int *)malloc(max_routes * sizeof(int));
    
    for (int i=0; i<cnt; i++) {
        route_nums[i] = routes[i].NUMBER;
    }

    return route_nums;
}


int read_to_struct_from_file(char FNAME[], struct MARSH *routes, short *cnt) {
    *cnt = 0;  // обнуляем счётчик перед чтением
    FILE *fp;
    if ((fp = fopen(FNAME, "rb")) == NULL) {
        // если файла нет -- не ошибка, просто нет маршрутов
        return 0;
    }

    // читаем структуры, пока есть данные и не превышен max_routes
    while (*cnt < max_routes && fread(&routes[*cnt], sizeof(struct MARSH), 1, fp) == 1) {
        (*cnt)++;
    }

    fclose(fp);
    return 0;
}


void print_routes(struct MARSH *routes, short cnt) {
    for (int i=0; i<cnt; i++) {
        printf("%d %s %s\n", routes[i].NUMBER, routes[i].BEGST, routes[i].TERM);
    }
}


void get_route_info(struct MARSH *routes, short cnt) {
    short selected_route;
    int *availables = get_available_routes(routes, cnt); // записываем доступные маршруты в массив
    sort(availables, cnt); // сортируем список маршрутов

    printf("Доступны маршруты: ");
    for (int i=0; i<cnt; i++) {printf("%d ", availables[i]);} // выводим доступные маршруты

    printf("\nВведите номер маршрута: ");
    scanf("%hd", &selected_route);

    short index_route = get_index_route(routes, cnt, selected_route);
    if (index_route >= 0) {
        printf("Начало маршрута: %s\nКонечная остановка: %s\n",
               routes[index_route].BEGST, routes[index_route].TERM);
    } else {
        printf("Маршрут не найден.");
    }

    free(availables);  // освобождаем память
}


int write_main_routes(char FNAME[]) {
    struct MARSH TRAFIC[8] = {
        {"Юбилейный", "Ж/Д вокзал", 2},
        {"Ж/Д вокзал", "Аэропорт Волгоград", 6},
        {"Инструментальный завод", "Ж/Д вокзал", 21},
        {"Мясникова", "ТРЦ «Акварель»", 25},
        {"Больничный комплекс", "Речной вокзал", 35},
        {"ДК «Строитель»", "Детский центр", 55},
        {"Грамши", "Технологический колледж", 59},
        {"Пл. Куйбышева", "ЦСМ", 65}
    };

    FILE *fp;
    if ((fp = fopen(FNAME, "wb")) == NULL) {perror(FNAME); return 0;}
    fwrite(TRAFIC, sizeof(struct MARSH), 8, fp);
    return 1;
}


int remove_route(char FNAME[], struct MARSH *routes, short *cnt) {
    short selected_route;

    printf("\nВведите номер маршрута: ");
    scanf("%hd", &selected_route);

    int index_route = get_index_route(routes, *cnt, selected_route);

    // сдвигаем массив структур на 1 элемент влево, начиная с индекса этого маршрута
    for (int i=index_route; i<(*cnt-1); i++) {
        routes[i] = routes[i+1];
    }
    (*cnt)--;

    FILE *fp;
    if ((fp = fopen(FNAME, "rb+")) == NULL) {perror(FNAME); return 1;}
    fwrite(routes, sizeof(struct MARSH), *cnt, fp);
    fclose(fp);

    printf("Маршрут удалён\n");
    return 1;
}


void run_program(char FNAME[], struct MARSH *routes, short *cnt) {
    read_to_struct_from_file(FNAME, routes, cnt); // загружаем (читаем) данные из файла в структурный массив TRAFIC

    while (1) {
        short action;
        printf("\nВыберете действие (1/2/3): \n\
\t1. Получить информацию о маршруте\n\
\t2. Добавить маршрут\n\
\t3. Удалить маршрут.\n");
        printf("Введите действие: ");
        scanf("%hd", &action);
        while (getchar() != '\n'); // очищаем буфер после scanf
        
        switch (action) {
            case 1: get_route_info(routes, *cnt); break;
            case 2: add_route(FNAME, routes, cnt); break;
            case 3: remove_route(FNAME, routes, cnt); break;
        }

        printf("\nНажмите Enter для продолжения/Ctrl+C для завершения...");
        while (getchar() != '\n');
        getchar();
    }
}

 
int main() {
    char *FNAME = "structures.txt";
    short routes_cnt = 0;   // инициализируем нулём
    struct MARSH *TRAFIC = (struct MARSH*)malloc(max_routes * sizeof(struct MARSH));

    run_program(FNAME, TRAFIC, &routes_cnt);
    free(TRAFIC);
    
    return 0;
}