////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/SetSize1.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSize¹)

namespace yq::tachyon {
    SetSize¹::SetSize¹(const Header& h) : 
        SpatialCommand(h)
    {
    }

    SetSize¹::SetSize¹(const Header& h, const Size1D& v) : 
        SpatialCommand(h), m_size(v)
    {
    }

    SetSize¹::SetSize¹(const SetSize¹& cp, const Header& h) : 
        SpatialCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetSize¹::~SetSize¹()
    {
    }

    PostCPtr    SetSize¹::clone(rebind_k, const Header&h) const 
    {
        return new SetSize¹(*this, h);
    }
    
    void SetSize¹::init_info()
    {
        auto w = writer<SetSize¹>();
        w.description("Set Size Command in 1D");
        w.property("x", &SetSize¹::x).tag(kTag_Log);
        w.property("size", &SetSize¹::m_size).tag(kTag_Save);
    }
}
