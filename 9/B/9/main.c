#include <stdio.h>
#include <stdlib.h>

int is_correct_brackets(int N, char *str) {
    N--; // чтобы не доходить до /0
    char *stack = (char *)calloc(20, sizeof(char));
    int i, n = 0; // n - size of stack

    for (int i=0; i<N; i++) {
        if (str[i]=='(' || str[i]=='{' || str[i]=='[') {
            stack[n] = str[i];
            n++;
        } else if (str[i] == ')') {
            if (n > 0) {
                if (stack[n-1] == '(') {
                    stack[n-1] = 0;
                    n--;
                } else {
                    printf("NO");
                    return 0;
                }
            } else {
                printf("NO");
                return 0;
            }
        } else if (str[i] == '}') {
            if (n > 0) {
                if (stack[n-1] == '{') {
                    stack[n-1] = 0;
                    n--;
                } else {
                    printf("NO");
                    return 0;
                }
            } else {
                printf("NO");
                return 0;
            }
        } else if (str[i] == ']') {
            if (n > 0) {
                if (stack[n-1] == '[') {
                    stack[n-1] = 0;
                    n--;
                } else {
                    printf("NO");
                    return 0;
                }
            } else {
                printf("NO");
                return 0;
            }
        }
    }

    if ((n-1) > 0) {
        printf("NO");
    } else {
        printf("YES");
    }

    free(stack);
    return 0;
}

int main() {
    char str[20];

    printf("Введите скобочную последовательность: ");
    scanf("%s", str);
    int N = sizeof(str);
    
    printf("%s - ", str);
    is_correct_brackets(N, str);
    printf("\n");

    return 0;
}