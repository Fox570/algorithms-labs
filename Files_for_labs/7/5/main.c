#include<stdio.h>

void func(float a, float b, float *res) {
    *res=a+b;
}

int main() {
    float a,b,s;
    printf("\n Input two float numbers: \n");
    scanf("%f%f",&a,&b);
    func(a,b,&s);
    printf("\n %.2f + %.2f = %.2f\n",a,b,s);
    return 0;
}