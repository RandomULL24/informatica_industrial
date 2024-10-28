// Definición de la clase SensorTemperatura
// Autor: Lucas Díaz Pérez
// Fecha: 22/10/2024

#ifndef _SENSORTEMPERATURA_
#define _SENSORTEMPERATURA_

#include "Sensor.hpp"
#include <cmath>


class SensorTemperatura: public Sensor {
private:

  float temperaturaMinima = 12.6; // temperatura mínima que le pasó el constructor
  float temperaturaMaxima = 20.9; // temp máxima que se puede leer
  float temperaturaActual = NAN; // temp actual

public:

  SensorTemperatura(float temperaturaMinima, float temperaturaMaxima);

  void setTemperatura(float temperatura);
  
  virtual float getMedida() override;
};

#endif
