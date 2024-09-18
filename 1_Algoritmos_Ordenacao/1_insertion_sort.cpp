#include "1_insertion_sort.h"
#include <vector>

void insertion_sort(std::vector<int> &v) {
  std::size_t n = v.size();
  for (std::size_t i = 1; i < n; ++i) {
    auto pivot = v[i];
    int j = i - 1;
    while (j >= 0 and v[j] > pivot) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = pivot;
  }
}
