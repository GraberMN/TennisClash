#include "SoundBufferManager.h"

// "redeclare" static variable, so this file knows it exists and can use it
unordered_map<string, sf::SoundBuffer> SoundBufferManager::soundBuffers;

void SoundBufferManager::LoadSoundBuffer(string soundBufferName) {
	string path = "audio/" + soundBufferName + ".wav";
	soundBuffers[soundBufferName].loadFromFile(path);
}

sf::SoundBuffer& SoundBufferManager::GetSoundBuffer(string soundBufferName) {
	if (soundBuffers.find(soundBufferName) == soundBuffers.end())
		LoadSoundBuffer(soundBufferName);
	return soundBuffers[soundBufferName];
}

void SoundBufferManager::Clear() {
	soundBuffers.clear(); // gets rid of all stored sf::SoundBuffer objects
}