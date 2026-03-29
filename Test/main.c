#include<stdio.h>


int main() {
    // int var_i = 10;
    // double pi = 3.14159265358979;
    // char ch = 's';

    int var_i;
    double pi;
    char ch;


    FILE *fp;
    if ((fp = fopen("file.txt", "rb")) == NULL) {
        perror("file.txt");
        return 1;
    }

    fread(&var_i, sizeof(var_i), 1, fp);
    fread(&pi, sizeof(pi), 1, fp);
    fread(&ch, sizeof(ch), 1, fp);

    printf("%d, %lf, %c\n", var_i, pi, ch);

    // fwrite(&var_i, sizeof(var_i), 1, fp);
    // fwrite(&pi, sizeof(pi), 1, fp);
    // fwrite(&ch, sizeof(ch), 1, fp);

    fclose(fp);
    return 0;
}