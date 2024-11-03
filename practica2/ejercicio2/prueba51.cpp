// Autor: Alberto Hamilton

#define TITULO "Dinamico → activar"


#include "Dinamico.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>


int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  std::vector<std::tuple<unsigned, unsigned, unsigned>> periodo2_espera = {
    {100, 50, 3000},
    {200, 150, 2500},
    {1000, 300, 7000},
  };

  Dinamico dina1;

  dina1.setNombre("DinaUno");

  for(auto p_e: periodo2_espera) {
    Dinamico& dinA = dina1;
    unsigned periodoMs = std::get<0>(p_e);
    unsigned esperaMs = std::get<2>(p_e) + 5;

    std::cout << "- Fijamos periodo 1 a " << periodoMs << std::endl;

    dinA.setMsPeriodo(periodoMs);
    {
      pruebas++;
      unsigned esperado = periodoMs;
      unsigned ma = dinA.getMsPeriodo();
      if(ma != esperado)
        std::cout << "FALLO " << ++fallos << ": se obtiene periodo "
            << ma <<" cuando se esperaba " << esperado << std::endl;
    }

    std::cout << "Encendemos y esperamos " << esperaMs/1000 << " segundos "
        << std::endl;

    dinA.enciendePeriodico();
    auto espera = std::chrono::milliseconds(esperaMs);
    std::this_thread::sleep_for(espera);
    dinA.apaga();

    {
      pruebas++;
      unsigned esperaEtapa = (esperaMs) / periodoMs + 1;
      unsigned etapas = dinA.getEtapa();
      if(esperaEtapa != etapas)
        std::cout << "FALLO " << ++fallos << ": se devuelven "
            << etapas <<" etapas cuando se esperaban " << esperaEtapa << std::endl;
    }
  }

  Dinamico dina2;
  dina2.setNombre("DinaDos");

  for(auto p_e: periodo2_espera) {
    Dinamico& dinA = dina2;
    unsigned periodoMs = std::get<1>(p_e);
    unsigned esperaMs = std::get<2>(p_e) + 5;

    std::cout << "- Fijamos periodo 2 a " << periodoMs << std::endl;

    dinA.setMsPeriodo(periodoMs);
    {
      pruebas++;
      unsigned esperado = periodoMs;
      unsigned ma = dinA.getMsPeriodo();
      if(ma != esperado)
        std::cout << "FALLO " << ++fallos << ": se obtiene periodo "
            << ma <<" cuando se esperaba " << esperado << std::endl;
    }

    std::cout << "Encendemos y esperamos " << esperaMs/1000 << " segundos "
        << std::endl;

    dinA.enciendePeriodico();
    auto espera = std::chrono::milliseconds(esperaMs);
    std::this_thread::sleep_for(espera);
    dinA.apaga();

    {
      pruebas++;
      unsigned esperaEtapa = (esperaMs) / periodoMs + 1;
      unsigned etapas = dinA.getEtapa();
      if(esperaEtapa != etapas)
        std::cout << "FALLO " << ++fallos << ": se devuelven "
            << etapas <<" etapas cuando se esperaban " << esperaEtapa << std::endl;
    }
  }

  // ambos dinámicos concurrentemente.
  for(auto p_e: periodo2_espera) {
    unsigned periodo1Ms = std::get<0>(p_e);
    unsigned periodo2Ms = std::get<1>(p_e);
    unsigned esperaMs = std::get<2>(p_e) + 5;

    std::cout << "- Fijamos periodo de 1 a " << periodo1Ms << std::endl;

    dina1.setMsPeriodo(periodo1Ms);
    {
      pruebas++;
      unsigned esperado = periodo1Ms;
      unsigned ma = dina1.getMsPeriodo();
      if(ma != esperado)
        std::cout << "FALLO " << ++fallos << ": se obtiene periodo "
            << ma <<" cuando se esperaba " << esperado << std::endl;
    }

    std::cout << "- Fijamos periodo de 2 a " << periodo2Ms << std::endl;

    dina2.setMsPeriodo(periodo2Ms);
    {
      pruebas++;
      unsigned esperado = periodo2Ms;
      unsigned ma = dina2.getMsPeriodo();
      if(ma != esperado)
        std::cout << "FALLO " << ++fallos << ": se obtiene periodo "
            << ma <<" cuando se esperaba " << esperado << std::endl;
    }

    std::cout << "Encendemos y esperamos " << esperaMs/1000 << " segundos "
        << std::endl;

    dina1.enciendePeriodico();
    dina2.enciendePeriodico();
    auto espera = std::chrono::milliseconds(esperaMs);
    std::this_thread::sleep_for(espera);
    dina2.apaga();
    dina1.apaga();

    {
      pruebas++;
      unsigned esperaEtapa = (esperaMs) / periodo1Ms + 1;
      unsigned etapas = dina1.getEtapa();
      if(esperaEtapa != etapas)
        std::cout << "FALLO " << ++fallos << ": se devuelven "
            << etapas <<" etapas cuando se esperaban " << esperaEtapa << std::endl;
    }
    {
      pruebas++;
      unsigned esperaEtapa = (esperaMs) / periodo2Ms + 1;
      unsigned etapas = dina2.getEtapa();
      if(esperaEtapa != etapas)
        std::cout << "FALLO " << ++fallos << ": se devuelven "
            << etapas <<" etapas cuando se esperaban " << esperaEtapa << std::endl;
    }
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
