/************************************************************************************
 * 																					*
 *   		Manoratra : Sanda , Njiva, Andry, Christon								*
 * 																					*
 * 			Mombamomba azy: Tableau périodique (Ivon'ilay kaody)					*
 * 																					*
 * 			Daty nahavitana azy : 27 Aprily 2023									*
 * 																					*
 ***********************************************************************************/

///Fanamarihana:
    /********************************************************************************************************
     *                                                                                                      *
     *   Ny variabla "mots" dia misy ireo dikan-teny rehetra ao anatin'ny programa rehetra , ohatra : ireo  *
     *   lohateny rehetra .... Izy io dia afaka ovaina ao amin'ny alalan'ny "fichier language.txt" raha     *
     *   ohatra ka sendra misy diso na anampy ny ao.                                                        * 
     *                                                                                                      *
     *******************************************************************************************************/


#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "loading.h"						//Contien le chargement "HELLO"
#include "exploiter.h"						//Contien les fonctions utiles dans le menu : exploitation , aide , ...	
#include "jeu.h"						//Contien tous les fonction concernant le petit jeu 
#include "data.h"							//Contien tous les données des atomes
#include "langue.h"

int main(int argc, char *argv[]){
	int fihalana=1;
	char anarana_atoma[118][30];			//Ho an'ny anaran'ilay singa tsirairay
	char marika_atoma[118][5];				//Ho an'ny marika ny tsirairay ao amin'ny singa
	char mahakasika_atoma[118][100];		//Ho an'ny mombamomba tsirairay ny atomad
	int laharana_atomika[118];				//Ho an'ny laharana an'isa-tsiga 
	float lanja_atomika[118];				//Ho an'ny lanja an'ny atoma tsirairay
	char dika_teny[100][100];				//Hametrahana iseo dikateny amin'ny teny samihafa
	char fahasarotana[10];						//Ho an'ny fahasarotan'ny kilalao ato
	int isa_atoma_kilalao=20;								//Ho an'ny isany atoma atao ao anatin'ilay kilalao , dia atomboka amin'ny atoma 20 (fahasarotana = mora)
	char Fiteny[100]; 						//Hampantarana ilay teny ampiasaina

	hello();											//Mampadefa ilay soratra mipipika hoe "HELLO" amin'ny fanomboan'ilay programa
	data(anarana_atoma, marika_atoma, mahakasika_atoma, laharana_atomika, lanja_atomika);				//Mba hakana ireo mombamomba ny atoma tsirairay
	fanavaozana_fiteny(dika_teny, Fiteny);									//Fakana ireo diakan-teny rehetra ho an'ny varibla "mots"

	if(argc == 2 || argc == 3){									//Mijery raha sendra misy "argument""
		if(strcmp(argv[1],"1") == 0)					//Raha misy "argument" ka '1', dia tonga dia makao amin'ny voalohany ny safidy 
			goto m1;
		else if(strcmp(argv[1],"2") == 0)				//Raha misy "argument" ka '2', dia tonga dia makao amin'ny faharoa ny safidy 
			goto m2;
		else if(strcmp(argv[1],"3") == 0)				//Raha misy "argument" ka '3', dia tonga dia makao amin'ny fahatelo ny safidy 
			goto m3;
		else if(strcmp(argv[1],"4") == 0)				//Raha misy "argument" ka '4', dia tonga dia makao amin'ny fahaefatra ny safidy 
			goto m4;
		else{
			teny_mande_tsikelikely("\e[31mTsy misy io \"argument\" io!!!\n\e[0m");
			sleep(3);
		}
	}	
	else if(argc > 3){								//Raha ohatra ka mihoatra ny "argument" ampidirina 
		teny_mande_tsikelikely("\033[32mMihoatra ny \"argument\" ampidirinao!!!\n\033[0m");
		sleep(3);
	}
	
	while(fihalana){
		switch (Fandraisana_voalohany(dika_teny)){
			case 1:
			/********************************************************************************
			 *   Ity tapany ity dia natokana ho an'ny fijerena sy fianarana ireo atoma.		*
			 ********************************************************************************/
				m1:
					fitadiavana_anarana_atoma(anarana_atoma, marika_atoma, mahakasika_atoma, laharana_atomika, lanja_atomika, dika_teny, argv, argc);
				break;
			
			case 2:
			/************************************************************************************************
			 *   Ity tapany fahoroa ity dia natokana hanaovana an'ilay kilalao ao anatin'y programa.		*
			 ************************************************************************************************/
				m2:
					lalao(anarana_atoma, marika_atoma, mahakasika_atoma, laharana_atomika, lanja_atomika, dika_teny, fahasarotana, argv, argc, &isa_atoma_kilalao);
				break;
			
			case 3:
			/************************************************************************************************
			 *   Ity tapany fahatelo ity dia natao ho an'ny fanovana fiteny ao amin'ny ilay programa.		*
			 ************************************************************************************************/
				m3:
					fiteny(dika_teny, argc, argv, Fiteny);
				break;
			
			case 4:
			/**************************************************************************************** 
			 *   Ity kosa dia hanomezana fanazavana mombamomba an'ilay programa.					*
			 ****************************************************************************************/
				m4:
				fampisehoana_fanampiana(Fiteny, dika_teny);
				break;

			case 5:
				fihalana=0;							//Mba hialana tanteraka ao anatin'ilay programa
				break;
			
			default :
				fampitandremana(dika_teny);				//Hitenenana raha mampiditra zavatra hafa akotrany safidy misy ilay olona
				sleep(3);
				system("clear");
				break;
		}
	}

	return 0;
}
