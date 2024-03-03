#include <gtk/gtk.h>

#ifndef CALCULATRICE
#define CALCULATRICE

/*
    Mahakasina ny endrik'ilay programa ity ambany ity 
*/

GtkWidget *famoronana_varavarana(const gchar *lohateny, int lon, int lar);
void famoronana_bouton(GtkWidget **bouton,const char *teny);
void mametraka_css(GtkWidget *zavatra, char *anarana);
gboolean manidry(GtkWidget *fampidiara, GdkEventKey *key, gpointer data);
void manindry_0(GtkWidget *bouton, gpointer data);
void manindry_1(GtkWidget *bouton, gpointer data);
void manindry_2(GtkWidget *bouton, gpointer data);
void manindry_3(GtkWidget *bouton, gpointer data);
void manindry_4(GtkWidget *bouton, gpointer data);
void manindry_5(GtkWidget *bouton, gpointer data);
void manindry_6(GtkWidget *bouton, gpointer data);
void manindry_7(GtkWidget *bouton, gpointer data);
void manindry_8(GtkWidget *bouton, gpointer data);
void manindry_9(GtkWidget *bouton, gpointer data);
void manindry_p(GtkWidget *bouton, gpointer data);
void manindry_m(GtkWidget *bouton, gpointer data);
void manindry_f(GtkWidget *bouton, gpointer data);
void manindry_d(GtkWidget *bouton, gpointer data);
void manindry_p1(GtkWidget *bouton, gpointer data);
void manindry_p2(GtkWidget *bouton, gpointer data);
void manindry_te(GtkWidget *bouton, gpointer data);
void manindry_fafana(GtkWidget *bouton, gpointer data);
void kajio(GtkWidget *fampidiara, gpointer data);
void manindry_e(GtkWidget *bouton, gpointer data);

/*
    Mahakasika ilay fomba fikajiana kosa ity ambany ity
*/

int vatany(GtkWidget *var);
int manasaraka(char *kajina, char *v, char *f, char *litera);
double kajy(char *kaj);

void mampiseo_mombamomba(GtkWidget *bouton, gpointer data);

int mande(GtkWidget *fivoarany);
int fiatombohany(GtkWidget *var);

int alefa(int argc, char **argv);

#endif
