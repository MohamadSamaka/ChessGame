#pragma once
#include <iostream>
#include <vector>
#define Wrook L"\u2656"
#define Wknight L"\u2658"
#define Wbishop L"\u2657"
#define Wking L"\u2654"
#define Wqueen L"\u2655"
#define Wpawn L"\u2659"
#define Brook L"\u265C"
#define Bknight L"\u265E"
#define Bbishop L"\u265D"
#define Bking L"\u265A"
#define Bqueen L"\u265B"
#define Bpawn L"\u265F"
#define WHITE 1
#define BLACK 0
//for (int j = 0; j < c.size(); j++)
//	if (c[j][0] == i && c[j][1] == x)
class Pieces
{
	std::wstring name;
protected:
	int color;
public:
	std::vector<std::vector<int>> PossibleMoves;
	void SetName(std::wstring name);
	void SetColor(int color);
	std::wstring GetName();
	void PrintName();
	virtual void PossibilitiesFiller(int y, int x, std::vector<std::vector<int>> c = {}) = 0;
};



class King :public Pieces
{
public:
	King() {};
	void PossibilitiesFiller(int y, int x, std::vector<std::vector<int>> c = {})override;
};



class Queen :public Pieces
{
public:
	Queen() {};
	void PossibilitiesFiller(int y, int x, std::vector<std::vector<int>> c = {})override;
};



class Bishop :public Pieces
{
public:
	Bishop() {};
	void PossibilitiesFiller(int y, int x, std::vector<std::vector<int>> c = {})override;
};



class Knight :public Pieces
{
public:
	Knight() {};
	void PossibilitiesFiller(int y, int x, std::vector<std::vector<int>> c = {})override;
};



class Rook :public Pieces
{
public:
	Rook() {};
	void PossibilitiesFiller(int y, int x, std::vector<std::vector<int>> c = {})override;
};



class Pawn:public Pieces
{
	bool FirstStep;
public:
	Pawn();
	void PossibilitiesFiller(int y, int x, std::vector<std::vector<int>> c = {})override;
};


inline bool Validate(int flip, int pos, int FixedNum, std::vector<std::vector<int>> c);
