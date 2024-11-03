// Autor: Alberto Hamilton

#define TITULO "Dispositivo → toString << otras clases"


#include "SensorNivel.hpp"
#include "SensorTemperatura.hpp"
#include "Valvula.hpp"
#include "Calefactor.hpp"
#include <iostream>
#include <vector>
#include <iomanip>


int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  pruebas++;
  std::string nom1 = "Primero";
  std::string toStr1 = "'" + nom1 + "(id=1)'";
  SensorNivel d1(2.8);
  std::cout << "- Creado un dispositivo" << std::endl;
  d1.setNombre(nom1);
  std::cout << "- puesto nombre " << std::endl;
  {
    std::string nom = nom1;
    std::string nomG = d1.getNombre();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " nombre del dispositivo "
          << d1.getId() << " es '" << nomG << "' cuando se esperaba '"
          << nom << "'" << std::endl;
  }
  pruebas++;
  {
    std::string nom = toStr1;
    std::string nomG = d1.toString();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " toString() del dispositivo "
          << d1.getId() << " es '" << nomG << "' cuando se esperaba '"
          << nom << "'" << std::endl;
  }
  pruebas++;
  {
    std::string nom = toStr1;
    std::ostringstream oss;
    oss << d1;
    std::string nomG = oss.str();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " << del dispositivo "
          << d1.getId() << " es '" << nomG << "' cuando se esperaba '"
          << nom << "'" << std::endl;
  }
  pruebas++;
  {
    std::string nom = toStr1;
    std::ostringstream oss;
    oss << (&d1);
    std::string nomG = oss.str();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " << puntero del dispositivo "
          << d1.getId() << " es '" << nomG << "' cuando se esperaba '"
          << nom << "'" << std::endl;
  }

  pruebas++;
  std::string nom2 = "Segundo";
  std::string toStr2 = "'" + nom2 + "(id=2)'";
  SensorTemperatura d2(-12.4, 8.7);
  std::cout << "- Creado un dispositivo" << std::endl;
  d2.setNombre(nom2);
  std::cout << "- puesto nombre " << std::endl;
  {
    std::string nom = nom2;
    std::string nomG = d2.getNombre();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " nombre del dispositivo "
          << d2.getId() << " es '" << nomG << "' cuando se esperaba '"
          << nom << "'" << std::endl;
  }
  pruebas++;
  {
    std::string nom = toStr2;
    std::string nomG = d2.toString();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " toString() del dispositivo "
          << d2.getId() << " es '" << nomG << "' cuando se esperaba '"
          << nom << "'" << std::endl;
  }
  pruebas++;
  {
    std::string nom = toStr2;
    std::ostringstream oss;
    oss << d2;
    std::string nomG = oss.str();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " << del dispositivo "
          << d2.getId() << " es '" << nomG << "' cuando se esperaba '"
          << nom << "'" << std::endl;
  }
  pruebas++;
  {
    std::string nom = toStr2;
    std::ostringstream oss;
    oss << (&d2);
    std::string nomG = oss.str();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " << puntero del dispositivo "
          << d2.getId() << " es '" << nomG << "' cuando se esperaba '"
          << nom << "'" << std::endl;
  }

  pruebas++;
  std::string nom3 = "Tercero";
  std::string toStr3 = "'" + nom3 + "(id=3)'";
  Valvula d3(3.8);
  std::cout << "- Creado un dispositivo" << std::endl;

  d3.setNombre(nom3);
  std::cout << "- puesto nombre " << std::endl;
  {
    std::string nom = nom3;
    std::string nomG = d3.getNombre();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " nombre del dispositivo "
          << d3.getId() << " es '" << nomG << "' cuando se esperaba '"
          << nom << "'" << std::endl;
  }
  pruebas++;
  {
    std::string nom = toStr3;
    std::string nomG = d3.toString();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " toString() del dispositivo "
          << d3.getId() << " es '" << nomG << "' cuando se esperaba '"
          << nom << "'" << std::endl;
  }
  pruebas++;
  {
    std::string nom = toStr3;
    std::ostringstream oss;
    oss << d3;
    std::string nomG = oss.str();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " << del dispositivo "
          << d3.getId() << " es '" << nomG << "' cuando se esperaba '"
          << nom << "'" << std::endl;
  }
  pruebas++;
  {
    std::string nom = toStr3;
    std::ostringstream oss;
    oss << (&d3);
    std::string nomG = oss.str();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " << puntero del dispositivo "
          << d3.getId() << " es '" << nomG << "' cuando se esperaba '"
          << nom << "'" << std::endl;
  }

  pruebas++;
  std::string nom4 = "Cuarto";
  std::string toStr4 = "'" + nom4 + "(id=4)'";
  Calefactor d4(50);
  std::cout << "- Creado un dispositivo" << std::endl;

  d4.setNombre(nom4);
  std::cout << "- puesto nombre " << std::endl;
  {
    std::string nom = nom4;
    std::string nomG = d4.getNombre();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " nombre del dispositivo "
          << d4.getId() << " es '" << nomG << "' cuando se esperaba '"
          << nom << "'" << std::endl;
  }
  pruebas++;
  {
    std::string nom = toStr4;
    std::string nomG = d4.toString();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " toString() del dispositivo "
          << d4.getId() << " es '" << nomG << "' cuando se esperaba '"
          << nom << "'" << std::endl;
  }
  pruebas++;
  {
    std::string nom = toStr4;
    std::ostringstream oss;
    oss << d4;
    std::string nomG = oss.str();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " << del dispositivo "
          << d4.getId() << " es '" << nomG << "' cuando se esperaba '"
          << nom << "'" << std::endl;
  }
  pruebas++;
  {
    std::string nom = toStr4;
    std::ostringstream oss;
    oss << (&d4);
    std::string nomG = oss.str();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " << puntero del dispositivo "
          << d4.getId() << " es '" << nomG << "' cuando se esperaba '"
          << nom << "'" << std::endl;
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
