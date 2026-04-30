// TennisClash.cpp : Defines the entry point for the application.
//

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TennisClash.h"
#include "TextureManager.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 600), "Tennis Clash");
   

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.display();
    }

    // Clear out any sf::Texture objects before the program ends
    TextureManager::Clear();

	return 0;
}
