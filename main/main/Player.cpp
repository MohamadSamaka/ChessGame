#include <iostream>
#include "Player.h"

Player::Player() {
	InitialInitializer();
}

//Player::Player(int color) {
//	this->color = color;
//}

void Player::SetColor(int color) {
	this->color = color;
}

int Player::GetColor() {
	return color;
}

void Player::InitialInitializer() {
	std::wstring NameOrder[][6] = { {Brook, Bknight, Bbishop, Bking, Bqueen, Bpawn}, {Wrook, Wknight, Wbishop, Wking, Wqueen, Wpawn} };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			switch (i) {
			case 0:
				PiecesVec[i].push_back(&rook[j]);
				PiecesVec[i][j]->SetColor(color);
				PiecesVec[i][j]->SetName(NameOrder[color][0]);
				break;
			case 1:
				PiecesVec[i].push_back(&knight[j]);
				PiecesVec[i][j]->SetColor(color);
				PiecesVec[i][j]->SetName(NameOrder[color][1]);
				break;
			case 2:
				PiecesVec[i].push_back(&bishop[j]);
				PiecesVec[i][j]->SetColor(color);
				PiecesVec[i][j]->SetName(NameOrder[color][2]);
				break;
			}
		}
	}
	PiecesVec[3].push_back(&king);
	PiecesVec[3][0]->SetColor(color);
	PiecesVec[3][0]->SetName(NameOrder[color][3]);

	PiecesVec[4].push_back(&queen);
	PiecesVec[4][0]->SetColor(color);
	PiecesVec[4][0]->SetName(NameOrder[color][4]);

	for (int i = 0; i < 8; i++) {
		PiecesVec[5].push_back(&pawn[i]);
		PiecesVec[5][i]->SetColor(color);
		PiecesVec[5][i]->SetName(NameOrder[color][5]);
	}
}