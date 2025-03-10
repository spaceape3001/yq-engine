////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/Layout.hpp>

namespace yq::tachyon {
    class Layout²Info : public LayoutInfo {
    public:
        template <typename> class Writer;
        Layout²Info(std::string_view, LayoutInfo&, const std::source_location& sl = std::source_location::current());
    };
    
    class Layout² : public Layout {
        YQ_OBJECT_INFO(Layout²Info)
        YQ_OBJECT_DECLARE(Layout², Layout)
    public:
    
        static void init_info();
        
    protected:
        Layout²();
        ~Layout²();
    };
    
}
