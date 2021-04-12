#include "Chess.h"
Chess::Chess() {
	CopyPosFiller();
	PossibilitiesFiller();
	MAP = { {'A', 0}, {'B', 1} ,{'C', 2} , {'D', 3}, {'E', 4}, {'F', 5}, {'G', 6}, {'H', 7} };
}


void Chess::CopyPosFiller() {
	for (int y = 0; y < 8; y++)
		for (int x = 0; x < 8; x++)
			if (board.ChessBoard[y][x] != NULL)
				CopyPos.push_back({ y, x });
}



void Chess::ValidateInput() {
	while (true)
	{
		std::cin >> cy >> cx >> ty >> tx;
		cx = toupper(cx); tx = toupper(tx);
		if (std::cin.fail())
		{
			cy = -1;
			std::cin.clear();
			std::cin.ignore(100, '\n');
			system("cls");
			board.BoardPrinter();
			std::wcout << "[-] Please enter a valid value !\n";
			continue;
		}
		break;
	}
	if (cy > 7 || cy < 0 || ty > 7 || ty < 0 || cx > 'H' || cx < 'A' || tx > 'H' || tx < 'A') {
		system("cls");
		board.BoardPrinter();
		std::wcout << "[-] Please enter a valid values !\n";
		InputStatus = STATUS::INVALID;
	}
	else {
		cx_int = MAP[cx];
		tx_int = MAP[tx];
		InputStatus = STATUS::VALID;
	}
}



void Chess::PossibilitiesFiller(){
	for (int y = 0; y < 8; y++)
		for (int x = 0; x < 8; x++) {
			if(board.ChessBoard[y][x] != NULL)
				board.ChessBoard[y][x]->PossibilitiesFiller(x, y, CopyPos);
		}
}



bool Chess::ValidateMove() {
	bool ValidOrNot = false;
	Report = ReportStatus::FAIL;
	if (board.ChessBoard[cy][cx_int] == NULL) {
		Report = ReportStatus::EMPTY;
		return false;
	}
	else
		for (int i = 0; i < board.ChessBoard[cy][cx_int]->PossibleMoves.size(); i++)
			if (board.ChessBoard[cy][cx_int]->PossibleMoves[i][0] == ty &&
				board.ChessBoard[cy][cx_int]->PossibleMoves[i][1] == tx_int) {
				ValidOrNot = true;
				Report = ReportStatus::SUCCESSFUL;
			}
	return ValidOrNot;
}



void Chess::MovePiece() {
	board.ChessBoard[ty][tx_int] = board.ChessBoard[cy][cx_int];
	board.ChessBoard[cy][cx_int] = NULL;
	board.ChessBoard[ty][tx_int]->PossibleMoves.clear();
	CopyPos.clear();
	CopyPosFiller();
	PossibilitiesFiller();
	//board.ChessBoard[ty][tx_int]->PossibilitiesFiller(tx_int, ty);
}


	
void Chess::BoardPrintWithReport(){
	board.BoardPrinter();
	switch (Report) {
	case ReportStatus::EMPTY:
		std::wcout << "[-] You picked an empty cell! - try again now!\n"; break;
	case ReportStatus::SUCCESSFUL:
		std::wcout << "[+] The piece has been moved successfully! - do you next move now\n"; break;
	case ReportStatus::FAIL:
		std::wcout << "[-] Make sure from your move - try again now!\n"; break;
	}
}
