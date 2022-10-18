    #include <stdio.h>
     
    #define MAX 1050
     
    int InsertionSort(int sequencia[], int tamanho);
    int SelectionSort(int sequencia[], int tamanho);
     
    int main()
    {
        int a, b;
        int i;
        int num_elem;
        int num;    
        int vet[MAX];
        int clone[MAX];
     
        scanf("%d", &num_elem);
        for(i=0;i<num_elem;i++)
        {
            scanf("%d", &num);
            vet[i] = num;
        }
        for(i=0;i<num_elem;i++)
        {
            clone[i] = vet[i];
        }
     
        a = InsertionSort(vet, num_elem);
        b = SelectionSort(clone, num_elem);
     
        printf("%d\n", a-b);
     
        return 0; 
    }
     
    int InsertionSort(int sequencia[], int tamanho)
    {
        int cont = 0;
        int i, j, aux;
     
        i = 0; j = 1;
        aux = 0;
     
        while (j < tamanho) 
        {
            aux = sequencia[j];
            i = j - 1;
            while ((i >= 0) && (sequencia[i] > aux)) 
            {
                sequencia[i + 1] = sequencia[i];
                i--;
                cont++;
            }
            sequencia[i + 1] = aux;
            j++;
            cont++;
        }
        return cont;
    }
     
     
    int SelectionSort(int sequencia[], int tamanho)
    {
        int cont = 0;
        int i, j;
        int menor, ind_menor;
        int temp;
     
        for(i=0;i<tamanho-1;i++)
        {
            menor = sequencia[i];
            ind_menor = i;
            for(j=i+1;j<tamanho;j++)
            {
                if(sequencia[j]<menor)
                {
                    menor = sequencia[j];
                    ind_menor = j;
                }
            }
            if(sequencia[i]!=menor)
            {
                temp = sequencia[i];
                sequencia[i] = menor;
                sequencia[ind_menor] = temp;
                cont++;
            }
        }
     
        return cont;
    }
