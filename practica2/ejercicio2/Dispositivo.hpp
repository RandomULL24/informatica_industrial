// Definición de de la clase Dispositivos
// Autor: Alberto Hamilton
// Fecha: 2023-10-20

#ifndef _DISPOSITIVO_
#define _DISPOSITIVO_

#include <string>

class Dispositivo {

private:
  static unsigned ultimoID;
  unsigned id;

  std::string nombre = "-";

  bool encendido = false;

public:
  Dispositivo();

  unsigned getId() const;
  void setNombre(std::string nombre);
  std::string getNombre() const;
  void enciende();
  void apaga();
  bool isEncendido() const;
  std::string toString() const;
  

};


#endif
