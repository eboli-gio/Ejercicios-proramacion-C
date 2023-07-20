#include <stdio.h>
#include <stdlib.h>

#include "logo.h"
#include "hilbert.h"

int nivelRecursionHil;
double longitudHil;
double miX0Hil;
double miY0Hil;
LOGO *tortugaAuxHil;
int p=1;

int HilRecursivo(int n, double l, LOGO *tortuga,int paridad);

int iniciaHil(int n, double l, double x, double y, LOGO *tortuga)
{
  nivelRecursionHil=n;
  longitudHil=l;
  miX0Hil=x;
  miY0Hil=y;
  tortugaAuxHil=tortuga;  
  return 0;
}

int dibujaHil(void){
  inicia(miX0Hil, miY0Hil, 0, ABAJO, tortugaAuxHil);

  return HilRecursivo(nivelRecursionHil, longitudHil, tortugaAuxHil,p);
}

int HilRecursivo(int n, double l, LOGO *tortuga,int paridad)
{
	if(n<=0) return 0;
	izq(paridad*90,tortuga);
	HilRecursivo(n-1,l,tortuga,-paridad);
	avanza(l,tortuga);
	der(paridad*90,tortuga);
	HilRecursivo(n-1,l,tortuga,paridad);
	avanza(l,tortuga);
	HilRecursivo(n-1,l,tortuga,paridad);
	der(paridad*90,tortuga);
	avanza(l,tortuga);
	HilRecursivo(n-1,l,tortuga,-paridad);
	izq(paridad*90,tortuga);
	return 0;
}
