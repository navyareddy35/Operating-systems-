#include <stdio.h>
#include <string.h>

int main() {
    int n, i, rec;
    printf("Enter number of records: ");
    scanf("%d", &n);
    
    char records[n][50];
    
    printf("Enter records (strings):\n");
    for (i = 0; i < n; i++) {
        printf("Record %d: ", i + 1);
        scanf("%s", records[i]);
    }
    
    printf("\nEnter record number to read (1 to %d): ", n);
    scanf("%d", &rec);
    
    if (rec < 1 || rec > n) {
        printf("Invalid record number!\n");
        return 0;
    }
    
    printf("\nReading records sequentially:\n");
    for (i = 0; i < rec; i++) {
        printf("Record %d: %s\n", i + 1, records[i]);
    }
    
    printf("\n=> Record %d accessed successfully!\n", rec);
    
    return 0;
}

