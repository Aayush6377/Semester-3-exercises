//Write a program to convert infix expression to postfix expression
#include <stdio.h>
#include <string.h>
#define Max 50

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

int pop(){
    if (top==-1){
        printf("Stack underflow\n");
    }
    int r=stack[top];
    top--;
    return r;
}

int isempty(){
    if (top==-1) return 1;
    else return 0;
}

int peek(){
    if (isempty()){
        printf("Stack underflow\n");
    }
    else{
        return stack[top];
    }
}

int precedence(char ope){
    switch(ope){
        case '-':
            return 1;
        case '+':
            return 2;
        case '*':
        case 'x':
            return 3;
        case '/':
            return 4;
        case '^':
            return 5;
        default:
            return 0;
    }
}

int main(){
    char str[400];
    printf("Enter expression: ");
    gets(str);
    char postfix[strlen(str)+1];
    
    int u=0;
    for (int i=0; i<strlen(str); i++){
        char sym=str[i];
        if (sym!=' '){
            if (sym=='[' || sym=='{' || sym=='('){
                push('(');
            }
            else if (sym==']' || sym=='}' || sym==')'){
                while(peek()!='('){
                    postfix[u++]=pop();
                    postfix[u++]=' ';
                }
                pop();
            }
            else if (precedence(sym)){
                while (!isempty() && precedence(peek())>precedence(sym)){
                    postfix[u++]=pop();
                    postfix[u++]=' ';
                }
                push(sym);
            }
            else{
                postfix[u++]=sym;
                postfix[u++]=' ';
            }
        }
    }
    
    while(!isempty()){
        postfix[u++]=pop();
        postfix[u++]=' ';
    }
    postfix[u]='\0';
    
    printf("Postfix: %s\n",postfix);
    return 0;
}
