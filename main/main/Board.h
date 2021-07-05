#pragma once
#include <vector>
//#include "Pieces.h"
#include "Player.h"
#include "Board.h"
//#define Wrook L"\u2656"
//#define Wknight L"\u2658"
//#define Wbishop L"\u2657"
//#define Wking L"\u2654"
//#define Wqueen L"\u2655"
//#define Wpawn L"\u2659"
//#define Brook L"\u265C"
//#define Bknight L"\u265E"
//#define Bbishop L"\u265D"
//#define Bking L"\u265A"
//#define Bqueen L"\u265B"
//#define Bpawn L"\u265F"


class Board
{
	//Rook rook[4]; Knight knight[4]; Bishop bishop[4]; King king[2]; Queen queen[2]; Pawn pawn[16]; // making the pieces
public:
	Board();
	bool temp = true;
	void InitialInitializer(std::vector<std::vector<Pieces*>>BPiec, int color);
	void BoardPrinter();
	//std::vector<std::vector<Pieces*>> ChessBoard = { {}, {}, {}, {}, {}, {}, {}, {} };
	std::vector<std::vector<Pieces*>> ChessBoard = { {}, {}, {}, {}, {}, {}, {}, {} };

};