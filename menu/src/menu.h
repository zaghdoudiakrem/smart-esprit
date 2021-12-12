#include <gtk/gtk.h>
int m,k;
typedef struct
{
	int jour;
	int mois;
	int annee;
}Date;

typedef struct
{
char id[20];
Date date;
char type[20];
char entree[20];
char plat_principal[20];
char dessert[20];
char regime[40];
char choix[100];
}Menu;


void ajouter_repas(Menu repas);
void modifier(Menu repas,char *fichier);
void afficher_repas(GtkTreeView *l);
void supprimer_repas(char id[]);
Menu rechercher_repas(char id[]);


