	
	#include<stdio.h>
	#include<stdlib.h>
	
	typedef struct racionales{
	int p,q;	
	}Q;
	
	int mcd(int a,int b);
	Q simplificaQ(Q a);
	Q leeQ(void);
	int escribeQ(Q a);
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
	int escribe_M(M a);
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
	
	int main()
	{
		M a,b,c;
		Q d;
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
					printf("\nEl determinante de la matriz es:");
					d=Det_M(a);
					escribeQ(d);
					printf("\n");
					if(!C_CeroQ(d))
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
	//inicio de las funciones para matrices
	int mcd(int a,int b)
	{
		int r;
		if(a<0) a=-a;
		if(b<0) b=-b;
		while((r=a%b)!=0)
		{
			a=b;
			b=r;
		}
		return b;
	}
	
	Q simplificaQ(Q a)
	{
		int r;
		Q regreso;
		regreso=a;
		r=mcd(a.p,a.q);
			if(r>1)
			{
				regreso.p/=r;
				regreso.q/=r;
			}
			if (regreso.q < 0)
			{       
    			regreso.p *= -1;        
    			regreso.q *= -1;        
  			}

  		return regreso;
	}
	
	Q leeQ(void)
	{
		Q a;
		printf("Escriba el numerador del numero racional: ");
		scanf("%d",&a.p);
		printf("Escriba el denomindor del numero racional: ");
		scanf("%d",&a.q);
		while(a.q==0)
		{
			printf("\n%d no puede ser cero, por favor teclee un numero distinto de cero: ",a.q);
			scanf("%d",&a.q);	
		}
		a=simplificaQ(a);
		return a;
	}
	int escribeQ(Q a)
	{
		if(a.p==0)
		{
			printf(" %3d ",0.0);
			return 0;
		}
		if(a.q==1) printf(" %3d ",a.p);
		else printf(" %3d/%3d ",a.p,a.q);
		return 0;
	}
	Q SumaQ(Q a,Q b)
	{
		Q r;
		r.p=(a.p*b.q)+(b.p*a.q);
		r.q=a.q*b.q;
		r=simplificaQ(r);
		return r;
	}
	Q RestaQ(Q a,Q b)
	{
		Q r;
		r.p=(a.p*b.q)-(b.p*a.q);
		r.q=a.q*b.q;
		r=simplificaQ(r);
		return r;
	}
	Q MultiQ(Q a,Q b)
	{
		Q r;
		r.p=a.p*b.p;
		r.q=a.q*b.q;
		r=simplificaQ(r);
		return r;
	}
	Q DivQ(Q a,Q b)
	{
		Q r;
		r.p=a.p*b.q;
		r.q=b.p*a.q;
		r=simplificaQ(r);
		return r;
	}
	Q CeroQ(void)
	{
		Q a;
		a.p=0;
		a.q=1;
		return a;
	}
	int C_CeroQ(Q a)
	{
		return a.p==0;
	}
	Q Multi_esc(Q a,double b)
	{
		a.p*=b;
		return a;
	}
	//fin de las funciones de Q
	
	//inicio de las funciones para matrices
	int crea_espacio(M *a)
	{
		int i;
		printf("\nTeclee el numero de filas de la matriz:");
		scanf("%d",&a->f);
		printf("Teclee el numero de columnas de la matriz:");
		scanf("%d",&a->c);
		a->m=(Q**)malloc(a->f*sizeof(Q*));
		if(a->m!=NULL)
		{
			for(i=0;i<a->f;i++)
			{
				a->m[i]=(Q*)malloc(a->c*sizeof(Q));
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
				printf("Teclee el coeficiente %d%d de la matriz:\n",i+1,j+1);
				a.m[i][j]=leeQ();
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
		printf("La matriz resultante es:\n");
		for(i=0;i<a.f;i++)
		{
			printf("|");
			for(j=0;j<a.c;j++) escribeQ(a.m[i][j]);
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
		r.m=(Q**)malloc(r.f*sizeof(Q*));
		for(i=0;i<r.f;i++)r.m[i]=(Q*)malloc(r.c*sizeof(Q));            
        for(i=0;i<a.f;i++)for(j=0;j<a.c;j++)r.m[i][j]=a.m[j][i];  
        return r;         
     }
	M Suma_M(M a,M b)
	{
		M r;
		int i,j;
		r.f=a.f;
		r.c=a.c;
		r.m=(Q**)malloc(r.f*sizeof(Q*));
		for(i=0;i<r.f;i++)r.m[i]=(Q*)malloc(r.c*sizeof(Q));
		for(i=0;i<r.f;i++)for(j=0;j<r.c;j++)r.m[i][j]=SumaQ(a.m[i][j],b.m[i][j]);
		return r;
	}
	M Prod_M(M a,M b)
	{
		M r;
		int i,j,k;
		r.f=a.f;
		r.c=b.c;
		r.m=(Q**)malloc(r.f*sizeof(Q*));
		for(i=0;i<r.f;i++)r.m[i]=(Q*)malloc(r.c*sizeof(Q));
		for(i=0;i<r.f;i++)for(j=0;j<r.c;j++)r.m[i][j]=CeroQ();
		for(i=0;i<r.f;i++)for(j=0;j<r.c;j++)for(k=0;k<r.f;k++) r.m[i][j]=SumaQ(r.m[i][j],MultiQ(a.m[i][k],b.m[k][j]));//r.m[i][j]+=a.m[i][k]*b.m[k][j];
		return r;
	}
	M Cam_F(M a,int q,int p)
    {
    	int i,j;
		M r;
		Q aux;
		r.f=a.f;
		r.c=a.c;
		r.m=(Q**)malloc(r.f*sizeof(Q*));
		for(i=0;i<r.f;i++)r.m[i]=(Q*)malloc(r.c*sizeof(Q));
		for(j=0;j<r.c;j++)
			{
				aux=a.m[q][j];
				r.m[q][j]=a.m[p][j];
				r.m[p][j]=aux;
			}	
    	for(i=0;i<r.f;i++)for(j=0;j<r.c;j++) if(i!=p&&i!=q)r.m[i][j]=a.m[i][j];	
    return r;	
    }
    M Prod_F(M a,int f,Q k)
    {
    	int i,j;
		M r;	
    	r.f=a.f;
		r.c=a.c;
		r.m=(Q**)malloc(r.f*sizeof(Q*));
		for(i=0;i<r.f;i++)r.m[i]=(Q*)malloc(r.c*sizeof(Q));
		for(j=0;j<r.c;j++) r.m[f][j]=MultiQ(a.m[f][j],k);
		for(i=0;i<r.f;i++)for(j=0;j<r.c;j++) if(i!=f)r.m[i][j]=a.m[i][j];
    	return r;
    }
    M Sum_CL(M a,int f,int p,Q k)
    {
    	int i,j;
    	M r;
    	r.f=a.f;
		r.c=a.c;
		r.m=(Q**)malloc(r.f*sizeof(Q*));
		for(i=0;i<r.f;i++)r.m[i]=(Q*)malloc(r.c*sizeof(Q));
		for(j=0;j<r.c;j++) 
		{
			r.m[f][j]=SumaQ(MultiQ(k,a.m[p][j]),a.m[f][j]);   //k*a.m[p][j]+a.m[f][j];
		}
		for(i=0;i<r.f;i++)for(j=0;j<r.c;j++) if(i!=f)r.m[i][j]=a.m[i][j];
    	return r;
	}
	M M_trian(M a)
	{
		int i,j;
    	M r;
    	Q aux;
		for(j=0;j<a.c-1;j++)
		{
			for(i=j;i<a.f-j;i++)
			{
			
				while((C_CeroQ(a.m[j][j]))&&i<a.f-j)
				{
					a=Cam_F(a,j,i+1);
					i++;
				}
				for(;i<a.c-i;i++)
				{
					aux=DivQ(a.m[i+1][j],a.m[j][j]);
					a=Sum_CL(a,i+1,j,Multi_esc(aux,-1));
				}
			}	
		}
		return a;
	}
	Q Det_M(M a)
	{
		int i;
		Q r;
		r.p=1;
		r.q=1;
		a=M_trian(a);
		for(i=0;i<a.f;i++)r=MultiQ(r,a.m[i][i]);
		return r;
	}
	Q Co_fac(M a,int p, int q)
	{
		Q r;
		M aux;
		int i,j,k,t;
		double s=1;
		aux.f=a.f-1;
		aux.c=a.c-1;
		aux.m=(Q**)malloc(aux.f*sizeof(Q*));
		for(i=0;i<aux.f;i++)aux.m[i]=(Q*)malloc(aux.c*sizeof(Q));
		for(i=0,k=0;i<a.f;i++,k++)
		{
			if(i!=p)for(j=0,t=0;j<a.c;j++,t++)
					{
					  if(j!=q)aux.m[k][t]=a.m[i][j];
					  else t--;	
				 	}	
			else k--;
		}
		for(i=0;i<p+q;i++)s*=-1;
		r=Multi_esc(Det_M(aux),s);
		return r;
	}
	M inv_M(M a)
	{
		M r;
		Q d,aux;
		int i,j;
		aux.p=1;
		aux.q=1;
		r.f=a.f;
		r.c=a.c;
		r.m=(Q**)malloc(r.f*sizeof(Q*));
		for(i=0;i<r.f;i++)r.m[i]=(Q*)malloc(r.c*sizeof(Q));
		for(i=0;i<a.f;i++)for(j=0;j<a.c;j++)r.m[i][j]=Co_fac(a,i,j);
		d=Det_M(a);
		for(i=0;i<a.f;i++) r=Prod_F(r,i,DivQ(aux,d));
		return r;
	}
		
