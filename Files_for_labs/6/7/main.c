#include <stdio.h>

int main()
{
    const int M=10, N=20;
    float s=0.0;
    int i,j;

    printf("\nProgram for calculate double sum\n");

    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
        {
            s+=1.0/(i*i+j);
        }
    }

    printf("\n Sum=%f \n", s);
}