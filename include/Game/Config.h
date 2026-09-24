#pragma once
#include "Game/Constants.h"

namespace Arkanoid
{
    enum class WindowResolution
    {
        R720x540 = 3,
        R960x720 = 4,
        R1200x900 = 5,
        R1440x1080 = 6
    };

    struct Config
    {
        WindowResolution windowResolution;
        std::string playerName;
        bool soundEnabled;
        bool musicEnabled;
    };

    bool ConfigFileExists();
    void InitConfig(Config &config);
    void SetDefaultConfig(Config &config);
    bool LoadConfig(Config &config);
    bool SaveConfig(Config &config);

}
