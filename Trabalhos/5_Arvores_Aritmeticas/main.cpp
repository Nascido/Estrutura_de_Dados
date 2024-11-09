#include "ArvoreBinaria.h"
#include <iostream>

int main() {
    BinaryTree tree;
    std::string expression = "A*B+C*D-E";

    tree.insert_string(expression);

    std::cout << "Notação Prefixa: " << tree.prefixa() << std::endl;
    std::cout << "Notação Posfixa: " << tree.posfixa() << std::endl;

    return 0;
}