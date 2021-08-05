#include <iostream>
#include <io.h>
#include <fcntl.h>
#include "Chess.h"
//#include <limits>
int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    Chess obj;
	std::wcout << "do your move !\n";
	while (true) // keeps the game running
	{
		obj.ValidateInput();
		if (obj.InputStatus != Chess::STATUS::INVALID)
		{
			if (obj.ValidateMove())
				obj.MovePiece();
		}
		obj.BoardPrintWithReport();
	}
	return 0;
}
