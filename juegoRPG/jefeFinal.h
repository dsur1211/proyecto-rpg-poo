#pragma once
#include "Entidad.h"

class jefeFinal : public Entidad {
public: 
	jefeFinal(std::string nombre, int vidaMaxima, int danioBase, int defensa);
	void atacar(Entidad& objetivo) override; 
};