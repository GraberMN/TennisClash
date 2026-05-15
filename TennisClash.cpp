// TennisClash.cpp : Defines the entry point for the application.
//

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TennisClash.h"
#include "TextureManager.h"
#include "SoundBufferManager.h"
#include "FontManager.h"

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

void DrawRulesPage(sf::RenderWindow& window, bool& isMuted, unordered_map<string, sf::Sprite>& sprites, unordered_map<string, sf::Text>& texts) {
    window.draw(sprites["grassCourt"]);
    window.draw(sprites["title"]);
    window.draw(sprites["pageBackground"]);
    window.draw(sprites["closeButton"]);
    window.draw(texts["rulesTitle"]);
    DrawMuted(window, isMuted, sprites);
}

void DrawOptionsPage(sf::RenderWindow& window, bool& isMuted, unordered_map<string, sf::Sprite>& sprites, unordered_map<string, sf::Text>& texts) {
    window.draw(sprites["grassCourt"]);
    window.draw(sprites["title"]);
    window.draw(sprites["pageBackground"]);
    window.draw(sprites["closeButton"]);
    window.draw(texts["optionsTitle"]);
    DrawMuted(window, isMuted, sprites);
}

void DrawCreditsPage(sf::RenderWindow& window, bool& isMuted, unordered_map<string, sf::Sprite>& sprites, unordered_map<string, sf::Text>& texts) {
    window.draw(sprites["grassCourt"]);
    window.draw(sprites["title"]);
    window.draw(sprites["pageBackground"]);
    window.draw(sprites["closeButton"]);
    window.draw(texts["creditsTitle"]);
    DrawMuted(window, isMuted, sprites);
}

void DrawCharacterSelectScreen(sf::RenderWindow& window, bool& isMuted, unordered_map<string, sf::Sprite>& sprites) {
    window.draw(sprites["characterSelect"]);
    window.draw(sprites["dashCharacterModelSelected"]);
    window.draw(sprites["swiftCharacterModel"]);
    window.draw(sprites["heftyCharacterModel"]);
    DrawMuted(window, isMuted, sprites);
}

int main()
{
    // window + sprite + sound/music + text initializations
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
    sf::Sprite pageBackground(TextureManager::GetTexture("pageBackground"));
    pageBackground.setPosition(150.f, 100.f);
    sf::Sprite closeButton(TextureManager::GetTexture("closeButton"));
    closeButton.setPosition(715.f, 100.f);
    sf::Sprite characterSelect(TextureManager::GetTexture("characterSelect"));
    sf::Sprite dashCharacterModel(TextureManager::GetTexture("dashCharacterModel"));
    dashCharacterModel.setPosition(0.f, 150.f);
    sf::Sprite dashCharacterModelSelected(TextureManager::GetTexture("dashCharacterModelSelected"));
    dashCharacterModelSelected.setPosition(0.f, 150.f);
    sf::Sprite swiftCharacterModel(TextureManager::GetTexture("swiftCharacterModel"));
    swiftCharacterModel.setPosition(250.f, 150.f);
    sf::Sprite swiftCharacterModelSelected(TextureManager::GetTexture("swiftCharacterModelSelected"));
    swiftCharacterModelSelected.setPosition(250.f, 150.f);
    sf::Sprite heftyCharacterModel(TextureManager::GetTexture("heftyCharacterModel"));
    heftyCharacterModel.setPosition(500.f, 150.f);
    sf::Sprite heftyCharacterModelSelected(TextureManager::GetTexture("heftyCharacterModelSelected"));
    heftyCharacterModelSelected.setPosition(500.f, 150.f);

    sf::RectangleShape tempBackground(sf::Vector2f(900.f, 600.f));
    tempBackground.setFillColor(sf::Color::White);

    sf::Sound magicButtonClick(SoundBufferManager::GetSoundBuffer("magicButtonClick"));

    sf::Music backgroundMusic;
    backgroundMusic.openFromFile("audio/backgroundMusic.wav");
    backgroundMusic.setLoop(true);
    backgroundMusic.play();

    sf::Text rulesTitle;
    rulesTitle.setFont(FontManager::GetFont("lochleyPixel"));
    rulesTitle.setString("Rules");
    rulesTitle.setCharacterSize(50);
    rulesTitle.setFillColor(sf::Color::Black);
    rulesTitle.setPosition(165.f, 100.f);

    sf::Text optionsTitle;
    optionsTitle.setFont(FontManager::GetFont("lochleyPixel"));
    optionsTitle.setString("Options");
    optionsTitle.setCharacterSize(50);
    optionsTitle.setFillColor(sf::Color::Black);
    optionsTitle.setPosition(165.f, 100.f);

    sf::Text creditsTitle;
    creditsTitle.setFont(FontManager::GetFont("lochleyPixel"));
    creditsTitle.setString("Credits");
    creditsTitle.setCharacterSize(50);
    creditsTitle.setFillColor(sf::Color::Black);
    creditsTitle.setPosition(165.f, 100.f);

    // putting sprites, sounds, and texts into containers
    unordered_map<string, sf::Sprite> sprites;
    sprites.emplace("title", title);
    sprites.emplace("playButton", playButton);
    sprites.emplace("rulesButton", rulesButton);
    sprites.emplace("optionsButton", optionsButton);
    sprites.emplace("volumeButton", volumeButton);
    sprites.emplace("mutedButton", mutedButton);
    sprites.emplace("creditsButton", creditsButton);
    sprites.emplace("grassCourt", grassCourt);
    sprites.emplace("pageBackground", pageBackground);
    sprites.emplace("closeButton", closeButton);
    sprites.emplace("characterSelect", characterSelect);
    sprites.emplace("dashCharacterModel", dashCharacterModel);
    sprites.emplace("dashCharacterModelSelected", dashCharacterModelSelected);
    sprites.emplace("swiftCharacterModel", swiftCharacterModel);
    sprites.emplace("swiftCharacterModelSelected", swiftCharacterModelSelected);
    sprites.emplace("heftyCharacterModel", heftyCharacterModel);
    sprites.emplace("heftyCharacterModelSelected", heftyCharacterModelSelected);

    unordered_map<string, sf::Sound> sounds;
    sounds.emplace("magicButtonClick", magicButtonClick);

    unordered_map<string, sf::Text> texts;
    texts.emplace("rulesTitle", rulesTitle);
    texts.emplace("optionsTitle", optionsTitle);
    texts.emplace("creditsTitle", creditsTitle);
       
    // boolean variable initializations
    bool isMuted = false;
    bool isTitleScreen = true;
    bool isRulesPage = false;
    bool isOptionsPage = false;
    bool isCreditsPage = false;
    bool isCharacterSelectScreen = false;

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
                    if (playButton.getGlobalBounds().contains(mousePos.x, mousePos.y) && isTitleScreen) {
                        magicButtonClick.play();
                        isCharacterSelectScreen = true;
                        isTitleScreen = false;
                    }
                    if (rulesButton.getGlobalBounds().contains(mousePos.x, mousePos.y) && isTitleScreen) {
                        magicButtonClick.play();
                        isRulesPage = true;
                        isTitleScreen = false;
                        isOptionsPage = false;
                        isCreditsPage = false;
                    }
                    if (optionsButton.getGlobalBounds().contains(mousePos.x, mousePos.y) && isTitleScreen) {
                        magicButtonClick.play();
                        isOptionsPage = true;
                        isTitleScreen = false;
                        isRulesPage = false;
                        isCreditsPage = false;
                    }
                    if (creditsButton.getGlobalBounds().contains(mousePos.x, mousePos.y) && isTitleScreen) {
                        magicButtonClick.play();
                        isCreditsPage = true;
                        isTitleScreen = false;
                        isRulesPage = false;
                        isOptionsPage = false;
                    }
                    if (closeButton.getGlobalBounds().contains(mousePos.x, mousePos.y) && (isRulesPage || isOptionsPage || isCreditsPage)) {
                        isTitleScreen = true;
                        isRulesPage = false;
                        isOptionsPage = false;
                        isCreditsPage = false;
                    }
                }
            }
        }

        window.clear();
        if (isTitleScreen)
            DrawTitleScreen(window, isMuted, sprites);
        if (isRulesPage)
            DrawRulesPage(window, isMuted, sprites, texts);
        if (isOptionsPage)
            DrawOptionsPage(window, isMuted, sprites, texts);
        if (isCreditsPage)
            DrawCreditsPage(window, isMuted, sprites, texts);
        if (isCharacterSelectScreen)
            DrawCharacterSelectScreen(window, isMuted, sprites);
        
        window.display();
    }

    // Clear out any sf::Texture objects before the program ends
    TextureManager::Clear();

    // Clear out any sf::SoundBuffer objects before the program ends
    SoundBufferManager::Clear();

    // Clear out any sf::Font objects before the program ends
    FontManager::Clear();

	return 0;
}
