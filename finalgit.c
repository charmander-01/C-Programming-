// Trabalho Final - IP (Introdução à Progrmação)
// Jogo do milhão

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define STRING_MAX 1000                      // Tamanho máximo de caracteres da pergunta

struct struct_perguntas{
    char pergunta[STRING_MAX];
    char letra_a[STRING_MAX];
    char letra_b[STRING_MAX];
    char letra_c[STRING_MAX];
    char letra_d[STRING_MAX];
    char resposta_struct;
}vetorpergunta[50];

void inicio();
int read_file(FILE * arq);
void imprime_pergunta(int index, int * premio, int cont_ip, int *aux);
short int nova_pergunta(int vect[], int number);


int main()
{

    FILE *perguntas;                        // Arquivo texto (perguntas e respostas)
    int premiacao = 0;                      // Premiação do participante (atualizada a cada rodada)
    int num_aleat, resto;                   // Número aletório, resto de acordo com o núm. de perguntas
    int cont, i=0;                          // Contadores
    char resposta_usuario;                  // Resposta do usuário para a questão
    char escolha_final;                     // Decisão final (pergunta do milhão)
    int num_perguntas;                      // Núm de perguntas        
    int vect_perguntas[20];                 // Garantir perguntas diferentes;            
    short int retorno;                      // retorno da função nova_pergunta
    int pulos = 3;                          // Quantidade de pulos permitidos

    srand(time(0));                         // Criação da seed, importante para garantir a aleatoriedade (time.h)

    inicio();

    num_perguntas = read_file(perguntas);

    for(cont=0;cont<15;cont++){
        num_aleat = rand();
        resto = num_aleat % num_perguntas;
        retorno = nova_pergunta(vect_perguntas, resto);
        if(retorno){
            vect_perguntas[i]=resto;
            imprime_pergunta(resto, &premiacao, cont, &pulos);
            i++;
            if(cont==4){
                printf("SEGUNDA RODADA: \n");
                printf("_______________________________________\n");
                printf("\n");
            }
            if(cont==9){
                printf("TERCEIRA RODADA: \n");
                printf("_______________________________________\n");
                printf("\n");
            }
            if(cont==14){
                printf("PERGUNTA DO MILHÃO\n");
                printf("Deseja prosseguir para a pergunta do milhão(s/n)?");
                scanf("%c", &escolha_final);
                getchar();
                if(escolha_final=='n'){
                    printf("=======================================\n");
                    printf("Premiação: R$: 2000,00\n");
                    printf("Obrigado por jogar!\n");
                    printf("=======================================\n");
                    exit(1);    
                }
            }
        }
        else{
            while(retorno==0){
                num_aleat = rand();
                resto = num_aleat % num_perguntas;
                retorno = nova_pergunta(vect_perguntas , resto);
            }
            vect_perguntas[i]=resto;
            i++;
            if(cont==4){
                printf("SEGUNDA RODADA: \n");
                printf("_______________________________________\n");
                printf("\n");
            }
            if(cont==9){
                printf("TERCEIRA RODADA: \n");
                printf("_______________________________________\n");
                printf("\n");
            }
            if(cont==14){
                printf("PERGUNTA DO MILHÃO\n");
                printf("Deseja prosseguir para a pergunta do milhão(s/n)?\n");
                scanf("%c", &escolha_final);
                getchar();
                if(escolha_final=='n'){
                    printf("=======================================\n");
                    printf("Premiação: R$: 2000,00\n");
                    printf("Obrigado por jogar!\n");
                    printf("=======================================\n");
                    exit(1);    
                }
            }
            imprime_pergunta(resto, &premiacao, cont, &pulos);
        }
    }

    return 0;
}
void inicio(){
    printf("*********** JOGO DO MILHÃ0 ************\n");
    printf("\n");
    printf("***************************************\n");
    printf("INSTRUÇÕES:");
    printf("O jogo é composto de 3 rodadas, cada uma com 5 perguntas\n");
    printf("Na primeira rodada, cada questão vale mil reais\n");
    printf("Na segunda rodada, cada quetão vale dez mil reais\n");
    printf("Na terceira rodada, cada questão vale cem mil reais\n");
    printf("\n");
    printf("Para submeter a resposta, digite a letra minúscula correspondente\n");
    printf("e pressione a tecla ENTER.\n");
    printf("Caso queira pular a questão, digite p e aperte ENTER\n");
    printf("São permitidos, no máximo, 3 pulos\n");
    printf("***************************************\n");
    printf("\nPRIMEIRA RODADA:\n");
    printf("_______________________________________\n");
    printf("\n");    
}
int read_file(FILE * arq){
    int read_cont;
    int leitura=1;
    char caracteres[STRING_MAX];
    int cont_s = 0;

    arq = fopen("/home/luis/Documents/IP_Thierson/Trabalho Final/arq.txt", "rt");
    if (arq == NULL)
    {
        printf("Não foi possível abrir o arquivo em modo leitura\n");
        printf("Término do programa\n");
        exit(1);
    }

    while(leitura!=EOF){
        leitura = fscanf(arq, "%[^\n]", caracteres);
        fgetc(arq);
        strcpy(vetorpergunta[cont_s].pergunta, caracteres);
        leitura = fscanf(arq, "%[^\n]", caracteres);
        fgetc(arq);
        strcpy(vetorpergunta[cont_s].letra_a, caracteres);
        leitura = fscanf(arq, "%[^\n]", caracteres);
        fgetc(arq);
        strcpy(vetorpergunta[cont_s].letra_b, caracteres);
        leitura = fscanf(arq, "%[^\n]", caracteres);
        fgetc(arq);
        strcpy(vetorpergunta[cont_s].letra_c, caracteres);
        leitura = fscanf(arq, "%[^\n]", caracteres);
        fgetc(arq);
        strcpy(vetorpergunta[cont_s].letra_d, caracteres);
        leitura = fscanf(arq, "%c", &vetorpergunta[cont_s].resposta_struct);
        leitura = fgetc(arq);
        cont_s++;
    }
    fclose(arq);
    return cont_s;
}
short int nova_pergunta(int vect[], int number){
    int nova_pergunta_cont;
    for(nova_pergunta_cont=0;nova_pergunta_cont<15;nova_pergunta_cont++){
        if(vect[nova_pergunta_cont]==number){
            return 0;
        }
    }
    return 1;
}
void imprime_pergunta(int index, int * premio, int cont_ip, int *aux){
    char resposta_usuario;
    printf("%s\n", vetorpergunta[index].pergunta);
    printf("%s\n", vetorpergunta[index].letra_a);
    printf("%s\n", vetorpergunta[index].letra_b);
    printf("%s\n", vetorpergunta[index].letra_c);
    printf("%s\n", vetorpergunta[index].letra_d);
    scanf("%c", &resposta_usuario);
    getchar();
    if(resposta_usuario=='p' && cont_ip!=14){
        if(*aux){
            *aux = *aux-1;
            return;
        }
        else{
            printf("Vc não pode mais pular a questão\n");
        }
    }    
    
    if(resposta_usuario==vetorpergunta[index].resposta_struct){
        printf("RESPOSTA CORRETA!\n");
        if(cont_ip>=0 && cont_ip<=4) *premio+=1000;
        if(cont_ip>=5 && cont_ip<=9) *premio+=10000;
        if(cont_ip>=10 && cont_ip<=13) *premio+=100000;
        if(cont_ip==14) *premio = 1000000;
        printf("=======================================\n"); 
        printf("Premiação: R$: %d,00\n", *premio);
        printf("=======================================\n");
    }
    else{
        printf("RESPOSTA ERRADA\n");
        printf("=======================================\n");
        printf("Premiação: R$: %d,00\n", *premio);
        printf("Obrigado por jogar!\n");
        printf("=======================================\n");
        exit(1);
    }
}
	
	
