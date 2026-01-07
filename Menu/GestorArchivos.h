#pragma once
#include"Dependencias.h"

struct Registro {
    char nombre[50];
    int puntaje;
};


class GestorArchivos
{
private:

    void GuardarEnArchivo(vector<Registro>& lista) {
        ofstream escritor;
        escritor.open("files/puntajes.dat", ios::out | ios::binary);

        if (escritor.is_open()) {
            for (int i = 0; i < lista.size(); i++) {
                // Escribe el bloque de memoria exacto de cada Registro
                escritor.write((char*)&lista[i], sizeof(Registro));
            }
            escritor.close();
        }
    }

public:
    GestorArchivos() {
    }
    ~GestorArchivos() {}

    vector<Registro> ObtenerRecords() {
        vector<Registro> records;
        ifstream lector;

        lector.open("files/puntajes.dat", ios::in | ios::binary);

        if (lector.is_open()) {
            Registro regTemp;
            while (lector.read((char*)&regTemp, sizeof(Registro))) {
                records.push_back(regTemp);
            }
            lector.close();
        }

        //if (records.size() > 5) {
        //    records.erase(records.begin() + 5, records.end());
        //}


        return records;
    }


    void ActualizarRanking(string NombreJugador, int puntajeJugador) {
        vector<Registro> lista = ObtenerRecords();

        Registro nuevo;
        nuevo.puntaje = puntajeJugador;

        int longitud = NombreJugador.size();

        if (longitud > 49) longitud = 49;

        for (int i = 0; i < longitud; i++) {
            nuevo.nombre[i] = NombreJugador[i];
        }
        nuevo.nombre[longitud] = '\0';

        lista.push_back(nuevo);

        for (int i = 0; i < lista.size(); i++) {
            for (int j = 0; j < lista.size() - 1; j++) {


                /*  if (lista[j] < lista[j + 1]) {
                      int temp = lista[j];
                      lista[j] = lista[j + 1];
                      lista[j + 1] = temp;
                  }*/
                if (lista[j].puntaje < lista[j + 1].puntaje) {
                    Registro aux = lista[j];
                    lista[j] = lista[j + 1];
                    lista[j + 1] = aux;
                }


            }
        }


        const size_t MAX_RECORDS = 5;
        if (lista.size() > MAX_RECORDS) {
            while (lista.size() > MAX_RECORDS) {
                lista.pop_back();
            }

        }
        



        //ofstream escritor;
        //escritor.open("files/puntajes.txt", ios::out);
        //if (escritor.is_open()) {
        //    for (int i = 0; i < lista.size(); i++) {
        //        escritor << lista[i].nombre << " " << lista[i].puntaje << endl;
        //    }
        //    escritor.close();
        //}



        GuardarEnArchivo(lista);
    }





};

