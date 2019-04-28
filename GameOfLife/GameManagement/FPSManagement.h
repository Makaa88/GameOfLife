#pragma once
#include <SFML/Graphics.hpp>

class FPSManagement
{
public:
	FPSManagement();
	float GetFPS() const;
	void SetFPS(const float fps);

private:
	float _fps_per_second = 30;
	sf::Time _start_time;
	sf::Time _end_time;

	static sf::Clock _clock;
};