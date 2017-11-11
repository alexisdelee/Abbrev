#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Commit.h"

Node *initNode(char);
void build(char *, Commit);
char *abbrev(char *, Commit);
void freeCommit(Commit);

Commit commitInit()
{
    Commit commit;

    commit.entropy = 7;
    commit.tree = initNode('.');
    commit.add = build;
    commit.abbrev = abbrev;
    commit.free = freeCommit;

    return commit;
}

Node *initNode(char hexa)
{
    Node *seed = (Node *)malloc(sizeof(Node));

    seed->hexa = hexa;
    seed->size = 0;
    seed->pattern = 1;
    seed->next = NULL;

    return seed;
}

void build(char *chain, Commit commit)
{
    int size = strlen(chain);
    Node *seed = commit.tree;
    Node *_seed;
    int i, j;
    int active;

    for(i = 0; i < size; i++) {
        active = 0;

        _seed = initNode(chain[i]);

        if(i == size - 1) {
            _seed->next = NULL;
        }

        for(j = 0; j < seed->size; j++) {
            if(seed->next[j]->hexa == chain[i]) {
                seed = seed->next[j];
                seed->pattern++;
                active = 1;

                break;
            }
        }

        if(!active) {
            seed->next = (Node **)realloc(seed->next, sizeof(Node *) * ++seed->size);
            seed->next[seed->size - 1] = _seed;

            seed = seed->next[seed->size - 1];
        }
    }
}

char *abbrev(char *chain, Commit commit)
{
    Node *seed = commit.tree;
    int i, j;
    int entropy = commit.entropy;
    char *shortestId = NULL;
    int size = 1;

    if(entropy < 1) {
        return NULL;
    }

    for(i = 0; i < entropy; i++) {
        if(seed->next) {
            for(j = 0; j < seed->size; j++) {
                if(seed->next[j]->hexa == chain[i]) {
                    if(size == 1) {
                        shortestId = (char *)malloc(sizeof(char) * ++size);
                    } else {
                        shortestId = (char *)realloc(shortestId, sizeof(char) * ++size);
                    }

                    if(shortestId == NULL) {
                        return NULL;
                    } else {
                        sprintf(shortestId, "%s%c", size == 2 ? "" : shortestId, seed->next[j]->hexa);
                    }

                    seed = seed->next[j];

                    if(i == entropy - 1 && seed->pattern > 1) {
                        entropy++;
                    }

                    break;
                }
            }
        } else {
            break;
        }
    }

    return shortestId;
}

void freeCommit(Commit commit)
{
    freeTree(commit.tree);
}

void freeTree(Node *seed)
{
    int i;

    if(seed) {
        for(i = 0; i < seed->size; i++) {
            freeTree(seed->next[i]);
        }

        free(seed);
    }
}
