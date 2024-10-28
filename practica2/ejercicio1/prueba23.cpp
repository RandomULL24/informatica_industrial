// Autor: Alberto Hamilton

#define TITULO "Valvula → getCaudal"


#include "Valvula.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>


int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  float maxCaudal = 4.90;
  std::cout << "- Creada Valvula con caudal máximo " << maxCaudal << std::endl;
  Valvula val1(maxCaudal);
  {
    pruebas++;
    std::cout << "- Pedimos comando pero apagada" << std::endl;
    float ma = val1.getCaudal();
    if (! std::isnan(ma))
      std::cout << "FALLO " << ++fallos << ": la válvula devuelve "
          << ma <<" cuando se esperaba NaN" << std::endl;
  }

  std::cout << "- Fijamos comando a 0.0, pero apagada" << std::endl;
  val1.setComando(0.0);
  {
    pruebas++;
    float ma = val1.getCaudal();
    if (! std::isnan(ma))
      std::cout << "FALLO " << ++fallos << ": la válvula devuelve "
          << ma <<" cuando se esperaba NaN porque está apagado" << std::endl;
  }

  std::cout << "- Encendemos Válvula" << std::endl;
  val1.enciende();
  {
    pruebas++;
    float espera = 0.0;
    float ma = val1.getCaudal();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": la válvula devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
  }

  std::cout << "- Fijamos comando a 1.0" << std::endl;
  val1.setComando(1.0);
  {
    pruebas++;
    float espera = maxCaudal;
    float ma = val1.getCaudal();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": la válvula devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
  }

  std::cout << "- Fijamos comando a 0.5" << std::endl;
  val1.setComando(0.5);
  {
    pruebas++;
    float espera = maxCaudal / 2.0;
    float ma = val1.getCaudal();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": la válvula devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
  }

  std::cout << "- Fijamos comando a 0.25" << std::endl;
  val1.setComando(0.25);
  {
    pruebas++;
    float espera = maxCaudal / 4.0;
    float ma = val1.getCaudal();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": la válvula devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
  }

  std::cout << "- Fijamos comando negativo" << std::endl;
  val1.setComando(-0.01);
  {
    pruebas++;
    float espera = 0.0;
    float ma = val1.getCaudal();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": la válvula devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
  }

  std::cout << "- Fijamos comando mayor de 1.0" << std::endl;
  val1.setComando(1.001);
  {
    pruebas++;
    float espera = maxCaudal;
    float ma = val1.getCaudal();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": la válvula devuelve "
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
