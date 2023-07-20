	#include<stdio.h>
	#include<stdlib.h>
	int comp_p(int n,FILE *arch);
	int crea_zp(int a,int w);
	int suma_zp(int a,int b,int w);
	int resta_zp(int a,int b,int w);
	int multi_zp(int a,int b,int w);
	int divide_zp(int a,int b,int w);
	int inv_zp(int a,int w);
	
	typedef struct Polinomios
	{
		int gr,*p;		
	}P;
	int crea_espacio_Zp(P *a);
	P Lee_P_Zp(P a,int w);
	int escribe_P(P q);
	P Suma_P_Zp(P t,P q,int w);
	P Resta_p(P t,P q,int w);
	P multiplica_p(P t,P q,int w);
	P mono_p(P t,int q,int g,int w);
	int poli_cero(P t);
	P divide_p(P t,P q,P *res,int w);
	P mcd_p(P t,P q,P *res,int w);
	int main()
	{
		FILE *arch;
		int p;
		P a,b,c,res;
		arch=fopen("primos.txt","r");
		if((arch=fopen("primos.txt","r+"))==NULL)
		{
			printf("error al abrir y leer el archivo");
			return -1;
		}
		printf("El siguiente programa va a realizar operaciones modulares con\nmodulos primos: ");
		scanf("%d",&p);
		p=comp_p(p,arch);
			if(p)
			{
				crea_espacio_Zp(&a);				
				a=Lee_P_Zp(a,p);
				printf("El polinomio es:\n");
				escribe_P(a);
				crea_espacio_Zp(&b);
				b=Lee_P_Zp(b,p);
				printf("El polinomio es:\n");
				escribe_P(b);
				c=Suma_P_Zp(a,b,p);
				escribe_P(c);
				free(c.p);
				c=Resta_p(a,b,p);
				printf("\nLa resta es: ");
				escribe_P(c);
				free(c.p);
				c=multiplica_p(a,b,p);
				escribe_P(c);
				free(c.p);
				printf("\nEl cociente de la division es: ");
				c=divide_p(a,b,&res,p);
				escribe_P(c);
				printf("\nEl residuo de la division es: ");
     			escribe_P(res);
     			free(c.p);
     			c=mcd_p(a,b,&res,p);
     			printf("\nEl mcd es: ");
     			escribe_P(c);
			}
		free(a.p);
		free(b.p);
		free(c.p);
		free(res.p);	
		printf("\nFIN DEL PRIGRAMA\n");
		system("pause");
		return 0;	
	}
	//Definicion de una funciones para Zp
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
		int i,r=1;
		for(i=0;i<p-2;i++) r*=a;
		return crea_zp(r,p);		
	}
	int divide_zp(int a,int b,int p)
	{
		return multi_zp(a,inv_zp(b,p),p);
	}
	//Definicion de funciones para polinomios
	int crea_espacio_Zp(P *a)
	{
		printf("Teclee el grado del polinomio: ");
		scanf("%d",&a->gr);
		a->p=(int*)malloc((a->gr+1)*sizeof(int));
		if((a->p=(int*)malloc((a->gr+1)*sizeof(int)))==NULL) return -1;
		return 0;
	}
	P Lee_P_Zp(P a,int w)
	{
		int i;
		for(i=a.gr;i>=0;i--)
		{
			printf("Teclee el coeficiente de grado %d: ",i);
			scanf("%d",&a.p[i]);
			a.p[i]=crea_zp(a.p[i],w);
		}
		return a;
	}
	int escribe_P(P q)
	{
		int i;    
		if(poli_cero(q))
		{
			if(q.p[0]==0)printf("%d",0);
			else printf("%d",q.p[0]);
			return 0;
		}
		for(i=q.gr;i>=0;i--)
		{
			if(q.p[i]!=0&&q.gr>=0)
			{
				if(i!=0)
				{
					if(q.p[i]!=1)printf("%+dX^%d ",q.p[i],i);
					else if(i==q.gr)printf("X^%d",i);
					else printf("+X^%d",i);
				}
				else printf("%+d",q.p[i]);
			}
		}
		printf("\n");        
        return 0;
	}
	P Suma_P_Zp(P t,P q,int w)
	{
		P r;
        int max,min,i;
		max=(t.gr+q.gr+(abs(t.gr-q.gr)))/2;
		min=(t.gr+q.gr-(abs(t.gr-q.gr)))/2;
		r.gr=max;
		r.p=(int*)malloc((r.gr+1)*sizeof(int));
		if(r.p==NULL)return t;
		for(i=0;r.gr>=i;i++)
		{
			if(i<=min) r.p[i]=suma_zp(t.p[i],q.p[i],w);
			else
			{
				if(t.gr==max) r.p[i]=t.p[i];
				if(q.gr==max) r.p[i]=q.p[i];
			}	
		}
		printf("\nLa suma es: ");
		return r;         
	}
	P Resta_p(P t,P q,int w)
	{
		P r;
      	int max,min,i;
		max=(t.gr+q.gr+(abs(t.gr-q.gr)))/2;
		min=(t.gr+q.gr-(abs(t.gr-q.gr)))/2;
		r.gr=max;
		r.p=(int*)malloc((r.gr+1)*sizeof(int));
		if(r.p==NULL)return t;
		for(i=0;r.gr>=i;i++)
		{
			if(i<=min) r.p[i]=t.p[i]-q.p[i];
			else
			{
				if(t.gr==max) r.p[i]=t.p[i];
				if(q.gr==max) r.p[i]=-q.p[i];
			}	
		}
		while(r.gr>=0&&r.p[r.gr]==0.0)r.gr--;
		return r;            
	}
	P multiplica_p(P t,P q,int w)
	{
	   P r;
       int i,j,aux;    
       r.gr=t.gr+q.gr;          
       r.p=(int*)malloc((r.gr+1)*sizeof(int));
       if(r.p==NULL) return t;
       for(i=0;i<=r.gr;i++)r.p[i]=0;
       for(i=0;i<=t.gr;i++)for(j=0;j<=q.gr;j++)//r.p[i+j]+=t.p[i]*q.p[j];
       {
       		aux=multi_zp(t.p[i],q.p[j],w);
       		r.p[i+j]=suma_zp(r.p[i+j],aux,w);
	   }
       printf("\nEl producto es: ");
       return r;
	}
	P mono_p(P t,int q,int g,int w)
	{
		P r;
    	int i;
    	r.gr=t.gr+g;
    	r.p=(int*)malloc((r.gr+1)*sizeof(int));
    	for(i=0;i<=r.gr;i++)r.p[i]=0;
		for(i=g;i<=r.gr;i++)r.p[i]=multi_zp(q,t.p[i-g],w); //r.p[i]=q*t.p[i-g];
    	return r;
	}
	int poli_cero(P t)
    {
    	return t.gr<0;
    }
    P divide_p(P t,P q,P *res,int w)
    {
    	P aux,c;
    	int grad,i;
    	if (t.gr<q.gr)
		{
    		c.gr=-1;
    		*res = t;
    		return c;
    	}
		c.gr=t.gr-q.gr;
		c.p=(int*)malloc((c.gr+1)*sizeof(int));
		for(i=0;i<=c.gr;i++)c.p[i]=0;
		do
		{
			grad=t.gr-q.gr;
			c.p[grad]=divide_zp(t.p[t.gr],q.p[q.gr],w);//t.p[t.gr]/q.p[q.gr];
			aux=mono_p(q,c.p[grad],grad,w);	
			t=Resta_p(t,aux,w);
			*res=t;
		}while(!poli_cero(*res)&&(t.gr>=q.gr));				
		return c;
	}
	P mcd_p(P t,P q,P *res,int w)
	{
		P mcd,aux;
    	int i;
    	if(poli_cero(*res)) return *res;    	
		mcd=*res;
		do
    	{
    		t=q;
    		q=mcd;
    		aux=divide_p(t,q,&mcd,w);  		
		}while(!poli_cero(mcd)&&(t.gr>=q.gr));
    	return mcd;
	}
