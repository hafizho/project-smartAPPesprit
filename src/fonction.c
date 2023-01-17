#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <gtk/gtk.h>
#include "fonction.h"
#include <string.h>
int verif (char identifient[], char date[])
{
int trouve= -1;
FILE *f=NULL;
char ch1[150];
char ch2[150];
f=fopen("reclamation.txt","r");
if (f!=NULL)
{
while (fscanf(f, "%s %s\n",ch1,ch2)!=EOF)
{
if ((strcmp(ch1,identifient)==0)&&(strcmp(ch2,date)==0))
trouve=1;
}
fclose(f);
}
return (trouve);
}
void  utchoix(int s ,char choix[20])
{
if (s == 1)
	strcpy(choix,"accepter");
else strcpy(choix,"desaccord");
}
void resultat(int chois[],char texte[])
{
	strcpy(texte,"j'accepte les conditions ");
	if (chois[0]==1)
	strcat(texte,"accepté");
}
enum
{
	CONTENU,
	SERVICE,
	IDENTIFIENT,
	TYPE,
	DATE,
	CHOIX,
	COLUMNS,
};
void afficher_reclamation(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char contenu[20];
	char service[20];
	char identifient[20];
	char date[20];
	char type[20];
	
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
	renderer=gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("contenu",renderer, "text",CONTENU,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	renderer=gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("service",renderer, "text",SERVICE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	renderer=gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("identifient",renderer, "text",IDENTIFIENT,NULL);
	renderer=gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("date",renderer, "text",DATE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	renderer=gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("type",renderer, "text",TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	renderer=gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("identifient",renderer, "text",IDENTIFIENT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	renderer=gtk_cell_renderer_text_new ();
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	f=fopen("reclamation.txt","r");
	if (f==NULL)
	{
	return;
	}
	else
	{f =fopen("reclamation.txt","a+");
		while(fscanf(f," %s %s %s %s %s \n ",contenu,service,identifient,date,type)!=EOF)
		{
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,CONTENU,contenu,SERVICE,service,IDENTIFIENT,identifient,DATE,date,TYPE,type,-1);
		}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
}
void supprimer_reclamation(reclamation c)
{
	char date[200];
	
FILE *f,*g;
f= fopen("reclamation.txt","r");
g=fopen("sp.txt","w");
	if(f==NULL || g==NULL)
	{
		return;
	}
	else{
		while(fscanf(f,"%s \n",date)!=EOF)
		{
					if (strcmp(c.date,date)!=0)
			fprintf(g,"%s  \n",date);
		}
		fclose(f);
		fclose(g);
remove("reclamation.txt");
rename("sp.txt","reclamation.txt");
}
}
void modifier_reclamation(reclamation c)
{
FILE *F2;
FILE *F1;
    char date1[200];
    char identifient[200];
    char contenu[200];
    char service[200];
    char date[200];
    char type[200];
	

    F1=fopen("reclamation.txt","r");
    F2=fopen("modif.txt","w");
    if(F1 != NULL)
     {
        while(fscanf(F1,"%s %s %s %s %s \n",contenu,service,identifient,type,date)!=EOF)
        {
            		if (strcmp(date,date1)!=0) 
            {
                printf("ecrire conetnu \n");
                scanf("%s",contenu);
                printf("ecrire service");
                scanf("%s",service);
                printf("ecrire id ");
                scanf("%s",identifient);
                
		printf("ecrire type ");
                scanf("%s",type);
		printf("ecrire date");
                scanf("%s",date);
                strcpy(c.contenu,contenu);
                strcpy(c.service,service);
                strcpy(c.identifient,identifient);
                strcpy(c.date,date);
		strcpy(c.type,type);
                fprintf(F2,"%s %s %s %s %s \n",contenu,service,identifient,type,date);


            }



        }

    }
    fclose(F1);
    fclose(F2);
    remove("reclamation.txt");
    rename("modif.txt","reclamation.txt");
    getchar();
}

