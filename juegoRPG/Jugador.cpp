#include "Jugador.h"
#include <iostream>

Jugador::Jugador(std::string nombre, int vidaMaxima, int danioBase, int defensa) : Entidad(nombre, vidaMaxima, danioBase, defensa) {
	bonoArma = 0;
	bonoArmadura = 0;
}

void Jugador::atacar(Entidad& objetivo) {
	int danioTotal = danioBase + bonoArma;

	std::cout << nombre << " ataca a " << objetivo.getNombre() << " por " << danioTotal << " de danio" << std::endl; 
	
	objetivo.recibirDanio(danioTotal);
}

void Jugador::recibirDanio(int cantidad) {
	int danioFinal = cantidad - bonoArmadura;

	if (danioFinal < 0) {
		danioFinal = 0;
	}

	Entidad::recibirDanio(danioFinal);
}

void Jugador::agregarObjeto(Objeto item) {
	inventario.push_back(item);

	std::cout << item.getNombre() << " agregado al inventario." << std::endl;
}

void Jugador::mostrarInventario() const {
	if (inventario.empty()) {
		std::cout << "El inventario esta vacio" << std::endl; 
		return; 
	}

	for (int i = 0; i < inventario.size(); i++) {
		std::cout << (i + 1) << ". " << inventario[i].getNombre() << " [" << inventario[i].getTipo() << "] (+" << inventario[i].getValor() << ")" << std::endl;
	}
}

void Jugador::usarObjeto(int indice) {
	if (indice < 0 || indice >= inventario.size()) {
		std::cout << "Indice de objeto invalido" << std::endl;
		return; 
	}
	Objeto item = inventario[indice];

	if (item.getTipo() == "pocion") {
		vida += item.getValor();

		if (vida > vidaMaxima) {
			vida = vidaMaxima;
		}

		std::cout << "Tomaste la pocion " << item.getNombre() << std::endl; 
	}
	else if (item.getTipo() == "arma") {
		bonoArma = item.getValor();

		std::cout << item.getNombre() << " Equipado" << std::endl;
	}
	else if (item.getTipo() == "armadura") {
		bonoArmadura = item.getValor();

		std::cout << item.getNombre() << " Equipado" << std::endl;
	}

	inventario.erase(inventario.begin() + indice);
}