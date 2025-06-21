#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
    int source, dest;
    char buffer[1024];
    ssize_t bytes;
    source = open("source.txt", O_RDONLY);
    if (source < 0) {
        perror("Failed to open source file");
        return 1;
    }
    dest = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest < 0) {
        perror("Failed to open/create destination file");
        close(source);
        return 1;
    }
    while ((bytes = read(source, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, bytes);
    }
    close(source);
    close(dest);
    printf("File copied successfully.\n");
    return 0;
}

