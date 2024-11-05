// Autor: Lucas Díaz Pérez
// Fecha: 8-7-2024
#include <iostream>
#include <string>

int numero_bits_uno(int num)
{
  
  int cuenta = 0;
  int mascara = 1;

  for(unsigned i = 0; i < sizeof(num)*8 ; i++){
    if(num & mascara)
    {
      //el bit en la posición de la máscara esa a uno
      cuenta++;
    }
    mascara = mascara << 1; //Desplaza 1 espacio la máscara a la izq.
  }



  return cuenta;
}

int main()
{
  int entero;
  //manejamos la entrada como string para poder detectar el fallo de 
  //conversión a entero en caso de que no se trate de uno (ej: xx)
  std::string input;  
  
  do
  {
    std::cin >> input;
    
    try
    {
      entero = std::stoi(input);
    }
    catch(std::invalid_argument& e) //Si NO es entero que devuelva error
    {
      return 1;
    } 
    std::cout << std::dec << numero_bits_uno(entero) << " 0x" << 
        std::hex << entero << std::endl;
  
  }
  while(entero != 0);

  return 0;
}
