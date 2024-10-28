// Autor: Alberto Hamilton

#define TITULO "Controlador → calculaEtapa, calculaComando"


#include "Controlador.hpp"
#include "SensorNivel.hpp"
#include "SensorTemperatura.hpp"
#include "Valvula.hpp"
#include "Calefactor.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  std::cout << "- Creado controlador" << std::endl;
  Controlador cnt1;

  std::cout << "- Invocamos calcula comando con 0" << std::endl;
  {
    pruebas++;
    float esperado = 0.0;
    float ma = cnt1.calculaComando(0.0);
    if(ma != esperado)
      std::cout << "FALLO " << ++fallos << ": el controlador calcula comando "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  std::cout << "- Invocamos calcula comando con 1" << std::endl;
  {
    pruebas++;
    float esperado = 0.0;
    float ma = cnt1.calculaComando(1.0);
    if(ma != esperado)
      std::cout << "FALLO " << ++fallos << ": el controlador calcula comando "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  std::cout << "- Invocamos calcula comando con 0.5" << std::endl;
  {
    pruebas++;
    float esperado = 0.0;
    float ma = cnt1.calculaComando(0.5);
    if(ma != esperado)
      std::cout << "FALLO " << ++fallos << ": el controlador calcula comando "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  std::cout << "- Invocamos calcula Etapa sin sensor ni actuador y apagado"
      << std::endl;
  {
    pruebas++;
    cnt1.calculaEtapa();
  }

  std::cout << "- Encendemos e Invocamos calcula Etapa sin sensor ni actuador"
      << std::endl;
  cnt1.enciende();
  {
    pruebas++;
    cnt1.calculaEtapa();
  }

  std::cout << "- Conectamos una valvula" << std::endl;
  double valMax = 11.4;
  Valvula val1(valMax);
  cnt1.setActuador(&val1);
  val1.enciende();
  val1.setComando(1.0);
  {
    pruebas++;
    cnt1.calculaEtapa();
    float esperado = valMax;
    float ma = val1.getCaudal();
    if(ma != esperado)
      std::cout << "FALLO " << ++fallos << ": el controlador fija valvula a "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  std::cout << "- Conectamos un sensor nivel y lo encendemos" << std::endl;
  double maxNivel = 10.22;
  SensorNivel sn1(maxNivel);
  cnt1.setSensor(&sn1);
  sn1.enciende();
  {
    pruebas++;
    cnt1.calculaEtapa();
    float ma = val1.getCaudal();
    if(!std::isnan(ma))
      std::cout << "FALLO " << ++fallos << ": el controlador fija valvula a "
          << ma <<" cuando se esperaba NaN" << std::endl;
  }

  std::cout << "- Damos valor al sensor de nivel" << std::endl;
  sn1.setAltura(maxNivel);
  {
    pruebas++;
    cnt1.calculaEtapa();
    float esperado = 0.0;
    float ma = val1.getCaudal();
    if(ma != esperado)
      std::cout << "FALLO " << ++fallos << ": el controlador fija valvula a "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  std::cout << "- Creado 2º controlador" << std::endl;
  Controlador cnt2;
  std::cout << "- Conectamos un sensor temperatura encendido" << std::endl;
  double temMin = -20.0;
  double temMax = 44.8;
  SensorTemperatura st1(temMin, temMax);
  cnt2.setSensor(&st1);
  st1.enciende();
  {
    pruebas++;
    cnt2.calculaEtapa();
  }

  std::cout << "- Encendemos 2º controlador" << std::endl;
  cnt2.enciende();
  {
    pruebas++;
    cnt2.calculaEtapa();
  }

  std::cout << "- Conectamos calefactor" << std::endl;
  double potMax = 250.0;
  Calefactor cal1(potMax);
  cnt1.setActuador(&cal1);
  cal1.enciende();
  cal1.setComando(1.0);
  {
    pruebas++;
    cnt1.calculaEtapa();
    float esperado = 0.0;
    float ma = cal1.getPotencia();
    if(ma != esperado)
      std::cout << "FALLO " << ++fallos << ": el controlador fija valvula a "
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
