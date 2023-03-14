#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main (void) {
    sf::RenderWindow window(sf::VideoMode(836, 767), "res");

    sf::Texture mapt;
    mapt.loadFromFile("img/map.tga");

    sf::Sprite maps;
    maps.setTexture(mapt);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Mouse events
            if (event.type == sf::Event::MouseButtonPressed)
                continue;
            if (event.type == sf::Event::MouseButtonReleased)
                continue;
            // Keyboard events
            if (event.type == sf::Event::KeyPressed)
                continue;
            if (event.type == sf::Event::KeyReleased)
                continue;
            // Close Window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        window.draw(maps);

        window.display();
    }

    return 0;
}