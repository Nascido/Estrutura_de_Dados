#ifndef LINKED_H
#define LINKED_H

#include <utility>

struct Node {
  std::pair<std::size_t, std::size_t> data;          // Dados Armazenados no nó
  struct Node* next; // Ponteiro para o próximo nó
};



class LinkedList {
private:
  Node* head;         // Primeiro Node da Lista
  std::size_t _size;  // Tamanho da lista

public:
  LinkedList();                                                           // Construtora
  Node* find(std::pair<std::size_t, std::size_t> x);                      // Encontrar o nódulo
  void insert(std::size_t pos, std::pair<std::size_t, std::size_t> x);    // Inserir um novo elemnto
  std::pair<std::size_t, std::size_t> get_pair(std::size_t pos);          // Getter de elemento
  Node* get_node(std::size_t pos);                                        // Getter de Nódulo
  void switcher(std::size_t pos);                                         // Inverter nódulos
  void remove(std::pair<std::size_t, std::size_t> x);                     // Remover um nódulo
  std::size_t size();                                                     // Getter de size
  void clear();                                                           // Liberar espaço criado
  ~LinkedList();                                                          // Destrutora

private:
  void insert(Node* p, Node* new_elem);                                   // Inserir um novo nódulo

};


#endif
