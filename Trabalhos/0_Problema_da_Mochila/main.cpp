#include <iostream>
#include <vector>
#include <tuple>

void insertion_sort_inverso(std::vector<std::tuple<int, int, int, int, double>>& vetor){
  std::size_t n = vetor.size();
  for (std::size_t i = 1; i < n; ++i) {
    std::tuple<int, int, int, int, double> pivo = vetor[i];                 // Tupla Pivo

    double pivoValue = std::get<4>(pivo);                                   // Obter valor double da Tupla Pivo

    int j = i - 1;
    while (j >= 0 and std::get<4>(vetor[j]) < pivoValue) {
      vetor[j+1] = vetor[j];
      j--;
    }
    vetor[j+1] = pivo;
  }
}

int main(){
  int i, u, w, d;                                                        // i: indice, u: utilidade, w: peso, d: quantidade do item
  double relacao;                                                        // relacao de u/w

  std::vector<std::tuple<int, int, int, int, double>> itensDisponiveis;  // Vetor de Tuplas: Cada tupla representa um item
  std::tuple<int, int, int, int, double> item;                           // Tupla: Valores do Item

  std::cin >> u >> w >> d;                                               // Leitura dos vavlores: utilidade, peso, quantidade
  i = 0;

  while (u != -1) {
    relacao = static_cast<double>(u)/w;            // Calculo da relacao utilidade/peso
    item = std::make_tuple(i, u, w, d, relacao);
    itensDisponiveis.push_back(item);              // Inserindo Itens no vetor

    std::cin >> u >> w >> d;
    i++;
  }

  std::size_t capacidade;                          // Capacidade da mochila
  std::cin >> capacidade;
  std::size_t tamanho = itensDisponiveis.size();
  std::size_t wTotal = 0;                          // Soma dos pesos

  bool temEspaco=true, finalizado=false;

  insertion_sort_inverso(itensDisponiveis);                // Ordenar itens pela relação u/w

  while (temEspaco && !finalizado) {
    for (std::size_t i=0; i<tamanho ; i++) {
      if (!temEspaco){
        break;
      }

      item = itensDisponiveis[i];
      int iItem = std::get<0>(item);       // Indice do Item
      int wItem = std::get<2>(item);       // Peso do Item
      int dItem = std::get<3>(item);       // Quantidade do Item

      int vezesInserido=0, soma=0;

      bool proximoItem=false;

      for (std::size_t j = 0; j<dItem; j++) {
        soma = wTotal + wItem;

        if (soma <= capacidade){
          wTotal = soma;
          vezesInserido++;

        }else{
          proximoItem=true;
        }
          if (proximoItem || j == (dItem-1)){
            if(vezesInserido > 0){
              std::cout << iItem << ' ' << vezesInserido << std::endl;
            }
            break;
          }
      if (wTotal == capacidade)
        temEspaco = false;
      }
    }
    finalizado = true;
  }
  return 0;
}
