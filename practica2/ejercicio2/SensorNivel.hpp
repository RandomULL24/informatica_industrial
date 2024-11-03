// Dedfinición de la clase SensorNivel
// Autor: Alberto Hamilton
// Fecha: 2023-10-20

#ifndef _SENSORNIVEL_
#define _SENSORNIVEL_

#include "Sensor.hpp"
#include <cmath>


class SensorNivel : public Sensor {
private:
  float alturaMaxima;
  float alturaActual = NAN;

public:

  SensorNivel(float alturaMaxima);

  void setAltura(float altura);

  virtual float getMedida();
};

#endif
