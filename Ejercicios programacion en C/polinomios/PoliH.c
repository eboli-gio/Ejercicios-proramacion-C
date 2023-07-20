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
	H DifH(H a,H b);
	H ProdH(H a,H b);
	H invH(H a);
	H DivH(H a,H b);
	double NormH(H a);
	H ConjH(H a);
	int cero_H(H a);
	H Prod_escH(double t,H a);
	H es_ceroH(void);
	//Funciones de operaciones de cuaterniones
	typedef struct polinomios
    {
     int gr;
     H *p; 
    }P;       
    
    int crea_espacio(P *q);
    P lee_P(P q);
    int escribe_p(P q);
    P Suma_p(P t, P q);
    P Resta_p(P t,P q);
    P multiplica_p(P t,P q);
    P mono_p(P t,H q,int g);
    int poli_cero(P t);
    P divide_p(P t,P q,P *res);
    P mcd_p(P t,P q,P res);
    
    int main()
    {
    P t,q,r,res;
     crea_espacio(&q);
     q=lee_P(q);
     printf("El polinomio es: ");
     escribe_p(q);
     crea_espacio(&t);
     t=lee_P(t);
     printf("El polinomio es: ");
     escribe_p(t);
	 /*r=divide_p(q,t,&res);
	 printf("El cociente de la division es: ");
     escribe_p(r);
     printf("El residuo de la division es: ");
     escribe_p(res);
     free(r.p);
     printf("\n");
     printf("El mcd es: ");
     r=mcd_p(q,t,res);
     escribe_p(r);*/ 	 	
     printf("\n\nFIN DEL PROGRAMA\n");
     free(r.p);    
     free(q.p);
     free(t.p);
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
		if(a.re==0&&a.i!=0&&a.j!=0&&a.k!=0)printf("(%lgi%+lgj%+lgk)",a.i,a.j,a.k);
		else if((a.re==0&&a.i==0&&a.j!=0&&a.k!=0))printf("(%lgj%+lgk)",a.i,a.j,a.k);
		else if(a.re==0&&a.i==0&&a.j==0&&a.k!=0) printf("(%+lgk)",a.i,a.j,a.k);
		else if(a.re==0&&a.i==0&&a.j==0&&a.k==0) printf("0");
		else if(a.re!=0&&a.i==0&&a.j!=0&&a.k!=0) printf("(%lg%+lgj%+lgk)",a.re,a.j,a.k);
		else if(a.re!=0&&a.i!=0&&a.j==0&&a.k!=0) printf("(%lg%+lgi%+lgk)",a.re,a.i,a.k);
		else if(a.re!=0&&a.i!=0&&a.j!=0&&a.k==0) printf("(%lg%+lgi%+lgj)",a.re,a.i,a.j);
		else printf("(%lg%+lgi%+lgj%+lgk)",a.re,a.i,a.j,a.k);	
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
	H DifH(H a,H b)
	{
		H r;
		r.re=a.re-b.re;
		r.i=a.i-b.i;
		r.j=a.j-b.j;
		r.k=a.k-b.k;
		return r;
	}
	H ProdH(H a,H b)
	{
		H r;
		r.re=(a.re*b.re-a.i*b.i-a.j*b.j-a.k*b.k);
		r.i=((a.re*b.i)+(a.i*b.re)+(a.j*b.k)-(a.k*b.j));
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
		if(a.re==0&&a.i==0&&a.j==0&&a.k==0) return 0;
		return 1;
	}
	H Prod_escH(double t,H a)
	{
		H r;
		r.re=t*a.re;
		r.i=t*a.i;
		r.j=t*a.j;
		r.k=t*a.k;
		return r;
	}
	H es_ceroH(void)
	{
		H r;
		r.re=0;
		r.i=0;
		r.j=0;
		r.k=0;
		return r;
	}
	//Definicion de funciones de polinomios
	int crea_espacio(P *q)
    {
        printf("\nPor favor teclee el grado del polinomio: ");
        scanf("%d",&q->gr);
        q->p=(H*)malloc((q->gr+1)*sizeof(H));
        if(q->p==NULL) return -1;
        return 0;
    }
    P lee_P(P q)
    {             
     int i;            
     for(i=q.gr;i>=0;i--)
		{
			printf("Teclee el valor del coeficiente de grado %d:",i);
			q.p[i]=leeH();
		}            
         return q;        
    }
    int escribe_p(P q)
    {
        int i;    
		if(poli_cero(q))
		{
			printf("%lg",q.p[0]);
			return 0;
		}
		for(i=q.gr;i>=0;i--)
		{
			if(!cero_H(q.p[i]))
			{
				if(i!=0)
				{
					if(i==q.gr)
						{
						if(q.p[i].re!=0||q.p[i].i!=0||q.p[i].j!=0||q.p[i].k!=0)
							{
							printf("(");
							escribeH(q.p[i]);
							printf(")");
							printf("X^%d ",i);
							}
							else printf("X^%d",i);
						}
					else
					{
						if(q.p[i].re!=0||q.p[i].i!=0||q.p[i].j!=0||q.p[i].k!=0)
							{
							printf("+(");
							escribeH(q.p[i]);
							printf(")");
							printf("X^%d ",i);
							}
							else if(i==q.gr)printf("X^%d",i);
							else printf("+X^%d",i);
					}
				}
						
				else 
				{
					printf("+");
					escribeH(q.p[i]);
				}
			}
		}
		printf("\n");        
        return 0;        
    }
	int poli_cero(P t)
    {
    	return t.gr<=0;
    }
    P Suma_p(P t, P q)
    {
      P r;
      int max,min,i;
		max=(t.gr+q.gr+(abs(t.gr-q.gr)))/2;
		min=(t.gr+q.gr-(abs(t.gr-q.gr)))/2;
		r.gr=max;
		r.p=(H*)malloc((r.gr+1)*sizeof(H));
		if(r.p==NULL)return t;
		for(i=0;r.gr>=i;i++)
		{
			if(i<=min) r.p[i]=SumaH(t.p[i],q.p[i]);
			else
			{
				if(t.gr==max) r.p[i]=t.p[i];
				if(q.gr==max) r.p[i]=q.p[i];
			}	
		}
		while(r.gr>=0&&!(cero_H(r.p[r.gr])))r.gr--;
		return r;
	}
	P Resta_p(P t,P q)
    {
       	P r;
      	int max,min,i;
		max=(t.gr+q.gr+(abs(t.gr-q.gr)))/2;
		min=(t.gr+q.gr-(abs(t.gr-q.gr)))/2;
		r.gr=max;
		r.p=(H*)malloc((r.gr+1)*sizeof(H));
		if(r.p==NULL)return t;
		for(i=0;r.gr>=i;i++)
		{
			if(i<=min) r.p[i]=DifH(t.p[i],q.p[i]);
			else
			{
				if(t.gr==max) r.p[i]=t.p[i];
				if(q.gr==max) r.p[i]=Prod_escH(-1,q.p[i]);
			}	
		}
		while(r.gr>=0&&cero_H(r.p[r.gr]))r.gr--;	
		return r;              
    }
	P multiplica_p(P t,P q)
    {
       P r;
       int i,j,k,max,min;
       max=(t.gr+q.gr+(abs(t.gr-q.gr)))/2;
       min=(t.gr+q.gr-(abs(t.gr-q.gr)))/2;    
       r.gr=t.gr+q.gr;          
       r.p=(H*)malloc((r.gr+1)*sizeof(H));
       if(r.p==NULL) return t;
       for(i=0;i<=r.gr;i++) r.p[i]=es_ceroH();
       for(i=0;i<=t.gr;i++)for(j=0;j<=q.gr;j++)r.p[i+j]=SumaH(r.p[i+j],ProdH(t.p[i],q.p[j]));       						
       return r;
	}
	P mono_p(P t,H q,int g)
	{
		P r;
    	int i;
    	r.gr=t.gr+g;
    	r.p=(H*)malloc((r.gr+1)*sizeof(H));
    	for(i=0;i<=r.gr;i++)r.p[i]=es_ceroH();
		for(i=g;i<=r.gr;i++)r.p[i]=ProdH(q,t.p[i-g]);
    	return r;
	}
	P divide_p(P t,P q,P *res)
	{
		P aux,c;
    	int grad,i;
    	if (t.gr<q.gr)
		{
    		c.gr=-1;
    		*res=t;
    		return c;
    	}
		c.gr=t.gr-q.gr;
		c.p=(H*)malloc((c.gr+1)*sizeof(H));
		for(i=0;i<=c.gr;i++)c.p[i]=es_ceroH();
		do
		{
			grad=t.gr-q.gr;
			c.p[grad]=DivH(t.p[t.gr],ConjH(q.p[q.gr]));
			aux=mono_p(q,c.p[grad],grad);
			t=Resta_p(t,aux);
			*res=t;
		}while(!poli_cero(*res)&&(t.gr>=q.gr));		
		return c;
	}
	P mcd_p(P t,P q,P res)
    {
    	P aux;
    	if(poli_cero(res))
    	{
    		return q;
		}
    	do
    	{
    		t=q;
    		q=res;
    		aux=divide_p(t,q,&res);
		}while(!poli_cero(res)&&(t.gr>=q.gr));
    	return t;
	}
