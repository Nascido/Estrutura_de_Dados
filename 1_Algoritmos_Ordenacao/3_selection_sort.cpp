#include <vector>

void selection_sort(std::vector<int> &v) {
  std::size_t n = v.size();
  for (std::size_t i = 0; i + 1 < n; i++) {
    std::size_t ind_min = i;
    for (std::size_t j = i + 1; j < n; j++)
      if (v[j] < v[ind_min])
        ind_min = j;
    auto aux = v[i];
    v[i] = v[ind_min];
    v[ind_min] = aux;
  }
}
