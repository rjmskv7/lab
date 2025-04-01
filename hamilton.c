#include <stdio.h>
#define MAX 10

int n, G[MAX][MAX], x[MAX];

void NextValue(int k) {
    do {
        x[k] = (x[k] + 1) % (n + 1); 
        if (x[k] == 0) return;
        if (G[x[k - 1]][x[k]] != 0) { 
            int j;
            for (j = 1; j < k; j++)
                if (x[j] == x[k]) break;
            if (j == k) {
                if (k < n || (k == n && G[x[n]][x[1]] != 0)) return;
            }
        }
    } while (1);
}

void Hamiltonian(int k) {
    do {
        NextValue(k);
        if (x[k] == 0) return;
        if (k == n) {
            for (int i = 1; i <= n; i++)
                printf("%d ", x[i]);
            printf("%d\n", x[1]);
        } else {
            Hamiltonian(k + 1);
        }
    } while (1);
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
   
    printf("Enter adjacency matrix:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &G[i][j]);
   
    for (int i = 1; i <= n; i++)
        x[i] = 0;
   
    x[1] = 1;
   
    printf("Hamiltonian Cycles in the given graph:\n");
    Hamiltonian(2);
   
    return 0;
}