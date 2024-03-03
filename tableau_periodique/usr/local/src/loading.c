/****************************************************************************************************************
 * 																												*
 *   		Mpanoratra : Sanda , Njiva, Andry, Christon															*	
 * 																												*
 * 			Mombamomba : Tableau périodique (tapany fanaovana ilay 'hello' amin'ny fiatombohany programa 		*
 * 																												*
 * 			Daty nahavitana azy : 19 Avril 2023																	*
 * 																												*
 ***************************************************************************************************************/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include "exploiter.h"

void fanombohana_variabla(char variabla_miasa[9][37]){					//Fanombohana ilay variabla
	for(int j=0; j < 9; j++){
		for(int i=1; i<36 ; i++){										///Atao elanelana daholo ireo ao anatin'ny varaibale (varaibla_miasa[i][j]=' ')
			variabla_miasa[j][i]=32;
		}
		variabla_miasa[j][0]='*';							///Afatsy ny fiatombohany isaky ny makika voalohany (i=0)
		variabla_miasa[j][36]='\0';							//Faranana amin'y litera 'NULL' ireo teny rehetra ireo
	}
	variabla_miasa[0][1]='*';
	variabla_miasa[8][1]='*';
}

void fanehoana(char variabla_miasa[9][37]){					///Fanehoana ilay ao anatin'ny variable_miasa (dans la dimension)
	for (int j=0; j<9 ; j++){
		printf("\t\t\t\t%s", variabla_miasa[j]);
		putchar('\n');
	}
}

void fanajanonana_famafana(long t){  						///Fanajanonana amin'ny segondra voateny sy famafana tanteraka
	usleep(t);												//Fotoana anajanonana azy
    system("clear");										//Avy eo dia fafana ilay izy 
}

void fanovana_tsikelikely(char variabla_miasa[9][37]){			///Fanehoana ilay teny tsikelikely
	for (int i=0, l=0; i < 37 ; i++, l++){
		
		printf("\n\n\n\n\e[38;2;0;255;0m");						//Fanasiana loko ilay teny iray manontolo
        fanehoana(variabla_miasa);								//Fanehoana azy
        fanajanonana_famafana(30000);							//Fanajanonana azy amin'ny ampahana segondra
        for(int k=1; k<8; k++){
			variabla_miasa[k][l+1]=32;
			variabla_miasa[k][l+2]='*';
			variabla_miasa[0][l+2]='*';
			variabla_miasa[8][l+2]='*';
		}
		if (i == 3 || i == 7 || i == 9 || i == 14 || i == 20 || i == 26 || i == 30){
			for (int l=2; l<7 ; l++){								//Ho an'ny tsipika mitsangana rehetra dia ity no fanaovana azy 
				variabla_miasa[l][i]='*';
			}
		}
		if ((i > 3 && i < 7) || (i > 9 && i < 11)){
			variabla_miasa[4][i]='*';								//Ho an'ny tsipika mitsivalana rehetra kosa dia ity (ampovoany)
		}
		if ((i > 9 && i < 13) || (i > 25 && i < 31)){				//Ilay tsipika mitsivalana ambony sy ambany
			variabla_miasa[2][i]='*';
			variabla_miasa[6][i]='*';
		}
		if ((i >  14 && i < 19) || ((i > 19 && i < 25))){			//Ity kosa ny mitsivanana ambany fotsiny
			variabla_miasa[6][i]='*';										
		}
		if (i == 31){                                             	//Miala ao anatin'ilay fiverimberenana raha toa ka hazo ilay fetrany
			break;
		}
    }
}

void fanamboarana_mipipika(char variabla_miasa[9][37]){							///Mba hanaovana endrika mipipika ireo izay hivelan'ny ilay teny
	for (int a=0; a<30; a++){
		printf("\n\n\n\n\e[38;2;0;255;0m");					//fanovana ny lokon'ilay teny rehetra sy ny sisiny
		fanehoana(variabla_miasa);							//fanehoana ilay teny isaky ny manova eo ambany 
		fanajanonana_famafana(100000);						//Fanajanonana fotoana vitsy ilay izy 
		if((a%2) == 0){										///Mizara ho roa ny fampisehoana ampisehoana aloha izay rehetra mipetraka eo amin'ny isa '"pair" rehetra 
			for (int i=0; i < 33; i++){					
				if (i%2 == 0){								//Hoa an'ny tsipika mitsangana voalohany sy ilay farany  ka tsy mampiseho ireo '*'		
					variabla_miasa[0][i]=32;
					variabla_miasa[8][i]=32;
				}
				if (i%2 != 0){								//Ity kosa ho an'ireo mampiseho
					variabla_miasa[0][i]='*';
					variabla_miasa[8][i]='*';
				}
			}	
			for (int j=0; j<9 ; j++){						//Ho an'ny tsipika mitsivalana ambony sy ambany  dia mitovy amin'io ambony io ihany (izay aseo sy ny tsy )
				if(j%2 != 0 ){
					variabla_miasa[j][0]=32;
					variabla_miasa[j][33]=32;
				}
				if(j%2 == 0 ){					
					variabla_miasa[j][0]='*';
					variabla_miasa[j][33]='*';
				}
			}	
			
		}
		if((a%2) != 0){										///ny faharohany kosa dia afamadika fotsiny ireo tsy aseho sy aseho teo ambony 
			for (int i=0; i < 33; i++){
				if (i%2 != 0){								//Eto aohatra dia izay  'impaire' amin'ny tsipika mitsangana indray no aseho 
					variabla_miasa[0][i]=32;
					variabla_miasa[8][i]=32;
				}	
				if (i%2 == 0){								//dia ny ambiny ajanona 
					variabla_miasa[0][i]='*';
					variabla_miasa[8][i]='*';
				}
			}
			for (int j=0; j<9 ; j++){						//(ohatra ilay teo ambony ihany...)
				if(j%2 == 0){
					variabla_miasa[j][0]=32;
					variabla_miasa[j][33]=32;
				}
				if(j%2 != 0 ){								
					variabla_miasa[j][0]='*';
					variabla_miasa[j][33]='*';
				}
			}
		}
	}
}

void fampisehona_tanteraka(char variabla_miasa[9][37]){						///Amin'ny farany dia aseho tsy mipipika intsony ilay izy 
	for(int i=0; i < 34; i++){						//famerenana ireo tsipika mitsangana ho misy '*' daholo
		variabla_miasa[0][i]='*';			
		variabla_miasa[8][i]='*';
	}
	for(int i=0; i < 9; i++){						//(Mitovy amin'io ambony io fa ilay tsipika mitsivalana indray)
		variabla_miasa[i][0]='*';
		variabla_miasa[i][33]='*';
	}
}

void hello(){
    char variabla_miasa[9][37];
    fanombohana_variabla(variabla_miasa);                               ///Atomboka amin'ny fanaovana efajoro ny litera '*' ny variabla 
    
    fanovana_tsikelikely(variabla_miasa);								///Asehontsika tsikelikely ilay soratra hoe 'HELLO'
    fanamboarana_mipipika(variabla_miasa);								///Atao mipipika ilay litera '*' eny amin'ny sisin'ny 'HELLO'
    fampisehona_tanteraka(variabla_miasa);								///Ajanona ilay mipipika 
}
