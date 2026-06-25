#ifndef ALGORITMOS_HPP
#define ALGORITMOS_HPP

#include "vetores.hpp"
#include <cmath>

void insertionsort(float* vet, int n){
    for (int j = 1; j < n; j++){
        int chave = vet[j];
        int i = j - 1;
        while (i >= 0 && vet[i] > chave){
            vet[i + 1] = vet[i];
            i = i - 1;
        }
        vet[i+1] = chave;
    }
}

void shell(float* vet, int inicio, int inc, int tam){
    int j, k, chave;
    bool achei;
    for (int i = inicio+inc; i < tam; i+= inc){
        j = inicio;
        achei = false;
        while (j < i && !achei)
        {
            if (vet[i] < vet[j])
            {
                achei = true;
            }
            else
            {
                j = j+inc;
            }
        }
        if (achei){
            chave = vet[i];
            k = i - inc;
            while (k > (j - inc))
            {
                vet[k + inc] = vet[k];
                k = k - inc;
            }
            vet[j] = chave;
        }
    }
}

void shellsort(float* vet, int tam){
    for (int i = 3; i > 0; i--){
        int inc = pow(2, i);
        for (int j = 0; j < inc; j++){
            shell(vet, j, inc, tam);
            //printarVetor(vet, tam, "j=" + to_string(j) + " inc=" + to_string(inc));
        }
    }
    insertionsort(vet, tam);
}

void bubblesort(float* vet, int tam){
    bool troca = true;
    while (troca)
    {
        troca = false;
        int chave = 0;
        while (chave < tam-1)
        {
            if (vet[chave] > vet[chave+1]){
                float aux = vet[chave];
                vet[chave] = vet[chave+1];
                vet[chave+1] = aux;
                troca = true;
            }
            chave++;
        }
        //printarVetor(vet, tam, "bubblesort");
    }
}

#endif