
	#include<stdio.h>
	#include<stdlib.h>
	#include<math.h>	
	#define cuad(a) (a)*(a)
	typedef struct cuaternios
	{
		double re,i,j,k;
	}H;
	H leeH(void);
	int escribeH(H a);
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
	int main()
	{
		M A,B,C;
		H D;
		int sel;
		printf("Bienvenido usuario el siguiente programa va realizar\nlas siguientes operaciones en la lista:\n1)La suma de dos matrices A y B\n2)El producto de dos matrices A y B\n3)La traspuesta de una matriz\n4)Obtener el determinante e inversa de una matriz\n");
		scanf("%d",&sel);
		switch(sel)
		{
			case 1:
			crea_espacio(&A);
			A=lee_M(A);	
			escribe_M(A);
			crea_espacio(&B);
			B=lee_M(B);	
			escribe_M(B);
			if(A.f==B.f&&A.c==B.c)
			{
				 C=Suma_M(A,B);
				 printf("\nLa suma de las matrices es:\n");
				 escribe_M(C);
			}
			else printf("\nLas matrices tecleadas no se pueden sumar");	
			lib_M(&A);
			lib_M(&B);
			lib_M(&C);
			break;
			case 2:
				crea_espacio(&A);
				A=lee_M(A);	
				escribe_M(A);
				crea_espacio(&B);
				B=lee_M(B);	
				escribe_M(B);
				if(A.c==B.f)
				{
					printf("\nEl producto de la matrices es:\n");
					C=Prod_M(A,B);
					escribe_M(C);
				}
				else printf("\nLas matrices ingresadas no se pueden multiplicar\n");
				lib_M(&A);
				lib_M(&B);
				lib_M(&C);
				break;
			case 3:
                crea_espacio(&A);
				A=lee_M(A);	
				escribe_M(A);
                B=trans_M(A);
                printf("\nLa transpuesta de la matriz A es:\n");
                escribe_M(B);
                lib_M(&A);
				lib_M(&B);
				break;
			case 4:
				crea_espacio(&A);
				while(A.f!=A.c)
					{
						lib_M(&A);
						printf("la matriz debe ser cuadrada,y la matriz dada no lo es.Por favor teclee una matriz cuadrada\n");
						crea_espacio(&A);
					}
				A=lee_M(A);	
				escribe_M(A);
				D=Det_M(A);
					printf("\nEl determinante de la matriz es:");
					escribeH(D);
					if(cero_H(D))
					{
						printf("\nLa inversa de la matriz es:\n");
						C=inv_M(A);
						escribe_M(C);	
					}
					lib_M(&A);
					lib_M(&C);
		}
				
		system("pause");
		return 0;
	}
	
	H leeH(void)
	{
		H a;
		printf("\nPor fevor teclee la parte real del cuaternion: ");
		scanf("%lg",&a.re);
		printf("Por fevor teclee la parte vectorial i del cuaternion: ");
		scanf("%lg",&a.i);
		printf("Por fevor teclee la parte vectorial j del cuaternion: ");
		scanf("%lg",&a.j);
		printf("Por fevor teclee la parte vectorial k del cuaternion: ");
		scanf("%lg",&a.k);
		return a;
	}
	int escribeH(H a)
	{
		if(a.re==0&&a.i!=0&&a.j!=0&&a.k!=0)printf("%3lgi%+3lgj%+3lgk ",a.i,a.j,a.k);
		else if((a.re==0&&a.i==0&&a.j!=0&&a.k!=0))printf("%3lgj%+3lgk ",a.i,a.j,a.k);
		else if(a.re==0&&a.i==0&&a.j==0&&a.k!=0) printf("%+3lgk ",a.i,a.j,a.k);
		else if(a.re==0&&a.i==0&&a.j==0&&a.k==0) printf("  0  ");
		else if(a.re!=0&&a.i==0&&a.j!=0&&a.k!=0) printf("%3lg%+3lgj%+3lgk ",a.re,a.j,a.k);
		else if(a.re!=0&&a.i!=0&&a.j==0&&a.k!=0) printf("%3lg%+3lgi%+3lgk ",a.re,a.i,a.k);
		else if(a.re!=0&&a.i!=0&&a.j!=0&&a.k==0) printf("%3lg%+3lgi%+3lgj ",a.re,a.i,a.j);
		else if(a.re!=0&&a.i==0&&a.j==0&&a.k==0) printf("%3lg ",a.re);
		else printf("%3lg%+3lgi%+3lgj%+3lgk ",a.re,a.i,a.j,a.k);	
		return 0;
	}
	H SumaH(H a,H b)
	{
		H r;
		r.re=a.re+b.re;
		r.i=a.i+b.i;
		r.j=a.j+b.j;
		r.k=a.k+b.k;
		return r;
	}
	H ProdH(H a,H b)
	{
		H r;
		r.re=(a.re*b.re-a.i*b.i-a.j*b.j-a.k*b.k);
		r.i=(a.re*b.i+a.i*b.re+a.j*b.k-a.k*b.j);
		r.j=(b.re*a.j+a.re*b.j+a.k*b.i-a.i*b.k);
		r.k=(b.re*a.k+a.re*b.k+a.i*b.j-a.j*b.i);
		return r;
	}
	double NormH(H a)
	{
		double r;
		r=sqrt(cuad(a.re)+cuad(a.i)+cuad(a.j)+cuad(a.k));
		return r;	
	}
	H invH(H a)
	{
		H r;
		double n;
		n=NormH(a);
		r.re=a.re/(cuad(n));
		r.i=a.i/(cuad(n));
		r.j=a.j/(cuad(n));
		r.k=a.k/(cuad(n));
		return r;
	}
	H DivH(H a,H b)
	{
		H r;
		r=ProdH(a,invH(b));
		return r;
	}
	H ConjH(H a)
	{
		H r;
		r.re=a.re;
		r.i=-a.i;
		r.j=-a.j;
		r.k=-a.k;
		return r;
	}
	int cero_H(H a)
	{
		
		if(a.re==0&&a.i==0&&a.j==0&&a.k==0)return 0;
		else return 1;
	}
	H P_esc_H(int a,H b)
	{
		H r;
		r.re=b.re*a;
		r.i=b.i*a;
		r.j=b.j*a;
		r.k=b.k*a;
		return r;
	}
	
	int crea_espacio(M *a)
	{
		int i;
		printf("\nTeclee el numero de filas de la matriz:");
		scanf("%d",&a->f);
		printf("Teclee el numero de columnas de la matriz:");
		scanf("%d",&a->c);
		a->m=(H**)malloc(a->f*sizeof(H*));
		if(a->m!=NULL)
		{
			for(i=0;i<a->f;i++)
			{
				a->m[i]=(H*)malloc(a->c*sizeof(H));
				if(a->m[i]==NULL)
				{
					while(i>0)
					{
						free(a->m[--i]);
						a->m[i]=NULL;
					}
					break;
				}
			}
		}
		if(a->m==NULL) return -1;
		return 0;
	}
	M lee_M(M a)
	{
		int i,j;
		for(i=0;i<a.f;i++)
		{
			for(j=0;j<a.c;j++)
							{
								printf("Teclee el coeficiente %d%d",i+1,j+1);
								a.m[i][j]=leeH();
								printf("\n");
							}
			printf("\n");
		}
		return a;
	}
	int escribe_M(M a)
	{
		int i,j;
		for(i=0;i<a.f;i++)
		{
			printf("|");
			for(j=0;j<a.c;j++) escribeH(a.m[i][j]);
			printf("|\n");
		}
		return 0;	
	}
	int lib_M(M *a)
	{
		int i;
		for(i=0;i<a->f;i++)
		{
			free(a->m[i]);
			a->m[i]=NULL;
		}
		free(a->m);
		a->m=NULL;
		a->f=a->c=0;
		return 0;
	}
	M Suma_M(M a,M b)
	{
		M r;
		int i,j;
		r.f=a.f;
		r.c=a.c;
		r.m=(H**)malloc(r.f*sizeof(H*));
		for(i=0;i<r.f;i++)r.m[i]=(H*)malloc(r.c*sizeof(H));
		for(i=0;i<r.f;i++)for(j=0;j<r.c;j++)r.m[i][j]=SumaH(a.m[i][j],b.m[i][j]);
		return r;
	}
	M mat_cero(M a)
	{
		int i,j;
		for(i=0;i<a.f;i++)
		for(j=0;j<a.c;j++)
		{
			a.m[i][j].re=0;
			a.m[i][j].i=0;
			a.m[i][j].j=0;
			a.m[i][j].k=0;
		}
		return a;	
	}
	M Prod_M(M a,M b)
	{
		M r;
		H multi;
		int i,j,k;
		r.f=a.f;
		r.c=b.c;
		r.m=(H**)malloc(r.f*sizeof(H*));
		for(i=0;i<r.f;i++)r.m[i]=(H*)malloc(r.c*sizeof(H));
		r=mat_cero(r);
		for(i=0;i<r.f;i++)for(j=0;j<r.c;j++)for(k=0;k<r.f;k++)
											{
												multi=ProdH(a.m[i][k],b.m[k][j]);
												r.m[i][j]=SumaH(r.m[i][j],multi);
											}
		return r;
	}
     M trans_M(M a)
     {
       int i,j;
       M r;
       r.f=a.c;
       r.c=a.f;
		r.m=(H**)malloc(r.f*sizeof(H*));
		for(i=0;i<r.f;i++)r.m[i]=(H*)malloc(r.c*sizeof(H));            
       for(i=0;i<a.f;i++)for(j=0;j<a.c;j++)r.m[i][j]=a.m[j][i];  
        return r;         
    }
    M multi_MH(M a,H k)
    {
    	M r;
    	int i,j;
    	r.f=a.f;
    	r.c=a.c;
    	r.m=(H**)malloc(r.f*sizeof(H*));
		for(i=0;i<r.f;i++)r.m[i]=(H*)malloc(r.c*sizeof(H));
    	for(i=0;i<r.f;i++)for(j=0;j<r.c;j++) r.m[i][j]=ProdH(k,a.m[i][j]);
    	return r;
	}
    M Cam_F(M a,int q,int p)
    {
    	int i,j;
		M r;
		H aux;
		r.f=a.f;
		r.c=a.c;
		r.m=(H**)malloc(r.f*sizeof(H*));
		for(i=0;i<r.f;i++)r.m[i]=(H*)malloc(r.c*sizeof(H));
		for(j=0;j<r.c;j++)
			{
				aux=a.m[q][j];
				r.m[q][j]=a.m[p][j];
				r.m[p][j]=aux;
			}	
    	for(i=0;i<r.f;i++)for(j=0;j<r.c;j++) if(i!=p-1&&i!=q-1)r.m[i][j]=a.m[i][j];
    		
    	
    return r;	
    }
    M Prod_F(M a,int f,H k)
    {
    	int i,j;
		M r;	
    	r.f=a.f;
		r.c=a.c;
		r.m=(H**)malloc(r.f*sizeof(H*));
		for(j=0;j<r.c;j++)
		{
			r.m[f][j]=ProdH(a.m[f][j],k);
			escribeH(r.m[f][j]);
			system("pause");
		}
		for(i=0;i<r.f;i++)for(j=0;j<r.c;j++)
		if(i!=f)
		{
			r.m[i][j]=a.m[i][j];
			escribeH(r.m[i][j]);
			system("pause");
		}
    	return r;
    }
    M Sum_CL(M a,int f,int p,H k)
    {
    	int i,j;
    	M r;
    	r.f=a.f;
		r.c=a.c;
		r.m=(H**)malloc(r.f*sizeof(H*));
		for(i=0;i<r.f;i++)r.m[i]=(H*)malloc(r.c*sizeof(H));
		for(j=0;j<r.c;j++)r.m[f][j]=SumaH(ProdH(k,a.m[p][j]),a.m[f][j]); //k*a.m[p][j]+a.m[f][j];
		for(i=0;i<r.f;i++)for(j=0;j<r.c;j++) if(i!=f)r.m[i][j]=a.m[i][j];
    	return r;
    }
    M M_trian(M a)
    {
    	int i,j;
    	H aux;
		for(j=0;j<a.c-1;j++)
		{
			for(i=j;i<a.f-1;i++)
			{
				while(!cero_H(a.m[i][j])&&i<a.f-j)
				{
					a=Cam_F(a,j,i+1);
					i++;
				}	
				for(;i<a.c-i;i++)
				{
					aux=DivH(a.m[i+1][j],ConjH(a.m[j][j]));//a.m[i+1][j]/a.m[j][j];
					a=Sum_CL(a,i+1,j,P_esc_H(-1,aux));
				}
			}	
		}
		return a;				
    }
    H Det_M(M a)
    {
        int i;
		H r;
		if(a.f==1) return a.m[0][0];
		a=M_trian(a);
		r=ProdH(a.m[0][0],a.m[1][1]);
		for(i=2;i<a.f;i++)r=ProdH(r,a.m[i][i]);    
        return r;      
    }
    H Co_fac(M a,int p, int q)
    {
        H r;
		M aux;
		int i,j,k,t;
		aux.f=a.f-1;
		aux.c=a.c-1;
		aux.m=(H**)malloc(aux.f*sizeof(H*));
		for(i=0;i<aux.f;i++)aux.m[i]=(H*)malloc(aux.c*sizeof(H));
		for(i=0,k=0;i<a.f;i++,k++)
		{
			
			if(i!=p)for(j=0,t=0;j<a.c;j++,t++)
					{
					  if(j!=q)
					  {
					  	aux.m[k][t]=a.m[i][j];
					  }
					  else t--;	
					}
			else k--;
		}
		r=P_esc_H(pow(-1,p+q),Det_M(aux));
		return r;           
     }
     M inv_M(M a)
	{
		M r;
		H d;
		int i,j;
		r.f=a.f;
		r.c=a.c;
		r.m=(H**)malloc(r.f*sizeof(H*));
		for(i=0;i<r.f;i++)r.m[i]=(H*)malloc(r.c*sizeof(H));
		for(i=0;i<a.f;i++)for(j=0;j<a.c;j++)
		{
			r.m[i][j]=Co_fac(a,i,j);
		}
		d=Det_M(a);
		r=multi_MH(r,invH(d));
		return r;
	}
              
