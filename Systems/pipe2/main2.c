#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <pwd.h>
#include <time.h>

char *months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};


int main(int argc,char* argv[]) {
    
    char statusDirectory[2048] = "./";
    DIR *dir = opendir( "./");

    struct dirent* dirent;
    struct stat status;

    if(argc < 2 ||  argc > 3) {
        printf("Syntax Error\n");
    }

    else {

        if(argc == 2 && (strcmp(argv[1],"ls") == 0)){
            while((dirent = readdir(dir)) != NULL) {
                if(((strcmp(dirent->d_name,"..") != 0) && (strcmp(dirent->d_name,".") != 0 ))) {
                    printf("%s ",dirent->d_name);
                }
            }
            printf("\n");
        }

        else if(argc == 3 && (strcmp(argv[1],"ls") == 0) && (strcmp(argv[2],"-l") == 0)) {

            while((dirent = readdir(dir)) != NULL) {

                if(((strcmp(dirent->d_name,"..") != 0) && (strcmp(dirent->d_name,".") != 0 ))) {

                    strcat(statusDirectory,dirent->d_name);
                    stat(statusDirectory,&status);

                    char permission[] = "?rwxrwxrwx";

                    for(int i = 8 ; i >= 0 ; i--) {
                        if(((status.st_mode &  (1 << i)))) {

                        }
                        else {
                            permission[9-i] = '-';
                        }

                    }

                    switch (status.st_mode & S_IFMT) {
                        case S_IFDIR:
                            permission[0] = 'd';
                            break;
                        case S_IFLNK:
                            permission[0] = 'l';
                            break;
                        case S_IFREG:
                            permission[0] = '-';
                            break;
                    }

                    unsigned int link = status.st_nlink;
                    struct passwd *user = getpwuid(status.st_uid);
                    struct passwd *group = getpwuid(status.st_gid);

                    time_t time = status.st_mtim.tv_sec;
                    struct tm *localTime = localtime(&time);
                    int month = localTime->tm_mon;
                    int mday = localTime->tm_mday;
                    int hour = localTime->tm_hour;
                    int minute = localTime->tm_min;

                    printf("%s %*u %*s %*s %*ld %*s %02d %02d:%02d %s\n",permission,2,link,10,user->pw_name,10,group->pw_name,15,status.st_size,10,months[month],mday,hour,minute,dirent->d_name);
                    strcpy(statusDirectory,"./");
                }
            }
        }

        else {
            printf("Syntax Error\n");
        }
    }
    
}

