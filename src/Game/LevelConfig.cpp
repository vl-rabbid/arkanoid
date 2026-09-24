#include "Game/LevelConfig.h"
#include <fstream>
#include <filesystem>

namespace Arkanoid
{
    void LevelConfig::LoadFromFile(const std::string &filePath)
    {
        SetEmpty();
        std::filesystem::path path = filePath;
        id = path.stem().string();
        std::ifstream file(filePath);
        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                int pos = line.find('=');
                if (pos == std::string::npos)
                    continue;

                std::string key = line.substr(0, pos);
                std::string value = line.substr(pos + 1);

                if (key == "name")
                    name = value;
            }
            file.close();
        }
    }

    void LevelConfig::SetEmpty()
    {
        id = "empty";
        name = "Empty";
    }

    sf::VertexArray LevelConfig::GenerateLevelPreview() const
    {
        return {};
    }

    const std::string &LevelConfig::GetId() const
    {
        return id;
    }

    const std::string &LevelConfig::GetName() const
    {
        return name;
    }
}