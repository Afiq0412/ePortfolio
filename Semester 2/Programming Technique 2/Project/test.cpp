#include<SFML/Graphics.hpp>
#include <vector>

class Player {
public:
    sf::RectangleShape shape;
    sf::Vector2f velocity;

    Player() {
        shape.setSize({50, 50});
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(100, 300);
        velocity = {0, 0};
    }

    void jump() {
        if (shape.getPosition().y == 300) { // simplistic ground check
            velocity.y = -15;
        }
    }

    void update() {
        velocity.y += 0.5; // gravity
        shape.move(velocity);

        if (shape.getPosition().y > 300) {
            shape.setPosition(shape.getPosition().x, 300);
            velocity.y = 0;
        }
    }
};

class Obstacle {
public:
    sf::RectangleShape shape;

    Obstacle(float x, float y) {
        shape.setSize({50, 50});
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(x, y);
    }

    void update() {
        shape.move(-5, 0);
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Geometry Dash Clone");
    window.setFramerateLimit(60);

    Player player;
    std::vector<Obstacle> obstacles;

    sf::Clock clock;
    float spawnTimer = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                player.jump();
            }
        }

        float deltaTime = clock.restart().asSeconds();
        spawnTimer += deltaTime;

        if (spawnTimer > 2) {
            spawnTimer = 0;
            obstacles.emplace_back(800, 300);
        }

        player.update();

        for (auto& obstacle : obstacles) {
            obstacle.update();
        }

        window.clear();
        window.draw(player.shape);
        for (const auto& obstacle : obstacles) {
            window.draw(obstacle.shape);
        }
        window.display();
    }

    return 0;
}
