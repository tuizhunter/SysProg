#include "ownstring.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


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
	int i =0;
	int j=0;
	int merkei = 0;
	int merkej = 0;
	char a ='#';
	char b = '(';
	char* begin1 = personen;
	char* begin2 = personen;
	int c=0;
	while(c<=k && begin2[j+1]!='\0'){	//alle Vor und Nachnamen in Liste schreiben

		while(i<=k && begin1[i]!=a){	//Länge der Vornamen
			i++;
		}
		j = i+1;											//Setze Startpunkt für Nachname
		merkej = j;											//Merke Startpunkt des Nachnamen
		while(j<=k && begin2[j]!=b && begin2[j]!='\0' &&begin2[j+1]!='\0'){	//Länge der Nachnamen
			j++;
		}
		char vorname[i-merkei];								//Erstelle Array der richtigen Vornamenslänge
		char nachname[j-merkej];							//Erstelle Array der richtigen Nachnamenslänge
		for(int x=0; x<i-merkei; x++){						//Schreibe Vornamen in Array
			vorname[x]=begin1[x];
		}
		for(int z=0; z<j-merkej; z++){						//Schreibe Nachnamen in Array
			nachname[z]=begin2[z];
		}
		struct node* head = NULL;
		list_init(head, &vorname[0], &nachname[0]);		//Füge Namen in Liste ein
		merkei = i;											//Merke neues i
		merkej =j;											//Merke neues j
		i = j+1;											//Setzte Startpunkt für nächste Runde auf richtiges Zeichen

		c++;												//Inkrementiere Notfallabbruchbedigung
	}

	list_print(head);										//Drucke Liste
	list_remove(head);										//Lösche gesamte Liste
	return 1;

}