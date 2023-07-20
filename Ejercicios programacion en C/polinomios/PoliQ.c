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
	//Funciones de operaciones con racionales
	 typedef struct polinomios
    {
     int gr;
     Q *p; 
    }P;
	int crea_espacio(P *q);
    P lee_P(P q);
    int escribe_p(P q);
    P Suma_p(P t, P q);
    P Resta_p(P t,P q);
    P multiplica_p(P t,P q);
    P mono_p(P t,Q q,int g);
    int poli_cero(P t);
    P divide_p(P t,P q,P *res);
    P mcd_p(P t,P q,P res);
	//Funciones de operaciones polinomiales
	
	int main()
	{
	P t,q,r,res;
     Q p_val;
     crea_espacio(&q);
     q=lee_P(q);
     escribe_p(q);
     crea_espacio(&t);
     t=lee_P(t);
     escribe_p(t);
     r=Suma_p(q,t);
     escribe_p(r);
     free(r.p);
     printf("\nLa resta es:\n");
     r=Resta_p(q,t);
     escribe_p(r);
     free(r.p);
     r=multiplica_p(q,t);
     escribe_p(r);
     free(r.p);
     r=divide_p(q,t,&res);
     printf("\nEl cociente de la division es:\n");
     escribe_p(r);
     printf("\nEl residuo de la division es:\n");
     escribe_p(res);
     free(r.p);
     r=mcd_p(q,t,res);
     printf("\nEl mcd de los polinomios es:\n");
     escribe_p(r);
     free(res.p);
     free(r.p);    
     free(q.p);
     free(t.p);
     system("pause");
     return 0;         
		
	system("pause");
	return 0;	
	}   
	
	//Definicion de las opercaiones racionales
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
		if(a.q==1) printf("%+d",a.p);
		else printf("%+d/%d",a.p,a.q);
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
	//Fin de la definicion de operaciones racionales
	//definicion de operaciones polinomiales
	int crea_espacio(P *q)
    {
        printf("\nPor favor teclee el grado del polinomio: ");
        scanf("%d",&q->gr);
        q->p=(Q*)malloc((q->gr+1)*sizeof(Q));
        if(q->p==NULL) return -1;
        return 0;
    }
    P lee_P(P q)
    {             
     int i;            
     for(i=q.gr;i>=0;i--)
		{
			printf("Teclee el valor del coeficiente de grado %d:\n",i);
			q.p[i]=leeQ();
		}            
     return q;        
    }
    int escribe_p(P q)
    {
        int i,j;    
        printf("\nEl polinomio es:\n");
        if(poli_cero(q))
        {
        	if(q.p[0].p==0) printf("0");
        	else escribeQ(q.p[0]);
        	return 0;
		}
		for(i=q.gr;i>=0;i--)
		{
			if(!C_CeroQ(q.p[i]))
			{
				if(i!=0)
				{
					if(!(q.p[i].p==1&&q.p[i].q==1))//printf("%+lgX^%d ",q.p[i],i);
					{
						escribeQ(q.p[i]);
						printf("X^%d",i);
					}
					else if(i==q.gr)printf("X^%d",i);
					else printf("+X^%d",i);
				}
				else escribeQ(q.p[i]); //printf("%+lg",q.p[i]);
			}
		}
        return 0;        
    }
    P Suma_p(P t, P q)
    {
      P r;
      int max,min,i;
	  max=(t.gr+q.gr+(abs(t.gr-q.gr)))/2;
	  min=(t.gr+q.gr-(abs(t.gr-q.gr)))/2;
	  r.gr=max;
	  r.p=(Q*)malloc((r.gr+1)*sizeof(Q));
	  if(r.p==NULL)return t;
		for(i=0;r.gr>=i;i++)
		{
			if(i<=min) r.p[i]=SumaQ(t.p[i],q.p[i]);
			else
			{
				if(t.gr==max) r.p[i]=t.p[i];
				if(q.gr==max) r.p[i]=q.p[i];
			}	
		}
		while(r.gr>=0 && r.p[r.gr].p==0.0) r.gr--;
		printf("\nLa suma es:\n");
		return r;           
    }
	P Resta_p(P t,P q)
    {
       P r;
      	int max,min,i;
		max=(t.gr+q.gr+(abs(t.gr-q.gr)))/2;
		min=(t.gr+q.gr-(abs(t.gr-q.gr)))/2;
		r.gr=max;
		r.p=(Q*)malloc((r.gr+1)*sizeof(Q));
		if(r.p==NULL)return t;
		for(i=0;r.gr>=i;i++)
		{
			if(i<=min) r.p[i]=RestaQ(t.p[i],q.p[i]);
			else
			{
				if(t.gr==max) r.p[i]=t.p[i];
				if(q.gr==max) r.p[i]=Multi_esc(q.p[i],-1);
			}	
		}
		while(r.gr>0 && r.p[r.gr].p==0.0) r.gr--;
		return r;              
    }
     P multiplica_p(P t,P q)
    {
       P r;
       int i,j,k,max,min;
       max=(t.gr+q.gr+(abs(t.gr-q.gr)))/2;
       min=(t.gr+q.gr-(abs(t.gr-q.gr)))/2;    
       r.gr=t.gr+q.gr;          
       r.p=(Q*)malloc((r.gr+1)*sizeof(Q));
       if(r.p==NULL) return t;
       for(i=0;i<=r.gr;i++)r.p[i]=CeroQ();
       for(i=0;i<=t.gr;i++)for(j=0;j<=q.gr;j++)r.p[i+j]=SumaQ(r.p[i+j],MultiQ(t.p[i],q.p[j])); //r.p[i+j]+=t.p[i]*q.p[j];
       printf("\nEl producto es:\n");
       return r;     
    }
    P mono_p(P t,Q q,int g)
    {
    	P r;
    	int i;
    	r.gr=t.gr+g;
    	r.p=(Q*)malloc((r.gr+1)*sizeof(Q));
    	for(i=0;i<=r.gr;i++) r.p[i]=CeroQ();
    	for(i=g;i<=r.gr;i++)r.p[i]=MultiQ(q,t.p[i-g]);
    	return r;
    }
    int poli_cero(P t)
    {
    	return t.gr<=0;
    }
    P divide_p(P t,P q,P *res)
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
		   c.p=(Q*)malloc((c.gr+1)*sizeof(Q));
		   for(i=0;i<=c.gr;i++) c.p[i]=CeroQ();
             do
		     {
			  grad=t.gr-q.gr;
			  c.p[grad]=DivQ(t.p[t.gr],q.p[q.gr]);
			  aux=mono_p(q,c.p[grad],grad);	
			  t=Resta_p(t,aux);
			  *res=t;
		      }while(!poli_cero(*res)&&(t.gr>=q.gr));
		return c;
 	}
 	P mcd_p(P t,P q,P res)
 	{
     P aux;
	 if(poli_cero(res)) return q;   
        do
        {
            t=q;
            q=res;
            aux=divide_p(t,q,&res);           
        }while(!poli_cero(res)&&(t.gr>=q.gr));  
          return t;
    }

