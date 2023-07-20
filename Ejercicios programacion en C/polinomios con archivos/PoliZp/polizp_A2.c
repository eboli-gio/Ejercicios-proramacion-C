	#include <stdio.h>
	#include <stdlib.h>
	#include "polizp.h"
	int main()
	{
		FILE *archp,*arch,*arch1;
		int p;
		P a,b,c,res;
		int val,p_val;
		archp=fopen("primos.txt","r");
		if((archp=fopen("primos.txt","r"))==NULL)
		{
			printf("error al abrir y leer el archivo");
			return -1;
		}
		arch=fopen("polizp.txt","r");
		fscanf(arch,"%d",&p);
		p=comp_p(p,archp);
		if(p)
		{
			arch1=fopen("resultados_zp.txt","w");
			if((arch1=fopen("resultados_zp.txt","w"))==NULL)
			{
				printf("error");
				return -1;
			 } 
			a=Lee_P_Zp_A(arch,p);
			b=Lee_P_Zp_A(arch,p);
			fprintf(arch1,"El polinomio es:");
			escribe_P_A(a,arch1);
			fprintf(arch1,"El polinomio es:");
			escribe_P_A(b,arch1);
			c=Suma_P_Zp(a,b,p);
			fprintf(arch1,"La suma de los polinomios es:");
			escribe_P_A(c,arch1);
			c=Resta_p(a,b,p);
			fprintf(arch1,"La resta de los polinomios es:");
			escribe_P_A(c,arch1);
			c=multiplica_p(a,b,p);
			fprintf(arch1,"La multiplicacion de los polinomios es:");
			escribe_P_A(c,arch1);
			fprintf(arch1,"El cociente de la division es: ");
			c=divide_p(a,b,&res,p);
			escribe_P_A(c,arch1);
			fprintf(arch1,"El residuo de la division es: ");
     		escribe_P_A(res,arch1);
			c=mcd_p(a,b,&res,p);
     		fprintf(arch1,"\nEl mcd es: ");
     		escribe_P_A(c,arch1);
     		fscanf(arch,"%d",&val);
     		val=crea_zp(val,p);
			p_val=val_p(a,val,p);
			fprintf(arch1,"\nEl primer polinomio valuado en %d es:%d",val,p_val);
			fprintf(arch1,"\n");
		}
		free(a.p);
		free(b.p);
		free(c.p);
		free(res.p);
		fclose(archp);
		fclose(arch);
		fclose(arch1);	
		printf("\nFIN DEL PROGRAMA\n");
		system("pause");
		return 0;	
	}

