/* This is the main execution file */
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <cctype>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <filesystem>
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Photo Viewer");
    sf::Texture texture;

    if (!texture.loadFromFile("example.jpg")) {
        return -1; // Exit if the file could not be loaded
    }

    sf::Sprite sprite(texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}

