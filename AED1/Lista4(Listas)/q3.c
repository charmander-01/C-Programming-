    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>
     
    #define MAX 1000
     
    typedef struct NO no;
    typedef struct LISTA lista;
    typedef struct ELEMENTO elemento;
     
    struct ELEMENTO
    {
        int maior;
        int indice;
    };
     
    struct NO
    {
        int touca;
        no *proximo;
    };
     
    struct LISTA
    {
        no *inicio;
    };
     
    void IniciaLista(lista *sequencia);
    bool ListaVazia(lista *sequencia);
    bool InsereElemento(lista *sequencia, int cor);
    int ContaCor(lista *sequencia, int start, int end, int cor);
    void IndiceMaiorElemento(int vetor[], int tamanho, elemento *x);
    // void ImprimeLista(lista *sequencia);
    void ExcluiUltimoElemento(lista *sequencia);
     
    int main()
    {
        elemento *dados;
        dados = (elemento*) malloc(sizeof(elemento));
     
        int i, j, cor_touca;
        int num_anoes, qtd_cores;
        int qtd_fotos;
        int inicio, final;
        int registro[MAX];
        int grupo_anoes;
     
        lista anoes;
     
        IniciaLista(&anoes);
     
        scanf("%d %d", &num_anoes, &qtd_cores);
     
        for (i = 0; i < num_anoes; i++)
        {
            scanf("%d", &cor_touca);
            InsereElemento(&anoes, cor_touca);
        }
     
        // ImprimeLista(&anoes);
     
        scanf("%d", &qtd_fotos);
     
        for (i = 0; i < qtd_fotos; i++)
        {
            scanf("%d %d", &inicio, &final);
            for(j=0;j<qtd_cores;j++)
            {
                registro[j] = ContaCor(&anoes, inicio, final, j+1);
                // printf("registro: %d\n", registro[j]);
            }
     
            grupo_anoes = final-inicio+1;
     
            IndiceMaiorElemento(registro, qtd_cores, dados);
     
            if( dados->maior> (grupo_anoes/2) )
            {
                printf("bonita %d\n", dados->indice+1);
            }
            else
            {
                printf("feia\n");
            }
        }
     
        for(i=0;i<num_anoes;i++)
        {
            ExcluiUltimoElemento(&anoes);
        }
     
        return 0;
    }
     
    void IniciaLista(lista *sequencia)
    {
        sequencia->inicio = NULL;
        return;
    }
     
    bool ListaVazia(lista *sequencia)
    {
        if (sequencia->inicio == NULL)
            return true;
        else
            return false;
    }
     
    bool InsereElemento(lista *sequencia, int cor)
    {
        no *elemento = NULL;
        elemento = (no *)malloc(sizeof(no));
     
        elemento->touca = cor;
        elemento->proximo = NULL;
     
        if (elemento == NULL)
        {
            // printf("Não foi possível alocar memória.\n");
            return false;
        }
     
        if (ListaVazia(sequencia))
        {
            sequencia->inicio = elemento;
            return true;
        }
     
        else
        {
            no *percorre;
            percorre = sequencia->inicio;
            while (percorre->proximo != NULL)
            {
                percorre = percorre->proximo;
            }
            percorre->proximo = elemento;
            return true;
        }
    }
     
    int ContaCor(lista *sequencia, int start, int end, int cor)
    {
        int cont2 = 1;
        int cont3 = 0;
     
        no *percorre;
        percorre = sequencia->inicio;
     
        while(cont2!=start)
        {
            percorre = percorre->proximo;
            cont2++;
        }
     
        while(start!=end+1)
        {
            // printf("cor: %d\n", percorre->touca);
            if(percorre->touca==cor)
            {
                cont3++;
            }
            percorre=percorre->proximo;
            start++;
        }
        return cont3;
    }
     
    void IndiceMaiorElemento(int vetor[], int tamanho, elemento *x)
    {
        int k=0;
        int maior, ind_maior;
        maior = vetor[0];
        ind_maior = 0;
        for(k=0;k<tamanho;k++)
        {
            if(vetor[k]>maior)
            {
                maior = vetor[k];
                ind_maior = k;
            }
        }
        x->maior = maior;
        x->indice = ind_maior;
    }
     
    // void ImprimeLista(lista *sequencia)
    // {
    //     no *percorre;
     
    //     if (ListaVazia(sequencia))
    //     {
    //         // printf("A lista está vazia.\n");
    //         return;
    //     }
    //     else
    //     {
    //         percorre = sequencia->inicio;
    //         while (percorre->proximo != NULL)
    //         {
    //             printf("%d ", percorre->touca);
    //             percorre = percorre->proximo;
    //         }
    //         printf("%d\n", percorre->touca);
    //         return;
    //     }
    // }
     
    void ExcluiUltimoElemento(lista *sequencia)
    {
        no *aux;
        no *percorre;
        percorre = sequencia->inicio;
     
     
        if(ListaVazia(sequencia))
        {
            return;
        }
     
        if(sequencia->inicio->proximo==NULL)
        {
            free(percorre);
            sequencia->inicio==NULL;
            return;
        }
     
        while(percorre->proximo!=NULL)
        {
            aux = percorre;
            percorre=percorre->proximo;
        }
     
        free(percorre);
        aux->proximo=NULL;
    }
