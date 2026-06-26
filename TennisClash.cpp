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

void ChangeVolume(float& volumeSelected, sf::Music& backgroundMusic, unordered_map<string, sf::Sound>& sounds) {
    backgroundMusic.setVolume(volumeSelected);
    sounds["magicButtonClick"].setVolume(volumeSelected);
    sounds["characterSelectClick"].setVolume(volumeSelected);
    sounds["arcadeCountdown"].setVolume(volumeSelected);
    sounds["racketSwing"].setVolume(volumeSelected);
    sounds["tennisBallHit"].setVolume(volumeSelected);
    sounds["niceShot"].setVolume(volumeSelected);
    sounds["goodTry"].setVolume(volumeSelected);
    sounds["winSound"].setVolume(volumeSelected);
    sounds["lossSound"].setVolume(volumeSelected);
}

void DrawCorrectCourt(sf::RenderWindow& window, int& courtSelected, unordered_map<string, sf::Sprite>& sprites) {
    if (courtSelected == 1)
        window.draw(sprites["grassCourt"]);
    else if (courtSelected == 2)
        window.draw(sprites["clayCourt"]);
    else if (courtSelected == 3)
        window.draw(sprites["hardCourt"]);
}

void DrawTitleScreen(sf::RenderWindow& window, bool& isMuted, int& courtSelected, unordered_map<string, sf::Sprite>& sprites) {
    DrawCorrectCourt(window, courtSelected, sprites);
    window.draw(sprites["title"]);
    window.draw(sprites["playButton"]);
    window.draw(sprites["rulesButton"]);
    window.draw(sprites["optionsButton"]);
    window.draw(sprites["creditsButton"]);
    DrawMuted(window, isMuted, sprites);
}

void DrawRulesPage(sf::RenderWindow& window, bool& isMuted, int& courtSelected, unordered_map<string, sf::Sprite>& sprites, unordered_map<string, sf::Text>& texts) {
    DrawCorrectCourt(window, courtSelected, sprites);
    window.draw(sprites["title"]);
    window.draw(sprites["pageBackground"]);
    window.draw(sprites["closeButton"]);
    window.draw(texts["rulesTitle"]);
    window.draw(texts["rulesText"]);
    DrawMuted(window, isMuted, sprites);
}

void DrawOptionsPage(sf::RenderWindow& window, bool& isMuted, bool& isRandomClicked, bool& isPreciseClicked, int& courtSelected, unordered_map<string, sf::Sprite>& sprites, unordered_map<string, sf::Text>& texts) {
    DrawCorrectCourt(window, courtSelected, sprites);
    window.draw(sprites["title"]);
    window.draw(sprites["pageBackground"]);
    window.draw(sprites["closeButton"]);
    window.draw(texts["optionsTitle"]);
    window.draw(texts["optionsVolume"]);
    window.draw(texts["optionsVolumeChoices"]);
    window.draw(sprites["volumeRadio1"]);
    window.draw(sprites["volumeRadio2"]);
    window.draw(sprites["volumeRadio3"]);
    window.draw(sprites["volumeRadio4"]);
    window.draw(sprites["volumeRadio5"]);
    window.draw(sprites["volumeRadioSelected"]);
    window.draw(texts["optionsCourt"]);
    window.draw(texts["optionsCourtChoices"]);
    window.draw(sprites["courtRadio1"]);
    window.draw(sprites["courtRadio2"]);
    window.draw(sprites["courtRadio3"]);
    window.draw(sprites["courtRadioSelected"]);
    window.draw(texts["optionsScoreToWin"]);
    window.draw(texts["optionsScoreToWinChoices"]);
    window.draw(sprites["scoreToWinRadio1"]);
    window.draw(sprites["scoreToWinRadio2"]);
    window.draw(sprites["scoreToWinRadio3"]);
    window.draw(sprites["scoreToWinRadioSelected"]);
    window.draw(texts["optionsHitMode"]);
    window.draw(texts["optionsHitModeChoice1"]);
    window.draw(texts["optionsHitModeChoice2"]);
    window.draw(sprites["hitModeRadio1"]);
    window.draw(sprites["hitModeRadio2"]);
    window.draw(sprites["hitModeRadioSelected"]);
    if (isRandomClicked) 
        window.draw(sprites["randomMoreInfoBox"]);
    if (isPreciseClicked)
        window.draw(sprites["preciseMoreInfoBox"]);
    DrawMuted(window, isMuted, sprites);
}

void DrawCreditsPage(sf::RenderWindow& window, bool& isMuted, int& courtSelected, unordered_map<string, sf::Sprite>& sprites, unordered_map<string, sf::Text>& texts) {
    DrawCorrectCourt(window, courtSelected, sprites);
    window.draw(sprites["title"]);
    window.draw(sprites["pageBackground"]);
    window.draw(sprites["closeButton"]);
    window.draw(texts["creditsTitle"]);
    window.draw(texts["creditsText"]);
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

void DrawGameScreen(sf::RenderWindow& window, bool& isMuted, int& characterSelected, int& randomCPU, int& courtSelected, string& characterName, string& randomCPUName, unordered_map<string, sf::Sprite>& sprites, unordered_map<string, sf::Text>& texts) {
    DrawCorrectCourt(window, courtSelected, sprites);
    DrawCorrectCharacter(window, characterSelected, characterName, sprites);
    DrawRandomCPU(window, randomCPU, randomCPUName, sprites);
    window.draw(texts["playerScore"]);
    window.draw(texts["randomCPUScore"]);
    window.draw(sprites["tennisBall"]);
}

void DrawWinScreen(sf::RenderWindow& window, unordered_map<string, sf::Sprite>& sprites) {
    window.draw(sprites["winScreen"]);
    window.draw(sprites["titleScreenButton"]);
    window.draw(sprites["playAgainButton"]);
}

void DrawLossScreen(sf::RenderWindow& window, unordered_map<string, sf::Sprite>& sprites) {
    window.draw(sprites["lossScreen"]);
    window.draw(sprites["titleScreenButton"]);
    window.draw(sprites["playAgainButton"]);
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

void RandomCPUSwing(string& randomCPUName, bool& isSwingingCPU, unordered_map<string, sf::Sprite>& sprites) {
    this_thread::sleep_for(chrono::milliseconds(50));
    sprites[randomCPUName + "Racket"].setRotation(180.f);
    this_thread::sleep_for(chrono::milliseconds(100));
    sprites[randomCPUName + "Racket"].setRotation(240.f);
    this_thread::sleep_for(chrono::milliseconds(200));
    isSwingingCPU = false;
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

void StartNextPoint(int& pointNumber, int& gameWinner, float& tennisBallSpeed, float& tennisBallY, string& characterName, string& randomCPUName, bool& isServe, unordered_map<string, sf::Sprite>& sprites, unordered_map<string, sf::Sound>& sounds) {
    this_thread::sleep_for(chrono::milliseconds(1250));
    isServe = true;
    if (gameWinner == 0) {
        if (pointNumber % 2 == 0) {
            sprites[characterName + "Player"].setPosition(750.f, 385.f);
            sprites[characterName + "Player"].setRotation(0.f);
            sprites[characterName + "Racket"].setPosition(785.f, 390.f);
            sprites[characterName + "Racket"].setRotation(60.f);
            sprites["characterRacketHitZone"].setPosition(720.f, 325.f);
            sprites[randomCPUName + "Player"].setPosition(150.f, 285.f);
            sprites[randomCPUName + "Player"].setRotation(180.f);
            sprites[randomCPUName + "Racket"].setPosition(116.f, 280.f);
            sprites[randomCPUName + "Racket"].setRotation(240.f);
            sprites["randomCPURacketHitZone"].setPosition(118.f, 283.f);
            sprites["tennisBall"].setPosition(150.f, 300.f);
            tennisBallSpeed = 0.15f;
            tennisBallY = Random::Float(0.01f, 0.08f);
        }
        else {
            sprites[characterName + "Player"].setPosition(750.f, 235.f);
            sprites[characterName + "Player"].setRotation(0.f);
            sprites[characterName + "Racket"].setPosition(785.f, 240.f);
            sprites[characterName + "Racket"].setRotation(60.f);
            sprites["characterRacketHitZone"].setPosition(720.f, 175.f);
            sprites[randomCPUName + "Player"].setPosition(150.f, 435.f);
            sprites[randomCPUName + "Player"].setRotation(180.f);
            sprites[randomCPUName + "Racket"].setPosition(116.f, 430.f);
            sprites[randomCPUName + "Racket"].setRotation(240.f);
            sprites["randomCPURacketHitZone"].setPosition(118.f, 433.f);
            sprites["tennisBall"].setPosition(150.f, 450.f);
            tennisBallSpeed = 0.15f;
            tennisBallY = Random::Float(-0.13f, -0.05f);
        }
    }
    else {
        if (gameWinner == 1)
            sounds["winSound"].play();
        if (gameWinner == 2)
            sounds["lossSound"].play();
        tennisBallSpeed = 0.0f;
        tennisBallY = 0.0f;
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
    sf::Sprite clayCourt(TextureManager::GetTexture("clayCourt"));
    sf::Sprite hardCourt(TextureManager::GetTexture("hardCourt"));
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
    sf::Sprite niceShotText(TextureManager::GetTexture("niceShotText"));
    niceShotText.setPosition(300.f, 250.f);
    sf::Sprite goodTryText(TextureManager::GetTexture("goodTryText"));
    goodTryText.setPosition(300.f, 250.f);
    sf::Sprite winScreen(TextureManager::GetTexture("winScreen"));
    sf::Sprite lossScreen(TextureManager::GetTexture("lossScreen"));
    sf::Sprite titleScreenButton(TextureManager::GetTexture("titleScreenButton"));
    titleScreenButton.setPosition(25.f, 475.f);
    sf::Sprite playAgainButton(TextureManager::GetTexture("playAgainButton"));
    playAgainButton.setPosition(625.f, 475.f);
    sf::Sprite volumeRadio1(TextureManager::GetTexture("radioButtonNo"));
    volumeRadio1.setPosition(175.f, 195.f);
    sf::Sprite volumeRadio2(TextureManager::GetTexture("radioButtonNo"));
    volumeRadio2.setPosition(270.f, 195.f);
    sf::Sprite volumeRadio3(TextureManager::GetTexture("radioButtonNo"));
    volumeRadio3.setPosition(389.f, 195.f);
    sf::Sprite volumeRadio4(TextureManager::GetTexture("radioButtonNo"));
    volumeRadio4.setPosition(509.f, 195.f);
    sf::Sprite volumeRadio5(TextureManager::GetTexture("radioButtonNo"));
    volumeRadio5.setPosition(630.f, 195.f);
    sf::Sprite volumeRadioSelected(TextureManager::GetTexture("radioButtonYes"));
    volumeRadioSelected.setPosition(630.f, 195.f);
    sf::Sprite courtRadio1(TextureManager::GetTexture("radioButtonNo"));
    courtRadio1.setPosition(175.f, 260.f);
    sf::Sprite courtRadio2(TextureManager::GetTexture("radioButtonNo"));
    courtRadio2.setPosition(325.f, 260.f);
    sf::Sprite courtRadio3(TextureManager::GetTexture("radioButtonNo"));
    courtRadio3.setPosition(475.f, 260.f);
    sf::Sprite courtRadioSelected(TextureManager::GetTexture("radioButtonYes"));
    courtRadioSelected.setPosition(175.f, 260.f);
    sf::Sprite scoreToWinRadio1(TextureManager::GetTexture("radioButtonNo"));
    scoreToWinRadio1.setPosition(175.f, 325.f);
    sf::Sprite scoreToWinRadio2(TextureManager::GetTexture("radioButtonNo"));
    scoreToWinRadio2.setPosition(325.f, 325.f);
    sf::Sprite scoreToWinRadio3(TextureManager::GetTexture("radioButtonNo"));
    scoreToWinRadio3.setPosition(475.f, 325.f);
    sf::Sprite scoreToWinRadioSelected(TextureManager::GetTexture("radioButtonYes"));
    scoreToWinRadioSelected.setPosition(175.f, 325.f);
    sf::Sprite hitModeRadio1(TextureManager::GetTexture("radioButtonNo"));
    hitModeRadio1.setPosition(175.f, 390.f);
    sf::Sprite hitModeRadio2(TextureManager::GetTexture("radioButtonNo"));
    hitModeRadio2.setPosition(405.f, 390.f);
    sf::Sprite hitModeRadioSelected(TextureManager::GetTexture("radioButtonYes"));
    hitModeRadioSelected.setPosition(175.f, 390.f);
    sf::Sprite randomMoreInfoBox(TextureManager::GetTexture("randomMoreInfoBox"));
    randomMoreInfoBox.setPosition(195.f, 385.f);
    sf::Sprite preciseMoreInfoBox(TextureManager::GetTexture("preciseMoreInfoBox"));
    preciseMoreInfoBox.setPosition(425.f, 385.f);

    sf::RectangleShape tempBackground(sf::Vector2f(900.f, 600.f));
    tempBackground.setFillColor(sf::Color::White);

    sf::Sound magicButtonClick(SoundBufferManager::GetSoundBuffer("magicButtonClick"));
    sf::Sound characterSelectClick(SoundBufferManager::GetSoundBuffer("characterSelectClick"));
    sf::Sound arcadeCountdown(SoundBufferManager::GetSoundBuffer("arcadeCountdown"));
    sf::Sound racketSwing(SoundBufferManager::GetSoundBuffer("racketSwing"));
    sf::Sound tennisBallHit(SoundBufferManager::GetSoundBuffer("tennisBallHit"));
    sf::Sound niceShot(SoundBufferManager::GetSoundBuffer("niceShot"));
    sf::Sound goodTry(SoundBufferManager::GetSoundBuffer("goodTry"));
    sf::Sound winSound(SoundBufferManager::GetSoundBuffer("winSound"));
    sf::Sound lossSound(SoundBufferManager::GetSoundBuffer("lossSound"));

    sf::Music backgroundMusic;
    backgroundMusic.openFromFile("audio/backgroundMusic.wav");
    backgroundMusic.setLoop(true);
    backgroundMusic.play();

    sf::Text rulesTitle;
    rulesTitle.setFont(FontManager::GetFont("yosterIsland"));
    rulesTitle.setString("Rules");
    rulesTitle.setCharacterSize(50);
    rulesTitle.setFillColor(sf::Color::Black);
    rulesTitle.setPosition(165.f, 100.f);

    sf::Text rulesText;
    rulesText.setFont(FontManager::GetFont("aileronRegular"));
    rulesText.setString("Press the arrow keys to move, and the spacebar to swing.\n\nYour opponent will always change sides and serve diagonally\nat the start of each point. Then, anywhere is fair game.\n\nDifferent characters have unique stats (shot power and\nfoot speed), so choose wisely.\n\nOnly forehands (right of you) are allowed, and winners are key.\n\nThe default score to win is 7 but can be changed in Options.\nCheck out Options for more incredible customization.\n\nSo get out there and show everyone who the King\nof the Court really is!");
    rulesText.setCharacterSize(20);
    rulesText.setFillColor(sf::Color::Black);
    rulesText.setPosition(165.f, 160.f);

    sf::Text optionsTitle;
    optionsTitle.setFont(FontManager::GetFont("yosterIsland"));
    optionsTitle.setString("Options");
    optionsTitle.setCharacterSize(50);
    optionsTitle.setFillColor(sf::Color::Black);
    optionsTitle.setPosition(165.f, 100.f);

    sf::Text optionsVolume;
    optionsVolume.setFont(FontManager::GetFont("aileronRegular"));
    optionsVolume.setString("Volume");
    optionsVolume.setCharacterSize(25);
    optionsVolume.setFillColor(sf::Color::Black);
    optionsVolume.setPosition(170.f, 160.f);

    sf::Text optionsVolumeChoices;
    optionsVolumeChoices.setFont(FontManager::GetFont("aileronRegular"));
    optionsVolumeChoices.setString("0%                 25%                    50%                    75%                    100%");
    optionsVolumeChoices.setCharacterSize(20);
    optionsVolumeChoices.setFillColor(sf::Color::Black);
    optionsVolumeChoices.setPosition(195.f, 190.f);

    sf::Text optionsCourt;
    optionsCourt.setFont(FontManager::GetFont("aileronRegular"));
    optionsCourt.setString("Court");
    optionsCourt.setCharacterSize(25);
    optionsCourt.setFillColor(sf::Color::Black);
    optionsCourt.setPosition(170.f, 225.f);

    sf::Text optionsCourtChoices;
    optionsCourtChoices.setFont(FontManager::GetFont("aileronRegular"));
    optionsCourtChoices.setString("Grass                         Clay                            Hard");
    optionsCourtChoices.setCharacterSize(20);
    optionsCourtChoices.setFillColor(sf::Color::Black);
    optionsCourtChoices.setPosition(195.f, 255.f);

    sf::Text optionsScoreToWin;
    optionsScoreToWin.setFont(FontManager::GetFont("aileronRegular"));
    optionsScoreToWin.setString("Score To Win");
    optionsScoreToWin.setCharacterSize(25);
    optionsScoreToWin.setFillColor(sf::Color::Black);
    optionsScoreToWin.setPosition(170.f, 290.f);

    sf::Text optionsScoreToWinChoices;
    optionsScoreToWinChoices.setFont(FontManager::GetFont("aileronRegular"));
    optionsScoreToWinChoices.setString("7                                  11                                 21");
    optionsScoreToWinChoices.setCharacterSize(20);
    optionsScoreToWinChoices.setFillColor(sf::Color::Black);
    optionsScoreToWinChoices.setPosition(195.f, 320.f);

    sf::Text optionsHitMode;
    optionsHitMode.setFont(FontManager::GetFont("aileronRegular"));
    optionsHitMode.setString("Hit Mode");
    optionsHitMode.setCharacterSize(25);
    optionsHitMode.setFillColor(sf::Color::Black);
    optionsHitMode.setPosition(170.f, 355.f);

    sf::Text optionsHitModeChoice1;
    optionsHitModeChoice1.setFont(FontManager::GetFont("aileronRegular"));
    optionsHitModeChoice1.setStyle(sf::Text::Italic | sf::Text::Underlined);
    optionsHitModeChoice1.setString("Random Shots");
    optionsHitModeChoice1.setCharacterSize(20);
    optionsHitModeChoice1.setFillColor(sf::Color::Black);
    optionsHitModeChoice1.setPosition(195.f, 385.f);

    sf::Text optionsHitModeChoice2;
    optionsHitModeChoice2.setFont(FontManager::GetFont("aileronRegular"));
    optionsHitModeChoice2.setStyle(sf::Text::Italic | sf::Text::Underlined);
    optionsHitModeChoice2.setString("Precise Shots");
    optionsHitModeChoice2.setCharacterSize(20);
    optionsHitModeChoice2.setFillColor(sf::Color::Black);
    optionsHitModeChoice2.setPosition(425.f, 385.f);

    sf::Text creditsTitle;
    creditsTitle.setFont(FontManager::GetFont("yosterIsland"));
    creditsTitle.setString("Credits");
    creditsTitle.setCharacterSize(50);
    creditsTitle.setFillColor(sf::Color::Black);
    creditsTitle.setPosition(165.f, 100.f);

    sf::Text creditsText;
    creditsText.setFont(FontManager::GetFont("aileronRegular"));
    creditsText.setString("                           Ideas, Programming, and Game Design\n                                                      Mateo Graber\n\n                                                       Visual Assets\n                 Mateo Graber            Pixabay            Magnific (Freepik)\n\n                                                             Audio\n                                           Pixabay             Mateo Graber\n\n                                                             Fonts\n                                      FontSpace            1001 Fonts\n\n                                                    Special Thanks\n                        Photopea          FreeConvert          ImageColorPicker");
    creditsText.setCharacterSize(20);
    creditsText.setFillColor(sf::Color::Black);
    creditsText.setPosition(165.f, 160.f);

    int winCondition = 7;
    sf::Text firstToText;
    firstToText.setFont(FontManager::GetFont("komikaAxis"));
    firstToText.setString("First to " + to_string(winCondition));
    firstToText.setCharacterSize(30);
    firstToText.setOutlineColor(sf::Color::Cyan);
    firstToText.setOutlineThickness(1.f);
    firstToText.setFillColor(sf::Color::Black);
    firstToText.setPosition(360.f, 330.f);

    int playerScoreNum = 0;
    sf::Text playerScore;
    playerScore.setFont(FontManager::GetFont("aileronRegular"));
    if (playerScoreNum < 10)
        playerScore.setString("0" + to_string(playerScoreNum));
    else
        playerScore.setString(to_string(playerScoreNum));
    playerScore.setCharacterSize(30);
    playerScore.setFillColor(sf::Color::Green);
    playerScore.setPosition(465.f, 40.f);

    int randomCPUScoreNum = 0;
    sf::Text randomCPUScore;
    randomCPUScore.setFont(FontManager::GetFont("aileronRegular"));
    if (randomCPUScoreNum < 10)
        randomCPUScore.setString("0" + to_string(randomCPUScoreNum));
    else
        randomCPUScore.setString(to_string(randomCPUScoreNum));
    randomCPUScore.setCharacterSize(30);
    randomCPUScore.setFillColor(sf::Color::Green);
    randomCPUScore.setPosition(410.f, 40.f);

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
    sprites.emplace("clayCourt", clayCourt);
    sprites.emplace("hardCourt", hardCourt);
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
    sprites.emplace("niceShotText", niceShotText);
    sprites.emplace("goodTryText", goodTryText);
    sprites.emplace("winScreen", winScreen);
    sprites.emplace("lossScreen", lossScreen);
    sprites.emplace("titleScreenButton", titleScreenButton);
    sprites.emplace("playAgainButton", playAgainButton);
    sprites.emplace("volumeRadio1", volumeRadio1);
    sprites.emplace("volumeRadio2", volumeRadio2);
    sprites.emplace("volumeRadio3", volumeRadio3);
    sprites.emplace("volumeRadio4", volumeRadio4);
    sprites.emplace("volumeRadio5", volumeRadio5);
    sprites.emplace("volumeRadioSelected", volumeRadioSelected);
    sprites.emplace("courtRadio1", courtRadio1);
    sprites.emplace("courtRadio2", courtRadio2);
    sprites.emplace("courtRadio3", courtRadio3);
    sprites.emplace("courtRadioSelected", courtRadioSelected);
    sprites.emplace("scoreToWinRadio1", scoreToWinRadio1);
    sprites.emplace("scoreToWinRadio2", scoreToWinRadio2);
    sprites.emplace("scoreToWinRadio3", scoreToWinRadio3);
    sprites.emplace("scoreToWinRadioSelected", scoreToWinRadioSelected);
    sprites.emplace("hitModeRadio1", hitModeRadio1);
    sprites.emplace("hitModeRadio2", hitModeRadio2);
    sprites.emplace("hitModeRadioSelected", hitModeRadioSelected);
    sprites.emplace("randomMoreInfoBox", randomMoreInfoBox);
    sprites.emplace("preciseMoreInfoBox", preciseMoreInfoBox);

    unordered_map<string, sf::Sound> sounds;
    sounds.emplace("magicButtonClick", magicButtonClick);
    sounds.emplace("characterSelectClick", characterSelectClick);
    sounds.emplace("arcadeCountdown", arcadeCountdown);
    sounds.emplace("racketSwing", racketSwing);
    sounds.emplace("tennisBallHit", tennisBallHit);
    sounds.emplace("niceShot", niceShot);
    sounds.emplace("goodTry", goodTry);
    sounds.emplace("winSound", winSound);
    sounds.emplace("lossSound", lossSound);

    unordered_map<string, sf::Text> texts;
    texts.emplace("rulesTitle", rulesTitle);
    texts.emplace("rulesText", rulesText);
    texts.emplace("optionsTitle", optionsTitle);
    texts.emplace("optionsVolume", optionsVolume);
    texts.emplace("optionsVolumeChoices", optionsVolumeChoices);
    texts.emplace("optionsCourt", optionsCourt);
    texts.emplace("optionsCourtChoices", optionsCourtChoices);
    texts.emplace("optionsScoreToWin", optionsScoreToWin);
    texts.emplace("optionsScoreToWinChoices", optionsScoreToWinChoices);
    texts.emplace("optionsHitMode", optionsHitMode);
    texts.emplace("optionsHitModeChoice1", optionsHitModeChoice1);
    texts.emplace("optionsHitModeChoice2", optionsHitModeChoice2);
    texts.emplace("creditsTitle", creditsTitle);
    texts.emplace("creditsText", creditsText);
    texts.emplace("playerScore", playerScore);
    texts.emplace("randomCPUScore", randomCPUScore);
    texts.emplace("firstToText", firstToText);
    
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
    bool isSwingingCPU = false;
    bool isServe = true;
    bool isNextPoint = false;
    bool isRandomClicked = false;
    bool isPreciseClicked = false;
    bool isTitleScreen = true;
    bool isRulesPage = false;
    bool isOptionsPage = false;
    bool isCreditsPage = false;
    bool isCharacterSelectScreen = false;
    bool isGameScreen = false;
    int characterSelected = 1;
    int randomCPU = characterSelected;
    int pointNumber = 1;
    int gameWinner = 0;
    int courtSelected = 1;
    float volumeSelected = 100.f;
    float tennisBallSpeed = 0.15f;
    float tennisBallY = Random::Float(-0.13f, -0.05f);
    string characterName = "dash";
    string randomCPUName = "dash";
    string hitMode = "randomShots";

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
                        sounds["magicButtonClick"].play();
                        isCharacterSelectScreen = true;
                        isTitleScreen = false;
                        continue;
                    }
                    if (rulesButton.getGlobalBounds().contains(mousePos.x, mousePos.y) && isTitleScreen) {
                        sounds["magicButtonClick"].play();
                        isRulesPage = true;
                        isTitleScreen = false;
                        isOptionsPage = false;
                        isCreditsPage = false;
                    }
                    if (optionsButton.getGlobalBounds().contains(mousePos.x, mousePos.y) && isTitleScreen) {
                        sounds["magicButtonClick"].play();
                        isOptionsPage = true;
                        isTitleScreen = false;
                        isRulesPage = false;
                        isCreditsPage = false;
                    }
                    if (creditsButton.getGlobalBounds().contains(mousePos.x, mousePos.y) && isTitleScreen) {
                        sounds["magicButtonClick"].play();
                        isCreditsPage = true;
                        isTitleScreen = false;
                        isRulesPage = false;
                        isOptionsPage = false;
                    }
                    if (volumeRadio1.getGlobalBounds().contains(mousePos.x, mousePos.y) && isOptionsPage) {
                        sounds["magicButtonClick"].play();
                        sprites["volumeRadioSelected"].setPosition(175.f, 195.f);
                        volumeSelected = 0.f;
                        ChangeVolume(volumeSelected, backgroundMusic, sounds);
                    }
                    if (volumeRadio2.getGlobalBounds().contains(mousePos.x, mousePos.y) && isOptionsPage) {
                        sounds["magicButtonClick"].play();
                        sprites["volumeRadioSelected"].setPosition(270.f, 195.f);
                        volumeSelected = 25.f;
                        ChangeVolume(volumeSelected, backgroundMusic, sounds);
                    }
                    if (volumeRadio3.getGlobalBounds().contains(mousePos.x, mousePos.y) && isOptionsPage) {
                        sounds["magicButtonClick"].play();
                        sprites["volumeRadioSelected"].setPosition(389.f, 195.f);
                        volumeSelected = 50.f;
                        ChangeVolume(volumeSelected, backgroundMusic, sounds);
                    }
                    if (volumeRadio4.getGlobalBounds().contains(mousePos.x, mousePos.y) && isOptionsPage) {
                        sounds["magicButtonClick"].play();
                        sprites["volumeRadioSelected"].setPosition(509.f, 195.f);
                        volumeSelected = 75.f;
                        ChangeVolume(volumeSelected, backgroundMusic, sounds);
                    }
                    if (volumeRadio5.getGlobalBounds().contains(mousePos.x, mousePos.y) && isOptionsPage) {
                        sounds["magicButtonClick"].play();
                        sprites["volumeRadioSelected"].setPosition(630.f, 195.f);
                        volumeSelected = 100.f;
                        ChangeVolume(volumeSelected, backgroundMusic, sounds);
                    }
                    if (courtRadio1.getGlobalBounds().contains(mousePos.x, mousePos.y) && isOptionsPage) {
                        sounds["magicButtonClick"].play();
                        sprites["courtRadioSelected"].setPosition(175.f, 260.f);
                        courtSelected = 1;
                    }
                    if (courtRadio2.getGlobalBounds().contains(mousePos.x, mousePos.y) && isOptionsPage) {
                        sounds["magicButtonClick"].play();
                        sprites["courtRadioSelected"].setPosition(325.f, 260.f);
                        courtSelected = 2;
                    }
                    if (courtRadio3.getGlobalBounds().contains(mousePos.x, mousePos.y) && isOptionsPage) {
                        sounds["magicButtonClick"].play();
                        sprites["courtRadioSelected"].setPosition(475.f, 260.f);
                        courtSelected = 3;
                    }
                    if (scoreToWinRadio1.getGlobalBounds().contains(mousePos.x, mousePos.y) && isOptionsPage) {
                        sounds["magicButtonClick"].play();
                        sprites["scoreToWinRadioSelected"].setPosition(175.f, 325.f);
                        winCondition = 7;
                        firstToText.setString("First to " + to_string(winCondition));
                    }
                    if (scoreToWinRadio2.getGlobalBounds().contains(mousePos.x, mousePos.y) && isOptionsPage) {
                        sounds["magicButtonClick"].play();
                        sprites["scoreToWinRadioSelected"].setPosition(325.f, 325.f);
                        winCondition = 11;
                        firstToText.setString("First to " + to_string(winCondition));
                    }
                    if (scoreToWinRadio3.getGlobalBounds().contains(mousePos.x, mousePos.y) && isOptionsPage) {
                        sounds["magicButtonClick"].play();
                        sprites["scoreToWinRadioSelected"].setPosition(475.f, 325.f);
                        winCondition = 21;
                        firstToText.setString("First to " + to_string(winCondition));
                    }
                    if (optionsHitModeChoice1.getGlobalBounds().contains(mousePos.x, mousePos.y) && !isRandomClicked && isOptionsPage) {
                        isRandomClicked = true;
                        continue;
                    }
                    if (randomMoreInfoBox.getGlobalBounds().contains(mousePos.x, mousePos.y) && isRandomClicked && isOptionsPage) {
                        isRandomClicked = false;
                        continue;
                    }
                    if (optionsHitModeChoice2.getGlobalBounds().contains(mousePos.x, mousePos.y) && !isPreciseClicked && isOptionsPage) {
                        isPreciseClicked = true;
                        continue;
                    }
                    if (preciseMoreInfoBox.getGlobalBounds().contains(mousePos.x, mousePos.y) && isPreciseClicked && isOptionsPage) {
                        isPreciseClicked = false;
                        continue;
                    }
                    if (hitModeRadio1.getGlobalBounds().contains(mousePos.x, mousePos.y) && isOptionsPage) {
                        sounds["magicButtonClick"].play();
                        sprites["hitModeRadioSelected"].setPosition(175.f, 390.f);
                        hitMode = "randomShots";
                    }
                    if (hitModeRadio2.getGlobalBounds().contains(mousePos.x, mousePos.y) && isOptionsPage) {
                        sounds["magicButtonClick"].play();
                        sprites["hitModeRadioSelected"].setPosition(405.f, 390.f);
                        hitMode = "preciseShots";
                    }
                    if (closeButton.getGlobalBounds().contains(mousePos.x, mousePos.y) && (isRulesPage || isOptionsPage || isCreditsPage)) {
                        isTitleScreen = true;
                        isRulesPage = false;
                        isOptionsPage = false;
                        isCreditsPage = false;
                    }
                    if (backButton.getGlobalBounds().contains(mousePos.x, mousePos.y) && isCharacterSelectScreen) {
                        sounds["magicButtonClick"].play();
                        isTitleScreen = true;
                        isCharacterSelectScreen = false;
                    }
                    if (dashCharacterModel.getGlobalBounds().contains(mousePos.x, mousePos.y) && isCharacterSelectScreen) {
                        sounds["characterSelectClick"].play();
                        characterSelected = 1;
                    }
                    if (swiftCharacterModel.getGlobalBounds().contains(mousePos.x, mousePos.y) && isCharacterSelectScreen) {
                        sounds["characterSelectClick"].play();
                        characterSelected = 2;
                    }
                    if (heftyCharacterModel.getGlobalBounds().contains(mousePos.x, mousePos.y) && isCharacterSelectScreen) {
                        sounds["characterSelectClick"].play();
                        characterSelected = 3;
                    }
                    if (athenaCharacterModel.getGlobalBounds().contains(mousePos.x, mousePos.y) && isCharacterSelectScreen) {
                        sounds["characterSelectClick"].play();
                        characterSelected = 4;
                    }
                    if (joeCharacterModel.getGlobalBounds().contains(mousePos.x, mousePos.y) && isCharacterSelectScreen) {
                        sounds["characterSelectClick"].play();
                        characterSelected = 5;
                    }
                    if (janeCharacterModel.getGlobalBounds().contains(mousePos.x, mousePos.y) && isCharacterSelectScreen) {
                        sounds["characterSelectClick"].play();
                        characterSelected = 6;
                    }
                    if (okButton.getGlobalBounds().contains(mousePos.x, mousePos.y) && isCharacterSelectScreen) {
                        isGameScreen = true;
                        isCharacterSelectScreen = false;
                        gameStartTime = chrono::high_resolution_clock::now();
                        backgroundMusic.stop();
                        sounds["arcadeCountdown"].play();
                        if (characterSelected == 1) {
                            sprites["dashPlayer"].setPosition(750.f, 235.f);
                            sprites["dashPlayer"].setRotation(0.f);
                            sprites["dashRacket"].setPosition(785.f, 240.f);
                            sprites["dashRacket"].setRotation(60.f);
                        }
                        else if (characterSelected == 2) {
                            sprites["swiftPlayer"].setPosition(750.f, 235.f);
                            sprites["swiftPlayer"].setRotation(0.f);
                            sprites["swiftRacket"].setPosition(785.f, 240.f);
                            sprites["swiftRacket"].setRotation(60.f);
                        }
                        else if (characterSelected == 3) {
                            sprites["heftyPlayer"].setPosition(750.f, 235.f);
                            sprites["heftyPlayer"].setRotation(0.f);
                            sprites["heftyRacket"].setPosition(785.f, 240.f);
                            sprites["heftyRacket"].setRotation(60.f);
                        }
                        else if (characterSelected == 4) {
                            sprites["athenaPlayer"].setPosition(750.f, 235.f);
                            sprites["athenaPlayer"].setRotation(0.f);
                            sprites["athenaRacket"].setPosition(785.f, 240.f);
                            sprites["athenaRacket"].setRotation(60.f);
                        }
                        else if (characterSelected == 5) {
                            sprites["joePlayer"].setPosition(750.f, 235.f);
                            sprites["joePlayer"].setRotation(0.f);
                            sprites["joeRacket"].setPosition(785.f, 240.f);
                            sprites["joeRacket"].setRotation(60.f);
                        }
                        else if (characterSelected == 6) {
                            sprites["janePlayer"].setPosition(750.f, 235.f);
                            sprites["janePlayer"].setRotation(0.f);
                            sprites["janeRacket"].setPosition(785.f, 240.f);
                            sprites["janeRacket"].setRotation(60.f);
                        }
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
                    if (titleScreenButton.getGlobalBounds().contains(mousePos.x, mousePos.y) && gameWinner > 0) {
                        sounds["magicButtonClick"].play();
                        gameWinner = 0;
                        isTitleScreen = true;
                        HandleBackgroundMusic(isMuted, backgroundMusic);
                        isSwung = false;
                        isSwingingCPU = false;
                        characterSelected = 1;
                        randomCPU = characterSelected;
                        characterName = "dash";
                        randomCPUName = "dash";
                        pointNumber = 1;
                        sprites["characterRacketHitZone"].setPosition(720.f, 175.f);
                        sprites["randomCPURacketHitZone"].setPosition(118.f, 433.f);
                        sprites["tennisBall"].setPosition(150.f, 450.f);
                        tennisBallSpeed = 0.15f;
                        tennisBallY = Random::Float(-0.13f, -0.05f);
                        playerScoreNum = 0;
                        randomCPUScoreNum = 0;
                        texts["playerScore"].setString("0" + to_string(playerScoreNum));
                        texts["randomCPUScore"].setString("0" + to_string(randomCPUScoreNum));
                    }
                    if (playAgainButton.getGlobalBounds().contains(mousePos.x, mousePos.y) && gameWinner > 0) {
                        sounds["magicButtonClick"].play();
                        gameWinner = 0;
                        isGameScreen = true;
                        isSwung = false;
                        isSwingingCPU = false;
                        pointNumber = 1;
                        sprites["characterRacketHitZone"].setPosition(720.f, 175.f);
                        sprites["randomCPURacketHitZone"].setPosition(118.f, 433.f);
                        sprites["tennisBall"].setPosition(150.f, 450.f);
                        tennisBallSpeed = 0.15f;
                        tennisBallY = Random::Float(-0.13f, -0.05f);
                        playerScoreNum = 0;
                        randomCPUScoreNum = 0;
                        texts["playerScore"].setString("0" + to_string(playerScoreNum));
                        texts["randomCPUScore"].setString("0" + to_string(randomCPUScoreNum));
                        gameStartTime = chrono::high_resolution_clock::now();
                        sounds["arcadeCountdown"].play();
                        if (characterSelected == 1) {
                            sprites["dashPlayer"].setPosition(750.f, 235.f);
                            sprites["dashPlayer"].setRotation(0.f);
                            sprites["dashRacket"].setPosition(785.f, 240.f);
                            sprites["dashRacket"].setRotation(60.f);
                        }
                        else if (characterSelected == 2) {
                            sprites["swiftPlayer"].setPosition(750.f, 235.f);
                            sprites["swiftPlayer"].setRotation(0.f);
                            sprites["swiftRacket"].setPosition(785.f, 240.f);
                            sprites["swiftRacket"].setRotation(60.f);
                        }
                        else if (characterSelected == 3) {
                            sprites["heftyPlayer"].setPosition(750.f, 235.f);
                            sprites["heftyPlayer"].setRotation(0.f);
                            sprites["heftyRacket"].setPosition(785.f, 240.f);
                            sprites["heftyRacket"].setRotation(60.f);
                        }
                        else if (characterSelected == 4) {
                            sprites["athenaPlayer"].setPosition(750.f, 235.f);
                            sprites["athenaPlayer"].setRotation(0.f);
                            sprites["athenaRacket"].setPosition(785.f, 240.f);
                            sprites["athenaRacket"].setRotation(60.f);
                        }
                        else if (characterSelected == 5) {
                            sprites["joePlayer"].setPosition(750.f, 235.f);
                            sprites["joePlayer"].setRotation(0.f);
                            sprites["joeRacket"].setPosition(785.f, 240.f);
                            sprites["joeRacket"].setRotation(60.f);
                        }
                        else if (characterSelected == 6) {
                            sprites["janePlayer"].setPosition(750.f, 235.f);
                            sprites["janePlayer"].setRotation(0.f);
                            sprites["janeRacket"].setPosition(785.f, 240.f);
                            sprites["janeRacket"].setRotation(60.f);
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
                    sounds["racketSwing"].play();
                    CharacterSwing(characterName, isSwung, sprites);
                    if (sprites["tennisBall"].getGlobalBounds().intersects(sprites["characterRacketHitZone"].getGlobalBounds())) {
                        sounds["tennisBallHit"].play();
                        tennisBallSpeed = characterPower[characterName] * -1.f;
                        if (hitMode == "randomShots") {
                            if (sprites[characterName + "Player"].getPosition().y <= 312.f)
                                tennisBallY = Random::Float(0.0f, 0.13f);
                            else
                                tennisBallY = Random::Float(-0.13f, 0.0f);
                        }
                        else if (hitMode == "preciseShots") {
                            if (sprites["tennisBall"].getPosition().y >= sprites["characterRacketHitZone"].getPosition().y - 20.f && sprites["tennisBall"].getPosition().y < sprites["characterRacketHitZone"].getPosition().y + 2.f)
                                tennisBallY = -0.08f;
                            if (sprites["tennisBall"].getPosition().y >= sprites["characterRacketHitZone"].getPosition().y + 2.f && sprites["tennisBall"].getPosition().y < sprites["characterRacketHitZone"].getPosition().y + 14.f)
                                tennisBallY = -0.04f;
                            if (sprites["tennisBall"].getPosition().y >= sprites["characterRacketHitZone"].getPosition().y + 14.f && sprites["tennisBall"].getPosition().y < sprites["characterRacketHitZone"].getPosition().y + 26.f)
                                tennisBallY = 0.0f;
                            if (sprites["tennisBall"].getPosition().y >= sprites["characterRacketHitZone"].getPosition().y + 26.f && sprites["tennisBall"].getPosition().y < sprites["characterRacketHitZone"].getPosition().y + 38.f)
                                tennisBallY = 0.04f;
                            if (sprites["tennisBall"].getPosition().y >= sprites["characterRacketHitZone"].getPosition().y + 38.f && sprites["tennisBall"].getPosition().y <= sprites["characterRacketHitZone"].getPosition().y + 60.f)
                                tennisBallY = 0.08f;
                        }
                    }
                }
            }
        }

        window.clear();
        if (isTitleScreen)
            DrawTitleScreen(window, isMuted, courtSelected, sprites);
        if (isRulesPage)
            DrawRulesPage(window, isMuted, courtSelected, sprites, texts);
        if (isOptionsPage)
            DrawOptionsPage(window, isMuted, isRandomClicked, isPreciseClicked, courtSelected, sprites, texts);
        if (isCreditsPage)
            DrawCreditsPage(window, isMuted, courtSelected, sprites, texts);
        if (isCharacterSelectScreen)
            DrawCharacterSelectScreen(window, isMuted, characterSelected, sprites);
        if (isGameScreen) {
            MoveCharacter(characterName, sprites, characterSpeeds);
            MoveRandomCPU(randomCPUName, sprites, characterSpeeds);
            chrono::time_point<chrono::high_resolution_clock> currentTime = chrono::high_resolution_clock::now();
            chrono::duration<double> inGameTime = currentTime - gameStartTime;
            DrawGameScreen(window, isMuted, characterSelected, randomCPU, courtSelected, characterName, randomCPUName, sprites, texts);
            if (inGameTime.count() <= 3.0) {
                window.draw(firstToText);
                if (inGameTime.count() <= 1.0)
                    window.draw(readyText);
                else if (inGameTime.count() <= 2.0)
                    window.draw(setText);
                else
                    window.draw(goText);
            }
            else {
                sprites["tennisBall"].move(tennisBallSpeed, tennisBallY);
                if (sprites["tennisBall"].getGlobalBounds().intersects(sprites["randomCPURacketHitZone"].getGlobalBounds()) && !isSwingingCPU) {
                    isSwingingCPU = true;
                    sounds["racketSwing"].play();
                    thread randomCPUSwingT(RandomCPUSwing, ref(randomCPUName), ref(isSwingingCPU), ref(sprites));
                    randomCPUSwingT.detach();
                    sounds["tennisBallHit"].play();
                    if (!isServe) {
                        tennisBallSpeed = characterPower[randomCPUName];
                        if (sprites[randomCPUName + "Player"].getPosition().y <= 312.f)
                            tennisBallY = Random::Float(0.0f, 0.13f);
                        else
                            tennisBallY = Random::Float(-0.13f, 0.0f);
                    }
                    isServe = false;
                }
                if (sprites["tennisBall"].getPosition().x >= 850.f) {
                    sprites["tennisBall"].setPosition(450.f, 700.f);
                    randomCPUScoreNum++;
                    tennisBallSpeed = 0.f;
                    tennisBallY = 0.f;
                    if (randomCPUScoreNum < 10)
                        texts["randomCPUScore"].setString("0" + to_string(randomCPUScoreNum));
                    else
                        texts["randomCPUScore"].setString(to_string(randomCPUScoreNum));
                    pointNumber++;
                    window.draw(goodTryText);
                    sounds["goodTry"].play();
                    isNextPoint = true;
                }
                if (sprites["tennisBall"].getPosition().x <= 130.f) {
                    sprites["tennisBall"].setPosition(450.f, 700.f);
                    playerScoreNum++;
                    tennisBallSpeed = 0.f;
                    tennisBallY = 0.f;
                    if (playerScoreNum < 10)
                        texts["playerScore"].setString("0" + to_string(playerScoreNum));
                    else
                        texts["playerScore"].setString(to_string(playerScoreNum));
                    pointNumber++;
                    window.draw(niceShotText);
                    sounds["niceShot"].play();
                    isNextPoint = true;
                }
            }
        }
        if (gameWinner == 1)
            DrawWinScreen(window, sprites);
        if (gameWinner == 2)
            DrawLossScreen(window, sprites);
        window.display();
        if (isSwung) {
            thread characterSwingT(CharacterSwing, ref(characterName), ref(isSwung), ref(sprites));
            characterSwingT.detach();
        }
        if (isNextPoint) {
            isNextPoint = false;
            if (playerScoreNum >= winCondition) {
                gameWinner = 1;
                isGameScreen = false;
            }
            if (randomCPUScoreNum >= winCondition) {
                gameWinner = 2;
                isGameScreen = false;
            }
            StartNextPoint(pointNumber, gameWinner, tennisBallSpeed, tennisBallY, characterName, randomCPUName, isServe, sprites, sounds);
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
