// Autor: Alberto Hamilton

#define TITULO "ControladorPI → set/getSensor, set/getActuador"


#include "ControladorPI.hpp"
#include "SensorTemperatura.hpp"
#include "Calefactor.hpp"
#include <iostream>
#include <iomanip>


int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  std::cout << "- Creado controlador" << std::endl;
  ControladorPI cnt1;

  std::cout << "- Pedimos sensor" << std::endl;
  {
    pruebas++;
    Sensor* sa = cnt1.getSensor();
    if (sa != nullptr)
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve "
          << " un sensor distinto de nullptr" << std::endl;
  }

  std::cout << "- Conectamos sensor de Temperatura" << std::endl;
  SensorTemperatura st1(2.5, 5.5);
  cnt1.setSensor(&st1);
  {
    pruebas++;
    Sensor* sa = cnt1.getSensor();
    if (sa != &st1)
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve "
          << " un sensor que no se esperaba" << std::endl;
  }

  std::cout << "- Conectamos sensor de temperatura" << std::endl;
  SensorTemperatura st2(10.0, 50.0);
  cnt1.setSensor(&st2);
  {
    pruebas++;
    Sensor* sa = cnt1.getSensor();
    if (sa != &st2)
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve "
          << " un sensor que no se esperaba" << std::endl;
  }

  std::cout << "- Creado 2º controlador" << std::endl;
  ControladorPI cnt2;

  std::cout << "- Pedimos Actuador" << std::endl;
  {
    pruebas++;
    Actuador* sa = cnt2.getActuador();
    if (sa != nullptr)
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve "
          << " un actuador cuando se esperaba nullptr" << std::endl;
  }

  std::cout << "- Conectamos un calefactor" << std::endl;
  Calefactor cal1(12.8);
  cnt2.setActuador(&cal1);
  {
    pruebas++;
    Actuador* sa = cnt2.getActuador();
    if (sa != &cal1)
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve "
          << " un actuador que no se esperaba" << std::endl;
  }

  std::cout << "- Conectamos calefactor" << std::endl;
  Calefactor cal2(1500.0);
  cnt2.setActuador(&cal2);
  {
    pruebas++;
    Actuador* sa = cnt2.getActuador();
    if (sa != &cal2)
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve "
          << " un actuador que no se esperaba" << std::endl;
  }

  std::cout << "- Pedimos sensor al 1er controlador" << std::endl;
  {
    pruebas++;
    Sensor* sa = cnt1.getSensor();
    if (sa != &st2)
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve "
          << " un sensor que no se esperaba" << std::endl;
  }

  std::cout << "- Pedimos actuador al 2º controladro" << std::endl;
  {
    pruebas++;
    Actuador* sa = cnt2.getActuador();
    if (sa != &cal2)
      std::cout << "FALLO " << ++fallos << ": el controlador devuelve "
          << " un actuador que no se esperaba" << std::endl;
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
