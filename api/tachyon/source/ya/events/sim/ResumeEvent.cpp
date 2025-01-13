////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/sim/ResumeEvent.hpp>
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ResumeEvent)

namespace yq::tachyon {

    ResumeEvent::ResumeEvent(const Header&h) : SimEvent(h)
    {
    }

    ResumeEvent::ResumeEvent(const ResumeEvent& cp, const Header& h) : SimEvent(cp, h)
    {
    }
    
    ResumeEvent::~ResumeEvent()
    {
    }

    PostCPtr    ResumeEvent::clone(rebind_k, const Header&h) const 
    {
        return new ResumeEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ResumeEvent::init_info()
    {
        auto w = writer<ResumeEvent>();
        w.description("Resume Event");
    }
}
