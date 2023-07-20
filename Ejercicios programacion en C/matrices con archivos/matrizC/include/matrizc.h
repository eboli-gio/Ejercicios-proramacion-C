#ifndef _MI_MATRIZC_H_
#define _MI_MATRIZC_H_

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
	 int escribeC_A(FILE *arch,C a);
	 C SumC(C a,C b);
	 C DifC(C a,C b);
	 C MultiC(C a,C b);
	 C Multi_esc(C a,int b);
	 C Conj(C a);
	 C DivC(C a,C b);
	 double NormaC(C a);
	 C CeroC(void);
	 int C_Cero(C a);
	 //Declaracion de funciones de complejos
	 typedef struct matriz
	 {
	 	int f,c;
	 	C **m;
	 }M;
	 int crea_espacio(M *a);
	 M lee_M(M a);
	 int escribe_M(M a);
	 int lib_M(M *a);
	 int escribe_M_A(FILE *arch,M a);
	 M lee_M_A(FILE *arch);
	 M trans_M(M a);
	 M Suma_M(M a,M b);
	 M Prod_M(M a,M b);
	 M Cam_F(M a,int q,int p); 
	 M Prod_F(M a,int f,C k);
	 M Sum_CL(M a,int f,int p,C k);
	 M M_trian(M a);
	 C Det_M(M a);
	 C Co_fac(M a,int p, int q);
	 M inv_M(M a);
#ifdef __cplusplus
}
#endif

#endif
