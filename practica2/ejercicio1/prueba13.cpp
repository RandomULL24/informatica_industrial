// Autor: Alberto Hamilton

#define TITULO "SensorTemperatura → setTemperatura, getMedida"


#include "SensorTemperatura.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>


int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  float tempMin = 12.6;
  float tempMax = 20.9;
  float rango = tempMax - tempMin;
  SensorTemperatura st1(tempMin, tempMax);
  std::cout << "- Creamos SensorTemperatura con mínima " << tempMin <<
      " y máxima " << tempMax << std::endl;
  {
    std::cout << "- Pedimos medida despues de construir" << std::endl;
    pruebas++;
    float ma = st1.getMedida();
    if (! std::isnan(ma))
      std::cout << "FALLO " << ++fallos << ": el sensor de temperatura devuelve "
          << ma <<" cuando se esperaba NaN" << std::endl;
  }

  st1.setTemperatura(tempMin);
  {
    std::cout << "- Fijamos temperatura mínima, pero no encendido" << std::endl;
    pruebas++;
    float ma = st1.getMedida();
    if (! std::isnan(ma))
      std::cout << "FALLO " << ++fallos << ": el sensor de temperatura devuelve "
          << ma <<" cuando se esperaba NaN porque está apagado" << std::endl;
  }

  st1.enciende();
  std::cout << "- Encendemos dispositivo" << std::endl;
  {
    pruebas++;
    float espera = 0.0;
    float ma = st1.getMedida();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": el sensor de temperatura devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
  }

  st1.setTemperatura(tempMax);
  std::cout << "- Fijamos temperatura maxima" << std::endl;
  {
    pruebas++;
    float espera = 1.0;
    float ma = st1.getMedida();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": el sensor de temperatura devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
  }

  st1.setTemperatura(rango / 2.0 + tempMin);
  std::cout << "- Fijamos temperatura media" << std::endl;
  {
    pruebas++;
    float espera = 0.5;
    float ma = st1.getMedida();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": el sensor de temperatura devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
  }

  st1.setTemperatura(rango / 4.0 + tempMin);
  std::cout << "- Fijamos temperatura 1/4" << std::endl;
  {
    pruebas++;
    float espera = 0.25;
    float ma = st1.getMedida();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": el sensor de temperatura devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
  }

  st1.setTemperatura(tempMin - 0.1);
  std::cout << "- Fijamos temperatura por debajo de la mínima" << std::endl;
  {
    pruebas++;
    float espera = 0.0;
    float ma = st1.getMedida();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": el sensor de temperatura devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
  }

  st1.setTemperatura(tempMax + 0.1);
  std::cout << "- Fijamos temperatura por encima de la maxima" << std::endl;
  {
    pruebas++;
    float espera = 1.0;
    float ma = st1.getMedida();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": el sensor de temperatura devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
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
