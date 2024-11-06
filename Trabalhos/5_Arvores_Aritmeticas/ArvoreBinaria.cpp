#ifndef TREE_H
#define TREE_H

struct Node {
    char data;

    struct Node* parent;
    struct Node* left;
    struct Node* right;
};


#endif