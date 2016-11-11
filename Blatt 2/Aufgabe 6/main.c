#include "ownstring.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>


/*struct node {
struct node *succ;
char *vorname;
char *nachname;
};*/




int main(){
	printf("Hello, let's begin\n");
	int k =0;
	char* personen = read(&k);	//File lesen
	struct node *head = NULL;	// Head deklarieren
	k++;
	int c=0;
	int merke1=0;
	char** kriterien= (char**) malloc(sizeof(char*)*4);
	int laenge[4] = {0,0,0,0}; //1. Nachname, 2. Vorname, 3.Geburt, 4. Wohnen
	int check = 0;
	int decidef;
	int offset[4] = {0,0,0,0};
//Array über Sortierungsfunktionen erstellen
	int (*sortierung[]) (struct node*, char**, int, int*, int) = {alphabet, geburtstag, wohnort};
//finde die Länge der einzelnen Abschnitte heraus
	for(int i=0; i<=k;i++){
		
		if(personen[i]=='#' && check==0){
			laenge[0]=laenge[0]+i-merke1;
			merke1= i;
			check++;
		}
		if(personen[i]=='#' && check==1){
			laenge[1]=laenge[1]+i-merke1;
			merke1= i;
			check++;
		}
		if(personen[i]=='#' && check==2){
			laenge[2]=laenge[2]+i-merke1;
			merke1= i;
			check++;
		}
		if(personen[i]=='#' && check==3){
			laenge[3]=laenge[3]+i-merke1;
			merke1= i;
			check =0;
		}
	}
	//weiße den einzenlnen Abschnitten Länge zu
	for(int z=0; z<4; z++){
		if(z==0){
			kriterien[z]= (char*) malloc (sizeof(char) * (laenge[z]+1));
		}
		else{
			kriterien[z]= (char*) malloc (sizeof(char) * laenge[z]);
		}
	}
	check=0;
	int w=0;
	int a=0;
	int b=0;
	c=0;
	int d=0;
	int hashv=0;
	int hashn=0;
	int hashw=0;
	int hashg=0;
	//schreibe die einzelnen Daten durch Hasch getrennt in Array
	while(w<=k){

		while(personen[w]!='#' && check==0){
		kriterien[0][a]=personen[w];
		a++;
		w++;
		}

		if(personen[w]=='#' &&check==0){
			kriterien[0][a]=personen[w];
			a++;
			w++;
			check++;
			hashv++;
		}

		while(personen[w]!='#' && check==1){
		kriterien[1][b]=personen[w];
		w++;
		b++;
		}
		if(personen[w]=='#' &&check==1){
			kriterien[1][b]=personen[w];
			w++;
			c++;
			check++;
			hashn++;
		}
		while(personen[w]!='#' && check==2){
		kriterien[2][c]=personen[w];
		w++;
		b++;
		}
		if(personen[w]=='#' &&check==2){
			kriterien[2][c]=personen[w];
			w++;
			c++;
			check++;
			hashg++;
		}
		while(personen[w]!='#' && check==3){
			kriterien[3][d]=personen[w];
			w++;
			d++;
		}
		if(personen[w]=='#' && check==3){
			kriterien[3][d]=personen[w];
			w++;
			d++;
			check=0;
			hashw++;
		}
		//füge hinter letzten Namen noch Hash hinzu
		if((personen[w]=='\0' && check==3)){
			kriterien[3][d]='#';
			w++;
			d++;
			check=0;
			hashw++;
		}
//jetzt sind alle Kriterien Namenweise durch Hash getrennt in Arrays enthalten


	}
	printf("Geben Sie an, welches Kriterium Sie wählen möchten: 1 = Alphabetisch/Nachnamen, 2 = Geburtsdaten, 3 = Wohnorte\n");
	scanf("%d", &decidef);
	decidef--;
	int ist = 1;
	//Ordne alle Namen in Liste ein
	for(int l=0; l<hashn; l++){
		head = zuweisen((sortierung),head, kriterien, decidef, offset, ist, decidef);
	}

	list_print(head);										//Drucke Liste
	list_remove(head);									//Lösche gesamte Liste
	free(personen);
	for(int y=0; y<4; y++){
		free(kriterien[y]);
	}
	free(kriterien);
	return 1;

}