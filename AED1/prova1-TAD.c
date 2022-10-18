    // =====================
    /* Arquivo Janela.h */
    // =====================
     
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
     
    #define MAX 1000
     
    typedef struct JANELA janela;
     
    janela * janela_anterior; // variavel global
     
    // Funcoes padrao
    janela * AbrirJanela();
    int FecharJanela(janela * guia); 
    int RedimensionarJanela(janela * guia);
    int MoverJanela(janela * guia);  
    int DesfazerUltimaOperacao(janela * guia);
     
    // Funcoes extras
    void menu();
    int imprime_janela(janela * guia);
    janela * copia_janela(janela * guia);
     
    // =====================
    /* Arquivo Janela.c */
    // =====================
     
    struct JANELA{
        float x;              // Coordenada x de referencia
        float y;              // Coordenada y de referencia
        float largura;        // Largura da janela;
        float altura;         // Altura da janela
    };
     
    void menu(){
        printf("======================================================================\n");
        printf("Interface grafica de usuario: janelas\n");
        printf("Entre com o numero correspondente a operacao desejada\n");
        printf("(OBS.: caso deseje encerrar o programa, entre com o valor zero)\n");
        printf(" 1 - Abre uma janela\n");
        printf(" 2 - Fecha uma janela\n");
        printf(" 3 - Redimensiona a janela\n");
        printf(" 4 - Move a janela\n");
        printf(" 5 - Desfaz a ultima operacao realizada\n");
        printf(" 6 - Mostra os dados da janela (coordenadas, altura e largura)\n");
        printf("======================================================================\n");
    }
     
    int imprime_janela(janela * guia){
        if(guia!=NULL){
            printf("A coordenada x da janela e : %f\n", guia->x);
            printf("A coordenada y da janela e : %f\n", guia->y);
            printf("A largura da janela e: %f\n", guia->largura);
            printf("A altura da janela e: %f\n", guia->altura);
            return true;
        }
        else{
            printf("A janela nao existe\n");
            return false;
        }
    }
     
    janela* AbrirJanela(){
        janela_anterior = NULL;
        janela * aba;
        aba = (janela*) malloc(sizeof(janela));
     
        if(aba!=NULL){
            float coord_x, coord_y;
            float larg, alt;
     
            printf("Entre com as coordenadas (x y) da janela: ");
            scanf("%f %f", &coord_x, &coord_y);
            printf("Entre com a largura da janela: ");
            scanf("%f", &larg);
            printf("Entre com a altura da janela: ");
            scanf("%f", &alt);
     
            aba->x = coord_x;
            aba->y = coord_y;
            aba->largura = larg;
            aba->altura = alt;
     
            printf("A janela foi criada com sucesso!\n");
            return aba;
        }
        else{
            printf("Nao foi possivel criar a janela\n");
            return NULL;
        }
    }
     
    int FecharJanela(janela * guia){
     
        janela_anterior = copia_janela(guia);
     
        if(guia!=NULL){
            printf("******************\n");
            free(guia);
            return true;    
        }
        else{
            printf("A janela nao existe\n");
            return false;
        }
    }
     
    int RedimensionarJanela(janela * guia){
     
        janela_anterior = copia_janela(guia);
     
        float larg, alt;
        if(guia==NULL){
            printf("A janela nao existe\n");
            return false;
        }
        else{
            printf("Entre com a nova largura da janela: ");
            scanf("%f", &larg);
            printf("Entre com a nova altura da janela: ");
            scanf("%f", &alt);
            guia->largura = larg;
            guia->altura = alt;
            printf("A janela foi redimensionada com sucesso!\n");
            return true;
        }
    }
     
    int MoverJanela(janela * guia){
     
        janela_anterior = copia_janela(guia);
     
        float coord_x, coord_y;
        if(guia==NULL){
            printf("A janela nao foi criada\n");
            return false;
        }
        else{
            printf("Entre com a nova coordenada x da janela: ");
            scanf("%f", &coord_x);
            printf("Entre com a nova coordenada y da janela: ");
            scanf("%f", &coord_y);
            guia->x = coord_x;
            guia->y = coord_y;
            printf("A janela foi movida com sucesso!\n");
            return true;
        }
    }
     
    janela * copia_janela(janela * guia){
        janela * copia;
        copia = (janela*) malloc(sizeof(janela));
        if(copia!=NULL){
            copia->x = guia->x;
            copia->y = guia->y;
            copia->largura = guia->largura;
            copia->altura = guia->altura;
            return copia;
        }
        else{
            return NULL;
        }
    }
     
    int DesfazerUltimaOperacao(janela * guia){
        guia = copia_janela(janela_anterior);
        return true;
    }
     
    int main(){
        int i = 0;                  // Marcador do indice da janela
        int m = -1;                 // Variavel de controle para o uso do menu
        int indice;                 // Parametro que recebe o indice da janela
        janela vetjanela[MAX];      // Vetor da estrutura janela com tamanho MAX
        janela *pont_janela; 
     
        while(m!=0){
            menu();
            scanf("%d", &m);
            if(m==0){
                break;
            }
            if(m==1){
                pont_janela = AbrirJanela();
                vetjanela[i] = *pont_janela;
                i++;
                printf("\nO indice da janela criada e %d\n", i);
                printf("O indice da janela sera importante para operacoes futuras\n");
            }
            if(m==2){
                printf("Entre com o indice da janela: ");
                scanf("%d", &indice);
                FecharJanela(&vetjanela[indice-1]);
            }
            if(m==3){
                printf("Entre com o indice da janela: ");
                scanf("%d", &indice);
                RedimensionarJanela(&vetjanela[indice-1]);            
            }
            if(m==4){
                printf("Entre com o indice da janela: ");
                scanf("%d", &indice);
                RedimensionarJanela(&vetjanela[indice-1]);            
            }
            if(m==5){
                printf("Entre com o indice da janela: ");
                scanf("%d", &indice);
                DesfazerUltimaOperacao(&vetjanela[indice-1]);                
            }
            if(m==6){
                printf("Entre com o indice da janela: ");
                scanf("%d", &indice);
                imprime_janela(&vetjanela[indice-1]);
            }
        }
     
        return 0;
    }
