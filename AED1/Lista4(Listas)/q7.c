    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
     
    typedef struct NO no;
    typedef struct LISTA lista;
     
    struct NO
    {
        int elemento;
        no *proximo;
    };
     
    struct LISTA
    {
        no *inicio;
    };
     
    bool CriaLista(lista *sequencia);
    bool ListaVazia(lista *sequencia);
    bool InsereElemento(lista *sequencia, int elemento);
    int TamanhoLista(lista *sequencia);
    bool InsereDepois(lista *sequencia, int novo_elemento, int referencia);
    bool Remove_Elemento(lista *sequencia, int elemento);
    int ContaIntervalo(lista *sequencia, int valor1, int valor2);
    void MostraLista(lista *sequencia);
    void ExcluiLista(lista *sequencia);
     
    int main()
    {
        lista inimigos_de_arya;
     
        CriaLista(&inimigos_de_arya);
     
        int i;
        int qtd_inimigos;
        int inimigo;
        int inimigo2;
        int pessoa;
        int valor;
        char caractere;
     
        scanf("%d", &qtd_inimigos);
     
        for (i = 0; i < qtd_inimigos; i++)
        {
            scanf("%d", &inimigo);
            InsereElemento(&inimigos_de_arya, inimigo);
        }
     
        //MostraLista(&inimigos_de_arya);
     
        while (1)
        {
            scanf("%c", &caractere);
            if (caractere == 'I')
            {
                scanf("%d", &pessoa);
                scanf("%d", &inimigo);
                InsereDepois(&inimigos_de_arya, pessoa, inimigo);
                //MostraLista(&inimigos_de_arya);
                printf("inserido %d\n", pessoa);
            }
            if (caractere == 'R')
            {
                scanf("%d", &inimigo);
                Remove_Elemento(&inimigos_de_arya, inimigo);
                //MostraLista(&inimigos_de_arya);
                printf("removido %d\n", inimigo);
            }
            if (caractere == 'C')
            {
                scanf("%d", &inimigo);
                scanf("%d", &inimigo2);
                valor = ContaIntervalo(&inimigos_de_arya, inimigo, inimigo2);
                printf("quantidade %d\n", valor);
            }
            if (caractere == 'M')
            {
                printf("lista ");
                if (ListaVazia(&inimigos_de_arya) == true)
                {
                    printf("lista vazia\n");
                }
                else
                {
                    MostraLista(&inimigos_de_arya);
                }
            }
            if (caractere == 'F')
            {
                ExcluiLista(&inimigos_de_arya);
                printf("fim\n");
                return 0;
            }
        }
    }
     
    bool CriaLista(lista *sequencia)
    {
        sequencia->inicio = NULL;
        return true;
    }
     
    bool ListaVazia(lista *sequencia)
    {
        if (sequencia->inicio == NULL)
            return true;
        else
            return false;
    }
     
    int TamanhoLista(lista *sequencia)
    {
        int cont = 0;
     
        no *r;
        r = sequencia->inicio;
     
        if (r == NULL)
        {
            return cont;
        }
        else
        {
            while (r != NULL)
            {
                cont++;
                r = r->proximo;
            }
            return cont;
        }
    }
     
    bool InsereElemento(lista *sequencia, int elemento)
    {
        no *dado;
        dado = (no *)malloc(sizeof(no));
     
        if (dado == NULL)
        {
            return false;
        }
        else
        {
            dado->elemento = elemento;
            dado->proximo = NULL;
     
            if (ListaVazia(sequencia))
            {
                sequencia->inicio = dado;
                return true;
            }
            else
            {
                no *percorre;
                percorre = sequencia->inicio;
     
                if (TamanhoLista(sequencia) == 1)
                {
                    percorre->proximo = dado;
                    return true;
                }
                else
                {
                    while (percorre->proximo != NULL)
                    {
                        percorre = percorre->proximo;
                    }
                    percorre->proximo = dado;
                    return true;
                }
            }
        }
    }
     
    bool InsereDepois(lista *sequencia, int novo_elemento, int referencia)
    {
        no *dado;
        dado = (no *)malloc(sizeof(no));
     
        if (dado == NULL)
        {
            return false;
        }
        else
        {
            dado->elemento = novo_elemento;
     
            no *percorre;
            percorre = sequencia->inicio;
     
            // detalhe: no auxiliar
            no *aux;
     
            if (percorre->elemento == referencia)
            {
                aux = percorre->proximo;
                percorre->proximo = dado;
                dado->proximo = aux;
                return true;
            }
            else
            {
                while (percorre->proximo->elemento != referencia)
                {
                    percorre = percorre->proximo;
                }
     
                aux = percorre->proximo->proximo;
                percorre->proximo->proximo = dado;
                dado->proximo = aux;
                return true;
            }
        }
    }
     
    bool Remove_Elemento(lista *sequencia, int elemento)
    {
        no *percorre;
        no *aux;
        no *clone;
     
        percorre=sequencia->inicio;
     
        if(percorre->elemento==elemento)
        {
            clone = percorre;
            sequencia->inicio = percorre->proximo;
            free(clone);
        }
        else
        {
            while(percorre->proximo->elemento!=elemento)
            {
     
                percorre = percorre->proximo;
            }
            aux = percorre->proximo->proximo;
            clone = percorre->proximo;
            percorre->proximo = aux;
            free(clone);
        }
        return true;
    }
     
    int ContaIntervalo(lista *sequencia, int valor1, int valor2)
    {
        int cont = 0;
        int comeco, final;
        no *partida, *chegada;
     
        no *percorre;
        percorre =  sequencia->inicio;
     
        if(percorre->elemento==valor1 || percorre->elemento==valor2)
        {
            partida = percorre;
        }
        else
        {
            while(1)
            {
                if (percorre->proximo->elemento == valor1 || percorre->proximo->elemento == valor2)
                {
                    break;
                }
                percorre = percorre->proximo;
            }
     
            partida = percorre->proximo;
        }
        while(1)
        {
            if(partida->proximo->elemento==valor1 || partida->proximo->elemento==valor2)
            {
                break;
            }
            partida = partida->proximo;
            cont++;
        }
     
        return cont;
    }
     
    void MostraLista(lista *sequencia)
    {
        no *percorre;
        percorre = sequencia->inicio;
        while(percorre!=NULL)
        {
            printf("%d ", percorre->elemento);
            percorre = percorre->proximo;
        }
        printf("\n");
    }
     
    void ExcluiLista(lista *sequencia)
    {
        no *percorre;
        percorre = sequencia->inicio;
        while(percorre->proximo!=NULL)
        {
            Remove_Elemento(sequencia, percorre->elemento);
            percorre = percorre->proximo;
        }
    }
