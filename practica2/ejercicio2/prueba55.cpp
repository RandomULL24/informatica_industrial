// Autor: Alberto Hamilton

#define TITULO "Planta1TanqueNivel → setters y getters de A y Z"


#include "Planta1TanqueNivel.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#define EPS (1e-6)


int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  float maxValvula = 0.5;
  float maxNivel = 10;
  std::cout << "- construimos con "  << maxValvula << ", " << maxNivel << std::endl;
  Planta1TanqueNivel planta1(maxValvula, maxNivel);
  planta1.setNombre("PlantaUno");

  {
    float valA = 3.25;
    std::cout << "- Ponemos A a valor "  << valA << std::endl;
    planta1.setA(valA);

    {
      pruebas++;
      float esperado = valA;
      float ma = planta1.getA();
      if(ma != esperado)
        std::cout << "FALLO " << ++fallos << ": valor para A "
            << "del dispositivo " << planta1.getId() << " "
            << ma <<" cuando se esperaba " << esperado << std::endl;
    }

    float valZ = 0.999;
    std::cout << "- Ponemos Z a valor "  << valZ << std::endl;
    planta1.setZ(valZ);
    {
      pruebas++;
      float esperado = valZ;
      float ma = planta1.getZ();
      if(ma != esperado)
        std::cout << "FALLO " << ++fallos << ": valor para Z "
            << "del dispositivo " << planta1.getId() << " "
            << ma <<" cuando se esperaba " << esperado << std::endl;
    }
  }

  std::cout << "- construimos otra planta " << std::endl;
  Planta1TanqueNivel planta2(maxValvula, maxNivel);
  planta2.setNombre("PlantaDos");
  {
    float valA = 11.025;
    std::cout << "- Ponemos A a valor "  << valA << std::endl;
    planta2.setA(valA);

    {
      pruebas++;
      float esperado = valA;
      float ma = planta2.getA();
      if(ma != esperado)
        std::cout << "FALLO " << ++fallos << ": valor para A "
            << "del dispositivo " << planta2.getId() << " "
            << ma <<" cuando se esperaba " << esperado << std::endl;
    }

    float valZ = 3.75;
    std::cout << "- Ponemos Z a valor "  << valZ << std::endl;
    planta2.setZ(valZ);
    {
      pruebas++;
      float esperado = valZ;
      float ma = planta2.getZ();
      if(ma != esperado)
        std::cout << "FALLO " << ++fallos << ": valor para Z "
            << "del dispositivo " << planta2.getId() << " "
            << ma <<" cuando se esperaba " << esperado << std::endl;
    }
  }

  {
    float valA = 3.25;
    float valZ = 0.999;
    {
      pruebas++;
      float esperado = valA;
      float ma = planta1.getA();
      if(ma != esperado)
        std::cout << "FALLO " << ++fallos << ": valor para A "
            << "del dispositivo " << planta1.getId() << " "
            << ma <<" cuando se esperaba " << esperado << std::endl;
    }
    {
      pruebas++;
      float esperado = valZ;
      float ma = planta1.getZ();
      if(ma != esperado)
        std::cout << "FALLO " << ++fallos << ": valor para Z "
            << "del dispositivo " << planta1.getId() << " "
            << ma <<" cuando se esperaba " << esperado << std::endl;
    }
  }

  unsigned msPeriodo = 2500;
  std::cout << "- Ponemos periodo "  << msPeriodo << std::endl;
  planta1.setMsPeriodo(msPeriodo);
  {
    pruebas++;
    float esperado = msPeriodo;
    float ma = planta1.getMsPeriodo();
    if(ma != esperado)
      std::cout << "FALLO " << ++fallos << ": valor para periodo "
          << "del dispositivo " << planta1.getId() << " "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  unsigned msPeriodo2 = 4210;
  std::cout << "- Ponemos periodo "  << msPeriodo2 << std::endl;
  planta2.setMsPeriodo(msPeriodo2);
  {
    pruebas++;
    float esperado = msPeriodo2;
    float ma = planta2.getMsPeriodo();
    if(ma != esperado)
      std::cout << "FALLO " << ++fallos << ": valor para periodo "
          << "del dispositivo " << planta2.getId() << " "
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
