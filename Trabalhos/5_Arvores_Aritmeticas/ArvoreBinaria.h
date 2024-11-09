#ifndef TREE_H
#define TREE_H

#include <string>
#include <utility>

struct Node {
    char val;

    struct Node* left;
    struct Node* right;
};

class BinaryTree{
private:
    Node* root;

public:
    BinaryTree();

    void insert_string(std::string expression);
    std::string prefixa();
    std::string posfixa();


    ~BinaryTree();
};


#endif