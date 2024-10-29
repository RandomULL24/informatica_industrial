//Autor: Lucas Díaz Pérez
//Fecha: 22/10/2024

#include "Controlador.hpp"
#include <cmath>

void Controlador::setConsigna(float consigna) 
{
  this->consigna = consigna;
  
   if(! this->isEncendido())
    this->consigna = NAN;
}

float Controlador::getConsigna() 
{
  return this -> consigna;
}

void Controlador::setSensor(Sensor* sensor)
{
  this->sensorPt = sensor;
  
}

Sensor* Controlador::getSensor()
{
  return this->sensorPt;
}

void Controlador::setActuador(Actuador* actuador)
{
  this->actuadorPt = actuador;
}

Actuador* Controlador::getActuador()
{
  return this->actuadorPt;
}

float Controlador::calculaComando(float medida)
{
  return 0.0;
}
void Controlador::calculaEtapa(){

  //~ float medida = sensorPt->Sensor::getMedida();
  //~ float comando = calculaComando(medida);
  //~ actuadorPt->Actuador::setComando(comando);
 
}
