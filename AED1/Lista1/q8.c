    #include <stdio.h>
     
    int main(){
     
        int prim_num, seg_num;
        int menor;
        int i, divisor_comum, temp;
     
        // Entre com o primeiro numero inteiro:
        scanf("%d", &prim_num);
     
        // Entre com o segundo numero inteiro:
        scanf("%d", &seg_num);
     
        if(prim_num<seg_num) menor = prim_num;
        if(prim_num>seg_num) menor = seg_num;
        if(prim_num==seg_num && prim_num!=0 && seg_num!=0){
            printf("O maximo divisor comum de %d e %d é: %d\n", prim_num, prim_num, prim_num);
            return 0;
        }
        if(prim_num==0 || seg_num==0){
            printf("O maximo divisor comum de %d e %d é: 1\n", prim_num, seg_num);
            return 0;
        }
     
        temp = 1;
     
        for(i=1;i<=menor;i++){
            if(prim_num%i==0 && seg_num%i==0){
                divisor_comum = i;
            }
            if(divisor_comum>temp){
                temp = divisor_comum;
            }
        }
     
        printf("O maximo divisor comum de %d e %d é: %d\n", prim_num, seg_num, temp);
     
        return 0;
    }
