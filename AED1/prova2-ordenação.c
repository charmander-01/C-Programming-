    #include <stdio.h>
    #include <ctype.h>
     
    #define CANDIDATOS 1010
    #define QUESTOES 60
     
    typedef struct ALUNO aluno;
     
    struct ALUNO
    {
        int inscricao;
        int nota;
    };
     
    void SelectionSort(aluno vetor[], int tam);
     
    void swap(aluno vetor[], int pos1, int pos2);
     
    int main()
    {
        int cont_letras = 0;
        int i, j;
        int num_cand, qtd_questoes;
        char resposta;
        char vet_questoes[QUESTOES];
     
        aluno vet_aluno[CANDIDATOS];
     
        int pontuacao = 0;
     
        scanf("%d", &num_cand);
     
        if(num_cand<1 || num_cand>1000)
        {
            printf("erro\n");
            return 0;
        }
     
        scanf("%d", &qtd_questoes);
        getchar();
     
        if(qtd_questoes<1 || qtd_questoes>50)
        {
            printf("erro\n");
            return 0;
        }    
     
        for(i=0;i<qtd_questoes;i++)
        {
            if(i!=qtd_questoes-1) 
            {
                scanf("%c ", &resposta);
                if(islower(resposta) || !isalpha(resposta))
                {
                    printf("erro\n");
                    return 0;
                }
            }
            else
            { 
                scanf("%c", &resposta);
                if(islower(resposta) || !isalpha(resposta))
                {
                    printf("erro\n");
                    return 0;
                }
            }
            vet_questoes[i] = resposta;
        }
     
        getchar();
     
        for(i=0;i<num_cand;i++)
        {
            pontuacao = 0;
            vet_aluno[i].inscricao = i + 1;
     
            for(j=0;j<qtd_questoes;j++)
            {
                if(j!=qtd_questoes-1) scanf("%c ", &resposta);
                else scanf("%c", &resposta);
     
                if(vet_questoes[j]==resposta)
                {
                    pontuacao++;
                }
            }
            
            getchar();
     
            vet_aluno[i].nota = pontuacao;
        }
     
        SelectionSort(vet_aluno, num_cand);
     
        for(i=0;i<num_cand;i++)
        {
            printf("%d %d\n", vet_aluno[i].inscricao, vet_aluno[i].nota);
        }
     
        return 0;
    }
     
    void SelectionSort(aluno vetor[], int tam)
    {
        int i, j;
        int ind_maior, maior;
     
        for(i=0;i<tam-1;i++)
        {
            maior = vetor[i].nota;
            ind_maior = i;
     
            for(j=i+1;j<tam;j++)
            {
                if(vetor[j].nota==maior && vetor[j].inscricao<vetor[i].inscricao)
                {
                    maior = vetor[j].nota;
                    ind_maior = j;                
                }
                else
                {
                    if(vetor[j].nota>maior)
                    {
                        maior = vetor[j].nota;
                        ind_maior = j;
                    }            
                }
            }
            swap(vetor,i, ind_maior);
        }
    }
     
    void swap(aluno vetor[], int pos1, int pos2)
    {
        aluno aux;
     
        aux.inscricao = vetor[pos1].inscricao;
        aux.nota = vetor[pos1].nota;
     
        vetor[pos1].inscricao = vetor[pos2].inscricao;
        vetor[pos1].nota = vetor[pos2].nota;
     
        vetor[pos2].inscricao = aux.inscricao;
        vetor[pos2].nota = aux.nota;
    }
