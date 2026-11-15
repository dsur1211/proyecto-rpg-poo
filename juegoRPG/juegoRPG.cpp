#include <iostream>
#include <vector>
#include "Jugador.h"
#include "Orco.h"
#include "Dragon.h"
#include "jefeFinal.h"

int main() {
	Jugador heroe("Arthur", 120, 15, 5);

	heroe.agregarObjeto(Objeto("Pocion de vida", "pocion", 35));
	heroe.agregarObjeto(Objeto("Espada de acero", "arma", 10));
	heroe.agregarObjeto(Objeto("Escudo de hierro", "armadura", 6)); 

	Orco orco("Grom", 60, 10, 2);
	Dragon dragon("Ignis", 100, 16, 5);
	jefeFinal jefe("Malakor", 150, 22, 8);

	std::vector<Entidad*> enemigos = { &orco, &dragon, &jefe };

	return 0; 
}