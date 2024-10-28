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
1.0, 0.9473684210526316, 0.8947368421052632, 0.8421052631578947, 0.7894736842105263, 0.736842105263158, 0.6842105263157895, 0.631578947368421, 0.5789473684210527, 0.5263157894736843, 0.4736842105263158, 0.42105263157894735, 0.368421052631579, 0.3157894736842106, 0.26315789473684215, 0.21052631578947367, 0.1578947368421053, 0.10526315789473695, 0.052631578947368474, 0.0
  };
  std::vector<float> alturas {
1.250000e-01, 2.345822e-01, 3.343159e-01, 4.251240e-01, 5.075079e-01, 5.818032e-01, 6.482605e-01, 7.070792e-01, 7.584257e-01, 8.024432e-01, 8.392589e-01, 8.689877e-01, 8.917355e-01, 9.076012e-01, 9.166790e-01, 9.190589e-01, 9.148289e-01, 9.040751e-01, 8.868834e-01, 8.633398e-01,
  };
  std::vector<float> medidas {
1.041667e-02, 1.954852e-02, 2.785966e-02, 3.542700e-02, 4.229232e-02, 4.848360e-02, 5.402171e-02, 5.892327e-02, 6.320214e-02, 6.687026e-02, 6.993824e-02, 7.241564e-02, 7.431129e-02, 7.563344e-02, 7.638992e-02, 7.658824e-02, 7.623574e-02, 7.533959e-02, 7.390695e-02, 7.194498e-02,
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
