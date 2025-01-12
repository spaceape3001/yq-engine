////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/AddMaxSize3.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSize³)

namespace yq::tachyon {
    AddMaxSize³::AddMaxSize³(const Header& h) : SpatialCommand(h)
    {
    }
    
    AddMaxSize³::AddMaxSize³(const Header& h, const Vector3D& v) : 
        SpatialCommand(h), m_Δ(v)
    {
    }

    AddMaxSize³::AddMaxSize³(const AddMaxSize³& cp, const Header& h) : 
        SpatialCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMaxSize³::~AddMaxSize³()
    {
    }

    PostCPtr    AddMaxSize³::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSize³(*this, h);
    }
    
    void AddMaxSize³::init_info()
    {
        auto w = writer<AddMaxSize³>();
        w.description("AddMax Size Command");
        w.property("Δx", &AddMaxSize³::Δx).tag(kTag_Log);
        w.property("Δy", &AddMaxSize³::Δy).tag(kTag_Log);
        w.property("Δz", &AddMaxSize³::Δz).tag(kTag_Log);
        w.property("Δ",  &AddMaxSize³::m_Δ).tag(kTag_Save);
    }
}
