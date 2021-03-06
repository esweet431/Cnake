#include "Settings.hpp"
#include <fstream>
#include <iostream>
#include <string>

Settings::Settings(sf::RenderWindow* win) : window{ win } {
	std::fstream file;
	file.open("assets/settings.txt", std::ios::in);
	std::string line;
	if (!file.fail()) { // Load from existing file
		std::getline(file, line, '\n');
		std::getline(file, line, '\n');
		if (line == "true") {
			fpsLock = true;
			win->setFramerateLimit(60);
		} else {
			fpsLock = false;
			win->setFramerateLimit(0);
		}
		std::getline(file, line, '\n');
		std::getline(file, line, '\n');
		gameSpeed = std::stof(line);
	} else { // Create file if one does not exist
		file.open("assets/settings.txt", std::ios::out);
		file << "# fpslock\n" << "false\n" << "# gamespeed\n" << ".10f\n";
		fpsLock = false;
		gameSpeed = .10f; //
	}
	file.close();
}

void Settings::setFpsLock(bool temp) {
	fpsLock = temp;
	if (fpsLock)
		window->setFramerateLimit(60);
	else
		window->setFramerateLimit(0);
}

void Settings::saveToFile() {
	std::fstream file;
	file.open("assets/settings.txt", std::ios::out);
	file << "# fpslock\n";
	if (fpsLock) {
		file << "true\n";
	} else {
		file << "false\n";
	}
	file << "# gamespeed\n";
	file << std::to_string(gameSpeed);
	file.close();
}