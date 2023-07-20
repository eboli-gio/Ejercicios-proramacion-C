#ifndef _MI_POLI_ZP_H_
#define _MI_POLI_ZP_H_

#ifdef __cplusplus
extern "C" {
#endif
	#include <math.h>
	#include<stdio.h>
	int comp_p(int n,FILE *arch);
	int crea_zp(int a,int w);
	int suma_zp(int a,int b,int w);
	int resta_zp(int a,int b,int w);
	int multi_zp(int a,int b,int w);
	int divide_zp(int a,int b,int w);
	int pot_k_zp(int a,int k,int w);
	int inv_zp(int a,int w);
	
	typedef struct Polinomios
	{
		int gr,*p;		
	}P;
	int crea_espacio_Zp(P *a);
	P Lee_P_Zp(P a,int w);
	P Lee_P_Zp_A(FILE *arch,int w);
	int escribe_P(P q);
	int escribe_P_A(P q,FILE *arch);
	P Suma_P_Zp(P t,P q,int w);
	P Resta_p(P t,P q,int w);
	P multiplica_p(P t,P q,int w);
	P mono_p(P t,int q,int g,int w);
	int poli_cero(P t);
	P divide_p(P t,P q,P *res,int w);
	P mcd_p(P t,P q,P *res,int w);
	int val_p(P t,int a,int w);
#ifdef __cplusplus
}
#endif

#endif
