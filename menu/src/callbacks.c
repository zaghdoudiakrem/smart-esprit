#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "menu.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int t[]={0,0,0};
int rg=0;
int regime2=0;
int typemod=0;
/*void
on_button_afficher_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *first_window,*window_affiche;
first_window=lookup_widget(objet_graphique,"first_window");
window_affiche=create_window_affiche();
gtk_widget_show(window_affiche);
}
*/
void
on_button_ajouter_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *first_window,*window_ajout;
first_window=lookup_widget(objet_graphique,"first_window");
window_ajout=create_window_ajout();
gtk_widget_show(window_ajout);
gtk_widget_hide(first_window);
}


void
on_button_modifier_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *first_window,*window_modif;
first_window=lookup_widget(objet_graphique,"first_window");
window_modif=create_window_modif();
gtk_widget_show(window_modif);
gtk_widget_hide(first_window);
}




void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkTreeIter iter;
gchar* id;
gchar* jour;
gchar* mois;
gchar* annee;
gchar* type;
gchar* entree;
gchar* plat_principal;
gchar* dessert;
gchar* regime;
gchar* choix;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter, path))
{
gtk_tree_model_get (GTK_TREE_MODEL(model),&iter,0,&id, 1 ,&jour, 2 , &mois, 3 ,&annee, 4 ,&type, 5 ,&entree, 6 ,&plat_principal, 7 ,&dessert, 8 ,&regime, 9 ,&choix, -1);

afficher_repas(treeview);

}
}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) 

   t[0]=1;  
}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) 

   t[1]=1;  
}


void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) 

   t[2]=1;  
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
rg=2;
}


void
on_button_confirmer_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *input2, *input3, *input4, *input5, *input6, *input7, *input8, *input9;

Menu repas;
FILE *f=NULL;

int i;

input1=lookup_widget(objet_graphique,"entry_id");
input2=lookup_widget(objet_graphique,"spinbutton1");
input3=lookup_widget(objet_graphique,"spinbutton2");
input4=lookup_widget(objet_graphique,"spinbutton3");
input5=lookup_widget(objet_graphique,"comboboxentry1");
input6=lookup_widget(objet_graphique,"entry2");
input7=lookup_widget(objet_graphique,"entry3");
input8=lookup_widget(objet_graphique,"entry4");
input9=lookup_widget(objet_graphique,"label13");


strcpy(repas.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(repas.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
strcpy(repas.entree,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(repas.plat_principal,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(repas.dessert,gtk_entry_get_text(GTK_ENTRY(input8)));
	repas.date.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input2)) ;
	repas.date.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input3)) ;
	repas.date.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input4)) ;
if(strcmp("Petit_dejeuner",gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)))==0)
       strcpy(repas.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
    else if (strcmp("Dejeuner",gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)))==0)
        strcpy(repas.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
    else 
        strcpy(repas.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));


/*fflush(stdin);
FILE *g=NULL;
g=fopen("test.txt","a+");
fprintf(g,"%s\n",repas.type);
fclose(g);*/

if ((t[0]==1)&&((t[1]==0)&&(t[2]==0)))
	strcpy(repas.choix,"Etudiant");
else 
{if ((t[0]==0)&&((t[1]==1)&&(t[2]==0)))
	strcpy(repas.choix,"Professeurs");
else
{ if ((t[0]==0)&&((t[1]==0)&&(t[2]==1)))
	strcpy(repas.choix,"Techniciens");
else 
{if ((t[0]==1)&&((t[1]==1)&&(t[2]==0)))
	{strcpy(repas.choix,"Etudiant/Professeurs");}
else 
{if ((t[0]==1)&&((t[1]==0)&&(t[2]==1)))
	strcpy(repas.choix,"Etudiant/Techniciens");
else
{ if ((t[0]==0)&&((t[1]==1)&&(t[2]==1)))
	strcpy(repas.choix,"Professeurs/Techniciens");
else if ((t[0]==1)&&((t[1]==1)&&(t[2]==1)))
	strcpy(repas.choix,"Etudiant/Professeurs/Techniciens");}}}}}

if (rg==1) 
		strcpy(repas.regime,"Vegetarien") ; 
else //if (rg==2)
		strcpy(repas.regime,"Standard") ;

ajouter_repas(repas);
gtk_label_set_text(GTK_LABEL(input9),"Menu ajouté avec succés :)");

}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
rg=1;
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
regime2=1;
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
regime2=2;
}


void
on_Dinner_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
typemod=3;
}


void
on_Dejeuner_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
typemod=2;
}


void
on_Petitdej_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
typemod=1;
}


void
on_buttondemodification_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
Menu repas;
GtkWidget *idv,*Jour,*Mois,*Annee,*Entree,*Plat_principal,*Dessert,*Type,*Vg,*St,*Choix,*lab;
char jour[20];
	char mois[20];
	char annee[20];

idv = lookup_widget (objet_graphique,"entry_id2");
strcpy(repas.id,gtk_entry_get_text(GTK_ENTRY(idv)));
Jour = lookup_widget(objet_graphique, "entryjour");
Mois = lookup_widget(objet_graphique, "entrymois");
Annee = lookup_widget(objet_graphique, "entryannee");
Entree= lookup_widget(objet_graphique, "entry6");
Plat_principal = lookup_widget(objet_graphique, "entry7");
Dessert = lookup_widget (objet_graphique,"entry8");
Type = lookup_widget(objet_graphique, "entry10");
Vg = lookup_widget(objet_graphique, "radiobutton3");
St = lookup_widget(objet_graphique, "radiobutton4");
Choix=lookup_widget(objet_graphique, "entrychoix");
lab = lookup_widget(objet_graphique, "labelrepmodif");

//strcpy(repas.id,gtk_entry_get_text(GTK_ENTRY(idv)));
/*fflush(stdin);
sprintf(jour,"%d",repas.date.jour);
strcpy(jour,gtk_entry_get_text(GTK_ENTRY(Jour)));
sprintf(mois,"%d",repas.date.mois);
strcpy(mois,gtk_entry_get_text(GTK_ENTRY(Mois)));
sprintf(annee,"%d",repas.date.annee);
strcpy(annee,gtk_entry_get_text(GTK_ENTRY(Annee)));
fflush(stdin);*/
repas.date.jour=atoi(gtk_entry_get_text(GTK_ENTRY(Jour)));
repas.date.mois=atoi(gtk_entry_get_text(GTK_ENTRY(Mois)));
repas.date.annee=atoi(gtk_entry_get_text(GTK_ENTRY(Annee)));
strcpy(repas.entree,gtk_entry_get_text(GTK_ENTRY(Entree)));
strcpy(repas.plat_principal,gtk_entry_get_text(GTK_ENTRY(Plat_principal)));
strcpy(repas.dessert,gtk_entry_get_text(GTK_ENTRY(Dessert)));
strcpy(repas.type,gtk_entry_get_text(GTK_ENTRY(Type)));
strcpy(repas.choix,gtk_entry_get_text(GTK_ENTRY(Choix)));
strcpy(repas.regime,gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(Vg))==1?"Vegetarien":"Standard");
/*if (regime2=1) 
		strcpy(repas.regime,"Vegetarien") ; 
else 
		strcpy(repas.regime,"Standard") ;*/
modifier(repas,"Menu.txt");
gtk_label_set_text(GTK_LABEL(lab),"Menu modifié avec succés :)");

}



void
on_buttondevalidation_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char idd[20];
GtkWidget *idv,*Jour,*Mois,*Annee,*Entree,*Plat_principal,*Dessert,*Type,*Vg,*St,*Choix,*lab;
FILE *f;
int x=-1;
char id[20];
	char jour[20];
	char mois[20];
	char annee[20];
	/*char type[20];
	char entree[20];
	char plat_principal[20];
	char dessert[20];
	char regime[40];
	char choix[100];*/
Menu repas ;


idv = lookup_widget (objet_graphique,"entry_id2");
strcpy(idd,gtk_entry_get_text(GTK_ENTRY(idv)));
Jour = lookup_widget(objet_graphique, "entryjour");
Mois = lookup_widget(objet_graphique, "entrymois");
Annee = lookup_widget(objet_graphique, "entryannee");
Entree= lookup_widget(objet_graphique, "entry6");
Plat_principal = lookup_widget(objet_graphique, "entry7");
Dessert = lookup_widget (objet_graphique,"entry8");
Type = lookup_widget(objet_graphique, "entry10");
Vg = lookup_widget(objet_graphique, "radiobutton3");
St = lookup_widget(objet_graphique, "radiobutton4");
Choix=lookup_widget(objet_graphique, "entrychoix");
lab = lookup_widget(objet_graphique, "label_idex");

f = fopen ("Menu.txt", "r");


  if (f!=NULL)
 {
  while (fscanf (f,"%s %d %d %d %s %s %s %s %s %s\n",repas.id,&repas.date.jour,&repas.date.mois,&repas.date.annee,repas.type,repas.entree,repas.plat_principal,repas.dessert,repas.regime,repas.choix) != EOF)
  {
  
    if (strcmp (idd,repas.id) == 0)
      
      x=1;
  }
    
     fclose (f);
  }

if(x==1)
{
    Menu repas2 = rechercher_repas(idd);
    gtk_label_set_text(GTK_LABEL(lab),"Repas trouvé");


gtk_entry_set_text(GTK_ENTRY(Type),repas2.type);
gtk_entry_set_text(GTK_ENTRY(Entree),repas2.entree);
gtk_entry_set_text(GTK_ENTRY(Plat_principal),repas2.plat_principal);
gtk_entry_set_text(GTK_ENTRY(Dessert),repas2.dessert);
fflush(stdin);
sprintf(jour,"%d",repas2.date.jour);
gtk_entry_set_text(GTK_ENTRY(Jour),jour);
sprintf(mois,"%d",repas2.date.mois);
gtk_entry_set_text(GTK_ENTRY(Mois),mois);
sprintf(annee,"%d",repas2.date.annee);
gtk_entry_set_text(GTK_ENTRY(Annee),annee);
/*sprintf(jour,"%d",repas2.date.jour);
gtk_label_set_text(GTK_LABEL(Jour),jour);
sprintf(mois,"%d",repas2.date.mois);
gtk_label_set_text(GTK_LABEL(Mois),mois);
sprintf(annee,"%d",repas2.date.annee);
gtk_label_set_text(GTK_LABEL(Annee),annee);*/
fflush(stdin);


/*if(strcmp("Petit_dejeuner",repas2.type)==0)
{gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(Pd),TRUE);}
else
{if(strcmp(repas2.type,"Dejeuner")==0)
{gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(Dj),TRUE);}
else
{gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(Dn),TRUE);}}*/

if(strcmp(repas2.regime,"Vegetarien")==0)
{gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(Vg),TRUE);}
if(strcmp(repas2.regime,"Standard")==0)
{gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(St),TRUE);}
gtk_entry_set_text(GTK_ENTRY(Choix),repas2.choix);
//gtk_combo_box_set_active(GTK_COMBO_BOX(Type),repas.type);
//strcmp(repas.regime,"Vegetarien")==0?gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(Vg),TRUE):strcmp(repas.regime,"Standard")==0?gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(St),TRUE);
/*if(strcmp(repas.type,"Petit_dejeuner")==0)
       strcpy(repas.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Type)));
    else if (strcmp(repas.type,"Dejeuner")==0)
        strcpy(repas.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Type)));
    else 
        strcpy(repas.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Type)));*/
}
else
{
gtk_label_set_text(GTK_LABEL(lab),"l'id n'existe pas ");
gtk_entry_set_text(GTK_ENTRY(Type)," ");
gtk_entry_set_text(GTK_ENTRY(Entree)," ");
gtk_entry_set_text(GTK_ENTRY(Plat_principal)," ");
gtk_entry_set_text(GTK_ENTRY(Dessert)," ");
fflush(stdin);
//sprintf(jour,"%d",repas2.date.jour);
gtk_entry_set_text(GTK_ENTRY(Jour)," ");
//sprintf(mois,"%d",repas2.date.mois);
gtk_entry_set_text(GTK_ENTRY(Mois)," ");
//sprintf(annee,"%d",repas2.date.annee);
gtk_entry_set_text(GTK_ENTRY(Annee)," ");
gtk_entry_set_text(GTK_ENTRY(Choix)," ");

}


}



void
on_buttonde_supp_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *ids,*lab;

char idd[20];
FILE *f;
int x=-1;
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
lab = lookup_widget (objet_graphique,"label29");
ids = lookup_widget (objet_graphique,"entry_idsup");
strcpy(idd,gtk_entry_get_text(GTK_ENTRY(ids)));

f = fopen ("Menu.txt", "r");


  if (f!=NULL)
 {
  while (fscanf (f,"%s %s %s %s %s %s %s %s %s %s\n",id,jour,mois,annee,type,entree,plat_principal,dessert,regime,choix) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      x=1;
      } 
     } 
    
     fclose (f);
  }

if(x==-1)
{
gtk_label_set_text(GTK_LABEL(lab),"Desolé l'id n'existe pas ");
}else
{
    supprimer_repas(idd);
    gtk_label_set_text(GTK_LABEL(lab),"Menu supprimé avec succés :)");
}

}


void
on_button_actualiser_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview;
GtkWidget *window_affiche;
window_affiche=lookup_widget(objet_graphique,"window_affiche");
treeview=lookup_widget(window_affiche,"treeview");
afficher_repas(GTK_TREE_VIEW(treeview));
}


void
on_button_rechercher2_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_affiche,*window_recherche;
window_affiche=lookup_widget(objet_graphique,"window_affiche");
window_recherche=create_window_recherche();
gtk_widget_show(window_recherche);
gtk_widget_hide(window_affiche);

}


void
on_button1_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *idv,*Jour,*Mois,*Annee,*Type,*Entree,*Plat_principal,*Dessert,*Rg,*Choix,*lab;

	char idd[20];
	int x=-1;
	char jour[20];
	char mois[20];
	char annee[20];
	FILE *f;
	
Menu repas ;


idv = lookup_widget (objet_graphique,"entry9");
strcpy(idd,gtk_entry_get_text(GTK_ENTRY(idv)));
Jour = lookup_widget(objet_graphique, "labeljour");
Mois = lookup_widget(objet_graphique, "labelmois");
Annee = lookup_widget(objet_graphique, "labelannee");
Type = lookup_widget(objet_graphique, "labeltype");
Entree= lookup_widget(objet_graphique, "labelentree");
Plat_principal = lookup_widget(objet_graphique, "labelplat");
Dessert = lookup_widget (objet_graphique,"labeldessert");
Rg = lookup_widget(objet_graphique, "labelregime");
Choix = lookup_widget(objet_graphique, "labelpour");
lab = lookup_widget(objet_graphique, "labelrep");

f = fopen ("Menu.txt", "r");


  if (f!=NULL)
 {
  while (fscanf (f,"%s %d %d %d %s %s %s %s %s %s\n",repas.id,&repas.date.jour,&repas.date.mois,&repas.date.annee,repas.type,repas.entree,repas.plat_principal,repas.dessert,repas.regime,repas.choix) != EOF)
  {
  
    if (strcmp (idd,repas.id) == 0)
      
      x=1;
  }
    
    fclose (f);
 }

if(x==-1)
{
gtk_label_set_text(GTK_LABEL(lab),"l'id n'existe pas ");
gtk_label_set_text(GTK_LABEL(Jour)," ");
gtk_label_set_text(GTK_LABEL(Mois)," ");
gtk_label_set_text(GTK_LABEL(Annee)," ");
gtk_label_set_text(GTK_LABEL(Type)," ");
gtk_label_set_text(GTK_LABEL(Entree)," ");
gtk_label_set_text(GTK_LABEL(Plat_principal)," ");
gtk_label_set_text(GTK_LABEL(Dessert)," ");
gtk_label_set_text(GTK_LABEL(Type)," ");
gtk_label_set_text(GTK_LABEL(Rg)," ");
gtk_label_set_text(GTK_LABEL(Choix)," ");
}
else
{
    Menu repas2 = rechercher_repas(idd);
    gtk_label_set_text(GTK_LABEL(lab),"Repas trouvé");
fflush(stdin);
sprintf(jour,"%d",repas2.date.jour);
gtk_label_set_text(GTK_LABEL(Jour),jour);
sprintf(mois,"%d",repas2.date.mois);
gtk_label_set_text(GTK_LABEL(Mois),mois);
sprintf(annee,"%d",repas2.date.annee);
gtk_label_set_text(GTK_LABEL(Annee),annee);
fflush(stdin);
gtk_label_set_text(GTK_LABEL(Type),repas2.type);
gtk_label_set_text(GTK_LABEL(Entree),repas2.entree);
gtk_label_set_text(GTK_LABEL(Plat_principal),repas2.plat_principal);
gtk_label_set_text(GTK_LABEL(Dessert),repas2.dessert);
gtk_label_set_text(GTK_LABEL(Type),repas2.type);
gtk_label_set_text(GTK_LABEL(Rg),repas2.regime);
gtk_label_set_text(GTK_LABEL(Choix),repas2.choix);


}
}











void
on_button_afficher_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *first_window,*window_affiche;
first_window=lookup_widget(objet_graphique,"first_window");
window_affiche=create_window_affiche();
gtk_widget_show(window_affiche);
gtk_widget_hide(first_window);
}


void
on_button_supprimer_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *first_window,*window_supp;
first_window=lookup_widget(objet_graphique,"first_window");
window_supp=create_window_supp();
gtk_widget_show(window_supp);
gtk_widget_hide(first_window);
}


void
on_buttonretourajout_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *first_window,*window_ajout;
first_window=create_first_window();
gtk_widget_show(first_window);
window_ajout=lookup_widget(objet_graphique,"window_ajout");
gtk_widget_hide(window_ajout);
}


void
on_buttonretourmodif_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *first_window,**window_modif;
first_window=create_first_window();
gtk_widget_show(first_window);
window_modif=lookup_widget(objet_graphique,"window_modif");
gtk_widget_hide(window_modif);
}


void
on_buttonretoursupp_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *first_window,*window_supp;
first_window=create_first_window();
gtk_widget_show(first_window);
window_supp=lookup_widget(objet_graphique,"window_supp");
gtk_widget_hide(window_supp);
}


void
on_buttonretouraffiche_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *first_window,*window_affiche;
first_window=create_first_window();
gtk_widget_show(first_window);
window_affiche=lookup_widget(objet_graphique,"window_affiche");
gtk_widget_hide(window_affiche);
}


void
on_buttonretourrecherche_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_affiche,*window_recherche;
window_affiche=create_window_affiche();
gtk_widget_show(window_affiche);
window_recherche=lookup_widget(objet_graphique,"window_recherche");
gtk_widget_hide(window_recherche);

}
///////////////

void
on_buttonsuppdetree_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* tree=lookup_widget(objet_graphique,"treeview");
	GtkWidget* labsup = lookup_widget(objet_graphique, "labsup");
        
        gchar *id;
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(tree));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);

                supprimer_repas(id);
	gtk_label_set_text(GTK_LABEL(labsup),"Menu supprimé ");
}
}

