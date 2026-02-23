#include <stdio.h>
// #include <errno.h>

int main() {
    FILE *fp;
    char buff[512];

    if ((fp = fopen("file.txt", "r")) == NULL) {
        perror("file.txt");
        return 1;
    }
    
    fseek(fp, 0, SEEK_END);
    int lenght = ftell(fp);
    int i=0;
    char c;
    while ((c = fgetc(fp)) != EOF)
        buff[i++] = c;
    buff[i] = '\0';

    puts(buff);

    fclose(fp);
    return 0;
}