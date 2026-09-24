#pragma once

namespace Arkanoid
{
    enum class AppRequestType
    {
        None = 0,
        ExitApplication,
        SetWindowScale
    };

    struct AppRequest
    {
        AppRequestType type = AppRequestType::None;
    };

}
