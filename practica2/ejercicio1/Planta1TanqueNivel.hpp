//Autor: Lucas Díaz Pérez
//Fecha: 3/11/2024
#include "Planta.hpp"
#include "SensorNivel.hpp"
#include "Valvula.hpp"
#include <cmath>

#ifndef _PLANTA1TANQUENIVEL_
#define _PLANTA1TANQUENIVEL_

class Planta1TanqueNivel : public Planta
{
  private:
    SensorNivel senNivel(float alturaMaxima);
    Valvula actValvula(float caudalMax);
    
    float hk = NAN;
    float A = 2.0;
    float Z = 0.1;
    float T = 0.5;
  
  public:
    void setNombre(std::string nombre);
    SensorNivel* getSensorNivelPt();
    Valvula* getValvulaPt();
    void enciende();
    float getAltura;
    void calculaEtapa();
};

#endif
