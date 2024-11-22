////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/manager.hpp>

namespace yq::tachyon {
    struct ManagerSnap : public TachyonSnap {
    };
    
    struct ManagerData : public TachyonData {
    };
}
