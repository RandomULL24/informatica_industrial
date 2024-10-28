//Autor: Lucas Díaz Pérez
//Fecha: 22/10/2024

#ifndef _DINAMICO_
#define _DINAMICO_

class Dinamico : public Dipositivo
{
  public:
    virtual void calculaEtapa() = 0; //Método virtual puro (virutal y 0)
}

#endif
