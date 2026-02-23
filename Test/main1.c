#include <stdio.h>

int main() {
    FILE *fp;
    if ((fp = fopen("int.dat", "w")) == NULL) {
        perror("int.dat");
        return 0;
    }

    char s1[5];
    char s2[5];
    for (int i=0; i<10; i++) {
        fscanf(fp, "%d %d\n", &s1, &s2);
        puts(s1);
        puts(s2);
    }

    fclose(fp);
    return 0;
}