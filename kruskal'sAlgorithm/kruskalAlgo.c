#include <stdio.h>

#define MAX 10

struct Edge {
    int u, v, w;
};

int parent[MAX];


int find(int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}

void unionSet(int a, int b) {
    int x = find(a);
    int y = find(b);
    parent[y] = x;
}

void kruskal(int vertices, struct Edge edges[], int edgeCount) {

   
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j].w > edges[j+1].w) {
                struct Edge temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp;
            }
        }
    }

   
    for (int i = 0; i < vertices; i++)
        parent[i] = i;

    printf("\nEdge\tWeight\n");
    int edgesUsed = 0;

    for (int i = 0; i < edgeCount && edgesUsed < vertices - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

      
        if (find(u) != find(v)) {
            printf("%d - %d\t%d\n", u, v, edges[i].w);
            unionSet(u, v);
            edgesUsed++;
        }
    }
}

int main() {
    int vertices, edgesCount;

    printf("Enter number of vertices (max 10): ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edgesCount);

    struct Edge edges[50];

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < edgesCount; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    kruskal(vertices, edges, edgesCount);

    return 0;
}
