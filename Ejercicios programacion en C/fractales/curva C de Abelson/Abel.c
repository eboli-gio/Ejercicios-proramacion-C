#include <stdio.h>
#include <stdlib.h>

#include "logo.h"
#include "abel_c.h"

int nivelRecursionAbelc;
double longitudAbelc;
double miX0Abelc;
double miY0Abelc;
LOGO *tortugaAuxAbelc;

int AbelcRecursivo(int n, double l, LOGO *tortuga);

int iniciaAbelc(int n, double l, double x, double y, LOGO *tortuga)
{
	nivelRecursionAbelc=n;
  	longitudAbelc=l;
  	miX0Abelc=x;
  	miY0Abelc=y;
  	tortugaAuxAbelc=tortuga;  
  	return 0;
}

int dibujaAbelc(void)
{
	inicia(miX0Abelc, miY0Abelc, 0, ABAJO, tortugaAuxAbelc);
  return AbelcRecursivo(nivelRecursionAbelc, longitudAbelc, tortugaAuxAbelc);
}

int AbelcRecursivo(int n, double l, LOGO *tortuga)
{
	if(n<=0)
	{
		avanza(l,tortuga);
		return 0;
	}
	AbelcRecursivo(n-1,l,tortuga);
	der(90,tortuga);
	AbelcRecursivo(n-1,l,tortuga);
	izq(90,tortuga);
	return 0;
}
