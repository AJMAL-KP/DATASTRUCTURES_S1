#include<stdio.h>
#define MAX 10

int adj[MAX][MAX];
int queue[MAX];
int front=-1,rear=-1;
int visited[MAX];

void enqueue(int start){
        if(front==-1|| rear==-1){
            front++;
           
        }
        queue[++rear]=start;
}

int dequeue(){
    return queue[front++];
}

void BFS(int start,int vertices){
    int current;
    enqueue(start);
    visited[start]=1;
    while(front<=rear){
    current=dequeue();
    printf("%d ",current);

    for(int i=0;i<vertices;i++){
        if(adj[current][i] && !visited[i]){
            
            enqueue(i);
            visited[i]=1;
        }
    }
    }

    
}

int main(){
    int u,v,vertices,edges;

    printf("Enter the number of vertices. MAX=10");
    scanf("%d",&vertices);
    for(int i=0;i<vertices;i++){
        visited[i]=0;
        for(int j=0;j<vertices;j++){
            adj[i][j]=0;
        }
    }

    printf("Enter the number of edges.");
    scanf("%d",&edges);

    printf("Enter the adjacency");
    for(int i=0;i<edges;i++){
        scanf("%d %d",&u,&v);
        adj[u][v]=1;
        adj[v][u]=1;
    }

    for(int i=0;i<vertices;i++){
        if(!visited[i])
        BFS(i,vertices);
    }
}