#include "Habitacion.h"

Habitacion::Habitacion(std::string nombre, std::string descripcion) {
    this->nombre = nombre;
    this->descripcion = descripcion;
}

void Habitacion::agregarSalida(std::string direccion, Habitacion* destino) {
    salidas[direccion] = destino;
}

void Habitacion::agregarEnemigo(Entidad* enemigo) {
    enemigos.push_back(enemigo);
}

void Habitacion::mostrarInfo() {
    std::cout << "=========================================" << std::endl;
    std::cout << "UBICACION: " << nombre << std::endl;
    std::cout << descripcion << std::endl;
    std::cout << "=========================================" << std::endl;
    std::cout << "Salidas disponibles: ";
    for (auto const& salida : salidas) {
        std::cout << "[" << salida.first << "] ";
    }
    std::cout << std::endl;
}

Habitacion* Habitacion::getSalida(std::string direccion) {
    if (salidas.find(direccion) != salidas.end()) {
        return salidas[direccion];
    }
    return nullptr;
}

std::vector<Entidad*>& Habitacion::getEnemigos() {
    return enemigos;
}

bool Habitacion::tieneEnemigosVivos() {
    for (Entidad* enemigo : enemigos) {
        if (enemigo->estaVivo()) {
            return true;
        }
    }
    return false;
}

std::string Habitacion::getNombre() {
    return nombre;
}