#include <stdio.h>
#include <stdlib.h>

#include "logo.h"
#include "dragon.h"

int nivelRecursion_dragon;
double longitud_dragon;
double miX0_dragon;
double miY0_dragon;
LOGO *tortugaAux_dragon;

int dragon_L(int n, double l, LOGO *tortuga);
int dragon_R(int n,double l, LOGO *tortuga);

int inicia_dragon(int n, double l, double x, double y, LOGO *tortuga)
{
  nivelRecursion_dragon=n;
  longitud_dragon=l;
  miX0_dragon=x;
  miY0_dragon=y;
  tortugaAux_dragon=tortuga;  
  return 0;
}
int dibuja_dragon(void)
{
	inicia(miX0_dragon, miY0_dragon, 0, ABAJO, tortugaAux_dragon);
  return dragon_L(nivelRecursion_dragon, longitud_dragon, tortugaAux_dragon);
}

int dragon_L(int n, double l, LOGO *tortuga)
{
	if(n==0)
	{
		avanza(l,tortuga);
		return 0;
	}
	dragon_L(n-1,l,tortuga);
	izq(90,tortuga);
	dragon_R(n-1,l,tortuga);
	return 0;
}
int dragon_R(int n,double l, LOGO *tortuga)
{
	if(n==0)
	{
		avanza(l,tortuga);
		return 0;
	}
	dragon_L(n-1,l,tortuga);
	der(90,tortuga);
	dragon_R(n-1,l,tortuga);
	return 0;
}
