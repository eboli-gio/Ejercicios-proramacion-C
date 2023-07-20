#include<stdio.h>
#include<stdlib.h>
#include<string.h>
	typedef struct agenda
	{
		char nombre[50],apellido[15],apellido2[15];
		int ed;
		char tel[15],cel[15];
		char edo_civil[20];
		char sexo,lada[10];
		int cp;	
	}A;//estructura
	//Funciones para la agenda
	A Agenda(A a);
	//Funciones para archivos
	int escribe_A(FILE *arch,A a);
	int busca_A(FILE *arch,char a[]);
	int borrar_A(FILE *arch,char a[]);
	int mostrar_A(FILE *arch);	
	int main()
	{
		A per,sh;
		char bus[120];
		int sel=0,i=0;
		int p,q;
		FILE *arch1;
		arch1=fopen("datos_agenda.bin","ab+");
		do
		{
			printf("Teclee la opcion que quiera utilizar:\n0)Ingresar un nuevo contacto\n1)Buscar y mostrar en pantalla el contacto buscado\n2)Borrar a un usuario del registro\n3)Mostrar todos los datos de la agenda\n");
			scanf("%d",&sel);
			if(sel==0)
			{
				do
				{
					per=Agenda(per);
					escribe_A(arch1,per);
					printf("\nSi quiere seguir ingrsando datos teclee 0 sino teclee\ncualquier otro numero");
					scanf("%d",&sel);	
				}while(sel);
			}
			if(sel==1)
			{
				do
				{
					printf("\nContactos en la agenda:\n");
					fseek(arch1,0L,SEEK_END);
					p=ftell(arch1);
					fseek(arch1,0L,SEEK_SET);
					q=ftell(arch1);
					while(!(feof(arch1))&&q!=p)
					{
						fread(&per,sizeof(A),1,arch1);
						printf("%s %s %s\n",per.nombre,per.apellido,per.apellido2);
						q=ftell(arch1);	
					}
					printf("Teclee el nombre de la persona que desee buscar:");					
					scanf("%*c%[^\n]%*c",bus);
					fseek(arch1,0L,SEEK_SET);
					busca_A(arch1,bus);
					printf("Si quiere salir de la opcion teclee cero, si no\nteclee cualquier otro numero:");
					scanf("%d",&sel);		
				}while(sel);
			}
			if(sel==2)
			{
				do
				{
					printf("\nContactos en la agenda:\n");
					fseek(arch1,0L,SEEK_END);
					p=ftell(arch1);
					fseek(arch1,0L,SEEK_SET);
					q=ftell(arch1);
					while(!(feof(arch1))&&q!=p)
					{
						fread(&per,sizeof(A),1,arch1);
						printf("%s %s %s\n",per.nombre,per.apellido,per.apellido2);
						q=ftell(arch1);	
					}
					printf("Teclee el nombre de la persona que desee borrar:");
					scanf("%*c%[^\n]%*c",bus);
					fseek(arch1,0L,SEEK_SET);
					borrar_A(arch1,bus);
					fseek(arch1,0L,SEEK_SET);
					printf("Si quiere salir de la opcion teclee cero, si no\nteclee cualquier otro numero:");
					scanf("%d",&sel);
				}while(sel);					
			}
			if(sel==3)
			{
				printf("Los datos de la agenda son:\n");
				mostrar_A(arch1);
			}
		printf("Si quiere salir de la opcion teclee cero, si no\nteclee cualquier otro numero:");
		scanf("%d",&sel);
		}while(sel);
		
		fclose(arch1);
		system("pause");
		return 0;
	}
	A Agenda(A a)
	{
			fflush(stdin); 
			printf("Nombre:");
			scanf("%[^\n]%*c",a.nombre);
			printf("Primer apellido:");
			scanf("%[^\n]%*c",a.apellido);
			printf("Segundo apellido:");
			scanf("%[^\n]%*c",a.apellido2);
			printf("Edad:");
			scanf("%d",&a.ed);
			printf("Lada:");
			scanf("%*c%[^\n]%*c",a.lada);
			printf("Telefono fijo:");
			scanf("%[^\n]%*c",a.tel);
			printf("Telefono celular:");
			scanf("%[^\n]%*c",a.cel);
			printf("Estado civil:");
			scanf("%[^\n]%*c",a.edo_civil);
			printf("Sexo(M=masculino,F=Femenino):");
			scanf("%c%*c",&a.sexo);
			printf("Codigo postal:");
			scanf("%d%*c",&a.cp);
			return a;
	}
	//Definicion de funciones de archivos
	int escribe_A(FILE *arch,A a)
	{
		int l;
		fseek(arch,1L,SEEK_END);
		fwrite(&a,1,sizeof(A),arch);
		return 0;
	}
	int busca_A(FILE *arch,char a[])//Busca un dato en archivo y lo escribe
	{
		A sea;
		int i=0;
		while(!feof(arch)&&i==0)
		{
			fread(&sea,1,sizeof(A),arch);
			if(strstr(a,sea.nombre)!=NULL)
			{
				printf("Nombre:%s\nPrimer apellido:%s\nSegundo apellido:%s\n",sea.nombre,sea.apellido,sea.apellido2);
				printf("Edad:%d\nTelefono fijo:%s-%s\nTelefono celular:%s-%s\n",sea.ed,sea.lada,sea.tel,sea.lada,sea.cel);
				printf("Estado civil:%s\nSexo:%c\nCodigo postal:%d",sea.edo_civil,sea.sexo,sea.cp);
				i++;
			}
		}
		if(i==0) printf("No existe en el registro");
		printf("\n");
		return 0;		
	}
	int borrar_A(FILE *arch,char a[])
	{
		FILE *arch2;
		A aux;
		arch2=fopen("datos_aux.bin","wb+");
		while(!(feof(arch)))
		{
			fread(&aux,sizeof(A),1,arch);
			if(strstr(a,aux.nombre)==NULL)
				{
					fwrite(&aux,1,sizeof(A),arch2);
				}
		}
		fclose(arch);
		arch=fopen("datos_agenda.bin","wb+");
		fseek(arch2,0L,SEEK_SET);
		while(!feof(arch2))
		{
			fread(&aux,sizeof(A),1,arch2);
			fwrite(&aux,sizeof(A),1,arch);
		}
		fclose(arch2);
		return 0;
	}
	int mostrar_A(FILE *arch)
	{
		int p,q;
		A sea;
		fseek(arch,0L,SEEK_END);
		p=ftell(arch);
		fseek(arch,0L,SEEK_SET);
		q=ftell(arch);
		while(!(feof(arch))&&q!=p)
		{
			fread(&sea,sizeof(A),1,arch);
			printf("Nombre:%s\nPrimer apellido:%s\nSegundo apellido:%s\n",sea.nombre,sea.apellido,sea.apellido2);
			printf("Edad:%d\nTelefono fijo:%s-%s\nTelefono celular:%s-%s\n",sea.ed,sea.lada,sea.tel,sea.lada,sea.cel);
			printf("Estado civil:%s\nSexo:%c\nCodigo postal:%d\n\n\n",sea.edo_civil,sea.sexo,sea.cp);
			q=ftell(arch);	
		}
		return 0;
	}
