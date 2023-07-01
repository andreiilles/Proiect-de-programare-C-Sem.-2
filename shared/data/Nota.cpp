#include "Nota.h"

Nota::Nota() {
    this->valoare = 0;
    this->data = Data();
}

Nota::Nota(int valoare, Data data) {
    this->valoare = valoare;
    this->data = data;
}

Nota::Nota(const Nota &n) {
    this->valoare = n.valoare;
    this->data = n.data;
}

int Nota::getValoare() {
    return this->valoare;
}

Data Nota::getData() {
    return this->data;
}

void Nota::setValoare(int valoare) {
    this->valoare = valoare;
}

void Nota::setData(Data data) {
    this->data = data;
}

