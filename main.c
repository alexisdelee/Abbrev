#include <stdio.h>
#include <stdlib.h>

#include "Commit.h"

int main(int argc, char **argv)
{
    Commit commit = commitInit();

    commit.add("a94a8fe5ccb19ba61c4c0873d391e987982fbbd3", commit);
    commit.add("a94a8fe5ccb18ba61c4c0873d391e987982fbbd3", commit);
    commit.add("aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d", commit);
    commit.add("697bc46e1beaa1667601998bc72be435e5f8666f", commit);
    commit.add("7c211433f02071597741e6ff5a8ea34789abbf43", commit);
    commit.add("1edbf3da8cde6b893130354e79ba15fca2269959", commit);

    char *shortestId = commit.abbrev("a94a8fe5ccb19ba61c4c0873d391e987982fbbd3", commit);

    if(shortestId != NULL) {
        printf("%s\n", shortestId); // a94a8fe5ccb19
        free(shortestId);
    }

    commit.free(commit);

    return 0;
}
