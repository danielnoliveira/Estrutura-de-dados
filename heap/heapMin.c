#include<stdio.h>
#include<math.h>
#include <stdlib.h>
int *heap;
int tam_max = 50;
int tam_atual = 0;
int metodo_construcao = 0;//0-descer,1-subir
void printHeapMax(int *H,int n);
void construirHeapMax(int *H,int n);
void descer(int *H,int n,int i);
void subir(int *H,int n);
void construirArray();
void inserir();
void remover();
void menu(){
    int op = -1;
    do
    {
        printf("Escolha uma opção:\n");
        printf("1-construir\n");
        printf("2-inserir\n");
        printf("3-remover\n");
        printf("4-exibir heap\n");
        printf("5-sair\n");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            construirArray();
            break;
        case 2:
            inserir();
            break;
        case 3:
            remover();
            break;
        case 4:
            printHeapMax(heap,tam_atual);
            break;    
        default:
            break;
        }
    } while (op!=5);
    
}
void start(){
    heap = (int *)malloc(sizeof(int)*tam_max);
}

void main()
{
    start();
    menu();
    free(heap);
}
void printHeapMax(int *H,int n){

    for (int i = 0; i < n; i++)
    {
        printf("%d ",H[i]);
    }
    printf("\n");
    
}
void construirHeapMax(int *H,int n){
    if (metodo_construcao==0)
    {
        for (int i = floor(n/2); i >=1; i--)
        {
            // printf("Valores construir: n=%d i=%d \n",n,i);
            descer(H,n,i);
            
        }
    }else{
        for (int i = 2; i<=n; i++)
        {
            // printf("Valores construir: n=%d i=%d \n",n,i);
            subir(H,i);
        }
    }
    
    
}
void descer(int *H,int n, int i){
    int j = i;
    int aux = 0;
    // printf("Valores descer iniciais: j=%d\n",i);
    while ((2*j)-1<n)
    {
        int f = 2*j;
        if(f<n && H[f-1]>H[(f-1)+1]){
            f++;
        }
        // printf("valores do while descer: f=%d H[j]=%d H[f]=%d\n",f,H[j],H[f]);
        if (H[j-1]<=H[f-1]){
            j = n;
        }else{
            aux = H[j-1];
            H[j-1] = H[f-1];
            H[f-1] = aux;
            printHeapMax(heap,tam_atual);
            // printf("Valores do while descer final: H[j]=%d H[f]=%d\n",H[j-1],H[f-1]);
            j = f;
        }
    }
    
}
void construirArray(){
    int tam;
    printf("Qual o tamanho do vetor?");
    scanf("%d",&tam);
    if (tam+tam_atual>tam_max){
        heap = realloc(heap,tam_max+50);
        tam_max += 50;
    }
    printf("Digite os elementos:");
    for (int i = tam_atual; i < tam+tam_atual; i++)
    {
        scanf("%d",&heap[i]);
    }
    tam_atual += tam; 
    construirHeapMax(heap,tam_atual);
}

void subir(int *H,int n){
    int i = n;
    int d = floor(i/2);
    int aux = 0;
    // printf("Valores iniciais subir: i=%d d=%d H[d]=%d H[i]=%d\n",i,d,H[d-1],H[i-1]);
    while (i>=2 && H[d-1]>=H[i-1])
    {
        aux = H[i-1];
        H[i-1] = H[d-1];
        H[d-1] = aux;
        printHeapMax(heap,tam_atual);
        // printf("Valores iniciais subir while: i=%d H[d]=%d H[i]=%d\n",i,H[d-1],H[i-1]);
        i = floor(i/2);
        d = floor(i/2);
    }
}
void inserir(){
    int num;
    printf("Informe o numero");
    scanf("%d",&num);
    if (tam_atual+1>tam_max)
    {
        heap = realloc(heap,tam_max+10);
    }
    heap[tam_atual++] = num;
    subir(heap,tam_atual);
}
void remover(){
    int ultimo_elemento = heap[tam_atual-1];
    heap[0] = ultimo_elemento;
    tam_atual--;
    descer(heap,tam_atual,1);
}