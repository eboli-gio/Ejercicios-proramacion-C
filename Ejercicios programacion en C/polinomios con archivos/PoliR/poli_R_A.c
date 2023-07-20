	#include<stdio.h>
    #include<stdlib.h>
    #include<math.h>
    
    
    typedef struct polinomios
    {
     int gr;
     double *p; 
    }P;       
    
    int crea_espacio(P *q);
    P lee_P(P q);
    P lee_P_A(FILE *arch);
    int escribe_(P q);
    int escribe_P_A(P q,FILE *arch);
    P Suma_p(P t, P q);
    P Resta_p(P t,P q);
    P multiplica_p(P t,P q);
    P mono_p(P t,double q,int g);
    int poli_cero(P t);
    P divide_p(P t,P q,P *res);
    P mcd_p(P t,P q,P res);
    
    int main()
    {
    	FILE *arch,*arch1;
		P t,q,r,res;
		arch=fopen("polinomios.txt","r");
		if((arch=fopen("polinomios.txt","r"))==NULL)
		{
			printf("Error");
			return 0;
		}
		arch1=fopen("resultados.txt","w");
		if((arch1=fopen("resultados.txt","w"))==NULL)
		{
			printf("error");
			return 0;
		}
		t=lee_P_A(arch);
		q=lee_P_A(arch);
		fprintf(arch1,"El polinomio es:");
		escribe_P_A(t,arch1);
		fprintf(arch1,"El polinomio es:");
		escribe_P_A(q,arch1);
		r=Suma_p(t,q);
		fprintf(arch1,"La suma de los polinomios es:");
		escribe_P_A(r,arch1);
		r=Resta_p(t,q);
		fprintf(arch1,"La resta de los polinomios es:");
		escribe_P_A(r,arch1);
		r=multiplica_p(t,q);
		fprintf(arch1,"La multiplicacion de los polinomios es:");
		escribe_P_A(r,arch1);
		r=divide_p(t,q,&res);
		fprintf(arch1,"La division de los polinomios es:");
		escribe_P_A(r,arch1);
		fprintf(arch1,"El residuo de la division de los polinomios es:");
		escribe_P_A(res,arch1);
		r=mcd_p(t,q,res);
		fprintf(arch1,"El maximo comun divisor de los polinomios es:");
		escribe_P_A(r,arch1);
		free(res.p);	
		free(t.p);
		free(q.p);
		free(r.p);
		fclose(arch);
		fclose(arch1);
		system("pause");
		return 0;	
	}
	
	int crea_espacio(P *q)
    {
        printf("\nPor favor teclee el grado del polinomio: ");
        scanf("%d",&q->gr);
        q->p=(double*)malloc((q->gr+1)*sizeof(double));
        if(q->p==NULL) return -1;
        return 0;
    }
    P lee_P(P q)
    {             
     int i;            
     for(i=q.gr;i>=0;i--)
		{
			printf("Teclee el valor del coeficiente de grado %d:",i);
			scanf("%lg",&q.p[i]);
		}            
         return q;        
    }
    P lee_P_A(FILE *arch)
    {
    	int i;
    	P r;
    	fscanf(arch,"%d",&r.gr);
    	r.p=(double*)malloc((r.gr+1)*sizeof(double));
        if(r.p==NULL) return r;
		for(i=r.gr;i>=0;i--)fscanf(arch,"%lg",&r.p[i]);
		return r;
	}
    int escribe_p(P q)
    {
        int i;    
        printf("El polinomio es:\n");
        if(q.gr==0)
        {
        	printf("%lg",q.p[0]);
        	return 0;
		}
		for(i=q.gr;i>=0;i--)
		{
			if(q.p[i]!=0&&q.gr>0)
			{
				if(i!=0)
				{
					if(q.p[i]!=1)printf("%+lgX^%d ",q.p[i],i);
					else if(i==q.gr)printf("X^%d",i);
					else printf("+X^%d",i);
				}
				else printf("%+lg",q.p[i]);
			}
		}        
        return 0;        
    }
    int escribe_P_A(P q,FILE *arch)
    {
    	int i;
    	if(poli_cero(q))
        {
        	fprintf(arch,"%lg\n",q.p[0]);
        	return 0;
		}
		for(i=q.gr;i>=0;i--)
		{
			if(q.p[i]!=0&&q.gr>0)
			{
				if(i!=0)
				{
					if(q.p[i]!=1)fprintf(arch,"%+lgX^%d ",q.p[i],i);
					else if(i==q.gr)fprintf(arch,"X^%d",i);
					else fprintf(arch,"+X^%d",i);
				}
				else fprintf(arch,"%+lg",q.p[i]);
			}
		}
		fprintf(arch,"\n"); 
	 return 0;       
	}
    P Suma_p(P t, P q)
    {
      P r;
      int max,min,i;
		max=(t.gr+q.gr+(abs(t.gr-q.gr)))/2;
		min=(t.gr+q.gr-(abs(t.gr-q.gr)))/2;
		r.gr=max;
		r.p=(double*)malloc((r.gr+1)*sizeof(double));
		if(r.p==NULL)return t;
		for(i=0;r.gr>=i;i++)
		{
			if(i<=min) r.p[i]=t.p[i]+q.p[i];
			else
			{
				if(t.gr==max) r.p[i]=t.p[i];
				if(q.gr==max) r.p[i]=q.p[i];
			}	
		}
		return r;           
    } 
    P Resta_p(P t,P q)
    {
       	P r;
      	int max,min,i;
		max=(t.gr+q.gr+(abs(t.gr-q.gr)))/2;
		min=(t.gr+q.gr-(abs(t.gr-q.gr)))/2;
		r.gr=max;
		r.p=(double*)malloc((r.gr+1)*sizeof(double));
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
    P multiplica_p(P t,P q)
    {
       P r;
       int i,j,k,max,min;
       max=(t.gr+q.gr+(abs(t.gr-q.gr)))/2;
       min=(t.gr+q.gr-(abs(t.gr-q.gr)))/2;    
       r.gr=t.gr+q.gr;          
       r.p=(double*)malloc((r.gr+1)*sizeof(double));
       if(r.p==NULL) return t;
       for(i=0;i<=r.gr;i++)r.p[i]=0;
       for(i=0;i<=t.gr;i++)for(j=0;j<=q.gr;j++)r.p[i+j]+=t.p[i]*q.p[j];
       return r;     
    }
    P mono_p(P t,double q,int g)
    {
    	P r;
    	int i;
    	r.gr=t.gr+g;
    	r.p=(double *)malloc((r.gr+1)*sizeof(double));
    	for(i=0;i<=r.gr;i++)r.p[i]=0;
		for(i=g;i<=r.gr;i++)r.p[i]=q*t.p[i-g];
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
    		*res=t;
    		return c;
    	}
		c.gr=t.gr-q.gr;
		c.p=(double*)malloc((c.gr+1)*sizeof(double));
		for(i=0;i<=c.gr;i++)c.p[i]=0;
		do
		{
			grad=t.gr-q.gr;
			c.p[grad]=t.p[t.gr]/q.p[q.gr];
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
    	return q;
	}
