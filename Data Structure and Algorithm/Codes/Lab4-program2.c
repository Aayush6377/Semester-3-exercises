//Write a program to evaluate postfix expression
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
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

int solve(int a,int b, char ope){
    switch(ope){
        case '-':
           return b-a;
        case '+':
           return b+a;
        case '*':
        case 'x':
           return b*a;
        case '/':
           return b/a;
        case '^':
           return pow(b,a);
    }
}

int main(){
    char str[400];
    printf("Enter expression: ");
    gets(str);
    char postfix[2*strlen(str)+1];
    
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
                while(str[i+1]>='0' && str[i+1]<='9'){
                    postfix[u++]=str[++i];
                }
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
    
    //Postfix evaluation
    for (int i=0; i<strlen(postfix); i++){
        char sym=postfix[i];
        if (sym!=' '){
            if (precedence(sym)){
                int a=pop();
                int b=pop();
                push(solve(a,b,sym));
            }
            else{
                char temp[20];
                int u=0;
                while(postfix[i]!=' '){
                    temp[u++]=postfix[i++];
                }
                temp[u]='\0';
                push(atoi(temp));
            }
        }
    }
    
    int ans=pop();
    printf("Answer: %d",ans);
    return 0;
}
