#include <stdio.h>
#include <stdlib.h>
#include"poliR.h"

int main()
	{
		FILE *arch1,*arch3;
		char nomArch[]={"matrices_reales.txt"},nomArchR[]={"resultados.txt"},nomArchC[]={"Copia_resultados.txt"};
		M a,b,c;
		arch1=fopen(nomArch,"r");
		if((arch1=fopen(nomArch,"r"))==NULL) return -1;
		a=lee_M_A(arch1);
		b=lee_M_A(arch1);
		arch3=fopen(nomArchC,"w");
		if((arch3=fopen(nomArchC,"w"))==NULL)
		{
			fclose(arch1);
			return -1;
		}
		c=trans_M(a);
		fprintf(arch3,"La traspuesta de la primera matriz es:\n");
		escribe_M_A(arch3, c);
		lib_M(&c);
		if(a.f==b.f&&a.c==b.c)
		{
			fprintf(arch3,"La suma de las matrices es:\n");
			c=Suma_M(a,b);
			escribe_M_A(arch3, c);
			lib_M(&c);		
		}
		if(a.c==b.f)
		{
			c=Prod_M(a,b);
			fprintf(arch3,"El producto de las matrices es:\n");
			escribe_M_A(arch3, c);
			lib_M(&c);
		}
		if(a.f==a.c&&Det_M(a)!=0)
		{
			c=inv_M(a);
			fprintf(arch3,"La inversa de primera matriz es :\n");
			escribe_M_A(arch3, c);
			lib_M(&c);
		}
		lib_M(&a);
		lib_M(&b);
		lib_M(&c);		
		fclose(arch1);
		fclose(arch3);
		return 0;
	}
