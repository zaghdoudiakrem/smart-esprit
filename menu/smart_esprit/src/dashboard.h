#include<gtk/gtk.h>

typedef struct cap
{
    int jour;
    int heure;
    int num_capteur ;
    float valeur;
}defectueux;

typedef struct{
	int jour;
	int mois;
	int annee;
}date;
typedef struct{
	char id[20];
	char cin[20];
	char nom[20];
	char prenom[20];
	int type;
	char text_reclamation[50];
	date d;
	int sexe;
	int education;
	
}reclamation;

typedef struct alerte
{
int jour,heure,numCap,valeur;
}alerte;

int capteur_defc(char fichCap[],int capdef[],int maxtmp,int mintmp);
int serviceleplusreclame();
//void alertesMVTFUMEE(alerte alertemvt[],alerte alertefumee[],char *fichmvt,char *fichfumee,int *nbaf,int *nbam)
