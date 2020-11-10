#include "crupier.h"

Crupier::Crupier(const std::string dni, const std::string codigo, const std::string nombre, const std::string apellidos, int edad, \
        const std::string direccion, const std::string localidad, const std::string provincia, \
        const std::string pais) : Persona(dni,nombre,apellidos,edad,direccion,localidad,provincia,pais){
            setCodigo(codigo);
        }