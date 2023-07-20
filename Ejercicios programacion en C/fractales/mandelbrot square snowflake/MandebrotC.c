#include <stdio.h>
#include <stdlib.h>

#include "logo.h"
#include "MandelbrotC.h"

int nivelRecursionM_Cuad;
double longitudM_Cuad;
double miX0M_Cuad;
double miY0M_Cuad;
LOGO *tortugaAuxM_Cuad;
int i;

int M_CuadRecursivo(int n, double l, LOGO *tortuga);

int iniciaM_Cuad(int n, double l, double x, double y, LOGO *tortuga)
{
	nivelRecursionM_Cuad=n;
  	longitudM_Cuad=l;
  	miX0M_Cuad=x;
  	miY0M_Cuad=y;
  	tortugaAuxM_Cuad=tortuga;  
  	return 0;
}
int dibujaM_Cuad(void)
{
	inicia(miX0M_Cuad, miY0M_Cuad, 0, ABAJO, tortugaAuxM_Cuad);
	for(i=0;i<4;i++)
	{
		 M_CuadRecursivo(nivelRecursionM_Cuad, longitudM_Cuad, tortugaAuxM_Cuad);
		 der(90.0,tortugaAuxM_Cuad);
	}
	return 0;
}
int M_CuadRecursivo(int n, double l, LOGO *tortuga)
{
	double u;
	if(n<=0)
	{
		avanza(l,tortuga);
		return 0;
	}
	u=l/4;
	M_CuadRecursivo(n-1,u,tortuga);
	izq(90,tortuga);
	M_CuadRecursivo(n-1,u,tortuga);
	der(90,tortuga);
	M_CuadRecursivo(n-1,u,tortuga);
	der(90,tortuga);
	M_CuadRecursivo(n-1,u,tortuga);
	M_CuadRecursivo(n-1,u,tortuga);
	izq(90,tortuga);
	M_CuadRecursivo(n-1,u,tortuga);
	izq(90,tortuga);
	M_CuadRecursivo(n-1,u,tortuga);
	der(90,tortuga);
	M_CuadRecursivo(n-1,u,tortuga);
	return 0;
}
