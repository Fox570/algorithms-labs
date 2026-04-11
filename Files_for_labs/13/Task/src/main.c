#include "funcs.h"

int main(void) {
    char *FNAME = "data/structures.txt";
    short routes_cnt = 0;   // инициализируем нулём
    struct MARSH *TRAFIC = (struct MARSH*)malloc(max_routes * sizeof(struct MARSH));

    run_program(FNAME, TRAFIC, &routes_cnt);
    // write_main_routes(FNAME);
    free(TRAFIC);
    
    return 0;
}