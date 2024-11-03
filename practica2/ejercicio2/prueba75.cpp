// Autor: Alberto Hamilton

#define TITULO "ControladorPI → calculaComando"


#include "ControladorPI.hpp"
#include "SensorTemperatura.hpp"
#include "Calefactor.hpp"
#include <iostream>
#include <vector>
#include <iomanip>

#define EPS (1e-6)

int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  float consigna = 0.5;
  float Ki = 0.05;
  float Kp = 0.5;

  std::cout << "- controlador y encendido y con consigna " << consigna  << std::endl;
  ControladorPI cnt1;
  cnt1.enciende();
  cnt1.setConsigna(consigna);

  std::cout << "- Fijamos Kp a " << Kp << std::endl;
  cnt1.setKp(Kp);
  std::cout << "- Fijamos Ki a " << Ki << std::endl;
  cnt1.setKi(Ki);

  std::vector<float> medida {
      0.75      , 0.72763066, 0.70278048, 0.68916459, 0.64721089,
       0.63136477, 0.62337407, 0.61899095, 0.61872954, 0.60188128,
       0.57807499, 0.59233266, 0.6042923 , 0.56877463, 0.52885784,
       0.49351413, 0.48898726, 0.46050721, 0.46796934, 0.45302093,
       0.41940676, 0.41080536, 0.42751795, 0.44244363, 0.43352564,
       0.41589144, 0.42225769, 0.40823314, 0.38884129, 0.38631564,
       0.38402434, 0.38574491, 0.40443336, 0.37298028, 0.38021936,
       0.34936483, 0.31145661, 0.27936904, 0.28769872, 0.30455391
  };
  std::vector<float> comando {
    -0.1375    , -0.13769687, -0.13541081, -0.13806106, -0.12444481,
       -0.12308994, -0.12526331, -0.12902131, -0.13482706, -0.131497  ,
       -0.12349762, -0.13524306, -0.1464375 , -0.13211737, -0.11360187,
       -0.09560575, -0.09279169, -0.076577  , -0.07870656, -0.06888337,
       -0.04804663, -0.03928619, -0.04401837, -0.04860344, -0.04082069,
       -0.02779813, -0.02709419, -0.01549356, -0.00023969,  0.00670731,
        0.01365181,  0.01850425,  0.01393831,  0.03601587,  0.03838537,
        0.06134438,  0.08972569,  0.116801  ,  0.12325119,  0.12459594
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
