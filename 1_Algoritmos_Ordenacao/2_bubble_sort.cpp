#include <iostream>
#include <vector>

void bubble_sort1(std::vector<int>& v) {
    std::size_t n = v.size();
    bool mudou;
    do {
        mudou = false;
        for (std::size_t i = 1; i < n; ++i)
            if (v[i - 1] > v[i]) {
                auto aux = v[i - 1];
                v[i - 1] = v[i];
                v[i] = aux;
                mudou = true;
            }
    } while (mudou);
}

void bubble_sort2(std::vector<int>& v) {
    std::size_t n = v.size();
    for (std::size_t j = 0; j < n; ++j){
        for (std::size_t i = 1; i < n; ++i){
            if (v[i - 1] > v[i]) {
                auto aux = v[i - 1];
                v[i - 1] = v[i];
                v[i] = aux;
            }
        }
    }       
}

void bubble_sort3(std::vector<int>& v) {
    std::size_t n = v.size();
    for (std::size_t j = 0; j < n; ++j){
        for (std::size_t i = 1; i < n - j; ++i){
            if (v[i - 1] > v[i]) {
                auto aux = v[i - 1];
                v[i - 1] = v[i];
                v[i] = aux;
            }
        }
    }
}

void bubble_sort4(std::vector<int>& v) {
    std::size_t n = v.size();
    std::size_t lim_dir = n;
    for (std::size_t j = 0; j < n; ++j) {
        std::size_t pos_ult_inv = 0;
        for (std::size_t i = 1; i < lim_dir; ++i){
            if (v[i - 1] > v[i]) {
                auto aux = v[i - 1];
                v[i - 1] = v[i];
                v[i] = aux;
                pos_ult_inv = i;
            }
        }
        lim_dir = pos_ult_inv;
    }
}

