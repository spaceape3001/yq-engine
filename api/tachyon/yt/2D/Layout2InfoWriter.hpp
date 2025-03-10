////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/2D/Layout2.hpp>
#include <yt/ui/LayoutInfoWriter.hpp>

namespace yq::tachyon {

    /*! \brief Writer of layout information
    */
    template <typename C>
    class Layout²Info::Writer : public LayoutInfo::Writer<C> {
    public:
    
        //! Constructor of layout info (this is used by derived classes and this classes other constructor)
        Writer(Layout²Info* layoutInfo) : LayoutInfo::Writer<C>(layoutInfo), m_meta(layoutInfo)
        {
        }
        
        //! Constructor of layout info (this is used by the writer<T>() methods)
        Writer(Layout²Info& layoutInfo) : Writer(&layoutInfo)
        {
        }

    private:
        Layout²Info* m_meta;
    };
}
