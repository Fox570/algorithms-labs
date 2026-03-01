#include <stdio.h>

struct Date {
    unsigned int dd:5;
    unsigned int mm:4;
    unsigned int yy;
};

int main() {
    struct Date date = {19, 03, 2008};
    printf("%d\n", sizeof(date));

    return 0;
}