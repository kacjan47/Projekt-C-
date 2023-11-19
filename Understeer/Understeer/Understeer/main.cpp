#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Understeer");

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
    for (int i = 0; i < 40; ++i) {
        sf::Sprite roadPart(roadTexture);
        roadPart.setOrigin(roadPart.getLocalBounds().width / 2.0f, roadPart.getLocalBounds().height / 2.0f);
        roadPart.setPosition(100.0f + i * 50.0f, 100.0f);
        roadSprites.push_back(roadPart);
    }
    roadSprites[0].setPosition(100.0f, 100.0f);
    roadSprites[1].setPosition(150.0f, 100.0f);
    roadSprites[2].setPosition(200.0f, 100.0f);
    roadSprites[3].setPosition(250.0f, 100.0f);
    roadSprites[4].setPosition(300.0f, 100.0f);
    roadSprites[5].setPosition(350.0f, 100.0f);
    roadSprites[6].setPosition(400.0f, 100.0f);
    roadSprites[7].setPosition(450.0f, 100.0f);
    roadSprites[8].setPosition(500.0f, 100.0f);
    roadSprites[9].setPosition(550.0f, 100.0f);
    roadSprites[10].setPosition(600.0f, 100.0f);
    roadSprites[11].setPosition(650.0f, 100.0f);
    roadSprites[12].setPosition(700.0f, 100.0f);
    roadSprites[13].setPosition(700.0f, 150.0f);
    roadSprites[14].setPosition(700.0f, 200.0f);
    roadSprites[15].setPosition(700.0f, 250.0f);
    roadSprites[16].setPosition(700.0f, 300.0f);
    roadSprites[17].setPosition(700.0f, 350.0f);
    roadSprites[18].setPosition(700.0f, 400.0f);
    roadSprites[19].setPosition(700.0f, 450.0f);
    roadSprites[20].setPosition(700.0f, 500.0f);
    roadSprites[21].setPosition(650.0f, 500.0f);
    roadSprites[22].setPosition(600.0f, 500.0f);
    roadSprites[23].setPosition(550.0f, 500.0f);
    roadSprites[24].setPosition(500.0f, 500.0f);
    roadSprites[25].setPosition(450.0f, 500.0f);
    roadSprites[26].setPosition(400.0f, 500.0f);
    roadSprites[27].setPosition(350.0f, 500.0f);
    roadSprites[28].setPosition(300.0f, 500.0f);
    roadSprites[29].setPosition(250.0f, 500.0f);
    roadSprites[30].setPosition(200.0f, 500.0f);
    roadSprites[31].setPosition(150.0f, 500.0f);
    roadSprites[32].setPosition(100.0f, 500.0f);
    roadSprites[33].setPosition(100.0f, 450.0f);
    roadSprites[34].setPosition(100.0f, 400.0f);
    roadSprites[35].setPosition(100.0f, 350.0f);
    roadSprites[36].setPosition(100.0f, 300.0f);
    roadSprites[37].setPosition(100.0f, 250.0f);
    roadSprites[38].setPosition(100.0f, 200.0f);
    roadSprites[39].setPosition(100.0f, 150.0f);

    sf::Sprite raceTrack1Background;
    raceTrack1Background.setTexture(raceTrack1Texture);
    sf::Sprite startMenuBackground;
    startMenuBackground.setTexture(backgroundTexture);
    sf::Sprite carSprite;
    carSprite.setTexture(carTexture);
    carSprite.setOrigin(carSprite.getLocalBounds().width / 2.0f, carSprite.getLocalBounds().height / 2.0f);
    carSprite.setPosition(100.0f,100.0f);

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
            float velocity = 0.05f;
            const float rotationSpeed = 0.035f;
            const float acceleration = 0.001f; // Przyspieszenie
            const float deceleration = 0.001f; // Hamowanie
            const float maxSpeed = 0.5f;

            sf::Vector2f carPosition = carSprite.getPosition();
            float carWidth = carSprite.getGlobalBounds().width;
            float carHeight = carSprite.getGlobalBounds().height;


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                    for (const auto& roadPart : roadSprites) {
                        if (carSprite.getGlobalBounds().intersects(roadPart.getGlobalBounds())) {
                            // Samochód znajduje siê w elemencie drogi
                            float angleRad = (carRotation - 90.0f) * (3.14159265f / 180.0f);
                            float offsetX = velocity * std::cos(angleRad);
                            float offsetY = velocity * std::sin(angleRad);

                            // Sprawdzanie czy samochód nie wyje¿d¿a poza element drogi
                            if (carSprite.getPosition().x + offsetX > roadPart.getPosition().x - roadPart.getGlobalBounds().width / 2.0f &&
                                carSprite.getPosition().x + offsetX < roadPart.getPosition().x + roadPart.getGlobalBounds().width / 2.0f &&
                                carSprite.getPosition().y + offsetY > roadPart.getPosition().y - roadPart.getGlobalBounds().height / 2.0f &&
                                carSprite.getPosition().y + offsetY < roadPart.getPosition().y + roadPart.getGlobalBounds().height / 2.0f) {
                                carSprite.move(offsetX, offsetY);
                            }
                        }
                    }
                }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                for (const auto& roadPart : roadSprites) {
                    if (carSprite.getGlobalBounds().intersects(roadPart.getGlobalBounds())) {
                        // Samochód znajduje siê w elemencie drogi
                        float angleRad = (carRotation - 90.0f) * (3.14159265f / 180.0f);
                        float offsetX = velocity * std::cos(angleRad);
                        float offsetY = velocity * std::sin(angleRad);

                        // Sprawdzanie czy samochód nie wyje¿d¿a poza element drogi
                        if (carSprite.getPosition().x + offsetX > roadPart.getPosition().x - roadPart.getGlobalBounds().width / 2.0f &&
                            carSprite.getPosition().x + offsetX < roadPart.getPosition().x + roadPart.getGlobalBounds().width / 2.0f &&
                            carSprite.getPosition().y + offsetY > roadPart.getPosition().y - roadPart.getGlobalBounds().height / 2.0f &&
                            carSprite.getPosition().y + offsetY < roadPart.getPosition().y + roadPart.getGlobalBounds().height / 2.0f) {
                            carSprite.move(-offsetX, -offsetY);
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