#pragma once

namespace Arkanoid
{
    enum class GameState
    {
        Menu = 0,
        MenuOverlay,
        GameLoop,
        Delay
    };

    enum class MenuState
    {
        Main = 0,
        Pause,
        GameOver,
        Settings,
        Resolution,
        LevelSelect,
        Leaderboard,
        SetPlayerName
    };

    enum class DelayType
    {
        GameStart = 0,
        GameOver
    };

    struct Delay
    {
        float timer;
        float duration;
        GameState nextGameState;
        MenuState nextMenuState;
        DelayType type;
    };

}