#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main() {
    FILE *fp;
    char buffer[100];
    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    fp = fopen("shared.txt", "w");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }
    fprintf(fp, "Hello from parent process!");
    fclose(fp);
    if (!CreateProcess(NULL, "child_reader.exe", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        printf("CreateProcess failed (%lu).\n", GetLastError());
        return 1;
    }
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    printf("Parent process completed.\n");
    return 0;
}

