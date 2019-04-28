#pragma once
#include "Cell.h"
#include <vector>
#include <string>

class Board
{
public:
	Board(int width, int height, std::string preset);
	Board(const int width,const int height, const std::vector<std::vector<Cell>>& board);
	Board(const Board& board);
	//void PrintBoard() const;
	Board ProccedNextInteration();
	void ApplyPreset(std::string preset);
	int CountNeighbours(int column, int row) const;
	bool DecideIfCellAlive(int ammount_of_neighbours, int column, int row) const;
	std::vector<std::vector<Cell>>& GetBoard();

private:

	std::vector<std::vector<Cell>> _board;
	int _board_width;
	int _board_height;

};