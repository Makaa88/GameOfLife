#include <SFML/Window.hpp>
#include "main.h"

// B5 606
constexpr float DURATION = 15. / 60; //constexpr

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

std::string ChosePreset(sf::Font &font)
{
	sf::RenderWindow chose_window(sf::VideoMode(1000, 800), "GameOfLife", sf::Style::Titlebar | sf::Style::Close);
	sf::Event event;
	chose_window.clear(sf::Color::Black);


	std::vector<RLEFileText> texts = { /*0*/ RLEFileText{"My Saved Pattern", font},
								/*1*/	RLEFileText{"Glider", font},
								/*2*/	RLEFileText{"Queen Bee Shattle",font},
								/*3*/	RLEFileText{ "Blinker",font },
								/*4*/	RLEFileText{ "Boss",font },
								/*5*/	RLEFileText{"Gosper Glider Gun", font} };

	const int x = 450;
	int y = 200;
	for (auto& text : texts) //for range loop, auto keyword
	{
		text.SetPosition(x, y);
		y += 30;
	}

	while (chose_window.isOpen())
	{
		chose_window.clear(sf::Color::Black);
		if (chose_window.pollEvent(event))
		{
			if (event.key.code == sf::Keyboard::Num0)
			{
				chose_window.close();
				return texts.at(0).GetPath();
			}
			if (event.key.code == sf::Keyboard::Num1)
			{
				chose_window.close();
				return texts.at(1).GetPath();
			}
			else if (event.key.code == sf::Keyboard::Num2)
			{
				chose_window.close();
				return texts.at(2).GetPath();
			}
			else if (event.key.code == sf::Keyboard::Num3)
			{
				chose_window.close();
				return texts.at(3).GetPath();
			}
			else if (event.key.code == sf::Keyboard::Num4)
			{
				chose_window.close();
				return texts.at(4).GetPath();
			}
			else if (event.key.code == sf::Keyboard::Num5)
			{
				chose_window.close();
				return texts.at(5).GetPath();
			}
		}

		for (auto& text : texts)  //for range loop, auto keyword
		{
			chose_window.draw(text.GetText());
		}
		chose_window.display();

	}



}

int main()
{
	sf::Font font;
	font.loadFromFile("Welbut__.ttf");
	std::string path = ChosePreset(font);
	sf::RenderWindow window(sf::VideoMode(1000, 800), "GameOfLife", sf::Style::Titlebar | sf::Style::Close);
	window.clear(sf::Color::Black);
	sf::Event event;

	FileManagement::FileReader file{ path };
	Game game(file.GetWidth(), file.GetHeight(), file.GetPreset());

	Buttons::PlayButton play_button{}; //initialization list
	Buttons::StopButton stop_button{};
	Buttons::ForwardButton forward_button{};
	Buttons::BackwardButton backward_button{};
	Buttons::SaveButton save_button{ font };
	std::vector<Buttons::Button*> buttons = { &play_button, &stop_button, &forward_button, &backward_button, &save_button };

	sf::Clock clock;
	sf::Clock fps_clock;
	sf::Time start_time = clock.getElapsedTime();
	sf::Time end_time = start_time;

	sf::Time fps_time = start_time;

	sf::Text fps_text;
	fps_text.setCharacterSize(12);
	fps_text.setFont(font);
	fps_text.setFillColor(sf::Color::White);
	fps_text.setPosition(20, 30);


	window.setFramerateLimit(60);

	int fps_counter = 0;
	while (window.isOpen())
	{
		window.clear(sf::Color::Black);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::TextEntered)
			{
				std::cout << "Text entered: " <<static_cast<char>(event.text.unicode) << std::endl;
			}
			if (event.type == sf::Event::MouseMoved)
			{
				std::cout << event.mouseMove.x << " " << event.mouseMove.y << std::endl;
			}
			if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left))
			{
				CheckIfButtonPressed(buttons, event);
				if ((event.mouseButton.x >= 600) && (event.mouseButton.x <= 720) && (event.mouseButton.y >= 50)
					&& (event.mouseButton.y <= 100) && !play_button.IsButtonPressed())
				{
					save_button.PressButton();
					game.SavePattern();
				}
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

		for (auto button : buttons) //range for loop, auto keyword
		{
			button->DrawShape(window);
		}
		game.DrawBoard(window);
		if (fps_clock.getElapsedTime().asSeconds() - fps_time.asSeconds() > 1)
		{
			fps_text.setString(std::to_string(fps_counter));
			fps_counter = 0;
			fps_time = fps_clock.getElapsedTime();
		}
		
		window.draw(fps_text);
		window.display();
		fps_counter++;
		end_time = clock.getElapsedTime();
	}

	return 0;
}