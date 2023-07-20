	#include <stdio.h>
	#include <stdlib.h>
	#include "matriz_zp.h"

	int main()
	{
		FILE *archp,*arch,*arch1;
		int p,d;
		M a,b,c;
		archp=fopen("primos.txt","r");
		if((archp=fopen("primos.txt","r+"))==NULL)
		{
			printf("error al abrir y leer el archivo");
			return -1;
		}
		arch=fopen("matrices_zp.txt","r");
		if((arch=fopen("matrices_zp.txt","r"))==NULL)
		{
			printf("error al abrir y leer el archivo");
			return -1;
		}
		fscanf(arch,"%d",&p);
		p=comp_p(p,archp);
		if(p)
		{
			arch1=fopen("resultados.txt","w");
			a=lee_M_A(arch,p);
			b=lee_M_A(arch,p);
			if(a.f==b.f&&a.c==b.c)
			{
				fprintf(arch1,"La suma de las dos matrices es:\n");
				c=Suma_M(a,b,p);
				escribe_M_A(arch1,c);
			}
			else fprintf(arch1,"\nLa suma no es posible\n");
			if(a.c==b.f)
			{
				fprintf(arch1,"El producto de las dos matrices es:\n");
				c=Prod_M(a,b,p);
				escribe_M_A(arch1,c);	
			}
			else fprintf(arch1,"\nEl producto no es posible\n");				
			c=trans_M(a);
			fprintf(arch1,"La transpuesta de la matriz es:\n");
			escribe_M_A(arch1,c);
			if(a.c==a.f)
			{
				fprintf(arch1,"\nEl determinante de la matriz es:");
				d=Det_M(a,p);
				fprintf(arch1,"%d",d);
				fprintf(arch1,"\n");
				if(d!=0)
				{
					fprintf(arch1,"La inversa de la matriz es:\n");
					c=inv_M(a,p);
					escribe_M_A(arch1,c);
				}
			}
			else fprintf(arch1,"La matriz no tiene inversa\n");		
			lib_M(&a);
			lib_M(&b);
			lib_M(&c);			
			fclose(arch1);		
		}
		fclose(archp);
		fclose(arch);
		system("pause");
		return 0;
	}

