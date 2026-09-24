#pragma once

namespace Arkanoid
{
    enum class MenuAction
    {
        None = 0,

        MenuMoveVertical,
        MenuMoveHorizontal,
        MenuInput,
        MenuPress,

        SwitchMenuState,
        SwitchGameState,
        StartGame,
        ResetGame,
        ResumeGame,
        PreviousMenu,
        SetScreenScale,
        ToggleSound,
        ToggleMusic,
        SavePlayerName,
        ExitApplication
    };

    struct MenuCommand
    {
        MenuAction action;
        int actionTarget;
    };

}
