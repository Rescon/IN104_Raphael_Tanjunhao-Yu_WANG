//
//  evalue.h
//  2048
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "evalue.h"
#include "ai_choice.h"
#include "grille.h"
#include "move.h"
#include "appear.h"
#include "check.h"

#define Weight_Smooth (0.1)
#define Weight_Empty (2.7)
#define Weight_Mono (1.0)
#define Weight_max (1.0)

//Fonction auxiliaire de la fonction Islands
void Mark(int x, int y, int value, int** grille, int** marked){
	if(x >= 0 && x < SIZE && y >= 0 && y < SIZE && grille[x][y] == value && marked[x][y] == 0){
		marked[x][y] = 1;
		Mark(x-1,y,value,grille,marked);
		Mark(x+1,y,value,grille,marked);
		Mark(x,y-1,value,grille,marked);
		Mark(x,y+1,value,grille,marked);
	}
}

//Compte le nombre de groupes isolés.
double Islands(int** grille){
	int** marked = malloc(sizeof(int*) * SIZE);
	double islands = 0;
	int i,j;
	for(i = 0;i < SIZE;i++) marked[i] = (int*)malloc(sizeof(int) * SIZE);
	for(i = 0;i < SIZE;i++){
		for(j = 0;j < SIZE;j++){
			marked[i][j] = 0;
		}
	}

	for(i = 0;i < SIZE;i++){
		for(j = 0;j < SIZE;j++){
			if(grille[i][j] != 0 && marked[i][j] == 0){
				islands++;
				Mark(i,j,grille[i][j],grille,marked);
			}
		}
	}
	return islands;
}

//Mesurez la fluidité de la grille
//Notez que les pièces peuvent être éloignées
double Smooth(int** grille){
	double smoothness = 0;
	int k;
	double var1, var2;
	for(int i = 0;i < SIZE;i++){
		for(int j = 0;j < SIZE;j++){
			if(grille[i][j] != 0){
				var1 = log10((double)grille[i][j]) / log10(2.0);

				k = i - 1;
				while(k >= 0){
					if(grille[k][j] != 0){
						var2 = log10((double)grille[k][j]) / log10(2.0);
						smoothness -= fabs(var1 - var2);
						break;
					}
					k--;
				}

				k = i + 1;
				while(k < SIZE){
					if(grille[k][j] != 0){
						var2 = log10((double)grille[k][j]) / log10(2.0);
						smoothness -= fabs(var1 - var2);
						break;
					}
					k++;
				}

				k = j - 1;
				while(k >= 0){
					if(grille[i][k] != 0){
						var2 = log10((double)grille[i][k]) / log10(2.0);
						smoothness -= fabs(var1 - var2);
						break;
					}
					k--;
				}

				k = j + 1;
				while(k < SIZE){
					if(grille[i][k] != 0){
						var2 = log10((double)grille[i][k]) / log10(2.0);
						smoothness -= fabs(var1 - var2);
						break;
					}
					k++;
				}
			}
		}
	}
	return smoothness;
}

double Empty(int** grille){
	double num = 0;
	for(int i = 0;i < SIZE;i++){
		for(int j = 0;j < SIZE;j++){
			if(grille[i][j] == 0){
				num++;
			}
		}
	}
	return num;
}

//Mesure la monotonie de la grille.
double Mono(int** grille){
	double totals[4] = {0, 0, 0, 0};
	int current, next;
	double currentVar, nextVar;
	for(int i = 0;i < SIZE;i++){
		current = 0;
		next = current + 1;
		while(next < SIZE){
			while(next < SIZE && grille[i][next] != 0){
				next++;
			}
			if(next >= SIZE){
				next--;
			}

			if(grille[i][current] != 0){
				currentVar = log10((double)grille[i][current]) / log10(2.0);
			}else{
				currentVar = 0;
			}

			if(grille[i][next] != 0){
				nextVar = log10((double)grille[i][next]) / log10(2.0);
			}else{
				nextVar = 0;
			}

			if(currentVar >= nextVar){
				totals[0] += nextVar - currentVar;
			}else{
				totals[1] += currentVar - nextVar;
			}

			current = next;
			next = current + 1;
		}
	}

	for(int j = 0;j < SIZE;j++){
		current = 0;
		next = current + 1;
		while(next < SIZE){
			while(next < SIZE && grille[next][j] != 0){
				next++;
			}
			if(next >= SIZE){
				next--;
			}

			if(grille[current][j] != 0){
				currentVar = log10((double)grille[current][j]) / log10(2.0);
			}else{
				currentVar = 0;
			}

			if(grille[next][j] != 0){
				nextVar = log10((double)grille[next][j]) / log10(2.0);
			}else{
				nextVar = 0;
			}

			if(currentVar >= nextVar){
				totals[2] += nextVar - currentVar;
			}else{
				totals[3] += currentVar - nextVar;
			}
			
			current = next;
			next = current + 1;
		}
	}

	int mono = 0;
	if(totals[0] >= totals[1]){
		mono += totals[0];
	}else{
		mono += totals[1];
	}

	if(totals[2] >= totals[3]){
		mono += totals[2];
	}else{
		mono += totals[3];
	}
	
	return mono;
}

double MaxVar(int** grille){
	double maxvar = 0;
	for(int i = 0;i < SIZE;i++){
		for(int j = 0;j < SIZE;j++){
			if(grille[i][j] > maxvar){
				maxvar = (double)grille[i][j];
			}
		}
	}
	return log(maxvar) / log(2.0);
}

//Fonction d'évaluation statique
double Evalue(int** grille){
	double evalue;

	double smooth = Smooth(grille);
	double empty = Empty(grille);
	double mono = Mono(grille);
	double max = MaxVar(grille);

	evalue = Weight_Smooth*smooth + Weight_Empty*log10(empty) + Weight_Mono*mono + Weight_max*max;
	return evalue;
}

