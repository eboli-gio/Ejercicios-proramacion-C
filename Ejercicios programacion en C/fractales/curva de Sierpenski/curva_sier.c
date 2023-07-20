#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "logo.h"
#include "curva_sier.h"

int nivelRecursionCsier;
double longitudCsier;
double miX0Csier;
double miY0Csier;
LOGO *tortugaAuxCsier;
double L;
void CsierRecursivo(int n, double l, LOGO *tortuga,double L);

int iniciaCsier(int n, double l, double x, double y, LOGO *tortuga)
{
  nivelRecursionCsier=n;
  longitudCsier=l/sqrt(2);
  L=l;
  miX0Csier=x;
  miY0Csier=y;
  tortugaAuxCsier=tortuga;  
  return 0;
}
int dibujaCsier(void){
  int i;
  inicia(miX0Csier, miY0Csier, 0, ABAJO, tortugaAuxCsier);
  	for(i=0;i<4;i++)
  	{
  		CsierRecursivo(nivelRecursionCsier, longitudCsier, tortugaAuxCsier,L);
  		der(45,tortugaAuxCsier);
        avanza(longitudCsier,tortugaAuxCsier);
        der(45,tortugaAuxCsier);
	}
    
   return 0;
}

void CsierRecursivo(int n, double l, LOGO *tortuga,double L)
{
	if(n<=0) return;
	CsierRecursivo(n-1,l,tortuga,L);
	der(45,tortuga);
	avanza(l,tortuga);
	der(45,tortuga);
	CsierRecursivo(n-1,l,tortuga,L);
	izq(90,tortuga);
	avanza(L,tortuga);
	izq(90,tortuga);
	CsierRecursivo(n-1,l,tortuga,L);
	der(45,tortuga);
	avanza(l,tortuga);
	der(45,tortuga);
	CsierRecursivo(n-1,l,tortuga,L);
	return;
}
