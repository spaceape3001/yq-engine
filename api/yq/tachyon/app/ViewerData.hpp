////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/TachyonData.hpp>
#include <yt/api/ID.hpp>
#include <yt/typedef/viewer.hpp>
#include <yt/typedef/window.hpp>

namespace yq::tachyon {
    struct ViewerSnap : public TachyonSnap {
        WindowID        window;
        bool            paused  = false;
    };
    
    struct ViewerData : public TachyonData {
    };
}
