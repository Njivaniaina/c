#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    Ity dia ny tapany miafina amin'ilay programa dia ny fikajina izany
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////

int manasaraka(char *kajina, char *v, char *f, char *litera){
miverina: 
    int m=1, j=0, n=0;
    int mivoha=0, mihidy=0;

    for(int i=0; i<strlen(kajina);i++){
        if(((isdigit(kajina[i]) || kajina[i] == ',')&& m) || i==0 || (!isdigit(kajina[i] && kajina[i] != ',') && (mivoha != mihidy))){
            v[j] = kajina[i];
            j++;
            if( kajina[i] == '(')
                mivoha++;
            if( kajina[i] == ')')
                mihidy++;
        }
        else if(!isdigit(kajina[i] && kajina[i] != ',') && m && mivoha == mihidy){
            m=0;
            *litera = kajina[i];
            v[j] = '\0';
            j=0;
        }
        else if(!m && i!=0){
            f[j] = kajina[i];
            j++;
        }
        if(!isdigit(kajina[i] && kajina[i] != ',') && (mivoha != mihidy))
            n=1;
    }
    f[j]='\0';
    if(*litera == 0 && n){
        strcpy(kajina, v);
        char *p = strchr(kajina, '(');
        memmove(p, p+1, strlen(p));
        kajina[strlen(kajina)-1] = '\0';
        goto miverina;
    }
   
    char *p1 = strchr(v, '(');
    char *p2 = strchr(f, '(');
    if(p1 != NULL || p2 != NULL)
        return 1;
    return 0;
}

double kajy(char *kaj){
    double valiny=0, tmp=0;
    int j=0, m=1, r=0;
    char litera=0;
    char v[256], f0[256], *f, manelanelana=0;
    char kajina[256];

    strcpy(kajina, kaj);

    if(manasaraka(kajina, v, f0, &manelanelana)){
        sprintf(kajina, "%g%c%g\0", kajy(v), manelanelana, kajy(f0));
    }

    for(int i=0; i<strlen(kajina) ; i++){
        if(((isdigit(kajina[i]) || kajina[i] == ',') && m) || i==0){
            v[j] = kajina[i];
            j++;
            if(i == 0)
                kajina[0] = '0';
        }
        else if(!isdigit(kajina[i] && kajina[i] != ',') && m){
            m=0;
            litera = kajina[i];
            v[j] = '\0';
        }
        else if(!isdigit(kajina[i] && kajina[i] != ',') && !m){
            r=1;
        }
    }
    f = strchr(kajina, (int)litera);
    if(f[0] == '*' || f[0] == '/')
        f[0]='0';
    if(f[0] == '\0')
        return atof(v);
    else if(r)
        tmp = kajy(f);
    else if(!r)
        tmp = atof(f);

    valiny = atof(v);
    switch(litera){
        case '+':
            valiny += tmp;
            break;
        case '-':
            valiny += tmp;
            break;
        case '*':
            valiny *= tmp;
            break;
        case '/':
            valiny /= tmp;
            break;
    }

    return valiny;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    Mombamomba an'ilay fisehony ito tapany voalohany ito 
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////

GtkWidget *famoronana_varavarana(const gchar *lohateny, int lon, int lar){
    GtkWidget *varavarana;
    varavarana = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(varavarana), lohateny);
    gtk_window_set_default_size(GTK_WINDOW(varavarana), lon, lar);
    gtk_window_set_resizable(GTK_WINDOW(varavarana), FALSE);
    g_signal_connect(G_OBJECT(varavarana), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    return varavarana;
}

void famoronana_bouton(GtkWidget **bouton , const char *teny){
    *bouton = gtk_button_new_with_label(teny);
}

void mametraka_css(GtkWidget *zavatra, char *anarana){
    GtkStyleContext *contexte = gtk_widget_get_style_context(zavatra);
    gtk_style_context_add_class(contexte, anarana);

    GtkCssProvider *file = gtk_css_provider_new();
    gtk_css_provider_load_from_file(file, g_file_new_for_path("/usr/local/src/style.css"), NULL);

    gtk_style_context_add_provider(contexte, GTK_STYLE_PROVIDER(file), GTK_STYLE_PROVIDER_PRIORITY_USER);
}

gboolean manidry(GtkWidget *fampidiara, GdkEventKey *key, gpointer data){
    guint l = key->keyval;
    gchar litera = gdk_keyval_to_unicode(l);
    if((litera >= '0' && litera <= '9') ||litera == ','||litera == '('||litera==')'||l==GDK_KEY_BackSpace||litera == '/'||litera == '*'||litera == '-'||litera == '+'||l==GDK_KEY_Return||l==GDK_KEY_Left||l==GDK_KEY_Right)
        return FALSE;
    return TRUE;
}

void manindry_0(GtkWidget *bouton, gpointer data){
    const gchar *teny;
    teny = gtk_entry_get_text(GTK_ENTRY(data));
    gtk_entry_set_text(GTK_ENTRY(data), g_strdup_printf("%s0", teny));
}
void manindry_1(GtkWidget *bouton, gpointer data){
    const gchar *teny;
    teny = gtk_entry_get_text(GTK_ENTRY(data));
    gtk_entry_set_text(GTK_ENTRY(data), g_strdup_printf("%s1", teny));
}
void manindry_2(GtkWidget *bouton, gpointer data){
    const gchar *teny;
    teny = gtk_entry_get_text(GTK_ENTRY(data));
    gtk_entry_set_text(GTK_ENTRY(data), g_strdup_printf("%s2", teny));
}
void manindry_3(GtkWidget *bouton, gpointer data){
    const gchar *teny;
    teny = gtk_entry_get_text(GTK_ENTRY(data));
    gtk_entry_set_text(GTK_ENTRY(data), g_strdup_printf("%s3", teny));
}
void manindry_4(GtkWidget *bouton, gpointer data){
    const gchar *teny;
    teny = gtk_entry_get_text(GTK_ENTRY(data));
    gtk_entry_set_text(GTK_ENTRY(data), g_strdup_printf("%s4", teny));
}
void manindry_5(GtkWidget *bouton, gpointer data){
    const gchar *teny;
    teny = gtk_entry_get_text(GTK_ENTRY(data));
    gtk_entry_set_text(GTK_ENTRY(data), g_strdup_printf("%s5", teny));
}
void manindry_6(GtkWidget *bouton, gpointer data){
    const gchar *teny;
    teny = gtk_entry_get_text(GTK_ENTRY(data));
    gtk_entry_set_text(GTK_ENTRY(data), g_strdup_printf("%s6", teny));
}
void manindry_7(GtkWidget *bouton, gpointer data){
    const gchar *teny;
    teny = gtk_entry_get_text(GTK_ENTRY(data));
    gtk_entry_set_text(GTK_ENTRY(data), g_strdup_printf("%s7", teny));
}
void manindry_8(GtkWidget *bouton, gpointer data){
    const gchar *teny;
    teny = gtk_entry_get_text(GTK_ENTRY(data));
    gtk_entry_set_text(GTK_ENTRY(data), g_strdup_printf("%s8", teny));
}
void manindry_9(GtkWidget *bouton, gpointer data){
    const gchar *teny;
    teny = gtk_entry_get_text(GTK_ENTRY(data));
    gtk_entry_set_text(GTK_ENTRY(data), g_strdup_printf("%s9", teny));
}
void manindry_p(GtkWidget *bouton, gpointer data){
    const gchar *teny;
    teny = gtk_entry_get_text(GTK_ENTRY(data));
    gtk_entry_set_text(GTK_ENTRY(data), g_strdup_printf("%s+", teny));
}
void manindry_m(GtkWidget *bouton, gpointer data){
    const gchar *teny;
    teny = gtk_entry_get_text(GTK_ENTRY(data));
    gtk_entry_set_text(GTK_ENTRY(data), g_strdup_printf("%s-", teny));
}
void manindry_f(GtkWidget *bouton, gpointer data){
    const gchar *teny;
    teny = gtk_entry_get_text(GTK_ENTRY(data));
    gtk_entry_set_text(GTK_ENTRY(data), g_strdup_printf("%s*", teny));
}
void manindry_d(GtkWidget *bouton, gpointer data){
    const gchar *teny;
    teny = gtk_entry_get_text(GTK_ENTRY(data));
    gtk_entry_set_text(GTK_ENTRY(data), g_strdup_printf("%s/", teny));
}
void manindry_p1(GtkWidget *bouton, gpointer data){
    const gchar *teny;
    teny = gtk_entry_get_text(GTK_ENTRY(data));
    gtk_entry_set_text(GTK_ENTRY(data), g_strdup_printf("%s(", teny));
}
void manindry_p2(GtkWidget *bouton, gpointer data){
    const gchar *teny;
    teny = gtk_entry_get_text(GTK_ENTRY(data));
    gtk_entry_set_text(GTK_ENTRY(data), g_strdup_printf("%s)", teny));
}
void manindry_te(GtkWidget *bouton, gpointer data){
    const gchar *teny;
    teny = gtk_entry_get_text(GTK_ENTRY(data));
    gtk_entry_set_text(GTK_ENTRY(data), g_strdup_printf("%s,", teny));
}
void manindry_fafana(GtkWidget *bouton, gpointer data){
    const gchar *teny;
    char t[500];
    teny = gtk_entry_get_text(GTK_ENTRY(data));
    strcpy(t, teny);
    t[strlen(t)-1]='\0';
    gtk_entry_set_text(GTK_ENTRY(data), g_strdup_printf("%s", t));
}
void kajio(GtkWidget *fampidirana, gpointer data){
    const gchar *teny;
    char t[500];
    teny = gtk_entry_get_text(GTK_ENTRY(fampidirana));
    strcpy(t, teny);
    gtk_entry_set_text(GTK_ENTRY(fampidirana), g_strdup_printf("%0.18g\n", kajy(t)));
}
void manindry_e(GtkWidget *bouton, gpointer data){
    const gchar *teny;
    char t[500];
    teny = gtk_entry_get_text(GTK_ENTRY(data));
    strcpy(t, teny);
    gtk_entry_set_text(GTK_ENTRY(data), g_strdup_printf("%0.18g\n", kajy(t)));
}


void mampiseo_mombamomba(GtkWidget *bouton, gpointer data){
    GtkWidget *fampisehoana;

    fampisehoana = gtk_message_dialog_new(GTK_WINDOW(data), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_NONE, "Ity dia programa noforoni'ny Chatle573.\nIzay fikajiana no nanaovana azy ity.\n");
    gtk_dialog_add_button(GTK_DIALOG(fampisehoana), "Hiala", 1);
    gtk_window_set_title(GTK_WINDOW(fampisehoana), "Mombamomba ilay application!");
    gtk_dialog_run(GTK_DIALOG(fampisehoana));
    gtk_widget_destroy(fampisehoana);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    Ity ny vatan'ilay programa
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////

int vatany(GtkWidget *var){
    GtkWidget *grid;
    GtkWidget *bouton[20];
    GtkWidget *fampidirana;

    GtkWidget *box;
    GtkWidget *menu, *sous, *menubar;

    box = gtk_box_new(TRUE, 0);
    gtk_container_add(GTK_CONTAINER(var), box);

    menu = gtk_menu_new();
    sous = gtk_menu_item_new_with_label("Mombamomba...");
    g_signal_connect(G_OBJECT(sous), "activate", G_CALLBACK(mampiseo_mombamomba), (GtkWidget*)var);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), sous);

    sous = gtk_menu_item_new_with_label("?");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(sous), menu);

    menubar = gtk_menu_bar_new();
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), sous);
    gtk_box_pack_start(GTK_BOX(box), menubar, FALSE, FALSE, 0);

    grid = gtk_grid_new();
    gtk_box_pack_start(GTK_BOX(box), grid, TRUE, TRUE, 0);
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);

    fampidirana = gtk_entry_new();
    gtk_entry_set_alignment(GTK_ENTRY(fampidirana), 1.0);
    gtk_grid_attach(GTK_GRID(grid), fampidirana, 0, 0, 5, 1);

    famoronana_bouton(&bouton[0], "0");
    famoronana_bouton(&bouton[1], "1");
    famoronana_bouton(&bouton[2], "2");
    famoronana_bouton(&bouton[3], "3");
    famoronana_bouton(&bouton[4], "4");
    famoronana_bouton(&bouton[5], "5");
    famoronana_bouton(&bouton[6], "6");
    famoronana_bouton(&bouton[7], "7");
    famoronana_bouton(&bouton[8], "8");
    famoronana_bouton(&bouton[9], "9");
    famoronana_bouton(&bouton[10], "+");
    famoronana_bouton(&bouton[11], "-");
    famoronana_bouton(&bouton[12], "*");
    famoronana_bouton(&bouton[13], "/");
    famoronana_bouton(&bouton[14], "=");
    famoronana_bouton(&bouton[15], "fafaina");
    famoronana_bouton(&bouton[16], ",");
    famoronana_bouton(&bouton[17], "(");
    famoronana_bouton(&bouton[18], ")");

    gtk_grid_attach(GTK_GRID(grid), bouton[1], 0, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), bouton[2], 1, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), bouton[3], 2, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), bouton[4], 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), bouton[5], 1, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), bouton[6], 2, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), bouton[7], 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), bouton[8], 1, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), bouton[9], 2, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), bouton[0], 0, 5, 3, 1);
    gtk_grid_attach(GTK_GRID(grid), bouton[13], 3, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), bouton[12], 3, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), bouton[11], 3, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), bouton[15], 4, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), bouton[10], 4, 2, 1, 2);
    gtk_grid_attach(GTK_GRID(grid), bouton[14], 4, 4, 1, 2);
    gtk_grid_attach(GTK_GRID(grid), bouton[16], 3, 5, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), bouton[17], 0, 1, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), bouton[18], 2, 1, 2, 1);

    for(int i=0; i<19 ; i++)
        if(i != 15)
            mametraka_css(bouton[i], "bouton");
    mametraka_css(bouton[15], "bouton1");
    mametraka_css(fampidirana, "fampidirana");
    mametraka_css(var, "var");

    g_signal_connect(G_OBJECT(bouton[0]), "clicked", G_CALLBACK(manindry_0), fampidirana);
    g_signal_connect(G_OBJECT(bouton[1]), "clicked", G_CALLBACK(manindry_1), fampidirana);
    g_signal_connect(G_OBJECT(bouton[2]), "clicked", G_CALLBACK(manindry_2), fampidirana);
    g_signal_connect(G_OBJECT(bouton[3]), "clicked", G_CALLBACK(manindry_3), fampidirana);
    g_signal_connect(G_OBJECT(bouton[4]), "clicked", G_CALLBACK(manindry_4), fampidirana);
    g_signal_connect(G_OBJECT(bouton[5]), "clicked", G_CALLBACK(manindry_5), fampidirana);
    g_signal_connect(G_OBJECT(bouton[6]), "clicked", G_CALLBACK(manindry_6), fampidirana);
    g_signal_connect(G_OBJECT(bouton[7]), "clicked", G_CALLBACK(manindry_7), fampidirana);
    g_signal_connect(G_OBJECT(bouton[8]), "clicked", G_CALLBACK(manindry_8), fampidirana);
    g_signal_connect(G_OBJECT(bouton[9]), "clicked", G_CALLBACK(manindry_9), fampidirana);
    g_signal_connect(G_OBJECT(bouton[10]), "clicked", G_CALLBACK(manindry_p), fampidirana);
    g_signal_connect(G_OBJECT(bouton[11]), "clicked", G_CALLBACK(manindry_m), fampidirana);
    g_signal_connect(G_OBJECT(bouton[12]), "clicked", G_CALLBACK(manindry_f), fampidirana);
    g_signal_connect(G_OBJECT(bouton[13]), "clicked", G_CALLBACK(manindry_d), fampidirana);
    g_signal_connect(G_OBJECT(bouton[15]), "clicked", G_CALLBACK(manindry_fafana), fampidirana);
    g_signal_connect(G_OBJECT(bouton[16]), "clicked", G_CALLBACK(manindry_te), fampidirana);
    g_signal_connect(G_OBJECT(bouton[17]), "clicked", G_CALLBACK(manindry_p1), fampidirana);
    g_signal_connect(G_OBJECT(bouton[18]), "clicked", G_CALLBACK(manindry_p2), fampidirana);
    g_signal_connect(G_OBJECT(bouton[14]), "clicked", G_CALLBACK(manindry_e), fampidirana);

    g_signal_connect(G_OBJECT(fampidirana), "key-press-event", G_CALLBACK(manidry), NULL);
    g_signal_connect(G_OBJECT(fampidirana), "activate", G_CALLBACK(kajio), NULL);

    return 1;
}

void mande(GtkWidget *fivoarana){
    for(int i=0; i<50; i++){
        gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(fivoarana), i/50.0);
        gtk_main_iteration();
        g_usleep(100000);
    }
}

int fiatombohany(GtkWidget *var){
    GtkWidget *fivoarana;
    GtkWidget *box;

    box = gtk_box_new(TRUE, 0);
    gtk_container_add(GTK_CONTAINER(var), box);

    fivoarana = gtk_progress_bar_new();
    gtk_progress_bar_set_text(GTK_PROGRESS_BAR(fivoarana), "\n\nTongasoa!!!");
    gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(fivoarana), TRUE);

    GtkCssProvider *pro = gtk_css_provider_new();
    gtk_css_provider_load_from_data(pro, 
        "progressbar {\n"
        "  background-color: rgb(76, 187, 24);\n"
        "  background: linear-gradient(180deg, blue, green);\n"
        "}\n"
        "progressbar text {\n"
        "  color: #000000;\n" 
//        "  text-align: center;\n"
        "  font-size: 50px;\n"
        "}\n", -1, NULL);
    GtkStyleContext *con = gtk_widget_get_style_context(fivoarana);
    gtk_style_context_add_provider(con, GTK_STYLE_PROVIDER(pro), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    gtk_box_pack_start(GTK_BOX(box), fivoarana, TRUE, TRUE, 0);
    
    gtk_widget_show_all(var);
    mande(fivoarana);
    gtk_widget_destroy(box);
    return 1;
}

int alefa(int argc, char **argv){
    GtkWidget *var;
    gtk_init(&argc, &argv);
    var = famoronana_varavarana("Fampisehoana ny endrika", 400, 400);
    fiatombohany(var);

    vatany(var);

    gtk_widget_show_all(var);
    gtk_main();
    return EXIT_SUCCESS;
}

