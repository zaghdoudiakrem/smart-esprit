#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "capteur.h"
#include "admin.h"
#include"treeview.h"
#include "dashboard.c"

int rad1,rad2;
int chek[1]={0};
int test=0;
int rad,q;





//////////////////////////////////////////////
///ESPACE TECHNICIEN
//////////////////////////////////////////////
void
on_affichercapteur_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeviewaffcapt;
GtkWidget *fenetre_affichier;
fenetre_affichier=lookup_widget(objet_graphique,"Espace_technicien");
treeviewaffcapt=lookup_widget(fenetre_affichier,"treeviewaffcapteur");

affichage_capteur(GTK_TREE_VIEW (treeviewaffcapt));
}


void
on_deconnecterET_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *w1;
GtkWidget *w2;


w1=create_windowAuth();
gtk_widget_show (w1);
w2=lookup_widget(objet_graphique,"Espace_technicien");
gtk_widget_hide(w2);




}


void
on_chercherc_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *windowachercher;

windowachercher=create_rechercher_capteur ();
gtk_widget_show (windowachercher);

}


void
on_modifierc_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowmod;

windowmod=create_modifier_capteur ();
gtk_widget_show (windowmod);

}


void
on_supprimerc_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *windowasupp;

windowasupp=create_supprimer_capteur ();
gtk_widget_show (windowasupp);

}


void
on_ajouterc_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *windowajouter;

windowajouter=create_ajouter_capteur ();
gtk_widget_show (windowajouter);

}


void
on_treeviewaffcapteur_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* id;
	gchar* marque;
	gchar* type;
	gchar* jour;
	gchar* mois;
	gchar* annee;
	gchar* valeur;
	
        
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model, &iter ,path))
	{
		
		gtk_tree_model_get (GTK_TREE_MODEL(model),&iter,0,&id, 1, &marque, 2, &type ,3, &jour,4,&mois,5,&annee,6,&valeur,-1);
		affichage_capteur(treeview);
}

}


void
on_rb1_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{rad1=1;}

}


void
on_rb2_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{rad1=2;}

}


void
on_rb3_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{rad1=3;}

}


void
on_rb4_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{rad1=4;}

}


void
on_rb5_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{rad1=5;}

}


void
on_rb6_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{rad2=1;}
}


void
on_rb7_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{rad2=2;}
}


void
on_rb8_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{rad2=3;}
}


void
on_rb9_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{rad2=4;}
}


void
on_rb10_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{rad2=5;}
}


void
on_confmodf_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{chek[0]=1;}
}


void
on_buttonannulerm_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *windowamod;


windowamod=lookup_widget(objet_graphique,"modifier_capteur");
gtk_widget_hide (windowamod);


}

///modifier capteur
void
on_confirmerm_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2;
GtkWidget *comboboxtype;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
capteur d;
GtkWidget *output;

int test=0;
char x[50],ch[20];




input1=lookup_widget(objet_graphique,"entryidm");///id
input2=lookup_widget(objet_graphique,"entryvaleurm");///valeur

jour=lookup_widget(objet_graphique, "spinbuttonjourm");///jour
mois=lookup_widget(objet_graphique, "spinbuttonmoism");///mois
annee=lookup_widget(objet_graphique, "spinbuttonanneem");///annee
comboboxtype=lookup_widget(objet_graphique, "comboboxm");///type

strcpy(d.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(d.valeur,gtk_entry_get_text(GTK_ENTRY(input2)));
if(rad1==1)
strcpy(d.marque,"CHERRY");
else if(rad1==2)
strcpy(d.marque,"NERDO");
else if(rad1==3)
strcpy(d.marque,"MICRO_EPSILON");
else if(rad1==4)
strcpy(d.marque,"BOSCH");
else if(rad1==5)
strcpy(d.marque,"MADE_IN_CHINA");


d.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
d.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
d.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

strcpy(d.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxtype)));
fflush(stdin);
test=recherche_existe(d.id);
if(chek[0]==1)
{
if (test==1)
{
modifier_capteur(d);
output=lookup_widget(objet_graphique,"labelaffichagem");
strcpy(x,"la modification est faite avec succés");
gtk_label_set_text(GTK_LABEL(output),x);
}
else
{output=lookup_widget(objet_graphique,"labelaffichagem");
strcpy(x,"L'identifiant n'existe pas");
gtk_label_set_text(GTK_LABEL(output),x);}
}
else
{output=lookup_widget(objet_graphique,"labelaffichagem");
strcpy(x,"case confirmation n'est pas cocher");
gtk_label_set_text(GTK_LABEL(output),x);}

}







///ajout capteur
void
on_buttonajoutc_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *input1,*input2;
GtkWidget *comboboxtype;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
capteur d;
GtkWidget *output;
int test=0;
char x[50],ch[20];
fflush(stdin);



input1=lookup_widget(objet_graphique,"entryida");///id
input2=lookup_widget(objet_graphique,"entryvaleura");///valeur

jour=lookup_widget(objet_graphique, "spinbuttonja");///jour
mois=lookup_widget(objet_graphique, "spinbuttonmoisa");///mois
annee=lookup_widget(objet_graphique, "spinbuttonanneea");///annee
comboboxtype=lookup_widget(objet_graphique, "comboboxac");///type

strcpy(d.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(d.valeur,gtk_entry_get_text(GTK_ENTRY(input2)));
if(rad2==1)
strcpy(d.marque,"CHERRY");
else if(rad2==2)
strcpy(d.marque,"NERDO");
else if(rad2==3)
strcpy(d.marque,"MICRO_EPSILON");
else if(rad2==4)
strcpy(d.marque,"BOSCH");
else if(rad2==5)
strcpy(d.marque,"MADE_IN_CHINA");


d.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
d.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
d.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

strcpy(d.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxtype)));

//if((strcmp(d.type,"capteur_de_Mouvement")==0 || strcmp(d.type,"capteur_de_Fumee")==0)&& (d.valeur !=0 || d.valeur !=1))






test=recherche_existe(d.id);
if (test==0)
{
ajout_capteur(d);
output=lookup_widget(objet_graphique,"labelconfajout");
strcpy(x,"l'ajout est faite avec succés");
gtk_label_set_text(GTK_LABEL(output),x);
}
else
{
output=lookup_widget(objet_graphique,"labelconfajout");
strcpy(x,"L'identifiant existe");
gtk_label_set_text(GTK_LABEL(output),x);
}

}




void
on_Annulera_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowajout;

windowajout=lookup_widget(objet_graphique,"ajouter_capteur");
gtk_widget_hide (windowajout);

}


void
on_buttonannulerS_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *windowsupp;


windowsupp=lookup_widget(objet_graphique,"supprimer_capteur");
gtk_widget_hide (windowsupp);

}

///supprimer capteur
void
on_buttonsuppc_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *output;
int n=0;
int test=0;
char x[50],ch[20];
char ident[50]="";
fflush(stdin);


input1=lookup_widget(objet_graphique,"entryids");///id
strcpy(ident,gtk_entry_get_text(GTK_ENTRY(input1)));

test=recherche_existe(ident);
if (test==1)
{
supprimer_capteur(ident);
output=lookup_widget(objet_graphique,"supprimcapt");
strcpy(x," la suppression est faite avec succée");

gtk_label_set_text(GTK_LABEL(output),x);
}
else
{

output=lookup_widget(objet_graphique,"supprimcapt");
strcpy(x,"Le capteur n'existe pas");
gtk_label_set_text(GTK_LABEL(output),x);
}

/*strcpy(ident,"1");
supprimer_capteur(ident);*/

}

///rechercher un capteur
void
on_buttonrc_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *output;
int n=0;
int test=0;
FILE *f=NULL;
char x[300],ch[20];
char jour[50],mois[50],annee[50];
char ident[50]="";
capteur c;
fflush(stdin);


input1=lookup_widget(objet_graphique,"entryidr");///id
strcpy(ident,gtk_entry_get_text(GTK_ENTRY(input1)));
test=rechercher_capteur(ident);

if (test==1)
{f=fopen("recherchecapt.txt","r");
while (fscanf(f,"%s %s %s %s %s %s %s\n",c.id,c.marque,c.type,jour,mois,annee,c.valeur)!=EOF)
{
fflush(stdin);
strcpy(x,"Identifiant:");
strcat(x,c.id);
strcat(x,"\nMarque:");
strcat(x,c.marque);
strcat(x,"\nType:");
strcat(x,c.type);
strcat(x,"\nDate_d_ajout:");
strcat(x,jour);
strcat(x,"/");
strcat(x,mois);
strcat(x,"/");
strcat(x,annee);
strcat(x,"\nValeur:");
strcat(x,c.valeur);


}
output=lookup_widget(objet_graphique,"labelaffi_capt_r");
gtk_label_set_text(GTK_LABEL(output),x);
}
else
{
output=lookup_widget(objet_graphique,"labelaffi_capt_r");
strcpy(x,"Le capteur n'existe pas");
gtk_label_set_text(GTK_LABEL(output),x);
}

}


void
on_buttonanuulerR_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowchercher;


windowchercher=lookup_widget(objet_graphique,"rechercher_capteur");
gtk_widget_hide (windowchercher);

}


void
on_verifierexiste_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *output;

char x[50],ch[20];
char ident[50]="";
fflush(stdin);


input1=lookup_widget(objet_graphique,"entryidm");///id
strcpy(ident,gtk_entry_get_text(GTK_ENTRY(input1)));
test=recherche_existe(ident);

if (test==1)
{
output=lookup_widget(objet_graphique,"labelverifexiste");
strcpy(x," le capteur existe");

gtk_label_set_text(GTK_LABEL(output),x);
}
else
{
output=lookup_widget(objet_graphique,"labelverifexiste");
strcpy(x,"Le capteur n'existe pas");
gtk_label_set_text(GTK_LABEL(output),x);
}


}
/////////////////////////////////////////////////////////////////////////
////ESPACE ADMIN
/////////////////////////////////////////////////////////////////////////

void
on_buttonDec_clicked                   (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *eff;
eff=lookup_widget(objet_graphique,"windowAdmin");
gtk_widget_hide(eff);
}


void
on_buttonValider_clicked               (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
char f[30];
GtkWidget *Combobox1;
GtkWidget *windowajouter;
GtkWidget *windowaffiche;
GtkWidget *windowafficher;
GtkWidget *windowaffichet;
GtkWidget *windowmodifier;
GtkWidget *windowsupprimer;
GtkWidget *windowchercher;
GtkWidget *eff;
GtkWidget *treeviewutil;



Combobox1=lookup_widget(objet_graphique,"comboboxAdmin");

strcpy(f,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1)));


if(strcmp(f,"Ajouter")==0)
{
windowajouter=create_windowAjouter ();
gtk_widget_show (windowajouter);

eff=lookup_widget(objet_graphique,"windowAdmin");
gtk_widget_hide(eff);
}

if(strcmp(f,"Afficher")==0)
{
afficher(rad);

windowafficher=lookup_widget(objet_graphique,"windowAfficher");
windowafficher=create_windowAfficher();
gtk_widget_show (windowafficher);
treeviewutil=lookup_widget(windowafficher,"treeviewAfficher");
afficher_p(GTK_TREE_VIEW (treeviewutil));
eff=lookup_widget(objet_graphique,"windowAdmin");
gtk_widget_hide(eff);
}

if(strcmp(f,"Afficher tout")==0)
{
windowaffichet=lookup_widget(objet_graphique,"windowAffichert");
windowaffichet=create_windowAffichert();
gtk_widget_show (windowaffichet);
treeviewutil=lookup_widget(windowaffichet,"treeviewAT");
afficher_personne(GTK_TREE_VIEW (treeviewutil));
eff=lookup_widget(objet_graphique,"windowAdmin");
gtk_widget_hide(eff);
}

if(strcmp(f,"Modifier")==0)
{
windowmodifier=create_windowModifier();
gtk_widget_show (windowmodifier);
eff=lookup_widget(objet_graphique,"windowAdmin");
gtk_widget_hide(eff);
}

if(strcmp(f,"Supprimer")==0)
{
windowsupprimer=create_windowSupprimer();
gtk_widget_show (windowsupprimer);
eff=lookup_widget(objet_graphique,"windowAdmin");
gtk_widget_hide(eff);
}

if(strcmp(f,"Chercher")==0)
{
windowchercher=create_windowChercher();
gtk_widget_show (windowchercher);
eff=lookup_widget(objet_graphique,"windowAdmin");
gtk_widget_hide(eff);
}
}


void
on_Admin_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
rad=0;
}


void
on_radiobutton2_agent_de_foyer_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
rad=1;
}


void
on_radiobutton3_agent_de_restaurant_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
rad=2;
}


void
on_radiobutton4_nutritionniste_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
rad=3;
}


void
on_radiobutton5_technicien_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
rad=4;
}


void
on_radiobutton6_etudiant_clicked       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
rad=5;
}


void
on_buttonAfret_clicked                 (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *eff;
GtkWidget *windowAdmin;
windowAdmin=create_windowAdmin();
gtk_widget_show (windowAdmin);
eff=lookup_widget(objet_graphique,"windowAfficher");
gtk_widget_hide(eff);
}


void
on_treeviewAfficher_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* role;
	gchar* nom;
	gchar* prenom;
	gchar* jour;
	gchar* mois;
	gchar* annee;
	gchar* username;
	gchar* password;
	gchar* cin;
	
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model,&iter,path))
	{
		gtk_tree_model_get (GTK_TREE_MODEL(model),&iter,0,&role,1,&nom,2,&prenom,3,&jour,4,&mois,5,&annee,6,&username,7,&password,8,&cin,-1);
		afficher_p(treeview);

	}
}


void
on_buttonRetourAj_clicked              (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *eff;
GtkWidget *windowAdmin;
windowAdmin=create_windowAdmin();
gtk_widget_show (windowAdmin);
eff=lookup_widget(objet_graphique,"windowAjouter");
gtk_widget_hide(eff);
}


void
on_buttonAjouter_clicked               (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
int i,k;
utilisateur u, user[1000];
char RE[50];
int n=0;
GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *username;
GtkWidget *password;
GtkWidget *j;
GtkWidget *m;
GtkWidget *a;
GtkWidget *cin;
GtkWidget *output ;
int z=0;
n=importer(user,n);


nom=lookup_widget (objet_graphique,"entryNom");
prenom=lookup_widget (objet_graphique,"entryPrenom");
username=lookup_widget (objet_graphique,"entryUsername");
password=lookup_widget (objet_graphique,"entryPassword");
cin=lookup_widget (objet_graphique,"entryCIN");
j=lookup_widget(objet_graphique,"spinbuttonJour");
m=lookup_widget(objet_graphique,"spinbuttonMois");
a=lookup_widget(objet_graphique,"spinbuttonAnnee");


u.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(j));
u.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m));
u.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(a));
strcpy(u.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(u.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(u.username, gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(u.password, gtk_entry_get_text(GTK_ENTRY(password)));
strcpy(u.cin,gtk_entry_get_text(GTK_ENTRY(cin)));


if(rad==0)
strcpy(u.role,"Admin");
if(rad==1)
strcpy(u.role,"Agent_de_foyer");
if(rad==2)
strcpy(u.role,"Agent_de_restaurant");
if(rad==3)
strcpy(u.role,"Nutritionniste");
if(rad==4)
strcpy(u.role,"Technicien");
if(rad==5)
strcpy(u.role,"Etudiant");

z=chercher_user(u.cin);


if(z==1)
{output=lookup_widget(objet_graphique,"labelAjouterresult");
strcpy(RE," utilisateur deja existant");
gtk_label_set_text(GTK_LABEL(output),RE);
}
else
{
n=ajouter_user(user,u ,n);
sauvegarder(user,n);
output=lookup_widget(objet_graphique,"labelAjouterresult");
strcpy(RE,"utilisateur ajouté avec succés");
gtk_label_set_text(GTK_LABEL(output),RE);

}
}


void
on_buttoncnx_clicked                   (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
int x;
GtkWidget *eff;
GtkWidget *windowadmin;
GtkWidget *windowagent_de_restaurant;
GtkWidget *windowagent_de_foyer;
GtkWidget *windownutritionniste;
GtkWidget *windowtechnicien;
GtkWidget *windowetudiant;
char a[50];
char p[50];
GtkWidget *user;
GtkWidget *password;

user=lookup_widget(objet_graphique,"entryAuuser");
password=lookup_widget(objet_graphique,"entryAumdp");
strcpy(a, gtk_entry_get_text(GTK_ENTRY(user)));
strcpy(p, gtk_entry_get_text(GTK_ENTRY(password)));

x=connexion(a,p);

if(x==0)
{
windowadmin=create_windowAdmin();
gtk_widget_show (windowadmin);
eff=lookup_widget(objet_graphique,"windowAuth");
gtk_widget_hide(eff);
}

/*if(x==1)
{
windowagent_de_foyer=create_();
gtk_widget_show (windowagent_de_foyer);
eff=lookup_widget(objet_graphique,"windowAuth");
gtk_widget_hide(eff);
}

if(x==2)
{
windowagent_de_restaurant=create_();
gtk_widget_show (windowagent_de_restaurant);
eff=lookup_widget(objet_graphique,"windowAuth");
gtk_widget_hide(eff);
}

if(x==3)
{
windownutritionniste=create_();
gtk_widget_show (windownutritionniste);
eff=lookup_widget(objet_graphique,"windowAuth");
gtk_widget_hide(eff);
}*/

if(x==4)
{
windowtechnicien=create_Espace_technicien();
gtk_widget_show (windowtechnicien);
eff=lookup_widget(objet_graphique,"windowAuth");
gtk_widget_hide(eff);
}
/*
if(x==5)
{
windowetudiant=create_();
gtk_widget_show (windowetudiant);
eff=lookup_widget(objet_graphique,"windowAuth");
gtk_widget_hide(eff);
}
*/
}


void
on_buttonmodifierRetour_clicked        (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *eff;
GtkWidget *windowAdmin;
windowAdmin=create_windowAdmin();
gtk_widget_show (windowAdmin);
eff=lookup_widget(objet_graphique,"windowModifier");
gtk_widget_hide(eff);
}


void
on_buttonModifier_clicked              (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
int x=0;
FILE *l=NULL;
char cin[20];
char RE[50];
GtkWidget *input;
GtkWidget *output;
GtkWidget *window;
GtkWidget *eff;


input=lookup_widget(objet_graphique,"entrycinmod");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));
x=chercher_user(cin);

l=fopen("testmo.txt","w+");
fprintf(l,"%s",cin);
fclose(l);

if(x==1)
{
eff=lookup_widget(objet_graphique,"windowModifier");
gtk_widget_hide(eff);
window=create_windowModifier2();
gtk_widget_show (window);
}
else
{
output=lookup_widget(objet_graphique,"labelModifier");
strcpy(RE,"utilisateur n'existe pas");
gtk_label_set_text(GTK_LABEL(output),RE);
}
}


void
on_buttonretourmodifier1_clicked       (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *eff;
GtkWidget *windowAdmin;
windowAdmin=create_windowModifier();
gtk_widget_show (windowAdmin);
eff=lookup_widget(objet_graphique,"windowModifier2");
gtk_widget_hide(eff);
}





void
on_buttonModifier1_clicked             (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
FILE *l=NULL;
GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *username;
GtkWidget *password;
GtkWidget *j;
GtkWidget *m;
GtkWidget *a;
GtkWidget *cin;
GtkWidget *combobox;
utilisateur d;
int z=0;
int x=1;
char chaine[100];
FILE *n=NULL;


nom=lookup_widget (objet_graphique,"entrymnom");
prenom=lookup_widget (objet_graphique,"entrymprenom");
username=lookup_widget (objet_graphique,"entrymuser");
password=lookup_widget (objet_graphique,"entrympassword");
cin=lookup_widget (objet_graphique,"entrymcin");
j=lookup_widget (objet_graphique,"labelmresult");
combobox=lookup_widget(objet_graphique,"comboboxmodifer");

strcpy(d.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(d.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(d.username, gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(d.password, gtk_entry_get_text(GTK_ENTRY(password)));
strcpy(d.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(d.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));



if(q==0)
{
strcpy(chaine,"modification impossible (cin non verifié)");
gtk_label_set_text(GTK_LABEL(j),chaine);
}
if(q==1)
{
strcpy(chaine,"modifié avec succés");
gtk_label_set_text(GTK_LABEL(j),chaine);
modifier_user(d);
}

}


void
on_buttonretourchercher_clicked        (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *eff;
GtkWidget *windowAdmin;
windowAdmin=create_windowAdmin();
gtk_widget_show (windowAdmin);
eff=lookup_widget(objet_graphique,"windowChercher");
gtk_widget_hide(eff);
}


void
on_buttonChercher_clicked              (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
int x=0;
FILE *f=NULL;
char cin[20];
char RE[100];
GtkWidget *input;
GtkWidget *output;

input=lookup_widget(objet_graphique,"entrycher");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));
x=chercher_user(cin);
//output=lookup_widget(objet_graphique,"labelcher");

if(x==1)
{output=lookup_widget(objet_graphique,"labelcher");
strcpy(RE," utilisateur existe");
gtk_label_set_text(GTK_LABEL(output),RE);
}
else
{
output=lookup_widget(objet_graphique,"labelcher");
strcpy(RE,"utilisateur n'existe pas");
gtk_label_set_text(GTK_LABEL(output),RE);
}

}


void
on_buttonRetourAT_clicked              (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *eff;
GtkWidget *windowAdmin;
windowAdmin=create_windowAdmin();
gtk_widget_show (windowAdmin);
eff=lookup_widget(objet_graphique,"windowAffichert");
gtk_widget_hide(eff);
}


void
on_treeviewAT_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* role;
	gchar* nom;
	gchar* prenom;
	gchar* jour;
	gchar* mois;
	gchar* annee;
	gchar* username;
	gchar* password;
	gchar* cin;
	
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model,&iter,path))
	{
		gtk_tree_model_get (GTK_TREE_MODEL(model),&iter,0,&role,1,&nom,2,&prenom,3,&jour,4,&mois,5,&annee,6,&username,7,&password,8,&cin,-1);
		afficher_personne(treeview);

	}
}


void
on_buttonretourSupprimer_clicked       (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *eff;
GtkWidget *windowAdmin;
windowAdmin=create_windowAdmin();
gtk_widget_show (windowAdmin);
eff=lookup_widget(objet_graphique,"windowSupprimer");
gtk_widget_hide(eff);
}


void
on_buttonSupprimer_clicked             (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
int x=0;
char cin[20]="";
char RE[50];
GtkWidget *input;
GtkWidget *output;

input=lookup_widget(objet_graphique,"entrySupprimer");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));
x=chercher_user(cin);


if(x==1)
{
supprimer_user(cin);
output=lookup_widget(objet_graphique,"labelSupprimer");
strcpy(RE," utilisateur supprimé avec succés");
gtk_label_set_text(GTK_LABEL(output),RE);
}
else
{
output=lookup_widget(objet_graphique,"labelSupprimer");
strcpy(RE,"utilisateur n'existe pas");
gtk_label_set_text(GTK_LABEL(output),RE);
}
}


void
on_buttonverifier_exist_clicked        (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *m;
GtkWidget *cin;
utilisateur d;
int z=0;
int x=1;

FILE *n=NULL;
char id[20];

char mg[100];

cin=lookup_widget (objet_graphique,"entrymcin");
m=lookup_widget(objet_graphique,"labelconfirmat");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(cin)));


q=chercher_user(id);
if(q==0)
{
strcpy(mg,"cin n'existe pas (n'est pas modifiable)");
gtk_label_set_text(GTK_LABEL(m),mg);
}
else if(q==1)
{
strcpy(mg,"cin verifié");
gtk_label_set_text(GTK_LABEL(m),mg);
}
}
/////////////////////////////////////////////////////////////////////////
////Dashboard
/////////////////////////////////////////////////////////////////////////




void
on_meilleur_menu_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}
void
on_service_reclame_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *output;
char x[200];
int test=0;
test=serviceleplusreclame();
if(test==0)
{
output=lookup_widget(objet_graphique,"labelservicereclamee");
strcpy(x,"Le service le plus réclamé : Service d'Hébergement");
gtk_label_set_text(GTK_LABEL(output),x);
}
else
{
output=lookup_widget(objet_graphique,"labelservicereclamee");
strcpy(x,"Le service le plus réclamé : Service de Restauration");
gtk_label_set_text(GTK_LABEL(output),x);
}

}
void
on_listalarme_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{


}
void
on_capt_defc_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *val_min;
GtkWidget *val_max;
GtkWidget *output;
char fichCap[]="temperature.txt";
int capdef[1000];
int n,min,max,i;
char x[200],cap[100];


val_min=lookup_widget(objet_graphique, "spinbuttonvalmin");
val_max=lookup_widget(objet_graphique, "spinbuttonvalmax");
max=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(val_max));
min=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(val_min));
n=capteur_defc(fichCap,capdef,max,min);

if(n!=0)
{
output=lookup_widget(objet_graphique,"labelcapt_def");
strcpy(x,"les capteurs défectueux : ");


FILE *f=NULL;
f=fopen("capteur_defectueux.txt","r");
while(fscanf(f,"%s\n",cap)!=EOF)
{
strcat(x,cap);
strcat(x,"/");
}

gtk_label_set_text(GTK_LABEL(output),x);
}
else
{
output=lookup_widget(objet_graphique,"labelcapt_def");
strcpy(x,"pas de capteur défectueux");
gtk_label_set_text(GTK_LABEL(output),x);
}




}


void
on_buttonalleramonespace_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_buttonespaceetudiant_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}

/////////////////////////////////////////////////////////////////
////NUTITIONISTE
/////////////////////////////////////////////////////////////////
