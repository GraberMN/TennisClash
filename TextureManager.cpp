// Thanks to Prof. Joshua Fox for introducing me to TextureManager
#include "TextureManager.h"

// "redeclare" static variable, so this file knows it exists and can use it
unordered_map<string, sf::Texture> TextureManager::textures;

void TextureManager::LoadTexture(string textureName) {
	string path = "images/" + textureName + ".png";
	textures[textureName].loadFromFile(path);
}

sf::Texture& TextureManager::GetTexture(string textureName) {
	// if the texture doesn't exist
	if (textures.find(textureName) == textures.end()) 
		LoadTexture(textureName);
	return textures[textureName];
}

void TextureManager::Clear() {
	textures.clear(); // gets rid of all stored sf::Texture objects
}