#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mylib/mylib.h>


enum {name_length=50, max_routes=20};

struct MARSH {
    char BEGST[name_length];
    char TERM[name_length];
    unsigned short NUMBER;
};


int get_index_route(struct MARSH *routes, short *cnt, short route_number) {
    for (int i=0; i<*cnt; i++) {
        if (routes[i].NUMBER == route_number)
            return i;
    }
    return -1;
}


void add_route(struct MARSH *routes, short *cnt) {
    if (*cnt >= max_routes) {
        printf("Ошибка. Список маршрутов переполнен.\n");
        return;
    }

    struct MARSH new_route;
    printf("Введите номер маршрута: ");
    scanf("%hd", &new_route.NUMBER);
    while (getchar() != '\n');

    printf("Начальный пункт: ");
    fgets(new_route.BEGST, sizeof(new_route.BEGST), stdin);

    printf("Конечный пункт: ");
    fgets(new_route.TERM, sizeof(new_route.TERM), stdin);

    routes[(*cnt)++] = new_route;
    printf("Маршрут успешно добавлен.\n");
}


int *get_available_routes(struct MARSH *routes, short *cnt) {
    int *route_nums = (int *)malloc(max_routes * sizeof(int));
    
    for (int i=0; i<*cnt; i++) {
        route_nums[i] = routes[i].NUMBER;
    }

    return route_nums;
}


int read_file() {
    FILE *fp;
    if ((fp = fopen("structures.txt", "r")) == NULL) {
        perror("int.dat");
        return 1;
    }

    char *buff = (char *) malloc(100 * sizeof(char));
    int i=0;
    char c;
    while ((c = fgetc(fp)) != '\n')
        buff[i++] = c;
    buff[i] = '\0';

    puts(buff);
    fclose(fp);
    return 0;
}

int main() {
    read_file();

    return 0;
}

// int main() {
//     short routes_cnt = 8;

//     struct MARSH TRAFIC[max_routes] = {
//         {"Юбилейный", "Ж/Д вокзал", 2},
//         {"Ж/Д вокзал", "Аэропорт Волгоград", 6},
//         {"Инструментальный завод", "Ж/Д вокзал", 21},
//         {"Мясникова", "ТРЦ «Акварель»", 25},
//         {"Больничный комплекс", "Речной вокзал", 35},
//         {"ДК «Строитель»", "Детский центр", 55},
//         {"Грамши", "Технологический колледж", 59},
//         {"Пл. Куйбышева", "ЦСМ", 65}
//     };

//     while (1) {
//         short action;
//         printf("\nВыберете действие (1/2): \n\
// \t1. Добавить маршрут\n\
// \t2. Получить информацию о маршруте\n");
//         scanf("%hd", &action);
        
//         if (action == 1) {
//             add_route(TRAFIC, &routes_cnt);
//         } else if (action == 2) {
//             short selected_route;
//             int *availables = get_available_routes(TRAFIC, &routes_cnt); // записываем доступные маршруты
//             sort(availables, routes_cnt); // сортируем список маршрутов

//             printf("Доступны маршруты: ");
//             for (int i=0; i<routes_cnt; i++) {printf("%d ", availables[i]);} // выводим доступные маршруты

//             printf("\nВведите номер маршрута: ");
//             scanf("%hd", &selected_route);

//             short index_route = get_index_route(TRAFIC, &routes_cnt, selected_route);
//             if (index_route >= 0) {
//                 printf("Начало маршрута: %s\nКонечная остановка: %s\n",
//                     TRAFIC[index_route].BEGST, TRAFIC[index_route].TERM);
//             } else {
//                 printf("Маршрут не найден.");
//             }
//         }

//         printf("\nНажмите Enter для продолжения/Ctrl+C для завершения...");
//         while (getchar() != '\n');
//         // getchar();
//     }

//     return 0;
// }