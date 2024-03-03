#ifndef JEU
#define JEU

int isaN_ajambany(int max);

int fandresena(int *fanamarinana, int n);

void fanamarinana_litera(char teny_miafina[10], int* fanamarinana ,char litera, int n, int *isa_andrana);

char mamaky_teny();

char fandraisana_kilalao(char Teny[100][100]);

void fanehoana_teny(char teny_miafina[10], int* fanamarinana, int n, int isa_andrana, char Teny[100][100]);

void fanampiana_famatarana(char *mombamomba_atoma, char *marika_atoma, int isa_andrana, int laharana_atomika, float lanja_atomika, int n, int i, int *j, char Teny[100][100]);

void valiny(int isa_andrana, char *teny_miafina, char *atome, int n, char Teny[100][100]);

void maka_isa(int *isa, char Teny[100][100]);

void fanamarinana_isa(int n, int num, int* c, char Teny[100][100]);

void fanehoana_vokatra_teny( int n, int m, char *anarana_atoma, char Teny[100][100]);

void fanehoana_vokatra_isa(int isa_andrana, float n, char *anarana_atoma, char Teny[100][100]);

void lohateny_key(int c, char Teny[100][100]);

char fandraisana_fahasarotana(char Teny[100][100], char *fahasarotana, int *max);

int niveau(char *fahasarotana, char Teny[100][100], int *m);

char **maka_isa_andrana();

void lalao(char anarana_atoma[118][30], char marika_atoma[118][5], char mombamomba_atoma[118][100], int laharana_atomika[118], float lanja_atomika[118], char Teny[100][100], char *fahasarotana, char *argv[], int argc, int *max);

#endif