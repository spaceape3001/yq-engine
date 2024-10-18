////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/input/InputEvent.hpp>

namespace yq::tachyon {
    class Window;
    class Viewer;

    class KeyboardEventInfo : public InputEventInfo {
    public:
        KeyboardEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };


    class KeyboardEvent : public InputEvent {
        YQ_OBJECT_INFO(KeyboardEventInfo)
        YQ_OBJECT_DECLARE(KeyboardEvent, InputEvent)
    public:

        //  EVENT TODO
        
        Viewer*     viewer() const { return m_viewer; }
        Widget*     widget() const { return m_widget; }

        virtual ~KeyboardEvent();
    
    protected:
        KeyboardEvent(Viewer* v, Widget*w);

    private:
        Viewer* const   m_viewer;
        Widget* const   m_widget;
    };
}
