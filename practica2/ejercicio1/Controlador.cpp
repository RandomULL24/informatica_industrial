//Autor: Lucas Díaz Pérez
//Fecha: 22/10/2024

#include "Controlador.hpp"

void Controlador::setConsigna(float consigna) 
{
  this->consigna = consigna;
}

float Controlador::getConsigna() 
{
  return this -> consigna;
}

void Controlador::setSensor(Sensor* sensor)
{
  this->sensor = sensor;
  
}

Sensor* Controlador::getSensor()
{
  return this->sensorPt;
}

void Controlador::setActuador(Actuador* actuador)
{
  return this->actuador = actuador;
}

Actuador* Controlador::getActuador()
{
  return this->actuadorPt;
}

float Controlador::calculaComando(float medida)
{
  return this->0.0;
}
void Controlador::calculaEtapa(){
  float medida = Sensor::getMedida();
  float resultado = Controlador::calculaComando(medida);
  Actuador::setComando(resultado);
}
