    #include <stdio.h>
     
    #define CARBONO 7
    #define DUREZA 50
    #define RESISTENCIA 80000
     
    int main(){
        
        double conteudo_carbono;
        int var_dureza;
        int resist_tracao;
     
        // Entre com o percentual de conteudo do carbono do lote produzido (entre 0 e 30):
        scanf("%lf", &conteudo_carbono);
     
        if(conteudo_carbono<0 || conteudo_carbono>=50){
            printf("O percentual de conteudo de carbono deve estar entre 0 e 30 - programa cancelado\n");
            return 0;
        }
     
        // Entre com a escala de dureza Rockwell do lote produzido (entre 0 e 100):
        scanf("%d", &var_dureza);
     
        if(var_dureza<0 || var_dureza>=100){
            printf("A escala de dureza Rockwell deve estar entre 0 e 100 - programa cancelado\n");
            return 0;
        }
     
        // Entre com a resistencia a tracao do lote produzido (entre 0 e 100000):
        scanf("%d", &resist_tracao);
     
        if(resist_tracao<=0 || resist_tracao>=100000){
            printf("A resistência a tração deve estar entre 0 e 100000 - programa cancelado\n");
            return 0;
        }
     
        if(conteudo_carbono<CARBONO && var_dureza>DUREZA && resist_tracao>RESISTENCIA){
            printf("Grau de pureza do lote produzido: 10\n");
            return 0;
        }
        if(conteudo_carbono<CARBONO && var_dureza>DUREZA && resist_tracao<=RESISTENCIA){
            printf("Grau de pureza do lote produzido: 9\n");
            return 0;
        }
        if(conteudo_carbono<CARBONO && var_dureza<=DUREZA && resist_tracao<=RESISTENCIA){
            printf("Grau de pureza do lote produzido: 8\n");
            return 0;
        }
        if(conteudo_carbono>=CARBONO && var_dureza<=DUREZA && resist_tracao<=RESISTENCIA){
            printf("Grau de pureza do lote produzido: 7\n");
            return 0;
        }
     
        return 0;
    }
