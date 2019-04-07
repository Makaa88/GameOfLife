#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Board.h"


class Game
{
public:
	Game(int board_width, int board_height, std::string preset);
	void PlayGame();
	void DrawBoard(sf::RenderWindow &window);
	void ProccedNextIteration();
	void Forward();
	void Backward();

private:
	std::vector<Board> _board;
	int _position;
	int _width;
	int _height;
	std::string _preset;
	int _rectangle_size;
	int _offset = 10;
	int _start_x_position;

};