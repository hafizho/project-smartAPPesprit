#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdbool.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "hebergement.h"
#include "fonction.h"
#include "capteur.h"
#include "fonction1.h"
#include "repas.h"
char text[100];
int filtr[6] = { 1, 1, 1, 1, 1, 1 };
char rol[100];
char rol2[100];
int x;
utilisateur ug;
etudiant nb ;
guint jr;
guint mr;
guint ar;
char choix[20];
int checkbutton[0];
char msg[20];
int test = 0;
char  ted[20];
enum
{
ENOM_REPAS,
ETYPE_REPAS,
EDATE_REPAS,
EBOISSON_REPAS,
EDECHETS_REPAS,
COLUMNS1
};
repas gl_rep;
enum 
{
EID,
ENOM,
ETYPE,
EJOUR,
EMOIS,
EANNEE,
EVALEUR,
EBLOC,
ED,
COLUMNS,
};

void
on_button_1_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj_hebergement, *dashboard_hebergement;


dashboard_hebergement=lookup_widget(objet,"dashboard_hebergement");

//gtk_widget_destroy(dashboard_hebergement);
aj_hebergement=lookup_widget(objet,"aj_hebergement");
aj_hebergement=create_aj_hebergement();

gtk_widget_show(aj_hebergement);
}


void
on_button_2_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod_hebergement, *dashboard_hebergement;


dashboard_hebergement=lookup_widget(objet,"dashboard_hebergement");

//gtk_widget_destroy(dashboard_hebergement);
mod_hebergement=lookup_widget(objet,"mod_hebergement");
mod_hebergement=create_mod_hebergement();

gtk_widget_show(mod_hebergement);
}


void
on_button_3_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af_hebergement, *dashboard_hebergement;


dashboard_hebergement=lookup_widget(objet,"dashboard_hebergement");

//gtk_widget_destroy(dashboard_hebergement);
af_hebergement=lookup_widget(objet,"af_hebergement");
af_hebergement=create_af_hebergement();

gtk_widget_show(af_hebergement);

treeview=lookup_widget(af_hebergement,"treeview_hebergement");

afficher_hebergement(treeview,"hebergement.txt");
}


void
on_button_4_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af_alarme, *dashboard_hebergement;


dashboard_hebergement=lookup_widget(objet,"dashboard_hebergement");

//gtk_widget_destroy(dashboard_hebergement);
af_alarme=lookup_widget(objet,"af_alarme");
af_alarme=create_af_alarme();

gtk_widget_show(af_alarme);

treeview=lookup_widget(af_alarme,"treeview_alarme");

afficher_alarme(treeview,"alarme.txt");
}


void
on_button_af_alarme_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af_alarme;


af_alarme=lookup_widget(objet,"af_alarme");

gtk_widget_destroy(af_alarme);
af_alarme=lookup_widget(objet,"af_alarme");
af_alarme=create_af_alarme();

gtk_widget_show(af_alarme);

treeview=lookup_widget(af_alarme,"treeview_alarme");

afficher_alarme(treeview,"alarme.txt");
}


void
on_treeview_hebergement_row_activated  (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gint id;
	etudiant e;
	GtkWidget *pInfo;
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path)){
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,-1);
	e.id=id; pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Voulez-vous vraiment\nsupprimer cet étudiant?");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_YES:
	gtk_widget_destroy(pInfo);
	supprimer_hebergement(e,"hebergement.txt");
	afficher_hebergement(treeview,"hebergement.txt");
	break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(pInfo);
	break;
}	
}
}


void
on_button_af_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af_hebergement;


af_hebergement=lookup_widget(objet,"af_hebergement");

gtk_widget_destroy(af_hebergement);
af_hebergement=lookup_widget(objet,"af_hebergement");
af_hebergement=create_af_hebergement();

gtk_widget_show(af_hebergement);

treeview=lookup_widget(af_hebergement,"treeview_hebergement");

afficher_hebergement(treeview,"hebergement.txt");
}


void
on_button_mod_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod1, *mod2, *mod3, *mod4, *mod5, *mod6, *bloc1, *bloc2, *bloc3, *pInfo;
etudiant e;
int c;
mod1=lookup_widget(objet,"mod1");
mod2=lookup_widget(objet,"mod2");
mod3=lookup_widget(objet,"mod3");
bloc1=lookup_widget(objet,"modA");
bloc2=lookup_widget(objet,"modB");
bloc3=lookup_widget(objet,"modC");
mod4=lookup_widget(objet,"mod4");
mod5=lookup_widget(objet,"mod5");
mod6=lookup_widget(objet,"mod6");
e.id=atoi(gtk_entry_get_text(GTK_ENTRY(mod1)));
strcpy(e.prenom,gtk_entry_get_text(GTK_ENTRY(mod2)));
strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(mod3)));
strcpy(e.bloc,gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(bloc1))==1?"A":gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(bloc2))==1?"B":"C");
e.chambre=gtk_combo_box_get_active(GTK_COMBO_BOX(mod4))+1;
e.tel=atoi(gtk_entry_get_text(GTK_ENTRY(mod5)));
strcpy(e.email,gtk_entry_get_text(GTK_ENTRY(mod6)));
modifier_hebergement(e,"hebergement.txt");
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Etudiant modifié avec succès");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}


void
on_check_id_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod1, *mod2, *mod3, *mod4, *mod5, *mod6, *pInfo, *bloc1, *bloc2, *bloc3;
etudiant p;
int a=0;
char ch[20];
FILE *f;
mod1=lookup_widget(objet,"mod1");
mod2=lookup_widget(objet,"mod2");
mod3=lookup_widget(objet,"mod3");
bloc1=lookup_widget(objet,"modA");
bloc2=lookup_widget(objet,"modB");
bloc3=lookup_widget(objet,"modC");
mod4=lookup_widget(objet,"mod4");
mod5=lookup_widget(objet,"mod5");
mod6=lookup_widget(objet,"mod6");
int id = atoi(gtk_entry_get_text(GTK_ENTRY(mod1)));
f = fopen("hebergement.txt","r");
if(f!=NULL){
while(fscanf(f,"%d %s %s %d %d %d %s %d %d %s\n",&(p.id),p.prenom,p.nom,&(p.d.j),&(p.d.m),&(p.d.a),p.bloc,&(p.chambre),&(p.tel),p.email)!=EOF)
	{
		if(p.id==id){
			a=1;
			break;
                 }
	}
fclose(f);
}
if(a==1){
gtk_entry_set_text(GTK_ENTRY(mod2),p.prenom);
gtk_entry_set_text(GTK_ENTRY(mod3),p.nom);
strcmp(p.bloc,"A")==0?gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(bloc1),TRUE):strcmp(p.bloc,"B")==0?gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(bloc2),TRUE):gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(bloc3),TRUE);
gtk_combo_box_set_active(GTK_COMBO_BOX(mod4),p.chambre-1);
sprintf(ch,"%d",p.tel);
gtk_entry_set_text(GTK_ENTRY(mod5),ch);
gtk_entry_set_text(GTK_ENTRY(mod6),p.email);
}
else{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Etudiant introuvable");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}
}


void
on_button_aj_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj1, *aj2, *aj3, *aj4, *aj5, *aj6, *bloc1, *bloc2, *bloc3;
GtkCalendar *ajc;
etudiant e;
int c;
guint day, month, year;
aj1=lookup_widget(objet,"aj1");
aj2=lookup_widget(objet,"aj2");
aj3=lookup_widget(objet,"aj3");
ajc=lookup_widget(objet,"ajc");
bloc1=lookup_widget(objet,"ajA");
bloc2=lookup_widget(objet,"ajB");
bloc3=lookup_widget(objet,"ajC");
aj4=lookup_widget(objet,"aj4");
aj5=lookup_widget(objet,"aj5");
aj6=lookup_widget(objet,"aj6");
e.id=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(aj1));
strcpy(e.prenom,gtk_entry_get_text(GTK_ENTRY(aj2)));
strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(aj3)));
gtk_calendar_get_date(GTK_CALENDAR(ajc), &day, &month, &year);
e.d.j=year;
e.d.m=month+1;
e.d.a=day;
strcpy(e.bloc,gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(bloc1))==1?"A":gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(bloc2))==1?"B":"C");
c=gtk_combo_box_get_active(GTK_COMBO_BOX(aj4));
e.chambre = c==0?1:c==1?2:3;
e.tel=atoi(gtk_entry_get_text(GTK_ENTRY(aj5)));
strcpy(e.email,gtk_entry_get_text(GTK_ENTRY(aj6)));
ajouter_hebergement(e,"hebergement.txt");
}


void
on_button5_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *recherche, *dashboard_hebergement;


dashboard_hebergement=lookup_widget(objet,"dashboard_hebergement");

//gtk_widget_destroy(dashboard_hebergement);
recherche=lookup_widget(objet,"recherche");
recherche=create_recherche();

gtk_widget_show(recherche);
}


void
on_chercher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *r1, *r2, *r3, *r4, *r5, *r6, *r7, *r8, *pInfo;
char date_naissance[20], tel[20];
r1=lookup_widget(objet,"r1");
r2=lookup_widget(objet,"r2");
r3=lookup_widget(objet,"r3");
r4=lookup_widget(objet,"r4");
r5=lookup_widget(objet,"r5");
r6=lookup_widget(objet,"r6");
r7=lookup_widget(objet,"r7");
r8=lookup_widget(objet,"r8");
int id = atoi(gtk_entry_get_text(GTK_ENTRY(r1)));
etudiant p = chercher_hebergement(id,"hebergement.txt");
if (p.id==-1){
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"ID introuvable");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}
else{
gtk_label_set_text(GTK_LABEL(r2),p.prenom);
gtk_label_set_text(GTK_LABEL(r3),p.nom);
sprintf(date_naissance,"%d/%d/%d",p.d.j,p.d.m,p.d.a);
gtk_label_set_text(GTK_LABEL(r4),date_naissance);
gtk_label_set_text(GTK_LABEL(r5),p.bloc);
gtk_label_set_text(GTK_LABEL(r6),p.chambre==1?"Individuelle":p.chambre==2?"Double":"Triple");
sprintf(tel,"%d",p.tel);
gtk_label_set_text(GTK_LABEL(r7),tel);
gtk_label_set_text(GTK_LABEL(r8),p.email);
}
}


void
on_radioaccepter_toggled               (GtkToggleButton *togglebutton,
                                       gpointer         user_data)

{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
strcpy("accepter",choix);
}

void
on_radiodesaccord_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
strcpy("desaccord",choix);
}

void
on_admincheck_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if (gtk_toggle_button_get_active(togglebutton))
checkbutton[0]=1;
}

void
on_incription_clicked                  (GtkButton       *button,
					gpointer         user_data)
{
FILE *f=NULL;
GtkWidget *contenu,*service,*date,*type,*identifient, *a_connexion;
char contenu1[150];
char service1[150];
char date1[150];
char type1[150];
char identifient1[150];
char choix1[150];
reclamation c;
contenu = lookup_widget(button, "a_vn");
service = lookup_widget(button,"a_vp");
date = lookup_widget(button,"a_un");
type = lookup_widget(button,"a_rl");
identifient = lookup_widget(button,"a_mdp");
strcpy(contenu1, gtk_entry_get_text(GTK_ENTRY(contenu)));
strcpy(service1, gtk_entry_get_text(GTK_ENTRY(service)));
strcpy(date1, gtk_entry_get_text(GTK_ENTRY(date)));
strcpy(type1, gtk_entry_get_text(GTK_ENTRY(type)));
strcpy(identifient1, gtk_entry_get_text(GTK_ENTRY(identifient)));
strcpy(choix,choix1);
f=fopen("reclamation.txt","a+");
if (f!=NULL)                                        
{
fprintf(f," %s %s %s %s %s \n",contenu1,service1,identifient1,date1,type1);
fclose(f);
}
else 
printf(" \n not found ");
if (checkbutton[0] == 1) 
{
GtkWidget  *a_connexion; 
a_connexion=create_a_connexion();
gtk_widget_show(a_connexion);
}
}

void
on_az_cnx_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *date,*identifient, *a_admin;
int user[400];
int mdp[400];
int trouve;

date = lookup_widget(button,"a_us1");
identifient = lookup_widget(button,"a_mdp1");
strcpy(user, gtk_entry_get_text(GTK_ENTRY(date)));
strcpy(mdp, gtk_entry_get_text(GTK_ENTRY(identifient)));
trouve=verif(user,mdp);
if (trouve==1)
{
a_admin=create_a_admin();
gtk_widget_show(a_admin);
}
}

void
on_affiche_tab_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *a_admin;
GtkWidget *adminaffiche;
GtkWidget *treeview1;
a_admin=lookup_widget(button,"a_admin");
gtk_widget_destroy(a_admin);
adminaffiche=lookup_widget(button,"adminaffiche");
adminaffiche=create_adminaffiche();
gtk_widget_show(adminaffiche);
treeview1=lookup_widget(adminaffiche,"treeview1");
afficher_reclamation(treeview1);
}
void
on_tab_sup_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *a_suppression; 
a_suppression=create_a_suppression();
gtk_widget_show(a_suppression);
}

void
on_tab_modif_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *a_modif; 
a_modif=create_a_modif();
gtk_widget_show(a_modif);
}
void
on_radioaccepter1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
strcpy("accepter",choix);
}
void
on_radiodesaccord1_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
strcpy("desaccord",choix);
}
void
on_ad_ajout1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ad_contenu,*ad_service,*ad_date,*ad_type,*ad_identifient, *adminaffiche;
char contenu[20];
char service[20];
char date[20];
char type[20];
char identifient[20];
char choix1[20];
reclamation c;
adminaffiche=lookup_widget(button,"adminaffiche");
ad_contenu = lookup_widget(button, "ad_contenu1");
ad_service = lookup_widget(button,"ad_service1");
ad_date = lookup_widget(button,"ad_date1");
ad_type = lookup_widget(button,"ad_type1");
ad_identifient = lookup_widget(button,"ad_identifient1");
strcpy(c.contenu, gtk_entry_get_text(GTK_ENTRY(ad_contenu)));
strcpy(c.service, gtk_entry_get_text(GTK_ENTRY(ad_service)));
strcpy(c.date, gtk_entry_get_text(GTK_ENTRY(ad_date)));
strcpy(c.type, gtk_entry_get_text(GTK_ENTRY(ad_type)));
strcpy(c.identifient, gtk_entry_get_text(GTK_ENTRY(ad_identifient)));
strcpy(choix1,choix);
FILE *f;
f=fopen("reclamation.txt","a+");
if (f!=NULL)
{
fprintf(f," %s %s %s %s %s %s\n",contenu,service,date,type,identifient,choix);
fclose(f);
}
{
GtkWidget  *adminaffiche; 
adminaffiche=create_adminaffiche();
gtk_widget_show(adminaffiche);
}
}
void
on_delete_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *as_date;
reclamation c;
as_date = lookup_widget(button,"as_date1");
strcpy(c.date, gtk_entry_get_text(GTK_ENTRY(as_date)));
supprimer_reclamation(c);
}

void
on_md_modifier_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *md_date;
reclamation c;
md_date = lookup_widget(button,"modifdate");
strcpy(c.date, gtk_entry_get_text(GTK_ENTRY(md_date)));
GtkWidget  *ad_modif; 
ad_modif=create_ad_modif();
gtk_widget_show(ad_modif);
}

void
on_md_ok_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *md_date, *adminaffiche, *a_admin;
a_admin=lookup_widget(button,"a_dmin");
a_admin=create_a_admin();
gtk_widget_show(a_admin);
}

void
on_retour_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *a_admin, *adminaffiche;
a_admin=lookup_widget(button,"a_admin");
a_admin=create_a_admin();
gtk_widget_show(a_admin);
}


void
on_button11_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *a_admin, *adminaffiche;
a_admin=lookup_widget(button,"a_admin");
a_admin=create_a_admin();
gtk_widget_show(a_admin);
}

void
on_button111_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
capteur c;
GtkWidget *input1,*input2,*input5, *combobox1,*spinbutton1,*spinbutton2,*spinbutton3,*lbl,*ck1;
GtkWidget *fenetre_ajout,*fenetre_affiche;
int j,m,a;
char jour[20],mois[20],annee[20];
fenetre_ajout=lookup_widget(objet,"fenetre_ajout");
input1=lookup_widget(objet,"entry1");
input2=lookup_widget(objet,"entry2");

input5=lookup_widget(objet,"entry5");

spinbutton1=lookup_widget(objet,"spinbutton1");
spinbutton2=lookup_widget(objet,"spinbutton2");
spinbutton3=lookup_widget(objet,"spinbutton3");

combobox1=lookup_widget(objet,"combobox1");
strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton1));
m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton2));
a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton3));

sprintf(jour,"%d\0",j);
sprintf(mois,"%d\0",m);
sprintf(annee,"%d\0",a);


strcpy(c.da.jour,jour);
strcpy(c.da.mois,mois);
strcpy(c.da.annee,annee);

strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(input5)));
printf("%s",combobox1);


lbl=lookup_widget(objet,"label25");

char  msg[20];

if(test==0)

{
 strcpy(c.d,"etat0");
//strcpy(msg,"bloc");
//gtk_label_set_text(GTK_LABEL(lbl),msg);
}
else  strcpy(c.d,"etat1");

if(!strcmp(ted,"block"))

{
strcpy(c.bloc,"etage1");
gtk_label_set_text(GTK_LABEL(lbl),msg);
}

if(!strcmp(ted,"block2"))

{
strcpy(c.bloc,"etage2");
gtk_label_set_text(GTK_LABEL(lbl),msg);
}


if(!strcmp(ted,"block3"))

{
strcpy(c.bloc,"etage3");
gtk_label_set_text(GTK_LABEL(lbl),msg);
}








ajoutercapteur(c);

//////////////////////////////////////////////////////

fenetre_ajout=lookup_widget(objet,"fenetre_ajout");
gtk_widget_destroy(fenetre_ajout);
fenetre_affiche=lookup_widget(objet,"fenetre_affiche");
fenetre_affiche=create_fenetre_affiche();
gtk_widget_show(fenetre_affiche);

/////////////////////////////////////////////////////
}


void
on_button222_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_affiche;
GtkWidget *treeview1;
fenetre_ajout=lookup_widget(objet,"fenetre_ajout");
gtk_widget_destroy(fenetre_ajout);
fenetre_affiche=lookup_widget(objet,"fenetre_affiche");
fenetre_affiche=create_fenetre_affiche();
gtk_widget_show(fenetre_affiche);
treeview1=lookup_widget(fenetre_affiche,"treeview1");
affichercapteur(treeview1);
}



void
on_treeview111_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkTreeIter iter;
gchar* id;
gchar* nom;
gchar* type;
gchar* jour;
gchar* mois;
gchar* annee;
gchar* valeur;
gchar* bloc;
gchar* etat;
capteur c;
date da;
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path)){
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&nom,2,&type,3,&jour,4,&mois,5,&annee,6,&valeur,7,&bloc,8,&etat,-1);
//
strcpy(c.id,id);
strcpy(c.nom,nom);
strcpy(c.type,type);
strcpy(c.da.jour,jour);
strcpy(c.da.mois,mois);
strcpy(c.da.annee,annee);
strcpy(c.valeur,valeur);
strcpy(c.bloc,bloc);
strcpy(c.d,etat);
//
supprimercapteur(c);
affichercapteur(treeview);
}

}


void
on_button333_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_affiche;
fenetre_affiche=lookup_widget(objet,"fenetre_affiche");
gtk_widget_destroy(fenetre_affiche);
fenetre_ajout=lookup_widget(objet,"fenetre_ajout");
fenetre_ajout=create_fenetre_ajout();
gtk_widget_show(fenetre_ajout);
}


void
on_Actualiser_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_affiche,*w1;
GtkWidget *treeview1;

w1=lookup_widget(objet,"fenetre_affiche");
fenetre_affiche=create_fenetre_affiche();
gtk_widget_show(fenetre_affiche);
gtk_widget_hide(w1);
treeview1=lookup_widget(fenetre_affiche,"treeview111");
affichercapteur(treeview1);


}


void
on_modifier_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)

{



GtkWidget *fenetre_ajout,*fenetre_affiche;











//////////////////////////////////////////////////////
fenetre_ajout=lookup_widget(objet,"fenetre_affiche");
gtk_widget_destroy(fenetre_ajout);
fenetre_affiche=lookup_widget(objet,"fenetre_modif");
fenetre_affiche=create_fenetre_modif();
gtk_widget_show(fenetre_affiche);
















}


void
on_supprimer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkTreeSelection *selection;
  GtkTreeModel     *model;
  GtkTreeIter       iter;
  GtkWidget         *view;

  view = gtk_tree_view_new();

  /* This will only work in single or browse selection mode! */

  selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(view));
  if (1==1)
  {
    gchar *name;

    gtk_tree_model_get (model, &iter,EID, &name, -1);

   g_print ("selected row is: %s\n", name);
g_print ("selected row is");
   g_free(name);
//gtk_tree_selection_get_selected(selection, &model, &iter)
  }
  else
  {
    g_print ("no row selected.\n");
  }

}


void
on_update_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{




GtkWidget *editid;
GtkWidget *editnom;
GtkWidget *editvaleur;
GtkWidget *combobox2;
GtkWidget *spinbutton4;
GtkWidget *spinbutton5;
GtkWidget *spinbutton6;





char nom[20];
char type[20];
date da;
char valeur[20];

capteur c;

GtkWidget *fenetre_ajout,*fenetre_affiche,*lbl;

//

int j,m,a;
char jour[20],mois[20],annee[20];
fenetre_ajout=lookup_widget(objet,"fenetre_modif");
editid=lookup_widget(objet,"editid");
editnom=lookup_widget(objet,"editnom");
editvaleur=lookup_widget(objet,"editvaleur");


lbl=lookup_widget(objet,"label25");

spinbutton4=lookup_widget(objet,"spinbutton4");
spinbutton5=lookup_widget(objet,"spinbutton5");
spinbutton6=lookup_widget(objet,"spinbutton6");

combobox2=lookup_widget(objet,"combobox2");

strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(editid)));
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(editnom)));
strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton4));
m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton5));
a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton6));

sprintf(jour,"%d\0",j);
sprintf(mois,"%d\0",m);
sprintf(annee,"%d\0",a);


strcpy(c.da.jour,jour);
strcpy(c.da.mois,mois);
strcpy(c.da.annee,annee);


strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(editvaleur)));


modifiercapteur(gtk_entry_get_text(GTK_ENTRY(editid)),c);



//////////////////////////////////////////////////////

fenetre_ajout=lookup_widget(objet,"fenetre_modif");
gtk_widget_destroy(fenetre_ajout);
fenetre_affiche=lookup_widget(objet,"fenetre_affiche");
fenetre_affiche=create_fenetre_affiche();
gtk_widget_show(fenetre_affiche);

}


void
on_etage1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))){
 
 g_print("1");

strcpy(ted,"block");
}
}


void
on_etage2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))){
strcpy(ted,"block2");

}
}


void
on_etage3_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))){
 
strcpy(ted,"block3");
}
}


void
on_accepter_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))){
 test = 1;

}
else test=0;
}


void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkTreeIter iter;
gchar* id;
gchar* nom;
gchar* type;
gchar* jour;
gchar* mois;
gchar* annee;
gchar* valeur;
gchar* bloc;
gchar* etat;
capteur c;
date da;
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path)){
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&nom,2,&type,3,&jour,4,&mois,5,&annee,6,&valeur,7,&bloc,8,&etat,-1);

strcpy(c.id,id);
strcpy(c.nom,nom);
strcpy(c.type,type);
strcpy(c.da.jour,jour);
strcpy(c.da.mois,mois);
strcpy(c.da.annee,annee);
strcpy(c.valeur,valeur);
strcpy(c.bloc,bloc);
strcpy(c.d,etat);
supprimercapteur(c);
affichertempcapteur(treeview);
}
}


void
on_affiche_tache_clicked               (GtkWidget      *objet,
                                        gpointer         user_data)
{

GtkWidget *fenetre_ajout;
GtkWidget *fenetre_affiche;
GtkWidget *treeview1;
fenetre_ajout=lookup_widget(objet,"fenetre_ajout");
gtk_widget_destroy(fenetre_ajout);
fenetre_affiche=lookup_widget(objet,"tache2");
fenetre_affiche=create_tache2();
gtk_widget_show(fenetre_affiche);
treeview1=lookup_widget(fenetre_affiche,"treeview3");
affichertempcapteur(treeview1);
}


void
on_revenir_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_affiche;
fenetre_affiche=lookup_widget(objet,"tache2");
gtk_widget_destroy(fenetre_affiche);
fenetre_ajout=lookup_widget(objet,"fenetre_affiche");
fenetre_ajout=create_fenetre_affiche();
gtk_widget_show(fenetre_ajout);
}


void
on_rechercher_1_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_affiche,*w1,*input1;
GtkWidget *treeview1;

w1=lookup_widget(objet,"fenetre_affiche");
fenetre_affiche=create_fenetre_affiche();
gtk_widget_show(fenetre_affiche);
gtk_widget_hide(w1);
input1=lookup_widget(objet,"cherche_id");
//strcpy(text,gtk_entry_get_text(GTK_ENTRY(input1)));
treeview1=lookup_widget(fenetre_affiche,"treeview1");
cherchercapteur(treeview1,input1);
//recherchecapteur( text);

}


void sendmail(char to[], char body[])
{
        char cmd[1000];  // to hold the command.
        char tempFile[100] = "test.txt";     // name of tempfile.

        FILE *fp = fopen(tempFile,"w+"); // open it for writing.
        fprintf(fp,"%s\n",body);        // write body to it.
        fclose(fp);             // close it.

        
        sprintf(cmd,"curl --url 'smtps://smtp.gmail.com:465' --ssl-reqd   --mail-from 'smartproject9911@gmail.com' --mail-rcpt '%s'   --upload-file %s --user 'smartproject9911@gmail.com:ALA_BH_1998'", to, tempFile);
      
        system(cmd);     // execute it.
}


void
on_ajouter1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

utilisateur U;

GtkWidget *input1, *input2,*input3,*input4,*input5,*output,*output1,*j,*m,*a,*input6;
GtkWidget *fenetre_ajout;

char text1[100]="remplir le nom";
char text2[100]="remplir le prenom";
char text3[100]="choisir un mot de pass";
char text4[100]="saisir 8 chifre";
char text5[100]="Utilisateur ajouter avec succes";
//int jr,ms,ae;



fenetre_ajout=lookup_widget(button,"fenetre_ajout1");

input1=lookup_widget(button,"cin");
input2=lookup_widget(button,"nom");
input3=lookup_widget(button,"prenom");
input4 = lookup_widget(button, "comboboxentry1");
input6=lookup_widget(button,"passw");


strcpy(U.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(U.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(U.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(U.classe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
strcpy(U.role,rol);
strcpy(U.password,gtk_entry_get_text(GTK_ENTRY(input6)));
//strcpy(text1,"Uilisateur ajouté avec succès");
//strcpy(text2,"il faut accepter les règles");
//strcpy(text3,"Saisir 8 Chiffre");

//j=lookup_widget(button,"spinbutton1");
//m=lookup_widget(button,"spinbutton2");
//a=lookup_widget(button,"spinbutton3");
//U.date.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (j));
//U.date.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (m));
//U.date.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (a));
U.date.jour=jr;
U.date.mois=mr+1;
U.date.annee=ar;


if (strcmp(U.nom,"")==0)
{output = lookup_widget(button,"labelnom");
gtk_label_set_text(GTK_LABEL(output),text1);}

if (strcmp(U.prenom,"")==0)
{output = lookup_widget(button,"labelprenom");
gtk_label_set_text(GTK_LABEL(output),text2);}

if (strcmp(U.password,"")==0)
{output = lookup_widget(button,"labelpassword");
gtk_label_set_text(GTK_LABEL(output),text3);}

if (strlen(U.cin)!=8)
{output = lookup_widget(button,"labelcin");
gtk_label_set_text(GTK_LABEL(output),text4);}




if((strlen(U.cin)==8) && (strcmp(U.nom,"")!=0) && (strcmp(U.prenom,"")!=0) && (strcmp(U.password,"")!=0))
{

output = lookup_widget(button,"label101");
gtk_label_set_text(GTK_LABEL(output),text5);
Ajouter(U);
char msg[100] = "Un nouveau utilisateur a ete ajoute  ";
strcat(msg, "\n");
strcat(msg, U.nom);
strcat(msg, " ");
strcat(msg, U.prenom);
strcat(msg, "\n");
strcat(msg, U.classe);
strcat(msg, "\n");
strcat(msg, U.role);
sendmail("alaeddine.benhmida@esprit.tn", msg);

}


}

void
on_afficher1_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
utilisateur U;
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;

fenetre_ajout=lookup_widget(objet,"fenetre_ajout1");


gtk_widget_destroy(fenetre_ajout);
fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();

gtk_widget_show(fenetre_afficher);

treeview1=lookup_widget(fenetre_afficher,"treeview1111");

Afficher(treeview1, filtr);

}


void
on_treeview1111_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* nom;
gchar* prenom;
gchar* classe;
gchar* role;
gchar* cin;
gchar* password;
gchar* date;
char *jc,*jm,*ja;
utilisateur U;
char temp[20];
char temp2[20];
//GtkTreeSelection *select;
//select = gtk_tree_view_get_selection (treeview);


GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model, &iter, path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &cin, 1, &nom,2,&prenom,3,&classe,4,&role,5,&password,6,&date, -1);

strcpy(U.cin,cin);
strcpy(U.nom,nom);
strcpy(U.prenom,prenom);
strcpy(U.classe,classe);
strcpy(U.role,role);
strcpy(U.password,password);
jc=strtok(date,"/");
jm=strtok(NULL,"/");
ja=strtok(NULL,"/");
U.date.jour = atoi(jc);
U.date.mois = atoi(jm);
U.date.annee = atoi(ja);


ug = U;
//Afficher(treeview, filtr);



}
}


void
on_retour1_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *fenetre_ajout1;
GtkWidget *fenetre_afficher;
fenetre_afficher=lookup_widget(objet,"fenetre_afficher");


gtk_widget_destroy(fenetre_afficher);

fenetre_ajout1=lookup_widget(objet,"fenetre_ajout1");
fenetre_ajout1=create_fenetre_ajout1();
gtk_widget_show(fenetre_ajout1);
}

void
on_actualiser_clicked                  (GtkWidget       *objet,
                                      gpointer         user_data)
{ 

GtkWidget *entry_rech20;
GtkWidget *treeview1;
GtkWidget *test;


entry_rech20=lookup_widget(objet,"entry_rech20");
gtk_entry_set_text (GTK_ENTRY (entry_rech20), _("Entre la cin a chercher"));

treeview1=lookup_widget(objet,"treeview1111");

Afficher(treeview1, filtr);


}






void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
strcpy(rol,"Admin");			//admin
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{


if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))

strcpy(rol,"Etudiant");
			//Etudiant
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
strcpy(rol,"technicien");	  			//technicien
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
strcpy(rol,"A.foyer");				//foyer
}


void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
strcpy(rol,"A.resto");				//resto
}


void
on_radiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if(gtk_toggle_button_get_active (togglebutton))
strcpy(rol,"nutritionniste");				//nutri
}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
x=1;
else 
x=0;


}

void
on_button2222_clicked                     (GtkButton       *button,
                                        gpointer         user_data)              //suppression
{

GtkWidget *treeview1;

Supprimer(ug);

treeview1=lookup_widget(button,"treeview1111");
Afficher(treeview1, filtr);
}


void
on_button1111_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifier;
modifier = create_fenetre_modifier ();
gtk_widget_show (modifier);
}


void
on_button3_rech21_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

utilisateur U;

GtkWidget *input1, *input2,*input3,*input4,*input5,*output,*j,*m,*a;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
GtkWidget *w1;


input1=lookup_widget(button,"entry_rech20");
strcpy(text,gtk_entry_get_text(GTK_ENTRY(input1)));
treeview1=lookup_widget(button,"treeview1111");
rechercher(U,text);
Afficher2(treeview1, filtr);


}


void
on_chekbutton20_activate               (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void
on_item3_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void
on_item2_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void
on_button3_confirmer_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
utilisateur U;

GtkWidget *input1, *input2,*input3,*input4,*input5,*input6,*output,*j,*m,*a;
GtkWidget *fenetre_modifier;

char text1[100];
char text2[100];
int jr,ms,ae;



fenetre_modifier=lookup_widget(button,"fenetre_modifier");

input1=lookup_widget(button,"entry30_nom");
input2=lookup_widget(button,"entry31_prenom");
input3 = lookup_widget(button, "comboboxentry30");
input6=lookup_widget(button,"passswm");


strcpy(U.cin, ug.cin);
strcpy(U.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(U.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(U.password,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(U.classe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
strcpy(U.role,rol2);


j=lookup_widget(button,"spinbutton44");
m=lookup_widget(button,"spinbutton55");
a=lookup_widget(button,"spinbutton66");
U.date.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (j));
U.date.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (m));
U.date.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (a));
Modifier(U);



}


void
on_radiobutton32_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
strcpy(rol2,"technicien");
}


void
on_radiobutton35_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
strcpy(rol2,"nutrionniste");
}


void
on_radiobutton34_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
strcpy(rol2,"A.resto");
}


void
on_radiobutton31_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
strcpy(rol2,"Etudiant");
}


void
on_radiobutton33_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
strcpy(rol2,"A.foyer");
}


void
on_radiobutton30_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
strcpy(rol2,"Admin");
}


void
on_fenetre_modifier_show               (GtkWidget       *button,
                                        gpointer         user_data)
{
utilisateur U;
GtkWidget *input1, *input2,*input3,*input4,*input5,*output,*input6;
GtkWidget *radio30, *radio31,*radio32,*radio33,*radio34,*radio35;
GtkWidget *fenetre_modifier;
GtkSpinButton *j;
GtkSpinButton *m;
GtkSpinButton *a;
char text1[100];
char text2[100];
int jr,ms,ae;



fenetre_modifier=lookup_widget(button,"fenetre_modifier");

input1=lookup_widget(button,"entry30_nom");
input2=lookup_widget(button,"entry31_prenom");
input3=lookup_widget(button,"comboboxentry30");
input6=lookup_widget(button,"passswm");
j=lookup_widget(button,"spinbutton44");
m=lookup_widget(button,"spinbutton55");
a=lookup_widget(button,"spinbutton66");
radio30=lookup_widget(button,"radiobutton30");
radio31=lookup_widget(button,"radiobutton31");
radio32=lookup_widget(button,"radiobutton32");
radio33=lookup_widget(button,"radiobutton33");
radio34=lookup_widget(button,"radiobutton34");
radio35=lookup_widget(button,"radiobutton35");
gtk_entry_set_text(input1, ug.nom);
gtk_entry_set_text(input2, ug.prenom);
gtk_entry_set_text(input3, ug.nom);
gtk_entry_set_text(input6, ug.password);
gtk_entry_set_text (GTK_ENTRY (GTK_BIN (input3)->child), ug.classe);
gtk_spin_button_set_value (j, ug.date.jour);
gtk_spin_button_set_value (m, ug.date.mois);
gtk_spin_button_set_value (a, ug.date.annee);

if (strcmp(ug.role,"Admin") == 0)
gtk_toggle_button_set_active(GTK_RADIO_BUTTON (radio30), 1);
else if(strcmp(ug.role,"Etudiant") == 0)
gtk_toggle_button_set_active(GTK_RADIO_BUTTON (radio31), 1);
else if(strcmp(ug.role,"technicien") == 0)
gtk_toggle_button_set_active(GTK_RADIO_BUTTON (radio32), 1);
else if(strcmp(ug.role,"A.foyer") == 0)
gtk_toggle_button_set_active(GTK_RADIO_BUTTON (radio33), 1);
else if(strcmp(ug.role,"A.resto") == 0)
gtk_toggle_button_set_active(GTK_RADIO_BUTTON (radio34), 1);
else if(strcmp(ug.role,"nutrionniste") == 0)
gtk_toggle_button_set_active(GTK_RADIO_BUTTON (radio35), 1);
}


void
on_button3_nb_etud_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *nb_etudiants;
GtkWidget *fenetre_afficher;


fenetre_afficher=lookup_widget(objet,"fenetre_afficher");


gtk_widget_destroy(fenetre_afficher);
nb_etudiants=lookup_widget(objet,"nb_etudiants");
nb_etudiants=create_nb_etudiants();
gtk_widget_show(nb_etudiants);

}


void
on_button4_affch_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button3_retour3_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *nb_etudiants;
GtkWidget *fenetre_afficher;

nb_etudiants=lookup_widget(button,"nb_etudiants");


gtk_widget_destroy(nb_etudiants);
fenetre_afficher=lookup_widget(button,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"treeview1111");

Afficher(treeview1, filtr);
}


void
on_nb_etudiants_show                   (GtkWidget       *button,
                                        gpointer         user_data)
{
etudiant1 nb;
GtkWidget *input1, *input2,*input3,*input4,*input5,*output,*j,*m,*a;
GtkWidget *nb_etudiants;
nb_etudiants=lookup_widget(button,"nb_etudiants");
nb_etudiant(&nb);

input1=lookup_widget(button,"entry1_");
input2=lookup_widget(button,"entry2_");
input3=lookup_widget(button,"entry3_");
input4=lookup_widget(button,"entry4_");
input5=lookup_widget(button,"entry5_");

gtk_entry_set_text(input1,nb.pr);
gtk_entry_set_text(input2,nb.dr);
gtk_entry_set_text(input3,nb.tr);
gtk_entry_set_text(input4,nb.qr);
gtk_entry_set_text(input5,nb.cr);

}


void
on_fixed6_show                         (GtkWidget       *widget,
                                        gpointer         user_data)
{

}


void
on_checkbutton20_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_CHECK_BUTTON (togglebutton)))
filtr[0]=1;
else 
filtr[0]=0;

GtkWidget *treeview1;
treeview1=lookup_widget(togglebutton,"treeview1111");
Afficher(treeview1, filtr);
}


void
on_checkbutton21_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_CHECK_BUTTON (togglebutton)))
filtr[1]=1;
else 
filtr[1]=0;

GtkWidget *treeview1;
treeview1=lookup_widget(togglebutton,"treeview1111");
Afficher(treeview1, filtr);
}


void
on_checkbutton22_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_CHECK_BUTTON (togglebutton)))
filtr[2]=1;
else 
filtr[2]=0;

GtkWidget *treeview1;
treeview1=lookup_widget(togglebutton,"treeview1111");
Afficher(treeview1, filtr);
}


void
on_checkbutton23_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_CHECK_BUTTON (togglebutton)))
filtr[3]=1;
else 
filtr[3]=0;

GtkWidget *treeview1;
treeview1=lookup_widget(togglebutton,"treeview1111");
Afficher(treeview1, filtr);
}


void
on_checkbutton24_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_CHECK_BUTTON (togglebutton)))
filtr[4]=1;
else 
filtr[4]=0;

GtkWidget *treeview1;
treeview1=lookup_widget(togglebutton,"treeview1111");
Afficher(treeview1, filtr);
}


void
on_checkbutton25_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{


if(gtk_toggle_button_get_active(GTK_CHECK_BUTTON (togglebutton)))
filtr[5]=1;
else 
filtr[5]=0;

GtkWidget *treeview1;
treeview1=lookup_widget(togglebutton,"treeview1111");
Afficher(treeview1, filtr);
}




void
on_calendar1_day_selected              (GtkCalendar     *calendar,
                                        gpointer         user_data)
{utilisateur U;
GtkWidget *DD;

//DD=lookup_widget(widget,"calendar1");
gtk_calendar_get_date (GTK_CALENDAR (calendar),&ar ,&mr ,&jr );


}
///////////////////////////

void
on_buttonlog_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *HomeRepas;
    

    HomeRepas = create_HomeRepas ();
    gtk_widget_show (HomeRepas);
    GtkWidget * repas_treeview;
    repas_treeview = lookup_widget(HomeRepas, "amineHomeTreeview");
    afficher_repas(repas_treeview);
}


void
on_amineAjouterbutton_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
    repas rep;

    GtkWidget * repas_nom;
    GtkWidget * repas_radio_dej;
    GtkWidget * repas_radio_din;
    GtkWidget * repas_radio_petit;
    GtkWidget * repas_spin_jour;
    GtkWidget * repas_combobox_mois;
    GtkWidget * repas_spin_annee;
    GtkWidget * repas_checkbox_suppl;
    GtkWidget * repas_radio_less;
    GtkWidget * repas_radio_more;

    repas_nom = lookup_widget(button, "RepasAjouterEntryNom");
    repas_radio_dej = lookup_widget(button, "RepasAjouterRadioDej") ;
    repas_radio_din = lookup_widget(button, "RepasAjouterRadioDin");
    repas_radio_petit = lookup_widget(button, "RepasAjouterRadioPetit");
    repas_spin_jour = lookup_widget(button, "RepasAjouterSpinJour");
    repas_combobox_mois = lookup_widget(button, "RepasAjouterComboboxMois");
    repas_spin_annee = lookup_widget(button, "RepasAjouterSpinAnnee");
    repas_checkbox_suppl = lookup_widget(button, "RepasAjouterCheckboxBoisson");
    repas_radio_less = lookup_widget(button, "RepasAjouterRadioLess");
    repas_radio_more = lookup_widget(button, "RepasAjouterRadioMore");

    strcpy(rep.nom, gtk_entry_get_text(GTK_ENTRY(repas_nom)));

    if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(repas_radio_dej))) strcpy(rep.type, "Dejeuner");
    if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(repas_radio_din))) strcpy(rep.type, "Diner");
    if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(repas_radio_petit))) strcpy(rep.type, "PetitDej");

    rep.date.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(repas_spin_jour));
    strcpy(rep.date.mois, gtk_combo_box_get_active_text(GTK_COMBO_BOX(repas_combobox_mois)));
    rep.date.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(repas_spin_annee));

    if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(repas_checkbox_suppl))) strcpy(rep.suppl, "oui");
    else strcpy(rep.suppl, "non");


    if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(repas_radio_more))) strcpy(rep.dechets, "sup30");
    if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(repas_radio_less))) strcpy(rep.dechets, "inf30");

    ajouter_repas(rep);

    GtkWidget *HomeRepas;
    HomeRepas = create_HomeRepas ();
    gtk_widget_show (HomeRepas);
    GtkWidget * repas_treeview;
    repas_treeview = lookup_widget(HomeRepas, "amineHomeTreeview");
    afficher_repas(repas_treeview);
    GtkWidget *AjoutRepas;
    AjoutRepas = lookup_widget(button, "AjoutRepas");
    gtk_widget_destroy(AjoutRepas);

}



void
on_amineHomeAjouter_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *AjoutRepas;
    AjoutRepas = create_AjoutRepas ();
    gtk_widget_show (AjoutRepas);
    GtkWidget *HomeRepas;
    HomeRepas = lookup_widget(button, "HomeRepas");
    gtk_widget_destroy(HomeRepas);

}


void
on_amineHomeTreeview_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
    gchar *nom;
    gchar *type;
    gchar *date;
    gchar *suppl;
    gchar *dechets;
    GtkTreeIter iter;

    GtkTreeModel *model = gtk_tree_view_get_model(treeview); 
    if (gtk_tree_model_get_iter(model, &iter, path)) 
        {
            gtk_tree_model_get(model, &iter, ENOM_REPAS, &nom, ETYPE_REPAS, &type,EDATE_REPAS, &date , EBOISSON_REPAS, &suppl, EDECHETS_REPAS, &dechets ,-1); 
            strcpy(gl_rep.nom, nom);
            strcpy(gl_rep.type, type);

            char *jour = strtok(date, " ");
            strcpy(gl_rep.date.mois,strtok(NULL, " "));
            char *annee =  strtok(NULL, " ");
            gl_rep.date.jour = atoi(jour);
            gl_rep.date.annee = atoi(annee);

            strcpy(gl_rep.suppl, suppl);
            strcpy(gl_rep.dechets, dechets);
            
            GtkWidget *UpdateRepas;
            UpdateRepas = create_UpdateRepas ();
            gtk_widget_show (UpdateRepas);


                GtkWidget * repas_nom;
                GtkWidget * repas_radio_dej;
                GtkWidget * repas_radio_din;
                GtkWidget * repas_radio_petit;
                GtkWidget * repas_spin_jour;
                GtkWidget * repas_combobox_mois;
                GtkWidget * repas_spin_annee;
                GtkWidget * repas_checkbox_suppl;
                GtkWidget * repas_radio_less;
                GtkWidget * repas_radio_more;

                repas_nom = lookup_widget(UpdateRepas, "UpdateRepasEntryNom");
                repas_radio_dej = lookup_widget(UpdateRepas, "UpdateRepasRadioDej") ;
                repas_radio_din = lookup_widget(UpdateRepas, "UpdateRepasRadioDin");
                repas_radio_petit = lookup_widget(UpdateRepas, "UpdateRepasRadioPetit");
                repas_spin_jour = lookup_widget(UpdateRepas, "UpdateRepasSpinJour");
                repas_combobox_mois = lookup_widget(UpdateRepas, "UpdateRepasComboboxMois");
                repas_spin_annee = lookup_widget(UpdateRepas, "UpdateRepasSpinAnnee");
                repas_checkbox_suppl = lookup_widget(UpdateRepas, "UpdateRepasCheckboxBoisson");
                repas_radio_less = lookup_widget(UpdateRepas, "UpdateRepasRadioLess");
                repas_radio_more = lookup_widget(UpdateRepas, "UpdateRepasRadioMore");


                gtk_entry_set_text(repas_nom, gl_rep.nom); 


                if (strcmp(gl_rep.type, "Dejeuner") == 0) gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(repas_radio_dej), TRUE);
                if (strcmp(gl_rep.type, "PetitDej") == 0) gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(repas_radio_petit), TRUE);
                if (strcmp(gl_rep.type, "Diner") == 0) gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(repas_radio_din), TRUE);
                
                gtk_spin_button_set_value(GTK_SPIN_BUTTON(repas_spin_jour), gl_rep.date.jour);

                if (strcmp(gl_rep.date.mois, "Janvier") == 0) gtk_combo_box_set_active(GTK_COMBO_BOX(repas_combobox_mois), 0);
                else if (strcmp(gl_rep.date.mois, "Février") == 0) gtk_combo_box_set_active(GTK_COMBO_BOX(repas_combobox_mois), 1); 
                else if (strcmp(gl_rep.date.mois, "Mars") == 0) gtk_combo_box_set_active(GTK_COMBO_BOX(repas_combobox_mois), 2); 
                else if (strcmp(gl_rep.date.mois, "Avril") == 0) gtk_combo_box_set_active(GTK_COMBO_BOX(repas_combobox_mois), 3); 
                else if (strcmp(gl_rep.date.mois, "Mai") == 0) gtk_combo_box_set_active(GTK_COMBO_BOX(repas_combobox_mois), 4); 
                else if (strcmp(gl_rep.date.mois, "Juin") == 0L) gtk_combo_box_set_active(GTK_COMBO_BOX(repas_combobox_mois), 5); 
                else if (strcmp(gl_rep.date.mois, "Juillet") == 0) gtk_combo_box_set_active(GTK_COMBO_BOX(repas_combobox_mois), 6); 
                else if (strcmp(gl_rep.date.mois, "Aout") == 0) gtk_combo_box_set_active(GTK_COMBO_BOX(repas_combobox_mois), 7); 
                else if (strcmp(gl_rep.date.mois, "Septembre") == 0) gtk_combo_box_set_active(GTK_COMBO_BOX(repas_combobox_mois), 8); 
                else if (strcmp(gl_rep.date.mois, "Octobre") == 0) gtk_combo_box_set_active(GTK_COMBO_BOX(repas_combobox_mois), 9);  
                else if (strcmp(gl_rep.date.mois, "Novembre") == 0) gtk_combo_box_set_active(GTK_COMBO_BOX(repas_combobox_mois), 10); 
                else if (strcmp(gl_rep.date.mois, "Décembre") == 0) gtk_combo_box_set_active(GTK_COMBO_BOX(repas_combobox_mois), 11); 
                
                gtk_spin_button_set_value(GTK_SPIN_BUTTON(repas_spin_annee), gl_rep.date.annee);

                if (strcmp(gl_rep.suppl, "oui") == 0) gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(repas_checkbox_suppl), TRUE);

                if (strcmp(gl_rep.dechets, "inf30") == 0) gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(repas_radio_less), TRUE);
                if (strcmp(gl_rep.dechets, "sup30") == 0) gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(repas_radio_more), TRUE);
        
        GtkWidget *HomeRepas;
        HomeRepas = lookup_widget(treeview, "HomeRepas");
        gtk_widget_destroy(HomeRepas);


        }

}


void
on_amineDeletebutton_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
    supprimer_repas(gl_rep);
    GtkWidget *HomeRepas;
    HomeRepas = create_HomeRepas ();
    gtk_widget_show (HomeRepas);
    GtkWidget * repas_treeview;
    repas_treeview = lookup_widget(HomeRepas, "amineHomeTreeview");
    afficher_repas(repas_treeview);

    GtkWidget *UpdateRepas;
    UpdateRepas = lookup_widget(button, "UpdateRepas");
    gtk_widget_destroy (UpdateRepas);
}


void
on_amineUpdatebutton_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
    repas rep;

    GtkWidget * repas_nom;
    GtkWidget * repas_radio_dej;
    GtkWidget * repas_radio_din;
    GtkWidget * repas_radio_petit;
    GtkWidget * repas_spin_jour;
    GtkWidget * repas_combobox_mois;
    GtkWidget * repas_spin_annee;
    GtkWidget * repas_checkbox_suppl;
    GtkWidget * repas_radio_less;
    GtkWidget * repas_radio_more;

    repas_nom = lookup_widget(button, "UpdateRepasEntryNom");
    repas_radio_dej = lookup_widget(button, "UpdateRepasRadioDej") ;
    repas_radio_din = lookup_widget(button, "UpdateRepasRadioDin");
    repas_radio_petit = lookup_widget(button, "UpdateRepasRadioPetit");
    repas_spin_jour = lookup_widget(button, "UpdateRepasSpinJour");
    repas_combobox_mois = lookup_widget(button, "UpdateRepasComboboxMois");
    repas_spin_annee = lookup_widget(button, "UpdateRepasSpinAnnee");
    repas_checkbox_suppl = lookup_widget(button, "UpdateRepasCheckboxBoisson");
    repas_radio_less = lookup_widget(button, "UpdateRepasRadioLess");
    repas_radio_more = lookup_widget(button, "UpdateRepasRadioMore");

    strcpy(rep.nom, gtk_entry_get_text(GTK_ENTRY(repas_nom)));

    if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(repas_radio_dej))) strcpy(rep.type, "Dejeuner");
    if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(repas_radio_din))) strcpy(rep.type, "Diner");
    if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(repas_radio_petit))) strcpy(rep.type, "PetitDej");

    rep.date.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(repas_spin_jour));
    strcpy(rep.date.mois, gtk_combo_box_get_active_text(GTK_COMBO_BOX(repas_combobox_mois)));
    rep.date.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(repas_spin_annee));

    if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(repas_checkbox_suppl))) strcpy(rep.suppl, "oui");
    else strcpy(rep.suppl, "non");


    if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(repas_radio_more))) strcpy(rep.dechets, "sup30");
    if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(repas_radio_less))) strcpy(rep.dechets, "inf30");

    modifier_repas(gl_rep, rep);    

    GtkWidget *HomeRepas;
    HomeRepas = create_HomeRepas ();
    gtk_widget_show (HomeRepas);
    GtkWidget * repas_treeview;
    repas_treeview = lookup_widget(HomeRepas, "amineHomeTreeview");
    afficher_repas(repas_treeview);

    GtkWidget *UpdateRepas;
    UpdateRepas = lookup_widget(button, "UpdateRepas");
    gtk_widget_destroy (UpdateRepas);

}

void
on_button2223_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window=create_dashboard_hebergement();
gtk_widget_show(window);

}

void
on_button2224_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window=create_a_inscription();
gtk_widget_show(window);
}

void
on_button2225_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window=create_fenetre_affiche();
gtk_widget_show(window);
}

void
on_button2226_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window=create_fenetre_afficher();
gtk_widget_show(window);
}

void
on_button2227_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window=create_HomeRepas();
gtk_widget_show(window);
}

void
on_inscri_log_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *window,*window2;

window2=lookup_widget(button,"auth_");
gtk_widget_destroy(window2);

window=create_inscri_();
gtk_widget_show(window);
}


void
on_valider_log_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

	utilisateur U;
	GtkWidget *window;
	GtkWidget *output;
        GtkWidget *input1, *input2;

    char nom[100];
    char prenom[100];
    char cin[100];
    char role[100];
    char classe[100];
    char date[100];
    char password[100];
    char text[100]="Utilisateur introuvable";


input1 = lookup_widget(button, "cin_1");
input2 = lookup_widget(button, "pass_1");

strcpy(U.cin, gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(U.password, gtk_entry_get_text(GTK_ENTRY(input2)));

FILE *f=NULL;
f=fopen("ajout_etudiant.txt","r");
if (f==NULL)
{
	return;
}
else{
while(fscanf(f,"%s %s %s %s %s %s %s\n",nom,prenom,role,cin,classe,password,date)!=EOF)
{
if ((strcmp(U.cin,cin)==0) && (strcmp(U.password,password))==0)
{
if ((strcmp(role,"Admin")==0))
{window=create_fenetre_afficher();
gtk_widget_show(window);}
else if ((strcmp(role,"Etudiant")==0))
{window=create_auth_();
gtk_widget_show(window);}
else if ((strcmp(role,"technicien")==0))
{window=create_fenetre_affiche();
gtk_widget_show(window);}
else if ((strcmp(role,"A.foyer")==0))
{window=create_dashboard_hebergement();
gtk_widget_show(window);}
else if ((strcmp(role,"A.resto")==0))
{window=create_HomeRepas();
gtk_widget_show(window);}
}
else
{
output = lookup_widget(button,"label151");
gtk_label_set_text(GTK_LABEL(output),text);
}}}

}


void
on_inscri_confirm_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
utilisateur U;
GtkWidget *window,*window2;
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9;


input1=lookup_widget(button,"inscri_nom");
input2=lookup_widget(button,"inscri_prenom");
input3=lookup_widget(button,"inscri_cin");
input4=lookup_widget(button,"inscri_pass");
input5=lookup_widget(button,"combobox_classe");
input6=lookup_widget(button,"combobox_role");
input7=lookup_widget(button,"spinbutton_j");
input8=lookup_widget(button,"spinbutton_m");
input9=lookup_widget(button,"spinbutton_a");
strcpy(U.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(U.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(U.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(U.password,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(U.classe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
strcpy(U.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)));
U.date.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input7));
U.date.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input8));
U.date.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input9));
Ajouter(U);



window2=lookup_widget(button,"inscri_");

gtk_widget_destroy(window2);

window=create_auth_();
gtk_widget_show(window);
}


void
on_auth__show                          (GtkWidget       *widget,
                                        gpointer         user_data)
{
GtkWidget *image1;
image1 = lookup_widget(widget, "image40");
gtk_image_set_from_file(GTK_IMAGE(image1),"login3.png");

}

