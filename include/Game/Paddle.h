#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"

namespace Arkanoid
{
    class Paddle
    {
    public:
        void Init(float width);
        void Update(const float deltaTime);
        void Draw(sf::RenderTexture &texture) const;
        void HandleInput(const sf::Event &event);

        sf::FloatRect GetBounds() const;

    private:
        sf::Vector2f position;
        sf::Vector2f size;
        float speed;
        bool leftPressed;
        bool rightPressed;

        sf::RectangleShape shape;
    };
}
