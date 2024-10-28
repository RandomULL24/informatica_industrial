// Autor: Alberto Hamilton

#define TITULO "Dispositivo → enciende, apaga, isEncendido"


#include "Dispositivo.hpp"
#include <iostream>
#include <vector>
#include <iomanip>


int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  pruebas++;
  Dispositivo d1;
  std::cout << "- Creado un dispositivo" << std::endl;
  {
    bool encen = false;
    Dispositivo& da = d1;
    bool isEncen = da.isEncendido();
    if (encen != isEncen)
      std::cout << "FALLO " << ++fallos << ": el dispositivo " << da.getId()
          << " encendido "
          << isEncen <<" cuando se esperaba " << encen << std::endl;
  }

  pruebas++;
  Dispositivo d2;
  std::cout << "- Creado un dispositivo" << std::endl;
  {
    bool encen = false;
    Dispositivo& da = d2;
    bool isEncen = da.isEncendido();
    if (encen != isEncen)
      std::cout << "FALLO " << ++fallos << ": el dispositivo " << da.getId()
          << " encendido "
          << isEncen <<" cuando se esperaba " << encen << std::endl;
  }

  pruebas++;
  d1.enciende();
  std::cout << "- Encendido primer dispositivo" << std::endl;
  {
    bool encen = true;
    Dispositivo& da = d1;
    bool isEncen = da.isEncendido();
    if (encen != isEncen)
      std::cout << "FALLO " << ++fallos << ": el dispositivo " << da.getId()
          << " encendido "
          << isEncen <<" cuando se esperaba " << encen << std::endl;
  }

  pruebas++;
  d2.enciende();
  std::cout << "- Encendido segundo dispositivo" << std::endl;
  {
    bool encen = true;
    Dispositivo& da = d2;
    bool isEncen = da.isEncendido();
    if (encen != isEncen)
      std::cout << "FALLO " << ++fallos << ": el dispositivo " << da.getId()
          << " encendido "
          << isEncen <<" cuando se esperaba " << encen << std::endl;
  }

  pruebas++;
  d1.enciende();
  std::cout << "- Encendido primer dispositivo" << std::endl;
  {
    bool encen = true;
    Dispositivo& da = d1;
    bool isEncen = da.isEncendido();
    if (encen != isEncen)
      std::cout << "FALLO " << ++fallos << ": el dispositivo " << da.getId()
          << " encendido "
          << isEncen <<" cuando se esperaba " << encen << std::endl;
  }

  pruebas++;
  d1.apaga();
  std::cout << "- Apagado primer dispositivo" << std::endl;
  {
    bool encen = false;
    Dispositivo& da = d1;
    bool isEncen = da.isEncendido();
    if (encen != isEncen)
      std::cout << "FALLO " << ++fallos << ": el dispositivo " << da.getId()
          << " encendido "
          << isEncen <<" cuando se esperaba " << encen << std::endl;
  }

  pruebas++;
  d2.apaga();
  std::cout << "- Apagado el segundo dispositivo" << std::endl;
  {
    bool encen = false;
    Dispositivo& da = d2;
    bool isEncen = da.isEncendido();
    if (encen != isEncen)
      std::cout << "FALLO " << ++fallos << ": el dispositivo " << da.getId()
          << " encendido "
          << isEncen <<" cuando se esperaba " << encen << std::endl;
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
