#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "admin.h"


int importer(utilisateur user[] , int n)
{
   utilisateur u;
   int I=0;
    FILE *f=NULL;
    f=fopen("utilisateur.txt","a+");
    while(fscanf(f,"%s %s %s %d %d %d %s %s %s \n",u.role,u.nom,u.prenom,&u.jour,&u.mois,&u.annee,u.username,u.password,u.cin)!=EOF)
    {
n++;
strcpy(user[I].role,u.role);
strcpy(user[I].nom,u.nom);
strcpy(user[I].prenom,u.prenom);

strcpy(user[I].username,u.username);
strcpy(user[I].password,u.password);
strcpy(user[I].cin,u.cin);
user[I].jour=u.jour;
user[I].mois=u.mois;
user[I].annee=u.annee;
I++;
    }
    fclose(f);
return n;
}


int ajouter_user(utilisateur user[] ,utilisateur u ,int n)
{
n++;
strcpy(user[n-1].role,u.role);
strcpy(user[n-1].nom,u.nom);
strcpy(user[n-1].prenom,u.prenom);

strcpy(user[n-1].username,u.username);
strcpy(user[n-1].password,u.password);
strcpy(user[n-1].cin,u.cin);
user[n-1].jour=u.jour;
user[n-1].mois=u.mois;
user[n-1].annee=u.annee;
return(n);
}


void supprimer_user(char id[20])
{
utilisateur u;
FILE *f1=NULL;
FILE *f2=NULL;
f1=fopen("utilisateur.txt","r");
f2=fopen("util.txt","a+");
while(fscanf(f1,"%s %s %s %d %d %d %s %s %s\n",u.role,u.nom,u.prenom,&u.jour,&u.mois,&u.annee,u.username,u.password,u.cin)!=EOF)
{
if(strcmp(u.cin,id)!=0)
{
fprintf(f2,"%s %s %s %d %d %d %s %s %s\n",u.role,u.nom,u.prenom,u.jour,u.mois,u.annee,u.username,u.password,u.cin);
}
}
fclose(f1);
fclose(f2);
remove("utilisateur.txt");
rename("util.txt","utilisateur.txt");
}


int chercher_user(char id[])
{
FILE *f=NULL;
f=fopen("utilisateur.txt","r");
    utilisateur u;
    while(fscanf(f,"%s %s %s %d %d %d %s %s %s\n",u.role,u.nom,u.prenom,&u.jour,&u.mois,&u.annee,u.username,u.password,u.cin)!=EOF)
{
    if(strcmp(u.cin,id)==0)
    return 1;
}
return 0;
}



/*********************Affichage********************/
void afficher_user(utilisateur u ,utilisateur user[] ,int n)
{   int I;

    for(I=0;I<n;I++)
    {
        if(strcmp(u.role,user[I].role)==0)
      printf("%s %s %s %d %d %d %s %s %s \n",user[I].role,user[I].nom,user[I].prenom,user[I].jour,user[I].mois,user[I].annee,user[I].username,user[I].password,user[I].cin);
    }
}

void afficher_tout(utilisateur u ,utilisateur user[] ,int n)
{   int I;

    for(I=0;I<n;I++)
    {
      printf("%s %s %s %d %d %d %s %s %s \n", user[I].role,user[I].nom,user[I].prenom,user[I].jour,user[I].mois,user[I].annee,user[I].username,user[I].password,user[I].cin);
    }
}

/***************Modifier************************/
void modifier_user(utilisateur d)
{
int n;
char id[20];
utilisateur u,user[1000];
FILE *f1=NULL;
FILE *f2=NULL;
int i;

n=importer(user,n);
	for (i=0;i<n;i++)
		{
		if(strcmp(user[i].cin,d.cin)==0)
			{
			strcpy(user[i].nom,d.nom);
			strcpy(user[i].prenom,d.prenom);
			strcpy(user[i].username,d.username);
			strcpy(user[i].password,d.password);
			strcpy(user[i].role,d.role);			
			}
		}


sauvegarder(user,n);
}

/*
f1=fopen("utilisateur.txt","r");
f2=fopen("utilisat.txt","a+");

fflush(stdin);
while(fscanf(f1,"%s %s %s %d %d %d %s %s %s\n",u.role,u.nom,u.prenom,&u.jour,&u.mois,&u.annee,u.username,u.password,u.cin)!=EOF)
{
if(strcmp(u.cin,d.cin)==0);
{
strcpy(u.role,d.role);
strcpy(u.nom,d.nom);
strcpy(u.prenom,d.prenom);
strcpy(u.username,d.username);
strcpy(u.password,d.password);
}
fprintf(f2,"%s %s %s %d %d %d %s %s %s\n",u.role,u.nom,u.prenom,u.jour,u.mois,u.annee,u.username,u.password,u.cin);
}

fclose(f1);
fclose(f2);
remove("utilisateur.txt");
rename("utilisat.txt","utilisateur.txt");*/





void sauvegarder(utilisateur user[] , int n)
{ int i;
FILE *f = NULL;
f=fopen("utilisateur.txt","w+");

if ("f!=NULL")
{
for(i=0;i<n;i++)
{
fprintf(f,"%s %s %s %d %d %d %s %s %s \n",user[i].role,user[i].nom,user[i].prenom,user[i].jour,user[i].mois,user[i].annee,user[i].username,user[i].password,user[i].cin);
}
}
fclose(f);
}

enum
{
	
	ENOM,
	EPRENOM,
	EJOUR,
	EMOIS,
	EANNEE,
	ECIN,
	EUSERNAME,
	EPASSWORD,
	EROLE,
	COLUMNS
};

void afficher_personne(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char nom[30];
char prenom[30];
char jour[30];
char mois[30];
char annee[30];
char cin[30];
char username[30];
char password[30];
char role[30];

store=NULL;
FILE *f;

/*n=importer(user,n);
sprintf(jour,"%d",u.jour);
sprintf(mois,"%d",u.mois);
sprintf(annee,"%d",u.annee);

strcat(jour,'/');
strcat(mois,'/');
strcat(mois,annee);
strcat(jour,mois);
strcpy(date,jour);*/

store=GTK_LIST_STORE(gtk_tree_view_get_model(liste));
if(store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("role",renderer,"text",EROLE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",EPRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("username",renderer,"text",EUSERNAME,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("password",renderer,"text",EPASSWORD,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("cin",renderer,"text",ECIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("utilisateur.txt","r");
if(f==NULL)
{
return;
}
else
	{
f=fopen("utilisateur.txt","a+");
	while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",role,nom,prenom,jour,mois,annee,username,password,cin)!=EOF)
	{gtk_list_store_append(store,&iter);
gtk_list_store_append(store,&iter);	gtk_list_store_set(store,&iter,EROLE,role,ENOM,nom,EPRENOM,prenom,EJOUR,jour,EMOIS,mois,EANNEE,annee,EUSERNAME,username,EPASSWORD,password,ECIN,cin,-1);
	}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
	}
}


void afficher_p(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char nom[30];
char prenom[30];
char jour[30];
char mois[30];
char annee[30];
char cin[30];
char username[30];
char password[30];
char role[30];

store=NULL;
FILE *h;

store=GTK_LIST_STORE(gtk_tree_view_get_model(liste));
if(store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("role",renderer,"text",EROLE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",EPRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("username",renderer,"text",EUSERNAME,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("password",renderer,"text",EPASSWORD,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("cin",renderer,"text",ECIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
h=fopen("afficher.txt","r");
if(h==NULL)
{
return;
}
else
	{
h=fopen("afficher.txt","a+");
	while(fscanf(h,"%s %s %s %s %s %s %s %s %s\n",role,nom,prenom,jour,mois,annee,username,password,cin)!=EOF)
	{gtk_list_store_append(store,&iter);
gtk_list_store_append(store,&iter);	gtk_list_store_set(store,&iter,EROLE,role,ENOM,nom,EPRENOM,prenom,EJOUR,jour,EMOIS,mois,EANNEE,annee,EUSERNAME,username,EPASSWORD,password,ECIN,cin,-1);
	}
fclose(h);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
	}
}



int connexion(char a[50], char b[50])
{int x;
utilisateur u;
FILE *f=NULL;

f=fopen("utilisateur.txt","r");
while(fscanf(f,"%s %s %s %d %d %d %s %s %s\n",u.role,u.nom,u.prenom,&u.jour,&u.mois,&u.annee,u.username,u.password,u.cin)!=EOF)
{
if(strcmp(a,u.username)==0)
	{if(strcmp(b,u.password)==0)
		{
		if(strcmp(u.role,"Admin")==0)
			x=0;
		
		if(strcmp(u.role,"Agent_de_foyer")==0)
			x=1;

		if(strcmp(u.role,"Agent_de_restaurant")==0)
			x=2;
		
		if(strcmp(u.role,"Nutritionniste")==0)
			x=3;

		if(strcmp(u.role,"Technicien")==0)
			x=4;	
		
		if(strcmp(u.role,"Etudiant")==0)
			x=5;
		}
		
	}
}
return x;
}

void afficher(int p)
{
FILE *g=NULL;
int i=0;
utilisateur user[1000];
int n=0;


n=importer(user,n);
g=fopen("afficher.txt","w+");

if(p==0)
{
for(i=0;i<n;i++)
{
if(strcmp(user[i].role,"Admin")==0)
{
fprintf(g,"%s %s %s %d %d %d %s %s %s \n",user[i].role,user[i].nom,user[i].prenom,user[i].jour,user[i].mois,user[i].annee,user[i].username,user[i].password,user[i].cin);
}
}
}

else if(p==1)
{
for(i=0;i<n;i++)
{
if(strcmp(user[i].role,"Agent_de_foyer")==0)
{
fprintf(g,"%s %s %s %d %d %d %s %s %s \n",user[i].role,user[i].nom,user[i].prenom,user[i].jour,user[i].mois,user[i].annee,user[i].username,user[i].password,user[i].cin);
}
}
}

else if(p==2)
{
for(i=0;i<n;i++)
{
if(strcmp(user[i].role,"Agent_de_restaurant")==0)
{
fprintf(g,"%s %s %s %d %d %d %s %s %s \n",user[i].role,user[i].nom,user[i].prenom,user[i].jour,user[i].mois,user[i].annee,user[i].username,user[i].password,user[i].cin);
}
}
}

else if(p==3)
{
for(i=0;i<n;i++)
{
if(strcmp(user[i].role,"Nutritionniste")==0)
{
fprintf(g,"%s %s %s %d %d %d %s %s %s \n",user[i].role,user[i].nom,user[i].prenom,user[i].jour,user[i].mois,user[i].annee,user[i].username,user[i].password,user[i].cin);
}
}
}

else if(p==4)
{
for(i=0;i<n;i++)
{
if(strcmp(user[i].role,"Technicien")==0)
{
fprintf(g,"%s %s %s %d %d %d %s %s %s \n",user[i].role,user[i].nom,user[i].prenom,user[i].jour,user[i].mois,user[i].annee,user[i].username,user[i].password,user[i].cin);
}
}
}

else if(p==5)
{
for(i=0;i<n;i++)
{
if(strcmp(user[i].role,"Etudiant")==0)
{
fprintf(g,"%s %s %s %d %d %d %s %s %s \n",user[i].role,user[i].nom,user[i].prenom,user[i].jour,user[i].mois,user[i].annee,user[i].username,user[i].password,user[i].cin);
}
}
}
fclose(g);

}




////// partie 2 ///////

/*void alertesMVTFUMEE(alerte alertemvt[], alerte alertefumee[],char *fichmvt,char *fichfumee,int *nbaf,int *nbam )
{alerte alerte;
nbaf=0;
nbam=0;
FILE *f=NULL;
FILE *g=NULL;

f=fopen("fumee.txt","r");

while(fscanf(f,"%d %d %d %d\n", alerte.jour,alerte.heure,alerte.numCap,alerte.valeur)!=EOF)
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

}*/

utilisateur chercheru(char id[])
{utilisateur y,k;
FILE *f=NULL;
utilisateur u;
f=fopen("utilisateur.txt","r");
if(f!=NULL)
{    while(fscanf(f,"%s %s %s %d %d %d %s %s %s\n",u.role,u.nom,u.prenom,&u.jour,&u.mois,&u.annee,u.username,u.password,u.cin)!=EOF)
{
    if(strcmp(u.cin,id)==0)
	{	strcpy(y.role,u.role);
		strcpy(y.nom,u.nom);
		strcpy(y.prenom,u.prenom);
		strcpy(y.username,u.username);
		strcpy(y.password,u.password);
		strcpy(y.cin,u.cin);
		y.jour=u.jour;
		y.mois=u.mois;
		y.annee=u.annee;
    		
	}
fclose(f);
}
}
return y;
}


