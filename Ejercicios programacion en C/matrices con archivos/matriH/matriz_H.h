#ifndef _MI_MATRIZH_H_
#define _MI_MATRIZH_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <math.h>
#include <stdio.h>
	typedef struct cuaternios
	{
		double re,i,j,k;
	}H;
	H leeH(void);
	int escribeH(H a);
	int escribeH_A(FILE *arch,H a);
	H SumaH(H a,H b);
	H ProdH(H a,H b);
	H invH(H a);
	H DivH(H a,H b);
	H Prod_escH(H a,double b);
	double NormH(H a);
	H ConjH(H a);
	int cero_H(H a);
	H P_esc_H(int a,H b);
	typedef struct matrices
	{
		H **m;
		int f,c;
	}M;
	int crea_espacio(M *a);
	M lee_M(M a);
	int escribe_M(M a);
	int escribe_M_A(FILE *arch,M a);
	M lee_M_A(FILE *arch);
	int lib_M(M *a);
	M Suma_M(M a,M b);
	M Prod_M(M a,M b);
	M mat_cero(M a);
	M trans_M(M a);
	M Cam_F(M a,int q,int p);
	M Prod_F(M a,int f,H k);	
	M Sum_CL(M a,int p,int q,H k);
	M M_trian(M a);
	H Det_M(M a);
	H Co_fac(M a,int p, int q);
	M inv_M(M a);
	M multi_MH(M a,H k); 
#ifdef __cplusplus
}
#endif

#endif
