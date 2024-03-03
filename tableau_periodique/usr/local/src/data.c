/************************************************************************************
 * 																					*
 *   		AUTEUR : Sanda , Njiva, Andry, Christon									*	
 * 																					*
 * 			DESCRIPTION : Tableau périodique (Partie données)               		*
 * 																					*
 * 			DATE DE FINISSION : 27 Avril 2023										*
 *																					*
 * 			CONTENANT : Contenant le programme de gestion de données				*
 * 																					*
 ***********************************************************************************/

#include <string.h>

void data(char nom[118][30], char symbole[118][5], char description[118][100], int numero_atomique[118], float masse_atomique[118]){
	strcpy(nom[0],"Hydrogene");
	strcpy(symbole[0],"H");
	strcpy(description[0],"Gazeux et Non-meteaux");
	numero_atomique[0]=1;
	masse_atomique[0]=1.008000;
	
	strcpy(nom[1],"Helium");
	strcpy(symbole[1],"He");
	strcpy(description[1],"Gazeux et Gaz rares");
	numero_atomique[1]=2;
	masse_atomique[1]=4.003000;
	
	strcpy(nom[2],"Lithium");
	strcpy(symbole[2],"Li");
	strcpy(description[2],"Solide et Metaux alcalins");
	numero_atomique[2]=3;
	masse_atomique[2]=6.940000;
	
	strcpy(nom[3],"Beryllium");
	strcpy(symbole[3],"Be");
	strcpy(description[3],"Solide et Metaux alcalino-terreux");
	numero_atomique[3]=4;
	masse_atomique[3]=9.012000;
	
	strcpy(nom[4],"Bore");
	strcpy(symbole[4],"B");
	strcpy(description[4],"Solide et Metalloides");
	numero_atomique[4]=5;
	masse_atomique[4]=10.810000;
	
	strcpy(nom[5],"Carbone");
	strcpy(symbole[5],"C");
	strcpy(description[5],"Solide et Non-metaux");
	numero_atomique[5]=6;
	masse_atomique[5]=12.010000;
	
	strcpy(nom[6],"Azote");
	strcpy(symbole[6],"N");
	strcpy(description[6],"Gazeux et Non-metaux");
	numero_atomique[6]=7;
	masse_atomique[6]=14.010000;
	
	strcpy(nom[7],"Oxygene");
	strcpy(symbole[7],"O");
	strcpy(description[7],"Gazeux et non-metaux");
	numero_atomique[7]=8;
	masse_atomique[7]=16.000000;
	
	strcpy(nom[8],"Fluor");
	strcpy(symbole[8],"F");
	strcpy(description[8],"Gazeux et Halogene");
	numero_atomique[8]=9;
	masse_atomique[8]=19.000000;
	
	strcpy(nom[9],"Neon");
	strcpy(symbole[9],"Ne");
	strcpy(description[9],"Gazeux et gaz rares");
	numero_atomique[9]=10;
	masse_atomique[9]=20.180000;
	
	strcpy(nom[10],"Sodium");
	strcpy(symbole[10],"Na");
	strcpy(description[10],"Solide et meteaux alcalins");
	numero_atomique[10]=11;
	masse_atomique[10]=22.990000;
	
	strcpy(nom[11],"Magnesium");
	strcpy(symbole[11],"Mg");
	strcpy(description[11],"Solide et metaux alcalino-terreux");
	numero_atomique[11]=12;
	masse_atomique[11]=24.310000;
	
	strcpy(nom[12],"Aluminium");
	strcpy(symbole[12],"Al");
	strcpy(description[12],"Solide et metaux pauvres");
	numero_atomique[12]=13;
	masse_atomique[12]=26.980000;
	
	strcpy(nom[13],"Silicium");
	strcpy(symbole[13],"Si");
	strcpy(description[13],"Solide et metalloides");
	numero_atomique[13]=14;
	masse_atomique[13]=28.090000;
	
	strcpy(nom[14],"Phosphore");
	strcpy(symbole[14],"P");
	strcpy(description[14],"Solide et Non-metaux");
	numero_atomique[14]=15;
	masse_atomique[14]=30.970000;
	
	strcpy(nom[15],"Soufre");
	strcpy(symbole[15],"S");
	strcpy(description[15],"Solide et Non-metaux");
	numero_atomique[15]=16;
	masse_atomique[15]=32.060000;
	
	strcpy(nom[16],"Chlore");
	strcpy(symbole[16],"Cl");
	strcpy(description[16],"Gazeux et halogenes");
	numero_atomique[16]=17;
	masse_atomique[16]=35.450000;
	
	strcpy(nom[17],"Argon");
	strcpy(symbole[17],"Ar");
	strcpy(description[17],"Gazeux et gaz rares");
	numero_atomique[17]=18;
	masse_atomique[17]=39.950000;
	
	strcpy(nom[18],"Potassium");
	strcpy(symbole[18],"K");
	strcpy(description[18],"Solide et metaux alcalins");
	numero_atomique[18]=19;
	masse_atomique[18]=39.100000;
	
	strcpy(nom[19],"Calcium");
	strcpy(symbole[19],"Ca");
	strcpy(description[19],"Solide et metaux alcalino-terreux");
	numero_atomique[19]=20;
	masse_atomique[19]=40.080000;
	
	strcpy(nom[20],"Scandium");
	strcpy(symbole[20],"Sc");
	strcpy(description[20],"Solide et metaux de transition");
	numero_atomique[20]=21;
	masse_atomique[20]=44.960000;
	
	strcpy(nom[21],"Titane");
	strcpy(symbole[21],"Ti");
	strcpy(description[21],"Solide et metaux de transition");
	numero_atomique[21]=22;
	masse_atomique[21]=47.870000;
	
	strcpy(nom[22],"Vanadium");
	strcpy(symbole[22],"V");
	strcpy(description[22],"Solide et metaux de transition");
	numero_atomique[22]=23;
	masse_atomique[22]=50.940000;
	
	strcpy(nom[23],"Chrome");
	strcpy(symbole[23],"Cr");
	strcpy(description[23],"Solide et metaux de transition");
	numero_atomique[23]=24;
	masse_atomique[23]=52.000000;
	
	strcpy(nom[24],"Manganese");
	strcpy(symbole[24],"Mn");
	strcpy(description[24],"Solide et metaux de transition");
	numero_atomique[24]=25;
	masse_atomique[24]=54.940000;
	
	strcpy(nom[25],"Fer");
	strcpy(symbole[25],"Fe");
	strcpy(description[25],"Solide et metaux de transition");
	numero_atomique[25]=26;
	masse_atomique[25]=55.850000;
	
	strcpy(nom[26],"Cobalt");
	strcpy(symbole[26],"Co");
	strcpy(description[26],"Solide et metaux de transition");
	numero_atomique[26]=27;
	masse_atomique[26]=58.930000;
	
	strcpy(nom[27],"Nickel");
	strcpy(symbole[27],"Ni");
	strcpy(description[27],"Solide et metaux de transition");
	numero_atomique[27]=28;
	masse_atomique[27]=58.690000;
	
	strcpy(nom[28],"Cuivre");
	strcpy(symbole[28],"Cu");
	strcpy(description[28],"Solide et metaux de transition");
	numero_atomique[28]=29;
	masse_atomique[28]=63.550000;
	
	strcpy(nom[29],"Zinc");
	strcpy(symbole[29],"Zn");
	strcpy(description[29],"Solide et metaux de transition");
	numero_atomique[29]=30;
	masse_atomique[29]=65.390000;
	
	strcpy(nom[30],"Gallium");
	strcpy(symbole[30],"Ga");
	strcpy(description[30],"Solide et metaux pauvres");
	numero_atomique[30]=31;
	masse_atomique[30]=69.720000;
	
	strcpy(nom[31],"Germanium");
	strcpy(symbole[31],"Ge");
	strcpy(description[31],"Solide et metalloides");
	numero_atomique[31]=32;
	masse_atomique[31]=72.630000;
	
	strcpy(nom[32],"Arsenic");
	strcpy(symbole[32],"As");
	strcpy(description[32],"Solide et metalloides");
	numero_atomique[32]=33;
	masse_atomique[32]=74.920000;
	
	strcpy(nom[33],"Selenium");
	strcpy(symbole[33],"Se");
	strcpy(description[33],"Solide et Non-metaux");
	numero_atomique[33]=34;
	masse_atomique[33]=78.960000;
	
	strcpy(nom[34],"Brome");
	strcpy(symbole[34],"Br");
	strcpy(description[34],"Liquide et Halogenes");
	numero_atomique[34]=35;
	masse_atomique[34]=79.900000;
	
	strcpy(nom[35],"Krypton");
	strcpy(symbole[35],"Kr");
	strcpy(description[35],"Gazeux et  gaz rares");
	numero_atomique[35]=36;
	masse_atomique[35]=83.800000;
	
	strcpy(nom[36],"Rubidium");
	strcpy(symbole[36],"Rb");
	strcpy(description[36],"Solide et metaux alcalins");
	numero_atomique[36]=37;
	masse_atomique[36]=85.470000;
	
	strcpy(nom[37],"Strontium");
	strcpy(symbole[37],"Sr");
	strcpy(description[37],"Solide et metaux alcalino-terreux");
	numero_atomique[37]=38;
	masse_atomique[37]=87.620000;
	
	strcpy(nom[38],"Yttrium");
	strcpy(symbole[38],"Y");
	strcpy(description[38],"Solide et metaux de transition");
	numero_atomique[38]=39;
	masse_atomique[38]=88.910000;
	
	strcpy(nom[39],"Zirconium");
	strcpy(symbole[39],"Zr");
	strcpy(description[39],"Solide et metaux de transition");
	numero_atomique[39]=40;
	masse_atomique[39]=91.220000;
	
	strcpy(nom[40],"Niobium");
	strcpy(symbole[40],"Nb");
	strcpy(description[40],"Solide et metaux de transition");
	numero_atomique[40]=41;
	masse_atomique[40]=92.910000;
	
	strcpy(nom[41],"Molybdene");
	strcpy(symbole[41],"Mo");
	strcpy(description[41],"Solide et metaux de transition");
	numero_atomique[41]=42;
	masse_atomique[41]=95.960000;
	
	strcpy(nom[42],"Technetium");
	strcpy(symbole[42],"Tc");
	strcpy(description[42],"Solide et metaux de transition");
	numero_atomique[42]=43;
	masse_atomique[42]=98.000000;
	
	strcpy(nom[43],"Ruthenium");
	strcpy(symbole[43],"Ru");
	strcpy(description[43],"Solide et metaux de transition");
	numero_atomique[43]=44;
	masse_atomique[43]=101.070000;
	
	strcpy(nom[44],"Rhodium");
	strcpy(symbole[44],"Rh");
	strcpy(description[44],"Solide et metaux de transition");
	numero_atomique[44]=45;
	masse_atomique[44]=102.910000;
	
	strcpy(nom[45],"Palladium");
	strcpy(symbole[45],"Pd");
	strcpy(description[45],"Solide et metaux de transition");
	numero_atomique[45]=46;
	masse_atomique[45]=106.420000;
	
	strcpy(nom[46],"Argent");
	strcpy(symbole[46],"Ag");
	strcpy(description[46],"Solide et metaux de transition");
	numero_atomique[46]=47;
	masse_atomique[46]=107.870000;
	
	strcpy(nom[47],"Cadmium");
	strcpy(symbole[47],"Cd");
	strcpy(description[47],"Solide et metaux de transition");
	numero_atomique[47]=48;
	masse_atomique[47]=112.410000;
	
	strcpy(nom[48],"Indium");
	strcpy(symbole[48],"In");
	strcpy(description[48],"Solide et metaux pauvres");
	numero_atomique[48]=49;
	masse_atomique[48]=114.820000;
	
	strcpy(nom[49],"Etain");
	strcpy(symbole[49],"Sn");
	strcpy(description[49],"Solide et metaux pauvres");
	numero_atomique[49]=50;
	masse_atomique[49]=118.710000;
	
	strcpy(nom[50],"Antimoine");
	strcpy(symbole[50],"Sb");
	strcpy(description[50],"Solide et metalloides");
	numero_atomique[50]=51;
	masse_atomique[50]=121.760000;

	strcpy(nom[51],"Tellure");
	strcpy(symbole[51],"Te");
	strcpy(description[51],"Solide et metalloides");
	numero_atomique[51]=52;
	masse_atomique[51]=127.600000;

	strcpy(nom[52],"Iode");
	strcpy(symbole[52],"I");
	strcpy(description[52],"Solide et halogenes");
	numero_atomique[52]=53;
	masse_atomique[52]=126.900000;

	strcpy(nom[53],"Xenon");
	strcpy(symbole[53],"Xe");
	strcpy(description[53],"Gazeux et fait parties des gaz rares");
	numero_atomique[53]=54;
	masse_atomique[53]=131.290000;

	strcpy(nom[54],"Cesium");
	strcpy(symbole[54],"Cs");
	strcpy(description[54],"solide et fait partie des metaux alcalins");
	numero_atomique[54]=55;
	masse_atomique[54]=132.900000;

	strcpy(nom[55],"Baryum");
	strcpy(symbole[55],"Ba");
	strcpy(description[55],"solide et fait partie des metaux alcalino-terreux");
	numero_atomique[55]=56;
	masse_atomique[55]=137.340000;

	strcpy(nom[56],"Lanthane");
	strcpy(symbole[56],"La");
	strcpy(description[56],"Solide et lanthanides");
	numero_atomique[56]=57;
	masse_atomique[56]=138.910000;

	strcpy(nom[57],"Cerium");
	strcpy(symbole[57],"Ce");
	strcpy(description[57],"Solide et lanthanides");
	numero_atomique[57]=58;
	masse_atomique[57]=140.120000;

	strcpy(nom[58],"Praseodyme");
	strcpy(symbole[58],"Pr");
	strcpy(description[58],"Solide et lanthanides");
	numero_atomique[58]=59;
	masse_atomique[58]=140.910000;

	strcpy(nom[59],"Neodyme");
	strcpy(symbole[59],"Nd");
	strcpy(description[59],"Solide et lanthanides");
	numero_atomique[59]=60;
	masse_atomique[59]=144.240000;

	strcpy(nom[60],"Prometheum");
	strcpy(symbole[60],"Pm");
	strcpy(description[60],"Solide et lanthanides");
	numero_atomique[60]=61;
	masse_atomique[60]=145.000000;

	strcpy(nom[61],"Samarium");
	strcpy(symbole[61],"Sm");
	strcpy(description[61],"Solide et lanthanides");
	numero_atomique[61]=62;
	masse_atomique[61]=150.360000;

	strcpy(nom[62],"Europium");
	strcpy(symbole[62],"Eu");
	strcpy(description[62],"Solide et lanthanides");
	numero_atomique[62]=63;
	masse_atomique[62]=151.960000;

	strcpy(nom[63],"Gadolinium");
	strcpy(symbole[63],"Gd");
	strcpy(description[63],"Solide et lanthanides");
	numero_atomique[63]=64;
	masse_atomique[63]=157.250000;

	strcpy(nom[64],"Terbium");
	strcpy(symbole[64],"Tb");
	strcpy(description[64],"Solide et lanthanides");
	numero_atomique[64]=65;
	masse_atomique[64]=158.920000;

	strcpy(nom[65],"Dysprosium");
	strcpy(symbole[65],"Dy");
	strcpy(description[65],"Solide et lanthanides");
	numero_atomique[65]=66;
	masse_atomique[65]=162.500000;

	strcpy(nom[66],"Holmium");
	strcpy(symbole[66],"Ho");
	strcpy(description[66],"Solide et lanthanides");
	numero_atomique[66]=67;
	masse_atomique[66]=164.930000;

	strcpy(nom[67],"Erbium");
	strcpy(symbole[67],"Er");
	strcpy(description[67],"Solide et lanthanides");
	numero_atomique[67]=68;
	masse_atomique[67]=167.260000;

	strcpy(nom[68],"Thulium");
	strcpy(symbole[68],"Tm");
	strcpy(description[68],"Solide et lanthanides");
	numero_atomique[68]=69;
	masse_atomique[68]=168.930000;

	strcpy(nom[69],"Ytterbium");
	strcpy(symbole[69],"Yb");
	strcpy(description[69],"Solide et anthanides");
	numero_atomique[69]=70;
	masse_atomique[69]=173.040000;

	strcpy(nom[70],"Lutecium");
	strcpy(symbole[70],"Lu");
	strcpy(description[70],"Solide et lanthanides");
	numero_atomique[70]=71;
	masse_atomique[70]=174.970000;

	strcpy(nom[71],"Hafnium");
	strcpy(symbole[71],"Hf");
	strcpy(description[71],"Solide et fait parties des metaux de transitions");
	numero_atomique[71]=72;
	masse_atomique[71]=178.490000;

	strcpy(nom[72],"Tantale");
	strcpy(symbole[72],"Ta");
	strcpy(description[72],"Solide et fait parties des metaux de transitions");
	numero_atomique[72]=73;
	masse_atomique[72]=180.950000;

	strcpy(nom[73],"Tungstene");
	strcpy(symbole[73],"W");
	strcpy(description[73],"Solide et fait parties des metaux de transitions");
	numero_atomique[73]=74;
	masse_atomique[73]=180.950000;

	strcpy(nom[74],"Rhenium");
	strcpy(symbole[74],"Re");
	strcpy(description[74],"Solide et fait parties des metaux de transitions");
	numero_atomique[74]=75;
	masse_atomique[74]=186.210000;

	strcpy(nom[75],"Osmium");
	strcpy(symbole[75],"Os");
	strcpy(description[75],"Solide et fait parties des metaux de transitions");
	numero_atomique[75]=76;
	masse_atomique[75]=190.230000;

	strcpy(nom[76],"Iridium");
	strcpy(symbole[76],"Ir");
	strcpy(description[76],"Solide et fait parties des metaux de transitions");
	numero_atomique[76]=77;
	masse_atomique[76]=192.220000;

	strcpy(nom[77],"Platine");
	strcpy(symbole[77],"Pt");
	strcpy(description[77],"Solide et fait parties des metaux de transitions");
	numero_atomique[77]=78;
	masse_atomique[77]=195.090000;

	strcpy(nom[78],"Or");
	strcpy(symbole[78],"Au");
	strcpy(description[78],"Solide et fait parties des metaux de transitions");
	numero_atomique[78]=79;
	masse_atomique[78]=196.970000;

	strcpy(nom[79],"Mercure");
	strcpy(symbole[79],"Hg");
	strcpy(description[79],"Liquide et fait parties des metaux de transitions");
	numero_atomique[79]=80;
	masse_atomique[79]=200.590000;

	strcpy(nom[80],"Thalium");
	strcpy(symbole[80],"Ti");
	strcpy(description[80],"Solide et fait parties des metaux pauvres");
	numero_atomique[80]=81;
	masse_atomique[80]=204.380000;

	strcpy(nom[81],"Plomb");
	strcpy(symbole[81],"Pb");
	strcpy(description[81],"Solide et fait parties des metaux pauvres");
	numero_atomique[81]=82;
	masse_atomique[81]=207.190000;

	strcpy(nom[82],"Bismuth");
	strcpy(symbole[82],"Bi");
	strcpy(description[82],"Solide et fait parties des metaux pauvres");
	numero_atomique[82]=83;
	masse_atomique[82]=208.980000;

	strcpy(nom[83],"Polonium");
	strcpy(symbole[83],"Po");
	strcpy(description[83],"Solide et fait parties des metaux pauvres");
	numero_atomique[83]=84;
	masse_atomique[83]=209.000000;

	strcpy(nom[84],"Astate");
	strcpy(symbole[84],"At");
	strcpy(description[84],"Solide et halogenes");
	numero_atomique[84]=85;
	masse_atomique[84]=210.000000;

	strcpy(nom[85],"Radon");
	strcpy(symbole[85],"Rn");
	strcpy(description[85],"Solide et fait partie des gaz rares");
	numero_atomique[85]=86;
	masse_atomique[85]=222.00000;

	strcpy(nom[86],"Francium");
	strcpy(symbole[86],"Fr");
	strcpy(description[86],"Solide et fait partie des metaux alcalins");
	numero_atomique[86]=87;
	masse_atomique[86]=223.0000;

	strcpy(nom[87],"Radium");
	strcpy(symbole[87],"Ra");
	strcpy(description[87],"Solide et fait partie des metaux alcalino-terreux");
	numero_atomique[87]=88;
	masse_atomique[87]=226.00000;

	strcpy(nom[88],"Actinium");
	strcpy(symbole[88],"Ac");
	strcpy(description[88],"Solide et actinides");
	numero_atomique[88]=89;
	masse_atomique[88]=227.000000;

	strcpy(nom[89],"Thorium");
	strcpy(symbole[89],"Th");
	strcpy(description[89],"Solide et actinides");
	numero_atomique[89]=90;
	masse_atomique[89]=232.040000;

	strcpy(nom[90],"Protactinium");
	strcpy(symbole[90],"Pa");
	strcpy(description[90],"Solide et actinides");
	numero_atomique[90]=91;
	masse_atomique[90]=231.040000;

	strcpy(nom[91],"Uranium");
	strcpy(symbole[91],"U");
	strcpy(description[91],"Solide et actinides");
	numero_atomique[91]=92;
	masse_atomique[91]=238.040000;

	strcpy(nom[92],"Neptunium");
	strcpy(symbole[92],"Np");
	strcpy(description[92],"Solide et actinides");
	numero_atomique[92]=93;
	masse_atomique[92]=237.000000;

	strcpy(nom[93],"Plutonium");
	strcpy(symbole[93],"Pu");
	strcpy(description[93],"Solide et actinides");
	numero_atomique[93]=94;
	masse_atomique[93]=244.060000;

	strcpy(nom[94],"Americium");
	strcpy(symbole[94],"Am");
	strcpy(description[94],"Solide et actinides");
	numero_atomique[94]=95;
	masse_atomique[94]=243.000000;

	strcpy(nom[95],"Curium");
	strcpy(symbole[95],"Cm");
	strcpy(description[95],"Solide et actinides");
	numero_atomique[95]=96;
	masse_atomique[95]=247.0000;

	strcpy(nom[96],"Berkelium");
	strcpy(symbole[96],"Bk");
	strcpy(description[96],"Solide et actinides");
	numero_atomique[96]=97;
	masse_atomique[96]=247.000000;

	strcpy(nom[97],"Californium");
	strcpy(symbole[97],"Cf");
	strcpy(description[97],"Solide et actinides");
	numero_atomique[97]=98;
	masse_atomique[97]=251.000000;

	strcpy(nom[98],"Einsteinium");
	strcpy(symbole[98],"Es");
	strcpy(description[98],"Solide et actinides");
	numero_atomique[98]=99;
	masse_atomique[98]=252.000000;

	strcpy(nom[99],"Fermium");
	strcpy(symbole[99],"Fm");
	strcpy(description[99],"Solide et actinides");
	numero_atomique[99]=100;
	masse_atomique[99]=257.000000;

	strcpy(nom[100],"Mendelevium");
	strcpy(symbole[100],"Md");
	strcpy(description[100],"Solide et actinides");
	numero_atomique[100]=101;
	masse_atomique[100]=258.000000;

	strcpy(nom[101],"Nobelium");
	strcpy(symbole[101],"No");
	strcpy(description[101],"Solide et actinides");
	numero_atomique[101]=102;
	masse_atomique[101]=259.000000;

	strcpy(nom[102],"Lawrencium");
	strcpy(symbole[102],"Lr");
	strcpy(description[102],"Solide et actinides");
	numero_atomique[102]=103;
	masse_atomique[102]=262.00000;

	strcpy(nom[103],"Rutherfordium");
	strcpy(symbole[103],"Rf");
	strcpy(description[103],"Solide et inconnu");
	numero_atomique[103]=104;
	masse_atomique[103]=267.000000;

	strcpy(nom[104],"Dubnium");
	strcpy(symbole[104],"Db");
	strcpy(description[104],"Solide et inconnu");
	numero_atomique[104]=105;
	masse_atomique[104]=268.000000;

	strcpy(nom[105],"Seaborgium");
	strcpy(symbole[105],"Sg");
	strcpy(description[105],"Solide et inconnu");
	numero_atomique[105]=106;
	masse_atomique[105]=271.000000;

	strcpy(nom[106],"Bohrium");
	strcpy(symbole[106],"Bh");
	strcpy(description[106],"Solide et inconnu");
	numero_atomique[106]=107;
	masse_atomique[106]=272.000000;

	strcpy(nom[107],"Hassium");
	strcpy(symbole[107],"Hs");
	strcpy(description[107],"Solide et inconnu");
	numero_atomique[107]=108;
	masse_atomique[107]=270.000000;

	strcpy(nom[108],"Meitnerium");
	strcpy(symbole[108],"Mt");
	strcpy(description[108],"Solide et inconnu");
	numero_atomique[108]=109;
	masse_atomique[108]=276.000000;

	strcpy(nom[109],"Darmstadium");
	strcpy(symbole[109],"Ds");
	strcpy(description[109],"Solide et inconnu");
	numero_atomique[109]=110;
	masse_atomique[109]=281.000000;

	strcpy(nom[110],"Roentgenium");
	strcpy(symbole[110],"Rg");
	strcpy(description[110],"Solide et inconnu");
	numero_atomique[110]=111;
	masse_atomique[110]=280.000000;

	strcpy(nom[111],"Copernicium");
	strcpy(symbole[111],"Cn");
	strcpy(description[111],"Solide et inconnu");
	numero_atomique[111]=112;
	masse_atomique[111]=285.000000;

	strcpy(nom[112],"Ununtrium");
	strcpy(symbole[112],"Uut");
	strcpy(description[112],"Metaux pauvres et inconnu");
	numero_atomique[112]=113;
	masse_atomique[112]=284.000000;

	strcpy(nom[113],"Flevorium");
	strcpy(symbole[113],"Fl");
	strcpy(description[113],"Metaux pauvres et inconnu");
	numero_atomique[113]=114;
	masse_atomique[113]=289.00000;

	strcpy(nom[114],"Ununpentium");
	strcpy(symbole[114],"Uup");
	strcpy(description[114],"Metaux pauvres et inconnu");
	numero_atomique[114]=115;
	masse_atomique[114]=288.000000;

	strcpy(nom[115],"Livermorium");
	strcpy(symbole[115],"Lv");
	strcpy(description[115],"Metaux pauvres et inconnu");
	numero_atomique[115]=116;
	masse_atomique[115]=293.000000;

	strcpy(nom[116],"Ununseptium");
	strcpy(symbole[116],"Uus");
	strcpy(description[116],"Metaux pauvres et inconnu");
	numero_atomique[116]=117;
	masse_atomique[116]=294.000000;

	strcpy(nom[117],"Ununoctium");
	strcpy(symbole[117],"Uuo");
	strcpy(description[117],"Gaz rares et inconnu");
	numero_atomique[117]=118;
	masse_atomique[117]=294.000000;
}
