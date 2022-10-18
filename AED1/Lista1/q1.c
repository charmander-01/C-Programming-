    #include <stdio.h>
     
    int main(){
        // Raciocínio:
        // Vm = (delta s)/(delta t) -> (delta s) = Vm * (delta t)
        // Sf = Si + Vt
        // SA = SB -> S0A (zero) + VAt = S0B (dist) + VBt
        // VAt = dist + VBt
        // dist = VAt - VBt
        // dist = t*(VA - VB);
        // t = dist/(VA - VB); VA > 0 e VB < 0;
        // t = dist/(VA + VB);   
     
        double dist;
        int vA, vB;
        double encontro, tempo;
     
        //Entre com a distancia entre as cidades A e B em Km: 
        scanf("%lf", &dist);
     
        if(dist==0){
            printf("A distancia entre as cidades deve ser maior do que zero – programa cancelado\n");
            return 0;
        }
     
        //Entre com a velocidade do automovel 1 em Km/h:
        scanf("%d", &vA);
     
        if(vA==0){
            printf("A velocidade do automovel deve ser maior do que zero – programa cancelado\n");
            return 0;
        }
     
        //Entre com a velocidade do automovel 2 em Km/h:
        scanf("%d", &vB);
        
        if(vB==0){
            printf("A velocidade do automovel deve ser maior do que zero – programa cancelado\n");
            return 0;
        }
     
        tempo = dist/(vA+vB);
        encontro = vA*tempo;
     
        printf("Momento do encontro: %.2lf horas apos a partida\n\n", tempo);
        printf("Local do encontro: %.2lf Km da cidade A\n", encontro);
     
        return 0;
    }

×

