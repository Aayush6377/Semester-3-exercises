//Write a program to implement Binary search
#include <stdio.h>
//Binary search
int Binary(int arr[],int ele,int l, int h){
    if (l>h){
        return -1;
    }
    int mid=(l+h)/2;
    if (arr[mid]==ele){
        return mid;
    }
    else if (arr[mid]>ele){
        return Binary(arr,ele,l,mid-1);
    }
    else{
        return Binary(arr,ele,mid+1,h);
    }
}
int main(){
    int n;
    printf("Enter no. of elements: ");
    scanf("%d",&n);
    printf("Enter a sorted array: ");
    int array[n];
    for (int i=0; i<n; i++){
        scanf("%d",&array[i]);
    }
    //Binary search
    int element;
    printf("Enter the searching element: ");
    scanf("%d",&element);
    
    int index=Binary(array,element,0,n-1);
    if (index==-1){
        printf("Element not found\n");
    }
    else{
        printf("Index: %d\n",index);
        printf("Position: %d\n",index+1);
    }
    return 0;
}
