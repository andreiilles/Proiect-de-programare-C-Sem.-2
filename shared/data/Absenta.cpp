#include "Absenta.h"

Absenta::Absenta(Data data) {
    this->data = data;
    this->motivata = false;
}

Absenta::Absenta(const Absenta &a) {
    this->data = a.data;
    this->motivata = a.motivata;
}
