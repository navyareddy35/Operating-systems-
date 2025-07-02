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
    int time[f];     
    
    for (i = 0; i < f; i++) {
        frames[i] = -1;
        time[i] = 0;
    }
    
    printf("\nPage\tFrames\n");
    
    for (i = 0; i < n; i++) {
        page = pages[i];
        found = 0;
        
        
        for (j = 0; j < f; j++) {
            if (frames[j] == page) {
                found = 1;
                time[j] = i; 
                break;
            }
        }
        
        if (!found) {
            int pos = 0;
            int min = time[0];
            
            for (j = 1; j < f; j++) {
                if (time[j] < min) {
                    min = time[j];
                    pos = j;
                }
            }
            
            frames[pos] = page;
            time[pos] = i;
            faults++;
        }
        
        printf("%d\t", page);
        for (k = 0; k < f; k++) {
            if (frames[k] != -1)
                printf("%d ", frames[k]);
            else
                printf("- ");
        }
        printf("\n");
    }
    
    printf("\nTotal Page Faults = %d\n", faults);
    
    return 0;
}

