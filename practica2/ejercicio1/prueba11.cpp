// Autor: Alberto Hamilton

#define TITULO "SensorNivel → setAltura, getMedida"


#include "SensorNivel.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  float alturaMaxima = 1.5;
  std::cout << "- Creamos SensorNivel con altura máxima " << alturaMaxima
      << std::endl;
  SensorNivel sn1(alturaMaxima);
  {
    std::cout << "- Pedimos medida despues de construir" << std::endl;
    pruebas++;
    float ma = sn1.getMedida();
    if (! std::isnan(ma))
      std::cout << "FALLO " << ++fallos << ": el sensor de nivel devuelve "
          << ma <<" cuando se esperaba NaN" << std::endl;
  }

  sn1.setAltura(0.0);
  {
    std::cout << "- Fijamos altura a 0.0, pero no encendido" << std::endl;
    pruebas++;
    float ma = sn1.getMedida();
    if (! std::isnan(ma))
      std::cout << "FALLO " << ++fallos << ": el sensor de nivel devuelve "
          << ma <<" cuando se esperaba NaN porque está apagado" << std::endl;
  }

  sn1.enciende();
  {
    std::cout << "- Encendemos dispositivo" << std::endl;
    pruebas++;
    float espera = 0.0;
    float ma = sn1.getMedida();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": el sensor de nivel devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
  }

  sn1.setAltura(alturaMaxima);
  std::cout << "- Fijamos altura maxima" << std::endl;
  {
    pruebas++;
    float espera = 1.0;
    float ma = sn1.getMedida();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": el sensor de nivel devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
  }

  sn1.setAltura(alturaMaxima / 2.0);
  std::cout << "- Fijamos altura media" << std::endl;
  {
    pruebas++;
    float espera = 0.5;
    float ma = sn1.getMedida();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": el sensor de nivel devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
  }

  sn1.setAltura(alturaMaxima / 4.0);
  std::cout << "- Fijamos altura 1/4" << std::endl;
  {
    pruebas++;
    float espera = 0.25;
    float ma = sn1.getMedida();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": el sensor de nivel devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
  }

  sn1.setAltura(-2.0);
  std::cout << "- Fijamos altura negativa" << std::endl;
  {
    pruebas++;
    float espera = 0.0;
    float ma = sn1.getMedida();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": el sensor de nivel devuelve "
          << ma <<" cuando se esperaba " << espera << std::endl;
  }

  sn1.setAltura(alturaMaxima + 0.1);
  std::cout << "- Fijamos altura superior a la máxima" << std::endl;
  {
    pruebas++;
    float espera = 1.0;
    float ma = sn1.getMedida();
    if (ma != espera)
      std::cout << "FALLO " << ++fallos << ": el sensor de nivel devuelve "
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
