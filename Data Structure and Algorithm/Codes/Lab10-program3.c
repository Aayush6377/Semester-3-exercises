//C program to create a graph and find its minimum spanning tree using Prism's algorithm
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node{
    int data;
    int weight;
    struct node* next;
};

struct graph{
    int vertex;
    int *labels;
    struct node** list;
};

struct node* create(int data,int weight){
    struct node* temp=(struct node*) malloc(sizeof(struct node));
    temp->data=data;
    temp->weight=weight;
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

void add_edge(struct graph* g,int a,int b,int w){
    int p=search(g->labels,g->vertex,a);
    int q=search(g->labels,g->vertex,b);

    struct node* temp=create(b,w);
    temp->next=g->list[p];
    g->list[p]=temp;

    temp=create(a,w);
    temp->next=g->list[q];
    g->list[q]=temp;
}

int findmin(int key[],int mst[],int v){
    int min=INT_MAX;
    int index;
    for (int i=0;i<v;i++){
        if (mst[i]==0 && min>key[i]){
            min=key[i];
            index=i;
        }
    }
    return index;
}

void prism(struct graph* g){
    int v=g->vertex;
    int parent[v],mst[v],key[v];

    for (int i=0;i<v;i++){
        parent[i]=-1;
        key[i]=INT_MAX;
        mst[i]=0;
    }

    key[0]=0;

    for (int j=0;j<v-1;j++){
        int cur=findmin(key,mst,v);
        mst[cur]=1;

        struct node* temp=g->list[cur];
        while(temp!=NULL){
            int nei=search(g->labels,v,temp->data);
            if (mst[nei]==0 && temp->weight < key[nei]){
                key[nei]=temp->weight;
                parent[nei]=g->labels[cur];
            }
            temp=temp->next;
        }
    }
    
    printf("Edges  Weight\n");
    for (int k=1;k<v;k++){
        printf("%d - %d : %d\n",parent[k],g->labels[k],key[k]);
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
        int a,b,w;
        printf("Enter %d edge: ",j+1);
        scanf("%d %d %d",&a,&b,&w);
        add_edge(g,a,b,w);
    }
    printf("Minimum spanning tree of the graph is\n");
    prism(g);
    return 0;
}