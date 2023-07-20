	
	#include<stdio.h>
 	#include<stdlib.h>
 	#include<math.h>
 	
 	typedef struct complejos
	 {
 		double re,im;	
	 }C;
	 
	 C leeC(void);
	 int escribeC(C a);
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
	 //Declaracion de funciones de las matrices
	 
	 int main()
	 {
	 	M a,b,c;
		C d;
		int elec,i=0;
		printf("Bienvenido usuario, el siguiente programa realizara las operaciones con matrices:\n1)Suma de 2 matrices\n2)EL producto de 2 matrices\n3)Regresa la transpuesta de una matriz\n4)Nos da el determinante de una matriz y su inversa\n");
		do
		{
			if(i)printf("\nEl programa realizara las operaciones con matrices:\n1)Suma de 2 matrices\n2)EL producto de 2 matrices\n3)Regresa la transpuesta de una matriz\n4)Nos da el determinante de una matriz y su inversa\n");
			scanf("%d",&elec);
			switch(elec)
			{
				case 1:
					crea_espacio(&a);
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
					escribeC(d);
					printf("\n");
					if(!C_Cero(d))
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
	 //Definicion de las funciones de los complejos
	 C leeC(void)
	 {
	 	 C a;
		 printf("\nEscriba la parte real de un numero complejo: ");
	 	 scanf("%lg",&a.re);
	 	 printf("Escriba la parte imaginaria de un numero complejo: ");
	 	 scanf("%lg",&a.im);
	 	 return a;
	 }
	 int escribeC(C a)
	 {
	 	if(a.re==0&&a.im==0)printf("%6lg ",a.re);	
		if((a.re==0)&&(a.im!=0))printf("%+6lgi ",a.im);
		if((a.im==0)&&(a.re!=0))printf("%6lg ",a.re);
	 	if((a.re!=0)&&(a.im!=0)) printf("%6lg%+6lgi ",a.re,a.im);
	 }
	 C SumC(C a,C b)
	 {
	 	C r;
	 	r.re=a.re+b.re;
	 	r.im=a.im+b.im;
	 	return r;
	 }
	 C DifC(C a,C b)
	 {
	 	C r;
	 	r.re=a.re-b.re;
	 	r.im=a.im-b.im;
	 	return r;
	 }
	 C MultiC(C a,C b)
	 {
	 	C r;
	 	r.re=(a.re)*(b.re)-(a.im)*(b.im);
	 	r.im=(a.re)*(b.im)+(a.im)*(b.re);
	 	return r;
	 }
	 C Conj(C a)
	 {
	 	C b;
	 	b.re=a.re;
	 	b.im=-a.im;
	 	return b;
	 }
	  C DivC(C a,C b)
	  {
	  	C r,d,c;
	  	c=Conj(b);
	  	r=MultiC(a,c);
	  	d=MultiC(b,c);
	  	r.re/=d.re;
	  	r.im/=d.re;
	  	return r;
	  }
	  double NormaC(C a)
	  {
	  	double n;
	  	n=sqrt((a.re)*(a.re)+(a.im)*(a.im));
	  	return n;
	  }
	  C CeroC(void)
	  {
	  	C r;
	  	r.re=0.0;
	  	r.im=0.0;
	  	return r;
	  }
	  int C_Cero(C a)
	  {
	  	 return a.re==0.0&&a.im==0;
	  }
	  C Multi_esc(C a,int b)
	  {
	  	C r;
	  	r.re=a.re*b;
	  	r.im=a.im*b;
	  	return r;
	  }
	  
	//inicio de las funciones para matrices
	int crea_espacio(M *a)
	{
		int i;
		printf("\nTeclee el numero de filas de la matriz:");
		scanf("%d",&a->f);
		printf("Teclee el numero de columnas de la matriz:");
		scanf("%d",&a->c);
		a->m=(C**)malloc(a->f*sizeof(C*));
		if(a->m!=NULL)
		{
			for(i=0;i<a->f;i++)
			{
				a->m[i]=(C*)malloc(a->c*sizeof(C));
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
				a.m[i][j]=leeC();
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
			for(j=0;j<a.c;j++) escribeC(a.m[i][j]);
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
		r.m=(C**)malloc(r.f*sizeof(C*));
		for(i=0;i<r.f;i++)r.m[i]=(C*)malloc(r.c*sizeof(C));            
        for(i=0;i<a.f;i++)for(j=0;j<a.c;j++)r.m[i][j]=a.m[j][i];  
        return r;         
     }
	M Suma_M(M a,M b)
	{
		M r;
		int i,j;
		r.f=a.f;
		r.c=a.c;
		r.m=(C**)malloc(r.f*sizeof(C*));
		for(i=0;i<r.f;i++)r.m[i]=(C*)malloc(r.c*sizeof(C));
		for(i=0;i<r.f;i++)for(j=0;j<r.c;j++)r.m[i][j]=SumC(a.m[i][j],b.m[i][j]);
		return r;
	}
	M Prod_M(M a,M b)
	{
		M r;
		int i,j,k;
		r.f=a.f;
		r.c=b.c;
		r.m=(C**)malloc(r.f*sizeof(C*));
		for(i=0;i<r.f;i++)r.m[i]=(C*)malloc(r.c*sizeof(C));
		for(i=0;i<r.f;i++)for(j=0;j<r.c;j++)r.m[i][j]=CeroC();
		for(i=0;i<r.f;i++)for(j=0;j<r.c;j++)for(k=0;k<r.f;k++) r.m[i][j]=SumC(r.m[i][j],MultiC(a.m[i][k],b.m[k][j]));//r.m[i][j]+=a.m[i][k]*b.m[k][j];
		return r;
	}
	M Cam_F(M a,int q,int p)
    {
    	int i,j;
		M r;
		C aux;
		r.f=a.f;
		r.c=a.c;
		r.m=(C**)malloc(r.f*sizeof(C*));
		for(i=0;i<r.f;i++)r.m[i]=(C*)malloc(r.c*sizeof(C));
		for(j=0;j<r.c;j++)
			{
				aux=a.m[q][j];
				r.m[q][j]=a.m[p][j];
				r.m[p][j]=aux;
			}	
    	for(i=0;i<r.f;i++)for(j=0;j<r.c;j++) if(i!=p&&i!=q)r.m[i][j]=a.m[i][j];	
    return r;	
    }
    M Prod_F(M a,int f,C k)
    {
    	int i,j;
		M r;	
    	r.f=a.f;
		r.c=a.c;
		r.m=(C**)malloc(r.f*sizeof(C*));
		for(i=0;i<r.f;i++)r.m[i]=(C*)malloc(r.c*sizeof(C));
		for(j=0;j<r.c;j++) r.m[f][j]=MultiC(a.m[f][j],k);
		for(i=0;i<r.f;i++)for(j=0;j<r.c;j++) if(i!=f)r.m[i][j]=a.m[i][j];
    	return r;
    }
    M Sum_CL(M a,int f,int p,C k)
    {
    	int i,j;
    	M r;
    	r.f=a.f;
		r.c=a.c;
		r.m=(C**)malloc(r.f*sizeof(C*));
		for(i=0;i<r.f;i++)r.m[i]=(C*)malloc(r.c*sizeof(C));
		for(j=0;j<r.c;j++) 
		{
			r.m[f][j]=SumC(MultiC(k,a.m[p][j]),a.m[f][j]);   //k*a.m[p][j]+a.m[f][j];
		}
		for(i=0;i<r.f;i++)for(j=0;j<r.c;j++) if(i!=f)r.m[i][j]=a.m[i][j];
    	return r;
	}
	M M_trian(M a)
	{
		int i,j;
    	M r;
    	C aux;
		for(j=0;j<a.c-1;j++)
		{
			for(i=j;i<a.f-j;i++)
			{
			
				while((C_Cero(a.m[j][j]))&&i<a.f-j)
				{
					a=Cam_F(a,j,i+1);
					i++;
				}
				for(;i<a.c-i;i++)
				{
					aux=DivC(a.m[i+1][j],a.m[j][j]);
					a=Sum_CL(a,i+1,j,Multi_esc(aux,-1));
				}
			}	
		}
		return a;
	}
	C Det_M(M a)
	{
		int i;
		C r;
		r.re=1;
		r.im=0;
		a=M_trian(a);
		for(i=0;i<a.f;i++)r=MultiC(r,a.m[i][i]);
		return r;
	}
	C Co_fac(M a,int p, int q)
	{
		C r;
		M aux;
		int i,j,k,t;
		int s=1;
		aux.f=a.f-1;
		aux.c=a.c-1;
		aux.m=(C**)malloc(aux.f*sizeof(C*));
		for(i=0;i<aux.f;i++)aux.m[i]=(C*)malloc(aux.c*sizeof(C));
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
		C d,aux;
		int i,j;
		aux.re=1;
		aux.im=0;
		r.f=a.f;
		r.c=a.c;
		r.m=(C**)malloc(r.f*sizeof(C*));
		for(i=0;i<r.f;i++)r.m[i]=(C*)malloc(r.c*sizeof(C));
		for(i=0;i<a.f;i++)for(j=0;j<a.c;j++)r.m[i][j]=Co_fac(a,i,j);
		d=Det_M(a);
		for(i=0;i<a.f;i++) r=Prod_F(r,i,DivC(aux,d));
		return r;
	}
		
