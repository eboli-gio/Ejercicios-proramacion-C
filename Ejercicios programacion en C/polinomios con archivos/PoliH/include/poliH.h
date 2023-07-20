#ifndef _MI_POLIH_H_
#define _MI_POLIH_H_

#ifdef __cplusplus
extern "C" {
#endif
	#include <math.h>
	#define cuad(a) (a)*(a)	
	typedef struct cuaternios
	{
		double re,i,j,k;
	}H;	
	H leeH(void);
	int escribeH(H a);
	int escribeH_A(FILE *arch,H a);
	H SumaH(H a,H b);
	H DifH(H a,H b);
	H ProdH(H a,H b);
	H invH(H a);
	H DivH(H a,H b);
	H pot_k_H(H a,int k);
	double NormH(H a);
	H ConjH(H a);
	int cero_H(H a);
	H Prod_escH(double t,H a);
	H es_ceroH(void);
	//Funciones de operaciones de cuaterniones
	typedef struct polinomios
    {
     int gr;
     H *p; 
    }P;           
    int crea_espacio(P *q);
    P lee_P(P q);
    P lee_P_A(FILE *arch);
    int escribe_p(P q);
    int escribe_P_A(FILE *arch,P q);
    P Suma_p(P t, P q);
    P Resta_p(P t,P q);
    P multiplica_p(P t,P q);
    P mono_p(P t,H q,int g);
    int poli_cero(P t);
    P divide_p(P t,P q,P *res);
    P mcd_p(P t,P q,P res);
    H val_p(P t,H a);
#ifdef __cplusplus
}
#endif

#endif
