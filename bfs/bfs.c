#include <stdio.h>

#define MAX 10  // maximum number of vertices (nodes)

// adjacency matrix to store the graph
int adj[MAX][MAX];

// an array to remember if we already visited a node
int visited[MAX];

// a queue for BFS
int queue[MAX];
int front = 0, rear = 0;  // pointers for our queue

// add (enqueue) a node into the queue
void enqueue(int value) {
    queue[rear++] = value;
}

// remove (dequeue) a node from the queue
int dequeue() {
    return queue[front++];
}

// check if the queue is empty
int isEmpty() {
    return front == rear;
}

// BFS function
void bfs(int start, int vertices) {
    // mark all nodes as unvisited at the start
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;

    printf("\nBFS starting from node %d:\n", start);

    // start BFS from the starting node
    visited[start] = 1;    // mark it visited
    enqueue(start);        // put it in the queue

    // keep going while there are nodes in the queue
    while (!isEmpty()) {
        int current = dequeue();  // take one out
        printf("%d ", current);   // print it (we're visiting it!)

        // look at all neighbors of the current node
        for (int i = 0; i < vertices; i++) {
            // if there's a connection and not visited yet
            if (adj[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;   // mark visited
                enqueue(i);       // add to the queue
            }
        }
    }

    printf("\n");
}

int main() {
    int vertices, edges;
    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d", &vertices);

    // set all connections to 0 (no edges yet)
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            adj[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter each edge (u v) — 0-based vertices:\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;  
        adj[v][u] = 1;  
    }

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(start, vertices);

    return 0;
}
