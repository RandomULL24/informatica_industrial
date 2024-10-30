//Autor: Lucas Díaz Pérez
//Fecha: 22/10/2024

#include "Controlador.hpp"
#include "Dispositivo.hpp"
#include <cmath>
#include <iostream>

void Controlador::setConsigna(float consigna) 
{
  this->consigna = consigna;
  
  if(! this->isEncendido())
  {
    this->consigna = NAN;
  } 
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
  float comando = 0.0;
  
  if(std::isnan(medida))
  {
    comando = NAN;
  }
  
  return comando;
}
void Controlador::calculaEtapa()
{

  float comando = NAN;
  float medida = NAN;
  
  
  if(!(sensorPt == nullptr))
  {
    medida = (this->sensorPt)->getMedida();
  }
  
  
  if(!(actuadorPt == nullptr))
  {
    if(sensorPt == nullptr)
    {
      comando = (this->actuadorPt)->getComando();
      (this->actuadorPt)->setComando(comando);
    }
    else
    {
      comando = calculaComando(medida);
      (this->actuadorPt)->setComando(comando);
    }
  }
 
}
