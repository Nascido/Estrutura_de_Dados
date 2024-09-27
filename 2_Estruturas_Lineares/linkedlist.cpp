
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

LinkedList::LinkedList(){
  head = nullptr;
  _size = 0;
}

Node* LinkedList::find(int x){
  auto pivot = head;
  while (pivot != nullptr and pivot->value != x) {
    pivot = pivot->next; 
  }
  return pivot;
}  

void LinkedList::insert(std::size_t pos, int x){
  Node* new_node = new Node();
  new_node->value = x;
  new_node->next = nullptr;

  if (size() == 0) {
    head = new_node;
  }
  else{
    auto pivot = head;
    if (pos == 0){
      new_node->next = head;
      head = new_node;
    }
    else{
      for (std::size_t i = 1; i < pos; i++) {
        pivot = pivot->next;
      }    
      new_node->next = pivot->next;
      pivot->next = new_node;
    }
  }
  _size++;
}

void LinkedList::remove(int x){
  if (size() == 0) {
    return;
  }
  Node* to_remove = nullptr;
  if (head->value == x) {
    to_remove = head;
    head = head->next;
  }
  else{
    auto pivot = head;
    while (pivot->next != nullptr and pivot->next->value != x) {
      pivot = pivot->next;
    }
    to_remove = pivot->next;
    if(pivot->next != nullptr)
      pivot->next = pivot->next->next;
}
  if(to_remove != nullptr){
    delete to_remove;
    _size--;
  }
}

std::size_t LinkedList::size(){
  return _size;
}

LinkedList::clear(){
  Node* to_delete = head;
  while (to_delete != nullptr) {
    auto aux = to_delete->next;
    delete to_delete;
    to_delete = aux;
  }
  head = nullptr;
  _size = 0;
}