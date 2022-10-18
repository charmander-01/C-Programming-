    // Fatorial duplo
     
    #include <stdio.h>
     
    unsigned long int fat_duplo(int num);
     
    int main()
    {
     
        int n;
        unsigned long int resultado;
        
        scanf("%d", &n);
        
        resultado = fat_duplo(n);
        printf("%lu", resultado);
     
        return 0;
    }
     
    unsigned long int fat_duplo(int num){
        if(num==1){
            return 1;
        }
        if(num%2==0){
            return fat_duplo(num-1);
        }
        else{
            return num*(fat_duplo(num-2));
        }
    }
