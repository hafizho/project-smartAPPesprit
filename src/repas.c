#include "repas.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <gtk/gtk.h>

enum
{
ENOM_REPAS,
ETYPE_REPAS,
EDATE_REPAS,
EBOISSON_REPAS,
EDECHETS_REPAS,
COLUMNS
};


void ajouter_repas(repas rep){
    FILE *f_rep;
    f_rep=fopen("repas.txt","a");
    if(f_rep!=NULL)
    {
    fprintf(f_rep,"%s %s %d %s %d %s %s\n",rep.nom,rep.type,rep.date.jour,rep.date.mois,rep.date.annee,rep.suppl,rep.dechets);
    fclose(f_rep);
    }
}
void afficher_repas(GtkWidget *liste){
    GtkCellRenderer * renderer;
    GtkTreeViewColumn * column;
    GtkTreeIter iter;
    GtkListStore *store;
    GList * columns;

    repas rep;
    FILE * f_rep;
    char rep_date_str[30];
    

    store = gtk_tree_view_get_model(liste);
    
    if(store == NULL)
    {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", ENOM_REPAS, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Type", renderer, "text", ETYPE_REPAS, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Date", renderer, "text",EDATE_REPAS, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);        

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Boisson", renderer, "text", EBOISSON_REPAS, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);       

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Dechets", renderer, "text", EDECHETS_REPAS, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column); 

        
        
        renderer = gtk_cell_renderer_text_new();
        store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        columns = gtk_tree_view_get_columns (GTK_TREE_VIEW (liste));
        
    }

    gtk_list_store_clear(store);
    
    f_rep = fopen("repas.txt", "r");
    if (f_rep != NULL)
    {
        while (fscanf(f_rep,"%s %s %d %s %d %s %s\n",rep.nom,rep.type,&rep.date.jour,rep.date.mois,&rep.date.annee,rep.suppl,rep.dechets) != EOF)
        {
            sprintf(rep_date_str, "%d %s %d", rep.date.jour,rep.date.mois,rep.date.annee);
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, ENOM_REPAS, rep.nom,  ETYPE_REPAS, rep.type,EDATE_REPAS, rep_date_str , EBOISSON_REPAS, rep.suppl, EDECHETS_REPAS, rep.dechets, -1);
        }
        fclose(f_rep);
    }
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
    }
int supprimer_repas(repas rep){
    repas tmp_rep;
    FILE * f_rep;
    FILE * f_tmp_rep;
    int delete_check_rep = 0;
    f_rep = fopen("repas.txt", "r");
    f_tmp_rep = fopen("repas_tmp.txt", "w");

    if (f_rep != NULL && f_tmp_rep != NULL)
    {
        while (fscanf(f_rep,"%s %s %d %s %d %s %s\n",tmp_rep.nom,tmp_rep.type,&tmp_rep.date.jour,tmp_rep.date.mois,&tmp_rep.date.annee,tmp_rep.suppl,tmp_rep.dechets) != EOF)
        {
            if (!( (strcmp(tmp_rep.nom, rep.nom)==0) && (strcmp(tmp_rep.type, rep.type)==0) && (tmp_rep.date.jour == rep.date.jour) && (strcmp(tmp_rep.date.mois, rep.date.mois)==0) && (tmp_rep.date.annee == rep.date.annee)&& (strcmp(tmp_rep.suppl, rep.suppl)==0)&& (strcmp(tmp_rep.dechets, rep.dechets)==0)))
	 fprintf(f_tmp_rep, "%s %s %d %s %d %s %s\n ",tmp_rep.nom, tmp_rep.type, tmp_rep.date.jour, tmp_rep.date.mois, tmp_rep.date.annee, tmp_rep.suppl, tmp_rep.dechets) ;
            else delete_check_rep = 1;
        }

        fclose(f_rep);
        fclose(f_tmp_rep);
        remove("repas.txt");
        rename("repas_tmp.txt", "repas.txt");
    }
    return delete_check_rep;    
}
void modifier_repas(repas old_rep, repas new_rep){
    repas tmp_rep;
    FILE * f_rep;
    FILE * f_tmp_rep;

    f_rep = fopen("repas.txt", "r");
    f_tmp_rep = fopen("repas_tmp.txt", "w");

    if (f_rep != NULL && f_tmp_rep != NULL)
    {
        while (fscanf(f_rep,"%s %s %d %s %d %s %s\n",tmp_rep.nom,tmp_rep.type,&tmp_rep.date.jour,tmp_rep.date.mois,&tmp_rep.date.annee,tmp_rep.suppl,tmp_rep.dechets) != EOF)
        {
            if ((strcmp(tmp_rep.nom, old_rep.nom)==0) && (strcmp(tmp_rep.type, old_rep.type)==0) && (tmp_rep.date.jour == old_rep.date.jour) && (strcmp(tmp_rep.date.mois, old_rep.date.mois)==0) && (tmp_rep.date.annee == old_rep.date.annee)&& (strcmp(tmp_rep.suppl, old_rep.suppl)==0)&& (strcmp(tmp_rep.dechets, old_rep.dechets)==0))
	            fprintf(f_tmp_rep, "%s %s %d %s %d %s %s\n ",new_rep.nom, new_rep.type, new_rep.date.jour, new_rep.date.mois, new_rep.date.annee, new_rep.suppl, new_rep.dechets);
            else 
                fprintf(f_tmp_rep, "%s %s %d %s %d %s %s\n ",tmp_rep.nom, tmp_rep.type, tmp_rep.date.jour, tmp_rep.date.mois, tmp_rep.date.annee, tmp_rep.suppl, tmp_rep.dechets) ;
        }

        fclose(f_rep);
        fclose(f_tmp_rep);
        remove("repas.txt");
        rename("repas_tmp.txt", "repas.txt");
    }


}
