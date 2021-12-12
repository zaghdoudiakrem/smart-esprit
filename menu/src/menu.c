#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <stdlib.h>
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "menu.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
enum
{
	EID,
	EJOUR,
	EMOIS,
	EANNEE,
	ETYPE,
	EENTREE,
	EPLATPRINCIPAL,
	EDESSERT,
	EREGIME,
	ECHOIX,
	COLUMNS,
};
GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;
//fonction d'affichage
 void afficher_repas(GtkTreeView *l)
{
         GtkCellRenderer *renderer;
         GtkTreeViewColumn *column;
         GtkTreeIter  iter;
         GtkListStore *store;
	char id[20];
	char jour[20];
	char mois[20];
	char annee[20];
	char type[20];
	char entree[20];
	char plat_principal[20];
	char dessert[20];
	char regime[40];
	char choix[100];
	

store=NULL;
FILE *f;
store=GTK_LIST_STORE(gtk_tree_view_get_model(l));
if (store==NULL)
{	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("id",renderer, "text" ,EID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(l), column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("jour",renderer, "text" ,EJOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(l), column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("mois",renderer, "text" ,EMOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(l), column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("annee",renderer, "text" ,EANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(l), column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("type",renderer, "text" ,ETYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(l), column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("entree",renderer, "text" ,EENTREE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(l), column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("plat_principal",renderer, "text" ,EPLATPRINCIPAL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(l), column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("dessert",renderer, "text" ,EDESSERT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(l), column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("regime",renderer, "text" ,EREGIME,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(l), column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("choix",renderer, "text" ,ECHOIX,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(l), column);

}

store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("Menu.txt","a+");
if (f==NULL)
{
	return;
}
else
{
f=fopen("Menu.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",id,jour,mois,annee,type,entree,plat_principal,dessert,regime,choix)!=EOF)
{
         gtk_list_store_append(store, &iter);
	 gtk_list_store_set(store, &iter,
                            EID,id,
                            EJOUR,jour,
			    EMOIS,mois,	
                            EANNEE,annee,
                            ETYPE,type,
                            EENTREE,entree,
                            EPLATPRINCIPAL,plat_principal,
                            EDESSERT,dessert,
                            EREGIME,regime,
                            ECHOIX,choix,
                            -1);}
        fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW(l), GTK_TREE_MODEL(store));
	g_object_unref (store);
	}

}

//fonction d'ajout
void ajouter_repas(Menu repas)
{
FILE *f=NULL;
f=fopen("Menu.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %d %d %d %s %s %s %s %s %s\n",repas.id,repas.date.jour,repas.date.mois,repas.date.annee,repas.type,repas.entree,repas.plat_principal,repas.dessert,repas.regime,repas.choix);
fclose(f);
}
}


//fonction de modification
void modifier(Menu repas,char *fichier)
{
	Menu repas2;
	FILE *f,*g;
	char jour[20];
	char mois[20];
	char annee[20];
	char jour2[20];
	char mois2[20];
	char annee2[20];


f=fopen("Menu.txt","r");
g=fopen("Menumod.txt","w");
    if((f==NULL) && (g==NULL))
{
    return;}
    else
{

//strcpy(repas2.choix,repas.choix);
sprintf(jour,"%d",repas.date.jour);
sprintf(mois,"%d",repas.date.mois);
sprintf(annee,"%d",repas.date.annee);
sprintf(jour2,"%d",repas2.date.jour);
sprintf(mois2,"%d",repas2.date.mois);
sprintf(annee2,"%d",repas2.date.annee);
    while (fscanf (f,"%s %s %s %s %s %s %s %s %s %s\n",repas2.id,jour2,mois2,annee2,repas2.type,repas2.entree,repas2.plat_principal,repas2.dessert,repas2.regime,repas2.choix)
!=EOF)
    {
      	if (strcmp(repas.id,repas2.id)!=0)
          fprintf(g,"%s %s %s %s %s %s %s %s %s %s\n",repas2.id,jour2,mois2,annee2,repas2.type,repas2.entree,repas2.plat_principal,repas2.dessert,repas2.regime,repas2.choix);
        else
          fprintf(g,"%s %s %s %s %s %s %s %s %s %s\n",repas.id,jour,mois,annee,repas.type,repas.entree,repas.plat_principal,repas.dessert,repas.regime,repas.choix);
    }
   fclose(f);
   fclose(g);
remove("Menu.txt");
rename("Menumod.txt","Menu.txt");       
	}

}

//fonction de suppression
void supprimer_repas(char id[])
{
FILE *f, *g;
Menu repas;
f=fopen("Menu.txt","r");
g=fopen("Menusup.txt","w");
if ((f!=NULL)&&(g!=NULL))
{
while(fscanf(f,"%s %d %d %d %s %s %s %s %s %s\n",repas.id,&repas.date.jour,&repas.date.mois,&repas.date.annee,repas.type,repas.entree,repas.plat_principal,repas.dessert,repas.regime,repas.choix)
!=EOF)
{
if (strcmp(repas.id,id)!=0)
fprintf(g,"%s %d %d %d %s %s %s %s %s %s\n",repas.id,repas.date.jour,repas.date.mois,repas.date.annee,repas.type,repas.entree,repas.plat_principal,repas.dessert,repas.regime,repas.choix);
}
fclose(f);
fclose(g);
remove("Menu.txt");
rename("Menusup.txt","Menu.txt");
}
}

//fonction de recherche
Menu rechercher_repas(char id[])
{
FILE *f=NULL;
  Menu repas;
  Menu repas2;
f = fopen ("Menu.txt", "r");


  if (f!=NULL)
 {


    while (fscanf (f,"%s %d %d %d %s %s %s %s %s %s\n",repas2.id,&repas2.date.jour,&repas2.date.mois,&repas2.date.annee,repas2.type,repas2.entree,repas2.plat_principal,repas2.dessert,repas2.regime,repas2.choix)
!=EOF)
    if (strcmp (repas2.id, id) == 0)
	{
        
	strcpy(repas.type,repas2.type);
        strcpy(repas.entree,repas2.entree);
        strcpy(repas.plat_principal,repas2.plat_principal);
	strcpy(repas.dessert,repas2.dessert);
	repas.date.jour=repas2.date.jour;
	repas.date.mois=repas2.date.mois;
        repas.date.annee=repas2.date.annee;
 	strcpy(repas.regime,repas2.regime);
	strcpy(repas.choix,repas2.choix);
        
    }
    
  fclose (f);
 }
return(repas);
}


