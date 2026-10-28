#include <stdio.h>
#define MAX 20
int adj[MAX][MAX], visited[MAX], n;
void bfs(int start) {
    int queue[MAX], front = 0, rear = 0, seen[MAX] = {0}; seen[start] = 1; queue[rear++] = start;
    printf("BFS traversal: ");
    while (front < rear) { int v = queue[front++]; printf("%d ", v); for (int i = 0; i < n; i++) if (adj[v][i] && !seen[i]) { seen[i] = 1; queue[rear++] = i; } }
    printf("\n");
}
void dfsVisit(int v) { visited[v] = 1; printf("%d ", v); for (int i = 0; i < n; i++) if (adj[v][i] && !visited[i]) dfsVisit(i); }
void dfs(int start) { for (int i = 0; i < n; i++) visited[i] = 0; printf("DFS traversal: "); dfsVisit(start); printf("\n"); }
int main(void) {
    int edges, u, v, start;
    printf("Enter number of vertices: "); if (scanf("%d", &n) != 1 || n < 1 || n > MAX) { printf("Invalid number of vertices.\n"); return 1; }
    printf("Enter number of edges: "); if (scanf("%d", &edges) != 1 || edges < 0 || edges > n * (n - 1) / 2) { printf("Invalid number of edges.\n"); return 1; }
    printf("Enter edges (u v), vertices numbered 0 to %d:\n", n - 1);
    for (int i = 0; i < edges; i++) { if (scanf("%d %d", &u, &v) != 2 || u < 0 || u >= n || v < 0 || v >= n) { printf("Invalid edge.\n"); return 1; } adj[u][v] = adj[v][u] = 1; }
    printf("Enter starting vertex: "); if (scanf("%d", &start) != 1 || start < 0 || start >= n) { printf("Invalid starting vertex.\n"); return 1; }
    bfs(start); dfs(start); return 0;
}
