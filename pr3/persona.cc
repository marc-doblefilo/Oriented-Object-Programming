#include "persona.h"

Persona::Persona(const std::string dni, const std::string nombre, const std::string apellidos, int edad, \
        const std::string direccion, const std::string localidad, const std::string provincia, \
        const std::string pais) {
            setDNI(dni);
            setNombre(nombre);
            setApellidos(apellidos);
            setDireccion(direccion);
            setLocalidad(localidad);
            setProvincia(provincia);
            setPais(pais);
            setEdad(edad);
        }