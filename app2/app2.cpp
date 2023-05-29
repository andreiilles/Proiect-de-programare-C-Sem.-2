//
// Created by mario on 5/28/2023.
//

#include <vector>
#include <cstring>
#include <string>
#include <fstream>
#include <iostream>
#include "../shared/data/Elev.h"
#include "../shared/data/UsefulFunctions.h"
using namespace std;



vector<Elev> elevi;

void readElevi() {
    ifstream f("../shared/files/elevi.txt");
    int numarElevi;
    f >> numarElevi;
    Elev::setNumarElevi(numarElevi);

    for(int i=1;i<=numarElevi;i++) {
        int nrMatricol;
        string prenume, nume;
        f >> nrMatricol;
        f >> prenume >> nume;
        elevi.push_back(Elev(nrMatricol, prenume, nume, vector<Materie>(), vector<Absenta>()));
    }

    f.close();
}

void writeElevi() {
    ofstream w("../shared/files/elevi.txt");
    w << Elev::getNumarElevi() << endl;
    for(auto it = elevi.begin(); it < elevi.end(); it++) {
        w << it->getNumarMatricol() << endl;
        w << it->getPrenume() << " " << it->getNume() << endl;
    }
    w.close();
}

void adaugaElev(string prenume, string nume) {
    elevi.push_back(Elev(prenume, nume));
}



int main(int argc, char* argv[]) {

    readElevi();
    if(strcmp(argv[0],"adauga_elev")==0)
        adaugaElev(argv[1],argv[2]);
    writeElevi();


    return 0;
}