#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    int fd;
    off_t size;
    struct stat info;
    DIR *d;
    struct dirent *dir;

    fd = open("sample.txt", O_RDONLY);
    if (fd == -1) {
        printf("Cannot open file.\n");
        return 1;
    }

    size = lseek(fd, 0, SEEK_END);
    printf("File size: %ld bytes\n", size);
    close(fd);

    if (stat("sample.txt", &info) == 0) {
        printf("File inode: %ld\n", info.st_ino);
        printf("File permissions: %o\n", info.st_mode & 0777);
    } else {
        printf("Could not get file info.\n");
    }

    d = opendir(".");
    if (d) {
        printf("Files in current directory:\n");
        while ((dir = readdir(d)) != NULL) {
            printf("  %s\n", dir->d_name);
        }
        closedir(d);
    } else {
        printf("Cannot open directory.\n");
    }

    return 0;
}

