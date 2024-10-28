// Autor: Alberto Hamilton

#define TITULO "Dispositivo → getId"


#include "Dispositivo.hpp"
#include <iostream>
#include <vector>
#include <iomanip>


int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  pruebas++;
  Dispositivo* d1 = new Dispositivo;
  std::cout << "- Creado un dispositivo"  << std::endl;
  {
    unsigned idEsp = 1;
    unsigned id = d1->getId();
    if (id != idEsp)
      std::cout << "FALLO " << ++fallos << ": Id del dispositivo es "
          << id <<" cuando se esperaba " << idEsp << std::endl;
  }

  pruebas++;
  Dispositivo* d2 = new Dispositivo;
  std::cout << "- Creado un dispositivo"  << std::endl;
  {
    unsigned idEsp = 2;
    unsigned id = d2->getId();
    if (id != idEsp)
      std::cout << "FALLO " << ++fallos << ": Id del dispositivo es "
          << id <<" cuando se esperaba " << idEsp << std::endl;
  }

  pruebas++;
  Dispositivo* d3 = new Dispositivo;
  std::cout << "- Creado un dispositivo"  << std::endl;
  {
    unsigned idEsp = 3;
    unsigned id = d3->getId();
    if (id != idEsp)
      std::cout << "FALLO " << ++fallos << ": Id del dispositivo es "
          << id <<" cuando se esperaba " << idEsp << std::endl;
  }

  pruebas++;
  delete d3;
  std::cout << "- Borrado un dispositivo"  << std::endl;
  std::cout << "- Creado un dispositivo"  << std::endl;
  Dispositivo* d4 = new Dispositivo;
  {
    unsigned idEsp = 4;
    unsigned id = d4->getId();
    if (id != idEsp)
      std::cout << "FALLO " << ++fallos << ": Id del dispositivo es "
          << id <<" cuando se esperaba " << idEsp << std::endl;
  }

  pruebas++;
  {
    unsigned idEsp = 2;
    unsigned id = d2->getId();
    if (id != idEsp)
      std::cout << "FALLO " << ++fallos << ": Id del dispositivo es "
          << id <<" cuando se esperaba " << idEsp << std::endl;
  }

  pruebas++;
  {
    unsigned idEsp = 1;
    unsigned id = d1->getId();
    if (id != idEsp)
      std::cout << "FALLO " << ++fallos << ": Id del dispositivo es "
          << id <<" cuando se esperaba " << idEsp << std::endl;
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
