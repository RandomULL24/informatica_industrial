// Autor: Lucas Díaz Pérez
// Fecha: 8-7-2024
#include<iostream>

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
	int entero;
	
	do
	{
		//~ std::cout << "Introduce el entero: ";
		std::cin >> entero;
		std::cout << numeroBits(entero) << " 0x" << std::hex << entero  
				<< std::endl;
	
	}
	while(entero != 0);

	//~ std::cerr << "Se ha salido del programa" << std::endl;
			
	
	
	return 0;
}
