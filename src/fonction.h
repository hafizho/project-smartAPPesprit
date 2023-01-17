#include <gtk/gtk.h>

int verif (char date[], char identifient[]);
typedef struct {
char contenu[20];
char service[20];
char date[20];
char type[20];
char identifient[20];
char choix[20];
} reclamation;

void choix1(int choix,char msg[]);
void ajouter_reclamation(reclamation c);
void afficher_reclamation(GtkWidget *liste);
void supprimer_reclamation(reclamation c);
void modifier_reclamation(reclamation c);

