#include <iostream>
#include "algoritmos.hpp"
#include "vetores.hpp"
using namespace std;

void testeVetores(int N, int M){
  float* rand = vetorAleatorio(N);
  printarVetor(rand,N,"vetorAleatorio");
  rand = melhorCaso(N);
  printarVetor(rand,N,"melhorCaso");
  rand = piorCaso(N);
  printarVetor(rand,N,"piorCaso");
  float** vv = vetorDeVetores(N, M); 
  for (int i = 0; i < M; i++)
  {
    printarVetor(vv[i], N, "vv[" + to_string(i) + "]");
  }
}

int main(){
  int M, N, X;
  cout << "Escolha o tamanho do vetor (N)" <<endl;
  cin >> N;
  cout << "Escolha a quantidade de vetores (M)" <<endl;
  cin >> M;
  cout << "Escolha a quantidade de vezes que os vetores serão ordenados (X)" <<endl;
  cin >> X;
  if(X == -1) {
    testeVetores(N,M);
    return 0;
  }
  float** vv = vetorDeVetores(N, M);
  for (int mi = 0; mi < M; mi++){
    bubblesort(vv[mi], N);
    printarVetor(vv[mi], N, "vv[" + to_string(mi) + "]");
  }
}
