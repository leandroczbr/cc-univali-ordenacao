#include <iostream>
#include <time.h>
#include "algoritmos.hpp"
#include "vetores.hpp"
using namespace std;

/*void testeVetores(int N, int M){
  int* rand = vetorAleatorio(N);
  printarVetor(rand,N,"vetorAleatorio");
  rand = melhorCaso(N);
  printarVetor(rand,N,"melhorCaso");
  rand = piorCaso(N);
  printarVetor(rand,N,"piorCaso");
  int** vv = vetorDeVetores(N, M); 
  for (int i = 0; i < M; i++)
  {
    printarVetor(vv[i], N, "vv[" + to_string(i) + "]");
  }
}*/

void testar(void func(int*, int), string nome, int** vv, int** copia, int N, int M){
  copia = vv;
  for (int mi = 0; mi < M; mi++)
  {
    func(copia[mi], N);
  }
  cout << "===" << endl;
  printarVetorDeVetores(copia, nome, N, M);
}


int main(){
  int M, N, X;
  cout << "Escolha o tamanho do vetor (N)" <<endl;
  cin >> N;
  cout << "Escolha a quantidade de vetores (M)" <<endl;
  cin >> M;
  cout << "Escolha a quantidade de vezes que os vetores serão ordenados (X)" <<endl;
  cin >> X;
  /*if(X == -1) {
    testeVetores(N,M);
    return 0;
  }*/
  
  int** vv = new int*[M];
  for (int i = 0; i < M; i++) {
    vv[i] = new int[N];
  }

  int** copia = new int*[M];
  for (int i = 0; i < M; i++) {
    copia[i] = new int[N];
  }

  for (int xi = 0; xi < X; xi++){
    vetorDeVetores(vv, N, M);
    cout << "============== Testes " << xi+1 << " de " << X << " =============" << endl;
    printarVetorDeVetores(vv, "Vetor original: ", N, M);
    testar(insertionsort, "insertionsort ", vv, copia, N, M);
    testar(shellsort, "shellsort ", vv, copia, N, M);
    testar(bubblesort, "bubblesort ", vv, copia, N, M);
    testar(selectionsort, "selectionsort ", vv, copia, N, M);
    testar(mergesort, "mergesort ", vv, copia, N, M);
    testar(quicksort, "quicksort ", vv, copia, N, M);
    cout << "============" << endl << endl;
  }
}
