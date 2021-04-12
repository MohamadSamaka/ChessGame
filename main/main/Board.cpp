#include "Board.h"

Board::Board() {
	InitialInitializer();
	BoardPrinter();
}


void Board::InitialInitializer() {
	int flip = 0;
	int color[] = { WHITE, BLACK };
	std::wstring order[][2] = { {Wrook, Brook}, {Wknight, Bknight}, {Wbishop, Bbishop}, {Wking, Bking}, {Wqueen, Bqueen},
								{Wbishop, Bbishop}, {Wknight, Bknight}, {Wrook, Brook}, {Wpawn, Bpawn} };
	int repeated[] = { 0,0,0,0,0,0 };
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i == 0 || i == 7) {
				switch (j)
				{
				case 0:
					ChessBoard[i].push_back(&rook[repeated[0]]);
					ChessBoard[i][j]->SetName(order[j][flip]);
					ChessBoard[i][j]->SetColor(color[flip]);
					repeated[0] += 1;
					break;
				case 1:
					ChessBoard[i].push_back(&knight[repeated[1]]);
					ChessBoard[i][j]->SetName(order[j][flip]);
					ChessBoard[i][j]->SetColor(color[flip]);

					repeated[1] += 1;
					break;
				case 2:
					ChessBoard[i].push_back(&bishop[repeated[2]]);
					ChessBoard[i][j]->SetName(order[j][flip]);
					ChessBoard[i][j]->SetColor(color[flip]);

					repeated[2] += 1;
					break;
				case 3:
					ChessBoard[i].push_back(&king[repeated[3]]);
					ChessBoard[i][j]->SetName(order[j][flip]);
					ChessBoard[i][j]->SetColor(color[flip]);

					repeated[3] += 1;
					break;
				case 4:
					ChessBoard[i].push_back(&queen[repeated[4]]);
					ChessBoard[i][j]->SetName(order[j][flip]);
					ChessBoard[i][j]->SetColor(color[flip]);
					repeated[4] += 1;
					break;
				case 5:
					ChessBoard[i].push_back(&bishop[repeated[2]]);
					ChessBoard[i][j]->SetName(order[j][flip]);
					ChessBoard[i][j]->SetColor(color[flip]);
					repeated[2] += 1;
					break;
				case 6:
					ChessBoard[i].push_back(&knight[repeated[1]]);
					ChessBoard[i][j]->SetName(order[j][flip]);
					ChessBoard[i][j]->SetColor(color[flip]);
					repeated[1] += 1;
					break;
				case 7:
					ChessBoard[i].push_back(&rook[repeated[0]]);
					ChessBoard[i][j]->SetName(order[j][flip]);
					ChessBoard[i][j]->SetColor(color[flip]);
					repeated[0] += 1;
					break;
				}
			}
			else if (i == 1 || i == 6) {
				ChessBoard[i].push_back(&pawn[repeated[5]]);
				ChessBoard[i][j]->SetName(order[8][flip]);
				ChessBoard[i][j]->SetColor(color[flip]);
				repeated[5] += 1;
			}
			else
				ChessBoard[i].push_back(NULL);
		}
		if (i == 1)
			flip = 1;
	}
}


void Board::BoardPrinter() {
	system("cls");
	std::wcout << " ";
	for (char i = 'A'; i <= 'H'; i++)
		std::wcout << i << " ";
	std::wcout << std::endl;
	std::wcout << " ---------------\n";
	int flip = -1;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			if (ChessBoard[i][j] != NULL)
				std::wcout << (j == 0 ? '|' : '\0') << ChessBoard[i][j]->GetName().c_str() << '|';
			else
				std::wcout << (j == 0 ? '|' : '\0') << " " << '|';
		std::wcout << " " << i << std::endl;
		if (i < 7)
			for (int j = 0; j <= 17; j++, flip *= -1)
				std::wcout << (j < 17 ? (flip != -1 ? '-' : (j != 0 && j != 16 ? '+' : '|')) : '\n');
	}
	std::wcout << " ---------------\n";
}
