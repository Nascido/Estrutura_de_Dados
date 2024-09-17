#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

const std::string palavra_secreta = "MELANCIA";


bool letra_existe(char chute){
  int n = palavra_secreta.size();
  for (int i=0; i<n;i++){
    if (chute == palavra_secreta[i]){
      return true;
    }
}
  return false;
}

int main()
{
  cout << "##############################################################################" << endl;
  cout << "                       Bem-Vindo ao Jogo da Forca                             " << endl;
  cout << "##############################################################################" << endl;

  bool acertou, enforcou;

  acertou  = false;
  enforcou = false;

  while (!acertou && !enforcou){
    char chute;
      cout << "Informe seu chute: ";
    cin >> chute;

    if(letra_existe(chute)){
      cout << "\nAcertou uma letra" << endl;
    } else {
      cout << "\nNão acertou nenhuma letra" << endl;
    }
  }
  return 0;
}
