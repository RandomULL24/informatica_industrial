// Autor: Alberto Hamilton
// Fecha: 2023-10-20

#include "Dispositivo.hpp"

unsigned Dispositivo::ultimoID = 0;

Dispositivo::Dispositivo() {
  Dispositivo::ultimoID++;
  this->id = ultimoID;
}

unsigned Dispositivo::getId() const {
  return this->id;
}

void Dispositivo::setNombre(std::string nombre) {
  this->nombre = nombre;
}


std::string Dispositivo::getNombre() const {
   return this->nombre;
}


void Dispositivo::enciende() {
  this->encendido = true;
}


void Dispositivo::apaga() {
  this->encendido = false;
}

bool Dispositivo::isEncendido() const  {
  return this->encendido;
}
