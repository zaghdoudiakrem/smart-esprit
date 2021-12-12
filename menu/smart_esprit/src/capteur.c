#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include "capteur.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<gtk/gtk.h>

enum
{
	EID,
	EMARQUE,
	ETYPE,
	EJOUR,
	EMOIS,
	EANNEE,
	EVALEUR,
	COLUMNS,



};



///////////////////////////////////////
/// ajout des capteurs dans un tableau
///////////////////////////////////////
void ajout_capteur(capteur d)
{
FILE *f=fopen("capt.txt","a+");
        fprintf(f,"%s %s %s %d %d %d %s\n",d.id,d.marque,d.type,d.date.jour,d.date.mois,d.date.annee,d.valeur);
fclose(f);
}
//////////////////////////////////////////
///remplissage fichier <--- tableau
///////////////////////////////////////////
void remplir_fichier(capteur tab[],int nb)
{
    int i=0;
    FILE *f=NULL;
    f=fopen("capt.txt","w+");
    if("f!=NULL")
        {for (i=0;i<nb;i++)
        fprintf(f,"%s %s %s %d %d %d %s\n",tab[i].id,tab[i].marque,tab[i].type,tab[i].date.jour,tab[i].date.mois,tab[i].date.annee,tab[i].valeur);
        }
    fclose(f);

}
///////////////////////////////////
/// supprimer des capteurs:
///////////////////////////////////
void supprimer_capteur(char identifiant[])
{
capteur c;
FILE *f1=NULL;
FILE *f2=NULL;
fflush(stdin);
f1=fopen("capt.txt","r");
f2=fopen("capt3.txt","a+");
while(fscanf(f1,"%s %s %s %d %d %d %s\n",c.id,c.marque,c.type,&c.date.jour,&c.date.mois,&c.date.annee,c.valeur)!=EOF)
{if (strcmp(c.id,identifiant)!=0)
fprintf(f2,"%s %s %s %d %d %d %s\n",c.id,c.marque,c.type,c.date.jour,c.date.mois,c.date.annee,c.valeur);
}
fclose(f1);
fclose(f2);
remove("capt.txt");
rename("capt3.txt","capt.txt");

}
//////////////////////////////////////////////////
/// remplissage d'un tableau <---fichier
//////////////////////////////////////////////////
int remplir_tableau(capteur tab[],int n)
{
    capteur c ;
    int i=0;
int nb=0;
    FILE *f1=NULL;
    f1=fopen("capt.txt","r");
    while (fscanf(f1,"%s %s %s %d %d %d %s\n",c.id,c.marque,c.type,&c.date.jour,&c.date.mois,&c.date.annee,c.valeur)!=EOF)
{ nb++;
   strcpy(tab[i].id,c.id);
   strcpy(tab[i].marque,c.marque);
   strcpy(tab[i].type,c.type);
   tab[i].date.jour=c.date.jour;
   tab[i].date.mois=c.date.mois;
   tab[i].date.annee=c.date.annee;
   strcpy(tab[i].valeur,c.valeur);
   i++;
}
fclose(f1);
return nb;
}

/////////////////////////////////////////
///recherche capteur
////////////////////////////////////////
int rechercher_capteur(char identifiant[])
{
    capteur c;
    int test=0;
    int i,nb;
    FILE *f=NULL;
    FILE *f1=NULL;
    f1=fopen("capt.txt","r");
while (fscanf(f1,"%s %s %s %d %d %d %s\n",c.id,c.marque,c.type,&c.date.jour,&c.date.mois,&c.date.annee,c.valeur)!=EOF)
    {

     if(strcmp(c.id,identifiant)==0)
    {
        test=1;
        f=fopen("recherchecapt.txt","w+");
        if ("f!=NULL")
                fprintf(f,"%s %s %s %d %d %d %s\n",c.id,c.marque,c.type,c.date.jour,c.date.mois,c.date.annee,c.valeur);
        fclose(f);
        break;
    }

    }
fclose(f1);
    return test;
}
/////////////////////////////
/// modification de capteur
/////////////////////////////
void modifier_capteur(capteur d)
{
capteur c;
FILE *f=NULL;
f=fopen("capt.txt","r");
FILE *f2=NULL;
f2=fopen("Capt2.txt","a+");
    
fflush(stdin);
    while (fscanf(f,"%s %s %s %d %d %d %s\n",c.id,c.marque,c.type,&c.date.jour,&c.date.mois,&c.date.annee,c.valeur)!=EOF)
    { if(strcmp(c.id,d.id)==0)
      {c=d;}
      fprintf(f2,"%s %s %s %d %d %d %s\n",c.id,c.marque,c.type,c.date.jour,c.date.mois,c.date.annee,c.valeur);
	
    }
fclose(f2);
fclose(f);   
remove("capt.txt");
rename("Capt2.txt","capt.txt");
      
}


////////////////////////
///fonction de recherche pour verifier l'existance
////////////////////////
int recherche_existe(char identifiant[])
{int i;
int n=0;
capteur c;
    FILE *f=NULL;
    f=fopen("capt.txt","r");
while (fscanf(f,"%s %s %s %d %d %d %s\n",c.id,c.marque,c.type,&c.date.jour,&c.date.mois,&c.date.annee,c.valeur)!=EOF)
    { if(strcmp(c.id,identifiant)==0)
            return(1);

    }

  return(0);
}

////////////////////////////////////
///Capteur defectueux
////////////////////////////////////
int capteur_defc(char fichCap[],int capdef[],int maxtmp,int mintmp)
{
    defectueux c ;
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
/////////////////////////////////////////////////////////////////
///affichage sur treeview
/////////////////////////////////////////////////////////////////

void affichage_capteur(GtkTreeView *liste)
{

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char id[50];
    	char marque[50];
    	char type[50] ;
    	char jour[20];
	char mois[20];	
	char annee[20];
    	char valeur[50];
	

	store=NULL;
	FILE *f;
	store=GTK_LIST_STORE(gtk_tree_view_get_model(liste));
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id", renderer, "text",EID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("marque", renderer, "text",EMARQUE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type", renderer, "text",ETYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);   
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",EJOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",EMOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text",EANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("valeur", renderer, "text",EVALEUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	f=fopen("capt.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("capt.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s\n",id,marque,type,jour,mois,annee,valeur)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, EID, id, EMARQUE,marque, ETYPE, type,EJOUR,jour,EMOIS,mois,EANNEE,annee,EVALEUR,valeur,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}








