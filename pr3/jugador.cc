#include "jugador.h"
#include <fstream>

Jugador::Jugador(const std::string dni, const std::string codigo, const std::string nombre, const std::string apellidos, int edad, \
        const std::string direccion, const std::string localidad, const std::string provincia, \
        const std::string pais) : Persona(dni,nombre,apellidos,edad,direccion,localidad,provincia,pais){
            setDNI(dni);
            setCodigo(codigo);
            setDinero(1000);
        }

void Jugador::setApuestas() {
    apuestas_.clear();
    std::string valor;
    std::ifstream file(getDNI() + ".txt");

    getline(file,valor,',');
    while(!file.eof()){
        Apuesta ap;
        ap.tipo = std::stoi(valor);
        getline(file,valor,',');
        ap.valor = valor;
        getline(file, valor, '\n');
        ap.cantidad = std::stoi(valor);
        apuestas_.push_back(ap);
        getline(file,valor,',');
    }
    file.close();
}