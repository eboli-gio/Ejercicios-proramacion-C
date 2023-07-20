#include <stdio.h>
#include <stdlib.h>
#include "poli_R.h"
int main()
    {
    	FILE *arch,*arch1;
		P t,q,r,res;
		arch=fopen("polinomios.txt","r");
		if((arch=fopen("polinomios.txt","r"))==NULL)
		{
			printf("Error");
			return 0;
		}
		arch1=fopen("resultados.txt","w");
		if((arch1=fopen("resultados.txt","w"))==NULL)
		{
			printf("error");
			return 0;
		}
		t=lee_P_A(arch);
		q=lee_P_A(arch);
		fprintf(arch1,"El polinomio es:");
		escribe_P_A(t,arch1);
		fprintf(arch1,"El polinomio es:");
		escribe_P_A(q,arch1);
		r=Suma_p(t,q);
		fprintf(arch1,"La suma de los polinomios es:");
		escribe_P_A(r,arch1);
		r=Resta_p(t,q);
		fprintf(arch1,"La resta de los polinomios es:");
		escribe_P_A(r,arch1);
		r=multiplica_p(t,q);
		fprintf(arch1,"La multiplicacion de los polinomios es:");
		escribe_P_A(r,arch1);
		r=divide_p(t,q,&res);
		fprintf(arch1,"La division de los polinomios es:");
		escribe_P_A(r,arch1);
		fprintf(arch1,"El residuo de la division de los polinomios es:");
		escribe_P_A(res,arch1);
		r=mcd_p(t,q,res);
		fprintf(arch1,"El maximo comun divisor de los polinomios es:");
		escribe_P_A(r,arch1);
		free(res.p);	
		free(t.p);
		free(q.p);
		free(r.p);
		fclose(arch);
		fclose(arch1);
		system("pause");
		return 0;	
	}
