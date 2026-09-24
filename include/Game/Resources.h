#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game/GameMath.h"

namespace Arkanoid
{
    enum class TextureID
    {
        UIFrame1,
        UIFrame2,
        UIFrame3,

        SelectorTopLeft,
        SelectorTopRight,
        SelectorBottomLeft,
        SelectorBottomRight,

        SliderHorizontal,

        Up,
        Down,

        UIFrame4,
        UIFrame5,

        Left,
        Right,

        SliderVertical,

        UIFrame6
    };

    struct Resources
    {
        sf::Texture atlas;
        sf::Texture background;
        sf::Font font;

        sf::Texture buttonEnabled;
        sf::Texture buttonDisabled;
        sf::Texture buttonPressed;
        sf::Texture subMenu;
        sf::Texture subMenuTitle;

        sf::Texture levelNameFrame;
        sf::Texture levelSelectButton;
        sf::Texture levelPreviewFrame;

        sf::Texture leaderboardFrame;
        sf::Texture leaderboardLabelFrame;

        sf::Texture inputMenu;
        sf::Texture inputField;
    };

    void InitResources(Resources &resources);
    void SetSpriteAtlas(const Resources &resources, sf::Sprite &sprite, TextureID id);
    void UpdateSpriteAtlas(sf::Sprite &sprite, TextureID id);
    void SetDefaultText(const Resources &resources, sf::Text &text, const std::string &string);

    sf::IntRect GetTextureRect(TextureID id);
    sf::Vector2f GetTextureOrigin(TextureID id);
    sf::Texture CreateNineSliceTexture(const sf::Texture &atlas, sf::IntRect rect, unsigned int width, unsigned int height);
}