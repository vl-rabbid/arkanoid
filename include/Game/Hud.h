#pragma once
#include <SFML/Graphics.hpp>
#include "Game/Resources.h"
#include "Game/GameMath.h"

namespace Arkanoid
{
    class Hud
    {
    public:
        Hud() = default;

        void Init(const Resources &resources);
        void Draw(sf::RenderTexture &texture) const;

        void SetDelayText(const std::string &string);
        void DrawDelay(sf::RenderTexture &texture) const;

    private:
        sf::RectangleShape windowTint;
        sf::Text delayText;
        sf::Text delayTextShadow;
    };

}
