#include "ownstring.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>


int geburtstag(struct node* head, char** kriterien, int decidek, int* offset, int ist){
	int x;
	char* geb = kriterien[decidek]+offset[2];
	struct node* zeiger = head;
	//jahrtausend
	if(geb[4]>zeiger->geburt[4]){
		x=0;
	}
	//jahrundert
	if(geb[4]==zeiger->geburt[4]){
		if(geb[5]>zeiger->geburt[5]){
			x= 0;
		}
	}
	//dekade
	if(geb[4]==zeiger->geburt[4]){
		if(geb[5]==zeiger->geburt[5]){
			if(geb[6]>zeiger->geburt[6]){
				x= 0;
			}
		}
	}
	//jahr
	if(geb[4]==zeiger->geburt[4]){
		if(geb[5]==zeiger->geburt[5]){
			if(geb[6]==zeiger->geburt[6]){
				if(geb[7]>zeiger->geburt[7]){
					x= 0;
				}
			}
		}
	}
	
	//monat-zehn
	if(geb[4]==zeiger->geburt[4]){
		if(geb[5]==zeiger->geburt[5]){
			if(geb[6]==zeiger->geburt[6]){
				if(geb[7]==zeiger->geburt[7]){
					if(geb[2]>zeiger->geburt[2]){
						x= 0;
					}
				}
			}
		}
	}
	
	//monat-eins
	if(geb[4]==zeiger->geburt[4]){
		if(geb[5]==zeiger->geburt[5]){
			if(geb[6]==zeiger->geburt[6]){
				if(geb[7]==zeiger->geburt[7]){
					if(geb[2]==zeiger->geburt[2]){
						if(geb[3]>zeiger->geburt[3]){
							x= 0;
						}
					}
				}
			}
		}
	}
	//tag-zehn
	if(geb[4]==zeiger->geburt[4]){
		if(geb[5]==zeiger->geburt[5]){
			if(geb[6]==zeiger->geburt[6]){
				if(geb[7]==zeiger->geburt[7]){
					if(geb[2]==zeiger->geburt[2]){
						if(geb[3]==zeiger->geburt[3]){
							if(geb[0]>zeiger->geburt[0]){
								x= 0;
							}
						}
					}
				}
			}
		}
	}
	//tag-eins
	if(geb[4]==zeiger->geburt[4]){
		if(geb[5]==zeiger->geburt[5]){
			if(geb[6]==zeiger->geburt[6]){
				if(geb[7]==zeiger->geburt[7]){
					if(geb[2]==zeiger->geburt[2]){
						if(geb[3]==zeiger->geburt[3]){
							if(geb[0]==zeiger->geburt[0]){
								if(geb[1]>zeiger->geburt[1]){
									x= 0;
								}
							}
						}
					}
				}
			}
		}
	}
	if(geb[4]==zeiger->geburt[4]&& ist>=0){
		if(geb[5]==zeiger->geburt[5]){
			if(geb[6]==zeiger->geburt[6]){
				if(geb[7]==zeiger->geburt[7]){
					if(geb[2]==zeiger->geburt[2]){
						if(geb[3]==zeiger->geburt[3]){
							if(geb[0]==zeiger->geburt[0]){
								if(geb[1]==zeiger->geburt[1]){
									x= wohnort(head, kriterien, decidek, offset, -1);
								}
							}
						}
					}
				}
			}
		}
	}
	//falls alle Klauses übersprungen werden
	else {
		x= 1;

	}
	return x;
}
int wohnort(struct node* head, char** kriterien, int decidek, int* offset, int ist){
	char* wohnort= kriterien[decidek+1]+offset[3];
	int x=0;
	char a =head->wohnort[0];
	char b =wohnort[0];
	int i=0;
	int k =0;
	struct node* test = head;
	while(a!='#'||a!='\0'){									//Bestimme Länge Wohnort in aktueller Node neu
		i++;
		a=test->wohnort[i];
	}
	int j=0;
	while(b!='\0'||b!='#'){									//Bestimme Länge des Wohnorts in Array;
		j++;
		b=wohnort[j];
	}
	if(i<j){													//Teste bis zu welchem Zeichen wohnort gleich, falls node.wohnort kürzer
		while(wohnort[k]==test->wohnort[k] && k<=i){
			k++;
		}
	}
	if(j<=i){													//Teste bis zu welchem wohnort gleich, falls wohnort kürzer
		while(wohnort[k]==test->wohnort[k] && k<=j){
			k++;
		}
		
	}

	if((j-i)!=0){												//Falls wohnort bis zu letztem Zeichen des Kürzeren gleich, gib Kürzeren als true zurück

		if(k==i){
			x = 0;
		}

		if(k==j){
			x = 1;
			
		}
		if(wohnort[k]<test->wohnort[k]){					//Return true für wohnort vor node.wohnort
		x = 1;
		}

		if(wohnort[k]>test->wohnort[k]){					//false otherwise
			x = 0;
		}
	}

	if(j==i && k==i && ist>0){										//Nachnamen gleich lang und inhaltsgleich		
		x= geburtstag(head, kriterien, decidek, offset, -2);
	}

	else {x=1;};

	return x;
}

int alphabet(struct node* head, char** kriterien, int decidek, int* offset, int ist){	//Namen sollen aus Datei eingelesen werden
	char* nachname= kriterien[decidek]+offset[1];
	char* vorname= kriterien[decidek-1]+offset[0];
	int x=0;
	struct node* test = head;
	char a =test->nachname[0];
	char b =nachname[0];
	int i=0;
	int k =0;
	while(a!='#' && a!='\0'){									//Bestimme Länge Nachname in Node neu
		i++;
		a=test->nachname[i];
	}
	int j=0;
	while(b!='\0'&&b!='#'){									//Bestimme Länge des Nachnamens in Array
		j++;
		b=nachname[j];
	}
	int m = 0;
	int n = 0;
	int c = test->vorname[0];
	int d = vorname[0];
	while(c!='\0' && c!='#'){									//Bestimme Länge der Node.Vornamen neu
		c=test->vorname[m];
		m++;
	}
	while(d!='\0'&& d!='#'){									//Bestimme Länge des Vornamens in Array
		d=vorname[n];
		n++;
	}
	offset[0]+=n+1;
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
		}

		if(k==j){
			x = 1;
		}

		}
		if(nachname[k]<test->nachname[k]){					//Return true für nachname vor node.nachname
			x = 1;
		}

		if(nachname[k]>test->nachname[k]){					//false otherwise
			x = 0;
		}


	if(j==i && k==i){										//Nachnamen gleich lang und inhaltsgleich		
		int k =0;
		if(m<n){													//Teste bis zu welchem Zeichen Namen gleich, falls node.vorname kürzer
			while(vorname[k]==test->vorname[k] && k<=m){
				k++;
			}
		}
		if(n<=m){													//Teste bis zu welchem Namen gleich, falls vorname kürzer
			while(vorname[k]==test->vorname[k] && k<=n){
				k++;
			}
			
		}

		if(vorname[k]<test->vorname[k]){					//Return true für vorname vor node.vorname
			x = 1;
		}

		if(vorname[k]>test->vorname[k]){					//false otherwise
			x = 0;
		}

	}

	if(nachname[k]<test->nachname[k]){				//Return true für nachname vor node.nachname
		x = 1;
	}

	if(nachname[k]>test->nachname[k]){			//false otherwise
		x = 0;
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
	char b = '\0';
	while((ch=getc(namefile)) !=EOF){		//Zähle character im File
		charcount+=charcount;				
		putchar(ch);						//Gebe Zeichen auf Konsole aus
	}
	char* personen;
	charcount = charcount +1;
	char* buffer = (char*)malloc(sizeof(char)*charcount);
	fgets(buffer, sizeof(char)*charcount, namefile);
	personen = (char*) malloc(sizeof(char)*charcount);
	charcount = charcount -1;
	int i;
	int check=0;
	int j=0;
	for(i=0; i<=charcount+1; i++){
		if(buffer[i]!=a && buffer[i]!=b){
			personen[j]=buffer[i];
		}
		if((buffer[i]==a ||buffer[i]==b) &&check==0){
			personen[j]='#';
			check++;			//Vor- und Nachnamen durch # trennen

		}
		if((buffer[i]==a ||buffer[i]==b) &&check==1){
			personen[j]='#';
			check++;			//Vor- und Nachnamen durch # trennen

		}
		if((buffer[i]==a ||buffer[i]==b) &&check==2){
			j=i-1;
			check++;			//Geburtstag keine Trennung
		}
		if((buffer[i]==a ||buffer[i]==b) &&check==3){
			j=i-1;
			check++;			//Geburtstag keine Trennung
		}
		if((buffer[i]==a ||buffer[i]==b) &&check==4){
			j=i-1;
			check++;			//Geburtstag keine Trennung
		}
		if((buffer[i]==a ||buffer[i]==b) &&check==2){
			personen[j]='#';
			check=0;			//Wohnort
		}


	}
	*z = j;
	free(buffer);
	fclose(namefile);
	return personen;
}

struct node* zuweisen(int (*sortFunction[])(struct node*, char**, int, int*, int),struct node* head, char** kriterien, int decidek, int* offset, int ist, int decidef){
		struct node* test=NULL;
	if(head==NULL){
		test = list_init(test);
		test->vorname = kriterien[0]+offset[0];
		test->nachname = kriterien[1]+offset[1];
		test->geburt = kriterien[2]+offset[2];
		test->wohnort = kriterien[3]+offset[3];
		test->succ = NULL;
		head = test;
	}
	//Testen, ob einfügen zu Beginn der Liste
	else{
		//Werte zwischenspeichern, da nach sort-Funktion der Offset bereits angepasst wurde
		char* vorname = kriterien[0]+offset[0];
		char* nachname = kriterien[1]+offset[1];
		char* geburt = kriterien[2]+offset[2];
		char* wohnort = kriterien[3]+offset[3];
		if(sortFunction[decidef](head, kriterien, decidek, offset, ist)== 1){
			struct node *newhead = NULL;
			newhead = list_add(newhead, head);
			newhead->vorname=vorname;
			newhead->nachname=nachname;
			newhead->geburt=geburt;
			newhead->wohnort=wohnort;
			newhead->succ=head;
			//passe offsets an
			int z=0;
			char w = nachname[0];
			while(w!='\0'&& w!='#'){									
				w= nachname[z];
				z++;
			}
			offset[1] = offset[1]+z+1;
			z=0;
			w = wohnort[0];
			while(w!='\0'&& w!='#'){									
				w= wohnort[z];
				z++;
			}
			offset[3] = offset[3]+z+1;
			w = vorname[0];
			z =0;
			while(w!='\0'&& w!='#'){									
				w= vorname[z];
				z++;
			}
			offset[0] = offset[0]+z+1;
			offset[2]=offset[2]+7;

			head = newhead;

		}

		struct node *zeiger = head;
		zeiger=zeiger->succ;
		struct node *point = head;										//Traversiere Liste und prüfe Einfügestelle
		while(sortFunction[decidef](head, kriterien, decidek, offset, ist)== 0 && zeiger!=NULL){
			zeiger = zeiger->succ;
			point = point->succ;
		}
		//füge neues Elemement in Mitten der Liste ein
		if(zeiger!=NULL){
			struct node *newel = NULL;
			newel = list_add(point, newel);
			newel->vorname=kriterien[0]+offset[0];
			newel->nachname=nachname;
			newel->geburt=geburt;
			newel->wohnort=wohnort;
			newel->succ=zeiger;
			//passe offsets an
			int z=0;
			char w = nachname[0];
			while(w!='\0'&& w!='#'){									
				w= nachname[z];
				z++;
			}
			offset[1] = offset[1]+z+1;
			z=0;
			w = wohnort[0];
			while(w!='\0'&& w!='#'){									
				w= wohnort[z];
				z++;
			}
			offset[3] = offset[3]+z+1;
			w = vorname[0];
			z =0;
			while(w!='\0'&& w!='#'){									
				w= vorname[z];
				z++;
			}
			offset[0] = offset[0]+z+1;
			offset[2]=offset[2]+7;


													//gebe neuen Kopf zurück
		}

		//füge neues Element am Ende der Liste ein
		if(zeiger==NULL){
			struct node *newel = NULL;
			newel = list_add(point, newel);
			newel->vorname=kriterien[0]+offset[0];
			newel->nachname=nachname;
			newel->geburt=geburt;
			newel->wohnort=wohnort;
			newel->succ=NULL;
			//passe offsets an
			int z=0;
			char w = nachname[0];
			while(w!='\0'&& w!='#'){									
				w= nachname[z];
				z++;
			}
			offset[1] = offset[1]+z+1;
			z=0;
			w = wohnort[0];
			while(w!='\0'&& w!='#'){									
				w= wohnort[z];
				z++;
			}
			offset[3] = offset[3]+z+1;
			w = vorname[0];
			z =0;
			while(w!='\0'&& w!='#'){									
				w= vorname[z];
				z++;
			}
			offset[0] = offset[0]+z+1;
			offset[2]=offset[2]+7;


														//gebe neuen Kopf zurück
		}
	}
	return head;
}
