// Autor: Alberto Hamilton

#define TITULO "ControladorPI → set/getConsigna, set/getKp. set/getKi"


#include "ControladorPI.hpp"
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
  {
    pruebas++;
    float ma = cnt1.getConsigna();
    if (! std::isnan(ma))
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve "
          << ma <<" cuando se esperaba NaN" << std::endl;
  }

  std::cout << "- Fijamos consigna 0.7, pero apagado" << std::endl;
  cnt1.setConsigna(0.7);
  {
    pruebas++;
    float ma = cnt1.getConsigna();
    if (! std::isnan(ma))
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve "
          << ma <<" cuando se esperaba NaN" << std::endl;
  }

  std::cout << "- Encendemos controlador" << std::endl;
  cnt1.enciende();
  {
    pruebas++;
    float esperado = 0.7;
    cnt1.setConsigna(esperado);
    float ma = cnt1.getConsigna();
    if(!(std::abs(ma - esperado) < EPS))  // detecta NaN
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve consigna "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  std::cout << "- Fijamos consigna 0.44" << std::endl;
  cnt1.setConsigna(0.44);
  {
    pruebas++;
    float esperado = 0.44;
    cnt1.setConsigna(esperado);
    float ma = cnt1.getConsigna();
    if(!(std::abs(ma - esperado) < EPS))  // detecta NaN
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve consigna "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  std::cout << "- Fijamos consigna por encima de 1.0 " << std::endl;
  cnt1.setConsigna(1.03);
  {
    pruebas++;
    float esperado = 1.0;
    cnt1.setConsigna(esperado);
    float ma = cnt1.getConsigna();
    if(!(std::abs(ma - esperado) < EPS))  // detecta NaN
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve consigna "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  std::cout << "- Fijamos consigna por debajo de 0.0" << std::endl;
  cnt1.setConsigna(-0.001);
  {
    pruebas++;
    float esperado = 0.0;
    cnt1.setConsigna(esperado);
    float ma = cnt1.getConsigna();
    if(!(std::abs(ma - esperado) < EPS))  // detecta NaN
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve consigna "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  std::cout << "- Pedimos Kp" << std::endl;
  {
    pruebas++;
    float ma = cnt1.getKp();
    if (! std::isnan(ma))
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve "
          << ma <<" cuando se esperaba NaN" << std::endl;
  }

  {
    pruebas++;
    float esperado = 1.5;
    std::cout << "- Fijamos Kp a " << esperado << std::endl;
    cnt1.setKp(esperado);
    float ma = cnt1.getKp();
    if(!(std::abs(ma - esperado) < EPS))  // detecta NaN
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve histeresis "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  {
    pruebas++;
    float esperado = 2.2;
    std::cout << "- Fijamos Kp a " << esperado << std::endl;
    cnt1.setKp(esperado);
    float ma = cnt1.getKp();
    if(!(std::abs(ma - esperado) < EPS))  // detecta NaN
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve histeresis "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  {
    pruebas++;
    float esperado = 0.0;
    std::cout << "- Fijamos Kp a " << esperado << std::endl;
    cnt1.setKp(esperado);
    float ma = cnt1.getKp();
    if(!(std::abs(ma - esperado) < EPS))  // detecta NaN
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve histeresis "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  std::cout << "- Pedimos Ki" << std::endl;
  {
    pruebas++;
    float ma = cnt1.getKi();
    if (! std::isnan(ma))
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve "
          << ma <<" cuando se esperaba NaN" << std::endl;
  }

  {
    pruebas++;
    float esperado = 0.99;
    std::cout << "- Fijamos Ki a " << esperado << std::endl;
    cnt1.setKi(esperado);
    float ma = cnt1.getKi();
    if(!(std::abs(ma - esperado) < EPS))  // detecta NaN
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve histeresis "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  {
    pruebas++;
    float esperado = 1.055;
    std::cout << "- Fijamos Ki a " << esperado << std::endl;
    cnt1.setKi(esperado);
    float ma = cnt1.getKi();
    if(!(std::abs(ma - esperado) < EPS))  // detecta NaN
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve histeresis "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  {
    pruebas++;
    float esperado = 0.0;
    std::cout << "- Fijamos Ki a " << esperado << std::endl;
    cnt1.setKi(esperado);
    float ma = cnt1.getKi();
    if(!(std::abs(ma - esperado) < EPS))  // detecta NaN
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve histeresis "
          << ma <<" cuando se esperaba " << esperado << std::endl;
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
