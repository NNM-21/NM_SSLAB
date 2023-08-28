#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void print_file_info(const char *file_path) {
    struct stat file_stat;

    if (stat(file_path, &file_stat) == 0) {
        printf("File Information:\n");
        printf("a. Inode: %lu\n", file_stat.st_ino);
        printf("b. Number of Hard Links: %lu\n", file_stat.st_nlink);
        
        struct passwd *uid_info = getpwuid(file_stat.st_uid);
        struct group *gid_info = getgrgid(file_stat.st_gid);
        
        printf("c. UID: %s\n", uid_info->pw_name);
        printf("d. GID: %s\n", gid_info->gr_name);
        
        printf("e. Size: %lld bytes\n", (long long)file_stat.st_size);
        printf("f. Block Size: %lu bytes\n", file_stat.st_blksize);
        printf("g. Number of Blocks: %lu\n", file_stat.st_blocks);
        printf("h. Time of Last Access: %s", ctime(&file_stat.st_atime));
        printf("i. Time of Last Modification: %s", ctime(&file_stat.st_mtime));
        printf("j. Time of Last Change: %s", ctime(&file_stat.st_ctime));
    } else {
        perror("Error");
    }
}

int main() {
    char file_path[256];
    printf("Enter the path to the file: ");
    scanf("%s", file_path);
    print_file_info(file_path);
    return 0;
}

