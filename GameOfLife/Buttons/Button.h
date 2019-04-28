#pragma once
#include <SFML/Graphics.hpp>

namespace Buttons
{
	class Button
	{
	public:
		Button() = default;
		~Button() = default;
		virtual void CreateShape() = 0;
		virtual void DrawShape(sf::RenderWindow& window) = 0;
		virtual void PressButton() = 0;
		virtual void ReleaseButton() = 0;
		virtual bool IsButtonPressed() const = 0;
		virtual sf::FloatRect GetGlobalBounds() = 0;
		
	protected:
		virtual void SetColor(const sf::Color& color) = 0;
		bool _is_button_pressed;
	};
}