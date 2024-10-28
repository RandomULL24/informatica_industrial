// Dedfinición de la clase Actuador
// Autor: Alberto Hamilton
// Fecha: 2023-10-20

#include "Actuador.hpp"
#include <cmath>

void Actuador::setComando(float comando) {
  if (comando > 1.0)
    comando = 1.0;

  if (comando < 0.0)
    comando = 0.0;

  this->comando = comando;
}

float Actuador::getComando() {

  if (! this->isEncendido())
    return NAN;

  return this->comando;

}
