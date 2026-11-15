#pragma once
#include <string>

class Objeto {
private:
	std::string nombre;
	std::string tipo;
	int valor;

public:
	Objeto(std::string nombre, std::string tipo, int valor);
	std::string getNombre() const;
	std::string getTipo() const;
	int getValor() const;
};