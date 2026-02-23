#include <stdio.h>

enum {name_length=10};

struct Product {
    char name[name_length];
    char type;
    unsigned int cult_aria;
    unsigned short productivity;
};

int main() {
    struct Product products[3] = {
        {"Soy", 'B', 13000, 45},
        {"Chumiza", 'Z', 8000, 17},
        {"Rice", 'Z', 25650, 24},
    };

    for (int i=0; i<3; i++) {
        printf("%s, %c, %d, %d\n",
            products[i].name, products[i].type, products[i].cult_aria, products[i].productivity);
    }

    return 0;
}