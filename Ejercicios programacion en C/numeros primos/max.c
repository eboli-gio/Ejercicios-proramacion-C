
	#include<stdio.h>
	#include<stdlib.h>
	#include<math.h>
	
	#define MAX(A,B) (A+B+abs(A-B))/2
	#define MIN(A,B) (A+B-abs(A-B))/2 
	 int main()
	 {
	 	int a,b;
	 	printf("teclee 2 numeros: ");
	 	scanf("%d%d",&a,&b);
	 	printf("El maximo es:%d\nEl minimo es:%d\n",MAX(a,b),MIN(a,b));
		system("pause");
	 	return 0;
	 }
