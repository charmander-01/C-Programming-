#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 
typedef struct NO no;
typedef struct LISTA lista;
 
struct NO
{
    char nome_struct[20];
    char num_struct[10];
    int liga_struct;
    no *proximo;
};
 
struct LISTA
{
    no *inicio;
};
 
bool CriaListaVazia(lista *clone);
bool CriaLista(lista *sequencia);
bool ListaVazia(lista *sequencia);
int TamanhoLista(lista *sequencia);
bool InsereElemento(lista *sequencia, char i_nome[], char i_numero[], int i_qtd_ligacoes);
char *NomeMaiorElemento(lista *sequencia);
lista *OrdenaLista(lista *sequencia);
void RegistraLigacao(lista *sequencia, char r_nome[]);
void RemoveElemento(lista *sequencia, char del_nome[]);
void ImprimeLista(lista *sequencia);
void ExcluiLista(lista *sequencia);
//  void inicia(lista *sequencia);
 
int main()
{
    lista *agenda = (lista *)malloc(sizeof(lista));
 
 
    char caractere;
    char nome[20];
    char numero[10];
    int qtd_ligacoes;
 
    // printf("*********\n");
    CriaLista(agenda);
 
    while (1)
    {
        scanf("%c", &caractere);
        if (caractere == 'F')
        {
            // printf("*********\n");
            break;
        }
 
        if (caractere == 'I')
        {
            // printf("*********\n");
            scanf("%s", nome);
            scanf("%s", numero);
            scanf("%d", &qtd_ligacoes);
            InsereElemento(agenda, nome, numero, qtd_ligacoes);
            //ImprimeLista(agenda);
            agenda = OrdenaLista(agenda);
            // ImprimeLista(agenda);
            // printf("\n");
        }
        if (caractere == 'L')
        {
            // printf("*********\n");
            scanf("%s", nome);
            RegistraLigacao(agenda, nome);
            agenda = OrdenaLista(agenda);
            // ImprimeLista(agenda);
            // printf("\n");
        }
        if (caractere == 'R')
        {
            // printf("*********\n");
            scanf("%s", nome);
            RemoveElemento(agenda, nome);
            agenda = OrdenaLista(agenda);
            // ImprimeLista(agenda);
            // printf("\n");
        }
        // printf("tamlist = %d\n", TamanhoLista(agenda));
    }
 
    // printf("%s\n", NomeMaiorElemento(&agenda));
    ImprimeLista(agenda);
    ExcluiLista(agenda);
 
    return 0;
}
 
// void inicia(lista *sequencia){
//     sequencia->inicio=NULL;
// }
bool CriaListaVazia(lista *clone)
{
    clone->inicio = NULL;
    return true;
}
 
bool CriaLista(lista *sequencia)
{
    no *hermanoteu;
    no *ooloneia;
 
    hermanoteu = (no *)malloc(sizeof(no));
 
    if (hermanoteu == NULL)
    {
        return false;
    }
    else
    {
        strcpy(hermanoteu->nome_struct, "Hermanoteu");
        strcpy(hermanoteu->num_struct, "4523-2248");
        hermanoteu->liga_struct = 300;
    }
 
    ooloneia = (no *)malloc(sizeof(no));
 
    if (ooloneia == NULL)
    {
        return false;
    }
    else
    {
        strcpy(ooloneia->nome_struct, "Ooloneia");
        strcpy(ooloneia->num_struct, "4523-4887");
        ooloneia->liga_struct = 299;
    }
 
    sequencia->inicio = hermanoteu;
    hermanoteu->proximo = ooloneia;
    ooloneia->proximo = NULL;
 
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
    no *percorre;
    percorre = sequencia->inicio;
    if (ListaVazia(sequencia))
    {
        return cont;
    }
    while (percorre != NULL)
    {
        cont++;
        percorre = percorre->proximo;
    }
    return cont;
}
 
bool InsereElemento(lista *sequencia, char i_nome[], char i_numero[], int i_qtd_ligacoes)
{
    no *percorre;
    no *elemento;
 
    percorre = sequencia->inicio;
    elemento = (no *)malloc(sizeof(no));
 
    if (elemento == NULL)
    {
        return false;
    }
    else
    {
        strcpy(elemento->nome_struct, i_nome);
        strcpy(elemento->num_struct, i_numero);
        elemento->liga_struct = i_qtd_ligacoes;
 
        if (ListaVazia(sequencia))
        {
            sequencia->inicio = elemento;
            elemento->proximo = NULL;
        }
        else
        {
            while (percorre->proximo != NULL)
            {
                percorre = percorre->proximo;
            }
            percorre->proximo = elemento;
            elemento->proximo = NULL;
            return true;
        }
    }
}
 
char *NomeMaiorElemento(lista *sequencia)
{
    no *menor;
    no *percorre;
    percorre = sequencia->inicio;
    menor = sequencia->inicio;
    while (percorre != NULL)
    {
        // printf("%d %d\n", percorre->liga_struct, menor->liga_struct);
        if (percorre->liga_struct > menor->liga_struct)
        {
            menor = percorre;
        }
        percorre = percorre->proximo;
    }
    return menor->nome_struct;
}
 
lista *OrdenaLista(lista *sequencia)
{
    char menor_nome[20];
    no *percorre;
 
    lista *clone = (lista *)malloc(sizeof(lista));
    CriaListaVazia(clone);
 
    while (1)
    {
        if (TamanhoLista(sequencia) == 0)
        {
            break;
        }
 
        percorre = sequencia->inicio;
        strcpy(menor_nome, NomeMaiorElemento(sequencia));
        // printf("menor eh %s\n", menor_nome);
 
        if (strcmp(percorre->nome_struct, menor_nome) == 0)
        {
            // printf("estou aqui\n");
            InsereElemento(clone, percorre->nome_struct, percorre->num_struct, percorre->liga_struct);
            RemoveElemento(sequencia, percorre->nome_struct);
            // printf("removi e agora tamlist=%d\n", TamanhoLista(sequencia));
        }
        else
        {
            percorre = percorre->proximo;
            while (strcmp(percorre->nome_struct, menor_nome) != 0)
            {
                percorre = percorre->proximo;
            }
            InsereElemento(clone, percorre->nome_struct, percorre->num_struct, percorre->liga_struct);
            RemoveElemento(sequencia, percorre->nome_struct);
            // printf("removi e agora tamlist=%d\n", TamanhoLista(sequencia));
        }
    }
    return clone;
}
 
void RegistraLigacao(lista *sequencia, char r_nome[])
{
    no *percorre;
    percorre = sequencia->inicio;
 
    if (strcmp(percorre->nome_struct, r_nome) == 0)
    {
        percorre->liga_struct++;
        return;
    }
    else
    {
        while (percorre->proximo != NULL)
        {
            if (strcmp(percorre->nome_struct, r_nome) == 0)
            {
                break;
            }
            percorre = percorre->proximo;
        }
    }
 
    percorre->liga_struct++;
    return;
}
 
void RemoveElemento(lista *sequencia, char del_nome[])
{
    no *percorre;
    no *aux;
 
    percorre = sequencia->inicio;
 
    if (strcmp(percorre->nome_struct, del_nome) == 0)
    {
        sequencia->inicio = percorre->proximo;
        free(percorre);
        return;
    }
 
    while (strcmp(percorre->proximo->nome_struct, del_nome) != 0)
    {
        percorre = percorre->proximo;
    }
    aux = percorre->proximo;
    percorre->proximo = percorre->proximo->proximo;
    free(aux);
    return;
}
 
void ImprimeLista(lista *sequencia)
{
    no *percorre;
    percorre = sequencia->inicio;
    while (percorre != NULL)
    {
        printf("%s", percorre->nome_struct);
        printf(" - ");
        printf("%s ", percorre->num_struct);
        printf("%d", percorre->liga_struct);
        printf("\n");
        percorre = percorre->proximo;
    }
    return;
}
 
void ExcluiLista(lista *sequencia)
{
    no *percorre;
    no *aux;
 
    while(1)
    {
        percorre = sequencia->inicio;
        if(TamanhoLista(sequencia)==0)
        {
            break;
        }
        while(percorre->proximo!=NULL)
        {
            aux = percorre;
            percorre = percorre->proximo;
        }
        RemoveElemento(sequencia, percorre->nome_struct);
    }
}
 
// lista* OrdenaLista(lista *sequencia)
// {
//     no *maior;
//     no *percorre;
//     no *aux;
 
//     while(sequencia->inicio!=NULL)
//     {
//         percorre = sequencia->inicio;
//         maior = sequencia->inicio;
 
//         while(percorre->proximo!=NULL)
//         {
//             aux = percorre;
//             percorre = percorre->proximo;
//             if(aux->liga_struct>percorre->liga_struct)
//             {
//                 maior = aux;
//             }
//         }
//         if(maior==sequencia->inicio)
//         {
//             sequencia->inicio = maior->proximo;
//             InsereElemento(copia, maior->nome_struct, maior->num_struct, maior->liga_struct);
//             RemoveElemento(sequencia, maior->nome_struct);
//         }
//         else
//         {
//             InsereElemento(copia, maior->nome_struct, maior->num_struct, maior->liga_struct);
//             aux = percorre->proximo;
//             RemoveElemento(sequencia, percorre->nome_struct);
//         }
//     }
//     return copia;
// }