////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MoveByX.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByˣ)

namespace yq::tachyon {
    MoveByˣ::MoveByˣ(const Header&h) : 
        SpatialCommand(h)
    {
    }

    MoveByˣ::MoveByˣ(const Header&h, double Δx) : 
        SpatialCommand(h), m_Δx(Δx)
    {
    }
    
    MoveByˣ::MoveByˣ(const MoveByˣ& cp, const Header&h) : 
        SpatialCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }

    MoveByˣ::~MoveByˣ()
    {
    }
    
    PostCPtr    MoveByˣ::clone(rebind_k, const Header&h) const 
    {
        return new MoveByˣ(*this, h);
    }

    void MoveByˣ::init_info()
    {
        auto w = writer<MoveByˣ>();
        w.description("Position MoveBy Command in X");
        w.property("Δx", &MoveByˣ::Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
