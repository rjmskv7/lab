#include <stdio.h>
#include <stdlib.h>

struct tree_node {
    struct tree_node *lchild;
    struct tree_node *rchild;
    int weight;  
};

typedef struct tree_node TreeNode;

TreeNode* createNode(int weight) {
    TreeNode *node = (TreeNode*) malloc(sizeof(TreeNode));
    node->lchild = node->rchild = NULL;
    node->weight = weight;
    return node;
}

TreeNode* least(TreeNode* list[], int *size) {
    int minIndex = 0;
    for (int i = 1; i < *size; i++) {
        if (list[i]->weight < list[minIndex]->weight) {
            minIndex = i;
        }
    }
    TreeNode* minNode = list[minIndex];

    for (int i = minIndex; i < *size - 1; i++) {
        list[i] = list[i + 1];
    }
    (*size)--;

    return minNode;
}


void insert(TreeNode* list[], int *size, TreeNode* node) {
    list[*size] = node;
    (*size)++;
}

TreeNode* optimalMergePattern(int files[], int n, int *totalMoves, int *totalSum) {
  
    TreeNode* list[n];
    for (int i = 0; i < n; i++) {
        list[i] = createNode(files[i]);
    }

    int size = n;

 
    for (int i = 1; i < n; i++) {
        TreeNode* pt = (TreeNode*) malloc(sizeof(TreeNode));

        pt->lchild = least(list, &size);
        pt->rchild = least(list, &size);

        pt->weight = pt->lchild->weight + pt->rchild->weight;

        
        insert(list, &size, pt);

       
        (*totalMoves)++;

        (*totalSum) += pt->weight;

        printf("Merge move %d: New root weight = %d\n", *totalMoves, pt->weight);
    }


    return least(list, &size);
}

int main() {
    int n;

    printf("Enter the number of files: ");
    scanf("%d", &n);

    int* files = (int*) malloc(n * sizeof(int));

    printf("Enter the sizes of the %d files:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &files[i]);
    }

    int totalMoves = 0; 
    int totalSum = 0;   

   
    TreeNode* root = optimalMergePattern(files, n, &totalMoves, &totalSum);

   
    printf("\nOptimal merge completed with final root weight: %d\n", root->weight);
    printf("Total number of merge moves: %d\n", totalMoves);
    printf("Total sum of all root weights during merges: %d\n", totalSum);


    free(files);

    return 0;
}