#include "ArvoreBinaria.h"
#include <cctype>
#include <functional>
#include <queue>
#include <stack>
#include <string>

BinaryTree::BinaryTree(){
    root = nullptr;
}

BinaryTree::~BinaryTree(){
    std::function<void(Node*)> deleteNodes = [&](Node* node){
        if (node){
            deleteNodes(node->left);
            deleteNodes(node->right);
            delete node;
        }
    };
    deleteNodes(root);
}

Node* createNode(char val){
    Node* node = new Node{val,nullptr, nullptr};
    return node;
}

int precedence(char c){
    if (c == '+' || c == '-') return 2;
    if (c == '*' || c == '/') return 1;
    return 0;
}

void BinaryTree::insert_string(std::string expression){
    std::stack<Node*> operands;
    std::stack<char>  operators1;
    std::queue<char>  operators2;
    std::stack<Node*> particles;

    for (char c : expression){
        if(std::isalpha(c)){
            Node* node = createNode(c);
            operands.push(node);
        }else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!operators1.empty()) {
                Node* right = operands.top(); operands.pop();
                Node* left  = operands.top(); operands.pop();
                Node* node  = createNode(operators1.top()); operators1.pop();

                node->left = left;
                node->right = right;

                particles.push(node);
            }

            if (precedence(c) == 2){
                 operators2.push(c);
            } else {
                 operators1.push(c);
            }

            if (operators2.size() == 2){
                Node* right = particles.top(); particles.pop();
                Node* left  = particles.top(); particles.pop();
                Node* node  = createNode(operators2.front()); operators2.pop();

                node->left = left;
                node->right = right;

                particles.push(node);
            }
        }
    }

    if (!operands.empty()){
        particles.push(operands.top()); operands.pop();
    }

    Node* right = particles.top(); particles.pop();
    Node* left  = particles.top(); particles.pop();
    Node* node = createNode(operators2.front()); operators2.pop();

    node->left  = left;
    node->right = right;

    root = node;
}

void prefixHelper(Node* node, std::string& result) {
    if (node) {
        result += node->val;
        prefixHelper(node->left, result);
        prefixHelper(node->right, result);
    }
}

std::string BinaryTree::prefixa() {
    std::string result;
    prefixHelper(root, result);
    return result;
}

void postfixHelper(Node* node, std::string& result) {
    if (node) {
        postfixHelper(node->left, result);
        postfixHelper(node->right, result);
        result += node->val;
    }
}

std::string BinaryTree::posfixa() {
    std::string result;
    postfixHelper(root, result);
    return result;
}