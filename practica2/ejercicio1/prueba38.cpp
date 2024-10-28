// Autor: Alberto Hamilton

#define TITULO "ControladorONOFF → calculaEtapa, calculaComando"


#include "ControladorONOFF.hpp"
#include "SensorNivel.hpp"
#include "SensorTemperatura.hpp"
#include "Valvula.hpp"
#include "Calefactor.hpp"
#include <iostream>
#include <vector>
#include <iomanip>

#define EPS (1e-6)

int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  std::cout << "- controlador y encendido y con consigna 0.5" << std::endl;
  ControladorONOFF cnt1;
  cnt1.enciende();
  cnt1.setConsigna(0.5);

  std::cout << "- Invocamos calcula comando con 0" << std::endl;
  {
    pruebas++;
    float esperado = 1;
    float ma = cnt1.calculaComando(0.0);
    if(ma != esperado)
      std::cout << "FALLO " << ++fallos << ": el controlador calcula comando "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  std::cout << "- Invocamos calcula comando con 1" << std::endl;
  {
    pruebas++;
    float esperado = 0;
    float ma = cnt1.calculaComando(1.0);
    if(ma != esperado)
      std::cout << "FALLO " << ++fallos << ": el controlador calcula comando "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  std::cout << "- Invocamos calcula comando con 0.49" << std::endl;
  {
    pruebas++;
    float esperado = 1;
    float ma = cnt1.calculaComando(0.49);
    if(ma != esperado)
      std::cout << "FALLO " << ++fallos << ": el controlador calcula comando "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  std::cout << "- Invocamos calcula comando con 0.51" << std::endl;
  {
    pruebas++;
    float esperado = 0;
    float ma = cnt1.calculaComando(0.51);
    if(ma != esperado)
      std::cout << "FALLO " << ++fallos << ": el controlador calcula comando "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  std::cout << "- Conectamos una valvula" << std::endl;
  double valMax = 11.4;
  Valvula val1(valMax);
  cnt1.setActuador(&val1);
  val1.enciende();
  val1.setComando(1.0);

  std::cout << "- Conectamos un sensor nivel y lo encendemos" << std::endl;
  double maxNivel = 10.22;
  SensorNivel sn1(maxNivel);
  cnt1.setSensor(&sn1);
  sn1.enciende();

  std::cout << "- Damos altura maxima al sensor de nivel" << std::endl;
  sn1.setAltura(maxNivel);
  {
    pruebas++;
    cnt1.calculaEtapa();
    double esperado = 0;
    float ma = val1.getCaudal();
    if(std::abs(ma-esperado) > EPS)
      std::cout << "FALLO " << ++fallos << ": el controlador fija valvula a "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  std::cout << "- Damos 0 al sensor de nivel" << std::endl;
  sn1.setAltura(0);
  {
    pruebas++;
    cnt1.calculaEtapa();
    double esperado = valMax;
    float ma = val1.getCaudal();
    if(std::abs(ma-esperado) > EPS)
      std::cout << "FALLO " << ++fallos << ": el controlador fija valvula a "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  std::cout << "- Damos valor por debajo mitad al sensor de nivel" << std::endl;
  sn1.setAltura(maxNivel/2.0 - 0.01);
  {
    pruebas++;
    cnt1.calculaEtapa();
    double esperado = valMax;
    float ma = val1.getCaudal();
    if(std::abs(ma-esperado) > EPS)
      std::cout << "FALLO " << ++fallos << ": el controlador fija valvula a "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  std::cout << "- Damos valor por encima mitad al sensor de nivel" << std::endl;
  sn1.setAltura(maxNivel/2.0 + 0.01);
  {
    pruebas++;
    cnt1.calculaEtapa();
    double esperado = 0;
    float ma = val1.getCaudal();
    if(std::abs(ma-esperado) > EPS)
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
