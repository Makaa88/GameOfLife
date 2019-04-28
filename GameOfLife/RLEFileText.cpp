#include "RLEFileText.h"
#include <iostream>

int RLEFileText::counter = 0;

RLEFileText::RLEFileText(const std::string & name, sf::Font &font)
	:_name(name)
{
	_path = "RLE/" + name + ".rle";
	_text.setFillColor(sf::Color::White);
	_text.setCharacterSize(25);
	_text.setFont(font);
	_text.setString(std::to_string(counter) + ". " + _name);
	counter++;
	std::cout << _path << std::endl;
}

sf::Text & RLEFileText::GetText()
{
	return _text;
}

std::string RLEFileText::GetPath() const
{
	return _path;
}

std::string RLEFileText::GetName() const
{
	return _name;
}

void RLEFileText::SetPosition(const int & x, const int & y)
{
	_text.setPosition(x, y);
}
