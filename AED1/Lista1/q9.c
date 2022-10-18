    #include <stdio.h>
     
    int main(){
     
        int N;
        int i, soma=0;
     
        //Entre com o número inteiro positivo que deve ser testado:
        scanf("%d", &N);
        if(N<=0){
            printf("O numero inteiro informado deve ser maior do que zero\n");
            return 0;
        }
     
        for(i=1;i<N;i++){
            if(N%i==0){
                soma+=i;
            }
        }
        if(soma==N){
            printf("Numero %d: perfeito\n", N);
        }
        else{
            printf("Numero %d: não perfeito\n", N);
        }
     
        return 0;
    }
