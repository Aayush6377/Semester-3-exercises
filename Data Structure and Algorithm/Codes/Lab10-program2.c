//C program to create a graph using adjacency matrix and print its DFS
#include <stdio.h>
#include <stdlib.h>

struct graph{
    int vertex;
    int *labels;
    int **matrix;
};

struct graph* make(int vertex,int labels[]){
    struct graph* g=(struct graph*) malloc(sizeof(struct graph));
    g->vertex=vertex;
    g->labels=(int*)malloc(vertex*sizeof(int));
    g->matrix=(int**)malloc(vertex*sizeof(int *));
    for (int i=0;i<vertex;i++){
        g->labels[i]=labels[i];
        g->matrix[i]=(int*)malloc(vertex*sizeof(int));
    }

    for (int j=0;j<vertex;j++){
        for (int k=0;k<vertex;k++){
            g->matrix[j][k]=0;
        }
    }
    return g;
}

int search(int array[],int n,int key){
    for(int i=0;i<n;i++){
        if (array[i]==key){
            return i;
        }
    }
    return -1;
}

void add_edge(struct graph* g,int a,int b){
    int p=search(g->labels,g->vertex,a);
    int q=search(g->labels,g->vertex,b);
    g->matrix[p][q]=1;
    g->matrix[q][p]=1;
}

void DFS(struct graph* g,int start){
    int v=g->vertex;
    int stack[v],visited[v];
    int top=-1;

    for (int i=0;i<v;i++) visited[i]=0;
    int index=search(g->labels,v,start);
    stack[++top]=index;
    visited[index]=1;

    while(top!=-1){
        int cur=stack[top--];
        printf("%d ",g->labels[cur]);
        for (int j=0;j<v;j++){
            int nei=g->matrix[cur][j];
            if (nei==1 && visited[j]==0){
                visited[j]=1;
                stack[++top]=j;
            }
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
    printf("Enter starting node for DFS traversal: ");
    scanf("%d",&start);
    printf("DFS : ");
    DFS(g,start);
    return 0;
}