#ifndef _MI_POLIR_H_
#define _MI_POLIR_H_

#ifdef __cplusplus
extern "C" {
#endif

	#include <math.h>
	#include <stdio.h>
	typedef struct polinomios
    {
     int gr;
     double *p; 
    }P;       
    
    int crea_espacio(P *q);
    P lee_P(P q);
    P lee_P_A(FILE *arch);
    int escribe_(P q);
    int escribe_P_A(P q,FILE *arch);
    P Suma_p(P t, P q);
    P Resta_p(P t,P q);
    P multiplica_p(P t,P q);
    P mono_p(P t,double q,int g);
    int poli_cero(P t);
    P divide_p(P t,P q,P *res);
    P mcd_p(P t,P q,P res);
#ifdef __cplusplus
}
#endif

#endif
