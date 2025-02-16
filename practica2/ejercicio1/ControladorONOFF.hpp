//Autor: Lucas Díaz Pérez
//Fecha: 3/11/2024
#include <cmath>
#ifndef _CONTROLADORONOFF_
#define _CONTROLADORONOFF_
#include "Dinamico.hpp"
#include "Actuador.hpp"
#include "Sensor.hpp"
#include "Controlador.hpp"

class ControladorONOFF : public Controlador
{
  private:
    float consigna = NAN;
    Sensor* sensorPt = nullptr;
    Actuador* actuadorPt = nullptr;
    
  public:
    float calculaComando(float medida);
    void calculaEtapa();
};

#endif
