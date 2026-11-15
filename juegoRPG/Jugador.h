#pragma once
#include <vector>
#include "Entidad.h"
#include "Objeto.h"

class Jugador : public Entidad {
private:
	std::vector<Objeto> inventario;
	int bonoArma; 
	int bonoArmadura; 

public: 
	Jugador(std::string nombre, int vidaMaxima, int danioBase, int defensa);
	void atacar(Entidad& objetivo) override;
	void recibirDanio(int cantidad) override;
	void agregarObjeto(Objeto item); 
	void mostrarInventario() const;
	void usarObjeto(int indice);
};