#include <windows.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "child") == 0) {
        printf("Child Process:\n");
        printf("Process ID: %lu\n", GetCurrentProcessId());
        printf("Note: Windows does not directly support getppid()\n");
    } else {
        STARTUPINFO si = { sizeof(si) };
        PROCESS_INFORMATION pi;


        if (!CreateProcess(NULL, "process.exe child", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
            printf("CreateProcess failed (%lu).\n", GetLastError());
            return 1;
        }

        printf("Parent Process:\n");
        printf("Process ID: %lu\n", GetCurrentProcessId());

        
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }

    return 0;
}

