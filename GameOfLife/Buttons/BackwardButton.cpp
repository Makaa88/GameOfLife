#include "BackwardButton.h"

namespace Buttons
{
	BackwardButton::BackwardButton()
	{
		_is_button_pressed = false;
		CreateShape();
		SetColor(sf::Color::White);
	}

	void BackwardButton::CreateShape()
	{
		_rectangle.setPosition(sf::Vector2f(445, 50));
		_rectangle.setSize(sf::Vector2f(75, 50));

		_play_left.setPointCount(3);
		_play_left.setPoint(0, sf::Vector2f(480, 50));
		_play_left.setPoint(1, sf::Vector2f(445, 75));
		_play_left.setPoint(2, sf::Vector2f(480, 100));

		_play_right.setPointCount(3);
		_play_right.setPoint(0, sf::Vector2f(515, 50));
		_play_right.setPoint(1, sf::Vector2f(480, 75));
		_play_right.setPoint(2, sf::Vector2f(515, 100));
	}

	void BackwardButton::DrawShape(sf::RenderWindow &window)
	{
		window.draw(_rectangle);
		window.draw(_play_left);
		window.draw(_play_right);
	}

	void BackwardButton::SetColor(const sf::Color& color)
	{
		_rectangle.setFillColor(sf::Color::Transparent);
		_play_left.setFillColor(color);
		_play_right.setFillColor(color);
	}

	void BackwardButton::PressButton()
	{
		_is_button_pressed = true;
		SetColor(sf::Color::Blue);
	}

	void BackwardButton::ReleaseButton()
	{
		_is_button_pressed = false;
		SetColor(sf::Color::White);
	}

	void BackwardButton::Disable()
	{
		_is_button_pressed = false;
	}

	bool BackwardButton::IsButtonPressed() const
	{
		return _is_button_pressed;
	}
	sf::FloatRect BackwardButton::GetGlobalBounds()
	{
		return _rectangle.getGlobalBounds();
	}
}
