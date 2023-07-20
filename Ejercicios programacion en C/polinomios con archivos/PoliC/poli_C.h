#ifndef _MI_POLIC_H_
#define _MI_POLIC_H_

#ifdef __cplusplus
extern "C" {
#endif
	#include <math.h>
	#include <stdio.h>
	typedef struct complejos
	 {
 		double re,im;	
	 }C;
	 C leeC(void);
	 int escribeC(C a);
	 int escribeC_A(C a,FILE *arch);
	 C SumC(C a,C b);
	 C DifC(C a,C b);
	 C MultiC(C a,C b);
	 C Multi_esc(C a,int b);
	 C Conj(C a);
	 C DivC(C a,C b);
	 C pot_k_C(C a,int k);
	 double NormaC(C a);
	 C CeroC(void);
	 int C_Cero(C a);	 
	 typedef struct polinomios
    {
     int gr;
     C *p; 
    }P;
	int crea_espacio(P *q);
    P lee_P(P q);
    P lee_P_A(FILE *arch);
    int escribe_(P q);
    int escribe_P_A(FILE *arch, P q);
    P Suma_p(P t, P q);
    P Resta_p(P t,P q);
    P multiplica_p(P t,P q);
    P mono_p(P t,C q,int g);
    int poli_cero(P t);
    P divide_p(P t,P q,P *res);
    P mcd_p(P t,P q,P res);
    C val_p(P t,C a);
#ifdef __cplusplus
}
#endif

#endif
