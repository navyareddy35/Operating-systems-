#include <stdio.h>

int main() {
    int n, f, i, j, page, found, pos = 0, faults = 0;
    
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
            frames[pos] = page;
            pos = (pos + 1) % f;
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

