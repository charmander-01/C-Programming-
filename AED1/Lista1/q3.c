    #include <stdio.h>
     
    int main(){
     
        int n, soma = 0;
        int primos_somados = 0;
        int i = 1, j, divisores=0;
     
        //Entre com o valor de n:
        scanf("%d", &n);
     
        if(n<=0 || n>1000){
            printf("O valor de n deve ser inteiro maior do que 0 e menor do que 1000 – programa cancelado\n");
            return 0;
        }
     
        while(primos_somados!=n){
            for(j=i;j>=1;j--){
                if(i%j==0) divisores++;
            }
            if(divisores==2) {
                soma+=i;
                primos_somados++;
            }
            divisores=0;
            i++; 
        }
     
        printf("Soma dos %d primeiros numeros primos: %d\n", n, soma);
     
        return 0;
    }
