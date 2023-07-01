
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

void Elev::adaugareAbsenta(Absenta absenta) {
    this->absente.push_back(absenta);
}
std::string serializareElevi(const std::vector<Elev>& elevi) {
    std::string json = "[";

    for (size_t i = 0; i < elevi.size(); i++) {
        const Elev& elev = elevi[i];

        json += "{";
        json += "\"numarMatricol\":" + std::to_string(elev.numarMatricol) + ",";
        json += "\"prenume\":\"" + elev.prenume + "\",";
        json += "\"nume\":\"" + elev.nume + "\",";
        json += "\"materii\":[";

        for (size_t j = 0; j < elev.materii.size(); j++) {
            Materie materie = elev.materii[j];

            json += "{";
            json += "\"materie\":\"" + materie.getNume() + "\",";
            json += "\"teza\":" + std::to_string(materie.getTeza()) + ",";
            json += "\"note\":[";

            for (size_t k = 0; k < materie.getNote().size(); k++) {
                Nota nota = materie.getNote()[k];

                json += "{";
                json += "\"valoare\":" + std::to_string(nota.getValoare()) + ",";
                json += "\"data\":{";
                json += "\"zi\":" + std::to_string(nota.getData().getZi()) + ",";
                json += "\"luna\":" + std::to_string(nota.getData().getLuna()) + ",";
                json += "\"an\":" + std::to_string(nota.getData().getAn());
                json += "}";
                json += "}";

                if (k != materie.getNote().size() - 1) {
                    json += ",";
                }
            }

            json += "],";
            json += "\"absente\":[";

            for (size_t k = 0; k < materie.getAbsente().size(); k++) {
                Absenta absenta = materie.getAbsente()[k];

                json += "{";
                json += "\"motivata\":" + std::string(absenta.getMotivata() ? "true" : "false") + ",";
                json += "\"data\":{";
                json += "\"zi\":" + std::to_string(absenta.getData().getZi()) + ",";
                json += "\"luna\":" + std::to_string(absenta.getData().getLuna()) + ",";
                json += "\"an\":" + std::to_string(absenta.getData().getAn());
                json += "}";
                json += "}";

                if (k != materie.getAbsente().size() - 1) {
                    json += ",";
                }
            }

            json += "}";

            if (j != elev.materii.size() - 1) {
                json += ",";
            }
        }

        json += "],";
        json += "\"absente\":[";

        for (size_t j = 0; j < elev.absente.size(); j++) {
            Absenta absenta = elev.absente[j];

            json += "{";
            json += "\"motivata\":" + std::string(absenta.getMotivata() ? "true" : "false") + ",";
            json += "\"data\":{";
            json += "\"zi\":" + std::to_string(absenta.getData().getZi()) + ",";
            json += "\"luna\":" + std::to_string(absenta.getData().getLuna()) + ",";
            json += "\"an\":" + std::to_string(absenta.getData().getAn());
            json += "}";
            json += "}";

            if (j != elev.absente.size() - 1) {
                json += ",";
            }
        }

        json += "}";
        json += (i != elevi.size() - 1) ? "," : "";
    }

    json += "]";

    return json;
}

std::vector<Elev> deserializareElevi(const std::string& json) {
    std::vector<Elev> elevi;

    std::istringstream iss(json);
    std::string token;

    // Parsare JSON și deserializare
    while (iss >> token) {
        // Omiterea separatorilor (',', ':', '[', ']')
        if (token == "{" || token == "}" || token == "[" || token == "]") {
            continue;
        }

        if (token == "\"numarMatricol\":") {
            // Începem deserializarea unui elev
            int numarMatricol;
            iss >> numarMatricol;
            elevi.push_back(Elev("", ""));
            elevi.back().numarMatricol = numarMatricol;
        }
        else if (token == "\"prenume\":\"") {
            // Deserializăm prenumele elevului
            std::string prenume;
            std::getline(iss >> std::ws, prenume, '\"');
            elevi.back().prenume = prenume;
        }
        else if (token == "\"nume\":\"") {
            // Deserializăm numele elevului
            std::string nume;
            std::getline(iss >> std::ws, nume, '\"');
            elevi.back().nume = nume;
        }
        else if (token == "\"materii\":[") {
            // Începem deserializarea materiilor elevului
            elevi.back().materii.push_back(Materie());
        }
        else if (token == "\"materie\":\"") {
            // Deserializăm numele materiei
            std::string materie;
            std::getline(iss >> std::ws, materie, '\"');
            elevi.back().materii.back().setNume(materie);
        }
        else if (token == "\"teza\":") {
            // Deserializăm teza materiei
            int teza;
            iss >> teza;
            elevi.back().materii.back().setTeza(teza);
        }
        else if (token == "\"note\":[") {
            // Începem deserializarea notelor materiei
        }
        else if (token == "{\"valoare\":") {
            // Deserializăm valoarea notei
            int valoare;
            iss >> valoare;
            elevi.back().materii.back().note.push_back(Nota());
            elevi.back().materii.back().note.back().valoare = valoare;
        }
        else if (token == "\"data\":{") {
            // Deserializăm data notei
            Data data;
            iss >> token; // "zi":
            iss >> data.zi;
            iss >> token; // "luna":
            iss >> data.luna;
            iss >> token; // "an":
            iss >> data.an;
            elevi.back().materii.back().note.back().data = data;
            iss >> token; // }
        }
        else if (token == "\"absente\":[") {
            // Începem deserializarea absențelor materiei
        }
        else if (token == "{\"motivata\":") {
            // Deserializăm motivarea absenței
            bool motivata;
            iss >> std::boolalpha >> motivata;
            elevi.back().materii.back().absente.push_back(Absenta());
            elevi.back().materii.back().absente.back().motivata = motivata;
        }
        else if (token == "\"data\":{") {
            // Deserializăm data absenței
            Data data;
            iss >> token; // "zi":
            iss >> data.zi;
            iss >> token; // "luna":
            iss >> data.luna;
            iss >> token; // "an":
            iss >> data.an;
            elevi.back().materii.back().absente.back().data = data;
            iss >> token; // }
        }
    }

    return elevi;
}

/*void Elev::getAbsente() {
    string temp = "";
    for (auto it = absente.begin();it!= absente.end();it++)
    {
        temp += it->getData();

    }
}*/