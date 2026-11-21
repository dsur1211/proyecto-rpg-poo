#include <iostream>
#include <vector>
#include "Jugador.h"
#include "Orco.h"
#include "Dragon.h"
#include "jefeFinal.h"
#include <cstdlib>

int main() {
	Jugador heroe("Arthur", 150, 18, 6);

	heroe.agregarObjeto(Objeto("Pocion de vida", "pocion", 45));
	heroe.agregarObjeto(Objeto("Espada de acero", "arma", 15));
	heroe.agregarObjeto(Objeto("Escudo de hierro", "armadura", 10));

	Orco orco("Grom", 60, 10, 2);
	Dragon dragon("Ignis", 100, 16, 5);
	jefeFinal jefe("Malakor", 150, 22, 8);

	std::vector<Entidad*> enemigos = { &orco, &dragon, &jefe };

	for (Entidad* enemigo : enemigos) {
		system("cls");
		std::cout << "=========================================" << std::endl;
		std::cout << "	UN NUEVO ENEMIGO APARECE: " << enemigo->getNombre() << std::endl;
		std::cout << "=========================================" << std::endl;
		system("pause");

		while (heroe.estaVivo() && enemigo->estaVivo()) {
			system("cls");
			std::cout << "=========================================" << std::endl;
			std::cout << heroe.getNombre() << " (HP: " << heroe.getVida() << ") VS " << enemigo->getNombre() << " (HP: " << enemigo->getVida() << ")" << std::endl;
			std::cout << "1. Atacar" << std::endl;
			std::cout << "2. Usar objeto de la mochila" << std::endl;
			std::cout << "Elige una opcion; ";

			int opcion;
			std::cin >> opcion;
			std::cout << std::endl;

			if (opcion == 1) {
				heroe.atacar(*enemigo);
			}
			else if (opcion == 2) {
				heroe.mostrarInventario();

				int indice;
				std::cout << "Elige el numero del objeto: ";
				std::cin >> indice;
				heroe.usarObjeto(indice - 1);
			}

			if (enemigo->estaVivo()) {
				enemigo->atacar(heroe);
			}

			std::cout << std::endl;
			system("pause");
		}

		if (!heroe.estaVivo()) {
			system("cls");
			std::cout << "Has caido en cambate contra " << enemigo->getNombre() << "... GAME OVER" << std::endl;
			system("pause");
			return 0;
		}

		std::cout << "\nHas derrotado a " << enemigo->getNombre() << std::endl;
		system("pause");
	}

	system("cls");
	std::cout << "=========================================" << std::endl;
	std::cout << "	VICTORIA! HAS COMPLETADO EL JUEGO	" << std::endl;
	std::cout << "=========================================" << std::endl;
	std::cout << heroe.getNombre() << " ha derrotado a todos los enemigos " << std::endl;
	system("pause");

	return 0;
}