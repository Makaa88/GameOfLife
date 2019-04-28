#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class RLEFileText
{
public:
	RLEFileText(const std::string &name, sf::Font& font);
	sf::Text& GetText();
	std::string GetPath() const;
	std::string GetName() const;
	void SetPosition(const int& x, const int& y);


private:
	sf::Text _text;
	std::string _name;
	std::string _path;

	static int counter;
};