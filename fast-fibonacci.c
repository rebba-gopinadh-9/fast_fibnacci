#include <stdio.h>
#include<math.h>
long long int fib(long k){
    if (k==1 || k==2){
        return 1;
    }else if (k%2 ==0){
        return (fib(k/2 +1)*fib(k/2 +1)-fib(k/2 -1)*fib(k/2 -1));
    }else {
        return (fib((k+1)/2)*fib((k+1)/2)+fib((k-1)/2)*fib((k-1)/2));
    }
}
int main(){
    long int n;
    scanf("%ld",&n);
    printf("f%ld:%lld\n",n,fib(n));
    return 0;
}
