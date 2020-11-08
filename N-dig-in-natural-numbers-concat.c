#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int dig(int i,int r,int p){
    if (r==0){
        return i%10;
    }else {
        i++;
        i=i/((int)(pow(10,p)));
        i=i%10;
        return i;
    }
}
int main(){
    int N;
    printf("Enter the Number:");
    scanf("%d",&N);
    int k=1,p=0;
    while (N>k*9*pow(10,p)){
        N=N-k*9*pow(10,p);
        k++;
        p++;
    }
    int q=N/k,r=N%k;
    int i=(int)pow(10,p)+q;
    printf("%d\n",dig(i,r,p));
    return 0;
}
