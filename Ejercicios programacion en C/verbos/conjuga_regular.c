	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	
	int Conjuga_ar(FILE *arch,char a[]);
	int Conjuga_er(FILE *arch,char a[]);
	int Conjuga_ir(FILE *arch,char a[]);
	char ter_s_c[5][6]={"he","has","ha","han","hemos"};
	char ter_co_p_c[5][9]={"habia","habias","habia","habian","habiamos"};
	char ter_p_c[5][9]={"hube","hubiste","hubo","hubieron","hubimos"};
	char ter_f_c[5][9]={"habre","habras","habra","habran","habremos"};
	char ter_pos_p_c[5][10]={"habria","habrias","habria","habriamos","habrian"};
	char t[5][13]={"Presente","Copreterito","Preterito","Futuro","Pospreterito"};
	char t_c[5][17]={"antepresente","antecopreterito","antepreterito","antefuturo","antepospreterito"};
	char pron[5][14]={"yo", "tu" , "el/ella", "ellos/ustedes" , "nosotros"};	
	int main()
	{
		int i,d;
		char palabra[50],aux[50];
		char a[3][3]={"ar","er","ir"};
		FILE *arch;
		printf("Escribe un verbo: ");
		scanf("%[^\n]%*c",palabra);
		strcpy(aux,palabra);
		palabra[strlen(palabra)-2]='\0';
		for(i=strlen(aux)-1;i>1;i--)
		{
			 aux[i-2]=aux[i-1];
			 aux[i-1]=aux[i];
		}
		aux[2]='\0';
	 	if(!strcmp(aux,a[0])) Conjuga_ar(arch,palabra);
		if(!strcmp(aux,a[1])) Conjuga_er(arch,palabra);
		if(!strcmp(aux,a[2])) Conjuga_ir(arch,palabra); 
		system("pause");
		return 0;
	}
	int Conjuga_ar(FILE *arch,char a[])
	{
		int i;
		char ter_c[]={"ado"};
		char ter_s[5][5]={"o","as","a","an","amos"};
		char ter_co_p[5][7]={"aba","abas","aba","aban","abamos"};
		char ter_p[5][5]={"e","aste","o","aron","amos"};
		char ter_f[5][7]={"are","aras","ara","aran","aremos"};
		char ter_pos_p[5][9]={"aria","arias","aria","arian","ariamos"};
		arch=fopen("verbos.txt","w+");
		fprintf(arch,"Tiempos simples ");
		for(i=0;i<5;i++)fprintf(arch,"           %12s",t[i]);
		fprintf(arch,"\n");
		for(i=0;i<5;i++)fprintf(arch,"%8s		%8s%s		%8s%s		%8s%s		 %8s%s		%8s%s\n",pron[i],a,ter_s[i],a,ter_co_p[i],a,ter_p[i],a,ter_f[i],a,ter_pos_p[i]);
		fprintf(arch,"\n\nTiempos compuestos");
		fprintf(arch,"      %16s",t_c[0]);
		fprintf(arch,"          %16s",t_c[1]);
		fprintf(arch,"      	  %16s",t_c[2]);
		fprintf(arch,"      	%16s",t_c[3]);
		fprintf(arch,"      		   %16s",t_c[4]);
		fprintf(arch,"\n");
		for(i=0;i<5;i++)fprintf(arch,"%8s		  %5s %s%s		  %8s %s%s		  %8s %s%s		  %8s %s%s		  %10s %s%s\n",pron[i],ter_s_c[i],a,ter_c,ter_co_p_c[i],a,ter_c,ter_p_c[i],a,ter_c,ter_f_c[i],a,ter_c,ter_pos_p_c[i],a,ter_c);
		fprintf(arch,"\n");
		fclose(arch);
		return 0;
	}
	int Conjuga_er(FILE *arch,char a[]) 
	{
		char ter_s[5][5]={"o","es","e","en","emos"};
		char ter_co_p[5][7]={"ia","ias","ia","ian","íamos"};
		char ter_p[5][6]={"i","iste","io","ieron","imos"};
		char ter_f[5][7]={"ere","eras","era","eran","eremos"};
		char ter_pos_p[5][9]={"eria","erias","eria","erian","eriamos"};
		char ter_c[]={"ido"};
		int i;
		arch=fopen("verbos.txt","w+");
		fprintf(arch,"	");
		for(i=0;i<5;i++)fprintf(arch,"		   %8s ",t[i]);
		fprintf(arch,"\n");
		for(i=0;i<5;i++)fprintf(arch,"%8s		%8s%s		%8s%s		%8s%s		%8s%s		%8s%s\n",pron[i],a,ter_s[i],a,ter_co_p[i],a,ter_p[i],a,ter_f[i],a,ter_pos_p[i]);
		fprintf(arch,"\n\nTiempos compuestos");
		fprintf(arch,"      %16s",t_c[0]);
		fprintf(arch,"          %16s",t_c[1]);
		fprintf(arch,"      	  %16s",t_c[2]);
		fprintf(arch,"      	%16s",t_c[3]);
		fprintf(arch,"      		   %16s",t_c[4]);
		fprintf(arch,"\n");
		for(i=0;i<5;i++)fprintf(arch,"%8s		  %5s %s%s		  %8s %s%s		  %8s %s%s		  %8s %s%s		  %10s %s%s\n",pron[i],ter_s_c[i],a,ter_c,ter_co_p_c[i],a,ter_c,ter_p_c[i],a,ter_c,ter_f_c[i],a,ter_c,ter_pos_p_c[i],a,ter_c);
		fprintf(arch,"\n");
		fclose(arch);
		return 0;	
	}
	int Conjuga_ir(FILE *arch,char a[])
	{
		
		char ter_s[5][5]={"o","es","e","en","imos"};
		char ter_co_p[5][7]={"ia","ias","ia","ian","íamos"};
		char ter_p[5][6]={"i","iste","io","ieron","imos"};
		char ter_f[5][7]={"ire","iras","ira","iran","iremos"};
		char ter_pos_p[5][9]={"iria","irias","iria","irian","iriamos"};
		char ter_c[]={"ido"};
		int i;
		arch=fopen("verbos.txt","w+");
		fprintf(arch,"	");
		for(i=0;i<5;i++)fprintf(arch,"		   %8s ",t[i]);
		fprintf(arch,"\n");
		for(i=0;i<5;i++)fprintf(arch,"%8s		%8s%s		%8s%s		%8s%s		%8s%s		%8s%s\n",pron[i],a,ter_s[i],a,ter_co_p[i],a,ter_p[i],a,ter_f[i],a,ter_pos_p[i]);
		fprintf(arch,"\n\nTiempos compuestos");
		fprintf(arch,"      %16s",t_c[0]);
		fprintf(arch,"          %16s",t_c[1]);
		fprintf(arch,"      	  %16s",t_c[2]);
		fprintf(arch,"      	%16s",t_c[3]);
		fprintf(arch,"      		   %16s",t_c[4]);
		fprintf(arch,"\n");
		for(i=0;i<5;i++)fprintf(arch,"%8s		  %5s %s%s		  %8s %s%s		  %8s %s%s		  %8s %s%s		  %10s %s%s\n",pron[i],ter_s_c[i],a,ter_c,ter_co_p_c[i],a,ter_c,ter_p_c[i],a,ter_c,ter_f_c[i],a,ter_c,ter_pos_p_c[i],a,ter_c);
		fprintf(arch,"\n");
		fclose(arch);
		return 0;			
	}
	
