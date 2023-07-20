	#include<stdio.h>
	#include<stdlib.h>
	#include "poli_C.h"
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
	 	if(a.re==0&&a.im==0)printf("%lg ",a.re);	
		if((a.re==0)&&(a.im!=0))printf("%+lgi ",a.im);
		if((a.im==0)&&(a.re!=0))printf("%lg ",a.re);
	 	if((a.re!=0)&&(a.im!=0)) printf("%lg%+lgi ",a.re,a.im);
	 	return 0;
	 }
	 int escribeC_A(C a,FILE *arch)
	 {
	 	if(a.re==0&&a.im==0)fprintf(arch,"%lg",a.re);	
		if((a.re==0)&&(a.im!=0))fprintf(arch,"%+lgi ",a.im);
		if((a.im==0)&&(a.re!=0))fprintf(arch,"%lg",a.re);
	 	if((a.re!=0)&&(a.im!=0))fprintf(arch,"%lg%+lgi",a.re,a.im);
	 	return 0;
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
	  C pot_k_C(C a,int k)
	  {
	  	int i;
	  	C r;
	  	r.re=1;
	  	r.im=0;
	  	for(i=0;i<k;i++) r=MultiC(r,a);
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
	  
	  int crea_espacio(P *q)
    {
        printf("\nPor favor teclee el grado del polinomio: ");
        scanf("%d",&q->gr);
        q->p=(C*)malloc((q->gr+1)*sizeof(C));
        if(q->p==NULL) return -1;
        return 0;
    }
    P lee_P(P q)
    {             
     int i;            
     for(i=q.gr;i>=0;i--)
		{
			printf("Teclee el valor del coeficiente de grado %d:\n",i);
			q.p[i]=leeC();
		}            
     return q;        
    }
    P lee_P_A(FILE *arch)
    {
    	P r;
    	int i;
    	fscanf(arch,"%d",&r.gr);
    	r.p=(C*)malloc((r.gr+1)*sizeof(C));
        if(r.p==NULL) return r;
        for(i=r.gr;i>=0;i--)fscanf(arch,"%lg%*c%lg",&r.p[i].re,&r.p[i].im);
        return r;
	}
    int escribe_p(P q)
    {
        int i;    
		if(q.gr==0)
		{
			escribeC(q.p[0]);
			return 0;
		}
		for(i=q.gr;i>=0;i--)
		{
			if(i==q.gr)
			{
				if(q.p[i].re==1&&q.p[i].im==0) printf("X^%d",i);				
				if(!(q.p[i].re==1&&q.p[i].im==0))//printf("%+lgX^%d ",q.p[i],i);
					{
						printf("(");
						escribeC(q.p[i]);
						printf(")");
						printf("X^%d",i);
					}										
			}
			if(i!=0&&i!=q.gr)
				{
					
					if(!(q.p[i].re==1&&q.p[i].im==0))//printf("%+lgX^%d ",q.p[i],i);
					{
						printf("+(");
						escribeC(q.p[i]);
						printf(")");
						printf("X^%d",i);						
					}
					else printf("+X^%d",i);
				}
			if(i==0)
			  {
			  	  printf("+(");
				  escribeC(q.p[i]);
				  printf(")");
			  }			
		}
        return 0;        
    }
    int escribe_P_A(FILE *arch, P q)
    {
    	int i;    
		if(q.gr==0)
		{
			escribeC_A(q.p[0],arch);
			return 0;
		}
		for(i=q.gr;i>=0;i--)
		{
			if(i==q.gr)
			{
				if(q.p[i].re==1&&q.p[i].im==0) fprintf(arch,"X^%d",i);				
				if(!(q.p[i].re==1&&q.p[i].im==0))//printf("%+lgX^%d ",q.p[i],i);
					{
						fprintf(arch,"(");
						escribeC_A(q.p[i],arch);
						fprintf(arch,")");
						fprintf(arch,"X^%d",i);
					}										
			}
			if(i!=0&&i!=q.gr)
				{					
					if(!(q.p[i].re==1&&q.p[i].im==0))//printf("%+lgX^%d ",q.p[i],i);
					{
						fprintf(arch,"+(");
						escribeC_A(q.p[i],arch);
						fprintf(arch,")");
						fprintf(arch,"X^%d",i);						
					}
					else fprintf(arch,"+X^%d",i);
				}
			if(i==0)
			  {
			  	  fprintf(arch,"+(");
				  escribeC_A(q.p[i],arch);
				  fprintf(arch,")");
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
	  r.p=(C*)malloc((r.gr+1)*sizeof(C));
	  if(r.p==NULL)return t;
		for(i=0;r.gr>=i;i++)
		{
			if(i<=min) r.p[i]=SumC(t.p[i],q.p[i]);
			else
			{
				if(t.gr==max) r.p[i]=t.p[i];
				if(q.gr==max) r.p[i]=q.p[i];
			}	
		}
		while(r.gr>=0 && C_Cero(r.p[r.gr])) r.gr--;
		return r;           
    }
    P Resta_p(P t,P q)
    {
       P r;
      	int max,min,i;
		max=(t.gr+q.gr+(abs(t.gr-q.gr)))/2;
		min=(t.gr+q.gr-(abs(t.gr-q.gr)))/2;
		r.gr=max;
		r.p=(C*)malloc((r.gr+1)*sizeof(C));
		if(r.p==NULL)return t;
		for(i=0;r.gr>=i;i++)
		{
			if(i<=min) r.p[i]=DifC(t.p[i],q.p[i]);
			else
			{
				if(t.gr==max) r.p[i]=t.p[i];
				if(q.gr==max) r.p[i]=Multi_esc(q.p[i],-1);
			}	
		}
		while(r.gr>=0 &&C_Cero(r.p[r.gr])) r.gr--;
		return r;              
    }
     P multiplica_p(P t,P q)
    {
       P r;
       int i,j,k,max,min;
       max=(t.gr+q.gr+(abs(t.gr-q.gr)))/2;
       min=(t.gr+q.gr-(abs(t.gr-q.gr)))/2;    
       r.gr=t.gr+q.gr;          
       r.p=(C*)malloc((r.gr+1)*sizeof(C));
       if(r.p==NULL) return t;
       for(i=0;i<=r.gr;i++)r.p[i]=CeroC();
       for(i=0;i<=t.gr;i++)for(j=0;j<=q.gr;j++)r.p[i+j]=SumC(r.p[i+j],MultiC(t.p[i],q.p[j])); //r.p[i+j]+=t.p[i]*q.p[j];
       return r;     
    }
     P mono_p(P t,C q,int g)
    {
    	P r;
    	int i;
    	r.gr=t.gr+g;
    	r.p=(C*)malloc((r.gr+1)*sizeof(C));
    	for(i=g;i<=r.gr;i++)r.p[i]=MultiC(q,t.p[i-g]);
    	return r;
    }
    int poli_cero(P t)
    {
    	return t.gr<0;
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
		   c.p=(C*)malloc((c.gr+1)*sizeof(C));
             do
		     {
			  grad=t.gr-q.gr;
			  c.p[grad]=DivC(t.p[t.gr],q.p[q.gr]);
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
        if(!poli_cero(res))
        {
          do
          {
              t=q;
              q=res;
              aux=divide_p(t,q,&res);           
          }while(!poli_cero(res)&&(t.gr>=q.gr));  
        }
        return t;
    }
    C val_p(P t,C a)
    {
    	C aux,r;
    	int i;
    	r.re=0;
    	r.im=0;
    	for(i=t.gr;i>=0;i--)
    	{
    		aux=pot_k_C(a,i);
    		r=SumC(r,MultiC(t.p[i],aux));
		}
		return r;
	}
