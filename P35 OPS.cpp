#include <stdio.h>

int main() {
    int n, i, block;
    
    printf("Enter number of blocks in the file: ");
    scanf("%d", &n);
    
    int indexBlock[n];
    
    printf("Enter block numbers for file blocks:\n");
    for (i = 0; i < n; i++) {
        printf("Block for file block %d: ", i);
        scanf("%d", &indexBlock[i]);
    }
    
    printf("\nIndex Block Contents:\n");
    for (i = 0; i < n; i++) {
        printf("Index [%d] -> Block %d\n", i, indexBlock[i]);
    }
    
    printf("\nEnter block number of file to access (0 to %d): ", n - 1);
    scanf("%d", &block);
    
    if (block < 0 || block >= n) {
        printf("Invalid block number!\n");
    } else {
        printf("Accessing File Block %d stored at Disk Block %d\n", block, indexBlock[block]);
    }
    
    return 0;
}

