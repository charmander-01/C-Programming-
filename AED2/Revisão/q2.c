#include <stdio.h>

int main()
{
    int i, j;
    int valor;
    int inicio, fim;
    int div;

    scanf("%d", &valor);

    int vet[valor];
    int index = 0;

    scanf("%d %d", &inicio, &fim);

    for(i=2;i<=valor;i++)
    {
        div = 0;
        for(j=1;j<=i;j++)
        {
            if(i%j==0) div++;
        }
        if(div==2)
        {
            vet[index] = i;
            index++;
        }
    }

    for(i=inicio-1;i<=fim-1;i++)
    {
        printf("%d ", vet[i]);
    }    

    printf("\n");

    return 0;
}
