// Definición de la clase SensorTemperatura
// Autor: Lucas Díaz Pérez
// Fecha: 22/10/2024

#include "SensorTemperatura.hpp"

SensorTemperatura::SensorTemperatura(float temperaturaMinima, 
    float temperaturaMaxima)
{
  this->temperaturaMinima = temperaturaMinima;
  this->temperaturaMaxima = temperaturaMaxima;
}

void SensorTemperatura::setTemperatura(float temperatura)
{
  this->temperaturaActual = temperatura;
}
  
float SensorTemperatura::getMedida() 
{
  
  bool encendido = this->isEncendido();
  
 
  
  float M = (this->temperaturaActual - this->temperaturaMinima)/
      (this->temperaturaMaxima - this->temperaturaMinima);
      
  if(!encendido) //Si está apagado
  {
    M = NAN;
  }
  
  if(temperaturaActual < temperaturaMinima) //Si es menor que la temperatura mínima
  {
    M = 0;
  }
  
  if(temperaturaActual > temperaturaMaxima) //Si es mayor que la temperatura máxima
  {
    M = 1;
  }
  
  return M;
}
