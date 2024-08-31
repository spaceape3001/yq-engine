////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <0/basic/Enum.hpp>
#include <yq/meta/InfoBinder.hpp>

namespace yq::tachyon {

    //! Stencil operation
    YQ_ENUM(StencilOp, ,
    
        //! Keep
        Keep = 0,
        
        //! Zero
        Zero = 1,
        
        //! Replace
        Replace = 2,
        
        //! Increment and clamp
        IncrementAndClamp = 3,

        //! Decrement and clamp
        DecrementAndClamp = 4,
        
        //! Invert
        Invert = 5,
        
        //! Increment and wrap
        IncrementAndWrap = 6,
        
        //! Decrement and wrap
        DecrementAndWrap = 7
    )
}

YQ_TYPE_DECLARE(yq::tachyon::StencilOp)
