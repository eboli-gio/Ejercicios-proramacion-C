#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "logo.h"
#include "AbelP.h"

double longitudAbelP;
double miX0AbelP;
double miY0AbelP;
LOGO *tortugaAuxAbelP;
double anguloAbelP,limite;

int AbelPRecursivo(double l,double a,int totalrun, LOGO *tortuga);
int AbelPAuxRecursivo(double l,double a,LOGO *tortuga);
int iniciaAbelP(double L,double l,double a, double x, double y, LOGO *tortuga)
{
  limite=L;
  longitudAbelP=l;
  anguloAbelP=a;
  miX0AbelP=x;
  miY0AbelP=y;
  tortugaAuxAbelP=tortuga;  
  return 0;
}
int dibujaAbelP(void)
{
	inicia(miX0AbelP, miY0AbelP, 0, ABAJO, tortugaAuxAbelP);
	return AbelPRecursivo(longitudAbelP,anguloAbelP,0,tortugaAuxAbelP);
}

int AbelPRecursivo(double l,double a,int totalrun, LOGO *tortuga)
{
	int res;
	if(l<=limite) return 0;
	AbelPAuxRecursivo(l,a,tortuga);
	totalrun+=a;
	if(!((res=totalrun%360)==0)) AbelPRecursivo(l,a,totalrun,tortuga);
	return 0;
}
int AbelPAuxRecursivo(double l,double a,LOGO *tortuga)
{
	avanza(l,tortuga);
	AbelPRecursivo(l/2,-a,0,tortuga);
	der(a,tortuga);
	return 0;
}

