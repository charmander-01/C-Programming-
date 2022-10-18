// 75% da nota obtida

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
     
    #define MAX 1500
     
    typedef struct NO no;
    typedef struct LISTA lista;
     
    bool CriaLista(lista * sequencia);
    bool ListaVazia(lista * sequencia);
    int TamanhoLista(lista * sequencia);
    bool InsereElemento(lista * sequencia, char caractere);
    bool ExcluiUltimoElemento(lista * sequencia);
     
    struct NO{
        char elemento;
        no *proximo;
    };
     
    struct LISTA{
        no *inicio;
    };
     
    int main()
    {
        bool controle;
        int i, tamanho;
        char vet[MAX];
        int n=0;
     
        lista pilha;
        CriaLista(&pilha);
       
        scanf("%[^\n]", vet);
        getchar();
     
        tamanho = strlen(vet);
     
        for(i=0;i<tamanho;i++)
        {
            if(vet[i]=='(')
            {
                n++;
                InsereElemento(&pilha, vet[i]);
            }
     
            if(vet[i]==')')
            {
                controle = ExcluiUltimoElemento(&pilha);
                if(controle==false)
                {
                    printf("incorreta\n");
                    return 0;
                }
            }
        }
     
        if(n==0)
        {
            printf("incorreta\n");
            return 0;
        }
     
        if(ListaVazia(&pilha))
        {
            printf("correta\n");
        }
        else
        {
            printf("incorreta\n");
        }
     
        return 0;
    }
     
    bool CriaLista(lista * sequencia)
    {
        sequencia->inicio = NULL;
        return true;
    }
     
    bool ListaVazia(lista * sequencia)
    {
        if(sequencia->inicio==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
     
    int TamanhoLista(lista * sequencia){
        int cont = 0;
        if(ListaVazia(sequencia)){
            return cont;
        }
        else{
            no * r;
            r = sequencia->inicio;
            while(r->proximo!=NULL){
                cont++;
                r = r->proximo;
            }
            cont++;
            return cont;
        }
    }
     
    bool InsereElemento(lista * sequencia, char caractere)
    {
        no *item;
        item = (no*)malloc(sizeof(no));
        if(item==NULL)
        {
            return false;
        }
        else
        {
            if(ListaVazia(sequencia))
            {
                sequencia->inicio = item;
                item->elemento = caractere;
                item->proximo = NULL;
                return true;
            }
            else
            {
                no *percorre;
                percorre = sequencia->inicio;
                while(percorre->proximo!=NULL)
                {
                    percorre = percorre->proximo;
                }
                percorre->proximo = item;
                item->elemento = caractere;
                item->proximo = NULL;
                return true;
            }
        }
    }
     
    bool ExcluiUltimoElemento(lista * sequencia)
    {
        if(ListaVazia(sequencia))
        {
            return false;
        }
        else
        {
            no *copia;
            if(TamanhoLista(sequencia)==1)
            {
                copia = sequencia->inicio;
                free(copia);
                sequencia->inicio = NULL;
            }
            else
            {
                no *anterior;
                no *percorre;
                percorre = sequencia->inicio;
                while(percorre->proximo!=NULL)
                {
                    anterior = percorre;
                    percorre = percorre->proximo;
                }
                copia =  anterior->proximo;
                free(copia);
                anterior->proximo = NULL;
            }
     
            return true;
        }
    }
