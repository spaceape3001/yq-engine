////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "KeyboardEvent.hpp"

#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::KeyboardEvent)

namespace yq::tachyon {
    
    KeyboardEventInfo::KeyboardEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl) :
        InputEventInfo(zName, base, sl)
    {
        set(Flag::KEYBOARD);
    }

    ////////////////////////////////////////////////////////////////////////////

    KeyboardEvent::KeyboardEvent(const Param& p) : InputEvent(p)
    {
    }
    
    KeyboardEvent::~KeyboardEvent()
    {
    }


    ////////////////////////////////////////////////////////////////////////////

    static void reg_keyboard_event()
    {
        {
            auto w = writer<KeyboardEvent>();
            w.description("Keyboard event base class");
        }
    }
    
    YQ_INVOKE(reg_keyboard_event();)
}
