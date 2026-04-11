#include "funcs.h"

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


int *get_available_routes(struct MARSH *routes, short cnt) {
    int *route_nums = (int *)malloc(max_routes * sizeof(int));
    
    for (int i=0; i<cnt; i++) {
        route_nums[i] = routes[i].NUMBER;
    }

    return route_nums;
}