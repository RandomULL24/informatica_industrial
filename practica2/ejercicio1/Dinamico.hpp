//Autor: Lucas Díaz Pérez
//Fecha: 22/10/2024

#ifndef _DINAMICO_
#define _DINAMICO_
#include "Dispositivo.hpp"

class Dinamico : public Dispositivo
{
  public:
    virtual void calculaEtapa() = 0; //Método virtual puro (virutal y 0)
};

#endif
