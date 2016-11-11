#include "brett.h"
#include <stdio.h>
#include <stdlib.h>



int init_brett(struct t_brett *b, int n, int x, int y){
		int i;
		int j;
		   /* Matrix ist Zeiger auf int-Zeiger. */
		int** matrix;
		/*if((b =
       		malloc(sizeof(struct t_brett))) == NULL) {
         	fprintf(stderr, "Kein Speicherplatz vorhanden "
                         "fuer anfang\n");
       		return EXIT_FAILURE;
      	}*/


		   /* Speicher reservieren für die int-Zeiger (=zeile) */
		matrix = (int **) malloc(n * sizeof(int *));
		if(NULL == matrix) {
		    printf("Kein virtueller RAM mehr vorhanden ... !");
		    return EXIT_FAILURE;
		}
		/* jetzt noch Speicher reservieren für die einzelnen Spalten
		* der i-ten Zeile */
		for(i = 0; i < n; i++) {
			matrix[i] = (int*) malloc(n * sizeof(int));
		    if(NULL == matrix[i]) {
		        printf("Kein Speicher mehr fuer Zeile %d\n",i);
		        return EXIT_FAILURE;
		    }
		}

		for (i = 0; i < n; i++){
      		for (j = 0; j < n; j++){
        		matrix[i][j] = 0;
        	}
        }	     /* matrix[zeile][spalte] */

		b->brett = matrix;
		b->x = x;
		b->y = y;
		b->n = n;
		b->brett[x][y]=1;
		b->zug = 1;
		//b.besuch 1;
	return 0;
}

int neuer_sprung(struct t_brett *b, int x, int y){
	int i = b->x + x;
	int j = b->y + y;
	//falls Züge nicht über Brett hinausgehen, führe Zug aus und setze alle Variablen i struct auf neue Werte
	if(i<b->n && j<b->n){
		b->zug++;
		b->brett[i][j] = b->zug;
		b->x = i;
		b->y = j;
		//b.besuch++;
		return 1;
	}
	else {return EXIT_FAILURE;}
}

int entferne_sprung(struct t_brett *b, int x, int y){
	int i = b->x - x;
	int j = b->y - y;
	if(i<0 || j<0 || i>=b->n || j>=b->n){
		return EXIT_FAILURE;
	}
	//falls rücknahme nicht über Brett hinausgeht, setze Werte im Struct wieder zurück
	else {
		b->zug--;
		b->brett[b->x][b->y] = 0;
		b->x = i;
		b->y = j;
		//b.besuch--;
		return 1;
	}
}

int frei(struct t_brett *b, int x, int y){
	//wie oben bei den Tests
	int i = b->x + x;
	int j = b->y + y;
	if(i<0 || j<0 || i>=b->n || j>=b->n ||b->brett[i][j]!=0 ){
		return 0;
	}
	//falls noch 0 im Feld steht, dann ist Feld noch nicht besucht
	/*if(b->brett[i][j]==0){
		return 1;
	}*/
	else return 1;

}

int besuchte_felder(struct t_brett *b){
	return b->zug;
}

void loesche_brett(struct t_brett *b){


	/* Spalten der i-ten Zeile freigeben */
   for(int i = 0; i < b->n; i++){
      	free(b->brett[i]);
   }
   /* Leere Zeilen freigegeben */
   	free(b->brett);
   	//free(b); 


}

void print(struct t_brett *b){
	//erstelle Muster des Brettes
	printf("+");
	for (int i = 0; i < b->n; i++) {
		//erstelle Trennlininen zwischen den Zeilen
		for(int c=0; c<b->n; c++){
		printf("---+");
		}
		printf("\n+");
		//gebe Zahlen in den Feldern aus
      	for (int j = 0; j < b->n; j++){
         printf("%3i + ",b->brett[i][j]);
      	}
	}	
}