#include <iostream>
#include <utility>
#include <cmath>
#include "LinkedList.h"

auto distancia_entre_pontos(std::pair<std::size_t, std::size_t> origem, std::pair<std::size_t, std::size_t> destino){
  long double x1, x2, y1, y2;

  long double rel, rel_X, rel_Y, dist;

  x1 = static_cast<long double>(origem.first);
  y1 = static_cast<long double>(origem.second);

  x2 = static_cast<long double>(destino.first);
  y2 = static_cast<long double>(destino.second);

  rel_X = x1 - x2;
  rel_X = std::pow(rel_X, 2.0);

  rel_Y = y1 - y2;
  rel_Y = std::pow(rel_Y, 2.0);
  
  rel = rel_X + rel_Y;

  dist = std::sqrt(rel);
 
  return dist;

}

auto distancia_total(LinkedList& rota){
  std::size_t size = 0;
  long double dist_total = 0;

  size = rota.size();

  for (std::size_t i=0; i<size-1; i++) {
    std::size_t j;
    std::pair<std::size_t, std::size_t> vi, vj;

    j = i+1;

    vi = rota.get_pair(i);
    vj = rota.get_pair(j);

    dist_total += distancia_entre_pontos(vi, vj);
  }
  
  std::pair<std::size_t, std::size_t> vinicial, vfinal;
  vfinal = rota.get_pair(size-1);
  vinicial = rota.get_pair(0);

  dist_total += distancia_entre_pontos(vfinal, vinicial);

  return dist_total;
}

int main(){

  std::size_t x, y;
  std::size_t i = 0;

  // Criar Lista Encadeada
  LinkedList cidades;
  std::cin >> x >> y;

  while(x != -1){
  // Guardar x e y em pair
    std::pair<std::size_t, std::size_t> cordenada(x, y);
    
    cidades.insert(i,cordenada);

    i++;
    std::cin >> x >> y;

  }

  auto size = cidades.size();
  
  if (size == 0) {
    return 0;
  }
  
  long double distancia;
  distancia = distancia_total(cidades);

  std::printf("%.2Lf\n", distancia);

  bool ready = false, change;

  while (!ready) {

    for (std::size_t j=0; j < size; j++) {
      cidades.switcher(j);
      auto dist_nova = distancia_total(cidades);

      if (dist_nova >= distancia){
        cidades.switcher(j);
      }else{
        change = true;
        distancia = dist_nova;
      }
    }

    if(change){
      ready = false;
    }else {
      ready = true;
    }
    change = false;
  }
  std::printf("%.2Lf\n", distancia); 
  
  return 0;
}

