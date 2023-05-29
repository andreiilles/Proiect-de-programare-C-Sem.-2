#include "Elev.h"

int Elev::numarElevi;

void Elev::init(std::string prenume, std::string nume, vector<Materie> materii, vector<Absenta> absente) {
    this->prenume = prenume;
    this->nume = nume;
    this->materii = materii;
    this->absente = absente;
}

Elev::Elev(std::string prenume, std::string nume) {
    this->init(prenume, nume, vector<Materie>(), vector<Absenta>());
    Elev::numarElevi++;
    this->numarMatricol = Elev::numarElevi;
}

Elev::Elev(std::string prenume, std::string nume, vector<Materie> materii, vector<Absenta> absente) {
    this->init(prenume, nume, materii, absente);
    Elev::numarElevi++;
    this->numarMatricol = Elev::numarElevi;
}

Elev::Elev(const Elev &e) {
    this->init(e.prenume, e.nume, e.materii, e.absente);
    this->numarMatricol = e.numarMatricol;
}

void Elev::setNumarElevi(int n) {
    Elev::numarElevi = n;
}

Elev::Elev(int numarMatricol, string prenume, string nume, vector<Materie> materii, vector<Absenta> absente) {
    this->numarMatricol = numarMatricol;
    this->init(prenume, nume, materii, absente);
}

ostream& operator<<(ostream &out, const Elev &e) {
    out << e.numarMatricol << ": " << e.prenume << " " << e.nume;
    return out;
}

int Elev::getNumarElevi() {
    return Elev::numarElevi;
}

int Elev::getNumarMatricol() {
    return this->numarMatricol;
}

string Elev::getPrenume() {
    return this->prenume;
}

string Elev::getNume() {
    return this->nume;
}

