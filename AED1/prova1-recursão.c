    #include <stdio.h>
     
    int menor(int num1, int num2);
    int maior(int num1, int num2);
    int elemento_max(int sequencia[], int tam, int inicio);
    int elemento_min(int sequencia[], int tam, int inicio);
    int soma_limites(int sequencia[], int tam, int min, int max, int inicio);
     
    int main(){
     
        int num_elem = 0 ;  // Numero de elementos do vetor 
        int vetor[100];     // Vetor com tamanho maximo de 100 elementos
        int i;              // Contador
        int minimo, maximo; // Valor minimo e valor maximo do vetor
        int somatorio;      // Soma dos valores limites
     
        while(1){
            printf("Entre com o numero de elementos (tamanho do vetor) : ");
            scanf ("%d", &num_elem);
            if(num_elem>0 && num_elem<=100) break;
            else{
                printf("O numero de elementos deve ser maior do que zero e menor ou igual a cem!\n");
                printf("*************** Entre novamente com os dados ***************\n");
            }
        }
     
        printf("Entre com os elementos do vetor: ");
        for(i=0;i<num_elem;i++){
            scanf("%d", &vetor[i]);
        }
        minimo = elemento_min(vetor, num_elem, 0);
        maximo = elemento_max(vetor, num_elem, 0);
     
        //printf("%d %d\n", minimo, maximo);
     
        somatorio = soma_limites(vetor, num_elem, minimo, maximo, 0);    
        printf("O valor da soma dos limites do vetor e: %d\n", somatorio);
     
        return 0;
    }
     
    int menor(int num1, int num2){
        if(num1<num2) return num1;
        else return num2;
    }
     
    int maior(int num1, int num2){
        if(num1>num2) return num1;
        else return num2;
    }
     
    int elemento_min(int sequencia[], int tam, int inicio){
        if(inicio==tam-1){
            return sequencia[inicio];
        }
        else{
            return menor(sequencia[inicio], elemento_min(sequencia, tam, inicio+1) );
        }
    }
     
    int elemento_max(int sequencia[], int tam, int inicio){
        if(inicio==tam-1){
            return sequencia[inicio];
        }
        else{
            return maior(sequencia[inicio], elemento_max(sequencia, tam, inicio+1) );
        }
    }
     
    int soma_limites(int sequencia[], int tam, int min, int max, int inicio){
        if(inicio>tam-1){
            return 0;
        }
        else{
            if(sequencia[inicio]==min && sequencia[inicio]==max){
                return 2*sequencia[inicio] + soma_limites(sequencia, tam, min, max, inicio+1);
            }
            else if (sequencia[inicio]==min || sequencia[inicio]==max) {
                return sequencia[inicio] + soma_limites(sequencia, tam, min, max, inicio+1);
            }
            else{
                return soma_limites(sequencia, tam, min, max, inicio+1);
            }       
        }
    }
