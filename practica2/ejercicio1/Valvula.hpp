// Definición de la clase Valvula
// Autor: Alberto Hamilton
// Fecha: 2023-10-20

#ifndef _VALVULA_
#define _VALVULA_

#include "Actuador.hpp"

class Valvula : public Actuador {
protected:
  float caudalMax;

public:
  Valvula(float caudalMaximo);

  // devolverá el caudal en este instante a la vista del caudal
  // máximo y el comando.
  float getCaudal();
};

#endif
