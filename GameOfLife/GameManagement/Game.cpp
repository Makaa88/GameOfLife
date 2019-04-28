#include "Game.h"
#include <iostream>
#include <fstream>

Game::Game(int board_width, int board_height, std::string preset)
	:_width(board_width),
	_height(board_height),
	_preset(preset),
	_position(0)
{
	_board.reserve(1000);
	_board.push_back(Board{ _width,_height, _preset });
	int x = (900 - ((_width - 1) * _offset)) / _width;
	int y = (600 - ((_height - 1) * _offset)) / _height;
	if (x < y)
		_rectangle_size = x;
	else _rectangle_size = y;

	_start_x_position = 900 - ((_width - 1) * _offset) - (_rectangle_size * _width);
	_start_x_position /= 2;
	std::cout << _start_x_position << std::endl;
}

void Game::DrawBoard(sf::RenderWindow & window)
{
	auto board = _board.at(_position).GetBoard();
	sf::RectangleShape rectangle;
	for (int i = 0; i < _width; i++)
	{
		for (int j = 0; j < _height; j++)
		{	
			int x = _start_x_position + i* (_rectangle_size + _offset);
			int y = 150 + j*(_rectangle_size + _offset);
			//std::cout << "QQQQ: " << x << " " << y <<  std::endl;
			rectangle.setPosition(sf::Vector2f(x,y ));
			rectangle.setSize(sf::Vector2f(_rectangle_size, _rectangle_size));
			if (board.at(i).at(j).GetCell())
				rectangle.setFillColor(sf::Color::Red);
			else
				rectangle.setFillColor(sf::Color::Yellow);
			window.draw(rectangle);
		}
	}
}

void Game::ProccedNextIteration()
{
	if (_position < _board.size()-1)
		_position++;
	else if (_position < 1000)
	{
		_board.push_back(_board.at(_position).ProccedNextInteration());
		_position++;
	}
}

void Game::Forward()
{
	if (_position >= (_board.size() - 1))
		ProccedNextIteration();
	else
		_position++;
}

void Game::Backward()
{
	if (_position > 0)
		_position--;
}


void Game::SavePattern()
{
	std::fstream file;
	file.open("RLE/My Saved Pattern.rle", std::ios::out);
	auto board = _board.at(_position).GetBoard();
	file << "x = " << _width << ",y = " << _height << ", rule = b3/s23" << std::endl;

	int number_of_cells = 0;
	bool previous_state = false;
	char sign = 'b';

	for (int j = 0; j < _height; j++)
	{
		number_of_cells = 1;
		previous_state = board.at(0).at(j).GetCell();
		for (int i = 1; i < _width; i++)
		{
			if (board[i][j].GetCell() == previous_state)
				number_of_cells++;
			else
			{
				if (previous_state) 
					sign = 'o';
				else sign = 'b';

				if( number_of_cells != 1)
					file << number_of_cells << sign;
				else file << sign;

				previous_state = !previous_state;
				number_of_cells = 1;
			}
		}

		if (previous_state)
			sign = 'o';
		else sign = 'b';

		if (number_of_cells != 1)
			file << number_of_cells << sign;
		else file << sign;

		if(j != (_height-1))
			file << '$';
	}
	
	file << "!";
}
