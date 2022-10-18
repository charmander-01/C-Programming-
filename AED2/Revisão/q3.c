#include <stdio.h>

int main()
{
    int prim = 0;
    int cont;
    int i, j;
    int inicio, fim;

    scanf("%d %d", &inicio, &fim);

    for(i=inicio;i<=fim;i++)
    {
        cont = 0;
        for(j=1;j<=i;j++)
        {
            if(i%j==0) cont++;
        }
        if(cont == 2) prim++;
    }

    printf("%d\n", prim);

    return 0;
}
