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

void selectionsort(float* vet, int tam){
    for (int  i=0; i< tam-1; i++){
        int pos_menor = i;
        for (int j = i+1; j< tam-1; j++){
            if(vet[j] < vet[pos_menor]){
                pos_menor = j;
            }
        }
        float temp = vet[i];
        vet[i] = vet[pos_menor];
        vet[pos_menor] = temp;
    }
}

void quicksort(float* vet, int esq, int dir){
    int x,i,j,aux;
    i = esq;
    j = dir;
    x = vet[(i + j) / 2];
    
    while(x > vet[i]){
        i++;
    }
    while(x<vet[j]){
         j--;
    }

    if(i<=j){
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
        i++;
        j--;
    }

    while(i>j){
        if (esq < j)
            quicksort(vet, esq, j);
        if (dir > i)
            quicksort(vet, i, dir);
    }

}

void mergesort(float* vet,int comeco, int fim){
int meio;

    if (comeco == fim)
    return; 
    meio = (comeco + fim) / 2;

    mergesort(vet, comeco, meio);
    mergesort(vet, meio + 1, fim);

    mesclar(vet, comeco, meio, fim);
}

void mesclar (float* vet, int comeco, int meio, int fim){
    int com1 = comeco;
    int com2 = meio + 1;
    int tam = fim - comeco + 1;
    int comAux = 0;
    float* vetAux = new float[tam];

    while(com1<meio && com2<= fim){
        if(vet[com1] < vet[com2]){
            vetAux[comAux] = vet[com1];
            com1++;
        }
        else{
            vetAux[comAux] = vet[com2];
            com2++;
        }
        comAux++;
    }

    while (com1<=meio){
        vetAux[comAux] = vet[com1];
        comAux++;
        com1++;
    }

    while(com2<=fim){
        vetAux[comAux] = vet[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){
        vet[comAux] = vetAux[comAux - comeco];
    }
    delete[] vetAux;

}

#endif