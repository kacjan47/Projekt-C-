#ifndef MY_GLOBALS_H
#define MY_GLOBALS_H
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
class TextureLoader {
public:
    TextureLoader(); // Konstruktor

    bool loadTextures(); // Metoda do ³adowania tekstur

    sf::Texture backgroundTexture;
    sf::Font buttonFont;
    sf::Font titleFont;
    sf::Texture carTexture;
    sf::Texture raceTrack1Texture;
    sf::Texture roadTexture;
};

extern sf::Texture backgroundTexture;
extern bool inSettings;
extern bool inSubmenu1;
extern bool inSubmenu2;
extern bool inGame, inGame2;
#endif