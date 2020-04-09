#include <stdio.h>
#include "utils.h"
# define tam 100000
# define N 200000 
// Metodos de dispersão
int metodoDaDivisao(long chave, long tam_table){
    return chave % tam_table;
}
long metodoDaDobraDecimal(long chave){

}
long* n;//vetor com os valores a serem colocados nas tabelas hash

long hash_table_div[tam];//tabela para o metodo de divisão
long hash_table_dobra[tam];//tabela para o metodo de dobra com deciamis

int main(int argc, char const *argv[])
{
    int count_colisoes = 0;
    n = randomNumbersArray(N);
    // for (long i = 0; i < 200000; i+=20)
    // {
    //     for(long j = 0; j<20;j++){
    //         printf("%li ",vetor[i+j]);
    //     }
    //     // printf("\n");
    // }
    // inserindo chaves na tabela do metodo da divisao
    long key;
    for (long i = 0; i < N; i++){
        key = metodoDaDivisao(n[i],tam);
        if (hash_table_div[key]!=0)
        {
            count_colisoes++;
        }else{
            hash_table_div[key] = n[i];
        }
        
    }
    printf("Colisões na tabela de dispersão por divisão: %d\n",count_colisoes);
    count_colisoes = 0;
    for (long i = 0; i < N; i++){
        key = metodoDaDobraDecimal(n[i]);
        if (hash_table_div[key]!=0)
        {
            count_colisoes++;
        }else{
            hash_table_div[key] = n[i];
        }
        
    }
    printf("Colisões na tabela de dispersão por divisão: %d\n",count_colisoes);
    free(n);
    return 0;
}
