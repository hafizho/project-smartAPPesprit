#include <gtk/gtk.h>
typedef struct { 
 char jour[5];
 char mois[5];
 char annee[5];
}
date;

typedef struct{
char id[20];
char nom[20];
char type[20];
char bloc[20];
date da;
char  d[10] ;
char valeur[20];
}capteur;

void ajoutercapteur(capteur c);

void affichercapteur(GtkWidget *liste);
void cherchercapteur(GtkWidget *liste,GtkWidget *l);
void affichertempcapteur(GtkWidget *liste);

void supprimercapteur(capteur c);
void modifiercapteur(char  id[20],capteur c);
void recherchecapteur(char id[20] );
/*
int ah_tab_capteur(capteur tab[200]);
void supprimercapteurbyid(char identi[20]);
*/
