//Autor: Lucas Díaz Pérez
//Fecha: 22/10/2024

#include "Dinamico.hpp"

Dinamico::Dinamico() : msPeriodo(500)
{
}
void Dinamico::setMsPeriodo(unsigned msPeriodo)
{
  (this->msPeriodo) = msPeriodo;
}
  
unsigned Dinamico::getMsPeriodo() const
{
  return this->msPeriodo;
}
