// Dedfinición de la clase Actuador
// Autor: Alberto Hamilton
// Fecha: 2023-10-20

#ifndef _ACTUADOR_
#define _ACTUADOR_

#include "Dispositivo.hpp"

class Actuador : public Dispositivo {
private:

  float comando = 0.0;

public:

  virtual void setComando(float comando);

  virtual float getComando();

};

#endif
