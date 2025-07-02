#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[100], n, head, size, i, j, total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter requests: ");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &size);

    
    req[n++] = head;
    req[n++] = 0;
    req[n++] = size - 1;

    
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (req[i] > req[j]) {
                int temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }

   
    for (i = 0; i < n; i++)
        if (req[i] == head) break;

    printf("\nSeek sequence: ");
    for (j = i; j < n - 1; j++) {
        printf("%d -> ", req[j]);
        total += abs(req[j+1] - req[j]);
    }
    printf("%d -> ", req[n - 1]);

    total += abs(req[n - 1] - req[0]);
    printf("%d", req[0]);

    for (j = 0; j < i - 1; j++) {
        printf(" -> %d", req[j+1]);
        total += abs(req[j+1] - req[j]);
    }

    printf("\nTotal head movement: %d\n", total);
    return 0;
}

