    #include <stdio.h>
     
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
