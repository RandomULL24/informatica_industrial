//Autor: Lucas Díaz Pérez
//Fecha: 3/11/2024
#include "Planta.hpp"
#include "SensorNivel.hpp"
#include "Valvula.hpp"
#include <cmath>
#include <string>

#ifndef _PLANTA1TANQUENIVEL_
#define _PLANTA1TANQUENIVEL_

class Planta1TanqueNivel : public Planta
{
  private:
    SensorNivel senNivel;
    Valvula actValvula;
    std::string nombre;
    
    float hk = NAN;
    float A  = 2.0;
    float Z  = 0.1;
    float T  = 0.5;
  
  public:
    Planta1TanqueNivel(float caudalMaximo, float nivelMaximo);
    void setNombre(std::string nombre);
    
    SensorNivel* getSensorNivelPt();
    Valvula* getValvulaPt();
    void enciende();
    float getAltura();
    void calculaEtapa();
};

#endif
