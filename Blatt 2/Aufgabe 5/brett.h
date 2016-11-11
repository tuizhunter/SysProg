#ifndef BRETT_H_   /* Include guard */
#define BRETT_H_


struct t_brett {
	int** brett;
	int x;
	int y;
	int n;
	int zug;
	int besuch;
};

	int init_brett(struct t_brett *b, int n, int x, int y);
	int neuer_sprung (struct t_brett *b, int x, int y);
	int entferne_sprung(struct t_brett *b, int x, int y);
	int frei(struct t_brett *b, int x, int y);
	int besuchte_felder(struct t_brett *b);
	void loesche_brett(struct t_brett *b);
	void print(struct t_brett *b);
#endif // BRETT_H_