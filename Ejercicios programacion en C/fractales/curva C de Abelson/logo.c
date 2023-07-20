#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logo.h"

int inicia(V x, int grados, char pluma, LOGO* tortuga)
{
  tortuga->a.i=x.i;
  tortuga->a.j=x.j;
  tortuga->pluma = pluma;
  tortuga->grados = grados;  
  return 0;
}
int asignaModoDibujarSegmento(void (*dibujaSegmento)(V x,V y), LOGO* tortuga)
{
	return (tortuga->dibujaSegmento = dibujaSegmento)!=NULL;
}
int der(int g, LOGO* tortuga)
{
	tortuga->grados = (((tortuga->grados-g)%360)+360)%360;  
  	return 0;
}
int izq(int g, LOGO* tortuga)
{
	return der(-g, tortuga);
}
int avanza(double l, LOGO* tortuga)
{
	V x={x.i=tortuga->a.i, x.j=tortuga->a.j};
	tortuga->a.i += l*cos(tortuga->grados*G2R);
  	tortuga->a.j += l*sin(tortuga->grados*G2R);
  	if (tortuga->pluma!=0)
    tortuga->dibujaSegmento(x, tortuga->a);
  return 0;
}
int retrocede(double l, LOGO* tortuga)
{
	return avanza(-l, tortuga);
}

