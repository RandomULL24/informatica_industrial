// Autor: Alberto Hamilton

#define TITULO "Planta1TanqueNivel y ControladorONOFF"


#include "Planta1TanqueNivel.hpp"
#include "ControladorONOFF.hpp"
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

#define EPS (1e-6)

int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  std::vector<float> valores {
0.0000000000, 0.0000000000, 1.0000000000,
0.2750000060, 0.0229166672, 1.0000000000,
0.5368899107, 0.0447408259, 1.0000000000,
0.7935717106, 0.0661309734, 1.0000000000,
1.0463010073, 0.0871917531, 1.0000000000,
1.2957288027, 0.1079773977, 1.0000000000,
1.5422712564, 0.1285226047, 1.0000000000,
1.7862242460, 0.1488520205, 1.0000000000,
2.0278117657, 0.1689843088, 1.0000000000,
2.2672114372, 0.1889342815, 1.0000000000,
2.5045683384, 0.2087140232, 0.0000000000,
2.4650037289, 0.2054169774, 0.0000000000,
2.4257528782, 0.2021460682, 0.0000000000,
2.3868157864, 0.1989013106, 1.0000000000,
2.6231925488, 0.2185993791, 0.0000000000,
2.5827019215, 0.2152251601, 0.0000000000,
2.5425250530, 0.2118770927, 0.0000000000,
2.5026617050, 0.2085551471, 0.0000000000,
2.4631121159, 0.2052593380, 0.0000000000,
2.4238762856, 0.2019896954, 0.0000000000,
2.3849542141, 0.1987461895, 1.0000000000,
2.6213459969, 0.2184454948, 0.0000000000,
2.5808696747, 0.2150724679, 0.0000000000,
2.5407068729, 0.2117255777, 0.0000000000,
2.5008578300, 0.2084048241, 0.0000000000,
2.4613225460, 0.2051102072, 0.0000000000,
2.4221010208, 0.2018417567, 0.0000000000,
2.3831932545, 0.1985994428, 1.0000000000,
2.6195993423, 0.2182999402, 0.0000000000,
2.5791363716, 0.2149280310, 0.0000000000,
2.5389871597, 0.2115822583, 0.0000000000,
2.4991517067, 0.2082626373, 0.0000000000,
2.4596300125, 0.2049691677, 0.0000000000,
2.4204220772, 0.2017018348, 0.0000000000,
2.3815279007, 0.1984606534, 1.0000000000,
2.6179473400, 0.2181622833, 0.0000000000,
2.5774972439, 0.2147914320, 0.0000000000,
2.5373606682, 0.2114467174, 0.0000000000,
2.4975378513, 0.2081281543, 0.0000000000,
2.4580287933, 0.2048357278, 0.0000000000,
2.4188334942, 0.2015694529, 0.0000000000,
2.3799519539, 0.1983293295, 1.0000000000,
2.6163842678, 0.2180320174, 0.0000000000,
2.5759460926, 0.2146621794, 0.0000000000,
2.5358216763, 0.2113184780, 0.0000000000,
2.4960110188, 0.2080009133, 0.0000000000,
2.4565141201, 0.2047095150, 0.0000000000,
2.4173309803, 0.2014442533, 0.0000000000,
2.3784615993, 0.1982051283, 1.0000000000,
2.6149058342, 0.2179088145, 0.0000000000,
  };

  float maxValvula = 1.1;
  float maxNivel = 12;
  std::cout << "- construimos planta con "  << maxValvula << ", " << maxNivel
      << std::endl;
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

  std::cout << "- Construimos ControladorONOFF" << std::endl;
  ControladorONOFF control;
  control.setActuador(valPt);
  control.setSensor(nivPt);

  float consigna = 0.2;
  std::cout << "- Fijamos la consigna a " << consigna << std::endl;
  control.setConsigna(consigna);


  std::cout << "- Encendemos la planta y controlador" << std::endl;
  planta.enciende();
  control.enciende();

  for(unsigned i = 0; i < 50; i++) {
    planta.calculaEtapa();
    control.calculaEtapa();
    float altura = planta.getAltura();
    float medida = nivPt->getMedida();
    float comando = valPt->getComando();
    std::cout << std::fixed << std::setprecision(10)
        << altura << ", "
        << medida << ", "
        << comando << ", "
        << std::endl;
    {
      pruebas++;
      float esperado = valores.at(i * 3);
      float ma = altura;
      if(std::abs(ma - esperado) > EPS)
        std::cout << "FALLO " << ++fallos << ": la altura de la planta es "
            << ma <<" cuando se esperaba " << esperado << std::endl;
    }
    {
      pruebas++;
      float esperado = valores.at(i * 3 + 1);
      float ma = medida;
      if(std::abs(ma - esperado) > EPS)
        std::cout << "FALLO " << ++fallos << ": la medida del sensor es "
            << ma <<" cuando se esperaba " << esperado << std::endl;
    }
    {
      pruebas++;
      float esperado = valores.at(i * 3 + 2);
      float ma = comando;
      if(std::abs(ma - esperado) > EPS)
        std::cout << "FALLO " << ++fallos << ": el comando del actuador es "
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
