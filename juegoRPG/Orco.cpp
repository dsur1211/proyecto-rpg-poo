#include "Orco.h"
#include <iostream>

Orco::Orco(std::string nombre, int vidaMaxima, int danioBase, int defensa) : Entidad(nombre, vidaMaxima, danioBase, defensa) {}

void Orco::atacar(Entidad& objetivo) {
	int danioTotal = danioBase + 2;

	std::cout << nombre << " golpea con su garrote a " << objetivo.getNombre() << " por " << danioTotal << " de danio" << std::endl; 

	objetivo.recibirDanio(danioTotal);
}