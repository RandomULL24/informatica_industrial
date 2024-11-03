// Autor: Alberto Hamilton

#define TITULO "Dispositivo → sobrecarga << objeto"


#include "Dispositivo.hpp"
#include <iostream>
#include <vector>
#include <iomanip>


int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  std::string nomDefecto = "-";

  pruebas++;
  std::string nom1 = "Primero";
  std::string toStr1 = "'" + nom1 + "(id=1)'";
  Dispositivo d1;
  std::cout << "- Creado un dispositivo" << std::endl;

  d1.setNombre(nom1);
  std::cout << "- puesto nombre " << std::endl;
  {
    Dispositivo& da = d1;
    std::string nom = toStr1;
    std::ostringstream oss;
    oss << da;
    std::string nomG = oss.str();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " << del dispositivo "
          << da.getId() << " es '" << nomG << "' cuando se esperaba '"
          << nom << "'" << std::endl;
  }

  pruebas++;
  std::string nom2 = "Segundo";
  std::string toStr2 = "'" + nom2 + "(id=2)'";
  Dispositivo d2;
  std::cout << "- Creado un dispositivo" << std::endl;

  d2.setNombre(nom2);
  std::cout << "- puesto nombre " << std::endl;
  {
    Dispositivo& da = d2;
    std::string nom = toStr2;
    std::ostringstream oss;
    oss << da;
    std::string nomG = oss.str();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " << del dispositivo "
          << da.getId() << " es '" << nomG << "' cuando se esperaba '"
          << nom << "'" << std::endl;
  }

  pruebas++;
  std::string nom3 = "Tercero";
  std::string toStr3 = "'" + nom3 + "(id=3)'";
  Dispositivo d3;
  std::cout << "- Creado un dispositivo" << std::endl;

  d3.setNombre(nom3);
  std::cout << "- puesto nombre " << std::endl;
  {
    Dispositivo& da = d3;
    std::string nom = toStr3;
    std::ostringstream oss;
    oss << da;
    std::string nomG = oss.str();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " << del dispositivo "
          << da.getId() << " es '" << nomG << "' cuando se esperaba '"
          << nom << "'" << std::endl;
  }

  pruebas++;
  {
    Dispositivo& da = d1;
    std::string nom = toStr1;
    std::ostringstream oss;
    oss << da;
    std::string nomG = oss.str();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " << del dispositivo "
          << da.getId() << " es '" << nomG << "' cuando se esperaba '"
          << nom << "'" << std::endl;
  }

  pruebas++;
  {
    Dispositivo& da = d2;
    std::string nom = toStr2;
    std::ostringstream oss;
    oss << da;
    std::string nomG = oss.str();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " << del dispositivo "
          << da.getId() << " es '" << nomG << "' cuando se esperaba '"
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
