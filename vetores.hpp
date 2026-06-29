#include <stdlib.h>
#include <iostream>
#ifndef VETORES_HPP
#define VETORES_HPP

using namespace std;

void vetorAleatorio(int* vetor, int N){
    for (int i = 0; i < N; i++){
        vetor[i] = (rand() % N) + 1;
    }
}
void melhorCaso(int* vetor, int N){
    for (int i = 0; i < N; i++){
        vetor[i] = i+1;
    }
}
void piorCaso(int* vetor, int N){
    for (int i = 0; i < N; i++){
        vetor[i] = (N-i);
    }
}
void vetorDeVetores(int** vv, int N, int M){
    if (M < 2){
        cout << "M deve ser maior que 1" << endl;
    }
    melhorCaso(vv[0], N);
    piorCaso(vv[1], N);
    for (int i = 2; i < M; i++)
    {
        vetorAleatorio(vv[i], N);
    }
}
void printarVetor(int* vetor, int N, string nome = ""){
    if (nome != ""){
        cout << nome << " = ";
    }
    for (int i = 0; i < N; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;
}
void printarVetorDeVetores(int** vv, string nome, int N, int M){
    printarVetor(vv[0], N,     nome + "Melhor caso [1]    ");
    printarVetor(vv[1], N,     nome + "Pior caso [2]      ");
    for (int i = 2; i < M; i++){
        printarVetor(vv[i], N, nome + "Vetor aleatório [" + to_string(i+1) + "]");
    }
}
#endif