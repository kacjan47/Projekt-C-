#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

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

    sf::Text titleText("UNDERSTEER", titleFont, 80);
    titleText.setFillColor(sf::Color::Black);
    titleText.setPosition(115, 40);

    sf::Sprite startMenuBackground;
    startMenuBackground.setTexture(backgroundTexture);

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
    int selectedButton = 0;
    int previousSelectedButton = 0;

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
                                // Rozpocznij gr�
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
                                // Rozpocznij now� gr�
                            }
                            else if (selectedButton == 1) {
                                // Wczytaj gr�
                            }
                            else if (selectedButton == 2) {
                                // Wybierz ras�
                            }
                            else if (selectedButton == 3) {
                                inSubmenu1 = false;
                                selectedButton = previousSelectedButton;
                            }
                        }
                    }
                    else { // Obs�uga submenu 2
                        if (event.key.code == sf::Keyboard::W) {
                            selectedButton = (selectedButton - 1 + 3) % 3; // Nawigacja w submenu 2
                        }
                        else if (event.key.code == sf::Keyboard::S) {
                            selectedButton = (selectedButton + 1) % 3; // Nawigacja w submenu 2
                        }
                        else if (event.key.code == sf::Keyboard::Enter) {
                            if (selectedButton == 0) {
                                // Obs�uga opcji 1
                            }
                            else if (selectedButton == 1) {
                                // Obs�uga opcji 2
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
                        selectedButton = (selectedButton - 1 + 3) % 3; // Nawigacja w menu ustawie�
                    }
                    else if (event.key.code == sf::Keyboard::S) {
                        selectedButton = (selectedButton + 1) % 3; // Nawigacja w menu ustawie�
                    }
                    else if (event.key.code == sf::Keyboard::Enter) {
                        if (selectedButton == 0) {
                            // Obs�uga opcji 1
                        }
                        else if (selectedButton == 1) {
                            // Obs�uga opcji 2
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
            // Rysuj przyciski menu ustawie�
            window.draw(startMenuBackground);
            window.draw(titleText);
            window.draw(backButton2);
            window.draw(option1Button);
            window.draw(option2Button);
            window.draw(backText2);
            window.draw(option1Text);
            window.draw(option2Text);
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