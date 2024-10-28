// Autor: Alberto Hamilton

#define TITULO "Actuador → setComando, getComando"


#include "Actuador.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>


int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  Actuador ac1;
  std::cout << "- Creado actuador" << std::endl;
  {
    std::cout << "- Pedimos comando pero apagado" << std::endl;
    pruebas++;
    float ma = ac1.getComando();
    if (! std::isnan(ma))
      std::cout << "FALLO " << ++fallos << ": el actuador devuelve "
          << ma <<" cuando se esperaba NaN" << std::endl;
  }

  ac1.enciende();
  {
    std::cout << "- Encendemos → comando 0.0" << std::endl;
    pruebas++;
    float espera = 0.0;
    float ma = ac1.getComando();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": el actuador devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
  }

  ac1.setComando(1.0);
  std::cout << "- Fijamos comando a 1.0" << std::endl;
  {
    pruebas++;
    float espera = 1.0;
    float ma = ac1.getComando();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": el actuador devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
  }

  ac1.setComando(0.0);
  std::cout << "- Fijamos comando a 0.0" << std::endl;
  {
    pruebas++;
    float espera = 0.0;
    float ma = ac1.getComando();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": el actuador devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
  }

  ac1.setComando(0.5);
  std::cout << "- Fijamos comando a 0.5" << std::endl;
  {
    pruebas++;
    float espera = 0.5;
    float ma = ac1.getComando();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": el actuador devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
  }

  ac1.setComando(0.25);
  std::cout << "- Fijamos comando a 0.25" << std::endl;
  {
    pruebas++;
    float espera = 0.25;
    float ma = ac1.getComando();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": el actuador devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
  }

  ac1.setComando(-0.01);
  std::cout << "- Fijamos comando negativo" << std::endl;
  {
    pruebas++;
    float espera = 0.0;
    float ma = ac1.getComando();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": el actuador devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
  }

  ac1.setComando(1.001);
  std::cout << "- Fijamos comando mayor que 1.0 " << std::endl;
  {
    pruebas++;
    float espera = 1.0;
    float ma = ac1.getComando();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": el actuador devuelve "
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
