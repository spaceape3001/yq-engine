////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <glm/glm.hpp>

namespace yq {
    namespace tachyon {

        //! Standard Push Data
        struct StdPushData {
            glm::mat4       matrix; // either view or render... depending on enumeration
            float           time        = 0;
        };
    }
}
