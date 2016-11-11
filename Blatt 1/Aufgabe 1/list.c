#include "list.h"
#include "ownstring.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct node* list_init(struct node* head, char* vorname, char* nachname){	//Liste starten
	if(head==NULL){														//Prüfung ob Liste leer
		if((head =
       		malloc(sizeof(struct node))) == NULL) {
         	fprintf(stderr, "Kein Speicherplatz vorhanden "
                         "fuer anfang\n");}
		head->vorname = vorname;
		head->nachname = nachname;
		head->succ = NULL;
		return head;
	}
	else{
		struct node* give = head;
	list_add(give, vorname, nachname);
	return head;}				//falls nicht leer rufe add-Funktion
}


struct node* list_add(struct node* head, char* vorname, char* nachname){	//Element sortiert einfügen
	if(alphabet(head, vorname, nachname)==1){							//Überprüfe ob erstes ELement
		struct node *newhead;
		if(( newhead =
       		malloc(sizeof(struct node))) == NULL) {
         	fprintf(stderr, "Kein Speicherplatz vorhanden fuer neues Element\n");}
		newhead->vorname=vorname;
		newhead->nachname=nachname;
		newhead->succ=head;
		return newhead;													//gebe neuen Kopf zurück
	}
	struct node *zeiger = head;											//Traversiere Liste und prüfe Einfügestelle
	zeiger = zeiger->succ;
	while(alphabet(zeiger, vorname, nachname)== 0){
		zeiger = zeiger->succ;
	}
	struct node *new;													//lege neue Node an für Element
	if(( new =
       		malloc(sizeof(struct node))) == NULL) {
         	fprintf(stderr, "Kein Speicherplatz vorhanden fuer neues Element\n");
    }
    new->vorname=vorname;
    new->nachname=nachname;
    new->succ=NULL;
    zeiger->succ=new;
    return head;														//gebe alten Kopf zurück
}

void list_print(struct node* head){										//gebe Liste aus
	struct node* zeiger = head;
	while(zeiger->succ!=NULL){
		printf("%s ", zeiger->vorname);
		printf("%s ", zeiger->nachname);
		zeiger=zeiger->succ;
	}
}


void list_remove(struct node* head){									//Auflösen der Liste
	struct node* zeiger = head->succ;
	struct node* follow =zeiger->succ;
	while(follow!=NULL){
		free(zeiger);
		zeiger=follow;
		follow=follow->succ;
	}
	free(zeiger);
	free(head);
}