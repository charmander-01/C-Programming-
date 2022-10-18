    #include <stdio.h>
     
    void bin (int number, int count, int vet[]);
     
    int main()
    {
        int N;
        int i, j=0;
        int num;
        int vetor[1000];
        
        scanf("%d", &N);
     
        for(i=0;i<N;i++){
            scanf("%d", &num);
            bin(num, j, vetor);
            printf("\n");
            j = 0;
        }
     
        return 0;
    }
     
    void bin(int number, int count, int vet[]){
        
        if(number/2==0){
            vet[count] = number%2;
            int k = 0;
            for(k=count;k>=0;k--){
                printf("%d",vet[k]);
            }
        }
        if(number/2!=0){
            vet[count] = number%2;
            //printf("number resto 2: %d\n", number%2);
            number = number/2;
            count++;
            bin(number, count, vet);
        }
    }
