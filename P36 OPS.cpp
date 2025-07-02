#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

int disk[SIZE];      
int start[10];      
int fileCount = 0;

void createFile(int blocks) {
    if (fileCount >= 10) {
        printf("Max file limit reached.\n");
        return;
    }

    int count = 0, prev = -1, first = -1;

    for (int i = 0; i < SIZE && count < blocks; i++) {
        if (disk[i] == -1) {
            if (first == -1) first = i;
            if (prev != -1) disk[prev] = i;
            prev = i;
            disk[i] = -2; 
            count++;
        }
    }

    if (count < blocks) {
        printf("Not enough space.\n");
        return;
    }

    start[fileCount++] = first;
    printf("File created. Start block: %d\n", first);
}

void displayFiles() {
    for (int i = 0; i < fileCount; i++) {
        int idx = start[i];
        printf("File %d blocks: ", i + 1);
        while (idx != -2) {
            printf("%d -> ", idx);
            int next = disk[idx];
            if (next == -2) {
                printf("END\n");
                break;
            }
            idx = next;
        }
    }
}

int main() {
    for (int i = 0; i < SIZE; i++) disk[i] = -1; 

    createFile(4);
    createFile(3);

    displayFiles();

    return 0;
}

