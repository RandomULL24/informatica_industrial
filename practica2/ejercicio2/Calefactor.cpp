// Definición de la clase Valvula
// Autor: Lucas Díaz Pérez
// Fecha: 28/10/2024


#include "Calefactor.hpp"

Calefactor::Calefactor(float potenciaMaximo)
    : potenciaMax(potenciaMaximo) {

}

float Calefactor::getPotencia() {
  // si alguno es NAN, el resultado será NAN.
  return this->getComando() * (this->potenciaMax);
}
