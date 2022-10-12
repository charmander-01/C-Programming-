// Exercício de Algoritmo e Estrutura de Dados
// Implementação de um modelo de agenda telefônica usando o conceito de lista simplesmente encadeada

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
 
int main()
{
    lista *agenda = (lista *)malloc(sizeof(lista));
    char caractere;
    char nome[20];
    char numero[10];
    int qtd_ligacoes;
 
    CriaLista(agenda);
 
    while (1)
    {
        scanf("%c", &caractere);
        if (caractere == 'F')
        {
            break;
        }
 
        if (caractere == 'I')
        {
            scanf("%s", nome);
            scanf("%s", numero);
            scanf("%d", &qtd_ligacoes);
            InsereElemento(agenda, nome, numero, qtd_ligacoes);
            agenda = OrdenaLista(agenda);
        }
        if (caractere == 'L')
        {
            scanf("%s", nome);
            RegistraLigacao(agenda, nome);
            agenda = OrdenaLista(agenda);
        }
        if (caractere == 'R')
        {
            scanf("%s", nome);
            RemoveElemento(agenda, nome);
            agenda = OrdenaLista(agenda);
        }
    }
 
    ImprimeLista(agenda);
    ExcluiLista(agenda);
 
    return 0;
}
 
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
 
        if (strcmp(percorre->nome_struct, menor_nome) == 0)
        {
            InsereElemento(clone, percorre->nome_struct, percorre->num_struct, percorre->liga_struct);
            RemoveElemento(sequencia, percorre->nome_struct);
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
