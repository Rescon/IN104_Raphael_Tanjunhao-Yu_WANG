//
//  ai_choice.c
//  2048
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "evalue.h"
#include "ai_choice.h"
#include "grille.h"
#include "move.h"
#include "appear.h"
#include "check.h"

#define MinSearchTime (100000)

//Alpha-bêta profondeur première recherche
struct search_result Search(int** grille, int depth, double alpha, double beta, int positions, int cutoffs, bool player_turn){
	double bestScore;
	int bestMove = -1;
	struct search_result result;
	int i;
	bool valid;

	if(player_turn){
		bestScore = alpha;
		for(i = 0;i < 4;i++){
			int** test = Copy_Grille(grille);

			switch(i){
				case 0: valid = Move_Up(test); break;
				case 1: valid = Move_Left(test); break;
				case 2: valid = Move_Down(test); break;
				case 3: valid = Move_Right(test); break;
			}

			if(valid){
				positions++;
				if(Result_Game(test) == win){
					result.move = i;
					result.score = 10000;
					result.positions = positions;
					result.cutoffs = cutoffs;
					Free_Grille(test);
					return result;
				}

				if(depth == 0){
					result.move = i;
					result.score = Evalue(test);
					Free_Grille(test);
					return result;
				}else{
					int** search = Copy_Grille(test);
					result = Search(search, depth-1, bestScore, beta, positions, cutoffs, false);
					if (result.score > 9900) {
					    result.score--;
					}
					Free_Grille(search);
        			positions = result.positions;
        			cutoffs = result.cutoffs;
				}

				if (result.score > bestScore){
        			bestScore = result.score;
        			bestMove = i;
        		}

        		if (bestScore > beta) {
          			cutoffs++;
					result.move = bestMove;
					result.score = beta;
					result.positions = positions;
					result.cutoffs = cutoffs;
					Free_Grille(test);
					return result;
          		}else{
          			Free_Grille(test);
          		}
			}else{
				Free_Grille(test);
			}
		}
	}else{
		//Tour de l'ordinateur, nous ferons une taille lourde pour garder le facteur de branchement bas
		bestScore = beta;
		struct position *position_empty = Find_Empty_Position(grille);
		int num = Count_Empty(grille);
		double scores[2][num];
		int i,j;
		double min_scores;

		//Essayez 2 et 4 dans chaque cellule et mesurez à quel point c'est ennuyeux
		for(i = 0;i < 2;i++){
			for(j = 0;j < num;j++){
				int** test = Copy_Grille(grille);
				test[position_empty[j].x][position_empty[j].y] = 2*(i+1);
				scores[i][j] = Smooth(test) - Islands(test);

				if((i == 0 && j == 0) || min_scores > scores[i][j]){
					min_scores = scores[i][j];
				}

				Free_Grille(test);
			}
		}


		for(i = 0;i < 2;i++){
			for(j = 0;j < num;j++){
				//Il suffit de choisir les mouvements les plus ennuyeux et de rechercher chaque candidat
				if(scores[i][j] == min_scores){
					int** search = Copy_Grille(grille);
					search[position_empty[j].x][position_empty[j].y] = 2*(i+1);
					result = Search(search, depth, alpha, bestScore, positions, cutoffs, true);
					Free_Grille(search);
        			positions = result.positions;
        			cutoffs = result.cutoffs;

					if (result.score < bestScore){
        				bestScore = result.score;
        			}
        			
        			if (bestScore < alpha){
          				cutoffs++;
						result.move = -1;
						result.score = alpha;
						result.positions = positions;
						result.cutoffs = cutoffs;
						return result;
          			}
				}
			}
		}

		free(position_empty);
	}

	result.move = bestMove;
	result.score = bestScore;
	return result;
}

//Touvez le meilleur choix en fonction de la situation actuelle
char Best_Choice(int** grille){
	char operation;
	struct search_result result, new_result;
	int** test = Copy_Grille(grille);
	int depth = 0;
	clock_t start, finish;

	//effectue un approfondissement itératif sur la recherche alpha-bêta
	start = clock();
	do{
		new_result = Search(test, depth, -10000, 10000, 0, 0, true);
		if(new_result.move == -1){
			break;
		}else{
			result = new_result;
		}
		depth++;
		finish = clock();
	}
	while(((double)(finish - start)) < MinSearchTime);
	Free_Grille(test);
	
	switch(result.move){
		case 0: operation = 'w'; break;
		case 1: operation = 'a'; break;
		case 2: operation = 's'; break;
		case 3: operation = 'd'; break;
	}
	return operation;
}
