#include <iostream>

using namespace std;

int main() {
  cout << "#####################################" << endl;
  cout << "   Bem vindo ao jogo da advinhacao   " << endl;
  cout << "#####################################" << endl;

  int segredo = 42;
  int chute;

  cout << "Qual o seu chute? ";
  cin >> chute;

  int dif;

  dif = abs(chute - segredo);

  while (dif != 0) {
    if (dif < 5) {
      cout << "Quente!!!\n";
    } else if (dif < 10) {
      cout << "Morno!\n";
    } else if (dif < 20) {
      cout << "Frio\n";
    } else {
      cout << "Muito Frio!!!\n";
    }

    cout << "Qual o seu chute? ";
    cin >> chute;
    dif = abs(chute - segredo);
  }

  cout << endl << "Você Acertou!! Seu chute: " << chute << "\n\n";

  return 0;
}
