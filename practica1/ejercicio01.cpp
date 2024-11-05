// Autor: Lucas Díaz Pérez
// Fecha: 1-7-2024
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int contar_mayor(std::vector<int>& datos,int pivote)
{
  int cuenta = 0;
  

  for(unsigned i = 0; i < datos.size(); i++)
  {
    if(datos.at(i) > pivote)
    {
      cuenta++;
    }
  }
  
  return cuenta;
}

int main(int argc, char* argv[])
{
  
  std::cerr << "El programa recibe " << argc << " argumentos" << std::endl;
   
  for(int i = 0; i<argc; i++) 
  {
    std::cerr << "Argumento " << i << " → '" << argv[i] << "'" << std::endl;
  }
  
  if(argc < 2)
  {
    std::cout << "Es necesario indicar el fichero de datos" << std::endl;
    return 1; //situación erronea
  }
  
  char* nombreFich = argv[1];
  std::cerr << "Vamos a tratar de abrir el fichero '" << nombreFich << "'"
      << std::endl;
      
  std::ifstream fichEntrada(nombreFich);
  
  if(fichEntrada.fail())
  {
   std::cerr << "No se pudo abrir el fichero" << std::endl;
    return 2;
  }
  
  int valorLeido;
  
  fichEntrada >> valorLeido;
  
  std::vector<int> datos;
  
  while(fichEntrada.good()) 
  {
    std::cerr << "Valor leído " << valorLeido << std::endl;
    datos.push_back(valorLeido);
    fichEntrada >> valorLeido;
  }

  //Valor por defecto
  int pivote = 11;
  
  //Si hay un 2º argumento, este pasa a ser el valor del pivote.
  try 
  {
    if(argc > 2)
      {
        pivote = std::stoi(argv[2]); 
        
      }
  }
  catch(std::invalid_argument& e)
  {
    std::cerr << "Argumento inválido del pivote" << std::endl;
    return 3;
  }
  // ver si está disponible el argv[2] y leer como entero y asignar al pivote
  
  
  int resultado = contar_mayor(datos,pivote);
  std::cout << "Pivote: " << pivote << std::endl;
  std::cout << "Resultado: " << resultado << std::endl; 
  
  return 0;
} 
