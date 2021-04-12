#pragma once
#include "Board.h"
#include <map>
class Chess
{
protected:
	int cy, ty, cx_int, tx_int;
	std::vector<std::vector<int>>CopyPos = {};
	char cx, tx;
	std::map<char, int> MAP;
	Board board;
public:
	enum class STATUS { VALID, INVALID };
	enum class ReportStatus {SUCCESSFUL, FAIL, EMPTY};
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
