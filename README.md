#include <stdio.h>
#include<math.h>
#include <string.h>
float fib(float k){
    int l=k;
    if (k==1 || k==2){
        return 1;
    }else if (l%2 ==0){
        return (fib(k/2 +1)*fib(k/2 +1)-fib(k/2 -1)*fib(k/2 -1));
    }else {
        return (fib((k+1)/2)*fib((k+1)/2)+fib((k-1)/2)*fib((k-1)/2));
    }
}
int fib_normal(int n){
    if (n==1 || n==2){
        return 1;
    }else {
        return fib_normal(n-1)+fib_normal(n-2);
    }
}
int main(){
    float n;
    printf("enter the number here :");
    scanf("%f",&n);
    int k=n;
    printf("value due to special fib function is:%f\n",fib(k));
    printf("value due to normal fib function is:%d\n",fib_normal(k));
    return 0;
}
