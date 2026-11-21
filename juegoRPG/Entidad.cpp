#include "Entidad.h"
#include <iostream>

Entidad::Entidad(std::string nombre, int vida, int danioBase, int defensa) {
	this->nombre = nombre;
	this->vida = vida;
	this->vidaMaxima = vida;
	this->danioBase = danioBase;
	this->defensa = defensa; 
}

void Entidad::recibirDanio(int cantidad) {
	int danioReal = cantidad - defensa; 

	if (danioReal < 0) {
		danioReal = 0;
	}

	vida -= danioReal;

	if (vida < 0) {
		vida = 0;
	}

	std::cout << nombre << " ha recibido " << danioReal << " puntos de danio y su vida es " << vida << std::endl;
}

bool Entidad::estaVivo() const {
	return vida > 0;
}

std::string Entidad::getNombre() const {
	return nombre;
}

int Entidad::getVida() const {
	return vida;
}

int Entidad::getDanioBase() const {
	return danioBase; 
}

int Entidad::getDefensa() const {
	return defensa;
}