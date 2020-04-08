#include <stdlib.h>
int* copyArray(int *h,int n){
   int *novo = (int *)malloc(sizeof(int)*n);
   for(int i=0; i<n;i++){
       novo[i] = h[i];
   }
   return novo;
}
void heapSort(int *heap,int n){
    int *copia = copyArray(heap,n);
    for(int i = 0; i<n;i++){
        remover();
    }
   
}