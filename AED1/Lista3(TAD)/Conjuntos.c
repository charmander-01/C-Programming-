    //==============================================================================
    // Arquivo ponto.h
    //==============================================================================
     
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <math.h>
    #include <limits.h>
     
    #define SUCESSO 1
    #define FALHA 0
     
    #define CRESCENTE 1
    #define DECRESCENTE 0
     
    #define MAX 1000000
     
    // Funcoes padroes
    typedef struct NO no;
    typedef struct LISTA lista;
    typedef struct PARTES partes;
    int criaConjunto(lista *l);
    int conjuntoVazio(lista *l);
    int insereElementoConjunto(int x, lista *l);
    int excluirElementoConjunto(int x, lista *l);
    int tamanhoConjunto(lista *l);
    int maior(int x, lista *l);
    int menor(int x, lista *l);
    int pertenceConjunto(int x, lista *l); 
    int conjuntosIdenticos(lista *l1, lista *l2);
    int subconjunto(lista *l1, lista *l2);
    lista *complemento(lista *l1, lista *l2);  
    lista *uniao(lista *l1, lista *l2);
    lista *interseccao(lista *l1, lista *l2);
    lista *diferenca(lista *l1, lista *l2);
    void geraConjunto(no* pos,lista * partes);
    void mostraConjunto(lista *l, int ordem);
    int copiarConjunto(lista *l1, lista *l2);
    int destroiConjunto(lista *l1);
     
    // Funcoes extras
    void menu();
    int abs(int a);
    void troca_sinal(int * vet, int tam);
    void selection_sort(int *sequence, int tam);
    void printa_conjunto(lista *l);
    lista *ordena_conjunto(lista *l, int forma);
     
    //==============================================================================
    // Arquivo ponto.c
    //==============================================================================
     
    // Structs
    struct NO{
        int elemento;
        no *proximo;
    };
     
    struct LISTA{
        no *inicio;
    };
     
    // Funcoes
     
    /**
     * @brief Imprime o menu de operacoes;
     */
    void menu(){
        printf("\n======================================================================\n");
        printf("Menu de opcoes\n");
        printf("======================================================================\n");
        printf("Digite o numero de acordo com a opcao desejada:\n");
        printf("(OBS.: Caso queira encerrar o programa, digite 0)\n");
        printf("01 - Cria um conjunto\n");
        printf("02 - Verifica se o conjunto e vazio\n");
        printf("03 - Insere um elemento no conjunto\n");
        printf("04 - Exclui um elemento do conjunto\n");
        printf("05 - Informa o tamanho do conjunto\n");
        printf("06 - Conta quantos elementos do conjunto sao maiores que um valor x\n"); 
        printf("07 - Conta quantos elementos do conjunto sao menores que um valor x\n"); 
        printf("08 - Verifica se um elemento x pertence ao conjunto\n");
        printf("09 - Verifica se dois conjuntos sao iguais\n");
        printf("10 - Verifica se um dado conjunto e subconjunto de outro\n");
        printf("11 - Retorna o conjunto complementar dados dois conjuntos\n");
        printf("12 - Retorna o conjunto uniao dados dois conjuntos\n");
        printf("13 - Retorna o conjunto intersecao dados dois conjuntos\n");
        printf("14 - Retorna o conjunto diferenca dados dois conjuntos\n");
        printf("15 - Retorna o conjunto das partes de um dado conjunto\n");
        printf("16 - Mostra os elementos do conjunto em ordem crescente ou decrescente\n");
        printf("17 - Copia os elementos do conjunto 1 para o conjunto 2\n");
        printf("18 - Destroi um conjunto dado (libera o espaco na memoria)\n");
        printf("======================================================================\n");
    }
     
    /**
     * @brief Cria um conjunto.
     * @param l 
     * @return int 
     */
    int criaConjunto(lista *l){
        l->inicio=NULL;
        return true;
    }
     
    /**
     * @brief Verifica se o conjunto e vazio.
     * Retorna true em caso afirmativo e false em caso contrario.
     * @param l 
     * @return int 
     */
    int conjuntoVazio(lista *l){
        if(l->inicio==NULL){
            return true;
        }
        else{
            return false;
        }
    }
     
    /**
     * @brief Insere um elemento x no conjunto.
     * Retorna true quando e possivel realizar a insercao e false quando o elemento
     * ja pertence ao conjunto.
     * @param x 
     * @param l 
     * @return int 
     */
    int insereElementoConjunto(int x, lista *l){
        no* r;
        no* novo;
        novo = (no*) malloc(sizeof(no)); 
        novo->elemento = x;
        novo->proximo = NULL;
     
        if(conjuntoVazio(l)){
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
     
    /**
     * @brief Exclui um elemento x do conjunto.
     * Retorna true quando e possivel excluir o elemento e false em caso contrario.
     * @param x 
     * @param l 
     * @return int 
     */
    int excluirElementoConjunto(int x, lista *l){
        no* r;
        no* q;
        r = l->inicio;
        if(conjuntoVazio(l)){
            return false;
        }
        else{
            if(tamanhoConjunto(l)==1){
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
        return false;
    }
     
    /**
     * @brief Retorna a cardinalidade do conjunto.
     * Se o conjunto for vazio, retorna zero.
     * @param l 
     * @return int 
     */
    int tamanhoConjunto(lista *l){
        int cont = 0;
        if(conjuntoVazio(l)){
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
     
    /**
     * @brief Retorna a quantidade (negativa) de elementos do conjunto 
     * que sao maiores do que um valor x. Retorna zero se todos os
     * elementos são menores do que o valor x;
     * @param x 
     * @param l 
     * @return int 
     */
    int maior(int x, lista *l){
        int cont = 0;
        no * r;
        r = l->inicio;
        while(r->proximo!=NULL){
            if(r->elemento>x){
                cont--;
            }
            r = r->proximo;
        }
        if(r->elemento>x){
            cont--;
        }
        return cont;
    }
     
    /**
     * @brief Retorna o valor absoluto de um numero inteiro.
     * @param a 
     * @return int 
     */
    int abs(int a){
        if(a>=0){
            return a;        
        } 
        else{
            return (-a);
        }
    }
     
    /**
     * @brief Retorna a quantidade (negativa) de elementos do conjunto
     * que sao menores do que um valor x. Retorna zero se todos os 
     * elementos sao maiores do que o valor x.
     * @param x 
     * @param l 
     * @return int 
     */
    int menor(int x, lista *l){
        int cont = 0;
        no * r;
        r = l->inicio;
        while(r->proximo!=NULL){
            if(r->elemento<x){
                cont--  ;
            }
            r = r->proximo;
        }
        if(r->elemento<x){
            cont--;
        }
        return cont;
    }
     
    /**
     * @brief Retrona true quando o elemento x pertence ao conjunto
     * e false em caso contrario.
     * @param x 
     * @param l 
     * @return int 
     */
    int pertenceConjunto(int x, lista *l){
        no * r;
        r = l->inicio;
        while(r->proximo!=NULL){
            if(r->elemento==x){
                return true;
            }
            r = r->proximo;
        }
        if(r->elemento==x){
            return true;
        }
        return false;
    }
     
    /**
     * @brief Retorna true quando os conjuntos sao identicos
     * e false em caso contrario.
     * @param l1 
     * @param l2 
     * @return int 
     */
    int conjuntosIdenticos(lista *l1, lista *l2){
        if(tamanhoConjunto(l1)!=tamanhoConjunto(l2)){
            return false;
        }
        else{
            if(conjuntoVazio(l1) && conjuntoVazio(l2)){
                return true;
            }
            no *primeiro;
            primeiro = l1->inicio;
            while(primeiro->proximo!=NULL){
                if(!pertenceConjunto(primeiro->elemento, l2)){
                    return false;
                }
                primeiro = primeiro->proximo;            
            }
            if(!pertenceConjunto(primeiro->elemento, l2)){
                return false;
            }
            return true;
        }
    }
     
    /**
     * @brief Retorna true quando o primeiro conjunto
     * e subconjunto do segundo e false em caso contario.
     * @param l1 
     * @param l2 
     * @return int 
     */
    int subconjunto(lista *l1, lista *l2){
        if(conjuntoVazio(l1)){
            return true;
        }
        if(conjuntosIdenticos(l1, l2)){
            return true;
        }
        if(tamanhoConjunto(l1)>tamanhoConjunto(l2)){
            return false;
        }    
        else{
            no *primeiro;
            primeiro = l1->inicio;
            while(primeiro->proximo!=NULL){
                if(!pertenceConjunto(primeiro->elemento,l2)){
                    return false;
                }
                primeiro = primeiro->proximo;
            }
            if(!pertenceConjunto(primeiro->elemento, l2)){
                return false;
            }
            return true;
        }
    }
     
    /**
     * @brief Retorna um conjunto que contem os elementos de C2 que nao pertencem a C1.
     *  Se todos os elementos de C2 estao em C1, entao retorna um conjunto vazio. 
     * @param l1 
     * @param l2 
     * @return lista* 
     */
    lista *complemento(lista *l1, lista *l2){
        int a;
        lista *complementar;
        complementar = (lista*) malloc(sizeof(lista));
        a = criaConjunto(complementar);
        if(a){
            no *primeiro;
            primeiro = l2->inicio;
            while(primeiro->proximo!=NULL){
                if(!pertenceConjunto(primeiro->elemento, l1)){
                    insereElementoConjunto(primeiro->elemento, complementar);
                }
                primeiro = primeiro->proximo;
            }
            if(!pertenceConjunto(primeiro->elemento, l1)){
                insereElementoConjunto(primeiro->elemento, complementar);
            }  
            return complementar;
        }
    }
     
    /**
     * @brief Imprime na tela os elementos do conjunto.
     * @param l 
     */
    void printa_conjunto(lista *l){
        no * r;
        r = l->inicio;
        if(conjuntoVazio(l)){
            printf("\nConjunto vazio!\n");
            return;
        }
        else{
            printf("\nOs elementos do conjunto sao: ");
            while(r->proximo!=NULL){
                printf("%d ", r->elemento);
                r = r->proximo;
            }
            printf("%d", r->elemento);
            printf("\n");    
        }
    }
     
    /**
     * @brief Retorna o conjunto uniao dos dois conjuntos passsados
     * como parametros.
     * @param l1 
     * @param l2 
     * @return lista* 
     */
    lista *uniao(lista *l1, lista *l2){
        int a;
        lista *juncao;
        lista *complementar;
        lista *maior;
        lista *menor;
        juncao = (lista*) malloc(sizeof(lista));
        a = criaConjunto(juncao);
        if(a){
            no * r;
            no * c;
            if(tamanhoConjunto(l1)>tamanhoConjunto(l2)){
                maior = l2;
                menor = l1;
            }
            else{
                maior = l1;
                menor = l2;
            }
            r = maior->inicio;
            while(r->proximo!=NULL){
                insereElementoConjunto(r->elemento, juncao);
                r = r->proximo;
            }
            insereElementoConjunto(r->elemento, juncao);
            complementar = complemento(maior, menor);
            c = complementar->inicio;
            while(c->proximo!=NULL){
                insereElementoConjunto(c->elemento, juncao);
                c = c->proximo;
            }
            insereElementoConjunto(c->elemento, juncao);
            return juncao;
        }
    }
     
    /**
     * @brief Retorna um conjunto contendo os elementos que fazem
     * parte tanto de l1 quanto de l2.
     * @param l1 
     * @param l2 
     * @return lista* 
     */
    lista *interseccao(lista *l1, lista *l2){
        lista *conjunto_interseccao;
        conjunto_interseccao = (lista*) malloc(sizeof(lista));
        no *r;
        lista *maior;
        lista *menor;
        if(tamanhoConjunto(l1)<=tamanhoConjunto(l2)){
            menor = l1;
        }
        else{
            menor = l2;
        }
        r = menor->inicio;
        while(r->proximo!=NULL){
            if(pertenceConjunto(r->elemento, l1) && pertenceConjunto(r->elemento, l2)){
                insereElementoConjunto(r->elemento, conjunto_interseccao);
            }
            r = r->proximo;
        }
        if(pertenceConjunto(r->elemento, l1) && pertenceConjunto(r->elemento, l2)){
            insereElementoConjunto(r->elemento, conjunto_interseccao);
        }
        return conjunto_interseccao;
    }
     
    /**
     * @brief Retorna um conjunto que contem os
     * elementos de l1 que nao pertencem a l2.
     * @param l1 
     * @param l2 
     * @return lista* 
     */
    lista *diferenca(lista *l1, lista *l2){
        lista * diferenca;
        diferenca = (lista*) malloc(sizeof(lista));
        no * r;
        r = l1->inicio;
        while(r->proximo!=NULL){
            if(!pertenceConjunto(r->elemento, l2)){
                insereElementoConjunto(r->elemento, diferenca);
            }
            r = r->proximo;
        }
        if(!pertenceConjunto(r->elemento, l2)){
            insereElementoConjunto(r->elemento, diferenca);
        }
        return diferenca;    
    }
     
    /**
     * @brief Imprime na tela o conjunto das partes (conjunto
     * potencia) do conjunto informado. Cada elemento e impresso
     * seguindo o padrao de conjunto.
     * @param pos 
     * @param partes 
     */
    void geraConjunto(no* pos,lista * partes)
    {
        if(pos==NULL)
        {
            mostraConjunto(partes, 1);
            printf("\n");
        }else
        {
            insereElementoConjunto(pos->elemento,partes);
            geraConjunto(pos->proximo,partes);
            excluirElementoConjunto(pos->elemento,partes);
            geraConjunto(pos->proximo,partes);
        }
    }
     
    /**
     * @brief Algoritmo de ordenação de vetores.
     * @param sequence 
     * @param tam 
     */
    void selection_sort(int *sequence, int tam){
        int cont1, cont2, temp, i;
        int menor_elemento, ind_menor;
     
        for(cont1=0;cont1<tam-1;cont1++){
            menor_elemento = sequence[cont1];
            ind_menor = cont1;
            for(cont2=cont1;cont2<tam;cont2++){
                if(sequence[cont2]<menor_elemento){
                    menor_elemento = sequence[cont2];    #include <stdio.h>
     
    int main(){
        int N, i;
        int divisores = 0;
     
        // Entre com o numero inteiro positivo que deve ser testado:
        scanf("%d", &N);
     
        if(N<=0){
            printf("O numero inteiro informado deve ser maior do que zero\n");
            return 0;
        }
        for(i=1;i<=N;i++){
            if(N%i==0) divisores++;
        }
        if(divisores==2){
            printf("O numero %d é primo\n", N);    
        }
        else{
            printf("O numero %d não é primo\n", N);
        }
     
        return 0;
    }

×

                    ind_menor = cont2;
                }            
            }
            temp = sequence[cont1];
            sequence[cont1] = menor_elemento;
            sequence[ind_menor] = temp;
        }
    }
     
    /**
     * @brief Ordena um conjunto de maneira crescente
     * ou de maneira decrescente ( de acordo com a forma).
     * @param l 
     * @param forma 
     * @return lista* 
     */
    lista *ordena_conjunto(lista *l, int forma){
        lista * conjunto_ordenado;
        int tamanho;
        no * r;
     
        tamanho = tamanhoConjunto(l);
     
        int vet[tamanho];
        int i;
        conjunto_ordenado = (lista*) malloc(tamanho*sizeof(lista));
        criaConjunto(conjunto_ordenado);
     
        i = 0;
        r = l->inicio;
        while(r!=NULL){
            vet[i] = r->elemento;
            r = r->proximo;
            i++;
        }
     
        if(forma==CRESCENTE){
            selection_sort(vet, tamanho);
        }
        if(forma==DECRESCENTE){
            troca_sinal(vet, tamanho);
            selection_sort(vet, tamanho);
            troca_sinal(vet, tamanho);
        }
     
        i = 0;
        while(i<tamanho){
            insereElementoConjunto(vet[i], conjunto_ordenado);
            i++;
        }
     
        return conjunto_ordenado;
    }
     
    /**
     * @brief Troca o sinal de todos os valores
     * do vetor informado.
     * @param vet 
     * @param tam 
     */
    void troca_sinal(int * vet, int tam){
        int i=0;
        for(i=0;i<tam;i++){
            vet[i] = -(vet[i]);
        }
    }
     
    /**
     * @brief Imprime os elementos do conjunto
     * em ordem crescente ou em ordem decrescente 
     * (de acordo com o informado).
     * @param l 
     * @param ordem 
     */
    void mostraConjunto(lista *l, int ordem){
        lista * receptor;
        if(ordem==CRESCENTE){
            receptor = ordena_conjunto(l, CRESCENTE);       
        }
        if(ordem==DECRESCENTE){
            receptor = ordena_conjunto(l, DECRESCENTE);
        }
        printa_conjunto(receptor);
    }
     
    /**
     * @brief Faz com que o conjunto l2 se torne um copia
     * do conjunto l1.
     * @param l1 
     * @param l2 
     * @return int 
     */
    int copiarConjunto(lista *l1, lista *l2){
        destroiConjunto(l2);
        no*p;
        p = l1->inicio;
        while(p->proximo!=NULL){
            insereElementoConjunto(p->elemento, l2);
            p = p->proximo;
        }
        insereElementoConjunto(p->elemento, l2);
        return SUCESSO;
    }
     
    /**
     * @brief Destroi um conjunto e libera
     * o espaco ocupado por ele na memoria.
     * @param l 
     * @return int 
     */
    int destroiConjunto(lista *l){
        no * d;
        no * aux;
        d = l->inicio;
        while(tamanhoConjunto(l)!=0){
            aux = d->proximo;
            excluirElementoConjunto(d->elemento, l);
            d = aux;
        }
        return true;
    }
     
    // Corpo da funcao principal (main)
     
    int main(){
        lista vetlista[1000];
        lista * vetpartes;
     
        vetpartes = (lista*) malloc(sizeof(lista));
        criaConjunto(vetpartes);
     
        int i = 0;
        int j, k;
        int m = -1;
        int num;
        int maiores;
        int menores;
        lista *p_lista;
     
        printf("\nConjunto de Numeros Naturais - TAD\n");
     
        while(m!=0){
            menu();
            scanf("%d", &m);
            if(m==1){
                criaConjunto(&vetlista[i]);
                printf("\nO conjunto foi criado com sucesso!\n");
                i++;
                printf("\nO indice do conjunto criado e %d\n", i);
                printf("O indice do conjunto sera importante para futuras operacoes\n");
            }
            if(m==2){
                printf("Entre com o numero (indice) do conjunto: ");
                scanf("%d", &j);
                if(conjuntoVazio(&vetlista[j-1])){
                    printf("\nO conjunto e vazio!\n");
                }
                else{
                    printf("\nO conjunto nao e vazio\n");
                }
            }
            if(m==3){
                printf("Entre com o numero que sera inserido: ");
                scanf("%d", &num);
                printf("Entre com o numero (indice) do conjunto: ");
                scanf("%d", &j);
                insereElementoConjunto(num, &vetlista[j-1]);
            }
            if(m==4){
                printf("Entre com o numero que sera excluido: ");
                scanf("%d", &num);
                printf("Entre com o numero (indice) do conjunto: ");
                scanf("%d", &j);
                excluirElementoConjunto(num, &vetlista[j-1]);            
            }
            if(m==5){
                printf("Entre com o numero (indice) do conjunto: ");
                scanf("%d", &j);
                num = tamanhoConjunto(&vetlista[j-1]);
                printf("\nO numero de elementos do conjunto e: %d\n", num);
            }
            if(m==6){
                printf("Entre com o valor x: ");
                scanf("%d", &num);
                printf("Entre com o numero (indice) do conjunto: ");
                scanf("%d", &j);          
                maiores = maior(num, &vetlista[j-1]);
                if(maiores==0){
                    printf("O conjunto nao apresenta nenhum valor maior do que %d\n", num);
                }
                else{
                    printf("O conjunto apresenta %d elemento", abs(maiores) );
                    if(abs(maiores)>1){
                        printf("s");
                    }
                    printf(" maior");
                    if(abs(maiores)>1){
                        printf("es");
                    }
                    printf(" do que %d\n", num);
                }
            }
            if(m==7){
                printf("Entre com o valor x: ");
                scanf("%d", &num);
                printf("Entre com o numero (indice) do conjunto: ");
                scanf("%d", &j);          
                menores = menor(num, &vetlista[j-1]);
                if(menores==0){
                    printf("\nO conjunto nao apresenta nenhum valor menor do que %d\n", num);
                }
                printf("\nO conjunto apresenta %d elemento", abs(menores) );
                if(abs(menores)>1){
                    printf("s");
                }
                printf(" menor");
                if(abs(menores)>1){
                    printf("es");
                }
                printf(" do que %d\n", num);
            }
            if(m==8){
                printf("Digite o elemento x: ");
                scanf("%d", &num);
                printf("Entre com o numero (indice) do conjunto: ");
                scanf("%d", &j);
                if(pertenceConjunto(num, &vetlista[j-1])){
                    printf("\nO elemento %d pertence ao conjunto!\n", num);
                }
                else{
                    printf("\nO elemento %d nao pertence ao conjunto\n", num);
                }
            }
            if(m==9){
                printf("Entre com o numero (indice) do primeiro conjunto: ");
                scanf("%d", &j);
                printf("Entre com o numero (indice) do segundo conjunto: ");
                scanf("%d", &k);
                if(conjuntosIdenticos(&vetlista[j-1], &vetlista[k-1])){
                    printf("\nOs conjuntos sao identicos!\n");
                }
                else{
                    printf("\nOs conjuntos nao sao identicos\n");
                }
            }
            if(m==10){
                printf("Entre com o numero (indice) do primeiro conjunto: ");
                scanf("%d", &j);
                printf("Entre com o numero (indice) do segundo conjunto: ");
                scanf("%d", &k);
                if(subconjunto(&vetlista[j-1], &vetlista[k-1])){
                    printf("\nO primeiro conjunto e subconjunto do segundo conjunto!\n");
                }
                else{
                    printf("\nNao e subconjunto\n");
                }
            }
            if(m==11){
                printf("Entre com o numero (indice) do primeiro conjunto: ");
                scanf("%d", &j);
                printf("Entre com o numero (indice) do segundo conjunto: ");
                scanf("%d", &k);
                p_lista = complemento(&vetlista[j-1], &vetlista[k-1]);
                vetlista[i] = *p_lista;
                i++;
                printf("O indice do conjunto complementar e %d\n", i);
            }
            if(m==12){
                printf("Entre com o numero (indice) do primeiro conjunto: ");
                scanf("%d", &j);
                printf("Entre com o numero (indice) do segundo conjunto: ");
                scanf("%d", &k);
                p_lista = uniao(&vetlista[j-1], &vetlista[k-1]);
                vetlista[i] = *p_lista;
                i++;
                printf("O indice do conjunto uniao e %d\n", i);            
            }
            if(m==13){
                printf("Entre com o numero (indice) do primeiro conjunto: ");
                scanf("%d", &j);
                printf("Entre com o numero (indice) do segundo conjunto: ");
                scanf("%d", &k);
                p_lista = interseccao(&vetlista[j-1], &vetlista[k-1]);
                vetlista[i] = *p_lista;
                i++;
                printf("O indice do conjunto interseccao e %d\n", i);            
            }
            if(m==14){
                printf("Entre com o numero (indice) do primeiro conjunto: ");
                scanf("%d", &j);
                printf("Entre com o numero (indice) do segundo conjunto: ");
                scanf("%d", &k);
                p_lista = diferenca(&vetlista[j-1], &vetlista[k-1]);
                vetlista[i] = *p_lista;
                i++;
                printf("O indice do conjunto diferenca e %d\n", i);            
            }
            if(m==15){
                printf("Entre com o numero (indice) do conjunto: ");
                scanf("%d", &j);
                geraConjunto(vetlista[j-1].inicio, vetpartes);                        
            }                  
            if(m==16){
                printf("Entre com o numero (indice) do conjunto: ");
                scanf("%d", &j);
                printf("Digite 1 para mostrar os elementos em ordem crescente ou 0 para ordem decrescente: ");
                scanf("%d", &num);
                mostraConjunto(&vetlista[j-1], num);                
            }
            if(m==17){
                printf("Entre com o numero (indice) do primeiro conjunto: ");
                scanf("%d", &j);
                printf("Entre com o numero (indice) do segundo conjunto: ");
                scanf("%d", &k);
                if(copiarConjunto(&vetlista[j-1], &vetlista[k-1])){
                    printf("O conjunto foi copiado com sucesso!\n");
                }
                else{
                    printf("Erro: o conjunto nao pode ser copiado\n");
                }            
            }
            if(m==18){
                printf("Entre com o numero (indice) do conjunto: ");
                scanf("%d", &j);
                if(destroiConjunto(&vetlista[j-1])){
                    printf("O conjunto foi destruido com sucesso!\n");
                }
                else{
                    printf("Nao foi possivel destruir o conjunto\n");
                }            
            }
        }
     
        return 0;
    }
