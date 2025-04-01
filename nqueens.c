#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x[100];  
int place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return 0; 
        }
    }
    return 1; 
}


void nqueens(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {  
            x[k] = i;  
            if (k == n) { 
                for (int j = 1; j <= n; j++) {
                    printf("%d ", x[j]);
                }
                printf("\n");
            } else {
                nqueens(k + 1, n);  
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the value of n (size of the chessboard): ");
    scanf("%d", &n);
    nqueens(1, n);

    return 0;
}