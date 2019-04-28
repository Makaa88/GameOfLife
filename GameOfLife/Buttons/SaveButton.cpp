#include "SaveButton.h"

Buttons::SaveButton::SaveButton(sf::Font &font)
{
	_is_button_pressed = false;
	CreateShape();
	SetColor(sf::Color::Red);
	_text.setFont(font);
	_text.setCharacterSize(30);
	_text.setString("SAVE");
}

void Buttons::SaveButton::CreateShape()
{
	_rectangle.setPosition(600, 50);
	_rectangle.setSize(sf::Vector2f(120, 50));
	_text.setPosition(610, 60);
}

void Buttons::SaveButton::SetColor(const sf::Color &color)
{
	_rectangle.setFillColor(sf::Color::Blue);
	_text.setFillColor(color);
}

void Buttons::SaveButton::DrawShape(sf::RenderWindow &window)
{
	window.draw(_rectangle);
	window.draw(_text);
}


void Buttons::SaveButton::PressButton()
{
	_is_button_pressed = true;
	SetColor(sf::Color::Green);
}

void Buttons::SaveButton::ReleaseButton()
{
	_is_button_pressed = false;
	SetColor(sf::Color::Red);
}

bool Buttons::SaveButton::IsButtonPressed() const
{
	return _is_button_pressed;
}

sf::FloatRect Buttons::SaveButton::GetGlobalBounds()
{
	return _rectangle.getGlobalBounds();
}

