    #include <stdio.h>
    #include <string.h>
     
    void reverso(char string[], int i, int j, int tamanho);
     
    int main(){
     
        char num[7], vect_reverso[7];
        int algarismos;
        int cont, cont2; 
     
        scanf("%[^\n]", num);
        getchar();
     
        //printf("num: %s\n", num);
     
        algarismos = strlen(num);
        //printf("algarismos: %d\n", algarismos);
        cont2 = algarismos-1;
        //printf("cont2: %d\n", cont2);
     
        for(cont=0;cont<algarismos;cont++){
            vect_reverso[cont] = num[cont2];
            //printf("%c", vect_reverso[cont]);
            cont2--; 
        }
     
        //printf("\n");
     
        cont = 0;
        cont2 = 0;
        reverso(vect_reverso, cont, cont2, algarismos);
     
        return 0;
    }
     
    void reverso(char string[], int i, int j, int tamanho){
     
        while(string[i]=='0' && j==0){
            i++;
        }    
     
        if(string[i]!='0' || j==1){
            j = 1;
            printf("%c", string[i]);
            if(i==tamanho-1){
                printf("\n");
                return;
            }
            else{
                i++;
                reverso(string, i, j, tamanho);            
            }
        }
    }
