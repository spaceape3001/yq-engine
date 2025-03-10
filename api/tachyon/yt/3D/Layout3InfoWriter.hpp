////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/3D/Layout3.hpp>
#include <yt/ui/LayoutInfoWriter.hpp>

namespace yq::tachyon {

    /*! \brief Writer of layout information
    */
    template <typename C>
    class Layout³Info::Writer : public LayoutInfo::Writer<C> {
    public:
    
        //! Constructor of layout info (this is used by derived classes and this classes other constructor)
        Writer(Layout³Info* layoutInfo) : LayoutInfo::Writer<C>(layoutInfo), m_meta(layoutInfo)
        {
        }
        
        //! Constructor of layout info (this is used by the writer<T>() methods)
        Writer(Layout³Info& layoutInfo) : Writer(&layoutInfo)
        {
        }

    private:
        Layout³Info* m_meta;
    };
}
