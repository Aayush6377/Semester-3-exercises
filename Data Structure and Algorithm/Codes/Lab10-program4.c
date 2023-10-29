//C program to create a graph and find its minimum spanning tree using Kruskal's algorithm
#include <stdio.h>
#include <stdlib.h>

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

struct edge{
    int scr,des,wei;
};

int compare(const void *a,const void *b){
    return ((struct edge*)a)->wei - ((struct edge*)b)->wei;
}

int find(int parent[],int key){
    if (parent[key]==-1){
        return key;
    }
    return parent[key]=find(parent,parent[key]);
}

void uniset(int parent[],int x,int y){
    int a=find(parent,x);
    int b=find(parent,y);
    parent[a]=b;
}

void kruskal(struct graph* g){
    int v=g->vertex;
    struct edge* ed=(struct edge*)malloc(sizeof(struct edge)*v*v);
    int count=0,parent[v];

    for (int i=0;i<v;i++){
        parent[i]=-1;
        struct node* temp=g->list[i];
        while(temp!=NULL){
            ed[count].scr=g->labels[i];
            ed[count].des=temp->data;
            ed[count++].wei=temp->weight;
            temp=temp->next;
        }
    }

    qsort(ed,count,sizeof(struct edge),compare);

    struct edge result[v-1];
    int e=0;

    for (int j=0;j<count;j++){
        int x=find(parent,search(g->labels,v,ed[j].scr));
        int y=find(parent,search(g->labels,v,ed[j].des));

        if (x!=y){
            result[e++]=ed[j];
            uniset(parent,x,y);
        }
    }
    printf("Edges  Weight\n");
    for(int k=0;k<e;k++){
        printf("%d - %d : %d\n",result[k].scr,result[k].des,result[k].wei);
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
    kruskal(g);
    return 0;
}