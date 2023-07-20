	#include<stdio.h>
	#include<stdlib.h>
	#include<math.h>
	
	int G_primos(FILE *arch,long unsigned int n);

	
	int main()
	{
		FILE *arch;
		long unsigned int n;
		arch=fopen("primos.txt","w+");
		printf("Introduzca un numero, y se creara en un archivo todos los numeros primos\nhasta ese numero: ");
		scanf("%ul",&n);
		G_primos(arch,n);
		fclose(arch);
		system("pause");
		return 0;
	}
	
	int G_primos(FILE *arch,long unsigned int n)
	{
		int i,j;
		long unsigned int *lis;
		lis=(long unsigned int*)malloc(n*sizeof(long unsigned int));
		for(i=0,j=0;i<n-1;i++,j++) lis[i]=2+j;
		for(i=0;i<sqrt(n);i++)if(lis[i]!=0)for(j=0;j<n;j++) if((lis[j]/lis[i]!=1)&&(lis[j]%lis[i]==0)&&(lis[j]!=0)) lis[j]=0;  
		for(i=0;i<n;i++) if(lis[i])fprintf(arch,"%d\n",lis[i]);
		return 0;
	}
	
