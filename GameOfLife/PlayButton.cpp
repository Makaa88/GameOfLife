#include "PlayButton.h"

namespace Buttons
{
	PlayButton::PlayButton()
	{
		_is_button_pressed = false;
		CreateShape();
		SetColor(sf::Color::White);
	}

	void PlayButton::CreateShape()
	{
		_rectangle.setPosition(250, 50);
		_rectangle.setSize(sf::Vector2f(35, 50));


		_play.setPointCount(3);
		_play.setPoint(0, sf::Vector2f(250, 50));
		_play.setPoint(1, sf::Vector2f(285, 75));
		_play.setPoint(2, sf::Vector2f(250, 100));
	}

	void PlayButton::SetColor(const sf::Color & color)
	{
		_rectangle.setFillColor(sf::Color::Transparent);
		_play.setFillColor(color);
	}

	void PlayButton::DrawShape(sf::RenderWindow & window)
	{
		window.draw(_play);
	}

	void PlayButton::PressButton()
	{
		_is_button_pressed = true;
		SetColor(sf::Color::Green);
	}

	void PlayButton::ReleaseButton()
	{
		_is_button_pressed = false;
		SetColor(sf::Color::White);
	}

	bool PlayButton::IsButtonPressed() const
	{
		return _is_button_pressed;
	}
	sf::FloatRect PlayButton::GetGlobalBounds()
	{
		return _rectangle.getGlobalBounds();
	}
}
