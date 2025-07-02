#include <stdio.h>

int main() {
    int n, f, i, j, k, page, found, faults = 0;
    
    printf("Enter number of pages: ");
    scanf("%d", &n);
    
    int pages[n];
    printf("Enter page numbers:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    
    printf("Enter number of frames: ");
    scanf("%d", &f);
    
    int frames[f];
    for (i = 0; i < f; i++)
        frames[i] = -1;
    
    printf("\nPage\tFrames\n");
    
    for (i = 0; i < n; i++) {
        page = pages[i];
        found = 0;
        
        for (j = 0; j < f; j++) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }
        
        if (!found) {
            int empty = -1;
            for (j = 0; j < f; j++) {
                if (frames[j] == -1) {
                    empty = j;
                    break;
                }
            }
            
            if (empty != -1) {
                frames[empty] = page;
            } else {
                int farthest = -1, pos = -1;
                for (j = 0; j < f; j++) {
                    int next_use = -1;
                    for (k = i + 1; k < n; k++) {
                        if (pages[k] == frames[j]) {
                            next_use = k;
                            break;
                        }
                    }
                    if (next_use == -1) {
                        pos = j;
                        break;
                    }
                    if (next_use > farthest) {
                        farthest = next_use;
                        pos = j;
                    }
                }
                frames[pos] = page;
            }
            faults++;
        }
        
        printf("%d\t", page);
        for (j = 0; j < f; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }
    
    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}

