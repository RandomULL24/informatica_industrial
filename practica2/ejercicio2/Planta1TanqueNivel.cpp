//Autor: Lucas Díaz Pérez
//Fecha: 3/11/2024
#include "Planta1TanqueNivel.hpp"
#include "Planta.hpp"
#include "SensorNivel.hpp"
#include "Valvula.hpp"
#include <cmath>
#include <string>
#include <iostream>

//Instanciamos los valores de la función.
Planta1TanqueNivel::Planta1TanqueNivel(float caudalMaximo, float nivelMaximo) : 
    senNivel(nivelMaximo), actValvula(caudalMaximo)
{
}

void Planta1TanqueNivel::setNombre(std::string nombre)
{
 this->Planta::setNombre(nombre); 
 (this->senNivel).setNombre(nombre + " SenNivel");
 (this->actValvula).setNombre(nombre + " Valvula");
 
}

SensorNivel* Planta1TanqueNivel::getSensorNivelPt()
{
  return &(this->senNivel);
}

Valvula* Planta1TanqueNivel::getValvulaPt()
{
  return &(this->actValvula);
}

void Planta1TanqueNivel::enciende()
{
  (this->senNivel).enciende();
  (this->actValvula).enciende();
  this->Planta::enciende();
  
  //Si la planta se enciende el valor de hk=0.0
  (this->hk) = 0.0;

}

float Planta1TanqueNivel::getAltura()
{
  return this->hk;
}

void Planta1TanqueNivel::calculaEtapa()
{
  
  (this->T) = getMsPeriodo();
  
  hk = (this->hk) + ((this->T)/(this->A))*((this->actValvula.getCaudal())
      - (this->Z)*sqrt(this->hk));
          float setValorA(float A);
    float setValorZ(float Z);
  (this->hk) = hk;
}

void Planta1TanqueNivel::setValorA(float A)
{
  (this->A) = A;
}

void Planta1TanqueNivel::setValorZ(float Z)
{
  (this->Z) = Z;
}

float Planta1TanqueNivel::getValorA()
{
    return this->A;
}

float Planta1TanqueNivel::getValorZ()
{
  return this->Z;
}
