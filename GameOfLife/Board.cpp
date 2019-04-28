#include "Board.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>

namespace
{
	void PrepareVector(std::vector<std::vector<Cell>> &board, int width, int height)
	{
		for (int columns = 0; columns < width; columns++)
		{
			std::vector<Cell> cells(height);
			board.push_back(cells);
		}
	}
}

Board::Board(int width, int height, std::string preset)
	:_board_width(width),
	 _board_height(height)
{
	PrepareVector(_board, width, height);
	ApplyPreset(preset);
}

Board::Board(const int width, const int height, const std::vector<std::vector<Cell>>& board)
	:_board_width(width),
	_board_height(height)
{
	PrepareVector(_board, _board_width, _board_height);
	for (int i = 0; i < _board_width; i++)
		for (int j = 0; j < _board_height; j++)
			_board.at(i).at(j).SetCell(board.at(i).at(j).GetCell());
}

Board::Board(const Board & board)
{
	_board = board._board;
	_board_width = board._board_width;
	_board_height = board._board_height;
}

void Board::ApplyPreset(std::string preset)
{
	std::string sign;
	char dead_or_alive;
	int number = 0;
	int column = 0;
	int row = 0;

	for (int i = 0; i < preset.size(); i++)
	{
		sign = "";
		while (isdigit(preset[i]))
		{
			sign += preset[i++];
		}

		if (sign.size() == 0)
			number = 1;
		else number = std::stoi(sign);
		dead_or_alive = preset[i];

		for (int j = 0; j < number; j++)
		{
			_board[column++][row].SetCell(dead_or_alive);
		}

		if (preset[i + 1] == '$')
		{
			column = 0;
			row++;
			i++;
		}
		else if (preset[i + 1] == '!')
			break;
	}
}


Board Board::ProccedNextInteration()
{

	std::vector<std::vector<Cell>> temp_board;
	PrepareVector(temp_board, _board_width, _board_height);
	int ammout_of_neighbours;
	bool dead_or_alive;
	for (int column = 0; column < _board_width; column++)
	{
		for (int row = 0; row < _board_height; row++)
		{
			ammout_of_neighbours = CountNeighbours(column, row);
			dead_or_alive = DecideIfCellAlive(ammout_of_neighbours, column, row);
			temp_board[column][row].SetCell(dead_or_alive);
		}
	}
	
	return Board(_board_width, _board_height, temp_board);
}

int Board::CountNeighbours(int column, int row) const
{
	int ammout_of_neighbours = 0;
	for (int i = column - 1; i <= column + 1; i++)
	{
		for (int j = row - 1; j <= row + 1; j++)
		{
			if ((i == column) && (j == row))
				continue;
			if ((i == -1) || (i == _board_width))
				continue;
			if ((j == -1))
			{
				continue;
				if (_board[i][_board_height - 1].GetCell())
				{
					ammout_of_neighbours++;
				}
			}
			else if (j == (_board_height))
			{
				continue;
				if (_board[i][0].GetCell())
					ammout_of_neighbours++;
			}
			else if (_board[i][j].GetCell())
				ammout_of_neighbours++;
		}
	}

	return ammout_of_neighbours;
}

bool Board::DecideIfCellAlive(int ammout_of_neighbours, int column, int row) const
{
	bool dead_or_alive = _board[column][row].GetCell();
	if (!dead_or_alive && (ammout_of_neighbours == 3))
		dead_or_alive = true;
	else if (dead_or_alive && ((ammout_of_neighbours < 2) || (ammout_of_neighbours > 3)))
		dead_or_alive = false;
	return dead_or_alive;
}

std::vector<std::vector<Cell>>& Board::GetBoard()
{
	return _board;
}

