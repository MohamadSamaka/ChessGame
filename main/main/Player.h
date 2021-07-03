#pragma once
#include <iostream>
//#include "Board.h"
#include "Pieces.h"
#include "Player.h"

class Player{
	int color;
	Rook rook[2]; Knight knight[2]; Bishop bishop[2]; King king; Queen queen; Pawn pawn[8]; // making the pieces
public:
	Player();
	//Player(int color);
	/*Player(int color) :Player(){};*/
	void InitialInitializer();
	std::vector<std::vector<Pieces*>> PiecesVec = { {}, {}, {}, {}, {}, {} };
	int GetColor();
	void SetColor(int color);
};
