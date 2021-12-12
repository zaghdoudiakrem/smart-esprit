#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include "dashboard.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<gtk/gtk.h>


////capteur defectueux
int capteur_defc(char fichCap[],int capdef[],int maxtmp,int mintmp)
{
    defectueux c;
    int i=0;
    int n=0;
    int test=0;
    FILE *f1;
    FILE *f2;

    f1=fopen(fichCap,"r");
    f2=fopen("capteur_defectueux.txt","w+");
    while (fscanf(f1,"%d %d %d %f\n",&c.jour,&c.heure,&c.num_capteur,&c.valeur)!=EOF)
{


    if ((c.valeur<mintmp) || (c.valeur>maxtmp))
        {
		for(i=0;i<n;i++)
		{if (capdef[i]==c.num_capteur)
			{test=1;
			break;}
		}
			if(test==0)
            {capdef[n]=c.num_capteur;
             n++;}

		}
        test=0;
}
for(i=0;i<n;i++)
fprintf(f2,"%d\n",capdef[i]);

fclose(f2);
fclose(f1);

return(n);
}

////service le plus reclamee

int serviceleplusreclame()
{
	int s=0,s1=0;
	FILE *f;
	reclamation r;
	f=fopen("reclamation.txt","r");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %d %s %d %d %d %d %d\n",r.id,r.cin,r.nom,r.prenom,&r.type,r.text_reclamation,&r.d.jour,&r.d.mois,&r.d.annee,&r.sexe,&r.education)!=EOF)
		{
			if(r.type==0)
				s++;
			else
				s1++;
		}
	}
	if(s>s1)
		return 0;
	else
		return 1;
		
}

////liste des alertes
/*
void alertesMVTFUMEE(alerte alertemvt[], alerte alertefumee[],char *fichmvt,char *fichfumee,int *nbaf,int *nbam)
{
nbaf=0;
nbam=0;
FILE *f=NULL;
FILE *g=NULL;

f=fopen("fumee.txt","r");

while(fscanf(f,"%d %d %d %d\n",alerte.jour,alerte.heure,alerte.numCap,alerte.valeur)!=EOF)
{
if(alerte.valeur==1)
{
	while((alerte.heure<7)&&(alerte.heure>0))
	{
		if(alerte.numCap!=alertefumee[i].numCap)
		{	
			alertefumee[nbaf]=numCap;
			nbaf++;
		}
	}
}
}
fclose(f);

g=fopen("mouvement.txt","r");
while(fscanf(g,"%d %d %d %d\n",alerte.jour,alerte.heure,alerte.numCap,alerte.valeur)!=EOF)
{
if(alerte.valeur==1)
{
	while((alerte.heure<7)&&(alerte.heure>0))
	{
		if(alerte.numCap!=alertemvt[i].numCap)
		{	
			alertemvt[nbam]=numCap;
			nbam++;
		}
	}
}
}
fclose(g);

}

*/

