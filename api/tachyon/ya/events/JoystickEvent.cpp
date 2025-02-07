////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/JoystickEvent.hpp>

#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickEvent)

namespace yq::tachyon {
    JoystickEvent::JoystickEvent(const Header& h) : Event(h)
    {
    }
    
    JoystickEvent::JoystickEvent(const JoystickEvent&cp, const Header&h) : Event(cp, h)
    {
    }

    JoystickEvent::~JoystickEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void JoystickEvent::init_info()
    {
        auto w = writer<JoystickEvent>();
        w.description("Joystick event base class");
    }
}
