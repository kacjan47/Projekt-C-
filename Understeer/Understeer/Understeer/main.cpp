#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include "init.h"

float currentSpeed = 0.0f;
bool accelerating = false;
bool isAccelerating = false;
bool wasKeyPressed = false;
sf::Clock keyTimer;
const float rotationSpeed = 1.25f;
const float acceleration = 0.015f; // Przyspieszenie
const float deceleration = 0.01f; // Hamowanie
const float maxSpeed = 2.1f;
float lastAcceleratingSpeed = 0.0f;
int lapsCompleted = 0;
bool raceFinished = false;
bool lapCounted = false;

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Understeer");
    window.setFramerateLimit(60);
    sf::Texture finishLineTexture;
    if (!finishLineTexture.loadFromFile("Sprites/finish_line.png")) {
        // Obs³uga b³êdu ³adowania tekstury
    }

    sf::Sprite finishLineSprite;
    finishLineSprite.setTexture(finishLineTexture);
    finishLineSprite.setOrigin(finishLineSprite.getLocalBounds().width / 2.0f, finishLineSprite.getLocalBounds().height / 2.0f);
    finishLineSprite.setPosition(125.0f, 240.0f);

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Sprites/desert1.png"))
    {
        // error...
    }
    sf::Font buttonFont;
    if (!buttonFont.loadFromFile("Fonts/KOMIKAX_.ttf"))
    {
        // error...
    }
    sf::Font titleFont;
    if (!titleFont.loadFromFile("Fonts/Freshman.ttf"))
    {
        // error...
    }
    sf::Texture carTexture;
    if (!carTexture.loadFromFile("Sprites/car1.png"))
    {
        // error...
    }
    sf::Texture raceTrack1Texture;
    if (!raceTrack1Texture.loadFromFile("Sprites/racetrack1.png"))
    {
        // error...
    }
    sf::Texture roadTexture;
    if (!roadTexture.loadFromFile("Sprites/road.png"))
    {
        // error...
    }
    sf::Text titleText("UNDERSTEER", titleFont, 80);
    titleText.setFillColor(sf::Color::Black);
    titleText.setPosition(115, 40);

    sf::Sprite roadSprite;
    roadSprite.setTexture(roadTexture);
    roadSprite.setOrigin(roadSprite.getLocalBounds().width / 2.0f, roadSprite.getLocalBounds().height / 2.0f);

    std::vector<sf::Sprite> roadSprites;
    for (int i = 0; i < 1300; ++i) {
        sf::Sprite roadPart(roadTexture);
        roadPart.setOrigin(roadPart.getLocalBounds().width / 2.0f, roadPart.getLocalBounds().height / 2.0f);
        roadSprites.push_back(roadPart);
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 34; j++)
        {  
            int index = i * 34 + j;
            roadSprites[index].setPosition(100.0f + i * 10.0f, 150.0f + j * 10.0f);
        }
    }
    roadSprites[216].setPosition(160.0f, 160.0f);
    roadSprites[217].setPosition(160.0f, 150.0f);
    roadSprites[218].setPosition(170.0f, 150.0f);
    roadSprites[219].setPosition(110.0f, 140.0f);
    roadSprites[220].setPosition(120.0f, 140.0f);
    roadSprites[221].setPosition(130.0f, 140.0f);
    roadSprites[222].setPosition(140.0f, 140.0f);
    roadSprites[223].setPosition(150.0f, 140.0f);
    roadSprites[224].setPosition(160.0f, 140.0f);
    roadSprites[225].setPosition(170.0f, 140.0f);
    roadSprites[226].setPosition(180.0f, 140.0f);
    roadSprites[227].setPosition(120.0f, 130.0f);
    roadSprites[228].setPosition(130.0f, 130.0f);
    roadSprites[229].setPosition(140.0f, 130.0f);
    roadSprites[230].setPosition(150.0f, 130.0f);
    roadSprites[231].setPosition(160.0f, 130.0f);
    roadSprites[232].setPosition(170.0f, 130.0f);
    roadSprites[233].setPosition(180.0f, 130.0f);
    roadSprites[234].setPosition(190.0f, 130.0f);
    roadSprites[235].setPosition(200.0f, 130.0f);
    roadSprites[236].setPosition(210.0f, 130.0f);
    roadSprites[237].setPosition(220.0f, 130.0f);
    roadSprites[238].setPosition(230.0f, 130.0f);
    roadSprites[239].setPosition(240.0f, 130.0f);
    roadSprites[240].setPosition(250.0f, 130.0f);
    roadSprites[241].setPosition(260.0f, 130.0f);
    roadSprites[242].setPosition(270.0f, 130.0f);
    roadSprites[243].setPosition(280.0f, 130.0f);
    roadSprites[244].setPosition(290.0f, 130.0f);
    roadSprites[245].setPosition(300.0f, 130.0f);
    roadSprites[246].setPosition(310.0f, 130.0f);
    roadSprites[247].setPosition(320.0f, 130.0f);
    roadSprites[248].setPosition(330.0f, 130.0f);
    roadSprites[249].setPosition(340.0f, 130.0f);
    roadSprites[250].setPosition(350.0f, 130.0f);
    roadSprites[251].setPosition(130.0f, 120.0f);
    roadSprites[252].setPosition(140.0f, 120.0f);
    roadSprites[253].setPosition(150.0f, 120.0f);
    roadSprites[254].setPosition(160.0f, 120.0f);
    roadSprites[255].setPosition(170.0f, 120.0f);
    roadSprites[256].setPosition(180.0f, 120.0f);
    roadSprites[257].setPosition(190.0f, 120.0f);
    roadSprites[258].setPosition(200.0f, 120.0f);
    roadSprites[259].setPosition(210.0f, 120.0f);
    roadSprites[260].setPosition(220.0f, 120.0f);
    roadSprites[261].setPosition(230.0f, 120.0f);
    roadSprites[262].setPosition(240.0f, 120.0f);
    roadSprites[263].setPosition(250.0f, 120.0f);
    roadSprites[264].setPosition(260.0f, 120.0f);
    roadSprites[265].setPosition(270.0f, 120.0f);
    roadSprites[266].setPosition(280.0f, 120.0f);
    roadSprites[267].setPosition(290.0f, 120.0f);
    roadSprites[268].setPosition(300.0f, 120.0f);
    roadSprites[269].setPosition(310.0f, 120.0f);
    roadSprites[270].setPosition(320.0f, 120.0f);
    roadSprites[271].setPosition(330.0f, 120.0f);
    roadSprites[272].setPosition(340.0f, 120.0f);
    roadSprites[273].setPosition(140.0f, 110.0f);
    roadSprites[274].setPosition(150.0f, 110.0f);
    roadSprites[275].setPosition(160.0f, 110.0f);
    roadSprites[276].setPosition(170.0f, 110.0f);
    roadSprites[277].setPosition(180.0f, 110.0f);
    roadSprites[278].setPosition(190.0f, 110.0f);
    roadSprites[279].setPosition(200.0f, 110.0f);
    roadSprites[280].setPosition(210.0f, 110.0f);
    roadSprites[281].setPosition(220.0f, 110.0f);
    roadSprites[282].setPosition(230.0f, 110.0f);
    roadSprites[283].setPosition(240.0f, 110.0f);
    roadSprites[284].setPosition(250.0f, 110.0f);
    roadSprites[285].setPosition(260.0f, 110.0f);
    roadSprites[286].setPosition(270.0f, 110.0f);
    roadSprites[287].setPosition(280.0f, 110.0f);
    roadSprites[288].setPosition(290.0f, 110.0f);
    roadSprites[289].setPosition(300.0f, 110.0f);
    roadSprites[290].setPosition(310.0f, 110.0f);
    roadSprites[291].setPosition(320.0f, 110.0f);
    roadSprites[292].setPosition(330.0f, 110.0f);
    roadSprites[293].setPosition(150.0f, 100.0f);
    roadSprites[294].setPosition(160.0f, 100.0f);
    roadSprites[295].setPosition(170.0f, 100.0f);
    roadSprites[296].setPosition(180.0f, 100.0f);
    roadSprites[297].setPosition(190.0f, 100.0f);
    roadSprites[298].setPosition(200.0f, 100.0f);
    roadSprites[299].setPosition(210.0f, 100.0f);
    roadSprites[300].setPosition(220.0f, 100.0f);
    roadSprites[301].setPosition(230.0f, 100.0f);
    roadSprites[302].setPosition(240.0f, 100.0f);
    roadSprites[303].setPosition(250.0f, 100.0f);
    roadSprites[304].setPosition(260.0f, 100.0f);
    roadSprites[305].setPosition(270.0f, 100.0f);
    roadSprites[306].setPosition(280.0f, 100.0f);
    roadSprites[307].setPosition(290.0f, 100.0f);
    roadSprites[308].setPosition(300.0f, 100.0f);
    roadSprites[390].setPosition(310.0f, 100.0f);
    roadSprites[391].setPosition(320.0f, 100.0f);
    roadSprites[392].setPosition(160.0f, 90.0f);
    roadSprites[393].setPosition(170.0f, 90.0f);
    roadSprites[394].setPosition(180.0f, 90.0f);
    roadSprites[395].setPosition(190.0f, 90.0f);
    roadSprites[396].setPosition(200.0f, 90.0f);
    roadSprites[397].setPosition(210.0f, 90.0f);
    roadSprites[398].setPosition(220.0f, 90.0f);
    roadSprites[399].setPosition(230.0f, 90.0f);
    roadSprites[400].setPosition(240.0f, 90.0f);
    roadSprites[401].setPosition(250.0f, 90.0f);
    roadSprites[402].setPosition(260.0f, 90.0f);
    roadSprites[403].setPosition(270.0f, 90.0f);
    roadSprites[404].setPosition(280.0f, 90.0f);
    roadSprites[405].setPosition(290.0f, 90.0f);
    roadSprites[406].setPosition(300.0f, 90.0f);
    roadSprites[407].setPosition(310.0f, 90.0f);
    roadSprites[408].setPosition(170.0f, 80.0f);
    roadSprites[409].setPosition(180.0f, 80.0f);
    roadSprites[410].setPosition(190.0f, 80.0f);
    roadSprites[411].setPosition(200.0f, 80.0f);
    roadSprites[412].setPosition(210.0f, 80.0f);
    roadSprites[413].setPosition(220.0f, 80.0f);
    roadSprites[414].setPosition(230.0f, 80.0f);
    roadSprites[415].setPosition(240.0f, 80.0f);
    roadSprites[416].setPosition(250.0f, 80.0f);
    roadSprites[417].setPosition(260.0f, 80.0f);
    roadSprites[418].setPosition(270.0f, 80.0f);
    roadSprites[419].setPosition(280.0f, 80.0f);
    roadSprites[420].setPosition(290.0f, 80.0f);
    roadSprites[421].setPosition(300.0f, 80.0f);
    roadSprites[422].setPosition(360.0f, 140.0f);
    roadSprites[423].setPosition(350.0f, 140.0f);
    roadSprites[424].setPosition(340.0f, 140.0f);
    roadSprites[425].setPosition(330.0f, 140.0f);
    roadSprites[426].setPosition(320.0f, 140.0f);
    roadSprites[427].setPosition(310.0f, 140.0f);
    roadSprites[428].setPosition(300.0f, 140.0f);
    roadSprites[429].setPosition(290.0f, 140.0f);
    roadSprites[430].setPosition(370.0f, 150.0f);
    roadSprites[431].setPosition(360.0f, 150.0f);
    roadSprites[432].setPosition(350.0f, 150.0f);
    roadSprites[433].setPosition(340.0f, 150.0f);
    roadSprites[434].setPosition(330.0f, 150.0f);
    roadSprites[435].setPosition(320.0f, 150.0f);
    roadSprites[436].setPosition(310.0f, 150.0f);
    roadSprites[437].setPosition(300.0f, 150.0f);
    roadSprites[438].setPosition(370.0f, 160.0f);
    roadSprites[439].setPosition(360.0f, 160.0f);
    roadSprites[440].setPosition(350.0f, 160.0f);
    roadSprites[441].setPosition(340.0f, 160.0f);
    roadSprites[442].setPosition(330.0f, 160.0f);
    roadSprites[443].setPosition(320.0f, 160.0f);
    roadSprites[444].setPosition(310.0f, 160.0f);
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            int index = 445 + i * 14 + j;
            roadSprites[index].setPosition(320.0f + i * 10.0f, 170.0f + j * 10.0f);
        }
    }
    roadSprites[529].setPosition(380.0f, 290.0f);
    roadSprites[530].setPosition(380.0f, 300.0f);
    roadSprites[531].setPosition(390.0f, 300.0f);
    for (int i = 0; i < 9; i++)
    {
        int index = 532 + i;
        roadSprites[index].setPosition(330.0f + i * 10.0f, 310.0f);
    }
    for (int i = 0; i < 26; i++)
    {
        int index = 540 + i;
        roadSprites[index].setPosition(340.0f + i * 10.0f, 320.0f);
    }
    for (int i = 0; i < 26; i++)
    {
        int index = 566 + i;
        roadSprites[index].setPosition(350.0f + i * 10.0f, 330.0f);
    }
    for (int i = 0; i < 26; i++)
    {
        int index = 592 + i;
        roadSprites[index].setPosition(360.0f + i * 10.0f, 340.0f);
    }
    for (int i = 0; i < 26; i++)
    {
        int index = 618 + i;
        roadSprites[index].setPosition(370.0f + i * 10.0f, 350.0f);
    }
    for (int i = 0; i < 26; i++)
    {
        int index = 644 + i;
        roadSprites[index].setPosition(380.0f + i * 10.0f, 360.0f);
    }
    for (int i = 0; i < 26; i++)
    {
        int index = 670 + i;
        roadSprites[index].setPosition(390.0f + i * 10.0f, 370.0f);
    }
    roadSprites[696].setPosition(580.0f, 380.0f);
    roadSprites[697].setPosition(590.0f, 380.0f);
    roadSprites[698].setPosition(590.0f, 390.0f);
    roadSprites[699].setPosition(600.0f, 380.0f);
    roadSprites[700].setPosition(600.0f, 390.0f);
    roadSprites[701].setPosition(600.0f, 400.0f);
    for (int i = 0; i < 17; i++)
    {
        int index = 702 + i;
        roadSprites[index].setPosition(610.0f, 370.0f + i * 10.0f);
    }
    for (int i = 0; i < 16; i++)
    {
        int index = 719 + i;
        roadSprites[index].setPosition(620.0f, 370.0f + i * 10.0f);
    }
    for (int i = 0; i < 15; i++)
    {
        int index = 735 + i;
        roadSprites[index].setPosition(630.0f, 370.0f + i * 10.0f);
    }
    for (int i = 0; i < 14; i++)
    {
        int index = 750 + i;
        roadSprites[index].setPosition(640.0f, 370.0f + i * 10.0f);
    }
    for (int i = 0; i < 12; i++)
    {
        int index = 764 + i;
        roadSprites[index].setPosition(650.0f, 380.0f + i * 10.0f);
    }
    for (int i = 0; i < 10; i++)
    {
        int index = 776 + i;
        roadSprites[index].setPosition(660.0f, 390.0f + i * 10.0f);
    }
    for (int i = 0; i < 9; i++)
    {
        int index = 786 + i;
        roadSprites[index].setPosition(600.0f, 460.0f + i * 10.0f);
    }
    for (int i = 0; i < 9; i++)
    {
        int index = 794 + i;
        roadSprites[index].setPosition(590.0f, 470.0f + i * 10.0f);
    }
    for (int i = 0; i < 8; i++)
    {
        int index = 802 + i;
        roadSprites[index].setPosition(580.0f, 480.0f + i * 10.0f);
    }
    int help = 0;
    for (int i = 0; i < 48; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            int index = 810 + help;
            roadSprites[index].setPosition(100.0f + i * 10.0f, 490.0f + j * 10.0f);
            help++;
        }
    }
    sf::Sprite raceTrack1Background;
    raceTrack1Background.setTexture(raceTrack1Texture);
    sf::Sprite startMenuBackground;
    startMenuBackground.setTexture(backgroundTexture);
    sf::Sprite carSprite;
    carSprite.setTexture(carTexture);
    carSprite.setOrigin(carSprite.getLocalBounds().width / 2.0f, carSprite.getLocalBounds().height / 2.0f);
    carSprite.setPosition(100.0f,400.0f);

    // Przyciski menu startowego
    sf::RectangleShape startButton(sf::Vector2f(300, 50));
    startButton.setPosition(250, 200);

    sf::RectangleShape settingsButton(sf::Vector2f(300, 50));
    settingsButton.setPosition(250, 300);

    sf::RectangleShape exitButton(sf::Vector2f(300, 50));
    exitButton.setPosition(250, 400);

    sf::Text startText("Start", buttonFont, 30);
    startText.setFillColor(sf::Color::Black);
    sf::FloatRect startTextRect = startText.getLocalBounds();
    startText.setOrigin(startTextRect.left + startTextRect.width / 2.0f, startTextRect.top + startTextRect.height / 2.0f);
    startText.setPosition(startButton.getPosition().x + startButton.getSize().x / 2.0f, startButton.getPosition().y + startButton.getSize().y / 2.0f);

    sf::Text settingsText("Settings", buttonFont, 30);
    settingsText.setFillColor(sf::Color::Black);
    sf::FloatRect settingsTextRect = settingsText.getLocalBounds();
    settingsText.setOrigin(settingsTextRect.left + settingsTextRect.width / 2.0f, settingsTextRect.top + settingsTextRect.height / 2.0f);
    settingsText.setPosition(settingsButton.getPosition().x + settingsButton.getSize().x / 2.0f, settingsButton.getPosition().y + settingsButton.getSize().y / 2.0f);

    sf::Text exitText("Exit", buttonFont, 30);
    exitText.setFillColor(sf::Color::Black);
    sf::FloatRect exitTextRect = exitText.getLocalBounds();
    exitText.setOrigin(exitTextRect.left + exitTextRect.width / 2.0f, exitTextRect.top + exitTextRect.height / 2.0f);
    exitText.setPosition(exitButton.getPosition().x + exitButton.getSize().x / 2.0f, exitButton.getPosition().y + exitButton.getSize().y / 2.0f);

    // Przyciski pierwszego submenu
    sf::RectangleShape newGameButton(sf::Vector2f(300, 50));
    newGameButton.setPosition(250, 200);

    sf::RectangleShape loadGameButton(sf::Vector2f(300, 50));
    loadGameButton.setPosition(250, 300);

    sf::RectangleShape chooseRaceButton(sf::Vector2f(300, 50));
    chooseRaceButton.setPosition(250, 400);

    sf::RectangleShape backToStartButton1(sf::Vector2f(300, 50));
    backToStartButton1.setPosition(250, 500);

    sf::Text newGameText("New Game", buttonFont, 30);
    newGameText.setFillColor(sf::Color::Black);
    sf::FloatRect newGameTextRect = newGameText.getLocalBounds();
    newGameText.setOrigin(newGameTextRect.left + newGameTextRect.width / 2.0f, newGameTextRect.top + newGameTextRect.height / 2.0f);
    newGameText.setPosition(newGameButton.getPosition().x + newGameButton.getSize().x / 2.0f, newGameButton.getPosition().y + newGameButton.getSize().y / 2.0f);

    sf::Text loadGameText("Load Game", buttonFont, 30);
    loadGameText.setFillColor(sf::Color::Black);
    sf::FloatRect loadGameTextRect = loadGameText.getLocalBounds();
    loadGameText.setOrigin(loadGameTextRect.left + loadGameTextRect.width / 2.0f, loadGameTextRect.top + loadGameTextRect.height / 2.0f);
    loadGameText.setPosition(loadGameButton.getPosition().x + loadGameButton.getSize().x / 2.0f, loadGameButton.getPosition().y + loadGameButton.getSize().y / 2.0f);

    sf::Text chooseRaceText("Choose Race", buttonFont, 30);
    chooseRaceText.setFillColor(sf::Color::Black);
    sf::FloatRect chooseRaceTextRect = chooseRaceText.getLocalBounds();
    chooseRaceText.setOrigin(chooseRaceTextRect.left + chooseRaceTextRect.width / 2.0f, chooseRaceTextRect.top + chooseRaceTextRect.height / 2.0f);
    chooseRaceText.setPosition(chooseRaceButton.getPosition().x + chooseRaceButton.getSize().x / 2.0f, chooseRaceButton.getPosition().y + chooseRaceButton.getSize().y / 2.0f);

    sf::Text backToStartText1("Back", buttonFont, 30);
    backToStartText1.setFillColor(sf::Color::Black);
    sf::FloatRect backToStartTextRect1 = backToStartText1.getLocalBounds();
    backToStartText1.setOrigin(backToStartTextRect1.left + backToStartTextRect1.width / 2.0f, backToStartTextRect1.top + backToStartTextRect1.height / 2.0f);
    backToStartText1.setPosition(backToStartButton1.getPosition().x + backToStartButton1.getSize().x / 2.0f, backToStartButton1.getPosition().y + backToStartButton1.getSize().y / 2.0f);

    // Przyciski drugiego submenu
    sf::RectangleShape option1Button(sf::Vector2f(300, 50));
    option1Button.setPosition(250, 200);

    sf::RectangleShape option2Button(sf::Vector2f(300, 50));
    option2Button.setPosition(250, 300);

    sf::RectangleShape backButton2(sf::Vector2f(300, 50));
    backButton2.setPosition(250, 400);

    sf::Text option1Text("Option 1", buttonFont, 30);
    option1Text.setFillColor(sf::Color::Black);
    sf::FloatRect option1TextRect = option1Text.getLocalBounds();
    option1Text.setOrigin(option1TextRect.left + option1TextRect.width / 2.0f, option1TextRect.top + option1TextRect.height / 2.0f);
    option1Text.setPosition(option1Button.getPosition().x + option1Button.getSize().x / 2.0f, option1Button.getPosition().y + option1Button.getSize().y / 2.0f);

    sf::Text option2Text("Option 2", buttonFont, 30);
    option2Text.setFillColor(sf::Color::Black);
    sf::FloatRect option2TextRect = option2Text.getLocalBounds();
    option2Text.setOrigin(option2TextRect.left + option2TextRect.width / 2.0f, option2TextRect.top + option2TextRect.height / 2.0f);
    option2Text.setPosition(option2Button.getPosition().x + option2Button.getSize().x / 2.0f, option2Button.getPosition().y + option2Button.getSize().y / 2.0f);

    sf::Text backText2("Back", buttonFont, 30);
    backText2.setFillColor(sf::Color::Black);
    sf::FloatRect backText2Rect = backText2.getLocalBounds();
    backText2.setOrigin(backText2Rect.left + backText2Rect.width / 2.0f, backText2Rect.top + backText2Rect.height / 2.0f);
    backText2.setPosition(backButton2.getPosition().x + backButton2.getSize().x / 2.0f, backButton2.getPosition().y + backButton2.getSize().y / 2.0f);

    bool inSettings = false;
    bool inSubmenu1 = false;
    bool inSubmenu2 = false;
    bool inGame = false;
    int selectedButton = 0;
    int previousSelectedButton = 0;
    float carRotation = 0.0f;
    sf::Clock gameTimeClock;
    sf::Text gameTimeText("", buttonFont, 30);
    gameTimeText.setFillColor(sf::Color::White);
    gameTimeText.setPosition(500, 20);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (!inSettings) {
                    if (!inSubmenu1) {
                        if (event.key.code == sf::Keyboard::W) {
                            selectedButton = (selectedButton - 1 + 3) % 3; // Nawigacja w menu startowym
                        }
                        else if (event.key.code == sf::Keyboard::S) {
                            selectedButton = (selectedButton + 1) % 3; // Nawigacja w menu startowym
                        }
                        else if (event.key.code == sf::Keyboard::Enter) {
                            if (selectedButton == 0) {
                                // Rozpocznij grê
                                inSubmenu1 = true;
                                previousSelectedButton = selectedButton;
                                selectedButton = 0;
                            }
                            else if (selectedButton == 1) {
                                inSettings = true;
                                selectedButton = 0;
                            }
                            else if (selectedButton == 2) {
                                window.close();
                            }
                        }
                    }
                    else if (!inSubmenu2) {
                        if (event.key.code == sf::Keyboard::W) {
                            selectedButton = (selectedButton - 1 + 4) % 4; // Nawigacja w submenu 1
                        }
                        else if (event.key.code == sf::Keyboard::S) {
                            selectedButton = (selectedButton + 1) % 4; // Nawigacja w submenu 1
                        }
                        else if (event.key.code == sf::Keyboard::Enter) {
                            if (selectedButton == 0) {
                                // Rozpocznij now¹ grê
                                std::cout << "Enter pressed!" << std::endl;
                                inGame = true;
                                inSubmenu1 = false;
                                gameTimeClock.restart();
                            }
                            else if (selectedButton == 1) {
                                // Wczytaj grê
                            }
                            else if (selectedButton == 2) {
                                // Wybierz rasê
                            }
                            else if (selectedButton == 3) {
                                inSubmenu1 = false;
                                selectedButton = previousSelectedButton;
                            }
                        }
                    }
                    else { // Obs³uga submenu 2
                        if (event.key.code == sf::Keyboard::W) {
                            selectedButton = (selectedButton - 1 + 3) % 3; // Nawigacja w submenu 2
                        }
                        else if (event.key.code == sf::Keyboard::S) {
                            selectedButton = (selectedButton + 1) % 3; // Nawigacja w submenu 2
                        }
                        else if (event.key.code == sf::Keyboard::Enter) {
                            if (selectedButton == 0) {
                                // Obs³uga opcji 1
                            }
                            else if (selectedButton == 1) {
                                // Obs³uga opcji 2
                            }
                            else if (selectedButton == 2) {
                                inSubmenu2 = false;
                                selectedButton = previousSelectedButton;
                            }
                        }
                    }
                }
                else {
                    if (event.key.code == sf::Keyboard::W) {
                        selectedButton = (selectedButton - 1 + 3) % 3; // Nawigacja w menu ustawieñ
                    }
                    else if (event.key.code == sf::Keyboard::S) {
                        selectedButton = (selectedButton + 1) % 3; // Nawigacja w menu ustawieñ
                    }
                    else if (event.key.code == sf::Keyboard::Enter) {
                        if (selectedButton == 0) {
                            // Obs³uga opcji 1
                        }
                        else if (selectedButton == 1) {
                            // Obs³uga opcji 2
                        }
                        else if (selectedButton == 2) {
                            inSettings = false;
                            selectedButton = previousSelectedButton;
                        }
                    }
                }
            }
        }
        window.clear();
        
        if (inGame) {
            window.draw(raceTrack1Background);
            for (const auto& roadPart : roadSprites) {
                window.draw(roadPart);
            }
            window.draw(finishLineSprite);
            sf::Time elapsedTime = gameTimeClock.getElapsedTime();
            int minutes = static_cast<int>(elapsedTime.asSeconds()) / 60;
            int seconds = static_cast<int>(elapsedTime.asSeconds()) % 60;

            // Tworzenie tekstu z czasem w formacie "Czas: minuty : sekundy"
            std::string timeString = "Time: " + std::to_string(minutes) + " : " + std::to_string(seconds);
            gameTimeText.setString(timeString);

            // Wyœwietlanie tekstu z czasem
            window.draw(gameTimeText);
            // Logika przyspieszania i hamowania
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                isAccelerating = true;
                wasKeyPressed = true;
                keyTimer.restart();
            }
            else {
                if (wasKeyPressed) {
                    wasKeyPressed = false;
                    keyTimer.restart();
                    lastAcceleratingSpeed = currentSpeed;
                }
                else if (keyTimer.getElapsedTime().asMilliseconds() > 100) {
                    isAccelerating = false;
                }
            }

            if (isAccelerating) {
                if (currentSpeed < maxSpeed) {
                    currentSpeed += acceleration;
                }
            }
            else {
                if (currentSpeed > 0.0f) {
                    currentSpeed -= deceleration; // Logika stopniowego zwalniania
                }
                else {
                    currentSpeed = 0.0f;
                }
            }
            float angleRad = (carRotation - 90.0f) * (3.14159265f / 180.0f);
            float offsetX = currentSpeed * std::cos(angleRad);
            float offsetY = currentSpeed * std::sin(angleRad);
            // Logika poruszania samochodu z pewn¹ prêdkoœci¹
            if (currentSpeed > 0.0f || lastAcceleratingSpeed > 0.0f) {
                for (const auto& roadPart : roadSprites) {
                    if (carSprite.getGlobalBounds().intersects(roadPart.getGlobalBounds())) {
                        if (carSprite.getPosition().x + offsetX > roadPart.getPosition().x - roadPart.getGlobalBounds().width / 2.0f &&
                            carSprite.getPosition().x + offsetX < roadPart.getPosition().x + roadPart.getGlobalBounds().width / 2.0f &&
                            carSprite.getPosition().y + offsetY > roadPart.getPosition().y - roadPart.getGlobalBounds().height / 2.0f &&
                            carSprite.getPosition().y + offsetY < roadPart.getPosition().y + roadPart.getGlobalBounds().height / 2.0f) {
                            carSprite.move(offsetX, offsetY);
                        }
                    }
                }
            }
            if (carSprite.getGlobalBounds().intersects(finishLineSprite.getGlobalBounds()) && !raceFinished && offsetY < 0) {
                if (!lapCounted) {
                    lapsCompleted++;
                    lapCounted = true;
                    std::cout << lapsCompleted;
                    if (lapsCompleted >= 3) {
                        raceFinished = true;
                        // Obliczenie czasu wyœcigu
                        sf::Time elapsedTime = gameTimeClock.getElapsedTime();
                        int minutes = static_cast<int>(elapsedTime.asSeconds()) / 60;
                        int seconds = static_cast<int>(elapsedTime.asSeconds()) % 60;
                        std::string raceTime = "Race Completed in: " + std::to_string(minutes) + " minutes " + std::to_string(seconds) + " seconds";

                        // Wyœwietlenie komunikatu o zakoñczeniu wyœcigu
                        sf::Text raceCompletedText(raceTime, buttonFont, 30);
                        raceCompletedText.setFillColor(sf::Color::White);
                        raceCompletedText.setPosition(250, 250);
                        window.draw(raceCompletedText);
                    }
                }
            }
            else {
                lapCounted = false;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                if (currentSpeed > 0.0f) {
                    currentSpeed -= deceleration * 3; // Logika hamowania
                    if (currentSpeed < 0.0f) {
                        currentSpeed = 0.0f;
                    }
                }
                else {
                    float angleRad = (carRotation - 90.0f) * (3.14159265f / 180.0f); // Zmiana k¹ta na ty³

                    // Ustawienie minimalnej wartoœci prêdkoœci, nawet gdy prêdkoœæ wynosi zero lub jest ujemna
                    float minSpeed = 0.15f;
                    float offsetX = minSpeed * std::cos(angleRad);
                    float offsetY = minSpeed * std::sin(angleRad);

                    // Logika poruszania siê do ty³u
                    for (const auto& roadPart : roadSprites) {
                        if (carSprite.getGlobalBounds().intersects(roadPart.getGlobalBounds())) {
                            if (carSprite.getPosition().x - offsetX > roadPart.getPosition().x - roadPart.getGlobalBounds().width / 2.0f &&
                                carSprite.getPosition().x - offsetX < roadPart.getPosition().x + roadPart.getGlobalBounds().width / 2.0f &&
                                carSprite.getPosition().y - offsetY > roadPart.getPosition().y - roadPart.getGlobalBounds().height / 2.0f &&
                                carSprite.getPosition().y - offsetY < roadPart.getPosition().y + roadPart.getGlobalBounds().height / 2.0f) {
                                carSprite.move(-offsetX, -offsetY);
                            }
                        }
                    }
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                carRotation -= rotationSpeed;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                carRotation += rotationSpeed;
            }

            carSprite.setRotation(carRotation);
            window.draw(carSprite);
        }

        else {
            // Rysuj pozosta³e elementy w zale¿noœci od aktualnego stanu gry
            if (!inSettings) {
                if (!inSubmenu1) {
                    // Rysuj przyciski menu startowego
                    window.draw(startMenuBackground);
                    window.draw(titleText);
                    window.draw(startButton);
                    window.draw(settingsButton);
                    window.draw(exitButton);
                    window.draw(startText);
                    window.draw(settingsText);
                    window.draw(exitText);
                }
                else if (!inSubmenu2) {
                    // Rysuj submenu 1
                    window.draw(startMenuBackground);
                    window.draw(titleText);
                    window.draw(newGameButton);
                    window.draw(loadGameButton);
                    window.draw(chooseRaceButton);
                    window.draw(backToStartButton1);
                    window.draw(newGameText);
                    window.draw(loadGameText);
                    window.draw(chooseRaceText);
                    window.draw(backToStartText1);
                }
                else {
                    // Rysuj submenu 2
                    window.draw(startMenuBackground);
                    window.draw(titleText);
                    window.draw(option1Button);
                    window.draw(option2Button);
                    window.draw(backButton2);
                    window.draw(option1Text);
                    window.draw(option2Text);
                    window.draw(backText2);
                }
            }
            else {
                // Rysuj przyciski menu ustawieñ
                window.draw(startMenuBackground);
                window.draw(titleText);
                window.draw(backButton2);
                window.draw(option1Button);
                window.draw(option2Button);
                window.draw(backText2);
                window.draw(option1Text);
                window.draw(option2Text);
            }
        }
        // Zaznacz przycisk
        if (inSettings) {
            switch (selectedButton) {
            case 0:
                option1Button.setOutlineThickness(2);
                option2Button.setOutlineThickness(0);
                backButton2.setOutlineThickness(0);
                break;
            case 1:
                option1Button.setOutlineThickness(0);
                option2Button.setOutlineThickness(2);
                backButton2.setOutlineThickness(0);
                break;
            case 2:
                option1Button.setOutlineThickness(0);
                option2Button.setOutlineThickness(0);
                backButton2.setOutlineThickness(2);
                break;
            }
        }
        else if (inSubmenu2) {
            switch (selectedButton) {
            case 0:
                option1Button.setOutlineThickness(2);
                option2Button.setOutlineThickness(0);
                backButton2.setOutlineThickness(0);
                break;
            case 1:
                option1Button.setOutlineThickness(0);
                option2Button.setOutlineThickness(2);
                backButton2.setOutlineThickness(0);
                break;
            case 2:
                option1Button.setOutlineThickness(0);
                option2Button.setOutlineThickness(0);
                backButton2.setOutlineThickness(2);
                break;
            }
        }
        else if (inSubmenu1) {
            switch (selectedButton) {
            case 0:
                newGameButton.setOutlineThickness(2);
                loadGameButton.setOutlineThickness(0);
                chooseRaceButton.setOutlineThickness(0);
                backToStartButton1.setOutlineThickness(0);
                break;
            case 1:
                newGameButton.setOutlineThickness(0);
                loadGameButton.setOutlineThickness(2);
                chooseRaceButton.setOutlineThickness(0);
                backToStartButton1.setOutlineThickness(0);
                break;
            case 2:
                newGameButton.setOutlineThickness(0);
                loadGameButton.setOutlineThickness(0);
                chooseRaceButton.setOutlineThickness(2);
                backToStartButton1.setOutlineThickness(0);
                break;
            case 3:
                newGameButton.setOutlineThickness(0);
                loadGameButton.setOutlineThickness(0);
                chooseRaceButton.setOutlineThickness(0);
                backToStartButton1.setOutlineThickness(2);
                break;
            }
        }
        else {
            switch (selectedButton) {
            case 0:
                startButton.setOutlineThickness(2);
                settingsButton.setOutlineThickness(0);
                exitButton.setOutlineThickness(0);
                break;
            case 1:
                startButton.setOutlineThickness(0);
                settingsButton.setOutlineThickness(2);
                exitButton.setOutlineThickness(0);
                break;
            case 2:
                startButton.setOutlineThickness(0);
                settingsButton.setOutlineThickness(0);
                exitButton.setOutlineThickness(2);
                break;
            }
        }
        window.display();
    }
    return 0;
}
