// Autor: Alberto Hamilton

#define TITULO "Calefactor → getPotencia"


#include "Calefactor.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  float maxPotencia = 12.80;
  std::cout << "- Creado Calefactor con potencia máxima "
      << maxPotencia << std::endl;
  Calefactor cal1(maxPotencia);
  {
    pruebas++;
    std::cout << "- Pedimos comando pero apagado" << std::endl;
    float ma = cal1.getPotencia();
    if (! std::isnan(ma))
      std::cout << "FALLO " << ++fallos << ": el calefactor devuelve "
          << ma <<" cuando se esperaba NaN" << std::endl;
  }

  std::cout << "- Fijamos comando a 0.0, pero apagado" << std::endl;
  cal1.setComando(0.0);
  {
    pruebas++;
    float ma = cal1.getPotencia();
    if (! std::isnan(ma))
      std::cout << "FALLO " << ++fallos << ": el calefactor devuelve "
          << ma <<" cuando se esperaba NaN porque está apagado" << std::endl;
  }

  std::cout << "- Encendemos Calefactor" << std::endl;
  cal1.enciende();
  {
    pruebas++;
    float espera = 0.0;
    float ma = cal1.getPotencia();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": el calefactor devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
  }

  std::cout << "- Fijamos comando a 1.0" << std::endl;
  cal1.setComando(1.0);
  {
    pruebas++;
    float espera = maxPotencia;
    float ma = cal1.getPotencia();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": el calefactor devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
  }

  std::cout << "- Fijamos comando a 0.5" << std::endl;
  cal1.setComando(0.5);
  {
    pruebas++;
    float espera = maxPotencia / 2.0;
    float ma = cal1.getPotencia();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": el calefactor devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
  }

  std::cout << "- Fijamos comando a 0.25" << std::endl;
  cal1.setComando(0.25);
  {
    pruebas++;
    float espera = maxPotencia / 4.0;
    float ma = cal1.getPotencia();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": el calefactor devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
  }

  std::cout << "- Fijamos comando negativo" << std::endl;
  cal1.setComando(-0.11);
  {
    pruebas++;
    float espera = 0.0;
    float ma = cal1.getPotencia();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": el calefactor devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
  }

  std::cout << "- Fijamos comando mayor de 1.0" << std::endl;
  cal1.setComando(1.0005);
  {
    pruebas++;
    float espera = maxPotencia;
    float ma = cal1.getPotencia();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": el calefactor devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
  }



  // Resumen final
  if (fallos == 0)
    std::cout << "\n :-) Todas las " << pruebas
        << " pruebas correctas (100% exito)\n" << std::endl;
  else
    std::cout << "\n :-( Se han producido " << fallos << " FALLOs de "
        << pruebas << " pruebas (" << std::fixed <<  std::setprecision(0)
        << (100 - fallos*100.0/pruebas) << "% éxito)"
        << std::endl;
  return fallos;
}
