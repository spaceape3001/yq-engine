////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/sim/PauseEvent.hpp>
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::PauseEvent)

namespace yq::tachyon {

    PauseEvent::PauseEvent(const Header&h) : SimEvent(h)
    {
    }

    PauseEvent::PauseEvent(const PauseEvent& cp, const Header& h) : SimEvent(cp, h)
    {
    }
    
    PauseEvent::~PauseEvent()
    {
    }

    PostCPtr    PauseEvent::clone(rebind_k, const Header&h) const 
    {
        return new PauseEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void PauseEvent::init_info()
    {
        auto w = writer<PauseEvent>();
        w.description("Pause Event");
    }
}
