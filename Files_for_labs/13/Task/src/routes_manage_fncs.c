#include "funcs.h"

void print_routes(struct MARSH *routes, short cnt) {
    printf("\n");
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


int remove_route(char FNAME[], struct MARSH *routes, short *cnt) {
    short selected_route;
    int *availables = get_available_routes(routes, *cnt); // записываем доступные маршруты в массив
    sort(availables, *cnt); // сортируем список маршрутов

    printf("Доступны маршруты: ");
    for (int i=0; i<*cnt; i++) {printf("%d ", availables[i]);} // выводим доступные маршруты

    printf("\nВведите номер маршрута: ");
    scanf("%hd", &selected_route);

    int index_route = get_index_route(routes, *cnt, selected_route);

    // сдвигаем массив структур на 1 элемент влево, начиная с индекса этого маршрута
    for (int i=index_route; i<(*cnt-1); i++) {
        routes[i] = routes[i+1];
    }
    (*cnt)--;

    FILE *fp;
    if ((fp = fopen(FNAME, "wb")) == NULL) {perror(FNAME); return 1;}
    fwrite(routes, sizeof(struct MARSH), *cnt, fp);
    fclose(fp);

    printf("Маршрут удалён\n");
    return 1;
}