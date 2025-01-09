////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MultiplyScaleX.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyScaleˣ)

namespace yq::tachyon {
    MultiplyScaleˣ::MultiplyScaleˣ(const Header&h) : 
        SpatialCommand(h)
    {
    }

    MultiplyScaleˣ::MultiplyScaleˣ(const Header&h, double x) : 
        SpatialCommand(h), m_δx(x)
    {
    }

    MultiplyScaleˣ::MultiplyScaleˣ(const MultiplyScaleˣ& cp, const Header& h) : 
        SpatialCommand(cp, h), m_δx(cp.m_δx)
    {
    }
    
    MultiplyScaleˣ::~MultiplyScaleˣ()
    {
    }
    
    PostCPtr    MultiplyScaleˣ::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyScaleˣ(*this, h);
    }

    void MultiplyScaleˣ::init_info()
    {
        auto w = writer<MultiplyScaleˣ>();
        w.description("Multiply Scale Command");
        w.property("δx", &MultiplyScaleˣ::m_δx).tag(kTag_Log).tag(kTag_Save);
    }
}
