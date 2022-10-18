    #include <stdio.h>
     
    int fib(int a);
     
    int main(){
     
        int n;
        int num;
        int i;
     
        scanf("%d", &n);
     
        for(i=0;i<=n;i++){
            num = fib(i);
            printf("%d ", num);
        }
     
        printf("\n");
     
        return 0;
    }
     
    int fib(int a){
        int soma;
     
        if(a==0) return a;
        if(a==1) return a;
        if(a>1){
            soma = fib(a-2) + fib(a-1);
            return soma;    
        }
    }
