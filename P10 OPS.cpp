#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MAX 100
struct msg_buffer {
    long msg_type;
    char msg_text[MAX];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;

    key = ftok("progfile", 65);

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget failed");
        exit(1);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        
        msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);
        printf("Child (Receiver) received message: %s\n", message.msg_text);
        msgctl(msgid, IPC_RMID, NULL);
    } else {
        message.msg_type = 1;
        strcpy(message.msg_text, "Hello from parent via message queue!");

        msgsnd(msgid, &message, sizeof(message.msg_text), 0);
        printf("Parent (Sender) sent message.\n");

        wait(NULL);
    }

    return 0;
}

