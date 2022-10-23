#include <stdio.h>
#include <math.h>

int conta_digitos(int valor, int numeral, int retorno);

int main()
{
    int n_testes;    
    int digito, num, cont;
    int resposta = 0;

    scanf("%d", &n_testes);
    scanf("%d", &digito);

    while(n_testes--)
    {
        scanf("%d", &num);
        cont = conta_digitos(num, digito, resposta);
        printf("%d ", cont);
    }

    printf("\n");

    return 0;
}

int conta_digitos(int valor, int numeral, int retorno)
{
    int tamanho = 0;
    int x = 10;
    int dig;

    if(valor==0)
    {
        return retorno;
    }

    while(x<=valor)
    {
        tamanho++;
        x = 10*x;    
    }

    dig = valor/(pow(10, tamanho));

    if(dig==numeral) retorno++;

    valor -= dig*(pow(10, tamanho));
    
    return conta_digitos(valor, numeral, retorno);
}
