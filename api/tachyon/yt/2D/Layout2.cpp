////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Layout2.hpp"
#include "Layout2InfoWriter.hpp"

YQ_OBJECT_IMPLEMENT(yq::tachyon::Layout²)

namespace yq::tachyon {
    Layout²Info::Layout²Info(std::string_view kName, LayoutInfo& pMeta, const std::source_location& sl) :
        LayoutInfo(kName, pMeta, sl)
    {
        set(Flag::D2);
    }

////////////////////////////////////////////////////////////////////////////////
    void Layout²::init_info()
    {
        auto w = writer<Layout²>();
        w.description("2D Layout");
    }
        
    Layout²::Layout²()
    {
    }
    
    Layout²::~Layout²()
    {
    }
}

