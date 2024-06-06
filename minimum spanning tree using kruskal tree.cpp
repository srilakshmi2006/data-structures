#include <stdio.h>
#include <stdlib.h>
#define V 5
#define INF 99999
struct Edge {
    int src, dest, weight;
};
struct Subset {
    int parent;
    int rank;
};
struct Edge* createGraph() {
    struct Edge* edge = (struct Edge*)malloc(V * sizeof(struct Edge));
    return edge;
}
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
int compare(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight - b1->weight;
}
void KruskalMST(struct Edge* edge) {
    struct Edge result[V];
    int e = 0; 
    int i = 0; 
    qsort(edge, V, sizeof(edge[0]), compare); 
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (e < V - 1) {
        struct Edge next_edge = edge[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
}
    printf("Edges in MST:\n");
    for (int i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
}
int main() {
    struct Edge* edge = createGraph();
    edge[0].src = 0;
    edge[0].dest = 1;
    edge[0].weight = 10;
    edge[1].src = 0;
    edge[1].dest = 2;
    edge[1].weight = 6;
    edge[2].src = 0;
    edge[2].dest = 3;
    edge[2].weight = 5;
    edge[3].src = 1;
    edge[3].dest = 3;
    edge[3].weight = 15;
    edge[4].src = 2;
    edge[4].dest = 3;
    edge[4].weight = 4;
    KruskalMST(edge);
    return 0;
}
