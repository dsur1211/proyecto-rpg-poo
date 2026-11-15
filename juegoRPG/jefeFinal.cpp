#include "jefeFinal.h"
#include <iostream>

jefeFinal::jefeFinal(std::string nombre, int vidaMaxima, int danioBase, int defensa) : Entidad(nombre, vidaMaxima, danioBase, defensa) {}

void jefeFinal::atacar(Entidad& objetivo) {
	int danioTotal = danioBase + 12;

	std::cout << nombre << " desata un golpe oscuro contra " << objetivo.getNombre() << " por " << danioTotal << " de danio" << std::endl;

	objetivo.recibirDanio(danioTotal);
}