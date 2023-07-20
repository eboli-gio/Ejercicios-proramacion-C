

	#include<stdio.h>
	#include<stdlib.h>
	#include<math.h>
	typedef struct matrices{
		double **m;
		int f,c;
	}M;
	
	int crea_espacio(M *a);
	M lee_M(M a);
	int escribe_M(M a);
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
	int main()
	{
		M a,b,c;
		double d;
		int elec,i=0;
		printf("Bienvenido usuario, el siguiente programa realizara las operaciones con matrices:\n1)Suma de 2 matrices\n2)EL producto de 2 matrices\n3)Regresa la transpuesta de una matriz\n4)Nos da el determinante de una matriz y su inversa\n");
		do
		{
			if(i)printf("\nEl programa realizara las operaciones con matrices:\n1)Suma de 2 matrices\n2)EL producto de 2 matrices\n3)Regresa la transpuesta de una matriz\n4)Nos da el determinante de una matriz y su inversa\n");
			scanf("%d",&elec);
			switch(elec)
			{
				case 1:crea_espacio(&a);
				   	a=lee_M(a);
				   	escribe_M(a);
				   	crea_espacio(&b);
				   	b=lee_M(b);
				   	escribe_M(b);
				   	if(a.f==b.f&&a.c==b.c)
				   	{
				   		printf("La suma de las dos matrices es:\n");
				   		c=Suma_M(a,b);
				   		escribe_M(c);
					}
					else printf("\nLa suma no es posible\n");
				   	lib_M(&a);
					lib_M(&b);
					if(a.f==b.f&&a.c==b.c) lib_M(&c);
			break;
			case 2:	crea_espacio(&a);
				   	a=lee_M(a);
				   	escribe_M(a);
				   	crea_espacio(&b);
				   	b=lee_M(b);
				  	escribe_M(b);
				   	if(a.c==b.f)
				   	{
				   		printf("El producto de las dos matrices es:\n");
				   		c=Prod_M(a,b);
				   		escribe_M(c);	
					}
					else printf("\nEl producto no es posible\n");
				   	lib_M(&a);
					lib_M(&b);
					if(a.c==b.f) lib_M(&c);
			break;
			case 3:	crea_espacio(&a);
				   	a=lee_M(a);
				   	escribe_M(a);
				   	c=trans_M(a);
				   	printf("La transpuesta de la matriz es:\n");
				   	escribe_M(c);
				   	lib_M(&a);
					lib_M(&c);
			break;
			case 4:	crea_espacio(&a);
					while(a.f!=a.c)
					{
						lib_M(&a);
						printf("la matriz debe ser cuadrada,y la matriz dada no lo es.Por favor teclee una matriz cuadrada\n");
						crea_espacio(&a);
					}
					a=lee_M(a);
				   	escribe_M(a);
					d=Det_M(a);
					printf("\nEl determinante de la matriz es:%lg\n",d);
					if(d!=0)
					{
						printf("La inversa de la matriz es:\n");
						c=inv_M(a);
						escribe_M(c);	
					}
					lib_M(&a);
					lib_M(&c);
			break;
			default:printf("Si se equivoco teclee un numero distinto de cero, si no teclee 0\n");
					scanf("%d",&i);
					system("cls");	
			break;		
		}
		}while(i);
		system("pause");
		return 0;	
	}
   int crea_espacio(M *a)
	{
		int i;
		printf("\nTeclee el numero de filas de la matriz:");
		scanf("%d",&a->f);
		printf("Teclee el numero de columnas de la matriz:");
		scanf("%d",&a->c);
		a->m=(double**)malloc(a->f*sizeof(double*));
		if(a->m!=NULL)
		{
			for(i=0;i<a->f;i++)
			{
				a->m[i]=(double*)malloc(a->c*sizeof(double));
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
								printf("Teclee el coeficiente %d%d: ",i+1,j+1);
								scanf("%lg",&a.m[i][j]);
								printf("\n");
							}
			printf("\n");
		}
		printf("\n");
		return a;
	}
	int escribe_M(M a)
	{
		int i,j;
		for(i=0;i<a.f;i++)
		{
			printf("|");
			for(j=0;j<a.c;j++) printf("%6lg ",a.m[i][j]);
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
	M trans_M(M a)
     {
       int i,j;
       M r;
       r.f=a.c;
       r.c=a.f;
		r.m=(double**)malloc(r.f*sizeof(double*));
		for(i=0;i<r.f;i++)r.m[i]=(double*)malloc(r.c*sizeof(double));            
       for(i=0;i<a.f;i++)for(j=0;j<a.c;j++)r.m[i][j]=a.m[j][i];  
        return r;         
    }
    M Suma_M(M a,M b)
	{
		M r;
		int i,j;
		r.f=a.f;
		r.c=a.c;
		r.m=(double**)malloc(r.f*sizeof(double*));
		for(i=0;i<r.f;i++)r.m[i]=(double*)malloc(r.c*sizeof(double));
		for(i=0;i<r.f;i++)for(j=0;j<r.c;j++)r.m[i][j]=a.m[i][j]+b.m[i][j];
		return r;
	}
	M Prod_M(M a,M b)
	{
		M r;
		int i,j,k;
		r.f=a.f;
		r.c=b.c;
		r.m=(double**)malloc(r.f*sizeof(double*));
		for(i=0;i<r.f;i++)r.m[i]=(double*)malloc(r.c*sizeof(double));
		for(i=0;i<r.f;i++)for(j=0;j<r.c;j++)r.m[i][j]=0;
		for(i=0;i<r.f;i++)for(j=0;j<r.c;j++)for(k=0;k<r.f;k++)r.m[i][j]+=a.m[i][k]*b.m[k][j];
		return r;
	}
	M Cam_F(M a,int q,int p)
    {
    	int i,j;
		M r;
		double aux;
		r.f=a.f;
		r.c=a.c;
		r.m=(double**)malloc(r.f*sizeof(double*));
		for(i=0;i<r.f;i++)r.m[i]=(double*)malloc(r.c*sizeof(double));
		for(j=0;j<r.c;j++)
			{
				aux=a.m[q][j];
				r.m[q][j]=a.m[p][j];
				r.m[p][j]=aux;
			}	
    	for(i=0;i<r.f;i++)for(j=0;j<r.c;j++) if(i!=p&&i!=q)r.m[i][j]=a.m[i][j];	
    return r;	
    }
    M Prod_F(M a,int f,double k)
    {
    	int i,j;
		M r;	
    	r.f=a.f;
		r.c=a.c;
		r.m=(double**)malloc(r.f*sizeof(double*));
		for(i=0;i<r.f;i++)r.m[i]=(double*)malloc(r.c*sizeof(double));
		for(j=0;j<r.c;j++) r.m[f][j]=a.m[f][j]*k;
		for(i=0;i<r.f;i++)for(j=0;j<r.c;j++) if(i!=f)r.m[i][j]=a.m[i][j];
    	return r;
    }
    M Sum_CL(M a,int f,int p,double k)
    {
    	int i,j;
    	M r;
    	r.f=a.f;
		r.c=a.c;
		r.m=(double**)malloc(r.f*sizeof(double*));
		for(i=0;i<r.f;i++)r.m[i]=(double*)malloc(r.c*sizeof(double));
		for(j=0;j<r.c;j++) 
		{
			r.m[f][j]=k*a.m[p][j]+a.m[f][j];
		}
		for(i=0;i<r.f;i++)for(j=0;j<r.c;j++) if(i!=f)r.m[i][j]=a.m[i][j];
    	return r;
	}
	M M_trian(M a)
	{
		int i,j;
    	M r;
    	double aux;
    	r.f=a.f;
		r.c=a.c;
		r.m=(double**)malloc(r.f*sizeof(double*));
		for(i=0;i<r.f;i++)r.m[i]=(double*)malloc(r.c*sizeof(double));
		for(j=0;j<a.c-1;j++)
		{
			for(i=j;i<a.f-j;i++)
			{
				while(a.m[i][j]==0&&i<a.f-j)
				{
					if(i<a.f-j)
					{
						a=Cam_F(a,j,i+1);
						i++;
					}
					else i++;
					
				}	
				if(a.m[j][j]!=0)
				{
					for(;i<a.c-i;i++)
								{
									aux=a.m[i+1][j]/a.m[j][j];
									a=Sum_CL(a,i+1,j,-aux);
								}
				}
			}	
		}	
		return a;
	}
	double Det_M(M a)
	{
		int i;
		double r;
		r=1;
		a=M_trian(a);
		for(i=0;i<a.f;i++)r*=a.m[i][i];
		return r;
	}
	double Co_fac(M a,int p, int q)
	{
		double r;
		M aux;
		int i,j,k,t;
		aux.f=a.f-1;
		aux.c=a.c-1;
		aux.m=(double**)malloc(aux.f*sizeof(double*));
		for(i=0;i<aux.f;i++)aux.m[i]=(double*)malloc(aux.c*sizeof(double));
		for(i=0,k=0;i<a.f;i++,k++)
		{
			if(i!=p)for(j=0,t=0;j<a.c;j++,t++)
					{
					  if(j!=q)aux.m[k][t]=a.m[i][j];
					  else t--;	
				 	}	
			else k--;
		}
		r=Det_M(aux)*pow(-1,p+q);
		return r;
	}
	M inv_M(M a)
	{
		M r;
		double d;
		int i,j;
		r.f=a.f;
		r.c=a.c;
		r.m=(double**)malloc(r.f*sizeof(double*));
		for(i=0;i<r.f;i++)r.m[i]=(double*)malloc(r.c*sizeof(double));
		for(i=0;i<a.f;i++)for(j=0;j<a.c;j++)r.m[i][j]=Co_fac(a,i,j);
		d=Det_M(a);
		for(i=0;i<a.f;i++) r=Prod_F(r,i,1/d);
		return r;
	}	
