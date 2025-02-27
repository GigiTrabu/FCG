#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600, 32), "SFML Simple Game");
    window.setFramerateLimit(60);    
    sf::CircleShape player(20.f);
    player.setFillColor(sf::Color::Green);
    player.setPosition(390.f, 290.f);
    
    float speed = 5.f;
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        // Movimento con i tasti freccia
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            player.move(-speed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            player.move(speed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            player.move(0, -speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            player.move(0, speed);
        
        window.clear();
        window.draw(player);
        window.display();
    }
    
    return 0;
}