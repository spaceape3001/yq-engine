////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QTachyonLL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Event.hpp>
#include <yt/typedef/spatial.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class TachyonEvent : public Event {
        YQ_OBJECT_DECLARE(TachyonEvent, Event)
    public:
    
        static void init_info();

    protected:
        TachyonEvent(const Header&);
        TachyonEvent(const TachyonEvent&, const Header&);
        ~TachyonEvent();
    
    private:
        TachyonEvent(const TachyonEvent&) = delete;
        TachyonEvent(TachyonEvent&&) = delete;
        TachyonEvent& operator=(const TachyonEvent&) = delete;
        TachyonEvent& operator=(TachyonEvent&&) = delete;
    };
}
