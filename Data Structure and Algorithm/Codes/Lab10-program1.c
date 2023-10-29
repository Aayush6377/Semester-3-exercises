//C program to create a graph using adjacency list and print its BFS
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct graph{
    int vertex;
    int *labels;
    struct node** list;
};

struct node* create(int data){
    struct node* temp=(struct node*) malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}

struct graph* make(int vertex,int labels[]){
    struct graph* g=(struct graph*)malloc(sizeof(struct graph));
    g->vertex=vertex;
    g->labels=(int *)malloc(sizeof(int)*vertex);
    g->list=(struct node**)malloc(sizeof(struct node*)*vertex);
    for (int i=0;i<vertex;i++){
        g->labels[i]=labels[i];
        g->list[i]=NULL;
    }
    return g;
}

int search(int array[],int n,int key){
    for (int i=0;i<n;i++){
        if (key==array[i]) return i;
    }
    return -1;
}

void add_edge(struct graph* g,int a,int b){
    int p=search(g->labels,g->vertex,a);
    int q=search(g->labels,g->vertex,b);

    struct node* temp=create(b);
    temp->next=g->list[p];
    g->list[p]=temp;

    temp=create(a);
    temp->next=g->list[q];
    g->list[q]=temp;
}

void BFS(struct graph* g,int start){
    int v=g->vertex;
    int queue[v],visited[v];
    int front=-1,rear=-1;

    for (int i=0;i<v;i++) visited[i]=0;
    int index=search(g->labels,v,start);
    queue[++rear]=index;
    visited[index]=1;

    while(front!=rear){
        int cur=queue[++front];
        printf("%d ",g->labels[cur]);

        struct node* temp=g->list[cur];
        while(temp!=NULL){
            int nei=search(g->labels,v,temp->data);
            if (visited[nei]==0){
                queue[++rear]=nei;
                visited[nei]=1;
            }
            temp=temp->next;
        }
    }
}

int main(){
    int v,e,start;
    printf("Enter vertex and edges: ");
    scanf("%d %d",&v,&e);
    int labels[v];
    printf("Enter labels: ");
    for (int i=0;i<v;i++) scanf("%d",&labels[i]);

    struct graph* g=make(v,labels);
    for (int j=0;j<e;j++){
        int a,b;
        printf("Enter %d edge: ",j+1);
        scanf("%d %d",&a,&b);
        add_edge(g,a,b);
    }
    printf("Graph Created!!!\n");
    printf("Enter starting node for BFS traversal: ");
    scanf("%d",&start);
    printf("BFS : ");
    BFS(g,start);
    return 0;
}