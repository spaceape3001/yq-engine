////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MonitorDisconnectEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

namespace yq::tachyon {
    void MonitorDisconnectEvent::init_info()
    {
        auto w = writer<MonitorDisconnectEvent>();
        w.description("Monitor Disconnection Event");
    }

    MonitorDisconnectEvent::MonitorDisconnectEvent(Monitor m, const Param&p) : MonitorEvent(m, p)
    {
    }
    
    MonitorDisconnectEvent::~MonitorDisconnectEvent()
    {
    }
    
    YQ_INVOKE(MonitorDisconnectEvent::init_info();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::MonitorDisconnectEvent)
