// Autor: Alberto Hamilton

#define TITULO "Planta1TanqueNivel → calculaEtapa"


#include "Planta1TanqueNivel.hpp"
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

#define EPS (1e-6)

int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  std::vector<float> comandos {
    0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0
  };
  std::vector<float> alturas {
0.000000e+00, 0.000000e+00, 1.250000e-01, 2.411612e-01, 3.538841e-01, 4.640121e-01, 5.719825e-01, 6.780751e-01, 7.824888e-01, 8.853742e-01, 9.868507e-01, 1.087016e+00, 1.060951e+00, 1.035200e+00, 1.009764e+00, 9.846421e-01, 1.084835e+00, 1.183796e+00, 1.281595e+00, 1.378294e+00, 1.473943e+00,
  };
  std::vector<float> medidas {
0.000000e+00, 0.000000e+00, 1.041667e-02, 2.009676e-02, 2.949034e-02, 3.866768e-02, 4.766521e-02, 5.650626e-02, 6.520740e-02, 7.378118e-02, 8.223756e-02, 9.058464e-02, 8.841255e-02, 8.626667e-02, 8.414698e-02, 8.205350e-02, 9.040290e-02, 9.864966e-02, 1.067996e-01, 1.148578e-01, 1.228286e-01,
  };


  float maxValvula = 0.5;
  float maxNivel = 12;
  std::cout << "- construimos con "  << maxValvula << ", " << maxNivel << std::endl;
  Planta1TanqueNivel planta(maxValvula, maxNivel);
  planta.setNombre("Planta");

  std::cout << "- Pedimos altura" << std::endl;
  {
    pruebas++;
    float ma = planta.getAltura();
    if(!std::isnan(ma))
      std::cout << "FALLO " << ++fallos << ": se devuelve altura "
          << ma <<" cuando se esperaba NaN" << std::endl;
  }

  Valvula* valPt = planta.getValvulaPt();
  SensorNivel* nivPt = planta.getSensorNivelPt();

  std::cout << "- Encendemos la planta" << std::endl;
  planta.enciende();
  {
    pruebas++;
    float esperado = 0.0;
    float ma = planta.getAltura();
    if(ma != esperado)
      std::cout << "FALLO " << ++fallos << ": la planta da altura "
          << ma <<" cuando se esperaba " << esperado << std::endl;
  }

  for(unsigned i = 0; i < comandos.size(); i++) {
    float cAct = comandos.at(i);
    std::cout << "- Aplicamos comando " << cAct << std::endl;
    valPt->setComando(cAct);
    planta.calculaEtapa();
    {
      pruebas++;
      float esperado = alturas.at(i);
      float ma = planta.getAltura();
      if(std::abs(ma - esperado) > EPS)
        std::cout << "FALLO " << ++fallos << ": la altura de la planta es "
            << ma <<" cuando se esperaba " << esperado << std::endl;
    }
    {
      pruebas++;
      float esperado = medidas.at(i);
      float ma = nivPt->getMedida();
      if(std::abs(ma - esperado) > EPS)
        std::cout << "FALLO " << ++fallos << ": sensor nive da medida "
            << ma <<" cuando se esperaba " << esperado << std::endl;
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
