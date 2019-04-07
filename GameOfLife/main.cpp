#include <SFML/Window.hpp>
#include "main.h"

constexpr float DURATION = 15. / 60;

void CheckIfButtonPressed(std::vector<Buttons::Button*>& buttons, sf::Event& event)
{
	int x = event.mouseButton.x;
	int y = event.mouseButton.y;

	if ((x >= 250) && (x <= 515) && (y >= 50) && (y <= 100))
	{
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

std::string ChosePreset()
{
	sf::RenderWindow chose_window(sf::VideoMode(1000, 800), "GameOfLife", sf::Style::Titlebar | sf::Style::Close);
	sf::Event event;
	chose_window.clear(sf::Color::Black);
	sf::Font font;
	font.loadFromFile("Welbut__.ttf");

	std::vector<RLEFileText> texts = { RLEFileText{"Glider", font},
									RLEFileText{"Queen Bee Shattle",font},
									RLEFileText{ "Blinker",font },RLEFileText{ "Boss",font } };

	const int x = 450;
	int y = 200;
	for (auto& text : texts)
	{
		text.SetPosition(x, y);
		y += 30;
	}

	while (chose_window.isOpen())
	{
		chose_window.clear(sf::Color::Black);
		if (chose_window.pollEvent(event))
		{
			if (event.key.code == sf::Keyboard::Num1)
			{
				chose_window.close();
				return texts.at(0).GetPath();
			}
			else if (event.key.code == sf::Keyboard::Num2)
			{
				chose_window.close();
				return texts.at(1).GetPath();
			}
			else if (event.key.code == sf::Keyboard::Num3)
			{
				chose_window.close();
				return texts.at(2).GetPath();
			}
			else if (event.key.code == sf::Keyboard::Num4)
			{
				chose_window.close();
				return texts.at(3).GetPath();
			}
		}

		for (auto& text : texts)
		{
			chose_window.draw(text.GetText());
		}
		chose_window.display();

	}



}

int main()
{
	std::string path = ChosePreset();
	sf::RenderWindow window(sf::VideoMode(1000, 800), "GameOfLife", sf::Style::Titlebar | sf::Style::Close);
	window.clear(sf::Color::Black);
	sf::Event event;

	FileManagement::FileReader file{ path };
	Game game(file.GetWidth(), file.GetHeight(), file.GetPreset());

	Buttons::PlayButton play_button{};
	Buttons::StopButton stop_button{};
	Buttons::ForwardButton forward_button{};
	Buttons::BackwardButton backward_button{};
	std::vector<Buttons::Button*> buttons = { &play_button, &stop_button, &forward_button, &backward_button };

	sf::Clock clock;
	sf::Time start_time = clock.getElapsedTime();
	sf::Time end_time = start_time;



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
		
		if (play_button.IsButtonPressed() && ((end_time.asSeconds() - start_time.asSeconds()) > DURATION))
		{
			game.ProccedNextIteration();
			clock.restart();
			start_time = clock.getElapsedTime();
		}
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

		end_time = clock.getElapsedTime();
	}

	return 0;
}