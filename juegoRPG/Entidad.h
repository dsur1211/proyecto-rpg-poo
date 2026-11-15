#pragma once
#include <string>

class Entidad {
protected:
	std::string nombre;
	int vida;
	int vidaMaxima;
	int danioBase;
	int defensa;

public:
	Entidad(std::string nombre, int vida, int danioBase, int defensa = 0);
	virtual ~Entidad() = default; 
	virtual void atacar(Entidad& objetivo) = 0;
	void recibirDanio(int cantidad);
	bool estaVivo() const;
	std::string getNombre() const; 
	int getVida() const;
	int getDanioBase() const; 
	int getDefensa() const; 
};