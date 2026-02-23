#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum {name_length=50, max_routes=20};

struct MARSH {
    char start[name_length];
    char finish[name_length];
    unsigned short number;
};

int get_index_route(struct MARSH *routes, short *cnt, short route_number) {
    for (int i=0; i<*cnt; i++) {
        if (routes[i].number == route_number)
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
    scanf("%d", &new_route.number);

    printf("Начальный пункт: ");
    scanf("%s", &new_route.start);

    printf("Конечный пункт: ");
    scanf("%s", &new_route.finish);

    routes[(*cnt)++] = new_route;
    printf("Маршрут успешно добавлен.\n");
}

int *get_available_routes(struct MARSH *routes, short *cnt) {
    int *route_nums = (int *)malloc(max_routes * sizeof(int));
    
    for (int i=0; i<*cnt; i++) {
        route_nums[i] = routes[i].number;
    }

    return route_nums;
}

int main() {
    short routes_cnt = 8;

    struct MARSH routes[max_routes] = {
        {"Юбилейный", "Ж/Д вокзал", 2},
        {"Ж/Д вокзал", "Аэропорт Волгоград", 6},
        {"Инструментальный завод", "Ж/Д вокзал", 21},
        {"Мясникова", "ТРЦ «Акварель»", 25},
        {"Больничный комплекс", "Речной вокзал", 35},
        {"ДК «Строитель»", "Детский центр", 55},
        {"Грамши", "Технологический колледж", 59},
        {"Пл. Куйбышева", "ЦСМ", 65}
    };

    while (1) {
        short action;
        printf("\nВыберете действие (1/2): \n\
\t1. Добавить маршрут\n\
\t2. Получить информацию о маршруте\n");
        scanf("%d", &action);
        
        if (action == 1) {
            add_route(routes, &routes_cnt);
        } else if (action == 2) {
            short selected_route;
            int *availables = get_available_routes(routes, &routes_cnt); // записываем доступные маршруты

            printf("Доступны маршруты: ");
            for (int i=0; i<routes_cnt; i++) {printf("%d ", availables[i]);} // выводим доступные маршруты

            printf("\nВведите номер маршрута: ");
            scanf("%d", &selected_route);

            short index_route = get_index_route(routes, &routes_cnt, selected_route);
            if (index_route >= 0) {
                printf("Начало маршрута: %s\nКонечная остановка: %s\n",
                    routes[index_route].start, routes[index_route].finish);
            } else {
                printf("Маршрут не найден.");
            }
        }

        printf("\nНажмите Enter для продолжения/Ctrl+C для завершения...");
        while (getchar() != '\n');
        getchar();
    }

    return 0;
}