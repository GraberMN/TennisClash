// Thanks to Prof. Joshua Fox for introducing me to TextureManager
#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
using std::unordered_map, std::string;

class TextureManager
{
	// static == one and only one in memory always
	static unordered_map<string, sf::Texture> textures;
public:
	static void LoadTexture(string textureName);
	static sf::Texture& GetTexture(string textureName);
	static void Clear(); // Call this once at the end of main()
};