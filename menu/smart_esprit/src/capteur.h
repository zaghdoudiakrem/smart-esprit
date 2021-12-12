
#include<gtk/gtk.h>
typedef struct date
{
    int jour,mois,annee;
}Date;


typedef struct capteur
{
    char id[50];
    char marque[50];
    char type[50] ;
    Date date;
    char valeur[50];
}capteur;
/////pour les capteur defectueux////
typedef struct cap
{
    int jour;
    int heure;
    int num_capteur ;
    float valeur;
}defectueux;
////////////////////////////////////////
void ajout_capteur(capteur d);
void remplir_fichier(capteur tab[],int nb);
void supprimer_capteur(char identifiant[]);
int remplir_tableau(capteur tab[],int n);
int rechercher_capteur(char identifiant[]);
void modifier_capteur(capteur d);
int recherche_existe(char identifiant[]);
//////////////////////////////////////////
void affichage_capteur(GtkTreeView *liste);

//////////////////////////////////////////
int capteur_defc();

