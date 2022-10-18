    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
     
    typedef struct NO no;
    typedef struct LISTA lista;
     
    struct NO{
        int elemento;
        no * proximo;
    };
     
    struct LISTA{
        no *inicio;
    };
     
    int CriaLista(lista *l);
    int ListaVazia(lista *l);
    int TamanhoLista(lista *l);
    int InsereElementoLista(int x, lista *l);
    int ExcluiElementoLista(int x, lista *l);
    void ImprimeLista(lista *l);
     
    int main()
    {
        lista fila;
        int i, pessoa, pessoa_saiu;
        int num_pessoas, pessoas_sairam;
       
        CriaLista(&fila);    
       
        scanf("%d", &num_pessoas);
        for(i=0;i<num_pessoas;i++)
        {
            scanf("%d", &pessoa);
            InsereElementoLista(pessoa, &fila);
        }
       
        scanf("%d", &pessoas_sairam);
       
        for(i=0;i<pessoas_sairam;i++)
        {
            scanf("%d", &pessoa_saiu);
            ExcluiElementoLista(pessoa_saiu, &fila);
        }
       
        ImprimeLista(&fila);
       
        return 0;
    }
     
    int CriaLista(lista *l){
        l->inicio=NULL;
        return true;
    }
     
    int ListaVazia(lista *l){
        if(l->inicio==NULL){
            return true;
        }
        else{
            return false;
        }
    }
     
    int TamanhoLista(lista *l){
        int cont = 0;
        if(ListaVazia(l)){
            return cont;
        }
        else{
            no * r;
            r = l->inicio;
            while(r->proximo!=NULL){
                cont++;
                r = r->proximo;
            }
            cont++;
            return cont;
        }
    }
     
    int InsereElementoLista(int x, lista *l){
        no* r;
        no* novo;
        novo = (no*) malloc(sizeof(no));
        novo->elemento = x;
        novo->proximo = NULL;
     
        if(ListaVazia(l)){
            l->inicio = novo;
            return true;
        }
        else{
            r =(l->inicio);
            while(r->proximo!=NULL){
                if(r->elemento == x) {
                    return false;
                }
                r = r->proximo;
            }
            if(r->elemento == x){
                return false;
            }
            r->proximo = novo;
            return true;
        }
    }
     
    int ExcluiElementoLista(int x, lista *l){
        no* r;
        no* q;
        r = l->inicio;
        if(ListaVazia(l)){
            return false;
        }
        else{
            if(TamanhoLista(l)==1){
                q = l->inicio;
                l->inicio = NULL;
                free(q);
                return true;
            }
            else{
                if(r->elemento==x){
                    q = r;
                    l->inicio = r->proximo;
                    free(q);
                    return true;
                }
                while(r->proximo!=NULL){
                    if(r->proximo->elemento==x){
                        q = r->proximo;
                        r->proximo = r->proximo->proximo;
                        free(q);
                        return true;
                    }
                    if(r->proximo->proximo==NULL && r->proximo->elemento==x){
                        q = r->proximo;
                        r->proximo=r->proximo->proximo;
                        free(q);
                        return true;
                    }
                    r = r->proximo;
                }
            }
        }
    }
     
    void ImprimeLista(lista *l){
        no * r;
        r = l->inicio;
        if(ListaVazia(l)){
            //printf("Fila vazia\n");
            printf("\n");
            return;
        }
        else{
            while(r->proximo!=NULL){
                printf("%d ", r->elemento);
                r = r->proximo;
            }
            printf("%d", r->elemento);
            printf("\n");    
        }
    }
