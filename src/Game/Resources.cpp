#include "Game/Resources.h"
#include <cassert>
#include <string>
#include <array>

namespace Arkanoid
{
    void InitResources(Resources &resources)
    {
        assert(resources.atlas.loadFromFile(std::string(RESOURCES_PATH) + "/graphics/atlas.png"));
        assert(resources.background.loadFromFile(std::string(RESOURCES_PATH) + "/graphics/background.png"));
        assert(resources.font.loadFromFile(std::string(RESOURCES_PATH) + "/fonts/monogram.ttf"));

        resources.buttonEnabled = CreateNineSliceTexture(resources.atlas, GetTextureRect(TextureID::UIFrame1), 90, 19);
        resources.buttonDisabled = CreateNineSliceTexture(resources.atlas, GetTextureRect(TextureID::UIFrame3), 90, 18);
        resources.buttonPressed = CreateNineSliceTexture(resources.atlas, GetTextureRect(TextureID::UIFrame2), 90, 18);

        resources.subMenu = CreateNineSliceTexture(resources.atlas, GetTextureRect(TextureID::UIFrame3), 120, 113);
        resources.subMenuTitle = CreateNineSliceTexture(resources.atlas, GetTextureRect(TextureID::UIFrame2), 100, 17);

        resources.levelNameFrame = CreateNineSliceTexture(resources.atlas, GetTextureRect(TextureID::UIFrame2), 62, 17);
        resources.levelSelectButton = CreateNineSliceTexture(resources.atlas, GetTextureRect(TextureID::UIFrame1), 72, 75);
        resources.levelPreviewFrame = CreateNineSliceTexture(resources.atlas, GetTextureRect(TextureID::UIFrame5), 62, 41);

        resources.leaderboardFrame = CreateNineSliceTexture(resources.atlas, GetTextureRect(TextureID::UIFrame3), 133, 84);
        resources.leaderboardLabelFrame = CreateNineSliceTexture(resources.atlas, GetTextureRect(TextureID::UIFrame2), 95, 17);

        resources.inputMenu = CreateNineSliceTexture(resources.atlas, GetTextureRect(TextureID::UIFrame3), 120, 90);
        resources.inputField = CreateNineSliceTexture(resources.atlas, GetTextureRect(TextureID::UIFrame6), 75, 15);
    }

    void SetSpriteAtlas(const Resources &resources, sf::Sprite &sprite, TextureID id)
    {
        sprite.setTexture(resources.atlas);
        UpdateSpriteAtlas(sprite, id);
    }

    void UpdateSpriteAtlas(sf::Sprite &sprite, TextureID id)
    {
        sprite.setTextureRect(GetTextureRect(id));
        sprite.setOrigin(GetTextureOrigin(id));
    }

    void SetDefaultText(const Resources &resources, sf::Text &text, const std::string &string)
    {
        text.setString(string);
        text.setFont(resources.font);
        text.setCharacterSize(16);
        text.setFillColor(COLOR_TEXT);
    }

    sf::IntRect GetTextureRect(TextureID id)
    {
        switch (id)
        {
        case TextureID::UIFrame1:
            return sf::IntRect(0, 48, 12, 12);
            break;
        case TextureID::UIFrame2:
            return sf::IntRect(12, 48, 12, 12);
            break;
        case TextureID::UIFrame3:
            return sf::IntRect(24, 48, 12, 12);
            break;

        case TextureID::SelectorTopLeft:
            return sf::IntRect(36, 48, 12, 12);
            break;
        case TextureID::SelectorTopRight:
            return sf::IntRect(48, 48, 12, 12);
            break;
        case TextureID::SelectorBottomLeft:
            return sf::IntRect(60, 48, 12, 12);
            break;
        case TextureID::SelectorBottomRight:
            return sf::IntRect(72, 48, 12, 12);
            break;

        case TextureID::SliderVertical:
            return sf::IntRect(84, 48, 12, 12);
            break;

        case TextureID::Up:
            return sf::IntRect(96, 48, 12, 12);
            break;
        case TextureID::Down:
            return sf::IntRect(108, 48, 12, 12);
            break;

        case TextureID::UIFrame4:
            return sf::IntRect(120, 48, 12, 12);
            break;
        case TextureID::UIFrame5:
            return sf::IntRect(132, 48, 12, 12);
            break;

        case TextureID::Left:
            return sf::IntRect(0, 60, 12, 12);
            break;
        case TextureID::Right:
            return sf::IntRect(12, 60, 12, 12);
            break;

        case TextureID::SliderHorizontal:
            return sf::IntRect(24, 60, 12, 12);
            break;

        case TextureID::UIFrame6:
            return sf::IntRect(36, 60, 12, 12);
            break;

        default:
            break;
        }
        return sf::IntRect(0, 0, 12, 12);
    }

    sf::Vector2f GetTextureOrigin(TextureID id)
    {
        switch (id)
        {
        case TextureID::SelectorTopLeft:
            return {2.f, 3.f};
            break;
        case TextureID::SelectorTopRight:
            return {6.f, 3.f};
            break;
        case TextureID::SelectorBottomLeft:
            return {2.f, 11.f};
            break;
        case TextureID::SelectorBottomRight:
            return {6.f, 11.f};
            break;

        case TextureID::Right:
            return {6.f, 4.f};
            break;
        case TextureID::Left:
            return {0.f, 4.f};
            break;
        case TextureID::Up:
            return {4.f, 8.f};
            break;
        case TextureID::Down:
            return {4.f, 0.f};
            break;
        case TextureID::SliderHorizontal:
            return {5.f, 3.f};
            break;
        case TextureID::SliderVertical:
            return {3.f, 5.f};
            break;

        default:
            return {0.f, 0.f};
            break;
        }
    }

    sf::Texture CreateNineSliceTexture(const sf::Texture &atlas, sf::IntRect rect, unsigned int width, unsigned int height)
    {
        const unsigned int borderLeft = 4;
        const unsigned int borderRight = 4;
        const unsigned int borderTop = 4;
        const unsigned int borderBottom = 6;
        unsigned int centralWidth = rect.width - borderLeft - borderRight;
        unsigned int centralHeight = rect.height - borderTop - borderBottom;

        sf::Texture resultTexture;
        sf::RenderTexture renderTexture;
        renderTexture.create(width, height);
        renderTexture.clear(sf::Color::Transparent);

        auto drawPart = [&](int sourceX, int sourceY, int sourceWidth, int sourceHight,
                            float destinationX, float destinationY, float destinationWidth, float destinationHight)
        {
            sf::Sprite sprite;
            sprite.setTexture(atlas);
            sprite.setTextureRect(sf::IntRect(rect.left + sourceX, rect.top + sourceY, sourceWidth, sourceHight));
            sprite.setPosition(destinationX, destinationY);
            sprite.setScale(destinationWidth / sourceWidth, destinationHight / sourceHight);
            renderTexture.draw(sprite);
        };

        unsigned int centralTargetWidth = width - borderLeft - borderRight;
        unsigned int centralTargetHeight = height - borderTop - borderBottom;

        // Top
        drawPart(0, 0, borderLeft, borderTop,
                 0, 0, borderLeft, borderTop);
        drawPart(borderLeft, 0, centralWidth, borderTop,
                 borderLeft, 0, centralTargetWidth, borderTop);
        drawPart(borderLeft + centralWidth, 0, borderRight, borderTop,
                 borderLeft + centralTargetWidth, 0, borderRight, borderTop);
        // Center
        drawPart(0, borderTop, borderLeft, centralHeight,
                 0, borderTop, borderLeft, centralTargetHeight);
        drawPart(borderLeft, borderTop, centralWidth, centralHeight,
                 borderLeft, borderTop, centralTargetWidth, centralTargetHeight);
        drawPart(borderLeft + centralWidth, borderTop, borderRight, centralHeight,
                 borderLeft + centralTargetWidth, borderTop, borderRight, centralTargetHeight);
        // Bottom
        drawPart(0, borderTop + centralHeight, borderLeft, borderBottom,
                 0, borderTop + centralTargetHeight, borderLeft, borderBottom);
        drawPart(borderLeft, borderTop + centralHeight, centralWidth, borderBottom,
                 borderLeft, borderTop + centralTargetHeight, centralTargetWidth, borderBottom);
        drawPart(borderLeft + centralWidth, borderTop + centralHeight, borderRight, borderBottom,
                 borderLeft + centralTargetWidth, borderTop + centralTargetHeight, borderRight, borderBottom);

        renderTexture.display();
        sf::Image image;
        image = renderTexture.getTexture().copyToImage();
        resultTexture.loadFromImage(image);
        resultTexture.setSmooth(false);
        return resultTexture;
    }
}