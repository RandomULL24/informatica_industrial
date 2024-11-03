// Autor: Alberto Hamilton

#define TITULO "ControladorPI → cambios consigna, Kp, Ki"


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

  std::cout << "- controlador y encendido " << std::endl;
  ControladorPI cnt1;
  cnt1.enciende();
  std::cout << "- Conectamos un calefactor" << std::endl;
  float calMax = 22.8;
  Calefactor cal1(calMax);
  cnt1.setActuador(&cal1);
  cal1.enciende();
  cal1.setComando(20.0);

  std::cout << "- Conectamos un sensor Temperatura y lo encendemos" << std::endl;
  float maxTemp = 100.22;
  float minTemp = -50.7;
  SensorTemperatura st1(minTemp, maxTemp);
  cnt1.setSensor(&st1);
  st1.enciende();

  std::vector<float> consignas {
       0.5    , 0.5    , 0.5    , 0.5    , 0.5    , 0.5    , 0.5    ,
       0.5    , 0.5    , 0.5    , 0.84375, 0.84375, 0.84375, 0.84375,
       0.84375, 0.84375, 0.84375, 0.84375, 0.84375, 0.84375, 0.84375,
       0.84375, 0.84375, 0.84375, 0.84375, 0.7375 , 0.7375 , 0.7375 ,
       0.7375 , 0.7375 , 0.7375 , 0.7375 , 0.7375 , 0.7375 , 0.7375 ,
       0.7375 , 0.7375 , 0.7375 , 0.7375 , 0.7375
  };
  std::vector<float> Kps {
    1, 1, 1, 1, 1, 0.3, 0.3, 0.3, 0.3, 0.3,
    0.3, 0.3, 0.3, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5,
    1.5, 2.5, 2.5, 2.5, 2.5, 2.5, 2.5, 2.5, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9,
  };
  std::vector<float> Kis {
    0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01,
    0.03, 0.03, 0.03, 0.03, 0.03, 0.03, 0.03, 0.03, 0.03, 0.03, 0.03, 0.03, 0.03, 0.03, 0.03,
    0.04, 0.04, 0.04, 0.04, 0.04, 0.04, 0.04, 0.04, 0.04, 0.04,
  };
  std::vector<float> temp {
    19.3, 18.59565292170715, 18.9765747885323, 18.292381238142497, 19.04954876112817, 19.21973587786203, 19.80307503869093, 19.333715368328896, 19.81748495460068, 20.579959891047665, 20.117710965572673, 19.591631428826414, 20.014930499379986, 19.822702293246174, 19.38578144290287, 18.89092769146849, 18.96292512424079, 19.631504451415253, 18.944746537008836, 18.711430703485703, 18.97709015630327, 19.575431345415797, 20.302802714374845, 19.639161567688195, 19.920560206164733, 19.329723657689936, 19.362457379600894, 19.727500085384662, 20.133560293550765, 20.15078390038011, 19.890147039125708, 19.365623338670034, 19.031014240642744, 18.464901343897335, 18.36720874543567, 18.581922952761637, 18.835163069968573, 18.722747603673213, 19.174915943066964, 19.8285948543869
  };
  std::vector<float> poten {
    0.8331096,  0.9488302,  0.9000204,  1.013154 ,  0.9073935,
        0.3041619,  0.2852127,  0.3146827,  0.3002241,  0.2719821,
        2.72957  ,  2.839596 ,  2.905955 , 13.30057  , 13.48608  ,
       14.8839   , 15.12898  , 15.23584  , 15.65295  , 15.96836  ,
       16.16949  , 16.29252  , 16.38302  , 16.79174  , 16.98503  ,
       13.67223  , 20.08216  , 20.12954  , 20.1596   , 20.33643  ,
       22.36693  , 22.8      , 22.8      , 13.47465  , 13.74316  ,
       13.9679   , 14.18587  , 14.45424  , 14.64311  , 14.80063
  };

  float conAnt = 0;
  float KpAnt = 0;
  float KiAnt = 0;

  for(unsigned i = 0; i < temp.size(); i++) {
    float con = consignas.at(i);
    float Kp = Kps.at(i);
    float Ki = Kis.at(i);
    if(con != conAnt) {
      std::cout << "- consigna " << con  << std::endl;
      cnt1.setConsigna(con);
      conAnt = con;
    }
    if(Kp != KpAnt) {
      std::cout << "- Kp " << Kp  << std::endl;
      cnt1.setKp(Kp);
      KpAnt = Kp;
    }
    if(Ki != KiAnt) {
      std::cout << "- Ki " << Ki  << std::endl;
      cnt1.setKi(Ki);
      KiAnt = Ki;
    }
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
