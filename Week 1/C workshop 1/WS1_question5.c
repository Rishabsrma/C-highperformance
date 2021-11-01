#include<stdio.h>
#include<stdlib.h>

void main(){
    int n,i; // n is number of items
    int *p;  //pointer variable
    printf("Enter a number between 1 to 50:");
    scanf("%d",&n);
    p = (int*)malloc(n * sizeof(int));
    for(i=0;i<n;i++){
        *(p+i) = rand();
    }
    for ( i = 0; i < n; i++)
    {
       printf("%d\n",*(p+i));
    }
    
}