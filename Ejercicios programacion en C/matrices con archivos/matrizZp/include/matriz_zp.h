#ifndef _MI_MATRIZ_ZP_H_
#define _MI_MATRIZ_ZP_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <math.h>
#include <stdio.h>
	int comp_p(int n,FILE *arch);
	int crea_zp(int a,int p);
	int suma_zp(int a,int b,int p);
	int resta_zp(int a,int b,int p);
	int multi_zp(int a,int b,int p);
	int divide_zp(int a,int b,int p);
	int inv_zp(int a,int p);
	//funciones de matrices
	typedef struct matrices{
		int **m;
		int f,c;
	}M;
	int crea_espacio(M *a,int p);
	M lee_M(M a,int p);
	M lee_M_A(FILE *arch,int p);
	int escribe_M(M a);
	int escribe_M_A(FILE *arch,M a);
	int lib_M(M *a);
	M trans_M(M a);
	M Suma_M(M a,M b,int p);
	M Prod_M(M a,M b,int p);
	M Cam_F(M a,int q,int p); 
	M Prod_F(M a,int f,int k,int p);
	M Sum_CL(M a,int f,int p,int k,int p_1);
	M M_trian(M a,int p);
	int Det_M(M a, int p);
	int Co_fac(M a,int p, int q,int p_1);
	M inv_M(M a,int p);
#ifdef __cplusplus
}
#endif

#endif
