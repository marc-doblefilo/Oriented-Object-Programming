#ifndef _CRUPIER_H_
#define _CRUPIER_H_

#include <iostream>
#include "persona.h"

class Crupier : public Persona {
    private:
        std::string codigo_;
    public:
        Crupier(const std::string dni, const std::string codigo, const std::string nombre="", const std::string apellidos="", int edad=0, \
        const std::string direccion="", const std::string localidad="", const std::string provincia="", \
        const std::string pais="");

        inline std::string getCodigo()const {return codigo_;}
        inline void setCodigo(std::string newCodigo) {codigo_ = newCodigo;}
};




#endif