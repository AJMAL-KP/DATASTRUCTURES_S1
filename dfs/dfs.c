#include<stdio.h>
#define MAX 10

int adj[MAX][MAX];
int stack[MAX];
int top=-1;
int visited[MAX];

void push(int start){
        if(top==MAX-1){
            printf("limit exceeded");
           
        }
        top++;
        stack[top]=start;
}

int pop(){
    if(top>-1){
        int v=stack[top];
        top--;
        return v;
    }
    return;
}


void DFS(int start,int vertices){
    int current;
    push(start);
    
    while(top>-1){
    current=pop();
    
    if(!visited[current]){
        visited[current]=1;
        printf("%d ",current);
    }

    for(int i=vertices-1;i>=0;i--){
        if(adj[current][i] && !visited[i]){
            // visited[i]=1;
            push(i);
            
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
        DFS(i,vertices);
    }
}