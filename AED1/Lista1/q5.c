    #include <stdio.h>
     
    double calcula_media(double valor1, double valor2, double valor3, double valor4);
     
    int main(){
     
        /*
            Soma dos pesos: 10
     
            Todas as notas distintas: (OK!)
                Maior nota: peso 4
                Segunda maior nota: peso 3
                Terceira maior nota: peso 2
                Quarta maior nota: peso 1
     
            Não existe uma nota maior e nem uma nota menor: (OK!)
                Peso de todas as notas : 2,5
     
            Existe uma nota maior, mas não uma nota menor
                Maior nota: peso 4
                Demais notas: peso 2
     
            Não existe uma nota maior, mas existe uma nota menor
                Menor nota: peso 1
                Demais notas: peso 3
        */
     
        int N;
        int i;
        double nota1, nota2, nota3, nota4;
        double media_aluno;
        double vetor_media_final[55];
        double soma = 0;
        double maior_media=0, menor_media=10;
     
        // Entre com o numero de alunos da turma:
        scanf("%d", &N);
     
        if(N<=0 || N>50){
            printf("O numero de alunos da turma dever ser estar entre 1 e 50 – programa cancelado\n");
            return 0;
        }
     
        for(i=0;i<N;i++){
            // Entre com as notas do aluno:
            scanf("%lf", &nota1);
            if(nota1<0 || nota1>10){
                printf("O valor de cada nota do aluno deve estar entre 0 e 10,0 – programa cancelado\n");
                return 0;            
            }
            scanf("%lf", &nota2);
            if(nota2<0 || nota2>10){
                printf("O valor de cada nota do aluno deve estar entre 0 e 10,0 – programa cancelado\n");
                return 0;            
            }
            scanf("%lf", &nota3);
            if(nota3<0 || nota3>10){
                printf("O valor de cada nota do aluno deve estar entre 0 e 10,0 – programa cancelado\n");
                return 0;            
            }
            scanf("%lf", &nota4);
            if(nota4<0 || nota4>10){
                printf("O valor de cada nota do aluno deve estar entre 0 e 10,0 – programa cancelado\n");
                return 0;            
            }
     
            media_aluno = calcula_media(nota1, nota2, nota3, nota4);        
            vetor_media_final[i] = media_aluno;
            soma += media_aluno;
            if(media_aluno>maior_media){
                maior_media = media_aluno;
            }
            if(media_aluno<menor_media){
                menor_media = media_aluno;
            }
        }
        
        for(i=0;i<N;i++){
            printf("Media final do aluno %d: %.1lf\n\n", (i+1), vetor_media_final[i]);
        }
     
        printf("Media geral da turma: %.1lf\n\n", (soma/N) );
        printf("Maior media da turma: %.1lf\n\n", maior_media);
        printf("Menor media da turma: %.1lf\n", menor_media);
     
        return 0;
    }
     
    double calcula_media(double valor1, double valor2, double valor3, double valor4){
     
        double valores[4];
        double maior_valor;
        double segundo_maior;
        double terceiro_maior;
        double menor_valor;
     
        int j, i;
        int ind_menor;
        double temp;
     
        double media;
     
        valores[0] = valor1;
        valores[1] = valor2;
        valores[2] = valor3;
        valores[3] = valor4;
     
        if(valor1==valor2 && valor2==valor3 && valor3==valor4){
            return valor1;
        }
     
        // Selection Sort
        for(i=0;i<3;i++){
            menor_valor = valores[i];
            ind_menor = i;
            for(j=i;j<4;j++){
                if(valores[j]<menor_valor){
                    menor_valor = valores[j];
                    ind_menor = j;
                }
            }
            temp = valores[i];
            valores[i] = menor_valor;
            valores[ind_menor] = temp;
        }
     
        menor_valor = valores[0];
        terceiro_maior = valores[1];
        segundo_maior = valores[2];
        maior_valor = valores[3];
     
        // Todas as notas distintas;
        if(valor1!=valor2 && valor1!=valor3 && valor1!=valor4 &&
           valor2!=valor3 && valor2!=valor4 && valor3!=valor4){
                media = (maior_valor*4 + segundo_maior*3 + terceiro_maior*2 + menor_valor*1)/10;
                return media;
        }
     
        // Não existe uma nota maior e nem uma nota menor;
        if( (valores[3]==valores[2] || valores[3]==valores[1] || valores[3]==valores[0]) 
            && (valores[0]==valores[1] || valores[0]==valores[2] || valores[0]==valores[3]) ){
                media = (maior_valor*2.5 + segundo_maior*2.5 + terceiro_maior*2.5 + menor_valor*2.5)/10;
                return media;
        }
     
        // Existe uma nota maior, mas não uma nota menor;
        if( (valores[3]!=valores[2] && valores[3]!=valores[1] && valores[3]!=valores[0]) 
            && (valores[0]==valores[1] || valores[0]==valores[2]) ){
                media = (maior_valor*4 + segundo_maior*2 + terceiro_maior*2 + menor_valor*2)/10;
                return media;
        }
     
        // Não existe uma nota maior, mas existe uma nota menor
        if( (valores[3]==valores[2] || valores[3]==valores[1]) 
            && (valores[0]!=valores[1] && valores[0]!=valores[2] && valores[0]!=valores[3]) ){
                media = (maior_valor*3 + segundo_maior*3 + terceiro_maior*3 + menor_valor*1)/10;
                return media;
        }
     
    }
     
        // if(valores[0]==valores[1] && valores[1]==valores[2] && valores[2]!=valores[3]){
        //     media = (valores[3]*4 + valores[0]*2 + valores[1]*2 + valores[2]*2)/10;
        //     return media; 
        // }
     
        // if(valores[1]==valores[2] && valores[2]==valores[3] && valores[3]!=valores[0]){
        //     media = (valores[0]*1 + valores[1]*3 + valores[2]*3 + valores[3]*3)/10;
        //     return media;
        // }
     
        // if(valor1==valor2 && valor2==valor3 && valor3==valor4){
        //     return valor1;
        // }
