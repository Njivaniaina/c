/****************************************************************************************************
 * 																									*
 *   		Mpanoratra : Sanda , Njiva, Andry, Christon												*	
 * 																									*
 * 			Mombamoba ilay programa : Tableau périodique (Tapany lalao ara-teny sy ara-isa) 		*
 * 																									*
 * 			Daty nahavitana azy : 27 Aprily 2023														*
 * 																									*																				*
 ***************************************************************************************************/

///Fanamarihana:
    /********************************************************************************************************
     *                                                                                                      *
     *   Ny variabla "teny" dia misy ireo dikan-teny rehetra ao anatin'ny programa rehetra , ohatra : ireo  *
     *   lohateny rehetra .... Izy io dia afaka ovaina ao amin'ny alalan'ny "fichier language.txt" raha     *
     *   ohatra ka sendra misy diso na anampy ny ao.                                                        * 
     *                                                                                                      *
     *******************************************************************************************************/


#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include "exploiter.h"

int isaN_ajambany(int max){								///Natao hoa akana tsy misafidy ilay atoma izay ho lalaovina
	srand(time(NULL));
	return (rand()%(max-0+1)-0);
}

int fandresena(int *fanamarinana, int n){								///Hanamarinana na hijerena hoe iza ny litera hita ao apmin'ny kilalao ara-teny
	int mandeha=1;
	for(int i=0;i<n;i++){
		if( *(fanamarinana+i) == 0){							///Raha ohatra ka mbola misy '1'ao amin'ilay variabla 'w' dia mbola atao 1 foana no havoakan'ity mpiasa ity dia mande foana ny lalao
			mandeha=0;
		}
	}
	return mandeha;										//Averina ilay izy raha mbola mande ny lalao na tsy
}

void fanamarinana_litera(char teny_miafina[10], int* fanamarinana ,char litera, int n, int *isa_andrana){					///Hanamarinana fa ao anatin'ilay teny ny litera iray na tsy.
	int misy=0;
	
	for(int i=0;i<n;i++){
		if(litera == teny_miafina[i]){						//Raha ao anatin'ilay teny ilay litera dia marihana ho 1 ny ao amin'ilay variabla fanamarinana
			fanamarinana[i]=1;
			misy=1;
		}
	}
	if(misy != 1){									//Raha tsy izany dia tsy misy hovaina ny ao anatiny
		(*isa_andrana)-=1;
	}
}

char mamaky_teny(){									///Mba hamakiana litera iray
	char teny='\n';
	
	//teny = getchar();
	while ((teny = getchar()) == '\n' );			//Mba hialana amin'ny fampidirana tsy misy n'inon'inona 
	teny = toupper(teny);							//Atao sora-baventy ilay litera 
	
	return teny;
}

char fandraisana_kilalao(char Teny[100][100]){									///Fandraisana ao amin'ny kilalao
	char safidy=0;
	char mihaotra[2];

	midina_taratasy(20);						
	printf("\e[34m   ________________________________________________________\n");
	printf(" / \\                                                        \\.\n");
	printf("|  |         \e[31;1m _^_                            _^_\e[34m            |.\n");
	printf(" \\-|        \e[31;1m (___)==========================(___)\e[34m           |.\n");	
	printf("   |         \e[31;1m |_|          \e[31;1;5m%s\e[0m\e[31;1m         |_|\e[34m            |.\n", mametraka_alavana(Teny[35], 10));
	printf("   |         \e[31;1m(___)==========================(___)\e[34m           |.\n");
	printf("   |                                                        |.\n");
	printf("   |          \e[33m***********************************\e[34m           |.\n");
	printf("   |          \e[33m[1]=)======> %s <======(=[1]\e[34m           |.\n", mametraka_alavana(Teny[9], 10));
	printf("   |          \e[33m***********************************\e[34m           |.\n");
	printf("   |                                                        |.\n");
	printf("   |          \e[33m***********************************\e[34m           |.\n");
	printf("   |          \e[33m[2]=)======> %s <======(=[2]\e[34m           |.\n", mametraka_alavana(Teny[10], 10));
	printf("   |          \e[33m***********************************\e[34m           |.\n");
	printf("   |                                                        |.\n");
	printf("   |          \e[33m***********************************\e[34m           |.\n");
	printf("   |          \e[33m[3]=)===> %s <===(=[3]\e[34m           |.\n", mametraka_alavana(Teny[11], 16));
	printf("   |          \e[33m***********************************\e[34m           |.\n");
	printf("   |                                                        |.\n");
	printf("   |          \e[33m***********************************\e[34m           |.\n");
	printf("   |          \e[33m[4]=)===> %s <===(=[4]\e[34m           |.\n", mametraka_alavana(Teny[12], 16));
	printf("   |          \e[33m***********************************\e[34m           |.\n");
	printf("   |                                                        |.\n");
	printf("   |                                                        |.\n");
	printf("   |          \e[33m***********************************\e[34m           |.\n");
	printf("   |          \e[33m[5]=)===> %s <===(=[5]\e[34m           |.\n", mametraka_alavana(Teny[69], 16));
	printf("   |          \e[33m***********************************\e[34m           |.\n");
	printf("   |                                                        |.\n");
	printf("   |          \e[33m***********************************\e[34m           |.\n");
	printf("   |          \e[33m[6]=)======> %s <======(=[6]\e[34m           |.\n", mametraka_alavana(Teny[13], 10));
	printf("   |          \e[33m***********************************\e[34m           |.\n");
	printf("   |   _____________________________________________________|____\n");
	printf("   |  /                                                         /.\n");
	printf("   \\-/_________________________________________________________/.\e[0m\n");
	printf("\n\t\e[36m");
	teny_mande_tsikelikely(Teny[6]);    	  	
	printf("\e[0m");
	mandray_teny(mihaotra, 2);
	safidy = mihaotra[0];									///Fakana ilay safidy ...
	system("clear");  
	miakatra_taratasy(28);					
	return safidy;
}

void fanehoana_teny(char teny_miafina[10], int* fanamarinana, int n, int isa_andrana, char Teny[100][100]){				///Fanehoana ilay teny efa ita amin'ny kilalao teny
	int i = 0;
	printf("\n\e[33m%s%d%s\n",Teny[40], isa_andrana, Teny[41]);					//Aseo ny isan'ny andrana sisa ananana
	printf("%s\e[31m", Teny[42]);									 
	for(i=0; i<n; i++){
		if (fanamarinana[i]){
			printf("%c",teny_miafina[i]);										//Aseo ny litera izay efa ita ao amin'ny ilay teny
		}
		else{
			printf("*");														//Raha tsy hita dia atao '*'
		}
	}
	printf("\e[36m\n%s\e[0m", Teny[43]);										//Dia asaina mampiditra litera indray ilay olona 
}

void fanampiana_famatarana(char *mombamomba_atoma, char *marika_atoma, int isa_andrana, int laharana_atomika, float lanja_atomika, int n, int i, int *j, char Teny[100][100]){						///Mba hanehoana marika hamatarana ilay atoma
	if(((fabs(isa_andrana-(2*n))<1&& isa_andrana%2 == 0) || (fabs(isa_andrana-(2*n))<2 && isa_andrana%2 != 0)) && (*j) == 2){									//Ny marika voalohany aseho dia ilay mahakasika ilay atoma
		teny_mande_tsikelikely("\e[32m");
		teny_mande_tsikelikely(Teny[44]);
		printf("\e[34m");
		teny_mande_tsikelikely(mombamomba_atoma);
		teny_mande_tsikelikely("\e[32m.\n");
		teny_mande_tsikelikely(Teny[45]);
		printf("%d", isa_andrana);
		teny_mande_tsikelikely(Teny[41]);
		printf("\e[0m\n\n");
		(*j)--;
	}
	
	/***************************************************************************************
		Ilay variabla i dia entina hamatarana ilay kilalao hoe teny sa isa ilay tadiavina
	****************************************************************************************/
	
	if (fabs(isa_andrana-n)<1 && i && (*j) == 1){								//Ny marika faharoa dia ny lanja sy ny laharana atomika an'ilay atoma raha kilalao teny ilay izy
		teny_mande_tsikelikely("\e[32m");
		teny_mande_tsikelikely(Teny[46]);
		teny_mande_tsikelikely("\n");
		teny_mande_tsikelikely(Teny[47]);
		printf("\e[31m");
		printf("%f", lanja_atomika);
		teny_mande_tsikelikely("\e[32m");
		teny_mande_tsikelikely(Teny[48]);
		printf("\e[31m");
		printf("%d", laharana_atomika);
		teny_mande_tsikelikely(".\e[0m\n\n");
		(*j)--;
		
	}
	if (fabs(isa_andrana-n)<1 && !i && (*j) == 1){								//Ho an'ilay kilalao isa kosa dia aseho ny marika an'ilay atoma
		teny_mande_tsikelikely("\e[32m");
		teny_mande_tsikelikely(Teny[46]);
		teny_mande_tsikelikely("\n");
		teny_mande_tsikelikely(Teny[47]);
		teny_mande_tsikelikely(Teny[49]);
		printf("\e[31m");
		teny_mande_tsikelikely(marika_atoma);
		teny_mande_tsikelikely(".\e[0m\n\n");
		(*j)--;
	}
}

void valiny(int isa_andrana, char *teny_miafina, char *atome, int n, char Teny[100][100]){			///Ity no miteny raha mandresy na tsia ilay olona 
	if( isa_andrana != 0){
		printf("\n\n\t\t\e[33;1m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("\t\t||        \e[33;1;5m %s \e[0m\e[33;1m     ||\n", mametraka_alavana(Teny[50], 15));
		printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		teny_mande_tsikelikely("\t\t        ");
		teny_mande_tsikelikely(Teny[51]);
		printf("\e[31m");			
		teny_mande_tsikelikely(teny_miafina);										//Aseho koa ihany koa ny teny miafia raha teny ilay izy
		printf(".\e[33m     \n");
		if(n){
			teny_mande_tsikelikely("\t\t        ");
			teny_mande_tsikelikely(Teny[52]);
			printf("\e[31m");                                               		///Ity dia hoa an'ny kilalao resaka isa dia aseho eto ny anaran'ilay atoma
			teny_mande_tsikelikely(atome);
			printf(".\e[33m.             \n\n\e[0m");
		}
	}
	if(isa_andrana == 0){															//Tenenina hoe "GAME OVER" raha tsy naharesy ilay olona
		printf("\n\n\t\t\e[33;1m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("\t\t||         \e[33;1;5m%s\e[0m\e[33;1m        ||\n", mametraka_alavana(Teny[53], 14));
		printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		teny_mande_tsikelikely("\t\t        ");
		teny_mande_tsikelikely(Teny[51]);
		printf("\e[31m");
		teny_mande_tsikelikely(teny_miafina);										//Dia tenenina koa ilay teny notediavina
		printf(".\e[33m     \n");
		if(n){																		///Ity dia ho an'ilay kilalao resaka isa
			teny_mande_tsikelikely("\t\t        ");
			teny_mande_tsikelikely(Teny[52]);
			printf("\e[31m");  
			teny_mande_tsikelikely(atome);
			printf(".\e[33m             \n\n\e[0m");
		}
	}
}

void maka_isa(int *isa, char Teny[100][100]){											///Mpamaky isa iray 
	char n[5];
	mandray_teny(n, 5);
	while((*isa = atoi(n)) == 0){													//Hamarinina tsara raha ohatra ka isa marina ilay izy
		printf("\e[41m%s\e[0m\n", Teny[54]);
		mandray_teny(n, 5);
	}
}

void fanamarinana_isa(int n, int num, int* c, char Teny[100][100]){			///Ity dia fitenenana hoe ambony na amban'ilay isa nampidirina ilay isa 
	if(n>num){
		printf("\e[31m%s\e[0m\n\n", Teny[55]);								//tenenina raha ambaniny
		(*c)--;																//Ahena ny isan'ny andrana afaka ataon'ilay olona 
	}
	else if(n<num){
		printf("\e[31m%s\e[0m\n\n", Teny[56]);								//Tenenina raha amboniny
		(*c)--;																//Ahena ihany ilay andrana afaka ataon'ilay olona
	}
}

void fanehoana_vokatra_teny( int n, int m, char *anarana_atoma, char Teny[100][100]){							//Ity dia fitenenana raha nadresy amin'ilay resaka laharana atomika an'ilay olona 
	if( n == m ){													//Na izy mandresy dia aseho ilay izy dia tenenina hoe naharesy
		teny_mande_tsikelikely("\n\e[32m");
		teny_mande_tsikelikely(Teny[57]);
		printf("\n");
		printf(Teny[52]);
		printf("\e[31m");
		teny_mande_tsikelikely(anarana_atoma);
		teny_mande_tsikelikely("\e[32m");
		teny_mande_tsikelikely(Teny[48]);
		printf("\e[31m");
		printf("%d", n);
		teny_mande_tsikelikely(".\e[0m\n");
	}
	else if(n!=m){													//Na izy resy , dia tenenina ihany ilay atoma
		teny_mande_tsikelikely("\n\e[32m");
		teny_mande_tsikelikely(Teny[59]);
		printf("\n");
		printf(Teny[52]);
		printf("\e[31m");
		teny_mande_tsikelikely(anarana_atoma);
		teny_mande_tsikelikely("\e[32m");
		teny_mande_tsikelikely(Teny[48]);
		printf("\e[31m");
		printf("%d", n);
		teny_mande_tsikelikely(".\e[0m\n");
	}
}

void fanehoana_vokatra_isa(int isa_andrana, float n, char *anarana_atoma, char Teny[100][100]){						///Ity kosa dia natao hoan'ilay resaka ara lanja atomika
	if(isa_andrana){														//Raha ohatra ka nandresy ilay olona 
		teny_mande_tsikelikely("\n\e[32m");
		teny_mande_tsikelikely(Teny[57]);
		printf("\n");
		printf(Teny[52]);
		printf("\e[31m");
		teny_mande_tsikelikely(anarana_atoma);
		teny_mande_tsikelikely("\e[32m");
		teny_mande_tsikelikely(Teny[58]);
		printf("\e[31m");
		printf("%f", n);
		teny_mande_tsikelikely(".\e[0m\n");
	}
	else if(!isa_andrana){												//Raha ohatra ka resy ilay olona 
		teny_mande_tsikelikely("\n\e[32m");
		teny_mande_tsikelikely(Teny[59]);
		printf("\n");
		printf(Teny[52]);
		printf("\e[31m");
		teny_mande_tsikelikely(anarana_atoma);
		teny_mande_tsikelikely("\e[32m");
		teny_mande_tsikelikely(Teny[58]);
		printf("\e[31m");
		printf("%f", n);
		teny_mande_tsikelikely(".\e[0m\n");
	}
}

void lohateny_key(int c, char Teny[100][100]){	
	printf("\n\e[33m%s%d%s\n",Teny[40], c, Teny[41]);							///Miteny ilay isan'ny andrana sy miteny ny mba hampidirana indray isa iray(numéro et masse atomique)
	printf("%s\e[0m", Teny[60]);
}

char fandraisana_fahasarotana(char Teny[100][100], char *fahasarotana, int *max){					///Ity dia mahakasika ilay tahampahasarotana an'ilay kilalao
	char mihaotra[2];
	char safidy=0;
	
	if((*max) == 20){								///Hoa an'ilay tahampahasarotana tsotra na "Facile"
		strcpy(fahasarotana, Teny[66]);
	}
	else if((*max) == 60){
		strcpy(fahasarotana, Teny[67]);					///Hoa an'ilay tahampahasarotana antonony na "Moyenne"
	}
	else if((*max) == 118){
		strcpy(fahasarotana, Teny[68]);					///Hoa an'ilay tahampahasarotana sarotra na "difficile"
	}

	printf("\t\t    \e[44m                             \e[0m\n");
	printf("\t\t    \e[41m                             \e[0m\n");
	printf("\t\t    \e[41;6m        %s         \e[0m\n", mametraka_alavana(Teny[65], 13));
	printf("\t\t    \e[41m                             \e[0m\n");
	printf("\t\t    \e[44m                             \e[0m\n");
	printf("\t\t\e[0m\t\n");
	printf("\t\t\e[41m\t                      \e[0m\n");
	printf("\t\t\e[41m\t  [1] : %s     \e[0m\n", mametraka_alavana(Teny[66], 10));
	printf("\t\t\e[41m\t                      \e[0m\n");
	printf("\t\t\e[0m\t\n");
	printf("\t\t\e[41m\t                      \e[0m\n");
	printf("\t\t\e[41m\t  [2] : %s     \e[0m\n", mametraka_alavana(Teny[67], 10));
	printf("\t\t\e[41m\t                      \e[0m\n");
	printf("\t\t\e[0m\t\n");
	printf("\t\t\e[41m\t                      \e[0m\n");
	printf("\t\t\e[41m\t  [3] : %s     \e[0m\n", mametraka_alavana(Teny[68], 10));
	printf("\t\t\e[41m\t                      \e[0m\n\n\n");
	teny_mande_tsikelikely("\e[43m\t");											//Fitenenanan ny niveau  amin'izao
	teny_mande_tsikelikely(Teny[70]);
	teny_mande_tsikelikely(fahasarotana);
	teny_mande_tsikelikely(".\e[0m\n");
	printf("\t\t\e[0m\t\n");
	printf("\n\t\e[36m");
	teny_mande_tsikelikely(Teny[6]);    	  	///Fampisafidianana ilay olona
	printf("\e[0m");
	mandray_teny(mihaotra, 2);
	safidy = mihaotra[0];
	system("clear");
	return safidy;
}

int niveau(char *fahasarotana, char Teny[100][100], int *m){								///Ity no mahakasika ilay sokajy misy ao amin'ny fisafidianana ny fahasarona'ilay kilalao
	int max;
	
	switch (fandraisana_fahasarotana(Teny, fahasarotana, m)){
		
		case '1' : {
			max = 20;														///Ho an'ilay sokajy mora dia , atao ho 20 ny isan'ilay atoma ampiasaina
			strcpy(fahasarotana, Teny[66]);	
			break ;
		}
		case '2' : {
			max = 60;														///Ho an'ilay sokajy atonony dia , atao ho 60 ny isan'ilay atoma ampiasaina
			strcpy(fahasarotana, Teny[67]);	
			break ;
		}		
		case '3' : {
			max = 118;														///Ho an'ilay sokajy sarotra dia , izy rehetra no atoma ampiasaina
			strcpy(fahasarotana, Teny[68]);
			break ;
		}
		default :{
			printf("\e[41m	    %s    \e[0m                            \n", mametraka_alavana(Teny[32], 23));
			sleep(3);
			break;
		}
	}
	return max;
}

char **maka_isa_andrana(){									///Fakana ireo isan'ny andrana afaka ataon'ilay mpilalao isakay ny kilalao ity 
	char *teny=(char*)malloc(50);
	char** isa = (char**)malloc(sizeof(char*)*4);
	for(int i=0;i<4;i++)
		*(isa+i) = (char*)malloc(50);
	FILE *conf = fopen("etc/tableau.conf", "r");				//Ao amin'ny "fichier tableau.conf" ny mombamomba ny "coups" azo ampiasain'ny mpilalao
	
	if(conf != NULL){
		fgets(teny, 50, conf);
		for(int k=0;k<4;k++){
			fgets(teny, 50, conf);
			teny = strchr(teny, '=');
			for(int i=0;i<strlen(teny);i++){
				*(teny+i)=*(teny+i+1);
			}
			*(teny+strlen(teny)-1)='\0';
			strcpy(isa[k], teny);
		}
		fclose(conf);
	}
	else
		printf("\033[31mMisy olana eo amin'ny fanokafana ilay fanamboarana \"tableau.conf\" !!!\033[0m");
	return isa;     									//Averina ho teny ilay izy dia avadika rehefa mampiasa azy
}

void lalao(char anarana_atoma[118][30], char marika_atoma[118][5], char mombamomba_atoma[118][100], int laharana_atomika[118], float lanja_atomika[118], char Teny[100][100], char *fahasarotana, char *argv[], int argc, int *max){
	int *fanamarinana=0;											//fanamarinana ny litera ita ao amin'ny kilalao teny
	char litera=0, ch[100];											//Ho an'ilay litera raisina ao amin'ny fakana litera ampidirin'ilay olona sy variabla ao amin'ny fanatoana fijerena zavatra...
	char teny_miafina[30];											//Ho an'ilay teny miafina (nom ou symbole)
	int isa_ajambany=0,												//Ilay isa nalaina ajambany 
		isa_andrana=10,												//Isan'ny andrana ahafahan'ny mpilalao manadrana maminaviana
		n=0,														//Isan'ilay litera ao amin'ny teny iray
		isa=0,													//Ilaina amin'ny fitahirizana an'ilay isa ampidirin'ilay mpilalao
		hiala=1;														//Hialana ao amin'ilay kilalao
	int j=0;														//Halalana hoe ilay fanampiana famatarana voalohany sa faharoa no alefa

	if(argc == 3){													///Raha toa ka misy "argument"
		if (strcmp(argv[2], "1") == 0)
			goto m21;
		else if (strcmp(argv[2], "2") == 0)
			goto m22;
		else if (strcmp(argv[2], "3") == 0)
			goto m23;
		else if (strcmp(argv[2], "4") == 0)
			goto m24;
		else if (strcmp(argv[2], "5") == 0)
			goto m25;
	}

	while(hiala){										///Raha toaka tsy mbola miala ao amin'ny lalao ilay olona dia averina foana ny "menu"
		if((*max) == 20){								///Hahafatarana ny zavatra aseho ao amin'ny fampisehoana ny tahampahasarotana ao amin'ny fandraisana fisafidianana ny fahasarotana
			strcpy(fahasarotana, Teny[66]);
		}
		else if((*max) == 60){
			strcpy(fahasarotana, Teny[67]);					///Ity dia manome fa atonony ny tahampahasarotana tokony aseho 
		}
		else if((*max) == 118){
			strcpy(fahasarotana, Teny[68]);					///Ity dia manome fa sarotra ny tahampahasarotana tokony aseho 
		}

		switch(fandraisana_kilalao(Teny)){
			case '1':												//Kilalao voalohany : maminavina ilay anaran'ilay atoma
				m21:
				printf("\e[32m");
				teny_mande_tsikelikely(Teny[36]);
				printf("\n\e[0m");
				isa_ajambany=isaN_ajambany(*max);									//Safidina anjambany ny laharana atomika an'ireo atoma manaraka ny fahasarotan'ny kilalao
				strcpy(teny_miafina, anarana_atoma[isa_ajambany]);					//Atao ao anatin'ny variable iray ny anaran'ilay atoma iray
				n=strlen(teny_miafina);										//Isaina ny isan'ny litera ao anatin'ilay teny
				for(int i=0;i<n;i++){
					teny_miafina[i]=toupper(teny_miafina[i]);				//Atao ho sora-baventy daholo ireo litera ao amin'ny anarana mba hanamora ny fanamarinana azy
				}
				isa_andrana=atoi(maka_isa_andrana()[0]);												//Fanombohana ilay isan'ny andrana afaka aton'ny mpilalao
				j=2;														//Marihana ilay fandefasana ilay fanampiana ny mpilalao : ny voalohany dia rehefa 2 ary ny faharoha dia rehefa 1
				fanamarinana = (int*)malloc(sizeof(int)*n);						
	
				for(int i=0;i<n;i++){
					fanamarinana[i]=0;													//Atomboka ihany koa ilay teny famantarana ny litera hita atao 0 (tsy hita daholo ny litera)
				}
		
				while(!fandresena(fanamarinana, n) && isa_andrana != 0){								///Rehefa mbola tsy hita tanteraka ilay teny na mbola manana andrana ilay olona dia alefa foana (while(1))
					fanampiana_famatarana(mombamomba_atoma[isa_ajambany], marika_atoma[isa_ajambany], isa_andrana, laharana_atomika[isa_ajambany], lanja_atomika[isa_ajambany], (int)(atoi(maka_isa_andrana()[0])/2), 1, &j, Teny); 		//Tenenina amin'ny voalohany ny fanampiana voalohany ary rehefa misasaka kosa no aseo ny faharoa
					fanehoana_teny(teny_miafina, fanamarinana, n, isa_andrana, Teny);					//Aseho ireo litera hita na '*' izay tsy mbola hita
					litera=mamaky_teny();																//Famakiana ilay litera ampidirina 
					fanamarinana_litera(teny_miafina, fanamarinana, litera, n, &isa_andrana);			//Fanamarinana raha misy an'ilay litera ao amin'ilay teny (anaran'ilay atoma)
				}
				valiny(isa_andrana, teny_miafina, anarana_atoma[isa_ajambany], 0, Teny);						//Aseho ny valiny
				teny_mande_tsikelikely(Teny[31]);														//Ajanona kely
				mandray_teny(ch, 100);
				system("clear");
				free(fanamarinana);
			break;
				
			case '2':												//Faharoa : dia ny faminafinana marika atoma iray
				m22:
				/***************************************************************************************************************
				 * Ity dia mitovy tanteraka amin'ny fanaovana ilay faminavinana anarana fa saingy marika fotsiny no tadiavina  *
				 **************************************************************************************************************/
				 
				printf("\e[32m");
				teny_mande_tsikelikely(Teny[37]);
				printf("\n\e[0m");
				isa_ajambany=isaN_ajambany(*max);
				strcpy(teny_miafina, marika_atoma[isa_ajambany]);
				n=strlen(teny_miafina);
				for(int i=0;i<n;i++){
					teny_miafina[i]=toupper(teny_miafina[i]);
				}
				isa_andrana=atoi(maka_isa_andrana()[1]);											///Atao 4 fotsiny satria fohy kely ny marikana atoma iray
				j=2;													
				fanamarinana = (int*)malloc(sizeof(int)*n);
	
				for(int i=0;i<n;i++){
					fanamarinana[i]=0;
				}
		
				while(!fandresena(fanamarinana, n) && isa_andrana != 0){
					fanampiana_famatarana(mombamomba_atoma[isa_ajambany], marika_atoma[isa_ajambany], isa_andrana, laharana_atomika[isa_ajambany], lanja_atomika[isa_ajambany], (int)(atoi(maka_isa_andrana()[1])/2), 1, &j, Teny);
					fanehoana_teny(teny_miafina, fanamarinana, n, isa_andrana, Teny);
					litera=mamaky_teny();
					fanamarinana_litera(teny_miafina, fanamarinana, litera, n, &isa_andrana);
				}
				valiny(isa_andrana, teny_miafina, anarana_atoma[isa_ajambany], 1, Teny);
				teny_mande_tsikelikely(Teny[31]);				
				mandray_teny(ch, 100);
				system("clear");
				free(fanamarinana);
			break;
			
			case '3':																	///Fahatelo : natao ho an'ny lalao maminavina ny laharana atomika 
				m23:
				printf("\e[32m");
				teny_mande_tsikelikely(Teny[38]);
				printf("\n\e[0m");
				isa_ajambany=isaN_ajambany(*max);
				isa_andrana = atoi(maka_isa_andrana()[2]);																	//Ny isan'ny andrana dia 6 indray raha ny amin'ity lalao ity dia mitovy amin'ireo teo ambony ihany ny fanaovana azy
				j=2;																				
				while(isa_andrana != 0 && isa != laharana_atomika[isa_ajambany]){					
					fanampiana_famatarana(mombamomba_atoma[isa_ajambany], marika_atoma[isa_ajambany], isa_andrana, laharana_atomika[isa_ajambany], lanja_atomika[isa_ajambany], (int)(atoi(maka_isa_andrana()[2])/2), 0, &j, Teny);
					lohateny_key(isa_andrana, Teny);													
					maka_isa(&isa, Teny);															
					fanamarinana_isa(isa, laharana_atomika[isa_ajambany], &isa_andrana, Teny);			//Mamantatra ilay isa nampidirina raha ambony na ambanin'ilay tokony ho izy
				}
				fanehoana_vokatra_teny( laharana_atomika[isa_ajambany], isa, anarana_atoma[isa_ajambany], Teny);    //Mampiseho raha naharesy ilay mpilalao
				teny_mande_tsikelikely(Teny[31]);															//Ajanona kely eo aloha ny fanehoana ny valiny
				mandray_teny(ch, 100);
				system("clear");
			break;
			
			case '4':											///Fahaefatra farany : faminavinana ny lanja atomika (Ity dia mitovy tanteraka amin'ny faminavinana ny laharana atomika ny fanaovana azy fa saingy manakaikin'ilay lanja fotsiny dia maharesy fa tsy voatery ita tsara)
				m24:
				printf("\e[32m");
				teny_mande_tsikelikely(Teny[39]);
				printf("\n\e[0m");
				isa_ajambany=isaN_ajambany(*max);
				isa_andrana = atoi(maka_isa_andrana()[3]);
				j=2;																		
				while(isa_andrana != 0 && fabs(isa-lanja_atomika[isa_ajambany])>1){		
					fanampiana_famatarana(mombamomba_atoma[isa_ajambany], marika_atoma[isa_ajambany], isa_andrana, laharana_atomika[isa_ajambany], lanja_atomika[isa_ajambany], (int)(atoi(maka_isa_andrana()[3])/2), 0, &j, Teny);
					lohateny_key(isa_andrana, Teny);														
					maka_isa(&isa, Teny);														 
					fanamarinana_isa(isa, lanja_atomika[isa_ajambany], &isa_andrana, Teny);					
				}
				fanehoana_vokatra_isa(isa_andrana, lanja_atomika[isa_ajambany], anarana_atoma[isa_ajambany], Teny);    	    
				teny_mande_tsikelikely(Teny[31]);						
				mandray_teny(ch, 100);	
				system("clear");
			break;

			case '5':
				m25:
				*max = niveau(fahasarotana, Teny, max);												///Ho an'ilay fisafidianana tahampahasarotana 
			break;
			
			case '6':
				hiala=0;																		///Hahafahana miverina amin'ny fandraisana voalohany
			break;
			
			default :																		///Fisorohana ny safidy tsy misy
				fampitandremana(Teny);
				sleep(3);
				system("clear");
			break;
		}
	}
}
