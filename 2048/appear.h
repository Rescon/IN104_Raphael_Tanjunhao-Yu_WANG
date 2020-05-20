//
//  appear.h
//  2048
//

#ifndef appear_h
#define appear_h

//Définir la structure qui représente la position
struct position{
    int x;
    int y;
};

struct position *Find_Empty_Position(int **grille);

//Génère aléatoirement un 2 (75%) ou un 4 (25%) en position libre
void Random_Appear(int **grille);

#endif /* appear_h */
