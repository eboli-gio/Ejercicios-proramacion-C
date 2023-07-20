#ifndef _MI_POLIR_H_
#define _MI_POLIR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <math.h>
typedef struct
	{
		int f,c;
		double **m;
	}M;
	int crea_espacio(M *a);
	M lee_M(M a);
	int lib_M(M *a);
	M trans_M(M a);
	M Suma_M(M a,M b);
	M Prod_M(M a,M b);
	M Cam_F(M a,int q,int p); 
	M Prod_F(M a,int f,double k);
	M Sum_CL(M a,int f,int p,double k);
	M M_trian(M a);
	double Det_M(M a);
	double Co_fac(M a,int p, int q);
	M inv_M(M a);
	//Funciones para matrices en los reales
	//Funciones para manejo de archivos
	int escribe_M_A(FILE *arch,M a);
	M lee_M_A(FILE *arch);
#ifdef __cplusplus
}
#endif

#endif
