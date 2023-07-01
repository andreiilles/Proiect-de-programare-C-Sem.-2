

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

    int maxi = 0;
    for(int i=1;i<=numarElevi;i++) {
        int nrMatricol;
        string prenume, nume;
        f >> nrMatricol;
        if(nrMatricol > maxi)
            maxi = nrMatricol;
        f >> prenume >> nume;
        elevi.push_back(Elev(nrMatricol, prenume, nume, vector<Materie>(), vector<Absenta>()));
    }
    Elev::setNumarElevi(maxi);
    f.close();
}

void readAbsente()
{
    ifstream f("../shared/files/absente.txt");
    while(!f.eof())
    {
        int tempMatricol;
        string tempString;
        f >> tempMatricol >> tempString;
        vector<string> params= splitString(tempString,"/");
        for(auto it = elevi.begin();it!=elevi.end();it++)
        {
            if (it->getNumarMatricol()==tempMatricol)
            {
                Absenta tempAbsenta(params[0]);
                it->adaugareAbsenta(tempAbsenta);
                break;
            }
        }
    }
    f.close();
}

void writeElevi() {
    ofstream w("../shared/files/elevi.txt");
    w << elevi.size() << endl;
    for(auto it = elevi.begin(); it < elevi.end(); it++) {
        w << it->getNumarMatricol() << endl;
        w << it->getPrenume() << " " << it->getNume() << endl;
    }
    w.close();
}

void adaugaElev(string prenume, string nume) {
    elevi.push_back(Elev(prenume, nume));
}

void stergeElev(int numarMatricol) {
    for(auto it = elevi.begin(); it!=elevi.end(); it++) {
        if(it->getNumarMatricol() == numarMatricol) {
            elevi.erase(it);
            break;
        }
    }
}

void calculeazaNrAbsente(int nrMatricol) {
    for(auto it = elevi.begin(); it != elevi.end(); it++) {
        if(it->getNumarMatricol() == nrMatricol) {
            cout << it->getPrenume() << " " << it->getNume() << endl << "Nr. Absente: " << it->getAbsente().size();
        }
    }
}



void init() {
    readElevi();
    readAbsente();
}

int main(int argc, char* argv[]) {

    init();

    if(strcmp(argv[1],"adauga_elev")==0)
        adaugaElev(argv[2],argv[3]);
    if(strcmp(argv[1],"sterge_elev")==0)
        stergeElev(stoi(argv[2]));
    if(strcmp(argv[1], "calculeaza_nr_absente")==0) {
        calculeazaNrAbsente(stoi(argv[2]));
    }


    writeElevi();


    return 0;
}

