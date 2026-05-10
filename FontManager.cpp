#include "FontManager.h"

// "redeclare" static variable, so this file knows it exists and can use it
unordered_map<string, sf::Font> FontManager::fonts;

void FontManager::LoadFont(string fontName) {
	string path = "fonts/" + fontName + ".ttf";
	fonts[fontName].loadFromFile(path);
}

sf::Font& FontManager::GetFont(string fontName) {
	// if the font doesn't exist
	if (fonts.find(fontName) == fonts.end())
		LoadFont(fontName);
	return fonts[fontName];
}

void FontManager::Clear() {
	fonts.clear(); // gets rid of all stored sf::Font objects
}