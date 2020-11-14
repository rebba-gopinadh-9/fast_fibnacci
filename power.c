#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long long int iter(int a,int n){
    int k=1;
    for (int i=0;i<n;i++){
        k=k*a;
    }
    return k;
}
long long int power(int a,int n){
    if (return n==0){
        return 1;
    }
    if (n==1){
        return a;
    }
    if (n%2==0){
        return power(a,n/2)*power(a,n/2);
    }else {
        return power(a,n/2)*power(a,n/2)*a;
    }
}
int main(){
    clock_t s,e,S,E;
    s=clock();
    long long int k=iter(2,20);
    printf("val :%lld\n",k);
    e=clock();
    printf("T:%f\n",(float)(e-s)/CLOCKS_PER_SEC);
    S=clock();
    k=power(2,20);
    printf("val :%lld\n",k);
    E=clock();
    printf("T:%f\n",((float)(E-S))/CLOCKS_PER_SEC);
    return 0;
}
