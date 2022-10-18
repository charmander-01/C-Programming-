    #include <stdio.h>
     
    #define MAX 1050
     
    void SelectionSort(int sequencia[], int tam);
     
    int main()
    {
        int i;
        int num_elem;
        int num;
        int I, K;
     
        int vet[MAX];
     
        scanf("%d", &num_elem);
     
        for(i=0;i<num_elem;i++)
        {
            scanf("%d", &num);
            vet[i] = num;
        }
     
        scanf("%d %d", &I, &K);
     
        SelectionSort(vet, num_elem);
          
        printf("%d\n", vet[I-1]+vet[K-1]);
     
        return 0;
    }
     
    void SelectionSort(int sequencia[], int tam)
    {
        int i, j;
        int menor, ind_menor;
        int temp;
     
        for(i=0;i<tam-1;i++)
        {
            menor = sequencia[i];
            ind_menor = i;
            for(j=i+1;j<tam;j++)
            {
                if(sequencia[j]<menor)
                {
                    menor = sequencia[j];
                    ind_menor = j;
                }
            }
            temp = sequencia[i];
            sequencia[i] = menor;
            sequencia[ind_menor] = temp; 
        }
    }
