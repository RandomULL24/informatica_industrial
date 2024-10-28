// Autor: Alberto Hamilton

#define TITULO "Controlador → setConsigna, getConsigna"


#include "Controlador.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>


int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  std::cout << "- Creado controlador" << std::endl;
  Controlador cnt1;
  cnt1.setNombre("\tControlador");
  {
    pruebas++;
    float ma = cnt1.getConsigna();
    if (! std::isnan(ma))
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve "
          << ma <<" cuando se esperaba NaN" << std::endl;
  }

  std::cout << "- Fijamos consigna 0.5, pero apagado" << std::endl;
  cnt1.setConsigna(0.5);
  {
    pruebas++;
    float ma = cnt1.getConsigna();
    if (! std::isnan(ma))
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve "
          << ma <<" cuando se esperaba NaN" << std::endl;
  }

  std::cout << "- Encendemos controlador" << std::endl;
  cnt1.enciende();
  {
    pruebas++;
    float esperado = 0.5;
    cnt1.setConsigna(esperado);
    float ma = cnt1.getConsigna();
    if(ma != esperado)
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve consigna "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  std::cout << "- Fijamos consigna 0.45" << std::endl;
  cnt1.setConsigna(0.45);
  {
    pruebas++;
    float esperado = 0.45;
    cnt1.setConsigna(esperado);
    float ma = cnt1.getConsigna();
    if(ma != esperado)
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve consigna "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  std::cout << "- Fijamos consigna por encima de 1 " << std::endl;
  cnt1.setConsigna(1.03);
  {
    pruebas++;
    float esperado = 1.0;
    cnt1.setConsigna(esperado);
    float ma = cnt1.getConsigna();
    if(ma != esperado)
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve consigna "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  std::cout << "- Fijamos consigna por debajo de 0.0" << std::endl;
  cnt1.setConsigna(-0.001);
  {
    pruebas++;
    float esperado = 0.0;
    cnt1.setConsigna(esperado);
    float ma = cnt1.getConsigna();
    if(ma != esperado)
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve consigna "
          << ma <<" cuando se esperaba " << esperado << std::endl;
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
