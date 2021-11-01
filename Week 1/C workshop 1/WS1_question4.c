#include<stdio.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void main(){
    int a,b;
    printf("Enter the value of a and b respectively:");
    scanf("%d%d",&a,&b);
    swap(&a,&b);
    printf("After swaping the value:\n");
    printf("A:%d\tB:%d",a,b);
}