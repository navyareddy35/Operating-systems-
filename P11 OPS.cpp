#include <windows.h>
#include <stdio.h>
#define NUM_THREADS 3
DWORD WINAPI ThreadFunction(LPVOID lpParam);
int main() {
    HANDLE threads[NUM_THREADS];
    DWORD threadIds[NUM_THREADS];
    int threadArgs[NUM_THREADS];

    printf("Main thread started (ID: %lu)\n", GetCurrentThreadId());
   
    for (int i = 0; i < NUM_THREADS; i++) {
        threadArgs[i] = i + 1;
        threads[i] = CreateThread(
            NULL,                   
            0,                      
            ThreadFunction,         
            &threadArgs[i],         
            0,                     
            &threadIds[i]           
        );
        
        if (threads[i] == NULL) {
            printf("Error creating thread %d\n", i);
            return 1;
        }
    }
    
 
    WaitForMultipleObjects(NUM_THREADS, threads, TRUE, INFINITE);
    
    
    for (int i = 0; i < NUM_THREADS; i++) {
        CloseHandle(threads[i]);
    }
    
    printf("All threads completed. Main thread exiting.\n");
    return 0;
}

DWORD WINAPI ThreadFunction(LPVOID lpParam) {
    int threadNum = *(int*)lpParam;
    printf("Thread %d started (ID: %lu)\n", threadNum, GetCurrentThreadId());
    for (int i = 1; i <= 3; i++) {
        printf("Thread %d: working... (%d/3)\n", threadNum, i);
        Sleep(1000); 
    }
    
    printf("Thread %d completed\n", threadNum);
    return 0;
}
