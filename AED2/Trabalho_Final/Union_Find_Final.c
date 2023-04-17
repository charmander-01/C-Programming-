/**
 * @file main.c
 * @author Laura Martins, Luis Miguel, Wevton Junior
 * @brief Programa principal para a execucao do algoritmo de Union & Find
 * @date 12/02/2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct SET set;
typedef struct DESCRITOR descritor;
     
struct SET{
    double elemento;
    set *proximo;
};
     
struct DESCRITOR{
    set *inicio;
    double rep;
}Desc[100];

int contador = 0;           
// contar a qtd de conjuntos.
int num_conjunto = -1;      
// Lembrete que deveremos associar a cada conjunto um numero especifico (indice).
// Tal indice podera ser alterado apos uma destruicao ou uniao.

// Funções acessórias:

/**
 * @brief Menu principal.
 * 
 */
void menu();

/**
 * @brief Função acessória de criação de uma lista linear simplesmente encadeada
 * 
 * @param d Vetor de nó descritor
 * @param num Índice do vetor de struct Desc
 * @return true or false 
 */
bool Cria_Lista(descritor d[], int num);

/**
 * @brief Função acessória que verifica se a lista (conjunto) está vazia ou não
 * 
 * @param d Vetor de nó descritor
 * @param num Índice do vetor de struct Desc
 * @return true (Lista Vazia) or false (caso contrário)
 */
bool Lista_Vazia(descritor d[], int num);

/**
 * @brief Função acessória que insere o primeiro elemento em uma lista (conjunto)
 * 
 * @param x Valor do elemento que será inserido 
 * @param d Vetor de nó descritor
 * @param num Índice do vetor de struct Desc
 * @return true or false
 */
bool Insere_Lista(double x, descritor d[], int num);

/**
 * @brief Função acessória que imprime os elementos da lista (conjunto)
 * 
 * @param d Vetor de nó descritor
 * @param num Índice do vetor de struct Desc
 */
void Imprime_Lista(descritor d[], int num);

/**
 * @brief Função acessória que diz se determinado elemento pertence à lista(conjunto) ou não
 * 
 * @param x Elemento
 * @param d Vetor de nó descritor
 * @param num Índice do vetor de struct Desc
 * @return true or false
 */
bool Esta_Na_Lista(double x, descritor d[], int num);

/**
 * @brief Função acessória que retorna a cardinalidade do conjunto
 * 
 * @param d Vetor de nó descritor
 * @param num Índice do vetor de struct Desc
 * @return true or false
 */
bool Imprime_Cardinalidade(descritor d[], int num);

/**
 * @brief Função acessória que exclui o último elemento de uma lista
 * 
 * @param d Vetor de nó descritor
 * @param num Índice do vetor de struct Desc
 * @return true or false
 */
bool ExcluiUltimoElemento(descritor d[], int num);

/**
 * @brief  Função acessória que liga as listas cujos índices são x e y.
 * 
 * @param x Índice 
 * @param y Índice
 * @return true 
 * @return false 
 */
bool LigaConjuntos(int x, int y);

/**
 * @brief Funcao acessória pra trocar dois conjuntos de lugar.
*/
void swap(descritor d1[], descritor d2[]);

// ***************************************************************

/**
 * @brief Função que cria um conjunto contendo o elemento x
 * 
 * @param x Elemento 
 * @return true or false
 */
bool Make_Set(double x);

/**
 * @brief Função que imprime os elementos do conjunto ao qual x pertence
 * 
 * @param x Elemento
 * @return true or false
 */
bool Show_Set(double x);

/**
 * @brief Função que imprime os elementos do conjunto de índice x
 * 
 * @param x Índice do conjunto
 * @return true or false
 */
void Show_SetI(int x);

/**
 * @brief Função que retorna o representante do conjunto ao qual x pertence
 * 
 * @param x Elemento 
 * @return double 
 */
double Find_Set(double x);

/**
 * @brief Função que retorna a cardinalidade do conjunto ao qual x pertence
 * 
 * @param x Elemento
 * @return true or false
 */
bool Size_Set(double x);

/**
 * @brief Função que retorna a cardinalidade do conjunto de índice x
 * 
 * @param x Índice
 * @return true or false
 */
void Size_SetI(int x);

/**
 * @brief Função que destroí o conjunto ao qual o elemento x pertence
 * 
 * @param x Elemento
 * @return true or false
 */
bool Destroy_Set(double x);

/**
 * @brief Função que destrói o conjunto de índice x
 * 
 * @param x Índice
 * @return true or false
 */
bool Destroy_SetI(int x);

/**
 * @brief Função que une os conjuntos dos elementos x e y. O índice do conjunto união é o menor dos índices. Se os dois elementos estão no mesmo conjunto, nada é feito.
 * 
 * @param x Elemento
 * @param y Elemento
 * @return true or false
 */
bool Union(double x, double y);

int main()
{
    double num, num2;
    int controle = 1, loop;
    int i;

    menu();

    
    while(controle!=0)
    {
        printf("Entre com o numero da operação desejada. (11 para abrir o Menu de operações)\n-> ");
        scanf("%d", &controle);

        if(controle==1)
        {
            if(contador < 100){
                printf("Escolha quantos conjuntos deseja criar (máximo de %d): ", 100-contador);
                scanf("%d", &loop);
                printf("Insira, em uma linha, os conjuntos a serem criados.\n-> ");
                for(i = 0; i < loop; i++){
                    scanf("%lf", &num);
                    Make_Set(num);
                }
            }
            else{
                printf("Numero maximo de conjuntos atingido. Falha na operação!\n");
            }
        }

        if(controle==2)
        {
            if(contador > 0){
                printf("Insira um número flutuante para a impressão do conjunto.\n-> ");
                scanf("%lf", &num);
                Show_Set(num);
            }
            else{
                printf("Não há conjuntos para operar. Crie um conjunto primeiro.\n");
            }
        }

        if(controle==3)
        {
            if(contador > 0){
                printf("Insira o índice do conjunto a ser impresso.\n-> ");
                scanf("%lf", &num);
                Show_SetI(num);            
            }
            else{
                printf("Não há um conjunto para operar. Crie um conjunto primeiro.\n");
            }
        }

        if(controle==4)
        {
            if(contador > 0){
                printf("Insira o número flutuante do conjunto a ser destruído.\n-> ");
                scanf("%lf", &num);
                Destroy_Set(num);
            }
            else{
                printf("Não há um conjunto para operar. Crie um conjunto primeiro.\n");
            }
        }

        if(controle==5)
        {
            if(contador > 0){
                scanf("%lf", &num);
                if(Destroy_SetI(num)){
                    printf("O conjunto foi destruido com sucesso.\n");
                    printf("O conjunto de índice %d passa agora a ter o índice %.0lf!\n", contador, num);
                }
            }
            else{
                printf("Não há um conjunto para operar. Crie um conjunto primeiro.\n");
            }
        }

        if(controle==6)
        {
            if(contador > 0){
                printf("Insira os dois valores flutuantes para a união dos dois conjuntos, com um espaço entre eles.\n-> ");
                scanf("%lf %lf", &num, &num2);
                Union(num, num2);
            }
            else{
                printf("Não há um conjunto para operar. Crie um conjunto primeiro.\n");
            }

        }

        if(controle==7)
        {
            if(contador > 0){
                printf("Insira o valor a ser procurado.\n-> ");
                scanf("%lf", &num);
                printf("O representante do conjunto e %lf\n", Find_Set(num));
            }
            else{
                printf("Não há um conjunto para operar. Crie um conjunto primeiro.\n");
            }
        }

        if(controle==8)
        {
            if(contador > 0){
                printf("Insira o valor flutuante.\n-> ");
                scanf("%lf", &num);
                Size_Set(num);
            }
            else{
                printf("Não há um conjunto para operar. Crie um conjunto primeiro.\n");
            }
        }

        if(controle==9)
        {
            if(contador > 0){
                printf("Insira o índice do conjunto. (Valores entre 0 e %d).\n-> ", contador);
                scanf("%lf", &num);
                Size_SetI(num);
            }
        }
        
        if(controle == 10){
            if(contador > 0){
                printf("Insira os valores flutuantes dos dois elementos a serem verificados.\n-> ");
                scanf("%lf %lf", &num, &num2);
                if(Find_Set(num) == Find_Set(num2)){
                    printf("Os elementos pertencem ao mesmo conjunto!\n");
                }
                else{
                    printf("Os elementos não pertencem ao mesmo conjunto!\n");
                }
            }
        }

        if(controle == 11){
            menu();
        }
    }

    printf("Limpando conjuntos para finalizar operação...\n");
    for(i = 0; i < 100; i++){
        while(!Lista_Vazia(Desc, i)){
            ExcluiUltimoElemento(Desc, i);
        }
    }

    printf("Conjuntos excluídos com sucesso! Programa encerrado com sucesso!\n");

    return 0;
}

void menu()
{
    printf("************************************\n");
    printf("Union Find (menu do sistema)\n");
    printf("Operações:\n");
    printf("1 - Criar conjunto;\n");
    printf("2 - Mostrar conjunto por elemento;\n");
    printf("3 - Mostrar conjunto por índice;\n");
    printf("4 - Destruir conjunto por elemento;\n");
    printf("5 - Destruir conjunto por índice;\n");
    printf("6 - Unir dois conjuntos;\n");
    printf("7 - Procurar o representante do elemento indicado;\n");
    printf("8 - Tamanho do conjunto do elemento indicado;\n");
    printf("9 - Tamanho do conjunto do índice indicado;\n");
    printf("10 - Verificar se dois elementos estão no mesmo conjunto;\n");
    printf("11 - Abrir o menu de operações;\n");
    printf("0 - encerrar o programa.\n");
    printf("************************************\n");
}

bool Cria_Lista(descritor d[], int num)
{
    d[num].inicio = NULL;
    return true;
}

bool Lista_Vazia(descritor d[], int num){
    if(d[num].inicio == NULL){
        return true;
    }
    else{
        return false;
    }
}

bool Insere_Lista(double x, descritor d[], int num)   // Insere no inicio da lista.
{
    set *novo;

    novo = (set*) malloc(sizeof(set));

    if(novo==NULL)
    {
        printf("Falha ao tentar alocar memoria - programa encerrado\n");
        return false;
    }

    novo->elemento = x;
    novo->proximo = NULL;
 
    if(Lista_Vazia(d, num)){
        d[num].inicio = novo;
        d[num].rep = novo->elemento;
        return true;
    }
    else{
        set *s;
        s = d[num].inicio;
        novo->proximo = s;
        d[num].inicio = novo;
        return true;
    }
}

bool Make_Set(double x)
{
    if(contador<100)
    {
        if(Find_Set(x)!=0)
        {
            printf("Elemento já existente em um conjunto. Falha na operacao!\n");
            return false;
        }
        else
        {
            Cria_Lista(Desc, contador);
            Insere_Lista(x, Desc, contador);
            printf("O conjunto de indice %d foi criado!\n", contador);
            contador++;
            return true;
        }
    }
    else
    {
        printf("Numero limite de conjuntos atingido. Falha na operacao!\n");
        return false;
    }
}

void Imprime_Lista(descritor d[], int num)
{
    set *s;

    s = d[num].inicio;

    printf("Imprimindo o conjunto de n° %d:\n-> {", num);
    while(s!=NULL)
    {
        printf("%lf", s->elemento);
        if(s->proximo != NULL){
            printf(", ");
        }
        s = s->proximo;
    }

    printf("}\n");
}

bool Show_Set(double x)
{
    int i;
    bool esta;

    for(i=0;i<=contador;i++)
    {
        esta = Esta_Na_Lista(x, Desc, i);
        if(esta==true)
        {
            Imprime_Lista(Desc, i);
            return true;
        }
    }
    printf("O elemento nao pertence a nenhum conjunto.\n");
    return false;
}

bool Esta_Na_Lista(double x, descritor d[], int num)
{
    set *s;
    s = d[num].inicio;
    while(s!=NULL)
    {
        if(s->elemento==x) return true;
        s = s->proximo;
    }
    return false;
}

void Show_SetI(int x)
{
    if(Lista_Vazia(Desc, x))
    {
        printf("O conjunto de indice %d nao existe.\n", x);
    }
    else
    {
        Imprime_Lista(Desc, x);
    }    
}

bool Size_Set(double x)
{
    int i;
    bool esta;

    for(i=0;i<=contador;i++)
    {
        esta = Esta_Na_Lista(x, Desc, i);
        if(esta==true)
        {
            Imprime_Cardinalidade(Desc, i);
            return true;
        }
    }
    printf("O elemento nao pertence a nenhum conjunto.\n");
    return false;    
}

bool Imprime_Cardinalidade(descritor d[], int num)
{
    set *s;
    s = d[num].inicio;
    int size = 0;

    while(s!=NULL)
    {
        size++;
        s = s->proximo;
    }

    printf("A cardinalidade do conjunto e: %d\n", size);
    return true;    
}

void Size_SetI(int x)
{
    if(Lista_Vazia(Desc, x))
    {
        printf("O conjunto de indice %d nao existe.\n", x);
    }
    else
    {
        Imprime_Cardinalidade(Desc, x);
    }    
}

double Find_Set(double x){
    int i;
    bool esta = false;

    for(i = 0; i <= contador; i++){
        esta = Esta_Na_Lista(x, Desc, i);
        if(esta==true)
        {
            return Desc[i].rep;
        }
    }

    return 0;
}

bool ExcluiUltimoElemento(descritor d[], int num)
{
    if(Lista_Vazia(d, num))
    {
        return false;
    }

    set *aux;
    set *percorre;
    percorre = d[num].inicio;

    if(percorre->proximo==NULL)
    {
        free(percorre);
        d[num].inicio = NULL;
        return true;
    }

    while(percorre->proximo!=NULL)
    {
        aux = percorre;
        percorre = percorre->proximo;
    }

    free(percorre);
    aux->proximo = NULL;
    return true;
}

bool Destroy_Set(double x)
{
    int i;
    bool esta = false;
    for(i=0;i<=contador;i++){
        esta = Esta_Na_Lista(x, Desc, i);
        if(esta==true){
            swap(&Desc[i], &Desc[contador-1]);
            while(!Lista_Vazia(Desc, contador-1)){
                ExcluiUltimoElemento(Desc, contador-1);
            }
            printf("O conjunto foi destruido com sucesso.\n");
            printf("O conjunto de índice %d passa agora a ter o índice %d!\n", contador-1, i);
            contador--;
            return true;
        }
    }
    printf("O elemento nao pertence a nenhum conjunto.\n");
    printf("Operacao concluida.\n");
    return false;
}

bool Destroy_SetI(int x)
{
    if(Lista_Vazia(Desc, x)==true)
    {
        printf("Conjunto inexistente.\n");
        printf("Operacao concluida.\n");
        return false;
    }

    swap(&Desc[x], &Desc[contador-1]);
    while(Lista_Vazia(Desc, contador-1)==false)
    {
        ExcluiUltimoElemento(Desc, contador-1);
    }

    contador--;
    return true;
}

bool Union(double x, double y)
{
    int i;
    double rep1, rep2;
    int ind1, ind2;
    int indmenor, indmaior;

    rep1 = Find_Set(x);
    rep2 = Find_Set(y);

    for(i=0;i<=contador;i++)
    {
        if(rep1==Desc[i].rep) ind1 = i;
        if(rep2==Desc[i].rep) ind2 = i;
    }

    if(ind1<ind2)
    {
        indmenor = ind1;
        indmaior = ind2;
    }
    if(ind2<ind1)
    {
        indmenor = ind2;
        indmaior = ind1;
    }

    if(ind1==ind2)
    {
        printf("Os dois elementos pertencem ao mesmo conjunto.\n");
        printf("Operacao concluida.\n");
        return true;
    }

    LigaConjuntos(indmenor, indmaior);

    Destroy_SetI(indmaior);

    printf("Os conjuntos foram unidos. O novo indice do conjunto uniao é: %d.\n", indmenor);
    return true;
}

bool LigaConjuntos(int x, int y)
{
    set *percorre;
    percorre = Desc[x].inicio;

    while(percorre->proximo!=NULL)
    {
        percorre = percorre->proximo;
    }

    set *novo;

    novo = (set*)malloc(sizeof(set));

    if(novo==NULL)
    {
        printf("Falha ao tentar alocar memoria - programa encerrado\n");
        return false;        
    }

    novo->elemento = Desc[y].inicio->elemento;

    percorre->proximo = novo;
    
    return true;
}

void swap(descritor d1[], descritor d2[]){
    descritor temp;
    temp = *d1;
    *d1 = *d2;
    *d2 = temp;
}
