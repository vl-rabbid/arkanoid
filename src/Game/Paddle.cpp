#include "Game/Paddle.h"
#include <cmath>

namespace Arkanoid
{
    void Paddle::Init(float width)
    {
        position = {RENDER_WIDTH / 2.f, 165.f};
        leftPressed = false;
        rightPressed = false;
        speed = PADDLE_SPEED;
        size = {width, PADDLE_HEIGHT};

        shape.setSize(size);
        shape.setFillColor(sf::Color::Blue);
        shape.setOrigin(sf::Vector2f(size.x / 2.f, 0.f));
        shape.setPosition(std::round(position.x), std::round(position.y));
    }

    void Paddle::Update(const float deltaTime)
    {
        float direction = 0.f;
        if (rightPressed)
            direction += 1.f;
        if (leftPressed)
            direction -= 1.f;

        position.x += direction * speed * deltaTime;

        float halfWidth = size.x / 2.f;
        if (position.x - halfWidth < 0.f)
            position.x = halfWidth;
        if (position.x + halfWidth > RENDER_WIDTH)
            position.x = RENDER_WIDTH - halfWidth;

        shape.setPosition(std::round(position.x), std::round(position.y));
    }

    void Paddle::Draw(sf::RenderTexture &texture) const
    {
        texture.draw(shape);
    }

    void Paddle::HandleInput(const sf::Event &event)
    {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
            leftPressed = true;
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
            rightPressed = true;

        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Left)
            leftPressed = false;
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right)
            rightPressed = false;
    }

    sf::FloatRect Paddle::GetBounds() const
    {
        return {position.x - size.x / 2.f, position.y, size.x, size.y};
    }
}
