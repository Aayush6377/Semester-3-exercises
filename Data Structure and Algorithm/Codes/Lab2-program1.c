//Write a program to implement linear search
#include <stdio.h>
int main(){
    int n;
    printf("Enter no. of elements: ");
    scanf("%d",&n);
    printf("Enter array: ");
    int array[n];
    for (int i=0; i<n; i++){
        scanf("%d",&array[i]);
    }
    //Linear search
    int element,index=-1;
    printf("Enter the searching element: ");
    scanf("%d",&element);
    for (int i=0; i<n;i++){
        if (array[i]==element){
           index=i;
        }
    }
    if (index==-1){
        printf("Element not found\n");
    }
    else{
        printf("Index: %d\n",index);
        printf("Position: %d\n",index+1);
    }
    return 0;
}
