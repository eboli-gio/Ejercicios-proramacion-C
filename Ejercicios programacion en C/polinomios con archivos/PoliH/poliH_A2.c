#include <stdio.h>
#include <stdlib.h>
#include "poliH.h"

	int main()
    {
    	FILE *arch, *arch1;
		P q,t,r,res;
		H val,p_val;
		arch=fopen("poliH.txt","r");
		if((arch=fopen("poliH.txt","r"))==NULL)
		{
			printf("Error");
			return 0;
		}
		arch1=fopen("resultados_H.txt","w");
		if((arch1=fopen("resultados_H.txt","w"))==NULL)
		{
			printf("error");
			return 0;
		}
		t=lee_P_A(arch);
		q=lee_P_A(arch);
		fprintf(arch1,"El polinomio es:");
		escribe_P_A(arch1,t);
		fprintf(arch1,"\nEl polinomio es:");
		escribe_P_A(arch1,q);
		r=Suma_p(q,t);
		fprintf(arch1,"\nLa suma de los polinomios es:");
		escribe_P_A(arch1,r);
		r=Resta_p(q,t);
		fprintf(arch1,"\nLa resta de los polinomios es:");
		escribe_P_A(arch1,r);
		r=multiplica_p(q,t);
		fprintf(arch1,"\nLa multiplicacion de los polinomios es:");
		escribe_P_A(arch1,r);
		free(r.p);
		r=divide_p(t,q,&res);
		fprintf(arch1,"\nEl cociente de la division de los polinomios es:");
		escribe_P_A(arch1,r);
		fprintf(arch1,"\nEl residuo de la division de los polinomios es:");
		escribe_P_A(arch1,res);
		//r=mcd_p(t,q,res);
		fprintf(arch1,"\nEl MCD de los polinomios es:");
		escribe_P_A(arch1,r);
		fscanf(arch,"%lg%*c%lg%*c%lg%*c%lg",&val.re,&val.i,&val.j,&val.k);
		p_val=val_p(t,val);
		fprintf(arch1,"\nEl primer polinomio valuado en (%lg%+lgi%+lgj%+lgk) es:%lg%+lgi%+lgj%+lgk",val.re,val.i,val.j,val.k,p_val.re,p_val.i,p_val.j,p_val.k);
		fprintf(arch1,"\n");
		free(t.p);
		free(q.p);
		free(r.p);
		free(res.p);
		fclose(arch);
		fclose(arch1);
		system("pause");
		return 0;
	}

