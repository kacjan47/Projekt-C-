#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

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