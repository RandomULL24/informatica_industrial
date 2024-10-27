#include<iostream>
#include<vector>
#include<fstream>
#include<string>

std::vector<int> contar_mayor(std::vector<int>& datos,int pivote)
{
  std::vector<int> num_mayor_pivote; 
  
  for(unsigned i = 0; i < datos.size(); i++)
  {
    if( (datos.at(i) > pivote) && (i%2 == 0))
    {
      num_mayor_pivote.push_back(datos.at(i));
    }
  }
  
  return num_mayor_pivote;
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
  int pivote = 5;
  
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
  
  
  std::vector<int> resultado = contar_mayor(datos,pivote);
  std::cout << "Pivote: " << pivote << std::endl;
  std::cout << "Resultado: ";
  
  for(unsigned i = 0; i < resultado.size(); i++)
  {
      std::cout << resultado.at(i) << ", ";
  } 
  

  return 0;
} 
