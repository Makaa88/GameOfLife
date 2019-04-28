#pragma once

#include "Button.h"

class Game;

namespace Buttons
{
	class SaveButton : public Button
	{
	public:
		friend class Game;
		SaveButton(sf::Font &font);
		void CreateShape() override;
		void DrawShape(sf::RenderWindow &window) override;
		void PressButton() override;
		void ReleaseButton() override;
		bool IsButtonPressed() const override;
		sf::FloatRect GetGlobalBounds() override;

	protected:
		void SetColor(const sf::Color& color) override;
	
	private:
		sf::RectangleShape _rectangle;
		sf::Text _text;
	};
}