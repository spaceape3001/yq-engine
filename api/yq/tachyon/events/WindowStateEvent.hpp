////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/WindowEvent.hpp>
#include <yq/tachyon/api/ViewerState.hpp>

namespace yq::tachyon {
    class WindowStateEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(WindowStateEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        WindowStateEvent(Window*, const ViewerState&, const Param& p = {});
        WindowStateEvent(WindowID, const ViewerState&, const Param& p = {});
        virtual ~WindowStateEvent();
        
        static void init_info();
        
        const ViewerState&  state() const { return m_state; }
        
    private:
        const ViewerState   m_state;
    };
}
