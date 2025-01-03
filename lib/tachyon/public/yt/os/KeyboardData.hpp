////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/TachyonData.hpp>
#include <yt/typedef/keyboard.hpp>

namespace yq::tachyon {
    struct KeyboardSnap : public TachyonSnap {
    };
    
    struct KeyboardData : public TachyonData {
    };
}
