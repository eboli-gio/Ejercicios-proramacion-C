#include <stdio.h>
#include <stdlib.h>
#include "matrizc.h"
int main()
	 {
	 	M a,b,c;
		C d;
		FILE *arch,*arch1;
		arch=fopen("matrices_complejas.txt","r");
		arch1=fopen("resultados.txt","w");
		a=lee_M_A(arch);
		b=lee_M_A(arch);
		if(a.f==b.f&&a.c==b.c)
		{
			fprintf(arch1,"La suma de las dos matrices es:\n");
			c=Suma_M(a,b);
			escribe_M_A(arch1,c);
		}
		else fprintf(arch1,"\nLa suma no es posible\n");
		if(a.c==b.f)
		{
			fprintf(arch1,"El producto de las dos matrices es:\n");
			c=Prod_M(a,b);
			escribe_M_A(arch1,c);	
		}
		else fprintf(arch1,"\nEl producto no es posible\n");				
		c=trans_M(a);
		fprintf(arch1,"La transpuesta de la matriz es:\n");
		escribe_M_A(arch1,c);
		if(a.c==a.f)
		{
			fprintf(arch1,"\nEl determinante de la matriz es:");
			d=Det_M(a);
			escribeC_A(arch1,d);
			fprintf(arch1,"\n");
			if(!C_Cero(d))
				{
					fprintf(arch1,"La inversa de la matriz es:\n");
					c=inv_M(a);
					escribe_M_A(arch1,c);
					}
		}
		else fprintf(arch1,"La matriz no tiene inversa\n");		
		lib_M(&a);
		lib_M(&b);
		lib_M(&c);
		fclose(arch);
		fclose(arch1);		
	 	system("pause");
	 	return 0;
	 }
