#include <stdio.h>
#include<math.h>
#include <time.h>
int fib(float k){
    int l=k;
    if (k==1 || k==2){
        return 1;
    }else if (l%2 ==0){
        return (fib(k/2 +1)*fib(k/2 +1)-fib(k/2 -1)*fib(k/2 -1));
    }else {
        return (fib((k+1)/2)*fib((k+1)/2)+fib((k-1)/2)*fib((k-1)/2));
    }
}
int fib_normal(float n){
    if (n==1 || n==2){
        return 1;
    }else {
        return fib_normal(n-1)+fib_normal(n-2);
    }
}
int main(){
    clock_t s1,e1,s2,e2;
    float n;
    printf("enter the number here :");
    scanf("%f",&n);
    s1=clock();
    printf("value due to special fib function is:%d\n",fib((int)n));
    e1=clock();
    printf("the time taken is : %f\n",(float)(e1-s1)/CLOCKS_PER_SEC);
    s2=clock();
    printf("value due to normal fib function is:%d\n",fib_normal((int)n));
    e2=clock();
    printf("the time taken is : %f\n",(float)((e2-s2)/CLOCKS_PER_SEC));
    return 0;
}
