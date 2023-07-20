#ifndef _MI_POLIQ_H_
#define _MI_POLIQ_H_

#ifdef __cplusplus
extern "C" {
#endif
	#include <math.h>
	#include <stdio.h>
	typedef struct racionales{
	int p,q;	
	}Q;
	
	int mcd(int a,int b);
	Q simplificaQ(Q a);
	Q leeQ(void);
	int escribeQ(Q a);
	int escribeQ_A(Q a,FILE *arch);
	Q SumaQ(Q a,Q b);
	Q RestaQ(Q a,Q b);
	Q MultiQ(Q a,Q b);
	Q Multi_esc(Q a,double b);
	Q DivQ(Q a,Q b);
	Q pot_k_Q(Q a,int k);
	Q CeroQ(void);
	int C_CeroQ(Q a);
	//Funciones de operaciones con racionales
	 typedef struct polinomios
    {
     int gr;
     Q *p; 
    }P;
	int crea_espacio(P *q);
    P lee_P(P q);
    P lee_P_A(FILE *arch);
    int escribe_p(P q);
    int escribe_P_A(FILE *arch, P q);
    P Suma_p(P t, P q);
    P Resta_p(P t,P q);
    P multiplica_p(P t,P q);
    P mono_p(P t,Q q,int g);
    int poli_cero(P t);
    P divide_p(P t,P q,P *res);
    P mcd_p(P t,P q,P res);
    Q val_p(P t,Q a);
#ifdef __cplusplus
}
#endif

#endif
