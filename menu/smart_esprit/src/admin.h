#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include <gtk/gtk.h>

typedef struct utilisateur
{
char role[30],nom[20],prenom[20],username[20],password[20],cin[20];
int jour,mois,annee;
}utilisateur;

typedef struct alerte
{
int jour,heure,numCap,valeur;
}alerte;

int importer(utilisateur user[] , int n);
int ajouter_user(utilisateur user[] ,utilisateur u ,int n);
void supprimer_user(char id[20]);
int chercher_user(char id[]);
utilisateur chercheru(char id[]);
void afficher_user(utilisateur u ,utilisateur user[] ,int n);
void afficher_user(utilisateur u ,utilisateur user[] ,int n);
void modifier_user(utilisateur d);
void sauvegarder(utilisateur user[] , int n);
void afficher_personne(GtkWidget *liste);
void afficher_p(GtkWidget *liste);
int connexion(char a[50], char b[50]);
void afficher(int p);
void alertesMVTFUMEE(alerte alertemvt[], alerte alertefumee[],char *fichmvt,char *fichfumee,int *nbaf,int *nbam );

#endif


