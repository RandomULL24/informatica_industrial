// Autor: Alberto Hamilton

#define TITULO "Planta1TanqueNivel → id, y nommbre"


#include "Planta1TanqueNivel.hpp"
#include <iostream>
#include <iomanip>


int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;


  float maxValvula = 0.5;
  float maxNivel = 10;
  std::cout << "- construimos con "  << maxValvula << ", " << maxNivel << std::endl;
  Planta1TanqueNivel planta(maxValvula, maxNivel);

  std::string nomPlanta = "PlantaNivel1";
  std::cout << "- Damos nombre "  << nomPlanta << std::endl;
  planta.setNombre(nomPlanta);
  {
    pruebas++;
    std::string esperado = nomPlanta;
    std::string ma = planta.getNombre();
    if(ma != esperado)
      std::cout << "FALLO " << ++fallos << ": el nombre que devuelve la plantae es '"
          << ma << "' cuando se esperaba '" << esperado << "'" << std::endl;
  }



  Valvula* valPt = planta.getValvulaPt();
  std::cout << "- Comprobamos nombre de la Valvula" << std::endl;
  {
    pruebas++;
    std::string esperado = nomPlanta + " Valvula";
    std::string ma = valPt->getNombre();
    if(ma != esperado)
      std::cout << "FALLO " << ++fallos << ": el nombre que devuelve la valvula '"
          << ma << "' cuando se esperaba '" << esperado << "'" << std::endl;
  }

  SensorNivel* nivPt = planta.getSensorNivelPt();
  std::cout << "- Comprobamos nombre del sensor nivel" << std::endl;
  {
    pruebas++;
    std::string esperado = nomPlanta + " SenNivel";
    std::string ma = nivPt->getNombre();
    if(ma != esperado)
      std::cout << "FALLO " << ++fallos << ": el nombre que devuelve sensor nivel es '"
          << ma << "' cuando se esperaba '" << esperado << "'" << std::endl;
  }

  std::cout << "- Comprobamos Id de la planta " << std::endl;
  {
    pruebas++;
    unsigned esperado = 1;
    unsigned ma = planta.getId();
    if(ma != esperado)
      std::cout << "FALLO " << ++fallos << ": el id de la planta es "
          << ma << " cuando se esperaba '" << esperado << "'" << std::endl;
  }

  std::cout << "- Comprobamos Id de la valvula " << std::endl;
  {
    pruebas++;
    unsigned ma = valPt->getId();
    if((ma != 2) && (ma != 3))
      std::cout << "FALLO " << ++fallos << ": el id de la valvula es "
          << ma << " cuando se esperaba 2 o 3" << std::endl;
  }

  std::cout << "- Comprobamos Id del sensor nivel " << std::endl;
  {
    pruebas++;
    unsigned esperado = (valPt->getId() == 2) ? 3 : 2;
    unsigned ma = nivPt->getId();
    if(ma != esperado)
      std::cout << "FALLO " << ++fallos << ": el id del sensor nivel es "
          << ma << " cuando se esperaba " << esperado  << std::endl;
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
