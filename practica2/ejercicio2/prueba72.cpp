// Autor: Alberto Hamilton

#define TITULO "ControladorPI → id, encendido"


#include "ControladorPI.hpp"
#include <iostream>
#include <vector>
#include <iomanip>


int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  std::string nomDefecto = "-";

  std::cout << "- Creamos un dispositivo"  << std::endl;
  ControladorPI* d1 = new ControladorPI();
  {
    pruebas++;
    unsigned idEsp = 1;
    unsigned id = d1->getId();
    if (id != idEsp)
      std::cout << "FALLO " << ++fallos << ": Id del dispositivo es "
          << id <<" cuando se esperaba " << idEsp << std::endl;
  }
  {
    pruebas++;
    bool encen = false;
    bool isEncen = d1->isEncendido();
    if (encen != isEncen)
      std::cout << "FALLO " << ++fallos << ": el dispositivo " << d1->getId() << " encendido "
          << isEncen <<" cuando se esperaba " << encen << std::endl;
  }


  std::cout << "- Creamos un dispositivo"  << std::endl;
  ControladorPI* d2 = new ControladorPI();
  {
    pruebas++;
    unsigned idEsp = 2;
    unsigned id = d2->getId();
    if (id != idEsp)
      std::cout << "FALLO " << ++fallos << ": Id del dispositivo es "
          << id <<" cuando se esperaba " << idEsp << std::endl;
  }

  {
    pruebas++;
    bool encen = false;
    bool isEncen = d2->isEncendido();
    if (encen != isEncen)
      std::cout << "FALLO " << ++fallos << ": el dispositivo " << d2->getId() << " encendido "
          << isEncen <<" cuando se esperaba " << encen << std::endl;
  }


  std::cout << "- Creamos un dispositivo"  << std::endl;
  ControladorPI* d3 = new ControladorPI();
  {
    pruebas++;
    unsigned idEsp = 3;
    unsigned id = d3->getId();
    if (id != idEsp)
      std::cout << "FALLO " << ++fallos << ": Id del dispositivo es "
          << id <<" cuando se esperaba " << idEsp << std::endl;
  }

  std::cout << "- Encendemos primer dispositivo" << std::endl;
  d1->enciende();
  {
    pruebas++;
    bool encen = true;
    bool isEncen = d1->isEncendido();
    if (encen != isEncen)
      std::cout << "FALLO " << ++fallos << ": el dispositivo " << d1->getId() << " encendido "
          << isEncen <<" cuando se esperaba " << encen << std::endl;
  }

  std::cout << "- Encendemos segundo dispositivo" << std::endl;
  d2->enciende();
  {
    pruebas++;
    bool encen = true;
    bool isEncen = d2->isEncendido();
    if (encen != isEncen)
      std::cout << "FALLO " << ++fallos << ": el dispositivo " << d2->getId() << " encendido "
          << isEncen <<" cuando se esperaba " << encen << std::endl;
  }

  std::cout << "- Borramos un dispositivo"  << std::endl;
  delete d3;
  std::cout << "- Creamos un dispositivo"  << std::endl;
  ControladorPI* d4 = new ControladorPI();
  {
    pruebas++;
    unsigned idEsp = 4;
    unsigned id = d4->getId();
    if (id != idEsp)
      std::cout << "FALLO " << ++fallos << ": Id del dispositivo es "
          << id <<" cuando se esperaba " << idEsp << std::endl;
  }

  {
    pruebas++;
    unsigned idEsp = 2;
    unsigned id = d2->getId();
    if (id != idEsp)
      std::cout << "FALLO " << ++fallos << ": Id del dispositivo es "
          << id <<" cuando se esperaba " << idEsp << std::endl;
  }

  {
    pruebas++;
    unsigned idEsp = 1;
    unsigned id = d1->getId();
    if (id != idEsp)
      std::cout << "FALLO " << ++fallos << ": Id del dispositivo es "
          << id <<" cuando se esperaba " << idEsp << std::endl;
  }

  std::cout << "- Apagamos primer dispositivo" << std::endl;
  d1->apaga();
  {
    pruebas++;
    bool encen = false;
    bool isEncen = d1->isEncendido();
    if (encen != isEncen)
      std::cout << "FALLO " << ++fallos << ": el dispositivo " << d1->getId() << " encendido "
          << isEncen <<" cuando se esperaba " << encen << std::endl;
  }

  std::cout << "- Apagamos el segundo dispositivo" << std::endl;
  d2->apaga();
  {
    pruebas++;
    bool encen = false;
    bool isEncen = d2->isEncendido();
    if (encen != isEncen)
      std::cout << "FALLO " << ++fallos << ": el dispositivo " << d2->getId() << " encendido "
          << isEncen <<" cuando se esperaba " << encen << std::endl;
  }


  // Resumen final
  if (fallos == 0)
    std::cout << "\n :-) Todas las " << pruebas << " pruebas correctas (100% exito)\n"
        << std::endl;
  else
    std::cout << "\n :-( Se han producido " << fallos << " FALLOs de "
        << pruebas << " pruebas (" << std::fixed <<  std::setprecision(0)
        << (100 - fallos*100.0/pruebas) << "% éxito)"
        << std::endl;
  return fallos;
}
