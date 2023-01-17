
#include <gtk/gtk.h>

typedef struct naissance{


int jour;
int mois;
int annee;
} naissance;


typedef struct utilisateur
{
    char nom[100];
    char prenom[100];
    char cin[100];
    char role[100];
    char classe[100];
    char password[100];
    naissance date;
}utilisateur;

typedef struct etudiant1
{
char pr[100];
char dr[100];
char tr[100];
char qr[100];
char cr[100];
}etudiant1;




void Ajouter(utilisateur U);
void Afficher(GtkWidget *liste, int filtr[6]);
void Modifier (utilisateur U);
void Supprimer(utilisateur U) ;
void rechercher(utilisateur U, char text[100]);
void nb_etudiant(etudiant1 *nb);
void Afficher2(GtkWidget *liste, int filtr[6]);
