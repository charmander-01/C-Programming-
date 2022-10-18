    //==============================================================================
    // Arquivo ponto.h
    //==============================================================================
     
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
     
    #define MENOR -1
    #define IGUAL 0
    #define MAIOR 1
     
    typedef struct data Data;
     
    // Imprime o menu de operacoes
    void menu();
     
    // Cria, de maneira dinamica, uma data a partir dos valores para dia, mes e ano fornecidos.
    Data * criaData (unsigned int dia, unsigned int mes, unsigned int ano);
     
    // Cria uma copia da data d, retornando-a.
    Data * copiaData (Data d);
     
    // void liberaData (Data * d);
    void liberaData (Data * d);
     
    // Retorna uma data que e dias dias posteriores a data d.
    // Por exemplo, fornecendo a data d = 16/03/2020 e dias = 5, retornara a data 21/03/2020.
    Data * somaDiasData (Data d, unsigned int dias);
     
     
    // Retorna uma data que e dias dias anteriores a data d.
    // Por exemplo, fornecendo a data d = 16/03/2020 e dias = 15, retornara a data 01/04/2020.
    Data * subtrairDiasData (Data d, unsigned int dias);
     
    // Atribui, a data d, a data dia/mes/ano especificada.
    //Se nao for possivel, entao faz com que d seja alterada para NULL.
    void atribuirData (Data * d, unsigned int dia, unsigned int mes, unsigned int ano);
     
    // Retorna a componente dia da data d.
    unsigned int obtemDiaData (Data d);
     
    // Retorna a componente mes da data d.
    unsigned int obtemMesData (Data d);
     
    // Retorna a componente ano da data d.
    unsigned int obtemAnoData (Data d);
     
    //Retorna MENOR se d1 < d2, retorna IGUAL se d1 = d2 ou retorna MAIOR, se d1 > d2.
    int comparaData (Data d1, Data d2);
     
    // Retorna TRUE se a data pertence a um ano bissexto. Do contrario, retorna FALSE.
    unsigned int bissextoData (Data d);
     
    // Retorna o numero de dias que existe entre as datas d1 e d2.
    //Se d1 = d2, entao o numero de dias e igual a 0 (zero). Do contrario, sera um numero estritamente
    //positivo.
    unsigned int numeroDiasDatas (Data d1, Data d2);
     
    //Se d1 e d2 estao no mesmo mes/ano, entao o numero de meses e igual a 0 (zero). Do contrario, sera
    //um numero estritamente positivo.
    unsigned int numeroMesesDatas (Data d1, Data d2);
     
    //Se d1 e d2 estao no mesmo ano, entao o numero de anos e igual a 0 (zero). Do contrario, sera um
    //numero estritamente positivo. 
    unsigned int numeroAnosDatas (Data d1, Data d2);
     
    // Retorna o dia da semana correspodente a data d.
    // Considerando que DOMINGO = 1; SEGUNDA-FEIRA = 2; ... ; SABADO = 7.
    unsigned int obtemDiaSemanaData (Data d);
     
    // Retorna uma string com a data "formatada" de acordo com o especificado em formato.
    char * imprimeData (Data d, char * formato);
     
    // Funcoes proprias:
     
    // Imprime uma data no formato dd/mm/aaaa
    void printa_data(Data d);
     
    // Retorna 1 caso o ano seja bissexto e 0 em caso contrario;
    bool e_bissexto(unsigned int ano_data);
     
    // Retorna o ultimo dia do mes em questao: 30 ou 31 e 28 ou 29(fevereiro);
    unsigned int ultimo_dia_do_mes(unsigned int mes_data, unsigned int ano_data);
     
    // Retorna true se as datas sao iguais ou false caso contrario;
    bool data_igual(Data d1, Data d2);
     
    // Retorna true se a primeira data for menor do que a segunda;
    bool data_menor(Data d1, Data d2);
     
    //==============================================================================
    // Arquivo ponto.c
    //==============================================================================
     
    struct data
    {
        unsigned int dia;
        unsigned int mes;
        unsigned int ano;
    };
     
    void menu()
    {
        printf("\n======================================================================\n");
        printf("Menu de opcoes\n");
        printf("======================================================================\n");
        printf("Digite o numero de acordo com a opcao desejada:\n");
        printf("(OBS.: Caso queira encerrar o programa, digite 0)\n");
        printf("01 - Cria uma data de maneira dinamica\n");
        printf("02 - Retorna uma copia da data informada\n");
        printf("03 - Deleta uma data e libera o espaco na memoria\n");
        printf("04 - Retorna uma data x dias posteriores a data d\n");
        printf("05 - Retorna uma data x dias anteriores a data d\n");
        printf("06 - Atribui data\n"); 
        printf("07 - Retorna o dia da data\n"); 
        printf("08 - Retorna o mes da data\n");
        printf("09 - Retorna o ano da data\n");
        printf("10 - Verifica se o ano da data e bissexto\n");
        printf("11 - Compara duas datas (igual, maior, menor)\n");
        printf("12 - Retorna o numero de meses entre duas datas\n");
        printf("13 - Retorna o numero de anos entre duas datas\n");
        printf("14 - Imprime a data no formato dd/mm/aaaa\n");
        printf("======================================================================\n");
    }
     
    Data * criaData (unsigned int dia, unsigned int mes, unsigned int ano)
    {
        Data * evento;
        evento = (Data*) malloc(sizeof(Data));
        if(evento!=NULL)
        {
            evento->dia = dia;
            evento->mes = mes;
            evento->ano = ano;
            printf("A data foi criada com sucesso!\n");
            return evento;        
        }
        else
        {
            printf("Nao foi possivel criar a data\n");
            exit(1);
        }
    }
     
    Data * copiaData (Data d)
    {
        Data * copia;
        copia = (Data*) malloc(sizeof(Data));
        if(copia!=NULL)
        {
            copia->dia = d.dia;
            copia->mes = d.mes;
            copia->ano = d.ano;
            return copia;
        }
        else
        {
            printf("Nao foi possivel copiar a data\n");
        }
    }
     
    void liberaData (Data * d)
    {
        if(d!=NULL)
        {
            d = NULL;
            printf("A data foi liberada com sucesso\n");
        }
        else
        {
            printf("A data ja havia sido liberada\n");
            return;
        }
    }
     
    Data * somaDiasData (Data d, unsigned int dias)
    {
        Data * data_resultante_soma;
        data_resultante_soma = (Data*) malloc(sizeof(Data));
     
        if(data_resultante_soma!=NULL)
        {
            data_resultante_soma->dia = d.dia;
            data_resultante_soma->mes = d.mes;
            data_resultante_soma->ano = d.ano;
     
            while(dias--)
            {
                if(data_resultante_soma->dia == ultimo_dia_do_mes (data_resultante_soma->mes, data_resultante_soma->ano) )
                {
                    data_resultante_soma->dia = 1;
                    if(data_resultante_soma->mes!=12)
                    {
                        data_resultante_soma->mes++;    
                    }
                    else
                    {
                        data_resultante_soma->mes = 1;
                        data_resultante_soma->ano++;
                    }
                }
                else
                {
                    data_resultante_soma->dia++;
                }
            }
     
            return data_resultante_soma;
        }
     
        else
        {
            printf("Erro: nao foi possivel realizar a operacao\n");
            return NULL;
        }
    }
     
    Data * subtrairDiasData (Data d, unsigned int dias)
    {
        Data * data_resultante_subt;
        data_resultante_subt = (Data*) malloc(sizeof(Data));
     
        if(data_resultante_subt!=NULL)
        {
            data_resultante_subt->dia = d.dia;
            data_resultante_subt->mes = d.mes;
            data_resultante_subt->ano = d.ano;
     
            while(dias--)
            {
                if(data_resultante_subt->dia == 1)
                {
                    if(data_resultante_subt->mes!=1)
                    {
                        data_resultante_subt->mes--;
                        data_resultante_subt->dia = ultimo_dia_do_mes(data_resultante_subt->mes, data_resultante_subt->ano);
                    }
     
                    else
                    {
                        data_resultante_subt->ano--;
                        data_resultante_subt->mes = 12;
                        data_resultante_subt->dia = ultimo_dia_do_mes(12, data_resultante_subt->ano);    
                    }
                }
                else
                {
                    data_resultante_subt->dia--;
                }
            }
     
            return data_resultante_subt;
        }
     
        else
        {
            printf("Erro: nao foi possivel realizar a operacao\n");
            return NULL;
        }
    }
     
    void atribuirData (Data * d, unsigned int dia, unsigned int mes, unsigned int ano)
    {
     
        if(d!=NULL)
        {
            d->dia = dia;
            d->mes = mes;
            d->ano = ano;        
        }
        else
        {
            d = NULL;
        }
    }
     
    unsigned int obtemDiaData (Data d)
    {
        return d.dia;    
    }
     
    unsigned int obtemMesData (Data d)
    {
        return d.mes;    
    }
     
    unsigned int obtemAnoData (Data d)
    {
        return d.ano;    
    }
     
    unsigned int bissextoData (Data d)
    {
        return ( e_bissexto(d.ano) );
    }
     
    int comparaData (Data d1, Data d2)
    {
        if(data_igual(d1, d2))
        {
            printf("As datas sao iguais!\n");
            return IGUAL;
        }
        else
        {
            if(data_menor(d1, d2))
            {
                printf("A primeira data e menor do que a segunda data\n");
                return MENOR;
            }
            else
            {
                printf("A primeira data e maior do que a segunda data\n");
                return MAIOR;
            }
        }
    }
     
    unsigned int numeroDiasDatas (Data d1, Data d2);
     
    unsigned int numeroMesesDatas (Data d1, Data d2)
    {
        unsigned int diferenca_anos;
        unsigned int diferenca_meses;
     
        if(d1.mes>d2.mes)
        {
            diferenca_meses = d1.mes - d2.mes;
        }
        else
        {
            diferenca_meses = d2.mes - d1.mes;
        }
     
        if(d1.ano==d2.ano)
        {
            return diferenca_meses;
        }
        else
        {
            printf("%u %u\n", d1.ano, d2.ano);
            if(d1.ano>d2.ano)
            {
                diferenca_anos = d1.ano - d2.ano;
            }
            else
            {
                diferenca_anos = d2.ano - d1.ano;
            }
     
            diferenca_meses = 12*diferenca_anos + diferenca_meses;
            return diferenca_meses;
        }
    }
     
    unsigned int numeroAnosDatas (Data d1, Data d2)
    {
        unsigned int diferenca_anos;
        if(d1.ano>d2.ano)
        {
            diferenca_anos = d1.ano - d2.ano;
        }
        else
        {
            diferenca_anos = d2.ano - d1.ano;
        }
     
        return diferenca_anos;
    }
     
    // Funcoes proprias
     
    void printa_data(Data d)
    {
        if(d.dia<10)
        {
            printf("0%d/", d.dia);
        }
        else
        {
            printf("%d/", d.dia);
        }
        if(d.mes<10)
        {
            printf("0%d/", d.mes);
        }
        else
        {
            printf("%d/", d.mes);
        }
        printf("%d", d.ano);
    }
     
    bool e_bissexto(unsigned int ano_data)
    {
        if(ano_data%4!=0)
        {
            return false;
        }
        else
        {
            if(ano_data%100!=0)
            {
                return true;
            }
            else
            {
                if(ano_data%400==0)
                {
                    return true;
                }
                else
                {
                    return false;
                }    
            }       
        }
    }
     
    unsigned int ultimo_dia_do_mes(unsigned int mes_data, unsigned int ano_data)
    {
        if(mes_data==2)
        {
            if(e_bissexto(ano_data))
            {
                return 29;
            }
            else
            {
                return 28;
            }
        }
        else{
            if(mes_data<=7)
            {
                if(mes_data%2!=0)
                {
                    return 31;
                }
                else
                {
                    return 30;
                }
            }
            if(mes_data>7 && mes_data<=12)
            {
                if(mes_data%2==0)
                {
                    return 31;
                }
                else{
                    return 30;
                }
            }
        }
    }
     
    bool data_igual(Data d1, Data d2)
    {
        if(d1.ano!=d2.ano)
        {
            return false;
        }
        if(d1.mes!=d2.mes)
        {
            return false;
        }
        if(d1.dia!=d2.dia)
        {
            return false;
        }
        return true;
    }
     
    bool data_menor(Data d1, Data d2)
    {
        if(d1.ano>d2.ano)
        {
            return false;
        }
        else
        {
            if(d1.mes>d2.mes)
            {
                return false;
            }
            else
            {
                if(d1.dia>d2.dia)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
        }
    }
     
    int main()
    {
        unsigned int dia_main, mes_main, ano_main;
        Data * copia_main;
        Data * pont_data;
        Data vet_data[1000];
        int m = -1 ;
        int i = 0;
        int indice, indice2;
     
        printf("\nManipulacao de datas - TAD\n");
        
        while(m!=0)
        {
            menu();
            scanf("%d", &m);
            if(m==0)
            {
                break;
            }
            if(m==1)
            {
                printf("Entre com o dia da data: ");
                scanf("%u", &dia_main);
                printf("Entre com o mes da data: ");
                scanf("%u", &mes_main);
                printf("Entre com o ano da data: ");
                scanf("%u", &ano_main);
                i++;
                pont_data = criaData(dia_main, mes_main, ano_main);
                vet_data[i-1] = *pont_data;
                printf("O indice da data criada e: %d\n", i);
                printf("O indice da data sera importante para operacoes futuras\n");
            }
            if(m==2)
            {
                printf("Entre com o indice da data: ");
                scanf("%d", &indice);
                i++;
                copia_main = copiaData(vet_data[indice-1]);
                vet_data[i-1] = *copia_main;
                printf("O indice da data criada e: %d\n", i);
            }
            if(m==3)
            {
                printf("Entre com o indice da data: ");
                scanf("%d", &indice);
                liberaData(&vet_data[indice-1]);
            }
            if(m==4)
            {
                printf("Entre com o indice da data: ");
                scanf("%d", &indice);
                printf("Entre com o numero de dias que deseja somar: ");
                scanf("%d", &dia_main);
                i++;
                pont_data = somaDiasData(vet_data[indice-1], dia_main);
                vet_data[i-1] = *pont_data;
                printf("O indice da data criada e: %d\n", i);
            }
            if(m==5)
            {
                printf("Entre com o indice da data: ");
                scanf("%d", &indice);
                printf("Entre com o numero de dias que deseja subtrair: ");
                scanf("%d", &dia_main);
                i++;
                pont_data = subtrairDiasData(vet_data[indice-1], dia_main);
                vet_data[i-1] = *pont_data;
                printf("O indice da data criada e: %d\n", i);            
            }
            if(m==6)
            {
                printf("Entre com o indice da data: ");
                scanf("%d", &indice);
                printf("Entre com o novo dia da data: ");
                scanf("%u", &dia_main);
                printf("Entre com o novo mes da data: ");
                scanf("%u", &mes_main);
                printf("Entre com o novo ano da data: ");
                scanf("%u", &ano_main);
     
                atribuirData(&vet_data[indice - 1], dia_main, mes_main, ano_main);
            }
            if(m==7)
            {
                printf("Entre com o indice da data: ");
                scanf("%d", &indice);
                dia_main = obtemDiaData(vet_data[indice-1]);
                printf("O dia da data informada e: %u\n", dia_main);
            }
            if(m==8)
            {
                printf("Entre com o indice da data: ");
                scanf("%d", &indice);
                mes_main = obtemDiaData(vet_data[indice-1]);
                printf("O mes da data informada e: %u\n", mes_main);
            }
            if(m==9)
            {
                printf("Entre com o indice da data: ");
                scanf("%d", &indice);
                ano_main = obtemDiaData(vet_data[indice-1]);
                printf("O ano da data informada e: %u\n", ano_main);
            }
            if(m==10)
            {
                printf("Entre com o indice da data: ");
                scanf("%d", &indice);
                if(bissextoData(vet_data[indice-1]))
                {
                    printf("O ano da data informada e bissexto\n");
                }
                else
                {
                    printf("O ano da data informada nao e bissexto\n");
                }
            }
            if(m==11)
            {
                printf("Entre com o indice da primeira data: ");
                scanf("%d", &indice);
                printf("Entre com o indice da segunda data: ");
                scanf("%d", &indice2);
                comparaData(vet_data[indice - 1], vet_data[indice2 - 1]);
            }
            if(m==12)
            {
                printf("Entre com o indice da primeira data: ");
                scanf("%d", &indice);
                printf("Entre com o indice da segunda data: ");
                scanf("%d", &indice2);
                mes_main = numeroMesesDatas(vet_data[indice - 1], vet_data[indice2 - 1]);
                printf("O numero de meses entre as datas e %u\n", mes_main);
            }
            if(m==13)
            {
                printf("Entre com o indice da primeira data: ");
                scanf("%d", &indice);
                printf("Entre com o indice da segunda data: ");
                scanf("%d", &indice2);
                ano_main = numeroMesesDatas(vet_data[indice - 1], vet_data[indice2 - 1]);
                printf("O numero de anos entre as datas e %u\n", ano_main);
            }
            if(m==14)
            {
                printf("Entre com o indice da data: ");
                scanf("%d", &indice);
                printa_data(vet_data[indice - 1]);
            }
        }
     
        return 0;
    }
