#include "funcs.h"

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