#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>


//==================== Functii generale ==============//

char *invers_binar(char *codbinar){

	int i, len;
	char cod_final[9];

	len = strlen( codbinar );

	for ( i = 0; i < len; i++ ){

		cod_final[i] = codbinar[len - i - 1];
	}
	cod_final[len] = '\0';

	return cod_final;
}

char *transforma_binar(int x){

	int i;
	char ch, cod_binar_ch[9];
	char cod_final[9];

	i = 0;
	while (x != 0){

		if (x % 2 == 0){ ch = '0'; }
		else{ ch = '1'; }

		x = x / 2;
		cod_binar_ch[i] = ch;
		i++;

		cod_binar_ch[i] = '\0';
	}
	strcpy( cod_final, invers_binar( cod_binar_ch ) );

	return cod_final;
}

void afisare_binar(char *text){

	int len = strlen(text);

	int i = 0;
	while (i < len){
		
		printf("%c", text[i]);
		if ( (i + 1) % 4 == 0){printf(" ");}
		i++;
	}
	printf("\n"); 
}

void afisare_hexa(char *text){

	int i, len = strlen(text);

	for (i = 0; i < len - 1; i++) { printf("%x ", text[i]); }

	printf("\n");
}

//=================== Cod binar 8 biti ===============//

char *eliminare_terminator_newline(char *text){

	char textbinar[1024];
	int len = strlen(text) - 8;

	strncpy(textbinar, text, len);
	textbinar[len] = '\0';

	return textbinar;
}

char *binar8biti(char *binar){

	char *bin8b = new char;
	char *fill = "00000000";

	int diferenta;
	int len = strlen(binar);

	if (len < 8){

		diferenta = 8 - len;
		strncpy(bin8b, fill, diferenta);
		bin8b[diferenta] = '\0';

		strcat(bin8b, binar);
	}
	return bin8b;
}

void text_cod_binar( char *text, char **textbinar ){

	int i = 1;
	char char_binar[9];
	char char_binar_8biti[9];
	char text_binar[1024];

	char ch = text[0];
	text_binar[0] = '\0';
	while (ch != '\0'){

		strcpy( char_binar, transforma_binar( ch ) );
		strcpy( char_binar_8biti, binar8biti( char_binar ) );

		strcat( text_binar, char_binar_8biti );			   

		ch = text[i];
		i++;
	}
	strcpy(*textbinar, eliminare_terminator_newline( text_binar ) );
}


//======================== Ciclare ===================//

void ciclare_5biti(char *string, char **string_ciclat){

	int len = strlen(string);
	int ciclu = len - 5;
	
	char str[6];
	strcpy( str, string + ciclu);

	strcpy(*string_ciclat, invers_binar(str));

	strncat(*string_ciclat, string, ciclu);
}

void ciclare_7biti(char *string, char **string_ciclat7){

	int len = strlen(string);
	int ciclu = len - 7;

	char str[8];
	strcpy(str, string + ciclu);

	strcpy(*string_ciclat7, invers_binar(str));

	strncat(*string_ciclat7, string, ciclu);
}


//============================== Inversare modulo 3 =============//

void inversare_modulo3(char *text, char **text_modulo){

	int len = strlen(text);
	char ch, transformat[1024];

	strcpy(transformat, text);
	int i = 0;
	while (i < len){
		if ((i + 1) % 3 == 0){
			if (transformat[i] == '1'){ ch = '0'; }
			else{ ch = '1'; }

			transformat[i] = ch;
		}
		i++;
	}
	strcpy(*text_modulo, transformat);
}


//===================================== Functii Permutare parti =============//


void permuta_parti(char *text, char **permutat){

	int lungime = strlen(text);
	int sfert, jumate, treisferturi;

	sfert = lungime / 4;
	jumate = lungime / 2;
	treisferturi = (3 * lungime) / 4;

	char parte1[500];
	char parte2[500];
	char parte3[500];
	char parte4[500];

	strncpy(parte1, text, sfert); 
	parte1[sfert] = '\0';
	
	strncpy(parte2, text + sfert, jumate); 
	parte2[sfert + 1] = '\0';
	
	strncpy(parte3, text + jumate, treisferturi); 
	parte3[sfert + 1] = '\0';
	
	strcpy(parte4, text + treisferturi + 1);

	strcpy(*permutat, parte3);
	strcat(*permutat, parte4);
	strcat(*permutat, parte1);
	strcat(*permutat, parte2);
	(*permutat)[lungime] = '\0';

}

void afisare_binar_permutari(char *text){

	int len = strlen(text);
	int sfert, jumate, treisferturi;

	sfert = len / 4;
	jumate = len / 2;
	treisferturi = (3 * len) / 4;

	int i = 0;
	printf("[");
	while (i < len){

		printf("%c", text[i]);
		if ((i + 1) % 4 == 0){ printf(" "); }
		i++;
		if (i == sfert) printf("][ ");
		if (i == jumate) printf("][ ");
		if (i == treisferturi) printf("][ ");
	}
	printf("]\n");
}


//======================================== Functii XOR intre biti ==========================//

char xor_biti(char x, char y){

	char res;

	if (x == y){ res = '0'; }
	else{ res = '1'; }

	return res;
}

void xor_pe_biti(char *cod, char *cheie, char **cod_criptat){


	int i, j;
	int len = strlen(cod);
	int len_cheie = strlen(cheie);

	j = 0;
	for (i = 0; i < len; i++){
	
		(*cod_criptat)[i] = xor_biti(cod[i], cheie[j]);
		j++;
		if (cheie[j] == '\0') j = 0;
	
	}
	(*cod_criptat)[len] = '\0';
}

//=========================================== Convertire Hexa, Text-ASCII====================//

int puteref(int x, int exp){
		
	int i, rez;
	rez = x;
	if (exp == 0) rez = 1;
	if (exp == 1) rez = x;
	else{
		for (i = 1; i < exp; i++){

			rez = rez*x;
		}
	}
	return rez;
}


void binar_ASCII( char *binar, int **binar_2ASCII){

	int i, j, putere;
	int len = strlen(binar);
	int ch = 0;

	putere = 7;
	j = 0;
	for (i = 0; i < len; i++){

		if (binar[i] == '1'){ ch = ch + puteref(2, putere);	}
		putere--;  
		if ((i + 1) % 8 == 0){

			(*binar_2ASCII)[j] = ch;
			j++;
			putere = 7;
			ch = 0;
		}
	}
	(*binar_2ASCII)[j] = '\0';
}

void afisare_int_ascii(int *vect){

	int i = 0;
	while (vect[i] != '\0'){

		printf("%c", vect[i]);
		i++;
	}
	printf("\n");
}

void afisare_int_hexa(int *vect){

	int i = 0;
	while (vect[i] != '\0'){

		printf("%x ", vect[i]);
		i++;
	}
	printf("\n");
}


void main(){

	//---------------------------------------Citire date de intrare-------------------------//
	char *string;
	string = (char*) malloc( 256 * sizeof( char ) );

	printf("Introduceti un text: ");
	fgets( string, 256, stdin );

	if ( strlen( string ) < 4 ){ // conditia pentru text de minim 4 caractere

		printf("Textul trebuie sa contina minim 4 caractere! \n\n");
		printf("Introduceti un text valid: ");

		fflush( stdin );
		fgets( string, 256, stdin );
	}

	//----------------------------------------- Afisare Text Initial --------------------------//

	system("cls");
	printf("Textul Initial:\n\t %s\n", string);
	printf("Textul format hexa:\n\t");
	afisare_hexa(string);

	//----------------------------------------- Afisare Text Binar ----------------------------//

	char *text_binar;
	text_binar = ( char* ) malloc ( 1024 * sizeof ( char ) );

	text_cod_binar(string, &text_binar);
	printf("\nTextul Binar:\n\t");
	afisare_binar(text_binar);

	//------------------------------- Afisare Text Ciclat dreapta 5 biti ----------------------//

	char *text_binar_ciclat5;
	text_binar_ciclat5 = (char*)malloc(1024 * sizeof (char));

	ciclare_5biti(text_binar, &text_binar_ciclat5);
	printf("\nTextul Binar Ciclat 5 biti dreapta:\n\t");
	afisare_binar(text_binar_ciclat5);

	//---------------------------------------- Afisare Text Modulo 3 -------------------------//

	char *text_binar_modulo3;
	text_binar_modulo3 = (char*)malloc(1024 * sizeof (char));

	inversare_modulo3(text_binar_ciclat5, &text_binar_modulo3);
	printf("\nTextul Binar cu Bitii pe pozitii modulo 3 inversati:\n\t");
	afisare_binar(text_binar_modulo3);

	//------------------------------- Afisare Text Ciclat dreapta 7 biti ----------------------//

	char *text_binar_ciclat7;
	text_binar_ciclat7 = (char*)malloc(1024 * sizeof (char));

	ciclare_7biti(text_binar_modulo3, &text_binar_ciclat7);
	printf("\nTextul Binar Ciclat 7 biti dreapta:\n\t");
	afisare_binar_permutari(text_binar_ciclat7);

	//------------------------------- Afisare Text Permutat 3412 ------------------------------//

	char *text_binar_permutat;
	text_binar_permutat = (char*)malloc(1024 * sizeof (char));

	permuta_parti(text_binar_ciclat7, &text_binar_permutat);
	printf("\nTextul Binar permutat 3-4-1-2:\n\t");
	afisare_binar_permutari(text_binar_permutat);

	//------------------------------- Citire si Afisare Cheie----------------------------------//

	char *cheie;
	cheie = (char*)malloc(5 * sizeof (char));

	char *cheie_binar;
	cheie_binar = (char*)malloc(17 * sizeof (char));

	printf("\n\n===============================================================\n");
	printf("Introduceti O cheie de criptare: ");
	fgets(cheie, 256, stdin);

	if (strlen(cheie) != 5){ // conditia pentru cheie de 4 caractere (pe poz 5 se afla terminatorul de sir)

		printf("Cheia tretuie sa fie de 4 caractere! \n\n");
		printf("Introduceti o cheie Valida: ");

		fflush(stdin);
		fgets(cheie, 256, stdin);
	}
	printf("==================================================\n");
	printf("Cheia in format TXT:\n\t %s\n", cheie);
	printf("Cheia in format hexa:\n\t");
	afisare_hexa(cheie);

	text_cod_binar(cheie, &cheie_binar);
	printf("\nEchivalent binar pe 8 biti:\n\t");
	afisare_binar(cheie_binar);

	//------------------------------- Afisare Cod Criptat----------------------------------//
	
	char *cod_criptat;
	cod_criptat = (char*)malloc(1024 * sizeof (char));

	xor_pe_biti(text_binar_permutat, cheie_binar, &cod_criptat);
	printf("\nCod Criptat varianta finala pe 8 biti:\n\t");
	afisare_binar(cod_criptat);

	//------------------------------- Afisare Cod HEXA + TEXT----------------------------------//

	int *cod_criptat_hexa;
	cod_criptat_hexa = (int*)malloc(256 * sizeof(int));

	binar_ASCII(cod_criptat, &cod_criptat_hexa);
	printf("\nCod Criptat varianta finala pe 8 biti(HEXA):\n\t");
	afisare_int_hexa(cod_criptat_hexa);

	printf("\nMESAJUL CRIPTAT VA FI: \n\t");
	afisare_int_ascii(cod_criptat_hexa);

	_getch();
}
