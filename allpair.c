#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge {
    int src, dest, weight;
};


void printSolution(int **dist, int V) {
    printf("Shortest paths between all pairs of vertices:\n");
    printf(" \t"); 
    for (int j = 0; j < V; j++) {
        printf("%d\t", j + 1); 
    }
    printf("\n");

    for (int i = 0; i < V; i++) {
        printf("%d\t", i + 1);
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(struct Edge edges[], int V, int E) {
    int **dist = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        dist[i] = (int *)malloc(V * sizeof(int));
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < E; i++) {
        dist[edges[i].src][edges[i].dest] = edges[i].weight;
    }

    for (int i = 0; i < V; i++) {
        dist[i][i] = 0;
    }


    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printSolution(dist, V);
    for (int i = 0; i < V; i++) {
        free(dist[i]);
    }
    free(dist);
}

int main() {
    int V, E;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Edge edges[E];

    printf("Enter the edges in the format: source destination weight\n");
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &src, &dest, &weight);
        edges[i].src = src - 1; 
        edges[i].dest = dest - 1; 
        edges[i].weight = weight;
    }

    floydWarshall(edges, V, E);

    return 0;
}