#include "init.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

sf::Texture backgroundTexture;
TextureLoader::TextureLoader() {
    loadTextures();
}
bool TextureLoader::loadTextures() {
    bool success = true;

    if (!backgroundTexture.loadFromFile("Sprites/desert1.png")) {
        // error...
        success = false;
    }

    if (!buttonFont.loadFromFile("Fonts/KOMIKAX_.ttf")) {
        // error...
        success = false;
    }

    if (!titleFont.loadFromFile("Fonts/Freshman.ttf")) {
        // error...
        success = false;
    }

    if (!carTexture.loadFromFile("Sprites/car1.png")) {
        // error...
        success = false;
    }

    if (!raceTrack1Texture.loadFromFile("Sprites/racetrack1.png")) {
        // error...
        success = false;
    }

    if (!roadTexture.loadFromFile("Sprites/road.png")) {
        // error...
        success = false;
    }

    return success;
}
bool inSettings = false;
bool inSubmenu1 = false;
bool inSubmenu2 = false;
bool inGame = false, inGame2 = false;