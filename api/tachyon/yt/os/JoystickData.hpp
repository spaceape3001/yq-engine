////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/TachyonData.hpp>
#include <yt/typedef/joystick.hpp>
#include <yt/os/HatState.hpp>

namespace yq::tachyon {
    struct JoystickSnap : public TachyonSnap {
        std::string             name, guid;
        std::vector<float>      axes;
        std::vector<bool>       buttons;
        std::vector<HatState>   hats;
    };
    
    struct JoystickData : public TachyonData {
    };
}
