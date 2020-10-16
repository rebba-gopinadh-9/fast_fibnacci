#include <stdio.h>
#include <time.h>
#include <math.h>
int main(){
    clock_t start,end;
    float a,b,n;
    printf("enter the number for SQRT :");
    scanf("%f",&n);         //takes input for the number .
    for (int i=0;1;i++){
        if (i*i>n){
            a=i-1;
            b=i;
            break;
        } // finds the nearest integers i,e  (i-1)*(i-1) < n < i*i
    }
    float p=0.01;
    start=clock();
    while(fabs(b*b-n)>p || fabs(n-a*a)>p){
        if (((a+b)/2)*((a+b)/2)>n){
            a=a;
            b=(a+b)/2;
        }else{
            a=(a+b)/2;
            b=b;
        }        // this is the logic (write it on paper and see .)
    }
    end=clock();
    printf("%f %f\n",a,b);
    printf("%f %f\n",a*a,b*b);
    if (fabs(n-a*a)>fabs(n-b*b)){
        printf("square root is close to : %f\n",b);
    }else{
        printf("square root is close to : %f\n",a);
    }
    //printf("~ ~ ~ ~ Time : %f~ ~ ~ ~ ~ ~\n",(float)((end-start)/CLOCKS_PER_SEC));
    return 0;
} 
