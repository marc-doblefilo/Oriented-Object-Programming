#ifndef _RULETA_H_
#define _RULETA_H_

#include "jugador.h"
#include "crupier.h"
#include <string>
#include <algorithm>
#include <fstream>

class Ruleta {
    private:
        int banca_;
        int bola_;
        std::list<Jugador> jugadores_;
        Crupier crupier_;
    public:
        Ruleta(const Crupier crupier);
        
        inline int getBanca()const {return banca_;};
        inline int getBola()const {return bola_;};
        inline Crupier getCrupier()const {return crupier_;};
        inline std::list<Jugador> getJugadores()const {return jugadores_;};
        
        bool setBola(int newBola);
        bool setBanca(int newBanca);
        inline void setCrupier(Crupier newCrupier) {crupier_ = newCrupier;};
        
        bool addJugador(Jugador newJugador);
        int deleteJugador(std::string playerDNI);
        int deleteJugador(Jugador jugador);
        void escribeJugadores();
        void leeJugadores();
        void giraRuleta();
        void getPremios();

        std::string getPairOdd();
        std::string getColor();
        std::string getHighLow();
};

#endif