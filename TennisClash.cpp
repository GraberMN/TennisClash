// TennisClash.cpp : Defines the entry point for the application.
//

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TennisClash.h"
#include "TextureManager.h"

using namespace std;

int main()
{
    // window + sprite initializations
    sf::RenderWindow window(sf::VideoMode(900, 600), "Tennis Clash");

    sf::Sprite title(TextureManager::GetTexture("title"));
    sf::Sprite playButton(TextureManager::GetTexture("playButton"));
    playButton.setPosition(325.f, 230.f);
    sf::Sprite rulesButton(TextureManager::GetTexture("rulesButton"));
    rulesButton.setPosition(325.f, 340.f);
    sf::Sprite optionsButton(TextureManager::GetTexture("optionsButton"));
    optionsButton.setPosition(325.f, 450.f);

    sf::RectangleShape tempBackground(sf::Vector2f(900.f, 600.f));
    tempBackground.setFillColor(sf::Color::White);

    // make the window come to life
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(tempBackground);
        window.draw(title);
        window.draw(playButton);
        window.draw(rulesButton);
        window.draw(optionsButton);
        
        window.display();
    }

    // Clear out any sf::Texture objects before the program ends
    TextureManager::Clear();

	return 0;
}
