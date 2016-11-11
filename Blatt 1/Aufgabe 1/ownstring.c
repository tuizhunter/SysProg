#include "ownstring.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>




int alphabet(struct node* test, char* vorname, char* nachname){	//Namen sollen aus Datei eingelesen werden
	int x=0;
	char a =test->nachname[0];
	char b =nachname[0];
	int i=0;
	int k =0;
	while(a!='\0'){									//Bestimme Länge Nachname neu
		i++;
		a=test->nachname[i];
	}
	int j=0;
	while(b!='\0'){									//Bestimme Länge des Nachnamens in aktueller Node
		j++;
		b=nachname[j];
	}
	if(i<j){													//Teste bis zu welchem Zeichen Namen gleich, falls node.nachname kürzer
		while(nachname[k]==test->nachname[k] && k<=i){
			k++;
		}
	}
	if(j<=i){													//Teste bis zu welchem Namen gleich, falls nachname kürzer
		while(nachname[k]==test->nachname[k] && k<=j){
			k++;
		}
		
	}

	if((j-i)!=0){												//Falls Namen bis zu letztem Zeichen des Kürzeren gleich, gib Kürzeren als true zurück

		if(k==i){
			x = 0;
			return x;
		}

		if(k==j){
			x = 1;
			return x;
		}
		if(nachname[k]<test->nachname[k]){					//Return true für nachname vor node.nachname
		x = 1;
		return x;
		}

		if(nachname[k]>test->nachname[k]){					//false otherwise
			x = 0;
			return x;
		}
	}

	if(j==i && k==i){										//Nachnamen gleich lang und inhaltsgleich		
		i = 0;
		j = 0;
		a = test->vorname[0];
		b = vorname[0];
		while(a!='\0'){									//Bestimme Länge Vornamen neu
		i++;
		a=test->vorname[i];
		}
		int j=0;
		while(b!='\0'){									//Bestimme Länge des Vornamens in aktueller Node
			j++;
			b=vorname[j];
		}
		if(i<j){													//Teste bis zu welchem Zeichen Namen gleich, falls node.vorname kürzer
			int k =0;
			while(vorname[k]==test->vorname[k] && k<=i){
				k++;
			}
		}
		if(j<=i){													//Teste bis zu welchem Namen gleich, falls vorname kürzer
			while(vorname[k]==test->vorname[k] && k<=j){
				k++;
			}
			
		}

		if(vorname[k]<test->vorname[k]){					//Return true für vorname vor node.vorname
		x = 1;
		return x;
		}

		if(vorname[k]>test->vorname[k]){					//false otherwise
			x = 0;
			return x;
		}

	}

	if(nachname[k]<test->nachname[k]){				//Return true für nachname vor node.nachname
		x = 1;
		return x;
	}

	if(nachname[k]>test->nachname[k]){			//false otherwise
		x = 0;
		return x;
	}
	return x;
}

char* read(int *z){
	printf("Bitte geben Sie den Datenpfad des Textfiles ein\n");
	char filename[999];
	fgets(filename, 998, stdin);
	FILE *namefile = fopen(filename, "r");	
	//FILE *namefile = fopen("/home/marcel/Schreibtisch/Blatt1/test", "r");	
	if(namefile==NULL){							//Fehler beim Öffnen des Files
		perror("Error opening file\n");
	}
	int ch;
	int charcount =0;
	char a = ' ';
	char b = '\n';
	while((ch=getc(namefile)) !=EOF){		//Zähle character im File
		charcount+=charcount;				
		putchar(ch);						//Gebe Zeichen auf Konsole aus
	}
	char* personen;
	char* buffer = (char*)malloc(sizeof(char)*charcount+1);
	fgets(buffer, sizeof(char)*charcount, namefile);
	personen = (char*) malloc(sizeof(char)*charcount+1);
	int i;
	for(i=0; i<=sizeof(sizeof(char)*charcount+1); i++){
		if(buffer[i]!=a && buffer[i]!=b){
			personen[i]=buffer[i];
		}
		if(buffer[i]==a){
			personen[i]='#';			//Vor- und Nachnamen durch # trennen

		}
		if(buffer[i]==b){						//Namen zweiter Personen durch ( trennen
			personen[i]='(';

		}
	}
	*z = charcount;
	free(buffer);
	return personen;
}
