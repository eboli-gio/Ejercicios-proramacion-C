#include <stdio.h>
#include <stdlib.h>

#include "logo.h"
#include "weave.h"

int nivelRecursionWea;
double longitudWea;
double miX0Wea;
double miY0Wea;
LOGO *tortugaAuxWea;
int p=-1;
int maze(int n, double l, LOGO *tortuga);
void interior(double l,LOGO *tortuga);
int iniciaWea(int n, double l, double x, double y, LOGO *tortuga)
{
  nivelRecursionWea=n;
  longitudWea=l;
  miX0Wea=x;
  miY0Wea=y;
  tortugaAuxWea=tortuga;  
  return 0;
}
int dibujaWea(void)
{
  inicia(miX0Wea, miY0Wea, 0, ABAJO, tortugaAuxWea);
  return maze(nivelRecursionWea, longitudWea, tortugaAuxWea);
}
int maze(int n, double l, LOGO *tortuga)
{
	double u;
	int i;
	if(n<=0)
	{
		interior(l,tortuga);
		return 0;
	}
	u=l/3;
	maze(n-1,u,tortuga);
	izq(90,tortuga);
	maze(n-1,u,tortuga);
	for(i=0;i<3;i++)
	{
		der(90,tortuga);
		maze(n-1,u,tortuga);
	}
	for(i=0;i<3;i++)
	{
		izq(90,tortuga);
		maze(n-1,u,tortuga);
	}
	der(90,tortuga);
	maze(n-1,u,tortuga);
	return 0;
}
void interior(double l,LOGO *tortuga)
{
	double u=l/5;
	p=-p;
	avanza(4*u,tortuga);
	der(90*p,tortuga);
	avanza(3*u,tortuga);
	der(90*p,tortuga);
	avanza(2*u,tortuga);
	der(90*p,tortuga);
	avanza(u,tortuga);
	der(90*p,tortuga);
	avanza(u,tortuga);
	izq(90*p,tortuga);
	avanza(u,tortuga);
	izq(90*p,tortuga);
	avanza(2*u,tortuga);
	izq(90*p,tortuga);
	avanza(3*u,tortuga);
	izq(90*p,tortuga);
	avanza(4*u,tortuga);
	izq(90*p,tortuga);
	avanza(4*u,tortuga);
	der(90*p,tortuga);
	return;
}
