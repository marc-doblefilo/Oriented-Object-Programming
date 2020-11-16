#include <iostream>
#include "ruleta.h"

Ruleta::Ruleta(const Crupier crupier) : crupier_(crupier){
    banca_ = 1000000;
    bola_ = -1;
}

bool Ruleta::setBola(int newBola) {
    if(newBola >= 0 && newBola <= 36) {
        bola_ = newBola;
        return true;
    }
    return false;
}

bool Ruleta::setBanca(int newBanca) {
    if(newBanca > 0) {
        banca_ = newBanca;
        return true;
    }
    return false;
}

bool Ruleta::addJugador(Jugador newJugador) {
    std::list<Jugador>::iterator it;
    for(it = jugadores_.begin(); it != jugadores_.end(); it++) {
        if(newJugador.getDNI() == it -> getDNI()) {
            return false;
        }
    }
    std::ifstream playerFile(newJugador.getDNI() + ".txt");
    if (((bool) playerFile) == false) {
        std::ofstream playerFile(newJugador.getDNI() + ".txt");
        playerFile.close();
    }
    playerFile.close();
    jugadores_.push_back(newJugador);
    return true;
}

int Ruleta::deleteJugador(std::string playerDNI) {
    if(jugadores_.empty()) {
        return -1;
    }

    std::list<Jugador>::iterator it;
    for(it = jugadores_.begin(); it != jugadores_.end(); it++) {
        if(it -> getDNI() == playerDNI) {
            jugadores_.erase(it);
            return 1;
        }
    }
    return -2;
}

int Ruleta::deleteJugador(Jugador jugador) {
    if(jugadores_.empty()) {
        return -1;
    }

    std::list<Jugador>::iterator it;
    for(it = jugadores_.begin(); it != jugadores_.end(); it++) {
        if(jugador.getDNI() == it -> getDNI()) {
            jugadores_.erase(it);
            return 1;
        }
    }
    return -2;
}

void Ruleta::escribeJugadores(){
    std::ofstream file("jugadores.txt");

    std::list<Jugador>::iterator it;
    for (it=jugadores_.begin(); it != jugadores_.end(); it++){
        file << it -> getDNI() << ","<<it -> getCodigo() << ","<< \
        it -> getNombre() <<"," << \
        it -> getApellidos() <<","<< it -> getDireccion() << "," << \
        it -> getLocalidad() <<","<<it -> getProvincia() <<","<< \
        it -> getPais() <<","<< it -> getDinero()<<std::endl;
    }
    file.close();
}

void Ruleta::leeJugadores(){
    jugadores_.clear();

    std::ifstream file("jugadores.txt");
    Jugador temporaryJugador("DNI", "CODIGO");
    std::list<Jugador>::iterator it;
    std::string value;
    while(getline(file, value, ',')) {
        temporaryJugador.setDNI(value);
        getline(file, value, ',');
        temporaryJugador.setCodigo(value);
        getline(file, value, ',');
        temporaryJugador.setNombre(value);
        getline(file, value, ',');
        temporaryJugador.setApellidos(value);
        getline(file, value, ',');
        temporaryJugador.setDireccion(value);
        getline(file, value, ',');
        temporaryJugador.setLocalidad(value);
        getline(file, value, ',');
        temporaryJugador.setProvincia(value);
        getline(file, value, ',');
        temporaryJugador.setPais(value);
        getline(file, value, '\n');
        temporaryJugador.setDinero(std::stoi(value));
        jugadores_.push_back(temporaryJugador);
    }
    file.close();
}

void Ruleta::giraRuleta() {
    srand(time(NULL));
    setBola(rand()%37);
}

std::string Ruleta::getPairOdd() {
    if(getBola() == 0) return "0";
    if((getBola()%2) == 0) {
        return "par";
    }
    else return "impar";
}

std::string Ruleta::getHighLow() {
    if(getBola() == 0) return "0";
    if(getBola() < 18) {
        return "bajo";
    }
    else return "alto";
}

std::string Ruleta::getColor() {
    if(getBola() == 0) return "0";
    int red[18] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
    
    for(int i = 0; i < 18; i++) {
        if(getBola() == red[i]) {
            return "rojo";
        }
    }
    return "negro";
}

void Ruleta::getPremios() {
    std::list<Jugador>::iterator it;

    std::list<Apuesta> apuestas;
    std::list<Apuesta>::iterator itapuestas;

    for(it = jugadores_.begin(); it != jugadores_.end(); it++) {
        it -> setApuestas();
        apuestas = it -> getApuestas();
        for(itapuestas = apuestas.begin(); itapuestas != apuestas.end(); itapuestas++) {
            switch(itapuestas -> tipo) {
                case 1: //Apuesta sencilla
                    if(std::stoi(itapuestas->valor) == getBola()) {
                        int profit = 35 * (itapuestas->cantidad);
                        it->setDinero(it->getDinero() + profit);
                        setBanca(getBanca() - profit);
                    }
                    else {
                        it->setDinero(it->getDinero() - itapuestas->cantidad);
                        setBanca(getBanca() + itapuestas->cantidad);
                    }
                    break;
                case 2: //Apuesta color
                    if(itapuestas-> valor == getColor()) {
                        it->setDinero(it->getDinero() + itapuestas->cantidad);
                        setBanca(getBanca() - itapuestas->cantidad);
                    }
                    else {
                        it->setDinero(it->getDinero() - itapuestas->cantidad);
                        setBanca(getBanca() + itapuestas->cantidad);
                    }
                    break;
                case 3: //Apuesta Pair/Odd
                    if(itapuestas-> valor == getPairOdd()) {
                        it->setDinero(it->getDinero() + itapuestas->cantidad);
                        setBanca(getBanca() - itapuestas->cantidad);
                    }
                    else {
                        it->setDinero(it->getDinero() - itapuestas->cantidad);
                        setBanca(getBanca() + itapuestas->cantidad);
                    }
                    break;
                case 4: //Apuesta High/Low
                    if(itapuestas-> valor == getHighLow()) {
                        it->setDinero(it->getDinero() + itapuestas->cantidad);
                        setBanca(getBanca() - itapuestas->cantidad);
                    }
                    else {
                        it->setDinero(it->getDinero() - itapuestas->cantidad);
                        setBanca(getBanca() + itapuestas->cantidad);
                    }
                    break;
            }
        }
    }
}