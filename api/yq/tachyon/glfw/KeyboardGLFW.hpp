////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/desktop/Keyboard.hpp>

namespace yq::tachyon {
    class KeyboardGLFW : public Keyboard {
        YQ_TACHYON_DECLARE(KeyboardGLFW, Keyboard)
    public:
        KeyboardGLFW(const Param&p={});
        ~KeyboardGLFW();
        static void init_info();
    };
}
