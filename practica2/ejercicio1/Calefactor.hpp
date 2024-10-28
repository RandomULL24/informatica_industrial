// Definición de la clase Valvula
// Autor: Lucas Díaz Pérez
// Fecha: 28/10/2024

#ifndef _CALEFACTOR_
#define _CALEFACTOR_

#include "Actuador.hpp"

class Calefactor : public Actuador {
protected:
  float potenciaMax;

public:
  Calefactor(float potenciaMaximo);

  // devolverá el caudal en este instante a la vista del caudal
  // máximo y el comando.
  float getPotencia();
};

#endif
