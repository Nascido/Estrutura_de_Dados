#include "LinkedList.h"
#include <stdexcept>
#include <utility>

LinkedList::LinkedList(){
  head = nullptr;
  _size = 0;
}

Node* LinkedList::find(std::pair<std::size_t, std::size_t> x){
  auto pivot = head;
  while (pivot != nullptr and pivot->data != x) {
    pivot = pivot->next; 
  }
  return pivot;
}  

void LinkedList::insert(std::size_t pos, std::pair<std::size_t, std::size_t> x){
  Node* new_node = new Node();
  new_node->data = x;
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

std::pair<std::size_t, std::size_t> LinkedList::get_pair(std::size_t pos){
  std::size_t size;

  size = _size;

  if (pos >= size) {
    throw std::out_of_range("Posicao Invalida: get_pair method");
  }

  auto pivot = head;

  for (std::size_t i=0; i < pos; i++){
    pivot = pivot->next;
  }

  return pivot->data;
}

Node* LinkedList::get_node(std::size_t pos){
  // Return Node
  std::size_t size;
  size = _size;

  if (pos >= size) {
    throw std::out_of_range("Posicao Invalida: get_node method");
  }

  auto pivot = head;

  for (std::size_t i=0; i < pos; i++){
    pivot = pivot->next;
  }

  return pivot;
}

void LinkedList::switcher(std::size_t pos){
  // Switch Positions
  std::size_t size, i, j;
  size = _size;

  if (pos >= size) {
    throw std::out_of_range("Posicao Invalida: Switcher method");
  }

  i = pos;
  if (i == size-1) {
    j = 0;
  } else {
    j = i+1;
  }

  if (i == 0){
    auto node = get_node(0);
    auto nodeProx = get_node(1);
    auto tmp = nodeProx->next;
    nodeProx->next = node;
    node->next = tmp;
    head = nodeProx;
  }else if (j == 0) {
    auto node = get_node(i);
    auto nodeProx = get_node(0);
    auto nodeAnt = get_node(i-1);
    auto tmp = nodeProx->next;
    nodeProx->next = nullptr;
    node->next = tmp;
    nodeAnt->next = nodeProx;
    head = node;
  }else {
    auto node = get_node(i);
    auto nodeProx = get_node(j);
    auto nodeAnt = get_node(i-1);
    auto tmp = nodeProx->next;
    nodeProx->next = node;
    node->next = tmp;
    nodeAnt->next = nodeProx;
  }
}

void LinkedList::remove(std::pair<std::size_t, std::size_t> x){
  if (size() == 0) {
    return;
  }
  Node* to_remove = nullptr;
  if (head->data == x) {
    to_remove = head;
    head = head->next;
  }
  else{
    auto pivot = head;
    while (pivot->next != nullptr and pivot->next->data != x) {
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

void LinkedList::clear(){
  Node* to_delete = head;
  while (to_delete != nullptr) {
    auto aux = to_delete->next;
    delete to_delete;
    to_delete = aux;
  }
  head = nullptr;
  _size = 0;
}

LinkedList::~LinkedList(){
  clear();
}
