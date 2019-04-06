#include "Game.h"
#include <iostream>

Game::Game(int board_width, int board_height, std::string preset)
	:_width(board_width),
	_height(board_height),
	_preset(preset),
	_position(0)
{
	_board.reserve(500);
	_board.push_back(Board{ _width,_height, _preset });
	int x = (900 - ((_width - 1) * _offset)) / _width;
	int y = (600 - ((_height - 1) * _offset)) / _height;
	if (x < y)
		_rectangle_size = x;
	else _rectangle_size = y;
}

void Game::PlayGame()
{
	/*for (int run = 0; run < number_of_runs_; run++)
	{
		board_.ProccedNextInteration();
		board_.PrintBoard();
	}*/
}

void Game::DrawBoard(sf::RenderWindow & window)
{
	auto board = _board.at(_position).GetBoard();
	sf::RectangleShape rectangle;
	for (int i = 0; i < _width; i++)
	{
		for (int j = 0; j < _height; j++)
		{	
			int x = 50 + i* (_rectangle_size + _offset);
			int y = 150 + j*(_rectangle_size + _offset);
			std::cout << "QQQQ: " << x << " " << y <<  std::endl;
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
	_board.push_back(_board.at(_position).ProccedNextInteration());
	_position++;
}

void Game::Forward()
{
	if (_position < (_board.size() - 1))
		_position++;
}

void Game::Backward()
{
	if (_position > 0)
		_position--;
}
