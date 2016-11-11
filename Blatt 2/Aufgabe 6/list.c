#include "list.h"
#include "ownstring.h"
#include <stdlib.h>
#include <stdio.h>

struct node* list_init(struct node* head){	//Liste starten
	if(head==NULL){														//Prüfung ob Liste leer
		if((head =
       		malloc(sizeof(struct node))) == NULL) {
         	fprintf(stderr, "Kein Speicherplatz vorhanden "
                         "fuer anfang\n");}
	}
}


struct node* list_add(struct node* last, struct node* follow){	//Element sortiert einfügen
	if(last==NULL){														//Prüfung ob Liste leer
		if((last =
       		malloc(sizeof(struct node))) == NULL) {
         	fprintf(stderr, "Kein Speicherplatz vorhanden "
                         "fuer anfang\n");}
	}
	last->succ= follow;
    return last;														//gebe alten Kopf zurück
}

void list_print(struct node* head){										//gebe Liste aus
	struct node* zeiger = head;
	while(zeiger->succ!=NULL){
		printf("%s ", zeiger->vorname);
		printf("%s ", zeiger->nachname);
		printf("%s ", zeiger->geburt);
		printf("%s ", zeiger->wohnort);
		zeiger=zeiger->succ;
	}
}


void list_remove(struct node* head){									//Auflösen der Liste
	struct node* zeiger = head->succ;
	struct node* follow =zeiger->succ;
	while(follow!=NULL){
		free(zeiger->vorname);
		free(zeiger->nachname);
		free(zeiger->geburt);
		free(zeiger->wohnort);
		free(zeiger);
		zeiger=follow;
		follow=follow->succ;
	}
	free(zeiger->vorname);
	free(zeiger->nachname);
	free(zeiger->geburt);
	free(zeiger->wohnort);
	free(zeiger);
	free(head);
}