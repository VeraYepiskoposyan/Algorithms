#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (graph) {
        graph->V = V;
        graph->E = E;
        graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    }
    return graph;
}

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

int compare(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}

void KruskalMST(struct Graph* graph) {
    int V = graph->V;
    
    int e = 0; 
    int i = 0; 

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare);

    int* parent = (int*)malloc(V * sizeof(int));
    if (parent) {
        for (int v = 0; v < V; ++v)
            parent[v] = -1;
        struct Edge* result = malloc(V * sizeof(struct Edge));
        if (result) {
            while (e < V - 1 && i < graph->E) {
                struct Edge next_edge = graph->edge[i++];

                int x = find(parent, next_edge.src);
                int y = find(parent, next_edge.dest);


                if (x != y) {
                    result[e++] = next_edge;
                    Union(parent, x, y);
                }

            }

            printf("Following are the edges in the MST:\n");
            int minimumCost = 0;
            for (i = 0; i < e; ++i) {
                printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
                minimumCost += result[i].weight;
            }
            printf("Minimum Cost Spanning Tree: %d\n", minimumCost);
            free(result);
        }

    }
}



int testKruskal() {
    printf("\ntestKruskal...\n");
    int V = 4; 
    int E = 5; 
    struct Graph* graph = createGraph(V, E);

    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    KruskalMST(graph);

    return 0;
}
