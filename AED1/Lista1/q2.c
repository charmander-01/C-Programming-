    #include <stdio.h>
     
    int main(){
     
        /* Raciocínio:
            Funcionamento: 8 horas por dia todos os dias; 
            Segunda a sexta: 
                mín -> 4 unidades por hora
                máx -> 5 unidades por hora
            Fim de semana:
                3 unidades por hora
     
            dias_letivos = num_semanas * 5
            finais_de_semana = num_semanas * 2;
            máx = 8 * 5 * dias_letivos + 3 * 8 * finais_de_semana
            mín = 8 * 4 * dias_letivos + 3 * 8 * finais_de_semana        
        */
     
        int num_semanas;
        int max, min;
        int dias_letivos;
        int finais_de_semana;
     
        //Entre com a quantidade de semanas de produção: 
        scanf("%d", &num_semanas);
     
        dias_letivos = num_semanas * 5;
        finais_de_semana = num_semanas * 2;    
     
        if(num_semanas<1){
            printf("A quantidade de semanas de producao deve ser maior ou igual a 1 – programa cancelado\n");
            return 0;
        }
     
        max = 8 * 5 * dias_letivos + 3 * 8 * finais_de_semana;
        min = 8 * 4 * dias_letivos + 3 * 8 * finais_de_semana;
     
        printf("A produção mínima sera de: %d unidades\n\n", min);
        printf("A produção máxima sera de: %d unidades\n", max);
     
        return 0;    
    }

×
