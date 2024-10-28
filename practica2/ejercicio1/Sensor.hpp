// Definición de la clase Sensor
// Autor: Alberto Hamilton
// Fecha: 2023-10-20

#ifndef _SENSOR_
#define _SENSOR_

#include "Dispositivo.hpp"

class Sensor : public Dispositivo {

public:

  virtual float getMedida() = 0;

};

#endif
