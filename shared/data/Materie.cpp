//
// Created by mario on 5/28/2023.
//

#include "Materie.h"

void Materie::init(string nume, vector<Nota> note, vector<Absenta> absente, int teza) {
    this->nume = nume;
    this->note = note;
    this->absente = absente;
    this->teza = teza;
}

Materie::Materie(string nume) {
    this->init(nume, vector<Nota>(), vector<Absenta>(), 0);
}

Materie::Materie(string nume, vector<Nota> note, vector<Absenta> absente) {
    this->init(nume, note, absente, 0);
}

Materie::Materie(string nume, vector<Nota> note, vector<Absenta> absente, int teza) {
    this->init(nume, note, absente, teza);
}

Materie::Materie(const Materie &m) {
    this->init(m.nume, m.note, m.absente, m.teza);
}


