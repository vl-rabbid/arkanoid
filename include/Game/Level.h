#pragma once
#include "Game/Constants.h"
#include "Game/GameMath.h"
#include "Game/Resources.h"
#include "Game/LevelConfig.h"

namespace Arkanoid
{
    class Level
    {
    public:
        void Init(const LevelConfig &config, const Resources &resources);
        void Draw(sf::RenderTexture &texture) const;

        const std::string &GetId() const;
        const std::string &GetName() const;

    private:
        std::string id;
        std::string name;
    };
}