#include <fstream>
#include <iomanip>

using namespace std;

ofstream* csv;

void inicializarArquivo(){
    csv = new ofstream("out.csv");
}

template <typename T>
void valor(T val){
    if (csv != nullptr) *csv << val << ", ";
}

void pularLinha(){
    if (csv != nullptr) *csv << endl; 
}

void salvarArquivo(){
    if (csv != nullptr) csv->close();
}