#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Jugador.h"
#include "Orco.h"
#include "Dragon.h"
#include "jefeFinal.h"
#include "Habitacion.h"

int main() {
	Jugador heroe("Arthur", 150, 18, 5);

	heroe.agregarObjeto(Objeto("Pocion de vida", "pocion", 60));
	heroe.agregarObjeto(Objeto("Pocion de vida", "pocion", 60));
	heroe.agregarObjeto(Objeto("Espada de acero", "arma", 15));
	heroe.agregarObjeto(Objeto("Escudo de hierro", "armadura", 6));

	Orco orco("Grom", 60, 10, 2);
	Dragon dragon("Ignis", 100, 16, 5);
	jefeFinal jefe("Malakor", 120, 18, 8);

	Habitacion entrada("Entrada de la Mazmorra", "Un pasillo humedo iluminado por antorchas.");
	Habitacion patio("Patio en Ruinas", "Columnas caidas rodean el lugar. Algo grune entre las sombras.");
	Habitacion caverna("Caverna Volcanica", "El calor es insoportable y el suelo esta cubierto de ceniza.");
	Habitacion trono("Salon del Trono Oscuro", "Una enorme sala donde aguarda el senor de la mazmorra.");

	entrada.agregarSalida("norte", &patio);
	patio.agregarSalida("sur", &entrada);
	patio.agregarSalida("este", &caverna);
	caverna.agregarSalida("oeste", &patio);
	caverna.agregarSalida("norte", &trono);
	trono.agregarSalida("sur", &caverna);

	patio.agregarEnemigo(&orco);
	caverna.agregarEnemigo(&dragon);
	trono.agregarEnemigo(&jefe);

	Habitacion* habitacionActual = &entrada;

	while (heroe.estaVivo() && jefe.estaVivo()) {
		if (habitacionActual->tieneEnemigosVivos()) {
			for (Entidad* enemigo : habitacionActual->getEnemigos()) {
				if (!enemigo->estaVivo()) {
					continue;
				}

				system("cls");
				std::cout << "=========================================" << std::endl;
				std::cout << "   UN NUEVO ENEMIGO APARECE: " << enemigo->getNombre() << std::endl;
				std::cout << "=========================================" << std::endl;
				system("pause");

				while (heroe.estaVivo() && enemigo->estaVivo()) {
					system("cls");
					std::cout << "=========================================" << std::endl;
					std::cout << heroe.getNombre() << " (HP: " << heroe.getVida() << ") VS "
						<< enemigo->getNombre() << " (HP: " << enemigo->getVida() << ")" << std::endl;
					std::cout << "=========================================" << std::endl;
					std::cout << "1. Atacar" << std::endl;
					std::cout << "2. Usar objeto de la mochila" << std::endl;
					std::cout << "Elige una opcion: ";

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
					std::cout << "Has caido en combate contra " << enemigo->getNombre() << "... GAME OVER." << std::endl;
					system("pause");
					return 0;
				}

				std::cout << "\nHas derrotado a " << enemigo->getNombre() << "!" << std::endl;
				system("pause");
			}
		}

		if (!jefe.estaVivo()) {
			break;
		}

		system("cls");
		habitacionActual->mostrarInfo();
		std::cout << "\n1. Moverse a otra habitacion" << std::endl;
		std::cout << "2. Usar objeto de la mochila" << std::endl;
		std::cout << "Elige una opcion: ";

		int opcionExplorar;
		std::cin >> opcionExplorar;
		std::cout << std::endl;

		if (opcionExplorar == 1) {
			std::string direccion;
			std::cout << "Escribe la direccion (norte, sur, este, oeste): ";
			std::cin >> direccion;

			Habitacion* siguiente = habitacionActual->getSalida(direccion);
			if (siguiente != nullptr) {
				habitacionActual = siguiente;
			}
			else {
				std::cout << "No hay salida en esa direccion." << std::endl;
				system("pause");
			}
		}
		else if (opcionExplorar == 2) {
			heroe.mostrarInventario();

			int indice;
			std::cout << "Elige el numero del objeto: ";
			std::cin >> indice;
			heroe.usarObjeto(indice - 1);
			std::cout << std::endl;
			system("pause");
		}
	}

	system("cls");
	std::cout << "=========================================" << std::endl;
	std::cout << "   VICTORIA! HAS COMPLETADO EL JUEGO     " << std::endl;
	std::cout << "=========================================" << std::endl;
	std::cout << heroe.getNombre() << " ha derrotado a todos los enemigos." << std::endl;
	system("pause");

	return 0;
}