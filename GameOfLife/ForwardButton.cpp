#include "ForwardButton.h"

namespace Buttons
{
	ForwardButton::ForwardButton()
	{
		_is_button_pressed = false;
		CreateShape();
		SetColor(sf::Color::White);
	}

	void ForwardButton::Disable()
	{
		_is_button_pressed = false;
	}

	void ForwardButton::CreateShape()
	{
		_rectangle.setPosition(sf::Vector2f(355, 50));
		_rectangle.setSize(sf::Vector2f(75, 50));

		_play_left.setPointCount(3);
		_play_left.setPoint(0, sf::Vector2f(355, 50));
		_play_left.setPoint(1, sf::Vector2f(390, 75));
		_play_left.setPoint(2, sf::Vector2f(355, 100));

		_play_right.setPointCount(3);
		_play_right.setPoint(0, sf::Vector2f(390, 50));
		_play_right.setPoint(1, sf::Vector2f(425, 75));
		_play_right.setPoint(2, sf::Vector2f(390, 100));

	}

	void ForwardButton::SetColor(const sf::Color &color)
	{
		_rectangle.setFillColor(sf::Color::Transparent);
		_play_left.setFillColor(color);
		_play_right.setFillColor(color);
	}

	void ForwardButton::DrawShape(sf::RenderWindow &window)
	{
		window.draw(_rectangle);
		window.draw(_play_left);
		window.draw(_play_right);
	}

	void ForwardButton::PressButton()
	{
		_is_button_pressed = true;
		SetColor(sf::Color::Red);
	}

	void ForwardButton::ReleaseButton()
	{
		_is_button_pressed = false;
		SetColor(sf::Color::White);
	}

	bool ForwardButton::IsButtonPressed() const
	{
		return _is_button_pressed;
	}
	sf::FloatRect ForwardButton::GetGlobalBounds()
	{
		return _rectangle.getGlobalBounds();
	}
}
