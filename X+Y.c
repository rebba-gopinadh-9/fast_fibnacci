#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int x;
    int y;
    int sum;
}point;
void merge(int A[],int p,int q,int r){
    int n1=q-p+1,n2=r-q;
    int L[n1],R[n2];
    for (int i=0;i<n1;i++){
        L[i]=A[p+i];
    }
    for (int i=0;i<n2;i++){
        R[i]=A[q+1+i];
    }
    int i=0,j=0,k=p;
    while (i<n1 && j<n2){
        if (L[i]<R[j]){
            A[k]=L[i];
            i++;
        }else {
            A[k]=R[j];
            j++;
        }
        k++;
    }
    while (i<n1){
        A[k]=L[i];
        i++;
        k++;
    }
    while (j<n2){
        A[k]=L[j];
        j++;
        k++;
    }
}
