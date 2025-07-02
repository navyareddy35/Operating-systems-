#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    struct dirent *de; 
    DIR *dr = opendir("."); 

    if (dr == NULL) {
        printf("Could not open current directory" );
        return 0;
    }

    while ((de = readdir(dr)) != NULL) {
        printf("%s\n", de->d_name);
    }

    closedir(dr); 
    return 0;
}

