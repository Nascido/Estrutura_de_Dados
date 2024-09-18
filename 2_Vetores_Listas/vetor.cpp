#include <cstdlib>
#include <iostream>

class MyVector {

private:
  std::size_t _size = 0;
  std::size_t capacity;
  int *v;

public:
  MyVector();
  void insert(std::size_t pos, int x);
  void remove(std::size_t pos);
  int find(int x);
  std::size_t size();
  void print();
  ~MyVector();

private:
  void resize_array();
};

MyVector::MyVector() {
  capacity = 10;
  v = new int[capacity];
}

void MyVector::insert(std::size_t pos, int x) {
  if (size() == capacity) {
    resize_array();
  }
  for (std::size_t i = size(); i > pos; i--) {
    v[i] = v[i - 1];
  }
  v[pos] = x;
  _size++;
}

void MyVector::remove(std::size_t pos) {
  if (pos >= _size) {
    return;
  }

  while (pos < _size - 1) {
    v[pos] = v[pos + 1];
    pos++;
  }
  _size--;
}

int MyVector::find(int x) {
  for (int i = 0; i < size(); i++) {
    if (v[i] == x) {
      return i;
    }
  }
  return -1;
}

std::size_t MyVector::size() { return _size; }

void MyVector::print() {
  for (std::size_t i = 0; i < size(); i++) {
    std::cout << v[i] << ' ';
  }
  std::cout << '\n';
}

void MyVector::resize_array() {
  capacity = 2 * capacity + 1;
  int *u = new int[capacity];
  for (std::size_t i = 0; i < size(); i++) {
    u[i] = v[i];
  }
  delete[] v;
  v = u;
}

MyVector::~MyVector() { delete[] v; }

int main() {
  MyVector v;
  for (int i = 0; i < 20; ++i) {
    v.insert(0, 10 * i);
    v.print();
  }
  while (v.size() != 0) {
    v.remove(0);
    v.print();
  }
  return 0;
}
