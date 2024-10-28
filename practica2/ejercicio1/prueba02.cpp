// Autor: Alberto Hamilton

#define TITULO "Dispositivo → getNombre"


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
  Dispositivo d1;
  std::cout << "- Creado un dispositivo" << std::endl;
  {
    Dispositivo& da = d1;
    std::string nom = nomDefecto;
    std::string nomG = da.getNombre();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " nombre del dispositivo "
          << da.getId() << " es '" << nomG
          << "' cuando se esperaba nombre por defecto '" << nom << "'"
          << std::endl;
  }

  d1.setNombre(nom1);
  std::cout << "- puesto nombre " << std::endl;
  {
    Dispositivo& da = d1;
    std::string nom = nom1;
    std::string nomG = da.getNombre();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " nombre del dispositivo "
          << da.getId() << " es '" << nomG << "' cuando se esperaba '"
          << nom << "'" << std::endl;
  }

  pruebas++;
  std::string nom2 = "Segundo";
  Dispositivo d2;
  std::cout << "- Creado un dispositivo" << std::endl;
  {
    Dispositivo& da = d2;
    std::string nom = nomDefecto;
    std::string nomG = da.getNombre();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " nombre del dispositivo "
          << da.getId() << " es '" << nomG
          << "' cuando se esperaba nombre por defecto '" << nom << "'"
          << std::endl;
  }

  d2.setNombre(nom2);
  std::cout << "- puesto nombre " << std::endl;
  {
    Dispositivo& da = d2;
    std::string nom = nom2;
    std::string nomG = da.getNombre();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " nombre del dispositivo "
          << da.getId() << " es '" << nomG << "' cuando se esperaba '"
          << nom << "'" << std::endl;
  }

  pruebas++;
  std::string nom3 = "Tercero";
  Dispositivo d3;
  std::cout << "- Creado un dispositivo" << std::endl;
  {
    Dispositivo& da = d3;
    std::string nom = nomDefecto;
    std::string nomG = da.getNombre();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " nombre del dispositivo "
          << da.getId() << " es '" << nomG
          << "' cuando se esperaba nombre por defecto '" << nom << "'"
          << std::endl;
  }

  d3.setNombre(nom3);
  std::cout << "- puesto nombre " << std::endl;
  {
    Dispositivo& da = d3;
    std::string nom = nom3;
    std::string nomG = da.getNombre();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " nombre del dispositivo "
          << da.getId() << " es '" << nomG << "' cuando se esperaba '"
          << nom << "'" << std::endl;
  }

  pruebas++;
  {
    Dispositivo& da = d1;
    std::string nom = nom1;
    std::string nomG = da.getNombre();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " nombre del dispositivo "
          << da.getId() << " es '" << nomG << "' cuando se esperaba '"
          << nom << "'" << std::endl;
  }

  pruebas++;
  {
    Dispositivo& da = d2;
    std::string nom = nom2;
    std::string nomG = da.getNombre();
    if (nom != nomG)
      std::cout << "FALLO " << ++fallos << " nombre del dispositivo "
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
