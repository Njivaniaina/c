/************************************************************************************************
 * 																					            *
 *   		Mpanoratra : Sanda , Njiva, Andry, Christon									        *	
 * 																					            *
 * 			Mombamomba azy : Tableau périodique (Tapany moban'ny fiteny ao amin'ny programa) 	*
 * 																					            *
 * 			Daty nahavitana azy : 27 Avril 2023										            *
 * 																					            *
 * 			Ny ato anatiny : Ato daholo ireo fakana ireo dikan'ny teny ampiasaina rehetra 		*
 * 																					            *
 ************************************************************************************************/

///Fanamarihana:
    /********************************************************************************************************
     *                                                                                                      *
     *   Ireo variabla "mots" dia variabla izay misy an'ny dika-teny amin'izay fiteny nofidiana             *
     *   , izay miasa ao amin'ny programa iray manontolo koa. Afaka ovaina na anampiana ireo ao amin'ny     *
     *   "fichier language.txt" , raha toa ka mila izany fanovana na fanampiana izany.                      *
     *                                                                                                      *
     ********************************************************************************************************/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include "exploiter.h"


void fanavaozana_fiteny(char teny_voadika[100][100], char *fiteny){                                ///Ity dia mba hanavaozana isaky izay manolo fiteny sy amin'ny voalohan'ny programa ny fiteny ampiasaina 
    FILE *rakibolana = NULL;                                           //Fanasiavana ireo dika-teny rehetra no hilavana ity "fichier" izay hosokafana ity
    char fasina_teny[300];                                                   //Anasiana teny alaina 
    int n=0, i=0, l=0;                                                   //variabla ilay ao amin'ny : fanisana teny, fahafantarana ny teny ampiasaina ,...
    int isa_teny_adika=100;                                              //Fanisana ireo isan'ny teny adika ao amin'ilay programma

    rakibolana = fopen("language.txt", "r");                           //Fanokafana ilay rakibolana
   
    if(rakibolana != NULL){
        fgets(fiteny, 100, rakibolana);                              //Ny andalana voalohany ao amin'ny rakibolana dia milaza ny teny ampiasaina 
        l = strlen(fiteny);
        fiteny[l-1] = '\0';
        
        for(int j=0; j<isa_teny_adika; j++){
            if(strcmp(fiteny, "francais") == 0)                            //Raha toa ka frantsay ilay teny
                n=0;
            else if(strcmp(fiteny, "malagasy") == 0)                            //Raha toa ka malagasy ilay teny
                n=1;
            else if(strcmp(fiteny, "anglais") == 0)                            //Raha toa ka angilisy ilay teny
                n=2;

            fgets(fasina_teny, 300, rakibolana);
            l=0;
            for( i=0; fasina_teny[i] != '\n';i++ ){
                if(n == 0 && fasina_teny[i] != '='){            //Atao ao anaty variabla isaky ny litera iray mandrapaha tonga amin'ny '='
                    teny_voadika[j][l]=fasina_teny[i];
                    l++;
                }
                if( fasina_teny[i] == '=' ){                     //rehefa misy '=' dia mihena ilay n ka rehefa n=0 ihany vao alaina ilay teny
                    n--;
                }
            }
            teny_voadika[j][l]='\0';
        }
        fclose(rakibolana);
    }
    else {                                                       ///Raha toa ka tsy mety ny fanokafana ilay rakibolana 
        printf("Misy olana amin'ny fanokafana an'ilay \"rakibolana\".\n");
    }
}

void manova_fiteny(char *fiteny){                                 //Fanovana ny fiteny miasa ao amin'ny programa
    FILE *rakibolana=NULL, *rakibolana_tahaka = NULL;
    char fehezanteny[300];

    rakibolana = fopen("language.txt", "r");                               //Fanokafana ialy rakibolana ho azo vakiana 
    rakibolana_tahaka = fopen("temporaire.txt", "w");                      //Fanokafana ny "fichier temporaire" iray asiana ireo dikanteny rehetra
    if( rakibolana != NULL && rakibolana_tahaka !=  NULL){                             //Adika ao amin'ilay "fichier temporaire" ireo dikanteny rehetra
        while(fgets(fehezanteny, 300, rakibolana) != NULL){   
            fprintf(rakibolana_tahaka, "%s", fehezanteny);
        }
        fclose(rakibolana_tahaka);                                            //Hidina daholo amin'izay
        fclose(rakibolana);
    }
    else{                                                              //Raha sedra ka misy tsy mety ny fanokafana ireo "fichier"
        printf("Misy olana ao amin'ny fakana tahaka ilsy \"fichier\" foronina ahanovana azy!!!!\n");
    }

    rakibolana = fopen("language.txt", "w");                               //Averina sokafana indray ilay "fichier" mba ahafahana manoratra
    rakibolana_tahaka = fopen("temporaire.txt", "r");                      //Ohatran'izay koa ilay "fichier temporaire" fa hahafahana mamaky kosa indray
    if( rakibolana != NULL && rakibolana_tahaka !=  NULL){
        fgets(fehezanteny, 300, rakibolana_tahaka);                                //Alaina fotsiny ny andalana voalohany ao amin'ilay "fichier temporaire"
        fprintf(rakibolana, "%s\n", fiteny);                               //Soloana ilay fiteny vaovao kosa ny ao amin'ilay rakibolana 
        while(fgets(fehezanteny, 300, rakibolana_tahaka) != NULL){                 //Averina ao amin'ilay rakibolana daholo amin'izay ireo dikanteny rehetra
            fprintf(rakibolana, "%s", fehezanteny);
        }
        remove("temporaire.txt");                                           //Fafaina amin'izay ilay "fichier temporaire" fa tsy ilaina intsony
        fclose(rakibolana_tahaka);                                            //Idina daholo ireo "FILE" izay nosokafana rehetra
        fclose(rakibolana);
    }
    else{
        printf("Misy olana ao amin'ilay fakana tahaka ilay rakibolana_tahaka!!!!\n");
    }
}

char fandraisan_ao_fiteny(char Teny[100][100]){												//Ity kosa dia fanehoana ny "meny de la language"
	char t=0;
	char mihaotra[2];								//Hasiana ny safidy raha mihaotra ilay zavatra ampidirin'ilay mpanjifa
	
	midina_taratasy(20);
	printf("\e[34m   ________________________________________________________\n");
	printf(" / \\                                                        \\.\n");
	printf("|  |         \e[31;1m _^_                            _^_\e[34m            |.\n");
	printf(" \\-|        \e[31;1m (___)==========================(___)\e[34m           |.\n");	
	printf("   |         \e[31;1m |_|     \e[31;1;5m      %s     \e[0m\e[31;1m    |_|\e[34m            |.\n", mametraka_alavana(Teny[61], 9));
	printf("   |         \e[31;1m(___)==========================(___)\e[34m           |.\n");
	printf("   |                                                        |.\n");
	printf("   |                                                        |.\n");
	printf("   |          \e[33m***********************************\e[34m           |.\n");
	printf("   |          \e[33m[1]=)======> %s <======(=[1]\e[34m           |.\n", mametraka_alavana(Teny[62], 10));
	printf("   |          \e[33m***********************************\e[34m           |.\n");
	printf("   |                                                        |.\n");
	printf("   |          \e[33m***********************************\e[34m           |.\n");
	printf("   |          \e[33m[2]=)======> %s <======(=[2]\e[34m           |.\n", mametraka_alavana(Teny[63], 10));
	printf("   |          \e[33m***********************************\e[34m           |.\n");
	printf("   |                                                        |.\n");
	printf("   |          \e[33m***********************************\e[34m           |.\n");
	printf("   |          \e[33m[3]=)======> %s <======(=[3]\e[34m           |.\n", mametraka_alavana(Teny[64], 10));
	printf("   |          \e[33m***********************************\e[34m           |.\n");
	printf("   |                                                        |.\n");
	printf("   |          \e[33m***********************************\e[34m           |.\n");
	printf("   |          \e[33m[4]=)======> %s <======(=[4]\e[34m           |.\n", mametraka_alavana(Teny[13], 10));
	printf("   |          \e[33m***********************************\e[34m           |.\n");
	printf("   |                                                        |.\n");
	printf("   |   _____________________________________________________|____\n");
	printf("   |  /                                                         /.\n");
	printf("   \\-/_________________________________________________________/.\e[0m\n");
	printf("\n\t\e[36m");
	teny_mande_tsikelikely(Teny[6]);    	  	///Fanasiavana ilay fehezanteny mandeha isakin'ny litera 
	printf("\e[0m");
	mandray_teny(mihaotra, 2);
	t = mihaotra[0];
	miakatra_taratasy(20);
	return t;
}

void fiteny(char Teny[100][100], int argc, char *argv[], char *l){      ///Ity ny mahakasina ny resaka fiteny rehetra rehefa alefa ny programa
	
	if(argc == 3){	                                                ///Ity ho an'ny "argument" 
		if (strcmp(argv[2], "1") == 0)
			goto m11;
		else if (strcmp(argv[2], "2") == 0)
			goto m12;
		else if (strcmp(argv[2], "3") == 0)
			goto m13;
	}

    miverina :										
	switch (fandraisan_ao_fiteny(Teny)){
		case '1':                                                  
            m11:
			manova_fiteny("francais");                            //Raha ohatra ka frantsay ny fiteny nosafidiana dia ovaina frantsy ilay fiteny ao amin'ny rakibolana 
            fanavaozana_fiteny(Teny, l);                          //Havaozina ilay teny avy eo 
			break;
		
		case '2':                                                   ///Raha ohatra kosa ka malagasy dia ovaina malagasy sy  havaozina ihany koa 
            m12:											
			manova_fiteny("malagasy");                            
            fanavaozana_fiteny(Teny, l);                          
			break;
	
		case '3':                                                   ///Ohatr'izay ihany koa raha angilisy no nosafidian'ilay olona 
            m13:											
			manova_fiteny("anglais");                             
            fanavaozana_fiteny(Teny, l);                          
			break;

        case '4':                                                  //Ho an'ny safidy miverina 
        break;

		default :
			fampitandremana(Teny);										//Ho an'ireo safidy tsy misy 
			sleep(3);
			system("clear");
            goto miverina;                                          ///dia haverina any amboalohany 
			break;
	}
}
