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
    float Kp = NAN;
    float Ki = NAN;
    float ekAcum = 0; //Error acumulado
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
  
    void setKp(float Kp);
    float getKp() const;
    void setKi(float Ki);
    float getKi() const;
};

#endif
