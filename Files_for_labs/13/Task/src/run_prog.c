#include "funcs.h"

void run_program(char FNAME[], struct MARSH *routes, short *cnt) {
    read_to_struct_from_file(FNAME, routes, cnt); // загружаем (читаем) данные из файла в структурный массив TRAFIC

    while (1) {
        short action;
        printf("\nВыберете действие (1-4): \n\
\t1. Получить информацию о маршруте\n\
\t2. Добавить маршрут\n\
\t3. Удалить маршрут.\n\
\t4. Вывести все маршруты.\n");
        printf("Введите действие: ");
        scanf("%hd", &action);
        while (getchar() != '\n'); // очищаем буфер после scanf
        
        switch (action) {
            case 1: get_route_info(routes, *cnt); break;
            case 2: add_route(FNAME, routes, cnt); break;
            case 3: remove_route(FNAME, routes, cnt); break;
            case 4: print_routes(routes, *cnt); break;
        }

        printf("\nНажмите Enter для продолжения/Ctrl+C для завершения...");
        while (getchar() != '\n');
        getchar();
    }
}