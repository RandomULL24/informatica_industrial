//Autor: Lucas Díaz Pérez
//Fecha: 3/11/2024
#include <cmath>
#include "ControladorONOFF.hpp"
#include "Controlador.hpp"
#include "Dispositivo.hpp"
#include <cmath>
#include <iostream>

float ControladorONOFF::calculaComando(float medida) 
{
  //Obtenemos el valor de la clase madre que sólo ser accedida por métodos
  consigna = getConsigna(); 
  
  float comando = 0.0; //Modo OFF default
  
  if(consigna > medida) //Modo ON
  {
    comando = 1;
  }
  
  if(std::isnan(medida) || std::isnan(consigna))
  {
    comando = NAN;
  }
  
  //~ std::cerr << "Consigna: " << (this->consigna) << std::endl;
  //~ std::cerr << "Comando: " << comando << std::endl;
  return comando;
}

void ControladorONOFF::calculaEtapa() 
{ 

  float comando = NAN;
  float medida = NAN;
  
  //Obtenemos el valor de la clase madre que sólo ser accedida por métodos  
  sensorPt = getSensor();
  actuadorPt = getActuador();
  
  
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
