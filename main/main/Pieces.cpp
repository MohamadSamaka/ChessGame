#include "Pieces.h"

void Pieces::SetName(std::wstring name){
	this->name = name;
}


void Pieces::SetColor(int color) {
	this->color = color;
}


int Pieces::GetColor() {
	return this->color;
}

std::wstring Pieces::GetName() {
	return this->name;
}


void Pieces::PrintName() {
	std::wcout << this->name.c_str();
}


void King::PossibilitiesFiller(int x, int y, std::vector<std::vector<Pieces*>> b) {
	for (int i = y - 1; i <= y + 1; i++)
		for (int j = x - 1; j <= x + 1; j++) {
			if (i < 0 || i > 7 || j < 0 || j > 7 || (i == y && j == x))
				continue;
			if (!ColorChcker(this->color, b[y][2]->GetColor())) {
				this->PossibleMoves.push_back({ i, j });
				break;
			}
		}
}



void Queen::PossibilitiesFiller(int x, int y, std::vector<std::vector<Pieces*>> b) {
	////bishop section
	//int situation = 0;
	//std::vector<std::vector<int>> Tvec;
	//int b, Tx = x, Ty = y;
	//b = y + x;
	//while (Tx < 7 && Ty > 0) {
	//	Tx++; Ty--;
	//}

	//while (Tx >= 0) {
	//	Ty = Tx * -1 + b;
	//	if (Ty >= 8)
	//		break;
	//	else if (Ty == y && Tx == x) {
	//		Tx--;
	//		situation = 1;
	//		continue;
	//	}
	//	if (Validate(1, Ty, Tx, c) && situation == 0) {
	//		Tvec.clear();
	//		Tvec.push_back({ Ty, Tx });
	//	}
	//	else if (Validate(1, Ty, Tx, c) && situation == 1) {
	//		Tvec.push_back({ Ty, Tx });
	//		break;
	//	}
	//	else {
	//		Tvec.push_back({ Ty, Tx });
	//	}
	//	Tx--;
	//}

	//situation = 0;
	//if (!Tvec.empty())
	//	for (int i = 0; i < Tvec.size(); i++)
	//		this->PossibleMoves.push_back(Tvec[i]);
	//Tvec.clear();


	//Tx = x, Ty = y;
	//b = y - x;
	//while (Tx > 0 && Ty > 0) {
	//	Tx--; Ty--;
	//}

	//while (Tx <= 7) {
	//	Ty = Tx + b;
	//	if (Ty >= 8)
	//		break;
	//	else if (Ty == y && Tx == x) {
	//		Tx++;
	//		situation = 1;
	//		continue;
	//	}
	//	if (Validate(1, Ty, Tx, c) && situation == 0) {
	//		Tvec.clear();
	//		Tvec.push_back({ Ty, Tx });
	//	}
	//	else if (Validate(1, Ty, Tx, c) && situation == 1) {
	//		Tvec.push_back({ Ty, Tx });
	//		break;
	//	}
	//	else
	//		Tvec.push_back({ Ty, Tx });
	//	Tx++;
	//}

	//if (!Tvec.empty())
	//	for (int i = 0; i < Tvec.size(); i++)
	//		this->PossibleMoves.push_back(Tvec[i]);


	////rook section
	//situation = 0;
	//Tvec.clear();
	//for (int t = 0; t < 2; t++) {
	//	if (t == 0) {
	//		for (int i = 0; i < 8; i++) {
	//			if (i == x) {
	//				situation = 1;
	//				continue;
	//			}
	//			if (Validate(0, i, y, c) && situation == 0) {
	//				Tvec.clear();
	//				Tvec.push_back({ y, i });
	//			}
	//			else if (Validate(0, i, y, c) && situation == 1) {
	//				Tvec.push_back({ y, i });
	//				break;
	//			}
	//			else
	//				Tvec.push_back({ y, i });
	//		}
	//	}
	//	else {
	//		for (int i = 0; i < 8; i++) {
	//			if (i == y) {
	//				situation = 1;
	//				continue;
	//			}
	//			if (Validate(1, i, x, c) && situation == 0) {
	//				Tvec.clear();
	//				Tvec.push_back({ i, x });
	//			}
	//			else if (Validate(1, i, x, c) && situation == 1) {
	//				Tvec.push_back({ i, x });
	//				break;
	//			}
	//			else
	//				Tvec.push_back({ i, x });
	//		}
	//	}
	//	situation = 0;
	//	if (!Tvec.empty())
	//		for (int i = 0; i < Tvec.size(); i++)
	//			this->PossibleMoves.push_back(Tvec[i]);
	//	Tvec.clear();
	//}
}



void Bishop::PossibilitiesFiller(int x, int y, std::vector<std::vector<Pieces*>> b) {
	//int situation = 0;
	//std::vector<std::vector<int>> Tvec;
	//int b, Tx = x, Ty = y;
	//b = y + x;
	//while (Tx < 7 && Ty > 0) {
	//	Tx++; Ty--;
	//}

	//while (Tx >= 0) {
	//	Ty = Tx * -1 + b;
	//	if (Ty >= 8)
	//		break;
	//	else if (Ty == y && Tx == x) {
	//		Tx--;
	//		situation = 1;
	//		continue;
	//	}
	//	if (Validate(1, Ty, Tx, c) && situation == 0) {
	//		Tvec.clear();
	//		Tvec.push_back({ Ty, Tx });
	//	}
	//	else if (Validate(1, Ty, Tx, c) && situation == 1) {
	//		Tvec.push_back({ Ty, Tx });
	//		break;
	//	}
	//	else {
	//		Tvec.push_back({ Ty, Tx });
	//	}
	//	Tx--;
	//}

	//situation = 0;
	//if (!Tvec.empty())
	//	for (int i = 0; i < Tvec.size(); i++)
	//		this->PossibleMoves.push_back(Tvec[i]);
	//Tvec.clear();


	//Tx = x, Ty = y;
	//b = y - x;
	//while (Tx > 0 && Ty > 0) {
	//	Tx--; Ty--;
	//}

	//while (Tx <= 7) {
	//	Ty = Tx + b;
	//	if (Ty >= 8)
	//		break;
	//	else if (Ty == y && Tx == x) {
	//		Tx++;
	//		situation = 1;
	//		continue;
	//	}
	//	if (Validate(1, Ty, Tx, c) && situation == 0) {
	//		Tvec.clear();
	//		Tvec.push_back({ Ty, Tx });
	//	}
	//	else if (Validate(1, Ty, Tx, c) && situation == 1) {
	//		Tvec.push_back({ Ty, Tx });
	//		break;
	//	}
	//	else
	//		Tvec.push_back({ Ty, Tx });
	//	Tx++;
	//}

	//if (!Tvec.empty())
	//	for (int i = 0; i < Tvec.size(); i++)
	//		this->PossibleMoves.push_back(Tvec[i]);


}



void Knight::PossibilitiesFiller(int x, int y, std::vector<std::vector<Pieces*>> b) {
	for (int i = 1, j = 2; i <= 2; i++, j--) {
		int Tx[] = { x + i, x - i };
		for (int c = 0; c <= 1; c++) {
			if (Tx[c] < 0 || Tx[c] > 7)
				continue;
			if ((y + j) <= 7)
				if(b[y + j][Tx[c]] == NULL || !ColorChcker(this->color, b[y + j][Tx[c]]->GetColor()))
					this->PossibleMoves.push_back({ y + j, Tx[c] });
			if ((y - j) >= 0)
				if (b[y - j][Tx[c]] == NULL || !ColorChcker(this->color, b[y - j][Tx[c]]->GetColor()))
					this->PossibleMoves.push_back({ y - j, Tx[c] });
		}
	}

}



void Rook::PossibilitiesFiller(int x, int y, std::vector<std::vector<Pieces*>> b) {
	//int situation = 0;
	//std::vector<std::vector<int>> Tvec;
	//for (int t = 0; t < 2; t++) {
	//	if (t == 0) {
	//		for (int i = 0; i < 8; i++) {
	//			if (i == x) {
	//				situation = 1;
	//				continue;
	//			}
	//			if (Validate(0, i, y, c) && situation == 0) {
	//				Tvec.clear();
	//				Tvec.push_back({ y, i });
	//			}
	//			else if (Validate(0, i, y, c) && situation == 1) {
	//				Tvec.push_back({ y, i });
	//				break;
	//			}
	//			else
	//				Tvec.push_back({ y, i });
	//		}
	//	}
	//	else {
	//		for (int i = 0; i < 8; i++) {
	//			if (i == y) {
	//				situation = 1;
	//				continue;
	//			}
	//			if (Validate(1, i, x, c) && situation == 0) {
	//				Tvec.clear();
	//				Tvec.push_back({ i, x });
	//			}
	//			else if (Validate(1, i, x, c) && situation == 1) {
	//				Tvec.push_back({ i, x });
	//				break;
	//			}
	//			else
	//				Tvec.push_back({ i, x });
	//		}
	//	}
	//	situation = 0;
	//	if (!Tvec.empty())
	//		for (int i = 0; i < Tvec.size(); i++)
	//			this->PossibleMoves.push_back(Tvec[i]);
	//	Tvec.clear();
	//}
}


Pawn::Pawn() {
	FirstStep = true;
}



void Pawn::PossibilitiesFiller(int x, int y, std::vector<std::vector<Pieces*>> b) {
	int step, F = 1;
	if (color == BLACK)
		F = -1;
	FirstStep == true ? step = 2 : step = 1;
	for (int i = x - 1; i <= x + 1; i+=2) {
		int s = y + 1 * F;
		if(i >= 0 && i<= 7)
			if (b[s][i] != NULL)
				if (!ColorChcker(color, b[s][i]->GetColor())) {
					this->PossibleMoves.push_back({ s , i });
				}
	}

	for (int i = 1; i <= step; i++) {
		int val = y + i * F;
		if (b[val][x] == NULL)
			this->PossibleMoves.push_back({ val , x });
	}

	FirstStep = false;
}


//void PawnPossobilitiesGenerator(std::vector<std::vector<int>> P, int YStep, int XStep) {
//
//}
//



inline bool Validate(int flip, int var, int FixedNum, std::vector<std::vector<int>> c){
	for (int j = 0; j < c.size() - 1; j++)
		if (flip == 0) {
			if (c[j][0] == FixedNum && c[j][1] == var)
				return true;
		}
		else if (c[j][0] == var && c[j][1] == FixedNum)
			return true;
	return false;
}


inline bool ColorChcker(int Acolor, int Tcolor) {
	if (Acolor == Tcolor)
		return true;
	return false;
}