#include "Dragon.h"
#include <iostream>

Dragon::Dragon(std::string nombre, int vidaMaxima, int danioBase, int defensa) : Entidad(nombre, vidaMaxima, danioBase, defensa){}

void Dragon::atacar(Entidad& objetivo) {
	int danioTotal = danioBase + 8;

	std::cout << nombre << " lanza su aliento de fuego contra " << objetivo.getNombre() << " por " << danioTotal << " de danio" << std::endl;

	objetivo.recibirDanio(danioTotal);
}