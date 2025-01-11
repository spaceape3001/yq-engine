////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/SetHeading.hpp>
#include <yt/msg/CommandInfoWriter.hpp>
#include <yq/unit/metatype.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetHeading)

namespace yq::tachyon {
    SetHeading::SetHeading(const Header&h) : 
        SpatialCommand(h)
    {
    }

    SetHeading::SetHeading(const Header&h, Radian θ) : 
        SpatialCommand(h), m_θ(θ)
    {
    }

    
    SetHeading::SetHeading(const SetHeading&cp, const Header&h) : SpatialCommand(cp, h), m_θ(cp.m_θ)
    {
    }
    
    SetHeading::~SetHeading()
    {
    }

    PostCPtr    SetHeading::clone(rebind_k, const Header&h) const 
    { 
        return new SetHeading(*this, h); 
    }
    
    void SetHeading::init_info()
    {
        auto w = writer<SetHeading>();
        w.description("Set Heading Command");
        w.property("θ", &SetHeading::m_θ).tag(kTag_Log).tag(kTag_Save);
    }
}
