#include <stdlib.h>
#include <iostream>
#ifndef VETORES_HPP
#define VETORES_HPP

using namespace std;

float* vetorAleatorio(int N){
    float* vetor = new float[N];
    for (int i = 0; i < N; i++){
        vetor[i] = (rand() % N) + 1;
    }
    return vetor;
}
float* melhorCaso(int N){
    float* vetor = new float[N];
    for (int i = 0; i < N; i++){
        vetor[i] = i+1;
    }
    return vetor;
}
float* piorCaso(int N){
    float* vetor = new float[N];
    for (int i = 0; i < N; i++){
        vetor[i] = (N-i);
    }
    return vetor;
}
float** vetorDeVetores(int N, int M){
    if (M < 2){
        cout << "M deve ser maior que 1" << endl;
    }
    float** vv = new float*[M];
    vv[0] = melhorCaso(N);
    vv[M-1] = piorCaso(N);
    for (int i = 1; i < M-1; i++)
    {
        vv[i] = vetorAleatorio(N);
    }
    return vv;
}
void printarVetor(float* vetor, int N, string nome = ""){
    if (nome != ""){
        cout << nome << " = ";
    }
    for (int i = 0; i < N; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;
}
#endif