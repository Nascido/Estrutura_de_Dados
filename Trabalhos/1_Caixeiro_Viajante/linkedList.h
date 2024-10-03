#ifndef LINKED_H
#define LINKED_H

#include <cstddef>

struct Node {
  int data;          // Dados Armazenados no nó
  struct Node* next; // Ponteiro para o próximo nó
};



class LinkedList {
private:
  Node* head;         // Primeiro Node da Lista
  std::size_t _size;

public:
  LinkedList();
  Node* find(int x);
  void insert(std::size_t pos, int x);
  void remove(int x);
  std::size_t size();
  void clear();
  ~LinkedList();

private:
  void insert(Node* p, Node* new_elem);

};


#endif
