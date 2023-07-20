	#include<stdio.h>
	#include<stdlib.h>
	#include"matriz_zp.h"
	
	int comp_p(int n,FILE *arch)
	{
		int i=0,p;
		while(!(feof(arch))&&i==0)
		{
			fscanf(arch,"%d",&p);
			if(p==n) i=1;
		}
		if(i==0)
		{
			printf("No es un numero primo\n");
			fclose(arch);
			return 0;
		}
		else
		{
			fclose(arch);
			return n;
		} 
	}
	int crea_zp(int a,int p)
	{
		return a%p;
	}
	int suma_zp(int a,int b,int p)
	{
		return crea_zp(a+b,p);
	}
	int resta_zp(int a,int b,int p)
	{
		int r;
		if((a-b)<0) r=-(a-b);
		return crea_zp(r,p);
	}
	int multi_zp(int a,int b,int p)
	{
		return crea_zp((a)*(b),p);
	}
	int inv_zp(int a,int p)
	{
		int i;
		for(i=1;i<p;i++)if((multi_zp(a,i,p))==1) break;
		return i;		
	}
	int divide_zp(int a,int b,int p)
	{
		return multi_zp(a,inv_zp(b,p),p);
	}
	int crea_espacio(M *a,int p)
	{
		int i;
		printf("\nTeclee el numero de filas de la matriz:");
		scanf("%d",&a->f);
		printf("Teclee el numero de columnas de la matriz:");
		scanf("%d",&a->c);
		a->m=(int**)malloc(a->f*sizeof(int*));
		if(a->m!=NULL)
		{
			for(i=0;i<a->f;i++)
			{
				a->m[i]=(int*)malloc(a->c*sizeof(int));
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
	M lee_M(M a,int p)
	{
		int i,j;
		for(i=0;i<a.f;i++)
		{
			for(j=0;j<a.c;j++)
			{
				printf("Teclee el coeficiente %d%d: ",i+1,j+1);
				scanf("%d",&a.m[i][j]);
				a.m[i][j]=crea_zp(a.m[i][j],p);
				printf("\n");
			}
			printf("\n");
		}
		printf("\n");
		return a;
	}
	M lee_M_A(FILE *arch,int p)
	{
		M r;
		int i,j;
		fscanf(arch,"%d%d",&r.f,&r.c);
		r.m=(int**)malloc(r.f*sizeof(int*));
		for(i=0;i<r.f;i++)r.m[i]=(int*)malloc(r.c*sizeof(int));
		for(i=0;i<r.f;i++)for(j=0;j<r.c;j++)
			{
				fscanf(arch,"%d",&r.m[i][j]);
				r.m[i][j]=crea_zp(r.m[i][j],p);
			}		
		return r;
	}
	int escribe_M(M a)
	{
		int i,j;
		for(i=0;i<a.f;i++)
		{
			printf("|");
			for(j=0;j<a.c;j++) printf("%6d ",a.m[i][j]);
			printf("|\n");
		}
		return 0;	
	}
	int escribe_M_A(FILE *arch,M a)
	{
		int i,j;
		for(i=0;i<a.f;i++)
		{
			for(j=0;j<a.c;j++) fprintf(arch,"%6d ",a.m[i][j]);	
		 	fprintf(arch,"\n");
		} 
		fprintf(arch,"\n");
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
	   r.m=(int**)malloc(r.f*sizeof(int*));
	   for(i=0;i<r.f;i++)r.m[i]=(int*)malloc(r.c*sizeof(int));            
       for(i=0;i<a.f;i++)for(j=0;j<a.c;j++)r.m[i][j]=a.m[j][i];  
       return r;         
    }
    M Suma_M(M a,M b,int p)
	{
		M r;
		int i,j;
		r.f=a.f;
		r.c=a.c;
		r.m=(int**)malloc(r.f*sizeof(int*));
		for(i=0;i<r.f;i++)r.m[i]=(int*)malloc(r.c*sizeof(int));
		for(i=0;i<r.f;i++)for(j=0;j<r.c;j++)r.m[i][j]=suma_zp(a.m[i][j],b.m[i][j],p);
		return r;
	}
	M Prod_M(M a,M b,int p)
	{
		M r;
		int i,j,k,r2;
		r.f=a.f;
		r.c=b.c;
		r.m=(int**)malloc(r.f*sizeof(int*));
		for(i=0;i<r.f;i++)r.m[i]=(int*)malloc(r.c*sizeof(int));
		for(i=0;i<r.f;i++)for(j=0;j<r.c;j++)r.m[i][j]=0;
		for(i=0;i<r.f;i++)for(j=0;j<r.c;j++)
		for(k=0;k<r.f;k++)
		{
			r2=multi_zp(a.m[i][k],b.m[k][j],p);
			r.m[i][j]=suma_zp(r.m[i][j],r2,p);
		}
		return r;
	}
	M Cam_F(M a,int q,int p)
    {
    	int i,j;
		M r;
		double aux;
		r.f=a.f;
		r.c=a.c;
		r.m=(int**)malloc(r.f*sizeof(int*));
		for(i=0;i<r.f;i++)r.m[i]=(int*)malloc(r.c*sizeof(int));
		for(j=0;j<r.c;j++)
			{
				aux=a.m[q][j];
				r.m[q][j]=a.m[p][j];
				r.m[p][j]=aux;
			}	
    	for(i=0;i<r.f;i++)for(j=0;j<r.c;j++) if(i!=p&&i!=q)r.m[i][j]=a.m[i][j];	
    return r;	
    }
    M Prod_F(M a,int f,int k,int p)
    {
    	int i,j;
		M r;	
    	r.f=a.f;
		r.c=a.c;
		r.m=(int**)malloc(r.f*sizeof(int*));
		for(i=0;i<r.f;i++)r.m[i]=(int*)malloc(r.c*sizeof(int));
		for(j=0;j<r.c;j++) r.m[f][j]=multi_zp(a.m[f][j],k,p);
		for(i=0;i<r.f;i++)for(j=0;j<r.c;j++) if(i!=f)r.m[i][j]=a.m[i][j];
    	return r;
    }
    M Sum_CL(M a,int f,int p,int k,int p_1)
    {
    	int i,j,R;
    	M r;
    	r.f=a.f;
		r.c=a.c;
		r.m=(int**)malloc(r.f*sizeof(int*));
		for(i=0;i<r.f;i++)r.m[i]=(int*)malloc(r.c*sizeof(int));
		for(j=0;j<r.c;j++) 
		{
			R=multi_zp(k,a.m[p][j],p_1);
			r.m[f][j]=suma_zp(R,a.m[f][j],p_1);					
		}
		for(i=0;i<r.f;i++)for(j=0;j<r.c;j++) if(i!=f)r.m[i][j]=a.m[i][j];
    	return r;
	}
	M M_trian(M a,int p)
	{
		int i,j;
    	M r;
    	int aux;
    	r.f=a.f;
		r.c=a.c;
		r.m=(int**)malloc(r.f*sizeof(int*));
		for(i=0;i<r.f;i++)r.m[i]=(int*)malloc(r.c*sizeof(int));
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
									aux=divide_zp(a.m[i+1][j],a.m[j][j],p);		
									a=Sum_CL(a,i+1,j,-aux,p);
								}
				}
			}	
		}			
		return a;
	}
	int Det_M(M a, int p)
	{
		int i,r;
		r=1;
		a=M_trian(a,p);
		for(i=0;i<a.f;i++)
		{
			r=multi_zp(r,a.m[i][i],p);
		}
		return r;
	}
	int Co_fac(M a,int p, int q,int p_1)
	{
		M aux;
		int i,j,k,t,r;
		aux.f=a.f-1;
		aux.c=a.c-1;
		aux.m=(int**)malloc(aux.f*sizeof(int*));
		for(i=0;i<aux.f;i++)aux.m[i]=(int*)malloc(aux.c*sizeof(int));
		for(i=0,k=0;i<a.f;i++,k++)
		{
			if(i!=p)for(j=0,t=0;j<a.c;j++,t++)
					{
					  if(j!=q)aux.m[k][t]=a.m[i][j];
					  else t--;	
				 	}	
			else k--;
		}
		r=Det_M(aux,p_1)*pow(-1,p+q);
		return r;		
	}
	M inv_M(M a,int p)
	{
		M r;		 
		int i,j,d;
		r.f=a.f;
		r.c=a.c;
		r.m=(int**)malloc(r.f*sizeof(int*));
		for(i=0;i<r.f;i++)r.m[i]=(int*)malloc(r.c*sizeof(int));
		for(i=0;i<a.f;i++)for(j=0;j<a.c;j++) r.m[i][j]=Co_fac(a,i,j,p);
		d=Det_M(a,p);
		for(i=0;i<a.f;i++) r=Prod_F(r,i,inv_zp(d,p),p);
		return r;
	}
