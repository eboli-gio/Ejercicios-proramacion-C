	#include<stdio.h>
	#include<stdlib.h>
	
	int comp_p(int n,FILE *arch);
	int crea_zp(int a,int p);
	int suma_zp(int a,int b,int p);
	int resta_zp(int a,int b,int p);
	int multi_zp(int a,int b,int p);
	int divide_zp(int a,int b,int p);
	int inv_zp(int a,int p);
	int main()
	{
		int a,b,c,p,sel;
		FILE *arch;
		arch=fopen("primos.txt","r+");
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
			printf("Teclee las siguientes opciones, para realizar las operaciones que desee realizar\n1)Suma y resta de dos numeros modulo %d\n2)multiplicacion de dos numeros modulo %d\n3)El inverso multiplicativo de un numero modulo %d\n4) la division de dos numeros modulo %d\n",p,p,p,p);
			scanf("%d",&sel);
			switch(sel)
			{
				case 1:printf("Teclee un numero:");
					   scanf("%d",&a);
					   printf("Teclee un numero:");
					   scanf("%d",&b);
					   c=suma_zp(a,b,p);
					   printf("La suma es:%d\n",c);
					   c=resta_zp(a,b,p);
					   printf("La resta es:%d\n",c);
				break;
				case 2:printf("Teclee un numero:");
					   scanf("%d",&a);
					   printf("Teclee un numero:");
					   scanf("%d",&b);
					   c=multi_zp(a,b,p);
					   printf("La multiplicacion es:%d\n",c);
				break;
				case 3:printf("Teclee un numero:");
					   scanf("%d",&a);
					   c=inv_zp(a,p);
					   printf("El inverso de %d es:%d\n",a,c);
				break;
				case 4:printf("Teclee un numero:");
					   scanf("%d",&a);
					   printf("Teclee un numero:");
					   scanf("%d",&b);
					   c=divide_zp(a,b,p);
					   printf("La division es:%d\n",c);
				break;
			}
		}
		system("pause");
		return 0;
	}
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
	
	
	
