////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetScaleʸ.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScaleʸ)

namespace yq::tachyon {
    SetScaleʸ::SetScaleʸ(TachyonID tid, double y, const Param& p) : 
        SpatialCommand(tid, p), m_y(y)
    {
    }
    
    SetScaleʸ::~SetScaleʸ()
    {
    }
    
    void SetScaleʸ::init_info()
    {
        auto w = writer<SetScaleʸ>();
        w.description("Set Scale Command");
        w.property("y", &SetScaleʸ::y);
    }
}
