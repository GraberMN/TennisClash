// TennisClash.cpp : Defines the entry point for the application.
//

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TennisClash.h"
#include "TextureManager.h"
#include "SoundBufferManager.h"
#include "FontManager.h"
#include "Random.h"

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

void DrawSelectedCharacter(sf::RenderWindow& window, int& characterSelected, unordered_map<string, sf::Sprite>& sprites) {
    if (characterSelected == 1) {
        window.draw(sprites["dashCharacterModelSelected"]);
        window.draw(sprites["swiftCharacterModel"]);
        window.draw(sprites["heftyCharacterModel"]);
        window.draw(sprites["athenaCharacterModel"]);
        window.draw(sprites["joeCharacterModel"]);
        window.draw(sprites["janeCharacterModel"]);
        window.draw(sprites["dashStats"]);
        window.draw(sprites["dashMiniModel"]);
    }
    else if (characterSelected == 2) {
        window.draw(sprites["dashCharacterModel"]);
        window.draw(sprites["swiftCharacterModelSelected"]);
        window.draw(sprites["heftyCharacterModel"]);
        window.draw(sprites["athenaCharacterModel"]);
        window.draw(sprites["joeCharacterModel"]);
        window.draw(sprites["janeCharacterModel"]);
        window.draw(sprites["swiftStats"]);
        window.draw(sprites["swiftMiniModel"]);
    }
    else if (characterSelected == 3) {
        window.draw(sprites["dashCharacterModel"]);
        window.draw(sprites["swiftCharacterModel"]);
        window.draw(sprites["heftyCharacterModelSelected"]);
        window.draw(sprites["athenaCharacterModel"]);
        window.draw(sprites["joeCharacterModel"]);
        window.draw(sprites["janeCharacterModel"]);
        window.draw(sprites["heftyStats"]);
        window.draw(sprites["heftyMiniModel"]);
    }
    else if (characterSelected == 4) {
        window.draw(sprites["dashCharacterModel"]);
        window.draw(sprites["swiftCharacterModel"]);
        window.draw(sprites["heftyCharacterModel"]);
        window.draw(sprites["athenaCharacterModelSelected"]);
        window.draw(sprites["joeCharacterModel"]);
        window.draw(sprites["janeCharacterModel"]);
        window.draw(sprites["athenaStats"]);
        window.draw(sprites["athenaMiniModel"]);
    }
    else if (characterSelected == 5) {
        window.draw(sprites["dashCharacterModel"]);
        window.draw(sprites["swiftCharacterModel"]);
        window.draw(sprites["heftyCharacterModel"]);
        window.draw(sprites["athenaCharacterModel"]);
        window.draw(sprites["joeCharacterModelSelected"]);
        window.draw(sprites["janeCharacterModel"]);
        window.draw(sprites["joeStats"]);
        window.draw(sprites["joeMiniModel"]);
    }
    else if (characterSelected == 6) {
        window.draw(sprites["dashCharacterModel"]);
        window.draw(sprites["swiftCharacterModel"]);
        window.draw(sprites["heftyCharacterModel"]);
        window.draw(sprites["athenaCharacterModel"]);
        window.draw(sprites["joeCharacterModel"]);
        window.draw(sprites["janeCharacterModelSelected"]);
        window.draw(sprites["janeStats"]);
        window.draw(sprites["janeMiniModel"]);
    }
}

void DrawCharacterSelectScreen(sf::RenderWindow& window, bool& isMuted, int& characterSelected, unordered_map<string, sf::Sprite>& sprites) {
    window.draw(sprites["characterSelect"]);
    window.draw(sprites["backButton"]);
    window.draw(sprites["okButton"]);
    DrawSelectedCharacter(window, characterSelected, sprites);
    DrawMuted(window, isMuted, sprites);
}

void DrawCorrectCharacter(sf::RenderWindow& window, int& characterSelected, string& characterName, unordered_map<string, sf::Sprite>& sprites) {
    if (characterSelected == 1) {
        window.draw(sprites["dashBannerRight"]);
        window.draw(sprites["dashRacket"]);
        window.draw(sprites["dashPlayer"]);
        characterName = "dash";
    }
    else if (characterSelected == 2) {
        window.draw(sprites["swiftBannerRight"]);
        window.draw(sprites["swiftRacket"]);
        window.draw(sprites["swiftPlayer"]);
        characterName = "swift";
    }
    else if (characterSelected == 3) {
        window.draw(sprites["heftyBannerRight"]);
        window.draw(sprites["heftyRacket"]);
        window.draw(sprites["heftyPlayer"]);
        characterName = "hefty";
    }
    else if (characterSelected == 4) {
        window.draw(sprites["athenaBannerRight"]);
        window.draw(sprites["athenaRacket"]);
        window.draw(sprites["athenaPlayer"]);
        characterName = "athena";
    }
    else if (characterSelected == 5) {
        window.draw(sprites["joeBannerRight"]);
        window.draw(sprites["joeRacket"]);
        window.draw(sprites["joePlayer"]);
        characterName = "joe";
    }
    else if (characterSelected == 6) {
        window.draw(sprites["janeBannerRight"]);
        window.draw(sprites["janeRacket"]);
        window.draw(sprites["janePlayer"]);
        characterName = "jane";
    }
    window.draw(sprites["characterRacketHitZone"]);
}

void DrawRandomCPU(sf::RenderWindow& window, int& randomCPU, string& randomCPUName, unordered_map<string, sf::Sprite>& sprites) {
    if (randomCPU == 1) {
        window.draw(sprites["dashBannerLeft"]);
        window.draw(sprites["dashRacket"]);
        window.draw(sprites["dashPlayer"]);
        randomCPUName = "dash";
    }
    else if (randomCPU == 2) {
        window.draw(sprites["swiftBannerLeft"]);
        window.draw(sprites["swiftRacket"]);
        window.draw(sprites["swiftPlayer"]);
        randomCPUName = "swift";
    }
    else if (randomCPU == 3) {
        window.draw(sprites["heftyBannerLeft"]);
        window.draw(sprites["heftyRacket"]);
        window.draw(sprites["heftyPlayer"]);
        randomCPUName = "hefty";
    }
    else if (randomCPU == 4) {
        window.draw(sprites["athenaBannerLeft"]);
        window.draw(sprites["athenaRacket"]);
        window.draw(sprites["athenaPlayer"]);
        randomCPUName = "athena";
    }
    else if (randomCPU == 5) {
        window.draw(sprites["joeBannerLeft"]);
        window.draw(sprites["joeRacket"]);
        window.draw(sprites["joePlayer"]);
        randomCPUName = "joe";
    }
    else if (randomCPU == 6) {
        window.draw(sprites["janeBannerLeft"]);
        window.draw(sprites["janeRacket"]);
        window.draw(sprites["janePlayer"]);
        randomCPUName = "jane";
    }
    window.draw(sprites["randomCPURacketHitZone"]);
}

void DrawGameScreen(sf::RenderWindow& window, bool& isMuted, int& characterSelected, int& randomCPU, string& characterName, string& randomCPUName, unordered_map<string, sf::Sprite>& sprites) {
    window.draw(sprites["grassCourt"]);
    DrawCorrectCharacter(window, characterSelected, characterName, sprites);
    DrawRandomCPU(window, randomCPU, randomCPUName, sprites);
    window.draw(sprites["tennisBall"]);
}

void CharacterSwing(string& characterName, bool& isSwung, unordered_map<string, sf::Sprite>& sprites) {
    if (!isSwung) {
        sprites[characterName + "Racket"].setRotation(0.f);
        isSwung = true;
    }
    else {
        this_thread::sleep_for(chrono::milliseconds(100));
        sprites[characterName + "Racket"].setRotation(60.f);
        isSwung = false;
    }
}

void MoveCharacter(string& characterName, unordered_map<string, sf::Sprite>& sprites, unordered_map<string, float>& characterSpeeds) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sprites[characterName + "Player"].getPosition().y >= 125.f) {
        sprites[characterName + "Player"].move(0.f, characterSpeeds[characterName] * -1.f);
        sprites[characterName + "Racket"].move(0.f, characterSpeeds[characterName] * -1.f);
        sprites["characterRacketHitZone"].move(0.f, characterSpeeds[characterName] * -1.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sprites[characterName + "Player"].getPosition().y <= 500.f) {
        sprites[characterName + "Player"].move(0.f, characterSpeeds[characterName]);
        sprites[characterName + "Racket"].move(0.f, characterSpeeds[characterName]);
        sprites["characterRacketHitZone"].move(0.f, characterSpeeds[characterName]);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sprites[characterName + "Player"].getPosition().x <= 800.f) {
        sprites[characterName + "Player"].move(characterSpeeds[characterName], 0.f);
        sprites[characterName + "Racket"].move(characterSpeeds[characterName], 0.f);
        sprites["characterRacketHitZone"].move(characterSpeeds[characterName], 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sprites[characterName + "Player"].getPosition().x >= 450.f) {
        sprites[characterName + "Player"].move(characterSpeeds[characterName] * -1.f, 0.f);
        sprites[characterName + "Racket"].move(characterSpeeds[characterName] * -1.f, 0.f);
        sprites["characterRacketHitZone"].move(characterSpeeds[characterName] * -1.f, 0.f);
    }
}

void MoveRandomCPU(string& randomCPUName, unordered_map<string, sf::Sprite>& sprites, unordered_map<string, float>& characterSpeeds) {
    if (sprites["tennisBall"].getPosition().y < sprites["randomCPURacketHitZone"].getPosition().y && sprites[randomCPUName + "Player"].getPosition().y >= 175.f) {
        sprites[randomCPUName + "Player"].move(0.f, characterSpeeds[randomCPUName] * -1.f);
        sprites[randomCPUName + "Racket"].move(0.f, characterSpeeds[randomCPUName] * -1.f);
        sprites["randomCPURacketHitZone"].move(0.f, characterSpeeds[randomCPUName] * -1.f);
    }
    else if (sprites["tennisBall"].getPosition().y > sprites["randomCPURacketHitZone"].getPosition().y && sprites[randomCPUName + "Player"].getPosition().y <= 550.f) {
        sprites[randomCPUName + "Player"].move(0.f, characterSpeeds[randomCPUName]);
        sprites[randomCPUName + "Racket"].move(0.f, characterSpeeds[randomCPUName]);
        sprites["randomCPURacketHitZone"].move(0.f, characterSpeeds[randomCPUName]);
    }
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
    sf::Sprite athenaCharacterModel(TextureManager::GetTexture("athenaCharacterModel"));
    athenaCharacterModel.setPosition(0.f, 350.f);
    sf::Sprite athenaCharacterModelSelected(TextureManager::GetTexture("athenaCharacterModelSelected"));
    athenaCharacterModelSelected.setPosition(0.f, 350.f);
    sf::Sprite joeCharacterModel(TextureManager::GetTexture("joeCharacterModel"));
    joeCharacterModel.setPosition(250.f, 350.f);
    sf::Sprite joeCharacterModelSelected(TextureManager::GetTexture("joeCharacterModelSelected"));
    joeCharacterModelSelected.setPosition(250.f, 350.f);
    sf::Sprite janeCharacterModel(TextureManager::GetTexture("janeCharacterModel"));
    janeCharacterModel.setPosition(500.f, 350.f);
    sf::Sprite janeCharacterModelSelected(TextureManager::GetTexture("janeCharacterModelSelected"));
    janeCharacterModelSelected.setPosition(500.f, 350.f);
    sf::Sprite backButton(TextureManager::GetTexture("backButton"));
    backButton.setPosition(775.f, 230.f);
    sf::Sprite okButton(TextureManager::GetTexture("okButton"));
    okButton.setPosition(775.f, 430.f);
    sf::Sprite dashStats(TextureManager::GetTexture("dashStats"));
    dashStats.setPosition(500.f, 0.f);
    sf::Sprite swiftStats(TextureManager::GetTexture("swiftStats"));
    swiftStats.setPosition(500.f, 0.f);
    sf::Sprite heftyStats(TextureManager::GetTexture("heftyStats"));
    heftyStats.setPosition(500.f, 0.f);
    sf::Sprite athenaStats(TextureManager::GetTexture("athenaStats"));
    athenaStats.setPosition(500.f, 0.f);
    sf::Sprite joeStats(TextureManager::GetTexture("joeStats"));
    joeStats.setPosition(500.f, 0.f);
    sf::Sprite janeStats(TextureManager::GetTexture("janeStats"));
    janeStats.setPosition(500.f, 0.f);
    sf::Sprite dashMiniModel(TextureManager::GetTexture("dashCharacterModel"));
    dashMiniModel.setScale(0.6f, 0.6f);
    dashMiniModel.setPosition(750.f, 15.f);
    sf::Sprite swiftMiniModel(TextureManager::GetTexture("swiftCharacterModel"));
    swiftMiniModel.setScale(0.6f, 0.6f);
    swiftMiniModel.setPosition(750.f, 15.f);
    sf::Sprite heftyMiniModel(TextureManager::GetTexture("heftyCharacterModel"));
    heftyMiniModel.setScale(0.6f, 0.6f);
    heftyMiniModel.setPosition(750.f, 15.f);
    sf::Sprite athenaMiniModel(TextureManager::GetTexture("athenaCharacterModel"));
    athenaMiniModel.setScale(0.6f, 0.6f);
    athenaMiniModel.setPosition(750.f, 15.f);
    sf::Sprite joeMiniModel(TextureManager::GetTexture("joeCharacterModel"));
    joeMiniModel.setScale(0.6f, 0.6f);
    joeMiniModel.setPosition(750.f, 15.f);
    sf::Sprite janeMiniModel(TextureManager::GetTexture("janeCharacterModel"));
    janeMiniModel.setScale(0.6f, 0.6f);
    janeMiniModel.setPosition(750.f, 15.f);
    sf::Sprite readyText(TextureManager::GetTexture("readyText"));
    readyText.setPosition(300.f, 250.f);
    sf::Sprite setText(TextureManager::GetTexture("setText"));
    setText.setPosition(300.f, 250.f);
    sf::Sprite goText(TextureManager::GetTexture("goText"));
    goText.setPosition(300.f, 250.f);
    sf::Sprite dashPlayer(TextureManager::GetTexture("dashPlayer"));
    dashPlayer.setPosition(750.f, 235.f);
    sf::Sprite swiftPlayer(TextureManager::GetTexture("swiftPlayer"));
    swiftPlayer.setPosition(750.f, 235.f);
    sf::Sprite heftyPlayer(TextureManager::GetTexture("heftyPlayer"));
    heftyPlayer.setPosition(750.f, 235.f);
    sf::Sprite athenaPlayer(TextureManager::GetTexture("athenaPlayer"));
    athenaPlayer.setPosition(750.f, 235.f);
    sf::Sprite joePlayer(TextureManager::GetTexture("joePlayer"));
    joePlayer.setPosition(750.f, 235.f);
    sf::Sprite janePlayer(TextureManager::GetTexture("janePlayer"));
    janePlayer.setPosition(750.f, 235.f);
    sf::Sprite dashBannerRight(TextureManager::GetTexture("dashBannerRight"));
    dashBannerRight.setPosition(450.f, 30.f); 
    sf::Sprite swiftBannerRight(TextureManager::GetTexture("swiftBannerRight"));
    swiftBannerRight.setPosition(450.f, 30.f);
    sf::Sprite heftyBannerRight(TextureManager::GetTexture("heftyBannerRight"));
    heftyBannerRight.setPosition(450.f, 30.f);
    sf::Sprite athenaBannerRight(TextureManager::GetTexture("athenaBannerRight"));
    athenaBannerRight.setPosition(450.f, 30.f);
    sf::Sprite joeBannerRight(TextureManager::GetTexture("joeBannerRight"));
    joeBannerRight.setPosition(450.f, 30.f);
    sf::Sprite janeBannerRight(TextureManager::GetTexture("janeBannerRight"));
    janeBannerRight.setPosition(450.f, 30.f);
    sf::Sprite dashBannerLeft(TextureManager::GetTexture("dashBannerLeft"));
    dashBannerLeft.setPosition(150.f, 30.f);
    sf::Sprite swiftBannerLeft(TextureManager::GetTexture("swiftBannerLeft"));
    swiftBannerLeft.setPosition(150.f, 30.f);
    sf::Sprite heftyBannerLeft(TextureManager::GetTexture("heftyBannerLeft"));
    heftyBannerLeft.setPosition(150.f, 30.f);
    sf::Sprite athenaBannerLeft(TextureManager::GetTexture("athenaBannerLeft"));
    athenaBannerLeft.setPosition(150.f, 30.f);
    sf::Sprite joeBannerLeft(TextureManager::GetTexture("joeBannerLeft"));
    joeBannerLeft.setPosition(150.f, 30.f);
    sf::Sprite janeBannerLeft(TextureManager::GetTexture("janeBannerLeft"));
    janeBannerLeft.setPosition(150.f, 30.f);
    sf::Sprite dashRacket(TextureManager::GetTexture("dashRacket"));
    dashRacket.setOrigin(75.f, 10.f);
    dashRacket.setPosition(785.f, 240.f);
    dashRacket.setRotation(60.f);
    sf::Sprite swiftRacket(TextureManager::GetTexture("swiftRacket"));
    swiftRacket.setOrigin(75.f, 10.f);
    swiftRacket.setPosition(785.f, 240.f);
    swiftRacket.setRotation(60.f);
    sf::Sprite heftyRacket(TextureManager::GetTexture("heftyRacket"));
    heftyRacket.setOrigin(75.f, 10.f);
    heftyRacket.setPosition(785.f, 240.f);
    heftyRacket.setRotation(60.f);
    sf::Sprite athenaRacket(TextureManager::GetTexture("athenaRacket"));
    athenaRacket.setOrigin(75.f, 10.f);
    athenaRacket.setPosition(785.f, 240.f);
    athenaRacket.setRotation(60.f);
    sf::Sprite joeRacket(TextureManager::GetTexture("joeRacket"));
    joeRacket.setOrigin(75.f, 10.f);
    joeRacket.setPosition(785.f, 240.f);
    joeRacket.setRotation(60.f);
    sf::Sprite janeRacket(TextureManager::GetTexture("janeRacket"));
    janeRacket.setOrigin(75.f, 10.f);
    janeRacket.setPosition(785.f, 240.f);
    janeRacket.setRotation(60.f);
    sf::Sprite characterRacketHitZone(TextureManager::GetTexture("racketHitZone"));
    characterRacketHitZone.setPosition(720.f, 175.f);
    sf::Sprite randomCPURacketHitZone(TextureManager::GetTexture("racketHitZone"));
    randomCPURacketHitZone.setPosition(118.f, 433.f);
    sf::Sprite tennisBall(TextureManager::GetTexture("tennisBall"));
    tennisBall.setPosition(150.f, 450.f);

    sf::RectangleShape tempBackground(sf::Vector2f(900.f, 600.f));
    tempBackground.setFillColor(sf::Color::White);

    sf::Sound magicButtonClick(SoundBufferManager::GetSoundBuffer("magicButtonClick"));
    sf::Sound characterSelectClick(SoundBufferManager::GetSoundBuffer("characterSelectClick"));
    sf::Sound arcadeCountdown(SoundBufferManager::GetSoundBuffer("arcadeCountdown"));
    sf::Sound racketSwing(SoundBufferManager::GetSoundBuffer("racketSwing"));

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
    sprites.emplace("athenaCharacterModel", athenaCharacterModel);
    sprites.emplace("athenaCharacterModelSelected", athenaCharacterModelSelected);
    sprites.emplace("joeCharacterModel", joeCharacterModel);
    sprites.emplace("joeCharacterModelSelected", joeCharacterModelSelected);
    sprites.emplace("janeCharacterModel", janeCharacterModel);
    sprites.emplace("janeCharacterModelSelected", janeCharacterModelSelected);
    sprites.emplace("backButton", backButton);
    sprites.emplace("okButton", okButton);
    sprites.emplace("dashStats", dashStats);
    sprites.emplace("swiftStats", swiftStats);
    sprites.emplace("heftyStats", heftyStats);
    sprites.emplace("athenaStats", athenaStats);
    sprites.emplace("joeStats", joeStats);
    sprites.emplace("janeStats", janeStats);
    sprites.emplace("dashMiniModel", dashMiniModel);
    sprites.emplace("swiftMiniModel", swiftMiniModel);
    sprites.emplace("heftyMiniModel", heftyMiniModel);
    sprites.emplace("athenaMiniModel", athenaMiniModel);
    sprites.emplace("joeMiniModel", joeMiniModel);
    sprites.emplace("janeMiniModel", janeMiniModel);
    sprites.emplace("readyText", readyText);
    sprites.emplace("setText", setText);
    sprites.emplace("goText", goText);
    sprites.emplace("dashPlayer", dashPlayer);
    sprites.emplace("swiftPlayer", swiftPlayer);
    sprites.emplace("heftyPlayer", heftyPlayer);
    sprites.emplace("athenaPlayer", athenaPlayer);
    sprites.emplace("joePlayer", joePlayer);
    sprites.emplace("janePlayer", janePlayer);
    sprites.emplace("dashBannerRight", dashBannerRight);
    sprites.emplace("swiftBannerRight", swiftBannerRight);
    sprites.emplace("heftyBannerRight", heftyBannerRight);
    sprites.emplace("athenaBannerRight", athenaBannerRight);
    sprites.emplace("joeBannerRight", joeBannerRight);
    sprites.emplace("janeBannerRight", janeBannerRight);
    sprites.emplace("dashBannerLeft", dashBannerLeft);
    sprites.emplace("swiftBannerLeft", swiftBannerLeft);
    sprites.emplace("heftyBannerLeft", heftyBannerLeft);
    sprites.emplace("athenaBannerLeft", athenaBannerLeft);
    sprites.emplace("joeBannerLeft", joeBannerLeft);
    sprites.emplace("janeBannerLeft", janeBannerLeft);
    sprites.emplace("dashRacket", dashRacket);
    sprites.emplace("swiftRacket", swiftRacket);
    sprites.emplace("heftyRacket", heftyRacket);
    sprites.emplace("athenaRacket", athenaRacket);
    sprites.emplace("joeRacket", joeRacket);
    sprites.emplace("janeRacket", janeRacket);
    sprites.emplace("characterRacketHitZone", characterRacketHitZone);
    sprites.emplace("randomCPURacketHitZone", randomCPURacketHitZone);
    sprites.emplace("tennisBall", tennisBall);

    unordered_map<string, sf::Sound> sounds;
    sounds.emplace("magicButtonClick", magicButtonClick);
    sounds.emplace("characterSelectClick", characterSelectClick);
    sounds.emplace("arcadeCountdown", arcadeCountdown);
    sounds.emplace("racketSwing", racketSwing);

    unordered_map<string, sf::Text> texts;
    texts.emplace("rulesTitle", rulesTitle);
    texts.emplace("optionsTitle", optionsTitle);
    texts.emplace("creditsTitle", creditsTitle);
    
    unordered_map<string, float> characterSpeeds;
    characterSpeeds.emplace("dash", 0.3f);
    characterSpeeds.emplace("swift", 0.3f);
    characterSpeeds.emplace("hefty", 0.1f);
    characterSpeeds.emplace("athena", 0.1f);
    characterSpeeds.emplace("joe", 0.2f);
    characterSpeeds.emplace("jane", 0.2f);

    unordered_map<string, float> characterPower;
    characterPower.emplace("dash", 0.15f);
    characterPower.emplace("swift", 0.15f);
    characterPower.emplace("hefty", 0.25f);
    characterPower.emplace("athena", 0.25f);
    characterPower.emplace("joe", 0.2f);
    characterPower.emplace("jane", 0.2f);

    // boolean + integer/float + string variable initializations
    bool isMuted = false;
    bool isSwung = false;
    bool isTitleScreen = true;
    bool isRulesPage = false;
    bool isOptionsPage = false;
    bool isCreditsPage = false;
    bool isCharacterSelectScreen = false;
    bool isGameScreen = false;
    int characterSelected = 1;
    int randomCPU = characterSelected;
    int pointNumber = 1;
    float tennisBallSpeed = 0.2f;
    float tennisBallY = Random::Float(-0.13f, -0.05f);
    string characterName = "dash";
    string randomCPUName = "dash";

    chrono::time_point<chrono::high_resolution_clock> gameStartTime; // for keeping track of time passed

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
                        continue;
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
                    if (backButton.getGlobalBounds().contains(mousePos.x, mousePos.y) && isCharacterSelectScreen) {
                        magicButtonClick.play();
                        isTitleScreen = true;
                        isCharacterSelectScreen = false;
                    }
                    if (dashCharacterModel.getGlobalBounds().contains(mousePos.x, mousePos.y) && isCharacterSelectScreen) {
                        characterSelectClick.play();
                        characterSelected = 1;
                    }
                    if (swiftCharacterModel.getGlobalBounds().contains(mousePos.x, mousePos.y) && isCharacterSelectScreen) {
                        characterSelectClick.play();
                        characterSelected = 2;
                    }
                    if (heftyCharacterModel.getGlobalBounds().contains(mousePos.x, mousePos.y) && isCharacterSelectScreen) {
                        characterSelectClick.play();
                        characterSelected = 3;
                    }
                    if (athenaCharacterModel.getGlobalBounds().contains(mousePos.x, mousePos.y) && isCharacterSelectScreen) {
                        characterSelectClick.play();
                        characterSelected = 4;
                    }
                    if (joeCharacterModel.getGlobalBounds().contains(mousePos.x, mousePos.y) && isCharacterSelectScreen) {
                        characterSelectClick.play();
                        characterSelected = 5;
                    }
                    if (janeCharacterModel.getGlobalBounds().contains(mousePos.x, mousePos.y) && isCharacterSelectScreen) {
                        characterSelectClick.play();
                        characterSelected = 6;
                    }
                    if (okButton.getGlobalBounds().contains(mousePos.x, mousePos.y) && isCharacterSelectScreen) {
                        isGameScreen = true;
                        isCharacterSelectScreen = false;
                        gameStartTime = chrono::high_resolution_clock::now();
                        backgroundMusic.stop();
                        arcadeCountdown.play();
                        randomCPU = Random::Int(1, 6);
                        while (randomCPU == characterSelected) {
                            randomCPU = Random::Int(1, 6);
                        }
                        if (randomCPU == 1) {
                            sprites["dashPlayer"].setPosition(150.f, 435.f);
                            sprites["dashPlayer"].setRotation(180.f);
                            sprites["dashRacket"].setPosition(116.f, 430.f);
                            sprites["dashRacket"].setRotation(240.f);
                        }
                        else if (randomCPU == 2) {
                            sprites["swiftPlayer"].setPosition(150.f, 435.f);
                            sprites["swiftPlayer"].setRotation(180.f);
                            sprites["swiftRacket"].setPosition(116.f, 430.f);
                            sprites["swiftRacket"].setRotation(240.f);
                        }
                        else if (randomCPU == 3) {
                            sprites["heftyPlayer"].setPosition(150.f, 435.f);
                            sprites["heftyPlayer"].setRotation(180.f);
                            sprites["heftyRacket"].setPosition(116.f, 430.f);
                            sprites["heftyRacket"].setRotation(240.f);
                        }
                        else if (randomCPU == 4) {
                            sprites["athenaPlayer"].setPosition(150.f, 435.f);
                            sprites["athenaPlayer"].setRotation(180.f);
                            sprites["athenaRacket"].setPosition(116.f, 430.f);
                            sprites["athenaRacket"].setRotation(240.f);
                        }
                        else if (randomCPU == 5) {
                            sprites["joePlayer"].setPosition(150.f, 435.f);
                            sprites["joePlayer"].setRotation(180.f);
                            sprites["joeRacket"].setPosition(116.f, 430.f);
                            sprites["joeRacket"].setRotation(240.f);
                        }
                        else if (randomCPU == 6) {
                            sprites["janePlayer"].setPosition(150.f, 435.f);
                            sprites["janePlayer"].setRotation(180.f);
                            sprites["janeRacket"].setPosition(116.f, 430.f);
                            sprites["janeRacket"].setRotation(240.f);
                        }
                    }
                }
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space && isGameScreen) {
                    racketSwing.play();
                    CharacterSwing(characterName, isSwung, sprites);
                    if (sprites["tennisBall"].getGlobalBounds().intersects(sprites["characterRacketHitZone"].getGlobalBounds())) {
                        tennisBallSpeed = characterPower[characterName] * -1.f;
                        if (sprites[characterName + "Player"].getPosition().y <= 312.f)
                            tennisBallY = Random::Float(-0.05f, 0.15f);
                        else
                            tennisBallY = Random::Float(-0.15f, 0.05f);
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
            DrawCharacterSelectScreen(window, isMuted, characterSelected, sprites);
        if (isGameScreen) {
            MoveCharacter(characterName, sprites, characterSpeeds);
            MoveRandomCPU(randomCPUName, sprites, characterSpeeds);
            chrono::time_point<chrono::high_resolution_clock> currentTime = chrono::high_resolution_clock::now();
            chrono::duration<double> inGameTime = currentTime - gameStartTime;
            DrawGameScreen(window, isMuted, characterSelected, randomCPU, characterName, randomCPUName, sprites);
            if (inGameTime.count() <= 3.0) {
                if (inGameTime.count() <= 1.0)
                    window.draw(readyText);
                else if (inGameTime.count() <= 2.0)
                    window.draw(setText);
                else
                    window.draw(goText);
            }
            else {
                sprites["tennisBall"].move(tennisBallSpeed, tennisBallY);
            }
        }    
        window.display();
        if (isSwung) {
            thread characterSwingT(CharacterSwing, ref(characterName), ref(isSwung), ref(sprites));
            characterSwingT.detach();
        }
    }

    // Clear out any sf::Texture objects before the program ends
    TextureManager::Clear();

    // Clear out any sf::SoundBuffer objects before the program ends
    SoundBufferManager::Clear();

    // Clear out any sf::Font objects before the program ends
    FontManager::Clear();

	return 0;
}
