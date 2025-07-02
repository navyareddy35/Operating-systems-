#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[100], n, head, i, j, total = 0, size, dir;

    printf("Enter number of requests: ");
    scanf("%d", &n);
    printf("Enter requests: ");
    for (i = 0; i < n; i++) scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);
    printf("Enter disk size: ");
    scanf("%d", &size);
    printf("Enter direction (0 = left, 1 = right): ");
    scanf("%d", &dir);

    
    req[n++] = head;
    if (dir == 0) req[n++] = 0;
    else req[n++] = size - 1;

    
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (req[i] > req[j]) {
                int temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }

    
    for (i = 0; i < n; i++)
        if (req[i] == head) break;

    printf("\nSeek sequence:\n");

    if (dir == 1) {
        for (j = i; j < n; j++) {
            printf("%d ", req[j]);
            if (j > i) total += abs(req[j] - req[j - 1]);
        }
        for (j = i - 1; j >= 0; j--) {
            printf("%d ", req[j]);
            total += abs(req[j + 1] - req[j]);
        }
    } else {
        for (j = i; j >= 0; j--) {
            printf("%d ", req[j]);
            if (j < i) total += abs(req[j] - req[j + 1]);
        }
        for (j = i + 1; j < n; j++) {
            printf("%d ", req[j]);
            total += abs(req[j] - req[j - 1]);
        }
    }

    printf("\nTotal head movement: %d\n", total);
    return 0;
}

