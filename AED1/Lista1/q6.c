    #include <stdio.h>
     
    #define RESIDENCIAL 1
    #define COMERCIAL 2
    #define INDUSTRIAL 3
     
    int main(){
     
        unsigned long int conta;
        int tipo;
        double consumo;
        double custo;
        
        // Entre com o numero da conta do consumidor:
        scanf("%lu", &conta);
     
        if(conta<1 || conta>=100000000){
            printf("O numero da conta deve estar entre 1 e 999999999 - programa cancelado\n");
            return 0;
        }
     
        // Entre com o tipo do consumidor (1=residencial; 2=comercial; 3=industrial):
        scanf("%d", &tipo);
     
        if(tipo!=1 && tipo!=2 && tipo!=3){
            printf("O tipo de consumidor deve ser 1 ou 2 ou 3 - programa cancelado\n");
            return 0;
        }
     
        // Entre com o consumo medido em metros cubicos:
        scanf("%lf", &consumo);
     
        if(consumo<0){
            printf("O consumo deve ser maior ou igual a zero - programa cancelado\n");
            return 0;
        }
     
     
        if(tipo==RESIDENCIAL){
            custo = 5 + 0.05*consumo;
        }
        if(tipo==COMERCIAL){
            if(consumo>=80)
                custo = 500 + (consumo-80)*0.03;
            else
                custo = 500;
        }
        if(tipo==INDUSTRIAL){
            if(consumo>=100)
                custo = 800 + (consumo-100)*0.04;
            else
                custo = 800;
        }
     
        printf("Valor a ser pago para a conta informada: R$ %.2lf\n", custo);
     
        return 0;
    }
