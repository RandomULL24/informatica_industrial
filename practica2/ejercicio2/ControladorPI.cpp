//Autor: Lucas Díaz Pérez
//Fecha: 22/10/2024

#include "ControladorPI.hpp"
#include "Dispositivo.hpp"
#include <cmath>
#include <iostream>

void Controlador::setConsigna(float consigna) 
{
  this->consigna = consigna;
  
  if(! this->isEncendido())
  {
    this->consigna = NAN;
    this->ekAcum = 0; //El error acumulado se resetea a 0 cada vez que se apaga
    //el controlador
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
  else
  {
    float ek = (this->consigna)-(medida);
    (this->ekAcum) += ek;
    comando = (this->Kp)*ek + (this->Ki)*(this->ekAcum); 
  }
  
  return comando;
}
void Controlador::calculaEtapa()
{

  float comando = NAN;
  float medida = NAN;
  
  
  if(!(sensorPt == nullptr)) //Si hay un sensor activo
  {
    medida = (this->sensorPt)->getMedida();
  }
  
  
  if(!(actuadorPt == nullptr)) //Si hay un actuador activo
  {
    if(sensorPt == nullptr) //Si NO hay un sensor activo
    {
      comando = (this->actuadorPt)->getComando();
      (this->actuadorPt)->setComando(comando);
    }
    else //Si hay un sensor activo
    {
      comando = calculaComando(medida);
      (this->actuadorPt)->setComando(comando);
    }
  }
 
}

void Controlador::setKp(float Kp)
{
  (this->Kp) = Kp;
}

float Controlador::getKp() const
{
  return (this->Kp);
}

void Controlador::setKi(float Ki)
{
  (this->Ki) = Ki;
}

float Controlador::getKi() const
{
  return (this->Ki);
}
