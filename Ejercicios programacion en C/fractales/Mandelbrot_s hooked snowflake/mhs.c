#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "logo.h"
#include "mhs.h"

int nivelRecursionMHS;
double longitudMHS;
double miX0MHS;
double miY0MHS;
LOGO *tortugaAuxMHS;

void MHSRrecursivo(double l,int n,LOGO *tortuga);
void MHSLrecursivo(double l,int n,LOGO *tortuga);

int inicia_mhs(int n, double l, double x, double y, LOGO *tortuga)
{
	nivelRecursionMHS=n;
  	longitudMHS=l;
  	miX0MHS=x;
  	miY0MHS=y;
  	tortugaAuxMHS=tortuga;  
  	return 0;
}
int dibuja_mhs(void)
{
	inicia(miX0MHS, miY0MHS, 0, ABAJO, tortugaAuxMHS);
	MHSRrecursivo(longitudMHS,nivelRecursionMHS,tortugaAuxMHS);
	return 0; 
}

void MHSRrecursivo(double l,int n,LOGO *tortuga)
{
	double u,su;
	if(n<=0)
	{
		avanza(l,tortuga);
		return;
	}
	u=l/3;
	su=(l*2*sin(60*G2R))/9;
	izq(60,tortuga);
	MHSLrecursivo(u,n-1,tortuga);
	MHSRrecursivo(u,n-1,tortuga);
	der(60,tortuga);
	MHSRrecursivo(u,n-1,tortuga);
	der(60,tortuga);
	MHSRrecursivo(u,n-1,tortuga);
	der(150,tortuga);
	MHSRrecursivo(su,n-1,tortuga);
	MHSLrecursivo(su,n-1,tortuga);
	izq(60,tortuga);
	MHSLrecursivo(su,n-1,tortuga);
	izq(60,tortuga);
	MHSLrecursivo(su,n-1,tortuga);
	MHSRrecursivo(su,n-1,tortuga);
	izq(90,tortuga);
	MHSLrecursivo(u,n-1,tortuga);
	MHSRrecursivo(u,n-1,tortuga);
	return;
}
void MHSLrecursivo(double l,int n,LOGO *tortuga)
{
	double u,su;
	if(n<=0)
	{
		avanza(l,tortuga);
		return;
	}
	u=l/3;
	su=(l*2*sin(60*G2R))/9;
	MHSLrecursivo(u,n-1,tortuga);
	MHSRrecursivo(u,n-1,tortuga);
	der(90,tortuga);
	MHSLrecursivo(su,n-1,tortuga);
	MHSRrecursivo(su,n-1,tortuga);
	der(60,tortuga);
	MHSRrecursivo(su,n-1,tortuga);
	der(60,tortuga);
	MHSRrecursivo(su,n-1,tortuga);
	MHSLrecursivo(su,n-1,tortuga);
	izq(150,tortuga);
	MHSLrecursivo(u,n-1,tortuga);
	izq(60,tortuga);
	MHSLrecursivo(u,n-1,tortuga);
	izq(60,tortuga);
	MHSLrecursivo(u,n-1,tortuga);
	MHSRrecursivo(u,n-1,tortuga);
	der(60,tortuga);
	return;
}
