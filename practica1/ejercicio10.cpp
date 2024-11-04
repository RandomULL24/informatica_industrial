// Autor: Lucas Díaz Pérez
// Fecha: 8-7-2024
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>

unsigned funcion(const std::vector<bool>& vectorBool, unsigned indexInicial, 
    unsigned indexFinal)
{
  std::string string1;
  unsigned suma = 0;
  
  for(unsigned i = indexInicial; i <= (indexFinal); i++)
  {
    
    if(vectorBool.at(i) == true)
    {
      //~ std::cerr << "True" << std::endl;
      suma += (unsigned) std::pow(2,(i-indexInicial));
      string1 = "1" + string1 ;
      //~ std::cerr << (i-indexInicial) << "-"; 
    }
    
    if(vectorBool.at(i) == false)
    {
      string1 = "0" + string1 ;
    }
    //~ std::cerr << (i-indexInicial) << "-"; 
  }
  std::cerr << "\n"; 
  std::cerr << string1 << "\n"; 
  std::cerr << suma << std::endl; 
  
  return suma;
}

std::string numeroBits(unsigned valor)
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
  
  if(unoVisto == false)
  {
    versionString = '0';
  }
  
	return versionString;
}
	

int main(int argc, char* argv[])
{
  std::string nombreFich;
  try
  {
    nombreFich = argv[1];
  }
  catch(std::logic_error& e1)
  {
    std::cerr << "Nombre del fichero inválido" << std::endl;
    return 1;
  }
  
  if(argc < 2)
  {
    std::cerr << "Es necesario indicar el fichero de datos" << std::endl;
    return 2; //situación erronea
  }
  
  
  std:: size_t found = nombreFich.find(".dat");
  if (found == std::string::npos)
  {
    std::cerr << "El fichero NO contiene  la extensión '.dat'" << std::endl;
    nombreFich+= ".dat";
    std::cerr << "El nombre del fichero actualizado es: " << 
        nombreFich << std::endl;
  }
   
   
  std::cerr << "Vamos a tratar de abrir el fichero '" << nombreFich << "'"
      << std::endl;
      
  std::ifstream fichEntrada(nombreFich);
  
  if(fichEntrada.fail())
  {
   std::cerr << "No se pudo abrir el fichero" << std::endl;
    return 3;
  }
  
  std::string valorLeido;
  
  fichEntrada >> valorLeido;
  
  std::vector<std::string> datos;
  
  while(fichEntrada.good()) 
  {
    //~ std::cerr << "Valor leído " << valorLeido << std::endl;
    datos.push_back(valorLeido);
    fichEntrada >> valorLeido;
  }
   
  //Convertimos los datos que están en string en booleanos 
  
  std::vector<bool> vectorBool;
  
  for(unsigned i = 0; i < datos.size(); i++)
  {
      if(datos.at(i) == "verdad")
      {
        vectorBool.push_back(true);
      }
      
      if(datos.at(i) == "si")
      {
        vectorBool.push_back(true);
      }
      
      if(datos.at(i) == "true")
      {
        vectorBool.push_back(true);
      }
      
      if(datos.at(i) == "1")
      {
        vectorBool.push_back(true);
      }
      
      if(datos.at(i) == "falso")
      {
        vectorBool.push_back(false);
      }
      if(datos.at(i) == "no")
      {
        vectorBool.push_back(false);
      }
      
      if(datos.at(i) == "false")
      {
        vectorBool.push_back(false);
      }
      
      if(datos.at(i) == "0")
      {
        vectorBool.push_back(false);
      }
     

      
  } 
  
  std::cerr << "Vector bool" << std::endl;
  std::cerr << "-------------" << std::endl;
  for(unsigned i = 0; i < datos.size(); i++)
  {
    std::cerr << datos.at(i) << ": " << vectorBool.at(i) << std::endl;
  }
  
  
  unsigned inicialIndex = 0;
  unsigned finalIndex = 0; 
  
  if(argc == 3)
  {
    try
    {
      inicialIndex = (unsigned) std::stoul(argv[2]);
    }catch(std::invalid_argument& e2)
    {
      std::cerr << "Indice inicial inválido";
      return 4;
    }
    
    finalIndex = (vectorBool.size()-1);
  }
  else if(argc == 4)
  {
    try
    {
      inicialIndex = (unsigned) std::stoul(argv[2]);
      finalIndex = (unsigned) std::stoul(argv[3]);
    }catch(std::invalid_argument& e3)
    {
      std::cerr << "Indice inicial o final inválido";
      return 5;
    }
  }
  else 
  {
    inicialIndex = 0;
    finalIndex = (vectorBool.size()-1);
    //~ std::cerr << "tamaño: " << vectorBool.size() << std::endl;
  }
  
   
  std::cerr << "inicialIndex: " << inicialIndex << std::endl;
  std::cerr << "finalIndex: " << finalIndex << std::endl;
  
  unsigned resultado = funcion(vectorBool,inicialIndex,finalIndex);
  std::string cadenaBin = numeroBits(resultado);
  
  std::cout << resultado << " 0x" << std::hex << resultado << " 0b" <<
      cadenaBin << std::endl;
  
  return 0;
}
