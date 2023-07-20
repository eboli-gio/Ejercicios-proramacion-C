#include <stdio.h>
#include <stdlib.h>

#include "logo.h"
#include "A_trian.h"

int nivelRecursionAtrian;
double longitudAtrian;
double miX0Atrian;
double miY0Atrian;
LOGO *tortugaAuxAtrian;

int nes_trian(int n, double l, LOGO *tortuga);

int iniciaAtrian(int n, double l, double x, double y, LOGO *tortuga)
{
  nivelRecursionAtrian=n;
  longitudAtrian=l;
  miX0Atrian=x;
  miY0Atrian=y;
  tortugaAuxAtrian=tortuga;  
  return 0;
}
int dibujaAtrian(void)
{
	inicia(miX0Atrian, miY0Atrian, 0, ABAJO, tortugaAuxAtrian);
  return nes_trian(nivelRecursionAtrian, longitudAtrian, tortugaAuxAtrian);
}

int nes_trian(int n, double l, LOGO *tortuga)
{
	int i;
	if(n<=0) return 0;
	for(i=0;i<3;i++)
	{
		nes_trian(n-1,l/2,tortuga);
		avanza(l,tortuga);
		der(120,tortuga);
	}
	return 0;
}
