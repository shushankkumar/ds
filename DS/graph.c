//Program: 13 Write a program to create a graph in a adjacency list
//structure traverse it in
//a. DFS b. BFS
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
// Graph structure
struct Graph
{
int numVertices;
int adjList[MAX_VERTICES][MAX_VERTICES]; // Adjacency list
//represented as an array
int visited[MAX_VERTICES];
} Graph;
// Function prototypes
void createGraph(struct Graph* graph, int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void DFS(struct Graph* graph, int vertex);
void BFS(struct Graph* graph, int startVertex);
void resetVisited(struct Graph* graph);
// Create a graph with the given number of vertices
void createGraph(struct Graph* graph, int vertices)
{
graph->numVertices = vertices;
for (int i = 0; i < vertices; i++)
{
for (int j = 0; j < vertices; j++)
graph->adjList[i][j] = 0;
graph->visited[i] = 0;
}
}
// Add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest)
{
graph->adjList[src][dest] = 1;
graph->adjList[dest][src] = 1; // For undirected graph
}
// Depth First Search (DFS)
void DFS(struct Graph* graph, int vertex)
{
graph->visited[vertex] = 1;
printf("%d ", vertex);
for (int i = 0; i < graph->numVertices; i++)
{
if (graph->adjList[vertex][i] == 1 && !graph->visited[i])
DFS(graph, i);
}
}
// Breadth First Search (BFS)
void BFS(struct Graph* graph, int startVertex)
{
int queue[MAX_VERTICES];
int front = 0, rear = 0;
graph->visited[startVertex] = 1;
queue[rear++] = startVertex;
while (front < rear)
{
int curVertex = queue[front++];
printf("%d ", curVertex );
for (int i = 0; i < graph->numVertices; i++)
{
if (graph->adjList[curVertex][i]==1 && !graph->
visited[i])
{
graph->visited[i] = 1;
queue[rear++] = i;
}
}
}
}
// Reset visited array for reuse
void resetVisited(struct Graph* graph)
{
for (int i = 0; i < graph->numVertices; i++)
graph->visited[i] = 0;
}
// Main function
int main()
{
struct Graph graph;
int vertices = 6; // Number of vertices
createGraph(&graph, vertices);
addEdge(&graph, 0, 1);
addEdge(&graph, 0, 2);
addEdge(&graph, 1, 3);
addEdge(&graph, 1, 4);
addEdge(&graph, 2, 4);
addEdge(&graph, 3, 5);
addEdge(&graph, 4, 5);
printf("DFS traversal starting from vertex 0:\n");
DFS(&graph, 0);
printf("\n");
resetVisited(&graph);
printf("BFS traversal starting from vertex 0:\n");
BFS(&graph, 0);
printf("\n");
return 0;
}