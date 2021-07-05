#pragma once
#include "Board.h"
//#include "Players.h"
//#include "Player.h"
#include <map>
class Chess
{
protected:
	int cy, ty, cx_int, tx_int; //coords variables
	std::vector<std::vector<int>>CopyPos = {}; /*Stores The Coords Of Already Exist Pieces, These Coords Gonna Be Avoided
											   When We Make The Possible Moves*/
	char cx, tx;
	std::map<char, int> MAP;
	//Player WhitePlayer;
	//Board board;
	//Player BlackPlayer(1);
	//Player WhitePlayer(WHITE);
public:
	Player WhitePlayer{ 1 };
	Player BlackPlayer{ 0 };
	//Player WhitePlayer;
	Board board;
	enum class STATUS { VALID, INVALID }; //Input Status
	enum class ReportStatus {SUCCESSFUL, FAIL, EMPTY}; //Result Of Tying To Move Piece
	STATUS InputStatus;
	ReportStatus Report;
	Chess();
	void PossibilitiesFiller();
	void CopyPosFiller();
	bool ValidateMove();
	void MovePiece();
	void BoardPrintWithReport();
	void ValidateInput();
};
