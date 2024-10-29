//Autor: Lucas Díaz Pérez
//Fecha: 22/10/2024
#include <cmath>
#ifndef _CONTROLADOR_
#define _CONTROLADOR_
#include "Dinamico.hpp"
#include "Actuador.hpp"
#include "Sensor.hpp"

class Controlador : public Dinamico
{
  private:
    float consigna = NAN;
    Sensor* sensorPt = nullptr;
    Actuador* actuadorPt = nullptr;
    
  public:
  
  void setConsigna(float consigna);
  float getConsigna();
  void setSensor(Sensor* sensor);
  Sensor* getSensor();

  void setActuador(Actuador* actuador);
  Actuador* getActuador();
  float calculaComando(float medida);
  void calculaEtapa();
  
};

#endif
