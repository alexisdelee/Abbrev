#ifndef IDENTIFIANT_COMMIT_H
#define IDENTIFIANT_COMMIT_H

typedef struct Token Token;
struct Token
{
    unsigned int size;
    char **data;
};

typedef struct Node Node;
struct Node
{
    char hexa;
    int size;
    int pattern;
    struct Node **next;
};

typedef struct Commit Commit;
struct Commit
{
    int entropy;
    Node *tree;
    void (*add)(char *, struct Commit);
    char *(*abbrev)(char *, struct Commit);
    Token *(*find)(char *, struct Commit);
    void (*free)(struct Commit);
};

Commit commitInit();
void freeTree(Node *);

#endif //IDENTIFIANT_COMMIT_H
