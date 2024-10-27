// Autor: Lucas Díaz Pérez
// Fecha: 8-7-2024
#include<iostream>

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
	
	do
	{
		//~ std::cout << "Introduce el entero: ";
		std::cin >> entero;
		std::cout << std::dec << numero_bits_uno(entero) << " 0x" << std::hex << entero  
				<< std::endl;
	
	}
	while(entero != 0);

	//~ std::cerr << "Se ha salido del programa" << std::endl;
			
	
	
	return 0;
}
