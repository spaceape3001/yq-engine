////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TachyonEvent.hpp"

#include <yq/tachyon/post/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TachyonEvent)

namespace yq::tachyon {
    TachyonEventInfo::TachyonEventInfo(std::string_view zName, EventInfo& base, const std::source_location& sl) :
        EventInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    TachyonEvent::TachyonEvent(Tachyon* v, const Param& p) : Event(p), TachyonBind(v)
    {
    }
    
    TachyonEvent::~TachyonEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void TachyonEvent::init_info()
    {
        auto w = writer<TachyonEvent>();
        w.description("Tachyon event base class");
    }
}
