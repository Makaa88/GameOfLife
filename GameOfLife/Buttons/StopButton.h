#pragma once
#include "Button.h"

namespace Buttons
{
	class StopButton : public Button
	{
	public:
		StopButton();
		void CreateShape() override;
		void DrawShape(sf::RenderWindow &window) override;
		void PressButton() override;
		void ReleaseButton() override;
		bool IsButtonPressed() const override;
		sf::FloatRect GetGlobalBounds() override;

	protected:
		void SetColor(const sf::Color& color) override;

	private:
		sf::RectangleShape _left_rectangle;
		sf::RectangleShape _right_rectangle;
		sf::RectangleShape _rectangle;
	};
}