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

			if (b[i][j] == NULL) {
				this->PossibleMoves.push_back({ i, j });
				continue;
			}

			if (!ColorChcker(this->color, b[i][j]->GetColor())) {
				this->PossibleMoves.push_back({ i, j });
			}
		}
}



void Queen::PossibilitiesFiller(int x, int y, std::vector<std::vector<Pieces*>> b) {
	//////bishop section

	int Tx = x, Ty = y, color = this->color, tcolor;
	bool flag = false;
	while (Tx < 7 && Ty > 0) {
		Tx++; Ty--;
		if (b[Ty][Tx] != NULL) {
			if (ColorChcker(b[Ty][Tx]->GetColor(), color))
				Tx--; Ty++;
			break;
		}
	}

	while (Tx >= 0 && Ty < 8) {
		if (b[Ty][Tx] != NULL)
			tcolor = b[Ty][Tx]->GetColor();
		if (Tx == x && Ty == y) {
			flag = true;
			Tx--; Ty++;
			continue;
		}

		if (b[Ty][Tx] == NULL) {///
			this->PossibleMoves.push_back({ Ty, Tx });
			Tx--; Ty++;
			continue;
		}

		if (b[Ty][Tx] != NULL && !ColorChcker(tcolor, color)) {
			this->PossibleMoves.push_back({ Ty, Tx });
			if (flag)
				break;
		}

		if (b[Ty][Tx] != NULL && ColorChcker(tcolor, color) && flag)
			break;

		Tx--; Ty++;
	}

	flag = false;
	Tx = x; Ty = y;
	while (Tx > 0 && Ty > 0) {
		Tx--; Ty--;
		if (b[Ty][Tx] != NULL) {
			if (ColorChcker(b[Ty][Tx]->GetColor(), color))
				Tx++; Ty++;
			break;
		}
	}

	while (Tx < 8 && Ty < 8) {
		if (b[Ty][Tx] != NULL)
			tcolor = b[Ty][Tx]->GetColor();
		if (Tx == x && Ty == y) {
			flag = true;
			Tx++; Ty++;
			continue;
		}

		if (b[Ty][Tx] == NULL) {///
			this->PossibleMoves.push_back({ Ty, Tx });
			Tx++; Ty++;
			continue;
		}

		if (b[Ty][Tx] != NULL && !ColorChcker(tcolor, color)) {
			this->PossibleMoves.push_back({ Ty, Tx });
			if (flag)
				break;
		}

		if (b[Ty][Tx] != NULL && ColorChcker(tcolor, color) && flag)
			break;

		Tx++; Ty++;
	}


	//rook's section

	Tx = x; Ty = y;
	flag = false;
	while (Tx > 0) {
		Tx--;
		if (b[Ty][Tx] != NULL) {
			if (ColorChcker(b[Ty][Tx]->GetColor(), color))
				Tx++;
			break;
		}
	}
	while (Tx < 8) {
		if (b[Ty][Tx] != NULL)
			tcolor = b[Ty][Tx]->GetColor();

		if (Tx == x) {
			Tx++;
			flag = true;
			continue;
		}

		if (b[Ty][Tx] == NULL) {
			this->PossibleMoves.push_back({ Ty,Tx });
			Tx++;
			continue;
		}

		if (b[Ty][Tx] != NULL && !ColorChcker(b[Ty][Tx]->GetColor(), color)) {
			this->PossibleMoves.push_back({ Ty,Tx });
			if (flag)
				break;
		}

		if (b[Ty][Tx] != NULL && ColorChcker(b[Ty][Tx]->GetColor(), color) && flag)
			break;

		Tx++;
	}
	Tx = x; Ty = y;
	flag = false;

	while (Ty > 0) {
		Ty--;
		if (b[Ty][Tx] != NULL) {
			if (ColorChcker(b[Ty][Tx]->GetColor(), color))
				Ty++;
			break;
		}
	}

	while (Ty < 8) {
		if (b[Ty][Tx] != NULL)
			tcolor = b[Ty][Tx]->GetColor();

		if (Ty == y) {
			Ty++;
			flag = true;
			continue;
		}

		if (b[Ty][Tx] == NULL) {
			this->PossibleMoves.push_back({ Ty,Tx });
			Ty++;
			continue;
		}

		if (b[Ty][Tx] != NULL && !ColorChcker(b[Ty][Tx]->GetColor(), color)) {
			this->PossibleMoves.push_back({ Ty,Tx });
			if (flag)
				break;
		}

		if (b[Ty][Tx] != NULL && ColorChcker(b[Ty][Tx]->GetColor(), color) && flag)
			break;

		Ty++;
	}
}



void Bishop::PossibilitiesFiller(int x, int y, std::vector<std::vector<Pieces*>> b) {
	int Tx = x, Ty = y, color = this->color, tcolor;
	bool flag = false;
	while (Tx < 7 && Ty > 0) {
		Tx++; Ty--;
		if (b[Ty][Tx] != NULL) {
			if (ColorChcker(b[Ty][Tx]->GetColor(), color))
				Tx--; Ty++;
			break;
		}
	}

	while (Tx >= 0 && Ty < 8) {
		if (b[Ty][Tx] != NULL)
			tcolor = b[Ty][Tx]->GetColor();
		if (Tx == x && Ty == y) { 
			flag = true;
			Tx--; Ty++;
			continue;
		}

		if (b[Ty][Tx] == NULL) {///
			this->PossibleMoves.push_back({ Ty, Tx });
			Tx--; Ty++;
			continue;
		}

		if (b[Ty][Tx] != NULL && !ColorChcker(tcolor, color)) {
			this->PossibleMoves.push_back({ Ty, Tx });
			if (flag)
				break;
		}

		if (b[Ty][Tx] != NULL && ColorChcker(tcolor, color) && flag)
			break;

		Tx--; Ty++;
	}

	flag = false;
	Tx = x; Ty = y;
	while (Tx > 0 && Ty > 0) {
		Tx--; Ty--;
		if (b[Ty][Tx] != NULL) {
			if (ColorChcker(b[Ty][Tx]->GetColor(), color))
				Tx++; Ty++;
			break;
		}
	}

	while (Tx < 8 && Ty < 8) {
		if (b[Ty][Tx] != NULL)
			tcolor = b[Ty][Tx]->GetColor();
		if (Tx == x && Ty == y) {
			flag = true;
			Tx++; Ty++;
			continue;
		}

		if (b[Ty][Tx] == NULL) {///
			this->PossibleMoves.push_back({ Ty, Tx });
			Tx++; Ty++;
			continue;
		}

		if (b[Ty][Tx] != NULL && !ColorChcker(tcolor, color)) {
			this->PossibleMoves.push_back({ Ty, Tx });
			if (flag)
				break;
		}

		if (b[Ty][Tx] != NULL && ColorChcker(tcolor, color) && flag)
			break;

		Tx++; Ty++;
	}

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
	int Tx = x, Ty = y, color = this->color, tcolor;
	bool flag = false;
	while (Tx > 0) {
		Tx--;
		if (b[Ty][Tx] != NULL) {
			if (ColorChcker(b[Ty][Tx]->GetColor(), color))
				Tx++;
			break;
		}
	}
	while (Tx < 8) {
		if (b[Ty][Tx] != NULL)
			tcolor = b[Ty][Tx]->GetColor();

		if (Tx == x) {
			Tx++;
			flag = true;
			continue;
		}

		if (b[Ty][Tx] == NULL) {
			this->PossibleMoves.push_back({ Ty,Tx });
			Tx++;
			continue;
		}

		if (b[Ty][Tx] != NULL && !ColorChcker(b[Ty][Tx]->GetColor(), color)) {
			this->PossibleMoves.push_back({ Ty,Tx });
			if (flag)
				break;
		}

		if (b[Ty][Tx] != NULL && ColorChcker(b[Ty][Tx]->GetColor(), color) && flag)
			break;

		Tx++;
	}
	Tx = x; Ty = y;
	flag = false;

	while (Ty > 0) {
		Ty--;
		if (b[Ty][Tx] != NULL) {
			if (ColorChcker(b[Ty][Tx]->GetColor(), color))
				Ty++;
			break;
		}
	}

	while (Ty < 8) {
		if (b[Ty][Tx] != NULL)
			tcolor = b[Ty][Tx]->GetColor();

		if (Ty == y) {
			Ty++;
			flag = true;
			continue;
		}

		if (b[Ty][Tx] == NULL) {
			this->PossibleMoves.push_back({ Ty,Tx });
			Ty++;
			continue;
		}

		if (b[Ty][Tx] != NULL && !ColorChcker(b[Ty][Tx]->GetColor(), color)) {
			this->PossibleMoves.push_back({ Ty,Tx });
			if (flag)
				break;
		}

		if (b[Ty][Tx] != NULL && ColorChcker(b[Ty][Tx]->GetColor(), color) && flag)
			break;

		Ty++;
	}
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




//
//inline bool Validate(int flip, int var, int FixedNum, std::vector<std::vector<int>> c){
//	for (int j = 0; j < c.size() - 1; j++)
//		if (flip == 0) {
//			if (c[j][0] == FixedNum && c[j][1] == var)
//				return true;
//		}
//		else if (c[j][0] == var && c[j][1] == FixedNum)
//			return true;
//	return false;
//}


inline bool ColorChcker(int Acolor, int Tcolor) {
	if (Acolor == Tcolor)
		return true;
	return false;
}