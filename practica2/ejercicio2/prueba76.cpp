// Autor: Alberto Hamilton

#define TITULO "ControladorPI → calculaEtapa"


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
  float Ki = 0.03;
  float Kp = 0.6;

  std::cout << "- controlador y encendido y con consigna " << consigna  << std::endl;
  ControladorPI cnt1;
  cnt1.enciende();
  cnt1.setConsigna(consigna);

  std::cout << "- Fijamos Kp a " << Kp << std::endl;
  cnt1.setKp(Kp);
  std::cout << "- Fijamos Ki a " << Ki << std::endl;
  cnt1.setKi(Ki);


  std::cout << "- Conectamos un calefactor" << std::endl;
  float calMax = 50.4;
  Calefactor cal1(calMax);
  cnt1.setActuador(&cal1);
  cal1.enciende();
  cal1.setComando(20.0);

  std::cout << "- Conectamos un sensor Temperatura y lo encendemos" << std::endl;
  float maxTemp = 37.22;
  float minTemp = 11.7;
  SensorTemperatura st1(minTemp, maxTemp);
  cnt1.setSensor(&st1);
  st1.enciende();

  std::vector<float> temp {
    21.0, 21.27794236784461, 20.65823531295678, 20.662401222107047, 21.187311431236555, 21.740224217357643, 21.987376415039414, 21.619239627002607, 21.228646531820154, 21.78533831493647, 22.232937721449897, 22.047430802902397, 21.66779459517529, 22.34970951210579, 21.674241848192736, 21.63781870677024, 21.11091349783316, 20.990048467547492, 20.42481297471974, 21.118523406919007, 21.53717503643537, 21.795000980578244, 21.79275135883166, 21.685213601915382, 21.649530411955126, 22.020301405693147, 22.20248446276119, 22.90030913178392, 22.97231582222213, 23.04645974085637, 22.86275294954198, 23.050221067155974, 23.47821775041265, 22.861362388398234, 22.975071534795806, 22.738222065190932, 22.894298829474074, 23.42699575366808, 22.874272437488468, 22.19253938012773
  };
  std::vector<float> poten {
      4.304935, 4.164115, 5.123685, 5.343747, 4.915653, 4.421617,
       4.275249, 4.879783, 5.534067, 5.032882, 4.634447, 4.997203,
       5.612484, 4.929476, 5.894924, 6.105291, 6.928074, 7.276879,
       8.185734, 7.561695, 7.238784, 7.091166, 7.251859, 7.543687,
       7.752482, 7.457683, 7.375557, 6.641076, 6.643892, 6.639785,
       6.952102, 6.813488, 6.364499, 7.190159, 7.143399, 7.526064,
       7.433885, 6.863866, 7.612769, 8.554933
  };

  for(unsigned i = 0; i < temp.size(); i++) {
    float temA = temp.at(i);
    std::cout << "- Fijamos temperatura a " << temA << " y calculamos etapa "<< std::endl;
    pruebas++;
    float esperado = poten.at(i);
    st1.setTemperatura(temA);
    cnt1.calculaEtapa();
    float ma = cal1.getPotencia();
    if(!(std::abs(ma - esperado) < EPS))  // detecta NaN
      std::cout << "FALLO " << ++fallos << ": el calefactor aplica potencia "
          << std::scientific << ma <<" cuando se esperaba " << esperado << std::endl;
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
