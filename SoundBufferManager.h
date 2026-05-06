#pragma once
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <string>
using std::unordered_map, std::string;

class SoundBufferManager
{
	// static == one and only one in memory always
	static unordered_map<string, sf::SoundBuffer> soundBuffers;
public:
	static void LoadSoundBuffer(string soundBufferName);
	static sf::SoundBuffer& GetSoundBuffer(string soundBufferName);
	static void Clear(); // Call this once at the end of main()
};