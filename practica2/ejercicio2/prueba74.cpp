// Autor: Alberto Hamilton

#define TITULO "ControladorPI → calculaComando"


#include "ControladorPI.hpp"
#include "SensorTemperatura.hpp"
#include "Calefactor.hpp"
#include <iostream>
#include <vector>
#include <iomanip>

#define EPS (1e-5)

int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  std::cout << "- controlador y encendido y con consigna 0.67"  << std::endl;
  ControladorPI cnt1;
  cnt1.enciende();
  cnt1.setConsigna(0.67);

  float Ki = 0.005;
  float Kp = 1.2;

  std::cout << "- Fijamos Kp a " << Kp << std::endl;
  cnt1.setKp(Kp);
  std::cout << "- Fijamos Ki a " << Ki << std::endl;
  cnt1.setKi(Ki);

  std::vector<float> medida {
        0.0625    ,  0.03880837,  0.00681519, -0.01975022, -0.03525834,
       -0.00123721,  0.01065839,  0.05249574,  0.08498484,  0.12780852,
        0.12902842,  0.17331225,  0.16322266,  0.1849471 ,  0.16516179,
        0.12494717,  0.16032125,  0.1566137 ,  0.13258282,  0.09021987,
        0.03800705,  0.0421403 ,  0.05254372,  0.01965757,  0.05154431,
        0.02177608, -0.00693859, -0.01515593, -0.03452843, -0.02296877,
       -0.04209733, -0.02244429,  0.02015605, -0.03020523, -0.07046137,
       -0.11172123, -0.12386542, -0.13522928, -0.09193527, -0.07737646
       };
  std::vector<float> comando {
    0.7320375, 0.7636235, 0.8053312, 0.8406584, 0.8627945, 0.8253253,
       0.8143473, 0.76723  , 0.7311682, 0.6824907, 0.6837317, 0.6330745,
       0.6477159, 0.6240718, 0.6503384, 0.7013212, 0.6614208, 0.6684367,
       0.6999608, 0.7536953, 0.8195106, 0.81769  , 0.8082932, 0.8510084,
       0.8158365, 0.8547995, 0.8926418, 0.9059284, 0.9326981, 0.9222913,
       0.948806 , 0.9286847, 0.8808134, 0.944748 , 0.9967577, 1.050178 ,
       1.06872  , 1.086383 , 1.03824  , 1.024506
  };

  for(unsigned i = 0; i < medida.size(); i++) {
    float medA = medida.at(i);
    std::cout << "- Invocamos calcula comando con medida " << medA << std::endl;
    pruebas++;
    float esperado = comando.at(i);
    float ma = cnt1.calculaComando(medA);
    if(!(std::abs(ma - esperado) < EPS))  // detecta NaN
      std::cout << "FALLO " << ++fallos << ": el controlador calcula comando "
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
