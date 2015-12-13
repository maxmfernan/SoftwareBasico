#include "operacaoBits.h"

u4 inverteIntBits(u4 numero)
{
	u4 auxiliar = 0;
	u4 retorno = 0;
	
	auxiliar = numero&255;
	retorno = auxiliar << 24;

	auxiliar = (numero >> 8)&255;
	auxiliar = auxiliar << 16;
	retorno = retorno|auxiliar;
	
	auxiliar = (numero >> 16)&255;
	auxiliar = auxiliar << 8;
	retorno = retorno|auxiliar;
	
	auxiliar = (numero >> 24)&255;
	retorno = retorno|auxiliar;
	
	return retorno;
}

u2 inverteShortBits(u2 numero)
{
	u2 auxiliar = 0;
	u2 retorno = 0;
	
	auxiliar = numero&255;
	retorno = auxiliar << 8;

	auxiliar = (numero >> 8)&255;
	retorno = retorno|auxiliar;
	
	return retorno;
}

u8 inverteLongBits(u8 numero)
{
	u8  auxiliar = 0;
	u8  retorno = 0;
	
	auxiliar = numero&255;
	retorno = auxiliar << 56;

	auxiliar = (numero >> 8)&255;
	auxiliar = auxiliar << 48;
	retorno = retorno|auxiliar;
	
	auxiliar = (numero >> 16)&255;
	auxiliar = auxiliar << 40;
	retorno = retorno|auxiliar;
	
	auxiliar = (numero >> 24)&255;
	auxiliar = auxiliar << 32;
	retorno = retorno|auxiliar;
	
	auxiliar = (numero >> 32)&255;
	auxiliar = auxiliar << 24;
	retorno = retorno|auxiliar;
	
	auxiliar = (numero >> 40)&255;
	auxiliar = auxiliar << 16;
	retorno = retorno|auxiliar;
	
	auxiliar = (numero >> 48)&255;
	auxiliar = auxiliar << 8;
	retorno = retorno|auxiliar;
	
	auxiliar = (numero >> 56)&255;
	retorno = retorno|auxiliar;
	
	return retorno;
}
