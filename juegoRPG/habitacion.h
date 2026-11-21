#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Entidad.h"

class Habitacion {
private:
    std::string nombre;
    std::string descripcion;
    std::vector<Entidad*> enemigos;
    std::map<std::string, Habitacion*> salidas;

public:
    Habitacion(std::string nombre, std::string descripcion);

    void agregarSalida(std::string direccion, Habitacion* destino);
    void agregarEnemigo(Entidad* enemigo);

    void mostrarInfo();
    Habitacion* getSalida(std::string direccion);
    std::vector<Entidad*>& getEnemigos();
    bool tieneEnemigosVivos();
    std::string getNombre();
};