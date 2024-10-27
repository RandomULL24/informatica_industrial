#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<cstring>

int contar_mayor(std::vector<int>& datos,
    std::vector<int>& num_mayor_pivote, std::vector<int>& num_menor_pivote,
    int pivote)
{

  int cuenta_iguales = 0;
  
  for(unsigned i = 0; i < datos.size(); i++)
  {
    if(datos.at(i) > pivote)
    {
      num_mayor_pivote.push_back(datos.at(i));
    }
    
    if(datos.at(i) < pivote)
    {
      num_menor_pivote.push_back(datos.at(i));
    }
    
    if(datos.at(i) == pivote)
    {
      cuenta_iguales++;
    }
  }
  
  return cuenta_iguales;
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
  
  std::string nombreFich = argv[1];
  
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
  int pivote = 10; 
  
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
  
  std::vector<int> mayores;
  std::vector<int> menores;
  
  int num_iguales = contar_mayor(datos,mayores,menores,pivote);
  std::cout << "Pivote: " << pivote << std::endl;
  
  std::cout << "Mayores: " << std::endl;
   for(unsigned i = 0; i < mayores.size(); i++)
  {
      std::cout << mayores.at(i) << std::endl;
  } 
  
  std::cout << "Menores: " << std::endl;
   for(unsigned i = 0; i < menores.size(); i++)
  {
      std::cout << menores.at(i) << std::endl;
  } 
  
  std::cout << "Iguales: " << num_iguales << std::endl;
 

  
  return 0;
} 
