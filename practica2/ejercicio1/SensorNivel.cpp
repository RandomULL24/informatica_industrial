// Dedfinición de la clase SensorNivel

#include "SensorNivel.hpp"

SensorNivel::SensorNivel(float alturaMaxima) {
  this->alturaMaxima = alturaMaxima;
}

void SensorNivel::setAltura(float altura) {
  this->alturaActual = altura;
}

float SensorNivel::getMedida() {

  
  if(! this->isEncendido())
  {
    return NAN;
  }
  else
  {
    if (this->alturaActual < 0.0)
    {
      return 0.0;
    }
    else if (this->alturaActual > this->alturaMaxima)
    {
      return 1.0;
    }
    else
    {
      return (this->alturaActual / this->alturaMaxima);
    }
  }
}
