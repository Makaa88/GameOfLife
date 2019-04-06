#pragma once
#include "Button.h"

namespace Buttons
{
	class BackwardButton : public Button
	{
	public:
		BackwardButton();
		void CreateShape() override;
		void DrawShape(sf::RenderWindow &window) override;
		void PressButton() override;
		void ReleaseButton() override;
		void Disable();
		bool IsButtonPressed() const override;
		sf::FloatRect GetGlobalBounds() override;

	protected:
		void SetColor(const sf::Color& color) override;
	private:
		sf::RectangleShape _rectangle;
		sf::ConvexShape _play_left;
		sf::ConvexShape _play_right;
	};
}