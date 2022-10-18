    #include <stdio.h>
    #include <stdbool.h>
     
    #define MAX 250
     
    bool Maior(int a, int b);
    void SelectionSort(int sequencia[], int tam);
     
    int vet_ouro[MAX];
    int vet_prata[MAX];
    int vet_bronze[MAX];
     
    int main()
    {
        int i;
        int num_paises, modalidades;
        int ouro, prata, bronze;
        int paises[MAX];
     
        scanf("%d %d", &num_paises, &modalidades);
     
        for(i=0;i<modalidades;i++)
        {
            scanf("%d %d %d", &ouro, &prata, &bronze);
            vet_ouro[ouro]++;
            vet_prata[prata]++;
            vet_bronze[bronze]++;
        }
     
        for(i=1;i<=num_paises;i++)
        {
            paises[i-1] = i;
        }
     
        SelectionSort(paises, num_paises);
     
        for(i=0;i<num_paises;i++)
        {
            printf("%d ", paises[i]);
        }
     
        printf("\n");
     
        return 0;
    }
     
    bool Maior(int a, int b)
    {
        if(vet_ouro[a]>vet_ouro[b]) return true;
        if(vet_ouro[a]<vet_ouro[b]) return false;
        if(vet_ouro[a]==vet_ouro[b])
        {
            if(vet_prata[a]>vet_prata[b]) return true;
            if(vet_prata[a]<vet_prata[b]) return false;
            if(vet_prata[a]==vet_prata[b])
            {
                if(vet_bronze[a]>vet_bronze[b]) return true;
                if(vet_bronze[a]<vet_bronze[b]) return false;
                if(vet_bronze[a]==vet_bronze[b])
                {
                    if(a>b) return true;
                    if(a<b) return false;
                }            
            }
        }
    }
     
    void SelectionSort(int sequencia[], int tam)
    {
        int i, j;
        int maior, ind_maior;
        int temp;
     
        for(i=0;i<tam-1;i++)
        {
            maior = sequencia[i];
            ind_maior = i;
            for(j=i+1;j<tam;j++)
            {
                if(Maior(sequencia[j], maior))
                {
                    maior = sequencia[j];
                    ind_maior = j;
                }
            }
            if(sequencia[i]!=maior)
            {
                temp = sequencia[i];
                sequencia[i] = maior;
                sequencia[ind_maior] = temp;
            }
        }
    }
