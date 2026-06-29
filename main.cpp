#include <iostream>
#include <time.h>
#include "algoritmos.hpp"
#include "vetores.hpp"
#include "csv.hpp"
#include <cstring>
using namespace std;

bool PRINTAR_RESULTADOS = false;
bool MULTIPLOS_N = true;
int NUMEROS_N[4] = {100,500,1000,10000};
int tam_numeros_n = 4;

struct Timer {
  double melhorCaso;
  double piorCaso;
  double casoMedio;
  string nome;
  void printarTimer() {
    cout << "Tempo médio de execução do algoritmo " << nome << " (em segundos):" << endl;
    printf("Melhor caso: %.7f\n", melhorCaso);
    printf("Pior caso  : %.7f\n", piorCaso);
    printf("Medio caso : %.7f\n", casoMedio);
  }
  Timer() {
    melhorCaso = 0.0;
    piorCaso = 0.0;
    casoMedio = 0.0;
    nome = "";
  }
};

void testeVetores(int N, int M){
  /// Alocação da matriz
  int** matrix = new int*[M];
  for (int i = 0; i < M; i++) {
    matrix[i] = new int[N];
  }
  matriz(matrix, N, M);
  
}

clock_t clocks[4] = {0};

void testar(void func(int*, int), int** &matrix, int** &copia, int &N, int &M, Timer &timer){
  for (int i = 0; i < M; i++) {
    memcpy(copia[i], matrix[i], N * sizeof(int));
  }

  clocks[0] = clock();
    func(copia[0], N);
    if (estaDesordenado(copia[0], N)){
      printarVetor(copia[0], N);
      cerr << "DESORDENADO ^^" << timer.nome << endl;
    }
  clocks[1] = clock();
    func(copia[1], N);
    if (estaDesordenado(copia[1], N)){
      printarVetor(copia[1], N);
      cerr << "DESORDENADO ^^" << timer.nome << endl;
    }
  clocks[2] = clock();
    for (int mi = 2; mi < M; mi++){
      func(copia[mi], N);
      if (estaDesordenado(copia[mi], N)){
        printarVetor(copia[mi], N);
        cerr << "DESORDENADO ^^" << timer.nome << endl;
      }
    }
  clocks[3] = clock();

  if(PRINTAR_RESULTADOS) {
    cout << "===" << endl;
    printarMatriz(copia, timer.nome, N, M);
  }
  
  timer.melhorCaso += (double)(clocks[1] - clocks[0]) / CLOCKS_PER_SEC;
  timer.piorCaso += (double)(clocks[2] - clocks[1]) / CLOCKS_PER_SEC;
  timer.casoMedio += (double)(clocks[3] - clocks[2]) / CLOCKS_PER_SEC;
}

int main(){

  Timer* timer = new Timer[6];
  timer[0].nome = "insertionsort";
  timer[1].nome = "shellsort";
  timer[2].nome = "bubblesort";
  timer[3].nome = "selectionsort";
  timer[4].nome = "mergesort";
  timer[5].nome = "quicksort";

  int M, N, X;
  if (MULTIPLOS_N)
  {
    N = NUMEROS_N[tam_numeros_n-1];
    M = 10000 / NUMEROS_N[0] + 3;
    inicializarArquivo();
    valor("N");
    for(int i = 0; i < 6; i++){
      valor(timer[i].nome + "_MelhorCaso");
      valor(timer[i].nome + "_PiorCaso");
      valor(timer[i].nome + "_CasoMedio");
    }
    pularLinha();
  }
  else
  {
    tam_numeros_n = 1;
    cout << "Escolha o tamanho do vetor (N)" <<endl;
    cin >> N;
    cout << "Escolha a quantidade de vetores (M)" <<endl;
    cin >> M;
    cout << "Escolha a quantidade de vezes que os vetores serão ordenados (X)" <<endl;
    cin >> X;
  }
  
  int** matrix = new int*[M];
  for (int i = 0; i < M; i++) {
    matrix[i] = new int[N];
  }

  int** copia = new int*[M];
  for (int i = 0; i < M; i++) {
    copia[i] = new int[N];
  }

  for (int i = 0; i < tam_numeros_n; i++){

    for (int i = 0; i < 6; i++)
    {
      timer[i].melhorCaso = 0;
      timer[i].piorCaso = 0;
      timer[i].casoMedio = 0;
    }
    
    if(MULTIPLOS_N)
    {
      N = NUMEROS_N[i];
      M = 10000 / N + 3;
      X = 10000 / N + 3;
      printf("primeira linha: N: %d (M = %d, X = %d)\n", N, M, X);
      valor(N);
    }
    for (int xi = 0; xi < X; xi++){
      matriz(matrix, N, M);
      cout << "============== Testes " << xi+1 << " de " << X << " =============" << endl;
      
      if (PRINTAR_RESULTADOS) printarMatriz(matrix, "Vetor original: ", N, M);
    
      testar(insertionsort, matrix, copia, N, M, timer[0]);
      testar(shellsort, matrix, copia, N, M, timer[1]);
      testar(bubblesort, matrix, copia, N, M, timer[2]);
      testar(selectionsort, matrix, copia, N, M, timer[3]);
      testar(mergesort, matrix, copia, N, M, timer[4]);
      testar(quicksort, matrix, copia, N, M, timer[5]);
      
      if (PRINTAR_RESULTADOS) cout << "============" << endl << endl;
    }

    cout << "Tempo médio de execução dos algoritmos (em segundos):" << endl;
    
    for (int i = 0; i < 6; i++){
      timer[i].melhorCaso /= (X);
      timer[i].piorCaso /= (X);
      timer[i].casoMedio /= (X*(M-2));
      
      timer[i].printarTimer();
      if(MULTIPLOS_N){
        valor(timer[i].melhorCaso);
        valor(timer[i].piorCaso);
        valor(timer[i].casoMedio);
      }
    }
    if(MULTIPLOS_N) pularLinha();
  }
}
