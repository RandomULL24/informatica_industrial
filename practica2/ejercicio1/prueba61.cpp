// Autor: Alberto Hamilton

#define TITULO "Planta1TanqueNivel → constructor"


#include "Planta1TanqueNivel.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>


int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;


  float maxValvula = 0.5;
  float maxNivel = 10;
  std::cout << "- construimos con "  << maxValvula << ", " << maxNivel << std::endl;
  Planta1TanqueNivel planta(maxValvula, maxNivel);

  Valvula* valPt = planta.getValvulaPt();
  std::cout << "- Comprobamos Valvula" << std::endl;
  {
    pruebas++;
    if(valPt == nullptr)
      std::cout << "FALLO " << ++fallos << ": el puntero a la vávula es nullptr "
          << std::endl;
  }

  SensorNivel* nivPt = planta.getSensorNivelPt();
  std::cout << "- Comprobamos sensor de nivel" << std::endl;
  {
    pruebas++;
    if(nivPt == nullptr)
      std::cout << "FALLO " << ++fallos << ": el puntero al sensor de nivel es nullptr "
          << std::endl;
  }

  std::cout << "- Pedimos cauda valvula" << std::endl;
  {
    pruebas++;
    float ma = valPt->getCaudal();
    if(!std::isnan(ma))
      std::cout << "FALLO " << ++fallos << ": la valvula da cuadal "
          << ma <<" cuando se esperaba NaN" << std::endl;
  }

  std::cout << "- Pedimos medida sensor nivel" << std::endl;
  {
    pruebas++;
    float ma = nivPt->getMedida();
    if(!std::isnan(ma))
      std::cout << "FALLO " << ++fallos << ": sensor nivel da medida "
          << ma <<" cuando se esperaba NaN" << std::endl;
  }

  std::cout << "- Encendemos planta" << std::endl;
  planta.enciende();
  {
    pruebas++;
    if(!planta.isEncendido())
      std::cout << "FALLO " << ++fallos << ": planta no encendida "
          << std::endl;
  }
  {
    pruebas++;
    if(!valPt->isEncendido())
      std::cout << "FALLO " << ++fallos << ": valvula no encendida "
          << std::endl;
  }
  {
    pruebas++;
    if(!nivPt->isEncendido())
      std::cout << "FALLO " << ++fallos << ": sensor nivel no encendido "
          << std::endl;
  }

  std::cout << "- Fijamos comando 1.0 a valvula" << std::endl;
  valPt->setComando(1.0);
  {
    pruebas++;
    float esperado = maxValvula;
    float ma = valPt->getCaudal();
    if(ma != esperado)
      std::cout << "FALLO " << ++fallos << ": la valvula da cuadal "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  std::cout << "- Fijamos altura al maximo en sensor" << std::endl;
  nivPt->setAltura(maxNivel);
  {
    pruebas++;
    float esperado = 1.0;
    float ma = nivPt->getMedida();
    if(ma != esperado)
      std::cout << "FALLO " << ++fallos << ": la sensor nivel da medida "
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
