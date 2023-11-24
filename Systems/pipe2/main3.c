#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

struct entry {
    char *name;
    long long int size;
    struct entry *next;
};

int main() {
    DIR *dir;
    struct dirent *dp;
    struct stat st;
    struct entry *head = NULL, *ep, **npp;

    dir = opendir(".");
    if (dir == NULL) {
        perror("cannot open directory");
        return 1;
    }
    while ((dp = readdir(dir)) != NULL) {
        ep = calloc(sizeof(*ep), 1);
        if (ep == NULL) {
            perror("cannot allocate memory");
            return 1;
        }
        ep->name = strdup(dp->d_name);
        if (ep->name == NULL) {
            perror("cannot allocate memory");
            return 1;
        }
        if (!stat(dp->d_name, &st)) {
            ep->size = st.st_size;
        }
        for (npp = &head; *npp && (*npp)->size <= ep->size; npp = &(*npp)->next)
            continue;
        ep->next = *npp;
        *npp = ep;
    }
    closedir(dir);
    for (ep = head; ep; ep = ep->next) {
        printf("%s\n", ep->name);
    }
    while ((ep = head) != NULL) {
        head = ep->next;
        free(ep->name);
        free(ep);
    }
    return 0;
}
