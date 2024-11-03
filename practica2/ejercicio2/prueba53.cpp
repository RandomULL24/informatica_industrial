// Autor: Alberto Hamilton

#define TITULO "Planta1TanqueNivel y ControladorONOFF"


#include "Planta1TanqueNivel.hpp"
#include "ControladorONOFF.hpp"
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

#define EPS (1e-6)

int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  float maxValvula = 0.5;
  float maxNivel = 12;
  std::cout << "- construimos planta con "  << maxValvula << ", "
      << maxNivel << std::endl;
  Planta1TanqueNivel planta(maxValvula, maxNivel);
  planta.setNombre("Planta");

  std::cout << "- Pedimos altura" << std::endl;

  Valvula* valPt = planta.getValvulaPt();
  SensorNivel* nivPt = planta.getSensorNivelPt();

  std::cout << "- Construimos ControladorONOFF" << std::endl;
  ControladorONOFF control;
  control.setNombre("ContONOFF");
  control.setActuador(valPt);
  control.setSensor(nivPt);

  float consigna = 0.1;
  std::cout << "- Fijamos la consigna a " << consigna << std::endl;
  control.setConsigna(consigna);

  float periodo = 0.5;
  std::cout << "- Fijamos el periodo de muestreo a " << periodo << std::endl;
  planta.setMsPeriodo(periodo * 1000);
  control.setMsPeriodo(periodo * 1000 * 2);


  std::cout << "- Encendemos la planta y controlador" << std::endl;
  planta.enciende();
  control.enciende();
  planta.calculaEtapa();
  control.calculaEtapa();
  planta.enciendePeriodico();
  control.enciendePeriodico();

  auto espera = std::chrono::seconds(15);
  std::this_thread::sleep_for(espera);

  planta.apaga();
  control.apaga();

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
