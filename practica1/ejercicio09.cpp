// Autor: Lucas Díaz Pérez
// Fecha: 8-7-2024
#include <iostream>
#include <string>

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
    
		
		std::cout << numeroBits(entero) << " 0x" << std::hex << entero  
				<< std::endl;
	
	}
	while(entero != 0);
	
	return 0;
}
