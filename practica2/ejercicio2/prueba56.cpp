// Autor: Alberto Hamilton

#define TITULO "Planta1TanqueNivel y ControladorONOFF cambiando A, Z y T"


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

{
  std::vector<float> valores {
0.0000000000, 0.0000000000, 1.0000000000,
0.3666666746, 0.0305555556, 1.0000000000,
0.6889278293, 0.0574106537, 1.0000000000,
0.9947265983, 0.0828938857, 1.0000000000,
1.2882535458, 0.1073544621, 1.0000000000,
1.5716860294, 0.1309738308, 1.0000000000,
1.8464169502, 0.1538680792, 1.0000000000,
2.1134362221, 0.1761196852, 1.0000000000,
2.3734934330, 0.1977911144, 1.0000000000,
2.6271817684, 0.2189318091, 0.0000000000,
2.5083189011, 0.2090265751, 0.0000000000,
2.3921759129, 0.1993479878, 1.0000000000,
2.6454203129, 0.2204516977, 0.0000000000,
2.5261454582, 0.2105121166, 0.0000000000,
2.4095904827, 0.2007992119, 0.0000000000,
2.2957561016, 0.1913130134, 1.0000000000,
2.5513098240, 0.2126091570, 0.0000000000,
2.4341757298, 0.2028479725, 0.0000000000,
2.3197622299, 0.1933135241, 1.0000000000,
2.5747365952, 0.2145613879, 0.0000000000,
2.4570660591, 0.2047555000, 0.0000000000,
2.3421158791, 0.1951763183, 1.0000000000,
2.5965533257, 0.2163794488, 0.0000000000,
2.4783852100, 0.2065321058, 0.0000000000,
2.3629374504, 0.1969114542, 1.0000000000,
2.6168773174, 0.2180731148, 0.0000000000,
2.4982476234, 0.2081872970, 0.0000000000,
2.3823380470, 0.1985281706, 1.0000000000,
2.6358160973, 0.2196513414, 0.0000000000,
2.5167579651, 0.2097298354, 0.0000000000,
2.4004197121, 0.2000349760, 0.0000000000,
2.2868022919, 0.1905668527, 1.0000000000,
2.5425729752, 0.2118810862, 0.0000000000,
2.4256396294, 0.2021366358, 0.0000000000,
2.3114268780, 0.1926189065, 1.0000000000,
2.5666022301, 0.2138835192, 0.0000000000,
2.4491176605, 0.2040931433, 0.0000000000,
2.3343534470, 0.1945294589, 1.0000000000,
2.5889770985, 0.2157480866, 0.0000000000,
2.4709815979, 0.2059151381, 0.0000000000,
2.3557062149, 0.1963088512, 1.0000000000,
2.6098186970, 0.2174848914, 0.0000000000,
2.4913492203, 0.2076124400, 0.0000000000,
2.3755998611, 0.1979666501, 1.0000000000,
2.6292381287, 0.2191031724, 0.0000000000,
2.5103287697, 0.2091940641, 0.0000000000,
2.3941392899, 0.1995116025, 1.0000000000,
2.6473371983, 0.2206114382, 0.0000000000,
2.5280191898, 0.2106682658, 0.0000000000,
2.4114210606, 0.2009517550, 0.0000000000,
  };

  float maxValvula = 1.1;
  float maxNivel = 12;
  std::cout << "- construimos planta con "  << maxValvula << ", " << maxNivel
      << std::endl;
  Planta1TanqueNivel planta(maxValvula, maxNivel);
  planta.setNombre("Planta");

  std::cout << "- Cambianmos Z y A" << std::endl;

  planta.setA(1.5);
  planta.setZ(0.22);

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
}

{
  std::vector<float> valores {
0.0000000000, 0.0000000000, 1.0000000000,
0.5500000119, 0.0458333343, 1.0000000000,
1.0184218884, 0.0848684907, 1.0000000000,
1.4574133158, 0.1214511096, 1.0000000000,
1.8746175766, 0.1562181264, 1.0000000000,
2.2740092278, 0.1895007640, 1.0000000000,
2.6581311226, 0.2215109318, 0.0000000000,
2.4787895679, 0.2065657973, 0.0000000000,
2.3056037426, 0.1921336502, 1.0000000000,
2.6885774136, 0.2240481228, 0.0000000000,
2.5082116127, 0.2090176344, 0.0000000000,
2.3340008259, 0.1945000738, 1.0000000000,
2.7159490585, 0.2263290882, 0.0000000000,
2.5346674919, 0.2112222910, 0.0000000000,
2.3595404625, 0.1966283768, 1.0000000000,
2.7405717373, 0.2283809781, 0.0000000000,
2.5584702492, 0.2132058591, 0.0000000000,
2.3825228214, 0.1985435635, 1.0000000000,
2.7627332211, 0.2302277684, 0.0000000000,
2.5798969269, 0.2149914056, 0.0000000000,
2.4032142162, 0.2002678514, 0.0000000000,
2.2326889038, 0.1860574037, 1.0000000000,
2.6183249950, 0.2181937546, 0.0000000000,
2.4403314590, 0.2033609599, 0.0000000000,
2.2684943676, 0.1890411973, 1.0000000000,
2.6528177261, 0.2210681438, 0.0000000000,
2.4736554623, 0.2061379552, 0.0000000000,
2.3006489277, 0.1917207390, 1.0000000000,
2.6838021278, 0.2236501724, 0.0000000000,
2.5035967827, 0.2086330652, 0.0000000000,
2.3295464516, 0.1941288710, 1.0000000000,
2.7116551399, 0.2259712666, 0.0000000000,
2.5305171013, 0.2108764201, 0.0000000000,
2.3555335999, 0.1962944716, 1.0000000000,
2.7367084026, 0.2280590385, 0.0000000000,
2.5547354221, 0.2128946185, 0.0000000000,
2.3789165020, 0.1982430369, 1.0000000000,
2.7592554092, 0.2299379557, 0.0000000000,
2.5765342712, 0.2147111893, 0.0000000000,
2.3999667168, 0.1999972314, 1.0000000000,
2.7795567513, 0.2316297293, 0.0000000000,
2.5961647034, 0.2163470536, 0.0000000000,
2.4189260006, 0.2015771717, 0.0000000000,
2.2478442192, 0.1873203516, 1.0000000000,
2.6329233646, 0.2194102854, 0.0000000000,
2.4544341564, 0.2045361847, 0.0000000000,
2.2821011543, 0.1901751012, 1.0000000000,
2.6659283638, 0.2221606970, 0.0000000000,
2.4863240719, 0.2071936727, 0.0000000000,
2.3128752708, 0.1927396059, 1.0000000000,
  };

  float maxValvula = 1.1;
  float maxNivel = 12;
  std::cout << "- construimos planta con "  << maxValvula << ", " << maxNivel
      << std::endl;
  Planta1TanqueNivel planta(maxValvula, maxNivel);
  planta.setNombre("Planta");

  std::cout << "- Cambianmos Z y A" << std::endl;

  planta.setA(1.5);
  planta.setZ(0.22);
  std::cout << "- Cambianmos periodo" << std::endl;
  planta.setMsPeriodo(750);

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
