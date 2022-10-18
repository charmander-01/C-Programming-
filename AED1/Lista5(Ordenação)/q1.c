    #include <stdio.h>
     
    void OrdenaCrescente(int sequencia[], int tamanho);
    void OrdenaDecrescente(int sequencia[], int tamanho);
    void ImprimeVetor(int sequencia[], int tamanho);
     
    #define MAX 105
     
    int main()
    {
        int i, num;
        int par = 0, impar = 0;
        int vet_impar[MAX];
        int vet_par[MAX];
        int num_elementos;
     
        scanf("%d", &num_elementos);
     
        for(i=0;i<num_elementos;i++)
        {
            scanf("%d", &num);
            if(num%2==0)
            {
                vet_par[par] = num;
                par++;
            }
            else
            {
                vet_impar[impar] = num;
                // printf("impar: %d\n", num);
                impar++;
            }
        }
     
        OrdenaCrescente(vet_par, par);
        OrdenaDecrescente(vet_impar, impar);
     
        return 0;
    }
     
    void OrdenaCrescente(int sequencia[], int tamanho)
    {
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
            temp = sequencia[i];
            sequencia[i] = menor;
            sequencia[ind_menor] = temp;
        }
     
        ImprimeVetor(sequencia, tamanho);
    }
     
    void OrdenaDecrescente(int sequencia[], int tamanho)
    {
        int i, j;
        int maior, ind_maior;
        int temp;
     
        for(i=0;i<tamanho-1;i++)
        {
            maior = sequencia[i];
            ind_maior = i;
            for(j=i+1;j<tamanho;j++)
            {
                if(sequencia[j]>maior)
                {
                    maior = sequencia[j];
                    ind_maior = j;
                }
            }
            temp = sequencia[i];
            sequencia[i] = maior;
            sequencia[ind_maior] = temp;
        }
     
        ImprimeVetor(sequencia, tamanho);
    }
     
    void ImprimeVetor(int sequencia[], int tamanho)
    {
        int i;
        for(i=0;i<tamanho;i++)
        {
            printf("%d ", sequencia[i]);
        }
        printf("\n");
    }
