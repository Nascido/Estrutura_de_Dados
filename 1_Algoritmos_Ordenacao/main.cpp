#include "2_bubble_sort.h"
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <vector>

void knuth_shuffle(std::vector<int> &v) {
  srand(time(NULL)); // A different seed each time
  std::size_t n = v.size();
  for (std::size_t i = n; i-- > 0;) {
    // Pick a random index from 0 to i:
    std::size_t j = rand() % (i + 1);

    // Swap v[i] and v[j]:
    auto aux = v[i];
    v[i] = v[j];
    v[j] = aux;
  }
}

std::vector<int> generate_random_vector(std::size_t size) {
  std::vector<int> v;
  v.reserve(size);
  for (auto i = 0; i < size; i++)
    v.push_back(i);
  knuth_shuffle(v);
  return v;
}

int main() {
  auto size = 32000;
  std::vector<int> v = generate_random_vector(size);

  auto start = std::chrono::system_clock::now();
  bubble_sort4(v);
  auto end = std::chrono::system_clock::now();

  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                     start)
                   .count()
            << "ms\n";
  return 0;
}
