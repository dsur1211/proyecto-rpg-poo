#pragma once
#include "Entidad.h"

class Dragon : public Entidad {
public:
	Dragon(std::string nombre, int vidaMaxima, int danioBase, int defensa);
	void atacar(Entidad& objetivo) override;
};