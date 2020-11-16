#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int x;
    int y;
}point;
void merge(point A[],int p,int q,int r){
    int n1=q-p+1,n2=r-q;
    point L[n1],R[n2];
    for (int i=0;i<n1;i++){
        L[i]=A[p+i];
    }
    for (int i=0;i<n2;i++){
        R[i]=A[q+1+i];
    }
    int i=0,j=0,k=p;
    while (i<n1 && j<n2){
        if ((L[i].x+L[i].y)<(R[j].y+R[j].x)){
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
void heap_sort(int A[],int n){
    for (int i=n/2-1;i>=0;i--){
        max_heapify(A,n,i);
    }
    for (int i=n-1;i>0;i--){
        swap(&A[0],&A[i]);
        max_heapify(A,i,0);
    }
}
void Sort(int A[],int B[],int n){
    heap_sort(A,n);
    heap_sort(B,n);
    point S[n*n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            S[n*i+j].x=A[i];
            S[n*i+j].y=B[j];
        }
    }
    for (int i=1;i<n;i++){
        merge(S,0,i*n-1,(i+1)*n-1);
    }
    for (int i=0;i<n*n;i++){
        printf("%d  : %d %d Sum:%d\n",i,S[i].x,S[i].y,S[i].x+S[i].y);
    }
}

int main(){
    int A[]={1,2,9};
    int B[]={2,4,6};
    Sort(A,B,3);
    return 0;
}
