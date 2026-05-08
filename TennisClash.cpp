// TennisClash.cpp : Defines the entry point for the application.
//

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TennisClash.h"
#include "TextureManager.h"
#include "SoundBufferManager.h"

using namespace std;

void ToggleMuted(bool& isMuted) {
    isMuted = !isMuted;
}

void DrawMuted(sf::RenderWindow& window, bool& isMuted, unordered_map<string, sf::Sprite>& sprites) {
    if (isMuted)
        window.draw(sprites["mutedButton"]);
    else
        window.draw(sprites["volumeButton"]);
}

void HandleBackgroundMusic(bool& isMuted, sf::Music& backgroundMusic) {
    if (isMuted)
        backgroundMusic.stop();
    else
        backgroundMusic.play();
}

void DrawTitleScreen(sf::RenderWindow& window, bool& isMuted, unordered_map<string, sf::Sprite>& sprites) {
    window.draw(sprites["grassCourt"]);
    window.draw(sprites["title"]);
    window.draw(sprites["playButton"]);
    window.draw(sprites["rulesButton"]);
    window.draw(sprites["optionsButton"]);
    window.draw(sprites["creditsButton"]);
    DrawMuted(window, isMuted, sprites);
}

int main()
{
    // window + sprite + sound/music initializations
    sf::RenderWindow window(sf::VideoMode(900, 600), "Tennis Clash");

    sf::Sprite title(TextureManager::GetTexture("title"));
    sf::Sprite playButton(TextureManager::GetTexture("playButton"));
    playButton.setPosition(325.f, 230.f);
    sf::Sprite rulesButton(TextureManager::GetTexture("rulesButton"));
    rulesButton.setPosition(325.f, 340.f);
    sf::Sprite optionsButton(TextureManager::GetTexture("optionsButton"));
    optionsButton.setPosition(325.f, 450.f);
    sf::Sprite volumeButton(TextureManager::GetTexture("volumeButton"));
    volumeButton.setPosition(840.f, 545.f);
    sf::Sprite mutedButton(TextureManager::GetTexture("mutedButton"));
    mutedButton.setPosition(840.f, 545.f);
    sf::Sprite creditsButton(TextureManager::GetTexture("creditsButton"));
    creditsButton.setPosition(0.f, 565.f);
    sf::Sprite grassCourt(TextureManager::GetTexture("grassCourt"));

    sf::RectangleShape tempBackground(sf::Vector2f(900.f, 600.f));
    tempBackground.setFillColor(sf::Color::White);

    sf::Music backgroundMusic;
    backgroundMusic.openFromFile("audio/backgroundMusic.wav");
    backgroundMusic.setLoop(true);
    backgroundMusic.play();

    // putting sprites and sounds into containers
    unordered_map<string, sf::Sprite> sprites;
    sprites.emplace("title", title);
    sprites.emplace("playButton", playButton);
    sprites.emplace("rulesButton", rulesButton);
    sprites.emplace("optionsButton", optionsButton);
    sprites.emplace("volumeButton", volumeButton);
    sprites.emplace("mutedButton", mutedButton);
    sprites.emplace("creditsButton", creditsButton);
    sprites.emplace("grassCourt", grassCourt);

    // boolean variable initializations
    bool isMuted = false;
    bool isTitleScreen = true;

    // make the window come to life
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos((float)event.mouseButton.x, (float)event.mouseButton.y);
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (volumeButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        ToggleMuted(isMuted);
                        HandleBackgroundMusic(isMuted, backgroundMusic);
                    }
                }
            }
        }

        window.clear();
        if (isTitleScreen)
            DrawTitleScreen(window, isMuted, sprites);
        
        window.display();
    }

    // Clear out any sf::Texture objects before the program ends
    TextureManager::Clear();

    // Clear out any sf::SoundBuffer objects before the program ends
    SoundBufferManager::Clear();

	return 0;
}
