////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/viewer.hpp>
#include <yq/tachyon/typedef/window.hpp>

namespace yq::tachyon {
    struct ViewerSnap : public TachyonSnap {
        WindowID        window;
        bool            paused  = false;
    };
    
    struct ViewerData : public TachyonData {
    };
}
