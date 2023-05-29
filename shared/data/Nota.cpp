#include "Nota.h"

Nota::Nota(int valoare, Data data) {
    this->valoare = valoare;
    this->data = data;
}

Nota::Nota(const Nota &n) {
    this->valoare = n.valoare;
    this->data = n.data;
}
