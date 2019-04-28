#include "StopButton.h"
namespace Buttons
{

	StopButton::StopButton()
	{
		_is_button_pressed = false;
		CreateShape();
		SetColor(sf::Color::White);
	}

	void StopButton::CreateShape()
	{
		_rectangle.setFillColor(sf::Color::Transparent);
		_rectangle.setPosition(305, 50);
		_rectangle.setSize(sf::Vector2f(35, 50));

		_left_rectangle.setPosition(305, 50);
		_left_rectangle.setSize(sf::Vector2f(15, 50));

		_right_rectangle.setPosition(sf::Vector2f(325, 50));
		_right_rectangle.setSize(sf::Vector2f(15, 50));
	}

	void StopButton::SetColor(const sf::Color &color)
	{
		_right_rectangle.setFillColor(color);
		_left_rectangle.setFillColor(color);
	}

	void StopButton::DrawShape(sf::RenderWindow  &window)
	{
		window.draw(_rectangle);
		window.draw(_left_rectangle);
		window.draw(_right_rectangle);
	}

	void StopButton::PressButton()
	{
		_is_button_pressed = true;
		SetColor(sf::Color::Red);
	}

	void StopButton::ReleaseButton()
	{
		_is_button_pressed = false;
		SetColor(sf::Color::White);
	}

	bool StopButton::IsButtonPressed() const
	{
		return _is_button_pressed;
	}
	sf::FloatRect StopButton::GetGlobalBounds()
	{
		return _rectangle.getGlobalBounds();
	}
}
