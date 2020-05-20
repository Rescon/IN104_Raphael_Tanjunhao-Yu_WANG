//
//  ai_choice.h
//  2048
//

#ifndef ai_choice_h
#define ai_choice_h
#include <stdbool.h>

struct search_result{
	int move;
	double score;
	int positions;
	int cutoffs;
};

//Touvez le meilleur choix en fonction de la situation actuelle
char Best_Choice(int** grille);

#endif /* ai_choice_h */