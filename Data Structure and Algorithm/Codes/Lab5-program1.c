/*Implement Queues and apply following operations
a) Create
b) Insert
c) Delete*/
#include <stdio.h>
#define Max 5

//Create
int Queue[Max];
int front=-1,rear=-1;

//Insert
void enqueue(int data){
    if (rear==Max-1){
        printf("Queue overflow");
        return;
    }
    if (front==-1){
        front=0;
    }
    rear++;
    Queue[rear]=data;
}

//Delete
int dequeue(){
    if (front==-1){
        printf("Queue underflow\n");
    }
    else{
        int temp=Queue[front];
        if (front==rear){
            front=rear=-1;
        }
        else{
            front++;
        }
        return temp;
    }
}

//Print
void print_queue(){
    if (front==-1){
        printf("Queue underflow\n");
        return;
    }
    for (int i=front; i<=rear; i++){
        printf("| %d ",Queue[i]);
    }
    printf("|\n");
}


int main(){
    printf("Operation:\n");
    printf("1) Enqueue\n");
    printf("2) Dequeue\n");
    printf("3) Print\n");
    printf("4) Quit\n");
    
    task=0;
    while(task!=4){
        printf("Enter task: ");
        scanf("%d",&task);
        switch(task){
            
        }
    }
    return 0;
}
