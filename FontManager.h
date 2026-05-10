#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
using std::unordered_map, std::string;

class FontManager
{
	// static == one and only one in memory always
	static unordered_map<string, sf::Font> fonts;
public:
	static void LoadFont(string fontName);
	static sf::Font& GetFont(string fontName);
	static void Clear(); // Call this once at the end of main()
};