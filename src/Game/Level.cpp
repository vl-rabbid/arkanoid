#include "Game/Level.h"

namespace Arkanoid
{
    void Level::Init(const LevelConfig &config, const Resources &resources)
    {
        id = config.GetId();
        name = config.GetName();
    }

    void Level::Draw(sf::RenderTexture &texture) const
    {
    }

    const std::string &Level::GetId() const
    {
        return id;
    }

    const std::string &Level::GetName() const
    {
        return name;
    }
}