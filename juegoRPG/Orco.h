#pragma once
#include "Entidad.h"

class Orco : public Entidad {
public:
	Orco(std::string nombre, int vidaMaxima, int danioBase, int defensa);
	void atacar(Entidad& objetivo) override; 
};