#include "fct8.h"



void main()
{
	FILE *fisier;
	char c[30];
	int nr=0, j, score=0, nr_coliziuni=0;
	Node v[256], *nodul;
	fisier=fopen("words_alpha.txt","r");
	citireverif(fisier);
	///while(!feof(fisier))
	///{c=fgetc(fisier);
	/// printf("%c",c);
	///}
	///citirea a avut loc cu succes
	
	while(!feof(fisier))
	{
		fgets(c,30,fisier);
		populare(sum_hash(c),v,c);
		printf("%d",sum_hash(c));
	}
	nodul=&(v[2]);
	printf("Aproape de second while");
	while(nodul->next!=NULL && nr<20)
	{printf("%s",nodul->val);
	 nr++;
	 nodul=nodul->next;
	}
	///cu acest while afisam primele 20 cuv de pe intrarea a treia
	fclose(fisier);
	for(j=0;j<(256-1);j++)
	{
		score+=(nr_elem(v[j])*(nr_elem(v[j])+1)/2)/((370105/(2*256))*(370105+2*256-1));
		nr_coliziuni+=nr_elem(v[j])-1;
	}
	printf("score: %d; procentaj coliziuni: %d",score,256/nr_coliziuni);
	
	return 0;
	
}
