// Autor: Alberto Hamilton

#define TITULO "ControladorONOFF → id, nombre, encendido"


#include "ControladorONOFF.hpp"
#include <iostream>
#include <vector>
#include <iomanip>


int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  std::string nomDefecto = "-";

  std::cout << "- Creamos un dispositivo"  << std::endl;
  ControladorONOFF* d1 = new ControladorONOFF();
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
    std::string nom = nomDefecto;
    std::string nomG = d1->getNombre();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " nombre del dispositivo "
          << d1->getId() << " es "
          << nomG <<" cuando se esperaba " << nom << std::endl;
  }
  std::string nom1 = "Primero";
  std::cout << "- ponemos nombre " << std::endl;
  d1->setNombre(nom1);
  {
    pruebas++;
    std::string nom = nom1;
    std::string nomG = d1->getNombre();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " nombre del dispositivo "
          << d1->getId() << " es "
          << nomG <<" cuando se esperaba " << nom << std::endl;
  }
  {
    pruebas++;
    bool encen = false;
    bool isEncen = d1->isEncendido();
    if (encen != isEncen)
      std::cout << "FALLO " << ++fallos << ": el dispositivo "
          << d1->getId() << " encendido "
          << isEncen <<" cuando se esperaba " << encen << std::endl;
  }


  std::cout << "- Creamos un dispositivo"  << std::endl;
  ControladorONOFF* d2 = new ControladorONOFF();
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
    std::string nom = nomDefecto;
    std::string nomG = d2->getNombre();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " nombre del dispositivo "
          << d2->getId() << " es "
          << nomG <<" cuando se esperaba " << nom << std::endl;
  }

  std::string nom2 = "Segundo";
  std::cout << "- ponemos nombre " << std::endl;
  d2->setNombre(nom2);
  {
    pruebas++;
    std::string nom = nom2;
    std::string nomG = d2->getNombre();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " nombre del dispositivo "
          << d2->getId() << " es "
          << nomG <<" cuando se esperaba " << nom << std::endl;
  }
  {
    pruebas++;
    bool encen = false;
    bool isEncen = d2->isEncendido();
    if (encen != isEncen)
      std::cout << "FALLO " << ++fallos << ": el dispositivo "
          << d2->getId() << " encendido "
          << isEncen <<" cuando se esperaba " << encen << std::endl;
  }


  std::cout << "- Creamos un dispositivo"  << std::endl;
  ControladorONOFF* d3 = new ControladorONOFF();
  {
    pruebas++;
    unsigned idEsp = 3;
    unsigned id = d3->getId();
    if (id != idEsp)
      std::cout << "FALLO " << ++fallos << ": Id del dispositivo es "
          << id <<" cuando se esperaba " << idEsp << std::endl;
  }
  {
    pruebas++;
    std::string nom = nomDefecto;
    std::string nomG = d3->getNombre();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " nombre del dispositivo "
          << d3->getId() << " es "
          << nomG <<" cuando se esperaba " << nom << std::endl;
  }
  std::string nom3 = "Tercero";
  std::cout << "- ponemos nombre " << std::endl;
  d3->setNombre(nom3);
  {
    pruebas++;
    std::string nom = nom3;
    std::string nomG = d3->getNombre();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " nombre del dispositivo "
          << d3->getId() << " es "
          << nomG <<" cuando se esperaba " << nom << std::endl;
  }

  {
    pruebas++;
    std::string nom = nom1;
    std::string nomG = d1->getNombre();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " nombre del dispositivo "
          << d1->getId() << " es "
          << nomG <<" cuando se esperaba " << nom << std::endl;
  }
  {
    pruebas++;
    std::string nom = nom2;
    std::string nomG = d2->getNombre();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " nombre del dispositivo "
          << d2->getId() << " es "
          << nomG <<" cuando se esperaba " << nom << std::endl;
  }

  std::cout << "- Encendemos primer dispositivo" << std::endl;
  d1->enciende();
  {
    pruebas++;
    bool encen = true;
    bool isEncen = d1->isEncendido();
    if (encen != isEncen)
      std::cout << "FALLO " << ++fallos << ": el dispositivo "
          << d1->getId() << " encendido "
          << isEncen <<" cuando se esperaba " << encen << std::endl;
  }

  std::cout << "- Encendemos segundo dispositivo" << std::endl;
  d2->enciende();
  {
    pruebas++;
    bool encen = true;
    bool isEncen = d2->isEncendido();
    if (encen != isEncen)
      std::cout << "FALLO " << ++fallos << ": el dispositivo "
          << d2->getId() << " encendido "
          << isEncen <<" cuando se esperaba " << encen << std::endl;
  }

  std::cout << "- Borramos un dispositivo"  << std::endl;
  delete d3;
  std::cout << "- Creamos un dispositivo"  << std::endl;
  ControladorONOFF* d4 = new ControladorONOFF();
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
      std::cout << "FALLO " << ++fallos << ": el dispositivo "
          << d1->getId() << " encendido "
          << isEncen <<" cuando se esperaba " << encen << std::endl;
  }

  std::cout << "- Apagamos el segundo dispositivo" << std::endl;
  d2->apaga();
  {
    pruebas++;
    bool encen = false;
    bool isEncen = d2->isEncendido();
    if (encen != isEncen)
      std::cout << "FALLO " << ++fallos << ": el dispositivo "
          << d2->getId() << " encendido "
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
