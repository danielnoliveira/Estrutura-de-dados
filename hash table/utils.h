#include <stdio.h>
#include <stdlib.h>

long* randomNumbersArray(long n){
    long* vetor  = (long *)malloc(sizeof(long)*n);
    time_t t;
    for (long i = 0; i < n; i++)
    {
       vetor[i] = rand() %2000000000; 
    }
    return vetor;
}
void fillZero(char * bits){

    for (size_t i = 0; i < 32; i++)
    {
        bits[i] = '0';
    }
    
}
int decimalToInt(long n,char *bits){
    bits = (char *)malloc(sizeof(char)*32);
    fillZero(bits);
    int last = 31;
    int resto = 0;
    int cont = 0;
    while(n!=0){
        resto = n%2;
        bits[last--] = resto==1?'1':'0';
        n = n/2;
        cont++;
    }
    // for (size_t i = 0; i < 32; i+=8)
    // {
    //     for (size_t j = 0; j <8; j++)
    //     {
    //         printf("%c",bits[i+j]);
    //     }
    //     printf(" ");
    // }
    
    // printf("\n%d\n",cont);
    return cont;
}