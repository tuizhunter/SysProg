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
	return head;
}


struct node* list_add(struct node* last, struct node* new, struct node* follow){	//Element sortiert einfügen
	if(new==NULL){														//Prüfung ob Liste leer
		if((new =
       		malloc(sizeof(struct node))) == NULL) {
         	fprintf(stderr, "Kein Speicherplatz vorhanden "
                         "fuer anfang\n");}
	}
	//Falls es noch ein weiteres Element in Liste gibt, dann setzte succ auf dieses
	if(follow!=NULL){
		new->succ= follow;
	}
	//Falls es kin weiteres Element in Liste gibt, dann setzte succ auf NULL
	if(follow==NULL){
		new->succ= NULL;
	}
	//Falls es ein Element in Liste vor new gibt, dann setzte las->succ auf new
	if(last!=NULL){
		last->succ=new;
	}
	//gebe das neue Element new zurück
    return new;													
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