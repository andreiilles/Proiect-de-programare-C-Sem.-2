#include "Materie.h"

void Materie::init(string nume, vector<Nota> note, vector<Absenta> absente, int teza) {
    this->nume = nume;
    this->note = note;
    this->absente = absente;
    this->teza = teza;
}

Materie::Materie() {
    this->init("", vector<Nota>(), vector<Absenta>(), 0);
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

string Materie::getNume() {
    return this->nume;
}

vector<Nota> Materie::getNote() {
    return this->note;
}

vector<Absenta> Materie::getAbsente() {
    return this->absente;
}

int Materie::getTeza() {
    return this->teza;
}

void Materie::setNume(string nume) {
    this->nume = nume;
}

void Materie::setNote(vector<Nota> note) {
    this->note = note;
}

void Materie::setAbsente(vector<Absenta> absente) {
    this->absente = absente;
}

void Materie::setTeza(int teza) {
    this->teza = teza;
}



