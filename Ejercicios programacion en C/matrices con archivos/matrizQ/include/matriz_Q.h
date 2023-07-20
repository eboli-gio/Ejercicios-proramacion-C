#ifndef _MI_MATRIZQ_H_
#define _MI_MATRIZQ_H_

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
	int escribeQ_A(FILE *arch,Q a);
	Q SumaQ(Q a,Q b);
	Q RestaQ(Q a,Q b);
	Q MultiQ(Q a,Q b);
	Q Multi_esc(Q a,double b);
	Q DivQ(Q a,Q b);
	Q CeroQ(void);
	int C_CeroQ(Q a);
	 //programas para operaciones de racionales
	typedef struct matrices
	{
		int f,c;
		Q **m;	
	}M; 	
	int crea_espacio(M *a);
	M lee_M(M a);
	M lee_M_A(FILE *arch);
	int escribe_M(M a);
	int escribe_M_A(FILE *arch,M a);
	int lib_M(M *a);
	M trans_M(M a);
	M Suma_M(M a,M b);
	M Prod_M(M a,M b);
	M Cam_F(M a,int q,int p); 
	M Prod_F(M a,int f,Q k);
	M Sum_CL(M a,int f,int p,Q k);
	M M_trian(M a);
	Q Det_M(M a);
	Q Co_fac(M a,int p, int q);
	M inv_M(M a);
#ifdef __cplusplus
}
#endif

#endif
