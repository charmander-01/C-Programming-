// 80 % da nota obtida

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>
     
    #define MAX 30
     
    typedef struct NO no;
    typedef struct LISTA lista;
     
    struct NO
    {
        no *anterior;
        char vet1[MAX];
        char vet2[MAX];
        no *posterior;
    };
     
    struct LISTA
    {
        no *inicio;
        no *final;
    };
     
    bool CriaLista(lista *sequencia);
    bool ListaVazia(lista *sequencia);
    bool InsereElemento(lista *sequencia, char *direcao, char *rua);
    bool ImprimeReverso(lista *sequencia);
    void ImprimeLista(lista *sequencia);
    void ExcluiElemento(lista *sequencia, no *ponteiro);
    void ExcluiLista(lista *sequencia);
     
    int main()
    {
        // int controle;
        int i;
        lista caminho;
        CriaLista(&caminho);
     
        for (i = 0; i < 15; i++)
        {
            char escrita[MAX];
            char localidade[MAX];
            scanf("%[^\n]", escrita);
            getchar();
            // printf("%s\n", escrita);
            scanf("%[^\n]", localidade);
            getchar();
            // printf("%s\n", localidade);
     
            InsereElemento(&caminho, escrita, localidade);
     
            if (strcmp(localidade, "ESCOLA") == 0)
            {
                break;
            }
        }
     
        // printf("\n");
        // ImprimeLista(&caminho);
     
        /*controle =*/ImprimeReverso(&caminho);
        // printf("%d\n", controle);
     
        ExcluiLista(&caminho);
     
        return 0;
    }
     
    bool CriaLista(lista *sequencia)
    {
        sequencia->inicio = NULL;
        sequencia->final = NULL;
        return true;
    }
     
    bool ListaVazia(lista *sequencia)
    {
        if (sequencia->inicio == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
     
    bool InsereElemento(lista *sequencia, char *direcao, char *rua)
    {
        no *item;
        item = (no *)malloc(sizeof(no));
     
        if (item == NULL)
        {
            return false;
        }
        else
        {
            if (ListaVazia(sequencia))
            {
                // printf("Insere o primeiro elemento\n");
                sequencia->inicio = item;
                sequencia->final = item;
                item->anterior = item;
                strcpy(item->vet1, direcao);
                strcpy(item->vet2, rua);
                item->posterior = NULL;
                return true;
            }
            else
            {
                no *percorre;
                percorre = sequencia->inicio;
                while (percorre->posterior != NULL)
                {
                    percorre = percorre->posterior;
                }
                percorre->posterior = item;
                sequencia->final = item;
                item->anterior = percorre;
                strcpy(item->vet1, direcao);
                strcpy(item->vet2, rua);
                item->posterior = NULL;
                return true;
            }
        }
    }
     
    bool ImprimeReverso(lista *sequencia)
    {
        no *end;
        end = sequencia->final;
     
        if (end == sequencia->inicio)
        {
            return false;
        }
     
        while (end != sequencia->inicio)
        {
            // printf("***********\n");
     
            if (strcmp(end->vet1, "DIREITA") == 0)
            {
                printf("Vire a ESQUERDA");
            }
            if (strcmp(end->vet1, "ESQUERDA") == 0)
            {
                printf("Vire a DIREITA");
            }
     
            printf(" na rua ");
            printf("%s", end->anterior->vet2);
            printf(".\n");
     
            end = end->anterior;
        }
        if (strcmp(end->vet1, "DIREITA") == 0)
        {
            printf("Vire a ESQUERDA");
        }
        if (strcmp(end->vet1, "ESQUERDA") == 0)
        {
            printf("Vire a DIREITA");
        }
        printf(" para chegar em CASA.\n");
        return true;
    }
     
    void ImprimeLista(lista *sequencia)
    {
        no *percorre;
        percorre = sequencia->inicio;
        while (percorre->posterior != NULL)
        {
            printf("%s\n", percorre->vet1);
            printf("%s\n", percorre->vet2);
            percorre = percorre->posterior;
        }
        printf("%s\n", percorre->vet1);
        printf("%s\n", percorre->vet2);
    }
     
    void ExcluiLista(lista *sequencia)
    {
        no *percorre, *aux, *clone;
        aux = sequencia->inicio;
        percorre = sequencia->final;
        while(percorre->anterior!=aux)
        {
            clone = percorre;
            percorre = percorre->anterior;
            free(clone);
        }
        free(percorre->anterior);
    }
