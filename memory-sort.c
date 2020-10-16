#include <stdio.h>
#include <stdlib.h>
int max_arr(int *a,long long int n){  
	int m=*(a+0);           // func to find max in array 
	for (long long int i=0;i<n;i++){
		if (*(a+i)>m){
			m=*(a+i);
		}
	}return m;
}
int min_arr(int *a,long long int n){
	int m=*(a+0);
	for (long long int i=0;i<n;i++){
		if (*(a+i)<m){     // func to find min in aray 
			m=*(a+i);
		}
	}return m;
}
int main(){
	long long int n;
	printf("enter n:");
	scanf("%lld",&n);
	int *a=(int *)malloc(n*sizeof(int));
	for (long long int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	int max_val=max_arr(a,n);
	printf("max value is %d\n",max_val);
	int min_val=min_arr(a,n);     // to get the max and min values of the array 
	printf("min value is %d\n",min_val);
	for (long long int j=0;j<n;j++){
		*(a+j)-=min_val;      // to reduce each element by the min value of the array 
	}
	max_val-=min_val;
	int *arr=(int *)malloc(max_val*sizeof(int));
	for (int k=0;k<max_val;k++){
		*(arr+k)=0;          // assigned 0's at each in large memory array 
	}
	for (long long int l=0;l<n;l++){
		*(arr+*(a+l))+=1;  //this is the key step ; 
		                     // keeps 1 at each point of arr[a[l]] position 
	}
	for (int q=0;q<max_val;q++){
		if (*(arr+q)==1){
			printf("%d ",q+min_val); // this exibhits the values in sorted order 
		}else if (*(arr+q)>1){
			for (int s=0;s<*(arr+q);s++){
				printf("%d ",q+min_val);
			} 
		}
	}
    printf("%d",max_val+min_val);
	printf("\n");
    free(a);
    free(arr);
	return 0;
}
