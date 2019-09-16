#pragma once
#include "Mode.hpp"
#include <SFML/Graphics.hpp>

class MenuMode : public Mode
{
public:
	MenuMode(std::mutex* mutex);
	virtual std::pair<ModeAction, ModeOption> Run(sf::Time, sf::RenderWindow&) override;
private:
	void processKeys(sf::Keyboard::Key, bool);
private:
	std::map<std::string, bool> mKeys;
};