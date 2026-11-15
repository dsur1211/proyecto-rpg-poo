#include "Objeto.h"
#include <iostream>

Objeto::Objeto(std::string nombre, std::string tipo, int valor) {
	this->nombre = nombre;
	this->tipo = tipo;
	this->valor = valor;
}

std::string Objeto::getNombre() const {
	return nombre;
}

std::string Objeto::getTipo() const {
	return tipo; 
}

int Objeto::getValor() const {
	return valor;
}