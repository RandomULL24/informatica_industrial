// Autor: Alberto Hamilton

#define TITULO "ControladorPI → calculaEtapa, calculaComando situaciones especiales"


#include "ControladorPI.hpp"
#include "SensorTemperatura.hpp"
#include "Calefactor.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

#define EPS (1e-5)

int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  std::cout << "- Creado controlador" << std::endl;
  ControladorPI cnt1;

  std::cout << "- Invocamos calcula comando con 4.0 pero sin consigna" << std::endl;
  {
    pruebas++;
    float ma = cnt1.calculaComando(4.0);
    if(!std::isnan(ma))
      std::cout << "FALLO " << ++fallos << ": el controlador calcula comando "
          << ma <<" cuando se esperaba NaN" << std::endl;
  }

  std::cout << "- Invocamos calcula comando con 20.0 pero sin consigna" << std::endl;
  {
    pruebas++;
    float ma = cnt1.calculaComando(20.0);
    if(!std::isnan(ma))
      std::cout << "FALLO " << ++fallos << ": el controlador calcula comando "
          << ma <<" cuando se esperaba NaN" << std::endl;
  }

  std::cout << "- Invocamos calcula comando con 12.0 pero sin consigna" << std::endl;
  {
    pruebas++;
    float ma = cnt1.calculaComando(12.0);
    if(!std::isnan(ma))
      std::cout << "FALLO " << ++fallos << ": el controlador calcula comando "
          << ma <<" cuando se esperaba NaN" << std::endl;
  }

  std::cout << "- Invocamos calcula Etapa sin sensor ni actuador y apagado" << std::endl;
  {
    pruebas++;
    cnt1.calculaEtapa();
  }

  std::cout << "- Encendemos e Invocamos calcula Etapa sin sensor ni actuador" << std::endl;
  cnt1.enciende();
  {
    pruebas++;
    cnt1.calculaEtapa();
  }

  std::cout << "- Conectamos un calefactor" << std::endl;
  double calMax = 11.4;
  Calefactor cal1(calMax);
  cnt1.setActuador(&cal1);
  cal1.enciende();
  cal1.setComando(20.0);
  {
    pruebas++;
    cnt1.calculaEtapa();
    float esperado = calMax;
    float ma = cal1.getPotencia();
    if(!(std::abs(ma - esperado) < EPS))  // detecta NaN
      std::cout << "FALLO " << ++fallos << ": el controlador fija valvula a "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  std::cout << "- Conectamos un sensor temperatura y lo encendemos" << std::endl;
  double maxTemp = 10.22;
  double minTemp = -22.1;
  SensorTemperatura st1(minTemp, maxTemp);
  cnt1.setSensor(&st1);
  st1.enciende();
  {
    pruebas++;
    cnt1.calculaEtapa();
    float ma = cal1.getPotencia();
    if(!std::isnan(ma))
      std::cout << "FALLO " << ++fallos << ": el controlador fija valvula a "
          << ma <<" cuando se esperaba NaN" << std::endl;
  }

  std::cout << "- Damos valor al sensor de temperatura" << std::endl;
  st1.setTemperatura(maxTemp);
  {
    pruebas++;
    cnt1.calculaEtapa();
    float ma = cal1.getPotencia();
    if(!std::isnan(ma))
      std::cout << "FALLO " << ++fallos << ": el controlador fija valvula a "
          << ma <<" cuando se esperaba NaN" << std::endl;
  }

  std::cout << "- Creado 2º controlador" << std::endl;
  ControladorPI cnt2;
  std::cout << "- Conectamos un sensor temperatura encendido" << std::endl;
  double temMin = -20.0;
  double temMax = 44.8;
  SensorTemperatura st2(temMin, temMax);
  cnt2.setSensor(&st2);
  st2.enciende();
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
  Calefactor cal2(potMax);
  cnt1.setActuador(&cal2);
  cal2.enciende();
  cal2.setComando(20.0);
  {
    pruebas++;
    cnt1.calculaEtapa();
    float ma = cal2.getPotencia();
    if(!std::isnan(ma))
      std::cout << "FALLO " << ++fallos << ": el controlador fija valvula a "
          << ma <<" cuando se esperaba NaN" << std::endl;
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
