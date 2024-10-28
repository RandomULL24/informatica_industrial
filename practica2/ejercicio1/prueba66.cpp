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
0.1250000000, 0.0104166670, 1.0000000000,
0.2411611676, 0.0200967640, 1.0000000000,
0.3538841307, 0.0294903442, 1.0000000000,
0.4640120864, 0.0386676751, 1.0000000000,
0.5719825029, 0.0476652086, 1.0000000000,
0.6780751348, 0.0565062612, 1.0000000000,
0.7824888229, 0.0652073994, 1.0000000000,
0.8853742480, 0.0737811849, 1.0000000000,
0.9868506789, 0.0822375566, 1.0000000000,
1.0870156288, 0.0905846357, 1.0000000000,
1.1859506369, 0.0988292173, 1.0000000000,
1.2837252617, 0.1069771051, 1.0000000000,
1.3803998232, 0.1150333211, 1.0000000000,
1.4760272503, 0.1230022684, 1.0000000000,
1.5706542730, 0.1308878511, 1.0000000000,
1.6643228531, 0.1386935711, 1.0000000000,
1.7570706606, 0.1464225501, 1.0000000000,
1.8489320278, 0.1540776640, 1.0000000000,
1.9399381876, 0.1616615206, 1.0000000000,
2.0301177502, 0.1691764742, 1.0000000000,
2.1194972992, 0.1766247749, 1.0000000000,
2.2081010342, 0.1840084195, 1.0000000000,
2.2959518433, 0.1913293153, 1.0000000000,
2.3830709457, 0.1985892504, 1.0000000000,
2.4694778919, 0.2057898194, 0.0000000000,
2.4301915169, 0.2025159597, 0.0000000000,
2.3912189007, 0.1992682368, 1.0000000000,
2.4775600433, 0.2064633369, 0.0000000000,
2.4382092953, 0.2031841129, 0.0000000000,
2.3991723061, 0.1999310255, 1.0000000000,
2.4854490757, 0.2071207613, 0.0000000000,
2.4460358620, 0.2038363218, 0.0000000000,
2.4069364071, 0.2005780339, 0.0000000000,
2.3681507111, 0.1973458976, 1.0000000000,
2.4546787739, 0.2045565695, 0.0000000000,
2.4155101776, 0.2012925148, 0.0000000000,
2.3766553402, 0.1980546117, 1.0000000000,
2.4631142616, 0.2052595168, 0.0000000000,
2.4238784313, 0.2019898742, 0.0000000000,
2.3849563599, 0.1987463683, 1.0000000000,
2.4713480473, 0.2059456706, 0.0000000000,
2.4320466518, 0.2026705593, 0.0000000000,
2.3930590153, 0.1994215846, 1.0000000000,
2.4793851376, 0.2066154331, 0.0000000000,
2.4400200844, 0.2033350021, 0.0000000000,
2.4009687901, 0.2000807375, 0.0000000000,
2.3622312546, 0.1968526095, 1.0000000000,
2.4488074780, 0.2040672898, 0.0000000000,
2.4096858501, 0.2008071542, 0.0000000000,
  };

  float maxValvula = 0.5;
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
