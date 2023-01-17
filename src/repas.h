#ifndef REPAS_H_INCLUDED
#define REPAS_H_INCLUDED

#include <gtk/gtk.h>
typedef struct aminedt
{
	int jour;
	char mois[20];
	int annee;
}Dateamine;

typedef struct rep
{   
    char nom[20];
	char type[20];
   	Dateamine date;
	char suppl[5];
	char dechets[10];
}repas;

void ajouter_repas(repas rep);
void afficher_repas(GtkWidget *liste);
int supprimer_repas(repas rep);
void modifier_repas(repas old_rep, repas new_rep);
#endif // REPAS_H_INCLUDED