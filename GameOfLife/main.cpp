#include <SFML/Window.hpp>
#include "main.h"

void CheckIfButtonPressed(std::vector<Buttons::Button*>& buttons, sf::Event& event)
{
	int x = event.mouseButton.x;
	int y = event.mouseButton.y;

	if ((x >= 250) && (x <= 515) && (y >= 50) && (y <= 100))
	{
		std::cout << "inniinin" << std::endl;
		for (auto b : buttons)
		{
			b->ReleaseButton();
		}

		for (auto b : buttons)
		{
			if (b->GetGlobalBounds().contains(x, y))
			{
				b->PressButton();
				break;
			}
		}
	}

}


int main()
{
	int width = 1000;
	int height = 800;
	sf::RenderWindow window(sf::VideoMode(width, height), "GameOfLife", sf::Style::Titlebar | sf::Style::Close);
	window.clear(sf::Color::Black);
	sf::Event event;

	FileManagement::FileReader file{ "glider.rle" };
	Game game(file.GetWidth(), file.GetHeight(), file.GetPreset());

	Buttons::PlayButton play_button{};
	Buttons::StopButton stop_button{};
	Buttons::ForwardButton forward_button{};
	Buttons::BackwardButton backward_button{};
	std::vector<Buttons::Button*> buttons = { &play_button, &stop_button, &forward_button, &backward_button };



	while (window.isOpen())
	{
		window.clear(sf::Color::Black);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::MouseMoved)
			{
				std::cout << event.mouseMove.x << " " << event.mouseMove.y << std::endl;
			}
			if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left))
			{
				CheckIfButtonPressed(buttons, event);
			}
		}
		
		if (play_button.IsButtonPressed())
			game.ProccedNextIteration();
		else if (forward_button.IsButtonPressed())
		{
			game.Forward();
			forward_button.Disable();
		}
		else if (backward_button.IsButtonPressed())
		{
			game.Backward();
			backward_button.Disable();
		}

	///	window.draw(circle);
		//window.display();
		for (auto button : buttons)
		{
			button->DrawShape(window);
		}
		game.DrawBoard(window);
		window.display();
	}

	return 0;
}