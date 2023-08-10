/*Write a program to create a function push which insert elements into the stack*/
#include <stdio.h>
#define Max 5

int stack[Max];
int top=-1;

void push(int data){
    if (top==Max-1){
        printf("Stack overflow\n");
        return;
    }
    top++;
    stack[top]=data;
}

int main(){
    while(top!=Max-1){
        int val;
        printf("Enter value: ");
        scanf("%d",&val);
        push(val);
    }
    printf("Stack form:\n");
    
    for (int i=top; i>=0; i--){
        printf("| %d |\n",stack[i]);
    }
    return 0;
}