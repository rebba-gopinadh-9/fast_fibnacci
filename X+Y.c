#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int x;
    int y;
    int sum;
}point;
void merge(int A[],int p,int q,int r){             //just to merge the the lines of the matrix so formed.
    int n1=q-p+1,n2=r-q;                           //changes have to done .
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
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void max_heapify(int A[],int n,int i){
    int left=2*i+1;
    int right=2*i+2;
    int large=i;
    if (A[left]>A[large] && left<n){
        large=left;
    }
    if (A[right]>A[large] && right <n){
        large=right;
    }
    if (large!=i){
        swap(&A[large],&A[i]);
        max_heapify(A,n,large);
    }
}
void heap_sort(int A[],int n){                     //heap sort for sorting the X & Y seperately to have O(lg n) time
     for (int i=n/2-1;i>=0;i--){
        max_heapify(A,n,i);
    }
    for (int i=n-1;i>0;i--){
        swap(&A[0],&A[i]);
        max_heapify(A,i,0);
    }
}
