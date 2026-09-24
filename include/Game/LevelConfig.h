#pragma once
#include "Game/GameMath.h"

namespace Arkanoid
{
    class LevelConfig
    {
    public:
        void LoadFromFile(const std::string &filePath);
        void SetEmpty();
        sf::VertexArray GenerateLevelPreview() const;

        const std::string &GetId() const;
        const std::string &GetName() const;

    private:
        std::string id;
        std::string name;
    };
}
