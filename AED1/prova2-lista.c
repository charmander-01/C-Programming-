    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
     
    typedef struct NO no;
    typedef struct LISTA lista;
     
    struct NO
    {
        int senha;
        no *proximo;
    };
     
    struct LISTA
    {
        no *inicio;
    };
     
    typedef struct ELEMENTO elemento;
    typedef struct ENTRADA entrada;
     
    struct ELEMENTO
    {
        int grupo;
        int senha;
        elemento *proximo;
    };
     
    struct ENTRADA
    {
        elemento *inicio;
    };
     
    void CriaLista(lista *fila);
    bool ListaVazia(lista *fila);
    int  TamanhoLista(lista *fila);
    bool InsereElementoFinal(lista *fila, int numero);
    int  BuscaMenorSenha(lista *fila);
    void ExcluiElemento(lista *fila, int elemento);
     
    bool CriaListaOriginal(entrada *fila);
    bool ListaVaziaOriginal(entrada *fila);
    bool InsereOriginal(entrada *fila, int grupo, int senha);
    void ExcluiOriginal(entrada *fila, int number);
    void ImprimeListaOriginal(entrada *fila);
     
    int main()
    {
        entrada original;
        lista prioridade, outros;
     
        CriaLista(&prioridade);
        CriaLista(&outros);
     
        int qtd_clientes;
        int cont;
        int grupo, senha_main;
        int caixa;
        int menor_senha;
     
        scanf("%d", &qtd_clientes);
     
        if(qtd_clientes<0)
        {
            printf("erro\n");
            return 0;
        }
        if(qtd_clientes==0)
        {
            printf("fim\n");
            return 0;
        }
     
     
        // O loop acontece n vezes, em que n representa a quantidade de clientes.
        // Para inserir as pessoas na fila, também é necessário um loop de 1<=n.
        // Como um loop acontece dentro do outro, a complexidade é O(n^2).
        // A ordem da complexidade do loop a seguir é a maior em todo o programa,
        // assim a complexidade do programa é O(n^2);
        for(cont=0;cont<qtd_clientes;cont++)
        {
            scanf("%d %d", &grupo, &senha_main);
     
            if(grupo>2 || grupo<1)
            {
                printf("erro\n");
                return 0;
            }
            InsereOriginal(&original, grupo, senha_main);
     
            if(grupo==1)
            {
                InsereElementoFinal(&prioridade, senha_main);
            }
            if(grupo==2)
            {
                InsereElementoFinal(&outros, senha_main);
            }
        }
     
        scanf("%d", &caixa);
     
        if(caixa<1||caixa>5)
        {
            printf("erro\n");
            return 0;
        }
     
        if(ListaVazia(&prioridade))
        {
            menor_senha = BuscaMenorSenha(&outros);
            printf("2 %d %d\n", menor_senha, caixa);
     
            ExcluiElemento(&outros, menor_senha);
            ExcluiOriginal(&original, menor_senha);
     
            qtd_clientes--;
            printf("%d\n", qtd_clientes);
     
            if(qtd_clientes==0)
            {
                return 0;
            }
        }
        else
        {
            menor_senha = BuscaMenorSenha(&prioridade);
            printf("1 %d %d\n", menor_senha, caixa);
     
            ExcluiElemento(&prioridade, menor_senha);
            ExcluiOriginal(&original, menor_senha);
     
            qtd_clientes--;
            printf("%d\n", qtd_clientes);
     
            if(qtd_clientes==0)
            {
                return 0;
            }
        }
     
        ImprimeListaOriginal(&original);
     
        // Complexidade: O(n^2);
     
        return 0;
    }
     
    void CriaLista(lista *fila)
    {
        fila->inicio = NULL;
    }
     
    bool ListaVazia(lista *fila)
    {
        if(fila->inicio==NULL) return true;
        else return false;
    }
     
    bool InsereElementoFinal(lista *fila, int numero)
    {
        no *elemento;
        elemento = (no*) malloc(sizeof(no));
     
        if(elemento==NULL)
        {
            // printf("Nao foi possivel alocar memoria\n");
            return false;  
        }
        else
        {
            elemento->senha = numero;
            elemento->proximo = NULL;
     
            if(ListaVazia(fila))
            {
                fila->inicio = elemento;
            }
            else
            {
                no *percorre;
                percorre = fila->inicio;
                while(percorre->proximo!=NULL)
                {
                    percorre = percorre->proximo;
                }
                percorre->proximo = elemento;
            }
        }
    }
     
    int BuscaMenorSenha(lista *fila)
    {
        no *aux;
        no *percorre;
     
        aux = fila->inicio;
        percorre = fila->inicio;
        while(percorre->proximo!=NULL)
        {
            if(percorre->senha<aux->senha)
            {
                aux = percorre;
            }
            percorre = percorre->proximo;
        }
        return aux->senha;
    }
     
    void ExcluiElemento(lista *fila, int elemento)
    {
        no *aux;
        no *percorre;
     
        percorre = fila->inicio;
     
        if(percorre->senha==elemento)
        {
            fila->inicio = percorre->proximo;
            free(percorre);
        }
        else
        {
            while(percorre->proximo->senha!=elemento)
            {
                percorre = percorre->proximo;
            }
            aux = percorre->proximo;
            percorre->proximo = percorre->proximo->proximo;
            free(aux);
        }
    }
     
    bool CriaListaOriginal(entrada *fila)
    {
        fila->inicio = NULL;
    }
     
    bool ListaVaziaOriginal(entrada *fila)
    {
        if(fila->inicio==NULL) return true;
        else return false;
    }
     
    bool InsereOriginal(entrada *fila, int grupo, int senha)
    {
        elemento * pessoa;
     
        pessoa = (elemento*) malloc(sizeof(elemento));
     
        if(pessoa==NULL)
        {
            // printf("Nao foi possivel alocar memoria\n");
            return false;  
        }
        else
        {
            pessoa->grupo = grupo;
            pessoa->senha = senha;
            pessoa->proximo = NULL;
     
            if(ListaVaziaOriginal(fila))
            {
                fila->inicio = pessoa;
            }
            else
            {
                elemento *percorre;
                percorre = fila->inicio;
                while(percorre->proximo!=NULL)
                {
                    percorre = percorre->proximo;
                }
                percorre->proximo = pessoa;
            }
        }
    }
     
    void ExcluiOriginal(entrada *fila, int number)
    {    
        elemento *aux;
        elemento *percorre;
     
        percorre = fila->inicio;
     
        if(percorre->senha==number)
        {
            fila->inicio = percorre->proximo;
            free(percorre);
        }
        else
        {
            while(percorre->proximo->senha!=number)
            {
                percorre = percorre->proximo;
            }
            aux = percorre->proximo;
            percorre->proximo = percorre->proximo->proximo;
            free(aux);
        }
    }
     
    void ImprimeListaOriginal(entrada *fila)
    {
        elemento *percorre;
        percorre = fila->inicio;
        while(percorre->proximo!=NULL)
        {
            printf("%d %d\n", percorre->grupo, percorre->senha);
            percorre = percorre->proximo;
        }
        printf("%d %d\n", percorre->grupo, percorre->senha);
    }
