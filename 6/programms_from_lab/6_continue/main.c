#include <stdio.h>
int main()
{
    unsigned int i,j;
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            if ((j!=8) && (j!=5))
                continue;
            printf("%2d ",i*10+j);
        }
        printf("\n");
    }
    return 0;
}