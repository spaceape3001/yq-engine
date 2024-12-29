////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Spatial.hpp>
#include <yq/tachyon/api/SpatialData.hpp>
#include <yq/tachyon/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    
    /*! \brief Writer of trigger information
    */
    template <typename C>
    class SpatialInfo::Writer : public TachyonInfo::Writer<C> {
    public:
    
        Writer(SpatialInfo* pInfo) : TachyonInfo::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        Writer(SpatialInfo& pInfo) : Writer(&pInfo)
        {
        }

    private:
        SpatialInfo* m_meta;
    };
}
