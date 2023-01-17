#ifdef HAVE_CONFIG_H
#   include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction1.h"
#include <gtk/gtk.h>
etudiant1 nb;
utilisateur U;
enum
{
	CIN,
	NOM,
	PRENOM,
	CLASSE,
	ROLE,
	PASSWORD,
	DATE,
	COLUMNS,
};




void Ajouter(utilisateur U)
 { 

FILE *f=NULL;
f=fopen("ajout_etudiant.txt","a+"); 


if(f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s %d/%d/%d\n",U.nom,U.prenom,U.role,U.cin,U.classe,U.password,U.date.jour,U.date.mois,U.date.annee);
fclose(f);
 } 
}


void Afficher(GtkWidget *liste, int filtr[6]) {

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
utilisateur U;
    char nom[100];
    char prenom[100];
    char cin[100];
    char role[100];
    char classe[100];
    char date[100];
    char password[100];
    store=NULL;
  FILE *f=NULL;

store = gtk_tree_view_get_model(liste);


if (store==NULL)
{

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("classe",renderer,"text",CLASSE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("role",renderer,"text",ROLE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("password",renderer,"text",PASSWORD, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Date de naissance",renderer,"text",DATE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

}
store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);


f=fopen("ajout_etudiant.txt","r");
if(f==NULL)
{


	return;
}

else

{ f = fopen("ajout_etudiant.txt","a+");

while(fscanf(f,"%s %s %s %s %s %s %s\n",nom,prenom,role,cin,classe,password,date)!=EOF){
if ((filtr[0] && strcmp(role, "Admin") == 0) || (filtr[1] && strcmp(role, "Etudiant") == 0) || (filtr[2] && strcmp(role, "technicien") == 0)
    || (filtr[3] && strcmp(role, "A.foyer") == 0) || (filtr[4] && strcmp(role, "A.resto") == 0) || (filtr[5] && strcmp(role, "nutrionniste") == 0))
{
gtk_list_store_append (store,&iter);
gtk_list_store_set (store, &iter, CIN, cin, NOM, nom, PRENOM, prenom, CLASSE, classe, ROLE, role, PASSWORD, password, DATE, date, -1);
}
//else
//fprintf(f, "%d %d %d %d %d %d %s", filtr[0], filtr[1], filtr[2], filtr[3], filtr[4], filtr[5], role);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}

void Modifier (utilisateur U) {
 char nom[100];
    char prenom[100];
    char cin[100];
    char role[100];
    char classe[100];
    char password[100];
    int jour;
    int mois;
    int annee;

FILE*f=NULL;
FILE*f1=NULL;

f=fopen("ajout_etudiant.txt","r");
f1=fopen("etudiants.txt","w+");
while(fscanf(f,"%s %s %s %s %s %s %d/%d/%d\n",nom,prenom,role,cin,classe,password,&jour,&mois,&annee)!=EOF)
{
	if( strcmp(U.cin,cin)==0)
	{
	fprintf(f1,"%s %s %s %s %s %s %d/%d/%d\n",U.nom,U.prenom,U.role,U.cin,U.classe,U.password,U.date.jour,U.date.mois,U.date.annee);
	}
	else
	{
	fprintf(f1,"%s %s %s %s %s %s %d/%d/%d\n",nom,prenom,role,cin,classe,password,jour,mois,annee);
	}

}
fclose(f);
fclose(f1);
remove("ajout_etudiant.txt");
rename("etudiants.txt","ajout_etudiant.txt");
}







void Supprimer(utilisateur U){
    char nom[100];
    char prenom[100];
    char cin[100];
    char role[100];
    char classe[100];
    char date[100];
    char password[100];

FILE *f,*g ;
f = fopen("ajout_etudiant.txt", "r");
g = fopen("TempEtudiants.txt", "w");


if(f ==NULL || g==NULL)
{
	return;
}

else{

while(fscanf(f,"%s %s %s %s %s %s %s\n",nom,prenom,role,cin,classe,password,date)!=EOF)
{
	if(strcmp(U.cin,cin)!=0 )
	fprintf(g,"%s %s %s %s %s %s %s\n",nom,prenom,role,cin,classe,password,date);
}

fclose(f);
fclose(g);
remove("ajout_etudiant.txt");
rename("TempEtudiants.txt","ajout_etudiant.txt");
 }}






void rechercher(utilisateur U,char text[100]) {
char date[100];
FILE *f,*n ;
remove("rech.txt");
f = fopen("ajout_etudiant.txt", "r");
n = fopen("rech.txt", "a+");



if(f ==NULL || n==NULL)
{
	return;
}

else{

while(fscanf(f,"%s %s %s %s %s %s %s\n",U.nom,U.prenom,U.role,U.cin,U.classe,U.password,date)!=EOF)
{
	if(strcmp(U.cin,text)==0 )
	fprintf(n,"%s %s %s %s %s %s %s\n",U.nom,U.prenom,U.role,U.cin,U.classe,U.password,date);
     
}

fclose(f);
fclose(n);

}
}










void Afficher2(GtkWidget *liste, int filtr[6]) {

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
utilisateur U;
    char nom[100];
    char prenom[100];
    char cin[100];
    char role[100];
    char classe[100];
    char date[100];
    char password[100];
    store=NULL;
  FILE *f=NULL;

store = gtk_tree_view_get_model(liste);


if (store==NULL)
{

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("classe",renderer,"text",CLASSE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("role",renderer,"text",ROLE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("password",renderer,"text",ROLE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Date de naissance",renderer,"text",DATE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


}
store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);


f=fopen("rech.txt","r");
if(f==NULL)
{


	return;
}

else

{ f = fopen("rech.txt","a+");

while(fscanf(f,"%s %s %s %s %s %s %s\n",nom,prenom,role,cin,classe,password,date)!=EOF){

if ((filtr[0] && strcmp(role, "Admin") == 0) || (filtr[1] && strcmp(role, "Etudiant") == 0) || (filtr[2] && strcmp(role, "technicien") == 0)
    || (filtr[3] && strcmp(role, "A.foyer") == 0) || (filtr[4] && strcmp(role, "A.resto") == 0) || (filtr[5] && strcmp(role, "nutrionniste") == 0))
{
gtk_list_store_append (store,&iter);
gtk_list_store_set (store, &iter, CIN, cin, NOM, nom, PRENOM, prenom, CLASSE, classe, ROLE, role, PASSWORD, password, DATE, date, -1);
}
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}

void nb_etudiant(etudiant1 *nb) {
int k=0 ;

char pere[100]="1ere";
char deme[100]="2eme";
char teme[100]="3eme";
char qeme[100]="4eme";
char ceme[100]="5eme";
char str1[100];
char str2[100];
char str3[100];
char str4[100];
char str5[100];
char date[100];
int trouve1 = 0;
int trouve2 = 0;
int trouve3 = 0;
int trouve4 = 0;
int trouve5 = 0;
FILE *fil=NULL;


FILE *f,*g ;

f = fopen("ajout_etudiant.txt", "r");
g = fopen("nb_etud.txt", "w+");


if(f ==NULL || g==NULL)
{
	return;
}

else{

while(fscanf(f,"%s %s %s %s %s %s %s\n",U.nom,U.prenom,U.role,U.cin,U.classe,U.password,date)!=EOF)
{
if(strcmp(U.classe,pere) == 0)
trouve1=trouve1+1;
 else if(strcmp(U.classe,deme) == 0)
trouve2=trouve2+1;
else if (strcmp(U.classe,teme) == 0)
trouve3=trouve3+1;
else if(strcmp(U.classe,qeme) == 0)
trouve4=trouve4+1;
else if(strcmp(U.classe,ceme) == 0)
trouve5=trouve5+1;
}

sprintf(nb->pr,"%d",trouve1);
sprintf(nb->dr,"%d",trouve2);
sprintf(nb->tr,"%d",trouve3);
sprintf(nb->qr,"%d",trouve4);
sprintf(nb->cr,"%d",trouve5);




fprintf(g,"%s %s %s %s %s\n",nb->pr,nb->dr,nb->tr,nb->qr,nb->cr);
fclose(g);
fclose(f);
}

}










