// Autor: Lucas Díaz Pérez
// Fecha: 5/11/2024
#include <iostream>
#include <string>
#include <vector>

void numeroBitsBool(unsigned valor, std::vector<bool>& vectorBool)
{
  int totalBits = sizeof(valor)*8;
  std::string versionString;
  bool unoVisto = false;

  for(int i = (totalBits - 1); i >= 0; i--){

  int mascara = 1 << i;

    if(valor & mascara)
    {
      versionString =  versionString + '1';
      unoVisto = true;
    }
    else
    {
      if(unoVisto)
      {
        versionString = versionString + '0';
      }
    }
  }
  
  for(unsigned i = 0; i < versionString.size() ; i++)
  {
    if(versionString[i] == '1')
    {
      vectorBool.push_back(true);
    }
    
    if(versionString[i] == '0')
    {
      vectorBool.push_back(false);
    }
  }
}

int main()
{
  unsigned entero;
  //manejamos la entrada como string para poder detectar el fallo de 
  //conversión a unsgined en caso de que no se trate de uno (ej: xx)
  std::string input;

  do
  {
    std::cin >> input;
    try
    {
      entero = std::stoul(input); //Si NO es unsigned manda una execpción
    }
    catch(std::invalid_argument& e)
    {
        return 1;
    }
    
    std::vector<bool> vectorBool;
    numeroBitsBool(entero,vectorBool); 
    
    for(unsigned i = 0; i < vectorBool.size() ; i++)
    {
      if(vectorBool.at(i) == true)
      {
        std::cout << "V, ";
      }
      
      if(vectorBool.at(i) == false)
      {
        std::cout << "F, ";
      }
      //~ std::cerr << vectorBool.at(i);
    }
    
    if(entero == 0)
    {
      std::cout << "F, ";
    }
    
    std::cout << "\n";
  }
  while(entero != 0);
  
  return 0;
}
