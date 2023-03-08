#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "res");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
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

        window.display();
    }

    return 0;
}