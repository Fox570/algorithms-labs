#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef FUNCTIONS
#define FUNCTIONS


enum {name_length=50, max_routes=20};

struct MARSH {
    char BEGST[name_length];
    char TERM[name_length];
    unsigned short NUMBER;
};

// main.c
int main(void);

// service_fncs.c
void sort(int *arr, int n);
int get_index_route(struct MARSH *routes, short cnt, short route_number);
int *get_available_routes(struct MARSH *routes, short cnt);

// file_manage_fncs.c
int read_to_struct_from_file(char FNAME[], struct MARSH *routes, short *cnt);
int write_main_routes(char FNAME[]);

// routes_manage_fncs.c
void get_route_info(struct MARSH *routes, short cnt);
int add_route(char FNAME[], struct MARSH *routes, short *cnt);
int remove_route(char FNAME[], struct MARSH *routes, short *cnt);
void print_routes(struct MARSH *routes, short cnt);

// run_prog.c
void run_program(char FNAME[], struct MARSH *routes, short *cnt);

#endif