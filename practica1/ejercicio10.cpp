// Autor: Lucas Díaz Pérez
// Fecha: 8-7-2024
#include<iostream>
#include<vector>
#include<string>

unsigned funcion(const std::vector<bool>& vectorBool, unsigned indexInicial, unsigned indexFinal)
{
  // E) Puesta a 1 de un bit dejando los demás como están
  std::string string1;
  
  for(unsigned i = indexInicial; i <= indexFinal; i++)
  {
    
    if(vectorBool.at(i) == true)
    {
      std::cerr << "True" << std::endl;
      string1 = string1 + '1';
    }
    
    if(vectorBool.at(i) == false)
    {
      std::cerr << "False" << std::endl;
       string1 = string1 + '0';
    }
    std::cerr << i << std::endl;
  }
  
  std::cerr << string1 << std::endl;
  
  unsigned resultado = (unsigned)std::stoul(string1);
    
  return resultado;
}


//~ std::string numeroBits(unsigned valor)
//~ {
	//~ int totalBits = sizeof(valor)*8;
	//~ std::string versionString;
	//~ bool unoVisto = false;


	//~ for(int i = (totalBits - 1); i >= 0; i--){
		
		//~ int mascara = 1 << i;
		
		//~ if(valor & mascara)
		//~ {
			//~ versionString =  versionString + '1';
			//~ unoVisto = true;
		//~ }
		//~ else
		//~ {
			//~ if(unoVisto)
			//~ {
				//~ versionString = versionString + '0';
			//~ }
		//~ }
	//~ }
  
  //~ if(unoVisto == false)
  //~ {
    //~ versionString = '0';
  //~ }
	
	
	
	//~ return versionString;
//~ }

int main()
{
  std::vector<bool> v1 = {true,false,true,true};
  
  unsigned num = funcion(v1,0,3);
  std::cout << "El resultado es: " << num << std::endl;
  return 0;
}
