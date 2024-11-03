// Definición de la clase Valvula
// Autor: Alberto Hamilton
// Fecha: 2023-10-20

#include "Valvula.hpp"

Valvula::Valvula(float caudalMaximo)
    : caudalMax(caudalMaximo) {

}

float Valvula::getCaudal() {
  // si alguno es NAN, el resultado será NAN.
  return this->getComando() * (this->caudalMax);
}
